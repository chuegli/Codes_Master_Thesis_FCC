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

////////////////////////////////////////////////////////////////////////////////
//////////////////////////// ATTENTION /////////////////////////////////////////
// NEED TO CHANGE WINO_MASS WINO <-> MUON
////////////////////////////////////////////////////////////////////////////////

void my_make_histo(string rootname, string outputname);

int main(int argc, char **argv){
    // std::cout << "Have " << argc << " arguments:" << std::endl;
    string filename,outputname;
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }
    filename   = argv[1];
    outputname = argv[2];
    my_make_histo(filename, outputname);

    return 0;
}

void my_make_histo(string rootname, string outputname){

  auto reader = podio::ROOTReader();
  auto store = podio::EventStore();
  reader.openFile(rootname.c_str());
  store.setReader(&reader);
  unsigned nevents= reader.getEntries();

  TH1D* b_h_deltaR   = new TH1D("b_h_deltaR",   "b_h_deltaR",   100,-0.0001,0.002);
  TH1D* h_d0         = new TH1D("h_d0",         "h_d0",         100,-0.1,0.1);
  TH1D* h_z0         = new TH1D("h_z0",         "h_z0",         100,-0.25,0.25);
  TH1D* h_Delta_beta = new TH1D("h_Delta_beta", "h_Delta_beta", 200,-0.2,0.2);
  TH1D* h_hit_energy = new TH1D("h_hit_energy", "h_hit_energy", 100,-0.0001,0.001); // all
  TH1D* h_hit_time   = new TH1D("h_hit_time",   "h_hit_time",   100,-2,6); // all
  TH1D* h_nhits      = new TH1D("h_nhits",      "h_nhits",      11,-0.5,10.5); // best
  TH1D* h_beta       = new TH1D("h_beta",       "h_beta",       100,0.5,1.5);
  TH1D* h_eta        = new TH1D("h_eta",        "h_eta",        100,-2.5,2.5);
  TH1D* h_r          = new TH1D("h_r",          "h_r",          100,50,200);

  double wino_mass = 3000.000+0.000165; //GeV (better cause beta sim 1 comma ca)
  // double wino_mass = 0.1056583745; // is the muon mass
  double speed_light = 299.792458; //mm/ns

  double nhit_max = 0;


  for(unsigned iev=0; iev<nevents; ++iev) {

    const fcc::MCParticleCollection* MCparticles;
    bool MCparticlePresents = store.get("GenParticles", MCparticles);

    const fcc::ParticleCollection* particles;
    bool particlesPresent = store.get("TrackRecoParticles", particles);

    double b_deltaR       = 1e8;
    double b_d0           = 1e8;
    double b_z0           = 1e8;
    double b_beta         = 1e8;
    double b_nhits        = 1e8;
    double b_eta          = 1e8;
    double b_r            = 1e8;

    double first_x = 0;
    double first_y = 0;
    double first_z = 0;
    double first_t = 0;
    double last_x = 0;
    double last_y = 0;
    double last_z = 0;
    double last_t = 0;

    TLorentzVector vMC;
    if(MCparticlePresents){
      for(const auto& MCparticle : *MCparticles){
        double local_px = MCparticle.core().p4.px;
        double local_py = MCparticle.core().p4.py;
        double local_pz = MCparticle.core().p4.pz;
        vMC.SetXYZM(local_px,local_py,local_pz,wino_mass);
        // cout << "MC px: " << vMC.Px() << endl;
      }
    }

    if (particlesPresent) {
      // cout << "reco exists" << endl;
      for(const auto& particle : *particles){
          // cout << "hi am I reco" << endl;
          TLorentzVector v;
          double local_px = particle.core().p4.px;
          double local_py = particle.core().p4.py;
          double local_pz = particle.core().p4.pz;
          v.SetXYZM(local_px,local_py,local_pz,wino_mass);
          // cout << "reco px: " << v.Px() << endl;

          for(auto track = particle.tracks_begin(); track != particle.tracks_end(); ++track) {
            if(track->isAvailable()) {
              if(b_deltaR > v.DeltaR(vMC)){
                b_eta = v.Eta();
              for(auto state = track->states_begin(); state !=track->states_end(); ++state){
                   b_deltaR = v.DeltaR(vMC);
                   b_d0 = state->d0();
                   b_z0 = state->z0();
                 } // loop over states
                 double hit_counter = 0;
                 for(auto hit = track->hits_begin(); hit !=track->hits_end(); ++hit){
                   hit_counter++;

                   //// Smearing of hit time:
                   double hit_time = hit->core().time;
                   double t_resolution = 1e-2; // 1e-2 = 10 ps
                   hit_time += gRandom->Gaus(0., t_resolution); // Add gaussian noise
                   ////

                    if(hit==track->hits_begin()){
                      first_x = hit->x();
                      first_y = hit->y();
                      first_z = hit->z();
                      first_t = hit_time;
                    }
                    last_x = hit->x();
                    last_y = hit->y();
                    last_z = hit->z();
                    last_t = hit_time;


                    h_hit_energy->Fill(hit->core().energy);
                    // cout << "hit energy: " << hit->core().energy << endl;
                    h_hit_time->Fill(hit_time);

                    double d_x = last_x-first_x;
                    double d_y = last_y-first_y;
                    double d_z = last_z-first_z;
                    double d_t = last_t-first_t;
                    double d_r = sqrt(d_x*d_x+d_y*d_y);
                    b_r = d_r;
                    double d_S = sqrt(d_x*d_x+d_y*d_y+d_z*d_z);
                    b_beta = d_S/d_t/speed_light;
                  }
                  b_nhits = hit_counter;
                  // cout << "nhits: " << b_nhits<< endl;
                  if(nhit_max<b_nhits){nhit_max=b_nhits;}
              } // closes best if
            }
          } // end of loop over reco tracks
      } // end for of particles reco
      b_h_deltaR->Fill(b_deltaR);
      h_z0->Fill(b_z0);
      h_d0->Fill(b_d0);
      h_Delta_beta->Fill(b_beta-vMC.Beta());
      h_nhits->Fill(b_nhits);
      h_beta->Fill(b_beta);
      h_eta->Fill(b_eta);
      h_r->Fill(b_r);
    } // end of particles present if

    store.clear();
    reader.endOfEvent();
    // if(iev==10){break;}
  } // end of loop over events

  cout << endl << "max number of hits " << nhit_max << endl << endl;

  cout << "Write to .root" << endl;
  string sss = outputname+".root";
  auto f1 = TFile::Open(sss.c_str(), "RECREATE");
  b_h_deltaR  ->Write();
  h_d0        ->Write();
  h_z0        ->Write();
  h_Delta_beta->Write();
  h_hit_energy->Write();
  h_hit_time  ->Write();
  h_nhits     ->Write();
  h_beta      ->Write();
  h_eta       ->Write();
  h_r         ->Write();
  f1->Close();

  cout <<"Delete" << endl;
  delete b_h_deltaR  ;
  delete h_d0        ;
  delete h_z0        ;
  delete h_Delta_beta;
  delete h_hit_energy;
  delete h_hit_time  ;
  delete h_nhits     ;
  delete h_beta      ;
  delete h_eta       ;
  delete h_r         ;

 cout << "***************** Finished *********************" << endl;
}
