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


  TH1D* h_deltaR = new TH1D("h_deltaR", "h_deltaR", 50,-0.001,0.005);
  TH1D* h_qOverP = new TH1D("h_qOverP", "h_qOverP", 50,-0.02,0.02);
  TH1D* h_Tpt    = new TH1D("h_Tpt", "h_Tpt", 50,-500,5000);

  double wino_mass = 3000.000+0.000165; //GeV (better cause beta sim 1 comma ca)

  double reco_counter = 0;
  for(unsigned iev=0; iev<nevents; ++iev) {

    const fcc::MCParticleCollection* MCparticles; // create a particle collections
    bool MCparticlePresents = store.get("GenParticles", MCparticles);

    const fcc::ParticleCollection* particles; // create a particle collections
    bool particlesPresent = store.get("TrackRecoParticles", particles);

    double b_deltaR            = 1e8;
    double b_Tpt               = -1e8;
    double b_T_Delta_q_pt      = -1e8;

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
                for(auto state = track->states_begin(); state !=track->states_end(); ++state){
                    if(b_deltaR > v.DeltaR(vMC)){
                        b_deltaR = v.DeltaR(vMC);
                        b_T_Delta_q_pt = state->qOverP()-1./vMC.Pt();
                        b_Tpt = abs(1./state->qOverP());
                    }
                }
              }
          }
      }
      if(b_deltaR<1000){
        reco_counter++;
        h_qOverP->Fill(b_T_Delta_q_pt);
        h_Tpt->Fill(b_Tpt);
      }
      h_deltaR->Fill(b_deltaR);
    } // end of particles present if


    store.clear();
    reader.endOfEvent();
  } // end of loop over events

  cout << endl << "reco counter with delta R < 0.01: " << reco_counter << endl;

  cout << "Write to .root" << endl;
  string sss = outputname+".root";
  auto f1 = TFile::Open(sss.c_str(), "RECREATE");
  h_deltaR->Write();
  h_qOverP->Write();
  h_Tpt   ->Write();
  f1->Close();

  cout <<"Delete" << endl;
  delete h_deltaR;
  delete h_qOverP;
  delete h_Tpt   ;

 cout << "***************** Finished *********************" << endl;
}
