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
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }
    string filename   = argv[1];
    string outputname = argv[2];
    my_make_histo(filename, outputname);

    return 0;
}

void my_make_histo(string rootname, string outputname){
  double t_resolution = 1e-2; // 1e-2 = 10ps

  auto reader = podio::ROOTReader();
  auto store = podio::EventStore();
  reader.openFile(rootname.c_str());
  store.setReader(&reader);
  unsigned nevents= reader.getEntries();

  ////// Pileup & signal comparison (no offline selection):
  // TH1D* h_track_pt     = new TH1D("h_track_pt",     "h_track_pt",     100,-500,5000);
  // TH1D* h_hit_beta     = new TH1D("h_hit_beta",     "h_hit_beta",     200,-2,2);
  // TH1D* h_track_z0     = new TH1D("h_track_z0",     "h_track_z0",     100,-5000,5000);
  // TH1D* h_track_d0     = new TH1D("h_track_d0",     "h_track_d0",     100,-200,200);
  // TH1D* h_track_phi    = new TH1D("h_track_phi",    "h_track_phi",    100,-4,4);
  // TH1D* h_track_theta  = new TH1D("h_track_theta",  "h_track_theta",  100,-2,2);
  // TH1D* h_track_eta    = new TH1D("h_track_eta",    "h_track_eta",    100,-1,10);
  // TH1D* h_track_qOverP = new TH1D("h_track_qOverP", "h_track_qOverP", 100,-5,5);
  // TH1D* h_ntrack       = new TH1D("h_ntrack",       "h_ntrack",       100,1000.5,5000.5);
  // TH1D* h_nhit         = new TH1D("h_nhit",         "h_nhit",         11,-0.5,10.5);

  ////// Pileup & signal comparison (with offline selection):
  /// Offline selection: pt>100GeV and |eta| < 2.5
  // TH1D* h_track_pt     = new TH1D("h_track_pt",     "h_track_pt",     100,-500,5000);
  // TH1D* h_hit_beta     = new TH1D("h_hit_beta",     "h_hit_beta",     200,-2,2);
  // TH1D* h_track_z0     = new TH1D("h_track_z0",     "h_track_z0",     100,-5000,5000);
  // TH1D* h_track_d0     = new TH1D("h_track_d0",     "h_track_d0",     100,-200,200);
  // TH1D* h_track_phi    = new TH1D("h_track_phi",    "h_track_phi",    100,-4,4);
  // TH1D* h_track_theta  = new TH1D("h_track_theta",  "h_track_theta",  100,-2,2);
  // TH1D* h_track_eta    = new TH1D("h_track_eta",    "h_track_eta",    100,-1,3);
  // TH1D* h_track_qOverP = new TH1D("h_track_qOverP", "h_track_qOverP", 100,-5,5);
  // TH1D* h_ntrack       = new TH1D("h_ntrack",       "h_ntrack",       100,1000.5,5000.5);
  // TH1D* h_nhit         = new TH1D("h_nhit",         "h_nhit",         11,-0.5,10.5);


  /////// Signal comparison:
  // TH1D* h_track_pt     = new TH1D("h_track_pt",     "h_track_pt",     100,-500,5000);
  // TH1D* h_hit_beta     = new TH1D("h_hit_beta",     "h_hit_beta",     100,-0.5,1.5);
  // TH1D* h_track_z0     = new TH1D("h_track_z0",     "h_track_z0",     100,-0.05,0.05);
  // TH1D* h_track_d0     = new TH1D("h_track_d0",     "h_track_d0",     100,-0.015,0.015);
  // TH1D* h_track_phi    = new TH1D("h_track_phi",    "h_track_phi",    100,-4,4);
  // TH1D* h_track_theta  = new TH1D("h_track_theta",  "h_track_theta",  100,-2,2);
  // TH1D* h_track_eta    = new TH1D("h_track_eta",    "h_track_eta",    100,-1,10);
  // TH1D* h_track_qOverP = new TH1D("h_track_qOverP", "h_track_qOverP", 100,-0.0035,0.0035);
  // TH1D* h_ntrack       = new TH1D("h_ntrack",       "h_ntrack",       6,-0.5,5.5);
  // TH1D* h_nhit         = new TH1D("h_nhit",         "h_nhit",         11,-0.5,10.5);

  //// Pileup size comparison:
  // TH1D* h_track_pt     = new TH1D("h_track_pt",     "h_track_pt",     100,-1,5);
  // TH1D* h_hit_beta     = new TH1D("h_hit_beta",     "h_hit_beta",     200,-5,5);
  // TH1D* h_track_z0     = new TH1D("h_track_z0",     "h_track_z0",     100,-10000,10000);
  // TH1D* h_track_d0     = new TH1D("h_track_d0",     "h_track_d0",     100,-400,400);
  // TH1D* h_track_phi    = new TH1D("h_track_phi",    "h_track_phi",    100,-4,4);
  // TH1D* h_track_theta  = new TH1D("h_track_theta",  "h_track_theta",  100,-0.3,0.3);
  // TH1D* h_track_eta    = new TH1D("h_track_eta",    "h_track_eta",    100,-1,10);
  // TH1D* h_track_qOverP = new TH1D("h_track_qOverP", "h_track_qOverP", 100,-10,10);
  // TH1D* h_ntrack       = new TH1D("h_ntrack",       "h_ntrack",       100,1000.5,5000.5);
  // TH1D* h_nhit         = new TH1D("h_nhit",         "h_nhit",         11,-0.5,10.5);

  ////// Pileups with selection vs signal:
  TH1D* h_track_pt     = new TH1D("h_track_pt",     "h_track_pt",     100,-500,5000);
  TH1D* h_hit_beta_10  = new TH1D("h_hit_beta_10",  "h_hit_beta_10",  200,-2,2);
  TH1D* h_hit_beta_50  = new TH1D("h_hit_beta_50",  "h_hit_beta_50",  200,-2,2);
  TH1D* h_track_z0     = new TH1D("h_track_z0",     "h_track_z0",     100,-5000,5000);
  TH1D* h_track_d0     = new TH1D("h_track_d0",     "h_track_d0",     100,-200,200);
  TH1D* h_track_phi    = new TH1D("h_track_phi",    "h_track_phi",    100,-4,4);
  TH1D* h_track_theta  = new TH1D("h_track_theta",  "h_track_theta",  100,-2,2);
  TH1D* h_track_eta    = new TH1D("h_track_eta",    "h_track_eta",    100,-1,10);
  TH1D* h_track_qOverP = new TH1D("h_track_qOverP", "h_track_qOverP", 100,-0.5,0.5);
  TH1D* h_nhit         = new TH1D("h_nhit",         "h_nhit",         11,-0.5,10.5);

  double speed_light = 299.792458; //mm/ns

  int tot_counter = 0;
  int tot_selection_counter = 0;
  int tot_selection_counter_masahiko = 0;
  int above_1_track_counter_s = 0; // number of events with more than 1 reco tracks and selection
  int above_1_track_counter = 0; // number of events with more than 1 reco tracks
  int equal_1_track_counter_s = 0; // number of events with more 1 reco tracks and selection
  int equal_1_track_counter = 0; // number of events with 1 reco tracks
  for(unsigned iev=0; iev<nevents; ++iev) {

    // const fcc::MCParticleCollection* MCparticles;
    // bool MCparticlePresents = store.get("GenParticles", MCparticles);

    const fcc::ParticleCollection* particles;
    bool particlesPresent = store.get("TrackRecoParticles", particles);

    double first_x = 0;
    double first_y = 0;
    double first_z = 0;
    double first_t = 0;
    double last_x = 0;
    double last_y = 0;
    double last_z = 0;
    double last_t = 0;

    int tracks_counter = 0;
    int tracks_counter_s = 0;
    if (particlesPresent) {
      for(const auto& particle : *particles){
          for(auto track = particle.tracks_begin(); track != particle.tracks_end(); ++track) {
            if(track->isAvailable()) {
              bool selection = false;
              bool selection_masahiko = false;
              for(auto state = track->states_begin(); state !=track->states_end(); ++state){
                   double cosTheta = cos(state->theta());
                   double eta;
                   if (cosTheta*cosTheta < 1){eta = -0.5* log((1.0-cosTheta)/(1.0+cosTheta));}
                   else{eta = -10e10;}
                   // if(abs(eta)< 2.5 && abs(1./state->qOverP())>100){selection_masahiko = true;}
                   // if(abs(eta)< 2.5 && abs(1./state->qOverP())>20){selection_masahiko = true;}
                   selection_masahiko = true;
                   if(selection_masahiko){
                     h_track_eta   ->Fill(eta);
                     h_track_pt    ->Fill(abs(1./state->qOverP()));
                     h_track_z0    ->Fill(state->z0());
                     h_track_d0    ->Fill(state->d0());
                     h_track_phi   ->Fill(state->phi());
                     h_track_theta ->Fill(state->theta());

                     h_track_qOverP->Fill(state->qOverP());
                   }
                   // if(abs(1./state->qOverP())>100 && abs(state->z0())<=2 && abs(state->d0())<=2 && abs(state->theta())>=0.5 && abs(eta)<2.5 && abs(state->qOverP())<=0.2){selection = true;}
                   if(abs(1./state->qOverP())>90 && abs(state->z0())<=5){selection = true;}
              } // loop over states
              int hit_counter = 0;
              for(auto hit = track->hits_begin(); hit !=track->hits_end(); ++hit){
                  hit_counter++;
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
              }
              h_nhit->Fill(hit_counter);
              double d_x = last_x-first_x;
              double d_y = last_y-first_y;
              double d_z = last_z-first_z;
              double d_t = last_t-first_t;
              double d_S = sqrt(d_x*d_x+d_y*d_y+d_z*d_z);

              if(selection_masahiko){h_hit_beta->Fill(d_S/d_t/speed_light);tot_selection_counter_masahiko++;}
              // if(abs(d_S/d_t/speed_light)>0.25 && abs(d_S/d_t/speed_light)<0.95 && selection){tot_selection_counter++;tracks_counter_s++;}
              if(selection){tot_selection_counter++;tracks_counter_s++;}
              tot_counter++;
              tracks_counter++;
            }
          } // end of loop over reco tracks
      } // end for of particles reco
    } // end of particles present if
    h_ntrack->Fill(tracks_counter);
    // cout << "Number of tracks: " <<tracks_counter<< endl;
    // cout << "track counters: " << tracks_counter << "  " <<tracks_counter_s << endl;
    if(tracks_counter>1){above_1_track_counter++;}
    if(tracks_counter_s>1){above_1_track_counter_s++;}
    if(tracks_counter==1){equal_1_track_counter++;}
    if(tracks_counter_s==1){equal_1_track_counter_s++;}

    store.clear();
    reader.endOfEvent();
    // if(iev==1000){break;}
  } // end of loop over events

  // cout << "Total selectioncounter: " << tot_selection_counter << endl;
  cout << "Total counter: " << tot_counter << endl;
  cout << "Masahiko selection: " << tot_selection_counter_masahiko << endl;
  // cout << "Number of events with more than 1 reco particles without selection: " << above_1_track_counter << endl;
  // cout << "Number of events with more than 1 reco particles with selection: " << above_1_track_counter_s << endl;
  // cout << "Number of events with 1 reco particles without selection: " << equal_1_track_counter << endl;
  // cout << "Number of events with 1 reco particles with selection: " << equal_1_track_counter_s << endl;

  cout << "Write to .root" << endl;
  string sss = outputname;
  auto f1 = TFile::Open(sss.c_str(), "RECREATE");
  h_track_pt    ->Write();
  h_hit_beta    ->Write();
  h_track_z0    ->Write();
  h_track_d0    ->Write();
  h_track_phi   ->Write();
  h_track_theta ->Write();
  h_track_eta   ->Write();
  h_track_qOverP->Write();
  h_ntrack      ->Write();
  h_nhit        ->Write();
  f1->Close();

  cout <<"Delete" << endl;
  delete h_track_pt    ;
  delete h_hit_beta    ;
  delete h_track_z0    ;
  delete h_track_d0    ;
  delete h_track_phi   ;
  delete h_track_theta ;
  delete h_track_eta   ;
  delete h_track_qOverP;
  delete h_ntrack      ;
  delete h_nhit        ;

 cout << "***************** Finished *********************" << endl;
}
