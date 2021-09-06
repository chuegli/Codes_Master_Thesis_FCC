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
#include <TGraphErrors.h>
#include <TF1.h>

using namespace std;

void my_make_histo(string rootname, string outputname, double p_size);

int main(int argc, char **argv){
    // std::cout << "Have " << argc << " arguments:" << std::endl;
    string filename,outputname;
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }
    filename = argv[1];
    outputname= argv[2];
    string extra = argv[3];
    double p_size = stod(extra);
    my_make_histo(filename, outputname, p_size);

    return 0;
}

void my_make_histo(string rootname, string outputname, double p_size){
  // double p_size = 0.005; // 0.005=5umu

  auto reader = podio::ROOTReader();
  auto store = podio::EventStore();
  reader.openFile(rootname.c_str());
  store.setReader(&reader);
  unsigned nevents= reader.getEntries();

  TH1D* h_Delta_beta_MC = new TH1D("h_Delta_beta_MC", "h_Delta_beta_MC",125,0,1.5);
  TH1D* h_Delta_beta_10 = new TH1D("h_Delta_beta_10", "h_Delta_beta_10",125,0,1.5);

  double t_resolution = 1e-2;

  double wino_mass = 3000.000+0.000165; //GeV (better cause beta sim 1 comma ca)
  double speed_light = 299.792458; //mm/ns

  for(unsigned iev=0; iev<nevents; ++iev) {

    const fcc::MCParticleCollection* MCparticles; // create a particle collections
    bool MCparticlePresents = store.get("GenParticles", MCparticles);

    const fcc::ParticleCollection* particles; // create a particle collections
    bool particlesPresent = store.get("TrackRecoParticles", particles);

    double b_deltaR = 1e8;
    double b_Hbeta;
    double chi2_ndf;

    TLorentzVector vMC;
    if(MCparticlePresents){
      for(const auto& MCparticle : *MCparticles){
        double local_px = MCparticle.core().p4.px;
        double local_py = MCparticle.core().p4.py;
        double local_pz = MCparticle.core().p4.pz;
        vMC.SetXYZM(local_px,local_py,local_pz,wino_mass);
      }
    }

    if (particlesPresent) {
      for(const auto& particle : *particles){
          TLorentzVector v;
          double local_px = particle.core().p4.px;
          double local_py = particle.core().p4.py;
          double local_pz = particle.core().p4.pz;
          double local_mass = wino_mass;
          v.SetXYZM(local_px,local_py,local_pz,local_mass);

          for(auto track = particle.tracks_begin(); track != particle.tracks_end(); ++track) {
            if(track->isAvailable()) {
              if(true){
                  b_deltaR = v.DeltaR(vMC);
                  bool selection_masahiko = false;
                  for(auto state = track->states_begin(); state !=track->states_end(); ++state){
                       double cosTheta = cos(state->theta());
                       double eta;
                       if (cosTheta*cosTheta < 1){eta = -0.5* log((1.0-cosTheta)/(1.0+cosTheta));}
                       else{eta = -10e10;}
                       if(abs(eta)< 2.5 && abs(1./state->qOverP())>100){
                         selection_masahiko = true;
                       }
                  }

                  double t_10[4] = {0,0,0,1000};
                  int hit_counter = 0;
                  double x[4]    = {0,0,0,1000};
                  double y[4]    = {0,0,0,1000};
                  double z[4]    = {0,0,0,1000};
                  for(auto hit = track->hits_begin(); hit !=track->hits_end(); ++hit){
                    x[hit_counter] = hit->x();
                    y[hit_counter] = hit->y();
                    z[hit_counter] = hit->z();
                    t_10[hit_counter] = hit->core().time;
                    t_10[hit_counter] += gRandom->Gaus(0., t_resolution);
                    hit_counter++;
                  }
                  if(true){
                  TGraph* gx_10 = new TGraph(4,t_10,x);
                  TF1 *fx_10 = new TF1("fx_10", "[0]*x+[1]");
                  gx_10->Fit(fx_10,"q");
                  double vx_10     = fx_10->GetParameter(0);
                  double chi2_x_10 = fx_10->GetChisquare();
                  double ndf       = fx_10->GetNDF();
                  chi2_ndf = chi2_x_10/ndf;

                  TGraph* gy_10 = new TGraph(4,t_10,y);
                  TF1 *fy_10 = new TF1("fy_10", "[0]*x+[1]");
                  gy_10->Fit(fy_10,"q");
                  double vy_10     = fy_10->GetParameter(0);
                  double chi2_y_10 = fy_10->GetChisquare();
                  ndf              = fy_10->GetNDF();
                  chi2_ndf = chi2_ndf + chi2_y_10/ndf;

                  TGraph* gz_10 = new TGraph(4,t_10,z);
                  TF1 *fz_10 = new TF1("fz_10", "[0]*x+[1]");
                  gz_10->Fit(fz_10,"q");
                  double vz_10     = fz_10->GetParameter(0);
                  double chi2_z_10 = fz_10->GetChisquare();
                  ndf              = fz_10->GetNDF();
                  chi2_ndf = chi2_ndf + chi2_z_10/ndf;

                  double beta_10 = sqrt(vx_10*vx_10+vy_10*vy_10+vz_10*vz_10)/speed_light;

                  b_Hbeta = beta_10;
                }


              } // if delta R best
            } // if track present
          } // end of loop over reco tracks
      } // end for of particles reco
      h_Delta_beta_MC->Fill(vMC.Beta());
      if(chi2_ndf<10){h_Delta_beta_10->Fill(b_Hbeta);}
    } // end of particles present if

    store.clear();
    reader.endOfEvent();
    // if(iev==100){break;}
  } // end of loop over events

  cout << "Write to .root" << endl;
  string sss = outputname+".root";
  auto f1 = TFile::Open(sss.c_str(), "RECREATE");
  h_Delta_beta_MC->Write();
  h_Delta_beta_10->Write();
  f1->Close();

  cout <<"Delete" << endl;

 cout << "***************** Finished *********************" << endl;
}
