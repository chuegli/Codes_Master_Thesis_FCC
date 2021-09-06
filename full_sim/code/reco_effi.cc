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

void my_make_histo();

int main(int argc, char **argv){
    my_make_histo();

    return 0;
}

void my_make_histo(){
  string rootname ="/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_10000.root";

  auto reader = podio::ROOTReader();
  auto store = podio::EventStore();
  reader.openFile(rootname);
  store.setReader(&reader);
  double nevents = 10000;

  int reco_counter = 0;
  for(unsigned iev=0; iev<nevents; ++iev) {

    const fcc::ParticleCollection* particles;
    bool particlesPresent = store.get("TrackRecoParticles", particles);

    bool bool_reco = false;
    if (particlesPresent) {
      for(const auto& particle : *particles){
          bool_reco = true;
      } // end for of particles reco
    } // end of particles present if
    if(bool_reco){reco_counter++;}

    store.clear();
    reader.endOfEvent();
    // if(iev==1000){break;}
  } // end of loop over events


  cout << "Reconstruction efficiency: " << reco_counter << "  " << nevents << "  " << reco_counter/nevents << endl;

 cout << "***************** Finished *********************" << endl;
}
