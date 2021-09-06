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
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void my_make_histo(string rootname);

int main(int argc, char **argv){
    string rootname = argv[1];
    cout << "Rootname: " << rootname << endl;
    my_make_histo(rootname);

    return 0;
}

void my_make_histo(string rootname){

  auto reader = podio::ROOTReader();
  auto store = podio::EventStore();
  reader.openFile(rootname);
  store.setReader(&reader);
  double nevents = reader.getEntries();


  for(unsigned iev=0; iev<nevents; ++iev) {
    int reco_counter  = 0;
    int gen_counter   = 0;
    int track_counter = 0;

    const fcc::ParticleCollection* particles;
    bool particlesPresent = store.get("TrackRecoParticles", particles);

    if (particlesPresent) {
      for(const auto& particle : *particles){
        reco_counter++;
      }
    }

    const fcc::TrackStateCollection* trackStates;
    bool trackStatesPresent = store.get("TrackStates", trackStates);

    if (trackStatesPresent) {
      for(const auto& trackState : *trackStates){
        track_counter++;
      }
    }

    const fcc::ParticleCollection* MCparticles;
    bool MCparticlesPresent = store.get("mergedGenParticles", MCparticles);

    if (MCparticlesPresent) {
      for(const auto& MCparticle : *MCparticles){
        gen_counter++;
      }
    }

    // cout << "------------------------------------------------" << endl;
    // cout << "Event number: " << iev << endl;
    cout << "Reconstruction counter: " << reco_counter << endl;
    // cout << "TrackState counter: " << track_counter << endl;
    // cout << "Gen counter: " << gen_counter << endl;


    ////////////////////// Text:
    ofstream MyFile;
    string myname = "/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/txt_files/Fake_rate_estimation.txt";
    MyFile.open(myname.c_str(), ios_base::app); // Create and open a text file
    string mystring = to_string(reco_counter)+", ";
    MyFile << mystring;
    MyFile.close();
    ////////////////////////////////

    store.clear();
    reader.endOfEvent();
    // if(iev==1000){break;}
  } // end of loop over events


 cout << "***************** Finished *********************" << endl;
}
