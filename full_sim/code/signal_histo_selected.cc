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
#include <TGraph.h>
#include <TF1.h>

using namespace std;

void my_make_histo(string rootname, string outputname);

int main(int argc, char **argv){
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }
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

  ////// Pileups with selection vs signal:
  TH1D* h_track_pt     = new TH1D("h_track_pt",     "h_track_pt",     100,-500,4000);
  TH1D* h_hit_beta_10  = new TH1D("h_hit_beta_10",  "h_hit_beta_10",  200,-2,2);
  TH1D* h_hit_beta_50  = new TH1D("h_hit_beta_50",  "h_hit_beta_50",  200,-2,2);
  TH1D* h_track_z0     = new TH1D("h_track_z0",     "h_track_z0",     100,-3000,3000);
  TH1D* h_track_d0     = new TH1D("h_track_d0",     "h_track_d0",     100,-200,200);
  TH1D* h_track_phi    = new TH1D("h_track_phi",    "h_track_phi",    100,-4,4);
  TH1D* h_track_theta  = new TH1D("h_track_theta",  "h_track_theta",  100,-2,2);
  TH1D* h_track_eta    = new TH1D("h_track_eta",    "h_track_eta",    100,-0.5,3);
  TH1D* h_track_qOverP = new TH1D("h_track_qOverP", "h_track_qOverP", 100,-0.015,0.015);
  TH1D* h_nhit         = new TH1D("h_nhit",         "h_nhit",         11,-0.5,10.5);

  double speed_light = 299.792458; //mm/ns

  for(unsigned iev=0; iev<nevents; ++iev) {
    cout << "Event number: " << iev << endl;

    const fcc::ParticleCollection* particles;
    bool particlesPresent = store.get("TrackRecoParticles", particles);
    
    cout << "test 0" << endl;

    if (particlesPresent) {
      cout << "test 1" << endl;
      for(const auto& particle : *particles){
          for(auto track = particle.tracks_begin(); track != particle.tracks_end(); ++track) {
            if(track->isAvailable()) {
              cout << "test 2" << endl;
              bool selection_masahiko = false;
              for(auto state = track->states_begin(); state !=track->states_end(); ++state){
                   double cosTheta = cos(state->theta());
                   double eta;
                   if (cosTheta*cosTheta < 1){eta = -0.5* log((1.0-cosTheta)/(1.0+cosTheta));}
                   else{eta = -10e10;}
                   if(abs(eta)< 2.5 && abs(1./state->qOverP())>100){selection_masahiko = true;}
                   if(selection_masahiko){
                     h_track_eta   ->Fill(eta);
                     h_track_pt    ->Fill(abs(1./state->qOverP()));
                     h_track_z0    ->Fill(state->z0());
                     h_track_d0    ->Fill(state->d0());
                     h_track_phi   ->Fill(state->phi());
                     h_track_theta ->Fill(state->theta());
                     h_track_qOverP->Fill(state->qOverP());
                   }
              } // loop over states
              cout << "test 3" << endl;
              int hit_counter = 0;
              double x[4]    = {0,0,0,1000};
              double y[4]    = {0,0,0,1000};
              double z[4]    = {0,0,0,1000};
              double t_10[4] = {0,0,0,1000};
              double t_50[4] = {0,0,0,1000};
              for(auto hit = track->hits_begin(); hit !=track->hits_end(); ++hit){
                hit_counter++;
                x[hit_counter] = hit->x();
                y[hit_counter] = hit->y();
                z[hit_counter] = hit->z();
                t_10[hit_counter] = hit->core().time;
                t_10[hit_counter] += gRandom->Gaus(0., 1e-2);
                t_50[hit_counter] = hit->core().time;
                t_50[hit_counter] += gRandom->Gaus(0., 5e-2);
              }
              cout << "test 4" << endl;

              if(selection_masahiko){
                ///////// Fits:
                // time resolution: 10 ps
                TGraph* gx_10 = new TGraph(4,x,t_10);
                TF1 *fx_10 = new TF1("fx_10", "[0]*x+[1]");
                gx_10->Fit(fx_10,"q");
                double vx_10     = fx_10->GetParameter(0);
                double chi2_x_10 = fx_10->GetChisquare();
                double ndf       = fx_10->GetNDF();
                chi2_x_10 = chi2_x_10/ndf;

                TGraph* gy_10 = new TGraph(4,y,t_10);
                TF1 *fy_10 = new TF1("fy_10", "[0]*x+[1]");
                gy_10->Fit(fy_10,"q");
                double vy_10     = fy_10->GetParameter(0);
                double chi2_y_10 = fy_10->GetChisquare();
                ndf              = fy_10->GetNDF();
                chi2_y_10 = chi2_y_10/ndf;

                TGraph* gz_10 = new TGraph(4,z,t_10);
                TF1 *fz_10 = new TF1("fz_10", "[0]*x+[1]");
                gz_10->Fit(fx_10,"q");
                double vz_10     = fz_10->GetParameter(0);
                double chi2_z_10 = fz_10->GetChisquare();
                ndf              = fz_10->GetNDF();
                chi2_z_10 = chi2_x_10/ndf;

                double beta_10 = sqrt(vx_10*vx_10+vy_10*vy_10+vz_10*vz_10)/speed_light;
                double chi2_10 = sqrt(chi2_x_10*chi2_x_10+chi2_y_10*chi2_y_10+chi2_z_10*chi2_z_10);

                cout << "test 5" << endl;

                // time resolution: 10 ps
                TGraph* gx_50 = new TGraph(4,x,t_50);
                TF1 *fx_50 = new TF1("fx_50", "[0]*x+[1]");
                gx_50->Fit(fx_50,"q");
                double vx_50     = fx_50->GetParameter(0);
                double chi2_x_50 = fx_50->GetChisquare();
                ndf              = fx_50->GetNDF();
                chi2_x_50 = chi2_x_50/ndf;

                TGraph* gy_50 = new TGraph(4,y,t_50);
                TF1 *fy_50 = new TF1("fy_50", "[0]*x+[1]");
                gy_50->Fit(fy_50,"q");
                double vy_50     = fy_50->GetParameter(0);
                double chi2_y_50 = fy_50->GetChisquare();
                ndf              = fy_50->GetNDF();
                chi2_y_50 = chi2_y_50/ndf;

                TGraph* gz_50 = new TGraph(4,z,t_50);
                TF1 *fz_50 = new TF1("fz_50", "[0]*x+[1]");
                gz_50->Fit(fx_50,"q");
                double vz_50     = fz_50->GetParameter(0);
                double chi2_z_50 = fz_50->GetChisquare();
                ndf              = fz_50->GetNDF();
                chi2_z_50 = chi2_x_10/ndf;

                cout << "test 6" << endl;

                double beta_50 = sqrt(vx_50*vx_50+vy_50*vy_50+vz_50*vz_50)/speed_light;
                double chi2_50 = sqrt(chi2_x_50*chi2_x_50+chi2_y_50*chi2_y_50+chi2_z_50*chi2_z_50);
                h_nhit->Fill(hit_counter);
                h_hit_beta_10->Fill(beta_10);
                h_hit_beta_50->Fill(beta_50);
                cout << "beta 10 ps: " << beta_10 << endl;
                cout << "beta 50 ps: " << beta_50 << endl;
              }
            }
          } // end of loop over reco tracks
      } // end for of particles reco
    } // end of particles present if

    store.clear();
    reader.endOfEvent();
    // if(iev==1000){break;}
  } // end of loop over events

  cout << "Write to .root" << endl;
  string sss = outputname;
  auto f1 = TFile::Open(sss.c_str(), "RECREATE");
  h_track_pt    ->Write();
  h_hit_beta_10 ->Write();
  h_hit_beta_50 ->Write();
  h_track_z0    ->Write();
  h_track_d0    ->Write();
  h_track_phi   ->Write();
  h_track_theta ->Write();
  h_track_eta   ->Write();
  h_track_qOverP->Write();
  h_nhit        ->Write();
  f1->Close();

  cout <<"Delete" << endl;
  delete h_track_pt    ;
  delete h_hit_beta_10 ;
  delete h_hit_beta_50 ;
  delete h_track_z0    ;
  delete h_track_d0    ;
  delete h_track_phi   ;
  delete h_track_theta ;
  delete h_track_eta   ;
  delete h_track_qOverP;
  delete h_nhit        ;

 cout << "***************** Finished *********************" << endl;
}
