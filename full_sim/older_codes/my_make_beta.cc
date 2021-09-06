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
    string p_size_s = argv[3];
    double p_size = stod(p_size_s);
    my_make_histo(filename, outputname, p_size);

    return 0;
}

void my_make_histo(string rootname, string outputname, double p_size){
  // double p_size = 0.005; // 0.005=5umu
  double t_resolution = 1e-2; //1e-2=10ps

  auto reader = podio::ROOTReader();
  auto store = podio::EventStore();
  reader.openFile(rootname.c_str());
  store.setReader(&reader);
  unsigned nevents= reader.getEntries();

  TH2D* h2_MCBeta_vs_hitBeta  = new TH2D("h2_MCBeta_vs_hitBeta", "h2_MCBeta_vs_hitBeta",  100,0.6,1.1,100,0.6,1.1);
  TH2D* h2_MCBeta_vs_RecoBeta = new TH2D("h2_MCBeta_vs_RecoBeta","h2_MCBeta_vs_RecoBeta", 100,0.6,1.1,100,-0.1,1.1);
  TH2D* h2_DeltaR_vs_hitBeta  = new TH2D("h2_DeltaR_vs_hitBeta", "h2_DeltaR_vs_hitBeta",  100,-0.001,0.03,100,0.6,1.1);
  TH1D* h_theoretical_beta    = new TH1D("h_theoretical_beta",   "h_theoretical_beta",    100,-0,0.025);
  TH1D* h_Delta_beta          = new TH1D("h_Delta_beta",         "h_Delta_beta",          70,-0.05,0.05);
  TH2D* h2_DeltaR_vs_DeltaBeta  = new TH2D("h2_DeltaR_vs_DeltaBeta", "h2_DeltaR_vs_DeltaBeta",  70,-0.0001,0.002,70,-0.05,0.05);
  TH2D* h2_DeltaqOverP_vs_DeltaBeta  = new TH2D("h2_DeltaqOverP_vs_DeltaBeta", "h2_DeltaqOverP_vs_DeltaBeta",  70,-0.015,0.015,70,-0.05,0.05);


  double wino_mass = 3000.000+0.000165; //GeV (better cause beta sim 1 comma ca)
  double speed_light = 299.792458; //mm/ns

  for(unsigned iev=0; iev<nevents; ++iev) {

    const fcc::MCParticleCollection* MCparticles; // create a particle collections
    bool MCparticlePresents = store.get("GenParticles", MCparticles);

    const fcc::ParticleCollection* particles; // create a particle collections
    bool particlesPresent = store.get("TrackRecoParticles", particles);

    double b_deltaR           = 1e8;
    double b_beta             = -1e8;
    double b_Hbeta            = -1e8;
    double b_theoretical_beta = -1e8;
    double b_deltaqOverP      = -1e8;

    TLorentzVector vMC;
    if(MCparticlePresents){
      for(const auto& MCparticle : *MCparticles){
        double local_px = MCparticle.core().p4.px;
        double local_py = MCparticle.core().p4.py;
        double local_pz = MCparticle.core().p4.pz;
        vMC.SetXYZM(local_px,local_py,local_pz,wino_mass);
      }
    }

    int particle_counter = 0;
    double last_x=0, last_y=0, last_z=0,last_t=0;
    double first_x=0, first_y=0, first_z=0,first_t=0;
    if (particlesPresent) {
      for(const auto& particle : *particles){
          particle_counter++;

          TLorentzVector v;
          double local_px = particle.core().p4.px;
          double local_py = particle.core().p4.py;
          double local_pz = particle.core().p4.pz;
          double local_mass = wino_mass;
          v.SetXYZM(local_px,local_py,local_pz,local_mass);

          for(auto track = particle.tracks_begin(); track != particle.tracks_end(); ++track) {
            if(track->isAvailable()) {
              if(b_deltaR > v.DeltaR(vMC)){
                b_deltaR = v.DeltaR(vMC);
                b_beta = v.Beta();
                for(auto hit = track->hits_begin(); hit !=track->hits_end(); ++hit){
                    if(hit==track->hits_begin()){
                      first_x = hit->x();
                      first_y = hit->y();
                      first_z = hit->z();

                      first_t = hit->core().time;
                      first_t += gRandom->Gaus(0., t_resolution); // Add gaussian noise

                    }
                    last_x = hit->x();
                    last_y = hit->y();
                    last_z = hit->z();

                    last_t = hit->core().time;
                    last_t += gRandom->Gaus(0., t_resolution); // Add gaussian noise

                    double d_x = last_x-first_x;
                    double d_y = last_y-first_y;
                    double d_z = last_z-first_z;
                    double d_t = last_t-first_t;
                    double d_S = sqrt(d_x*d_x+d_y*d_y+d_z*d_z);

                    // First tentative:
                    // double delta_S = sqrt(1./d_S* ((d_x*p_size)*(d_x*p_size)+(d_y*p_size)*(d_y*p_size)+(d_z*p_size)*(d_z*p_size)) );
                    // b_theoretical_beta = 1./(d_t*speed_light)*sqrt(delta_S*delta_S+(d_S/d_t*0.01)*(d_S/d_t*0.01));

                    //// Second tentative:
                    double pixel_size_extra = p_size*p_size+p_size*p_size;
                    double delta_t = sqrt(2)*0.01;
                    double delta_S = 1./d_S*sqrt(2)*sqrt((d_x*d_x+d_y*d_y+d_z*d_z)*pixel_size_extra);
                    b_theoretical_beta = 1./(d_t*speed_light)*sqrt(delta_S*delta_S+(d_S/d_t*delta_t)*(d_S/d_t*delta_t));

                    b_Hbeta = d_S/(d_t*speed_light);
                }// loop over hits

                for(auto state = track->states_begin(); state !=track->states_end(); ++state){
                    b_deltaqOverP = 1./vMC.Pt()-state->qOverP();
                }// loop over states
              } // if delta R best
            } // if track present
          } // end of loop over reco tracks
      } // end for of particles reco

      h_Delta_beta->Fill(vMC.Beta()-b_Hbeta);
      h2_DeltaR_vs_hitBeta->Fill(b_deltaR,b_Hbeta);
      h_theoretical_beta->Fill(b_theoretical_beta);
      h2_MCBeta_vs_RecoBeta->Fill(vMC.Beta(),b_beta);
      h2_DeltaR_vs_DeltaBeta->Fill(b_deltaR,vMC.Beta()-b_Hbeta);
      h2_DeltaqOverP_vs_DeltaBeta->Fill(b_deltaqOverP,vMC.Beta()-b_Hbeta);

      if(last_t!=0&&b_beta!=-1e8){
          h2_MCBeta_vs_hitBeta  ->Fill(vMC.Beta(),b_Hbeta);
      }
    } // end of particles present if

    store.clear();
    reader.endOfEvent();
    // if(iev==100){break;}
  } // end of loop over events

  cout << "Write to .root" << endl;
  string sss = outputname+".root";
  auto f1 = TFile::Open(sss.c_str(), "RECREATE");
  h2_MCBeta_vs_hitBeta       ->Write();
  h2_DeltaR_vs_hitBeta       ->Write();
  h_theoretical_beta         ->Write();
  h_Delta_beta               ->Write();
  h2_MCBeta_vs_RecoBeta      ->Write();
  h2_DeltaR_vs_DeltaBeta     ->Write();
  h2_DeltaqOverP_vs_DeltaBeta->Write();
  f1->Close();

  cout <<"Delete" << endl;
  delete h2_MCBeta_vs_hitBeta       ;
  delete h2_DeltaR_vs_hitBeta       ;
  delete h_theoretical_beta         ;
  delete h_Delta_beta               ;
  delete h2_MCBeta_vs_RecoBeta      ;
  delete h2_DeltaR_vs_DeltaBeta     ;
  delete h2_DeltaqOverP_vs_DeltaBeta;

 cout << "***************** Finished *********************" << endl;
}
