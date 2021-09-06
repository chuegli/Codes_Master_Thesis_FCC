// Data model
#include "datamodel/TrackCollection.h"
#include "datamodel/ParticleCollection.h"
#include "datamodel/TrackStateCollection.h"
#include "datamodel/MCParticleCollection.h"
#include "datamodel/PositionedTrackHitCollection.h"

// podio specific includes: https://github.com/AIDASoft/podio/tree/master/include/podio
#include "podio/EventStore.h"
#include "podio/ROOTReader.h"

#include <ostream>
#include <TLorentzVector.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TH3D.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TStyle.h>
#include <TRandom.h>
#include "TROOT.h"
#include "TTree.h"
#include <TGraph.h>
#include <TF1.h>

using namespace std;

void my_make_histo(string rootname, string outputname);

int main(int argc, char **argv){
    string filename   = argv[1];
    string outputname = argv[2];
    my_make_histo(filename, outputname);

    return 0;
}

void my_make_histo(string rootname, string outputname){

  auto reader = podio::ROOTReader();
  auto store = podio::EventStore();
  reader.openFile(rootname.c_str());
  store.setReader(&reader);
  unsigned nevents= reader.getEntries();

  double speed_light = 299.792458; //mm/ns

  //////////////// Create a selection tree:
  TFile f(outputname.c_str(),"recreate");
  TTree t1("t","Tree with selected track variables");
  Double_t eta, pt, mass, z0, d0, phi, theta, qOverP, beta_5, beta_10, beta_50, nhits, chi2_5, chi2_10, chi2_50;
  // Int_t ev;
  t1.Branch("eta"    ,&eta    ,"eta/D"    );
  t1.Branch("pt"     ,&pt     ,"pt/D"     );
  t1.Branch("mass"   ,&mass   ,"mass/D"   );
  t1.Branch("z0"     ,&z0     ,"z0/D"     );
  t1.Branch("d0"     ,&d0     ,"d0/D"     );
  t1.Branch("phi"    ,&phi    ,"phi/D"    );
  t1.Branch("theta"  ,&theta  ,"theta/D"  );
  t1.Branch("qOverP" ,&qOverP ,"qOverP/D" );
  t1.Branch("beta_5" ,&beta_5 ,"beta_5/D" );
  t1.Branch("beta_10",&beta_10,"beta_10/D");
  t1.Branch("beta_50",&beta_50,"beta_50/D");
  t1.Branch("chi2_5" ,&chi2_5 ,"chi2_5/D" );
  t1.Branch("chi2_10",&chi2_10,"chi2_10/D");
  t1.Branch("chi2_50",&chi2_50,"chi2_50/D");
  t1.Branch("nhits"  ,&nhits  ,"nhits/D"  );
  // t1.Branch("ev",&ev,"ev/I");

  for(unsigned iev=0; iev<nevents; ++iev) {

    const fcc::ParticleCollection* particles;
    bool particlesPresent = store.get("TrackRecoParticles", particles);

    if (particlesPresent) {
      for(const auto& particle : *particles){
          for(auto track = particle.tracks_begin(); track != particle.tracks_end(); ++track) {
            if(track->isAvailable()) {
              bool selection_masahiko = false;
              for(auto state = track->states_begin(); state !=track->states_end(); ++state){
                   double cosTheta = cos(state->theta());
                   if (cosTheta*cosTheta < 1){eta = -0.5* log((1.0-cosTheta)/(1.0+cosTheta));}
                   else{eta = -10e10;}
                   if(abs(eta)< 2.5 && abs(1./state->qOverP())>100){
                     selection_masahiko = true;
                     cout << "A passing track exists !!!" << endl;
                     pt     = abs(1./state->qOverP());
                     // cout << abs(1./state->qOverP()) << "  " << pt << endl;
                     z0     = state->z0();
                     d0     = state->d0();
                     phi    = state->phi();
                     theta  = state->theta();
                     qOverP = state->qOverP();
                   }
              } // loop over states
              int hit_counter = 0;
              double x[4]    = {0,0,0,1000};
              double y[4]    = {0,0,0,1000};
              double z[4]    = {0,0,0,1000};
              double t_5[4]  = {0,0,0,1000};
              double t_10[4] = {0,0,0,1000};
              double t_50[4] = {0,0,0,1000};
              for(auto hit = track->hits_begin(); hit !=track->hits_end(); ++hit){
                  x[hit_counter] = hit->x();
                  y[hit_counter] = hit->y();
                  z[hit_counter] = hit->z();
                  t_5[hit_counter] = hit->core().time;
                  t_5[hit_counter] += gRandom->Gaus(0., 0.5e-2);
                  t_10[hit_counter] = hit->core().time;
                  t_10[hit_counter] += gRandom->Gaus(0., 1e-2);
                  t_50[hit_counter] = hit->core().time;
                  t_50[hit_counter] += gRandom->Gaus(0., 5e-2);
                  hit_counter++;
              }
              nhits = hit_counter;
              // cout << "nhits: " << nhits<< endl;

              if(selection_masahiko){
                ///////// Fits:
                // time resolution: 10 ps
                TGraph* gx_5 = new TGraph(4,t_5,x);
                TF1 *fx_5 = new TF1("fx_5", "[0]*x+[1]");
                gx_5->Fit(fx_5,"q");
                double vx_5     = fx_5->GetParameter(0);
                double chi2_x_5 = fx_5->GetChisquare();
                double ndf      = fx_5->GetNDF();
                chi2_x_5 = chi2_x_5/ndf;

                TGraph* gy_5 = new TGraph(4,t_5,y);
                TF1 *fy_5 = new TF1("fy_5", "[0]*x+[1]");
                gy_5->Fit(fy_5,"q");
                double vy_5     = fy_5->GetParameter(0);
                double chi2_y_5 = fy_5->GetChisquare();
                ndf             = fy_5->GetNDF();
                chi2_y_5 = chi2_y_5/ndf;

                TGraph* gz_5= new TGraph(4,t_5,z);
                TF1 *fz_5 = new TF1("fz_5", "[0]*x+[1]");
                gz_5->Fit(fz_5,"q");
                double vz_5     = fz_5->GetParameter(0);
                double chi2_z_5 = fz_5->GetChisquare();
                ndf             = fz_5->GetNDF();
                chi2_z_5 = chi2_z_5/ndf;

                beta_5 = sqrt(vx_5*vx_5+vy_5*vy_5+vz_5*vz_5)/speed_light;
                chi2_5 = sqrt(chi2_x_5*chi2_x_5+chi2_y_5*chi2_y_5+chi2_z_5*chi2_z_5);

                // time resolution: 10 ps
                TGraph* gx_10 = new TGraph(4,t_10,x);
                TF1 *fx_10 = new TF1("fx_10", "[0]*x+[1]");
                gx_10->Fit(fx_10,"q");
                double vx_10     = fx_10->GetParameter(0);
                double chi2_x_10 = fx_10->GetChisquare();
                ndf              = fx_10->GetNDF();
                chi2_x_10 = chi2_x_10/ndf;

                TGraph* gy_10 = new TGraph(4,t_10,y);
                TF1 *fy_10 = new TF1("fy_10", "[0]*x+[1]");
                gy_10->Fit(fy_10,"q");
                double vy_10     = fy_10->GetParameter(0);
                double chi2_y_10 = fy_10->GetChisquare();
                ndf              = fy_10->GetNDF();
                chi2_y_10 = chi2_y_10/ndf;

                TGraph* gz_10 = new TGraph(4,t_10,z);
                TF1 *fz_10 = new TF1("fz_10", "[0]*x+[1]");
                gz_10->Fit(fz_10,"q");
                double vz_10     = fz_10->GetParameter(0);
                double chi2_z_10 = fz_10->GetChisquare();
                ndf              = fz_10->GetNDF();
                chi2_z_10 = chi2_z_10/ndf;

                beta_10 = sqrt(vx_10*vx_10+vy_10*vy_10+vz_10*vz_10)/speed_light;
                chi2_10 = sqrt(chi2_x_10*chi2_x_10+chi2_y_10*chi2_y_10+chi2_z_10*chi2_z_10);
                mass = sqrt(1-beta_10*beta_10)/beta_10*pt;

                // time resolution: 10 ps
                TGraph* gx_50 = new TGraph(4,t_50,x);
                TF1 *fx_50 = new TF1("fx_50", "[0]*x+[1]");
                gx_50->Fit(fx_50,"q");
                double vx_50     = fx_50->GetParameter(0);
                double chi2_x_50 = fx_50->GetChisquare();
                ndf              = fx_50->GetNDF();
                chi2_x_50 = chi2_x_50/ndf;

                TGraph* gy_50 = new TGraph(4,t_50,y);
                TF1 *fy_50 = new TF1("fy_50", "[0]*x+[1]");
                gy_50->Fit(fy_50,"q");
                double vy_50     = fy_50->GetParameter(0);
                double chi2_y_50 = fy_50->GetChisquare();
                ndf              = fy_50->GetNDF();
                chi2_y_50 = chi2_y_50/ndf;

                TGraph* gz_50 = new TGraph(4,t_50,z);
                TF1 *fz_50 = new TF1("fz_50", "[0]*x+[1]");
                gz_50->Fit(fz_50,"q");
                double vz_50     = fz_50->GetParameter(0);
                double chi2_z_50 = fz_50->GetChisquare();
                ndf              = fz_50->GetNDF();
                chi2_z_50 = chi2_z_50/ndf;

                beta_50 = sqrt(vx_50*vx_50+vy_50*vy_50+vz_50*vz_50)/speed_light;
                chi2_50 = sqrt(chi2_x_50*chi2_x_50+chi2_y_50*chi2_y_50+chi2_z_50*chi2_z_50);
                t1.Fill();
                // cout << "vx: " << vx_10 << endl;
                // cout << "vy: " << vy_10 << endl;
                // cout << "vz: " << vz_10 << endl;
                // cout << "chi2 x: " << chi2_x_10 << endl;
                // cout << "chi2 final: " << chi2_10 << endl;
                // cout << "velocity: " << sqrt(vx_10*vx_10+vy_10*vy_10+vz_10*vz_10) << endl;
                // cout << "beta 10 ps: " << beta_10 << endl;
                // cout << "beta 50 ps: " << beta_50 << endl;
                // double dx = x[0]-x[3];
                // double dy = y[0]-y[3];
                // double dz = z[0]-z[3];
                // double dt = t_10[3]-t_10[0];
                // double dS = sqrt(dx*dx+dy*dy+dz*dz);
                // double beta_10_extra = dS/dt/speed_light;
                // cout << "hit 1: (" << x[0] << ", "<< y[0] << ", "<< z[0] << ", "<< t_10[0] << ")"<< endl;
                // cout << "hit 2: (" << x[1] << ", "<< y[1] << ", "<< z[1] << ", "<< t_10[1] << ")"<< endl;
                // cout << "hit 3: (" << x[2] << ", "<< y[2] << ", "<< z[2] << ", "<< t_10[2] << ")"<< endl;
                // cout << "hit 4: (" << x[3] << ", "<< y[3] << ", "<< z[3] << ", "<< t_10[3] << ")"<< endl;
                // cout << "vx extra: " << dx/dt << endl;
                // cout << "vy extra: " << dy/dt << endl;
                // cout << "vz extra: " << dz/dt << endl;
                // cout << "velocity extra: " << dS/dt << endl;
                // cout << "beta 10 ps extra: " << beta_10_extra << endl;
              }
              // cout << "test" << endl;
            }
          } // end of loop over reco tracks
      } // end for of particles reco
    } // end of particles present if

    store.clear();
    reader.endOfEvent();
    // if(iev==1000){break;}
  } // end of loop over events

  // for (Int_t i=0;i<5;i++) {
  //     eta     = 1;
  //     pt      = 2;
  //     z0      = 3.1;
  //     d0      = -4;
  //     phi     = -6.55;
  //     theta   = 4;
  //     qOverP  = 5;
  //     beta_10 = 6;
  //     beta_50 = 7;
  //     nhits   = 300;
  //     ev = i;
  //     t1.Fill();
  //  }
  // t1.Fill();
  // cout << "Save the tree" << endl;
  t1.Write();

 // cout << "***************** Finished *********************" << endl;
}
