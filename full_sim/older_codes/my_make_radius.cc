// Data model
#include "datamodel/TrackCollection.h"
#include "datamodel/ParticleCollection.h"
#include "datamodel/TrackStateCollection.h"
#include "datamodel/MCParticleCollection.h"
#include "datamodel/PositionedTrackHitCollection.h"
#include "datamodel/GenVertex.h"

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

double make_delta_angle(double a, double b);
void my_make_histo(string rootname, string outputname);

int main(int argc, char **argv){
    // std::cout << "Have " << argc << " arguments:" << std::endl;
    string filename,outputname;
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }
    filename = argv[1];
    outputname= argv[2];
    my_make_histo(filename, outputname);

    return 0;
}

void my_make_histo(string rootname, string outputname){
  auto reader = podio::ROOTReader();
  auto store = podio::EventStore();
  reader.openFile(rootname.c_str());
  store.setReader(&reader);
  unsigned nevents= reader.getEntries();

  TH2D* h2_z_vs_radius = new TH2D("h2_z_vs_radius","h2_z_vs_radius",100,-800,800,100,0,500);
  TH1D* h1_radius_all  = new TH1D("h1_radius_all","h1_radius_all",100,0,500);
  TH1D* h1_radius_reco = new TH1D("h1_radius_reco","h1_radius_reco",100,0,500);

  TH2D* h2_pt_vs_radius = new TH2D("h2_pt_vs_radius","h2_pt_vs_radius",100,-100,5000,100,0,500);


  ////// checks:
  TH2D* h2_Reta_Seta = new TH2D("h2_Reta_Seta","h2_Reta_Seta",100,-3,3,100,-3,3);
  TH2D* h2_Rpz_Spz = new TH2D("h2_Rpz_Spz","h2_Rpz_Spz",100,-10000,10000,100,-10000,10000);
  TH1D* h1_decay_z = new TH1D("h1_decay_z","h1_decay_z",100,-800,800);

  double r_max = 0;
  double wino_mass = 3000.000+0.000165;

  for(unsigned iev=0; iev<nevents; ++iev) {
    const fcc::MCParticleCollection* MCparticles;
    bool MCparticlePresents = store.get("GenParticles", MCparticles);

    TLorentzVector vMC;
    if(MCparticlePresents){
      for(const auto& MCparticle : *MCparticles){
        double local_px = MCparticle.core().p4.px;
        double local_py = MCparticle.core().p4.py;
        double local_pz = MCparticle.core().p4.pz;
        vMC.SetXYZM(local_px,local_py,local_pz,wino_mass);
      }
    }


    const fcc::ParticleCollection* particles;
    bool particlesPresent = store.get("TrackRecoParticles", particles);
    double b_deltaR = 1e8;
    double b_pt = 1e8;
    double b_deltaR_2 = 1e8;
    double b_reco_eta = 1e8;
    double b_sim_eta =1e8;
    double b_sim_pz = 1e8;
    double b_reco_pz = 1e8;

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
              if(b_deltaR > v.DeltaR(vMC)){
              for(auto state = track->states_begin(); state !=track->states_end(); ++state){
                   b_deltaR = v.DeltaR(vMC);
                   b_pt     = v.Pt();
                   b_reco_eta   = v.Eta();
                   b_reco_pz = v.Pz();
                 } // loop over states
              } // closes best if
            }
          } // end of loop over reco tracks
      } // end for of particles reco
    }

    double r = 1e8;

    const fcc::MCParticleCollection* simparticles;
    bool simparticlesPresent = store.get("SimParticles", simparticles);
    if (simparticlesPresent){
      int neutralino_counter = 0;
      for(const auto& simparticle : *simparticles){
        if(simparticle.pdgId()==1000024){
          TLorentzVector v2;
          double local_px = simparticle.core().p4.px;
          double local_py = simparticle.core().p4.py;
          double local_pz = simparticle.core().p4.pz;
          double local_mass = wino_mass;
          v2.SetXYZM(local_px,local_py,local_pz,local_mass);
          if(b_deltaR_2 > v2.DeltaR(vMC)){
            b_deltaR_2 = v2.DeltaR(vMC);
            b_sim_eta   = v2.Eta();
            b_sim_pz = v2.Pz();
          }
        }
        if(simparticle.pdgId() == 1000022){
          neutralino_counter++;
          double x = simparticle.startVertex().x();
          double y = simparticle.startVertex().y();
          double z = simparticle.startVertex().z();
          double t = simparticle.startVertex().ctau();
          // if(x<0){cout << "x is negative" << endl;}
          // if(y<0){cout << "y is negative" << endl;}
          // if(z<0){cout << "z is negative" << endl;}
          r = sqrt(x*x + y*y);
          // cout << "  particle startVertex (r, z, t)  = " << r << ", " << z << ", " << t << endl;
          h1_decay_z->Fill(z);
          h2_z_vs_radius->Fill(z,r);
          if(r>=150){h1_radius_reco->Fill(r);}
          h1_radius_all->Fill(r);
          if(r_max<r){r_max =r;}
        }
      }
      if(neutralino_counter!=1){cout << "Number of neutralinos in the event " << neutralino_counter << endl;}
    }
    h2_pt_vs_radius->Fill(b_pt,r);
    h2_Reta_Seta->Fill(b_reco_eta,b_sim_eta);
    h2_Rpz_Spz->Fill(b_reco_pz,b_sim_pz);

    store.clear();
    reader.endOfEvent();
    // if(iev==3){break;}
  } // end of loop over events

  cout << endl << "R maximum: " << r_max << endl;

  h1_radius_reco->Divide(h1_radius_all);

  cout << "Write to .root" << endl;
  string sss = outputname+".root";
  auto f1 = TFile::Open(sss.c_str(), "RECREATE");
  h2_z_vs_radius ->Write();
  h1_radius_reco ->Write();
  h1_radius_all  ->Write();
  h2_pt_vs_radius->Write();
  h2_Reta_Seta   ->Write();
  h2_Rpz_Spz     ->Write();
  h1_decay_z     ->Write();
  f1->Close();


 cout << "***************** Finished *********************" << endl;
}
