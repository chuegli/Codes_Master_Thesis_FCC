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
  auto pt_true = 3000; // 3000 = 3 TeV
  double res_z = 0.005; //0.001 = 1um

  string rootname1 = "/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_2/winos_for_seeding_tracks_10000.root";
  string rootname2 = "/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_2/winos_for_seeding_tracks_10000_test.root";

  auto reader1 = podio::ROOTReader();
  auto store1 = podio::EventStore();
  reader1.openFile(rootname1.c_str());
  store1.setReader(&reader1);

  TH1D* h_1_pt        = new TH1D("h_1_pt",     "h_1_pt",     100,-500,5000);
  TH1D* h_1_px        = new TH1D("h_1_px",     "h_1_px",     100,-7000,7000);
  TH1D* h_1_py        = new TH1D("h_1_py",     "h_1_py",     100,-7000,7000);
  TH1D* h_1_pz        = new TH1D("h_1_pz",     "h_1_pz",     100,-15000,15000);
  TH1D* h_1_Tpt       = new TH1D("h_1_Tpt",    "h_1_Tpt",    100,-500,5000);
  TH1D* h_1_deltaR    = new TH1D("h_1_deltaR", "h_1_deltaR", 100,-0.0001,0.002);

  TH1D* h_2_pt        = new TH1D("h_2_pt",     "h_2_pt",     100,-500,5000);
  TH1D* h_2_px        = new TH1D("h_2_px",     "h_2_px",     100,-7000,7000);
  TH1D* h_2_py        = new TH1D("h_2_py",     "h_2_py",     100,-7000,7000);
  TH1D* h_2_pz        = new TH1D("h_2_pz",     "h_2_pz",     100,-15000,15000);
  TH1D* h_2_Tpt       = new TH1D("h_2_Tpt",    "h_2_Tpt",    100,-500,5000);
  TH1D* h_2_deltaR    = new TH1D("h_2_deltaR", "h_2_deltaR", 100,-0.0001,0.002);

  TH2D* h2_pt1_vs_pt2 = new TH2D("h2_pt1_vs_pt2", "h2_pt1_vs_pt2", 100,-500,5000,100,-500,5000);

  TH1D* h_Dx   = new TH1D("h_Dx",   "h_Dx",   100,-10,10);
  TH1D* h_Dy   = new TH1D("h_Dy",   "h_Dy",   100,-10,10);
  TH1D* h_Dz   = new TH1D("h_Dz",   "h_Dz",   100,-10,10);
  TH1D* h_Dr   = new TH1D("h_Dr",   "h_Dr",   100,-10,10);
  TH1D* h_Dpt  = new TH1D("h_Dpt",  "h_Dpt",  100,-10,10);
  TH1D* h_Deta = new TH1D("h_Deta", "h_Deta", 100,-10,10);


  double wino_mass = 3000.000+0.000165; //GeV (better cause beta sim 1 comma ca)
  // double speed_light = 299.792458; //mm/ns

  int nnn = 10;

  double b_1_deltaR[nnn];
  double b_1_pt    [nnn];
  double b_1_px    [nnn];
  double b_1_py    [nnn];
  double b_1_pz    [nnn];
  double b_1_Tpt   [nnn];
  double b_1_eta   [nnn];
  double first_1_x [nnn];
  double first_1_y [nnn];
  double first_1_z [nnn];
  double first_1_t [nnn];
  // double last_1_x  [nnn];
  // double last_1_y  [nnn];
  // double last_1_z  [nnn];
  // double last_1_t  [nnn];

  double b_2_deltaR[nnn];
  double b_2_pt    [nnn];
  double b_2_px    [nnn];
  double b_2_py    [nnn];
  double b_2_pz    [nnn];
  double b_2_Tpt   [nnn];
  double b_2_eta   [nnn];
  double first_2_x [nnn];
  double first_2_y [nnn];
  double first_2_z [nnn];
  double first_2_t [nnn];
  // double last_2_x  [nnn];
  // double last_2_y  [nnn];
  // double last_2_z  [nnn];
  // double last_2_t  [nnn];

  for(int iev=0; iev<nnn; ++iev) {
    const fcc::MCParticleCollection* MCparticles;
    bool MCparticlePresents = store1.get("GenParticles", MCparticles);

    TLorentzVector vMC;
    if(MCparticlePresents){
      for(const auto& MCparticle : *MCparticles){
        double local_px = MCparticle.core().p4.px;
        double local_py = MCparticle.core().p4.py;
        double local_pz = MCparticle.core().p4.pz;
        vMC.SetXYZM(local_px,local_py,local_pz,wino_mass);
      }
    }

    const fcc::ParticleCollection* particles1;
    bool particlesPresent1 = store1.get("TrackRecoParticles", particles1);

    if (particlesPresent1) {
      b_1_deltaR[iev] = 1e8;
      b_1_pt    [iev] = 1e8;
      b_1_px    [iev] = 1e8;
      b_1_py    [iev] = 1e8;
      b_1_pz    [iev] = 1e8;
      b_1_Tpt   [iev] = 1e8;
      b_1_eta   [iev] = 1e8;
      first_1_x [iev] = 1e8;
      first_1_y [iev] = 1e8;
      first_1_z [iev] = 1e8;
      first_1_t [iev] = 1e8;
      cout << "Test0" << endl;
      for(const auto& particle : *particles1){

          TLorentzVector v;
          double local_px = particle.core().p4.px;
          double local_py = particle.core().p4.py;
          double local_pz = particle.core().p4.pz;
          double local_mass = wino_mass;
          v.SetXYZM(local_px,local_py,local_pz,local_mass);
          cout << "Test1" << endl;
          for(auto track = particle.tracks_begin(); track != particle.tracks_end(); ++track) {
            cout << "Test2" << endl;
            if(track->isAvailable()) {
              cout << "Test3 !!" << endl;
              if(b_1_deltaR[iev] > v.DeltaR(vMC)){
                cout << "Test4" << endl;
                for(auto state = track->states_begin(); state !=track->states_end(); ++state){
                   cout << "Test5" << endl;
                   b_1_deltaR[iev] = v.DeltaR(vMC);
                   b_1_pt[iev]     = v.Pt();
                   b_1_px[iev]     = v.Px();
                   b_1_py[iev]     = v.Py();
                   b_1_pz[iev]     = v.Pz();
                   b_1_Tpt[iev]    = abs(1./state->qOverP());
                   b_1_eta[iev]    = v.Eta();
                 } // loop over states
                 for(auto hit = track->hits_begin(); hit !=track->hits_end(); ++hit){
                    if(hit==track->hits_begin()){
                      first_1_x[iev] = hit->x();
                      first_1_y[iev] = hit->y();
                      first_1_z[iev] = hit->z();
                      first_1_t[iev] = hit->core().time;
                      cout << "Test6" << endl;
                    }
                    // last_1_x[iev] = hit->x();
                    // last_1_y[iev] = hit->y();
                    // last_1_z[iev] = hit->z();
                    // last_1_t[iev] = hit->core().time;
                 } // end hit loop
              } // closes best if
            } // if available
          } // end of loop over reco tracks
      } // end for of particles reco

      h_1_pt->Fill(b_1_pt[iev]);
      h_1_px->Fill(b_1_px[iev]);
      h_1_py->Fill(b_1_py[iev]);
      h_1_pz->Fill(b_1_pz[iev]);
      h_1_Tpt->Fill(b_1_Tpt[iev]);
      h_1_deltaR->Fill(b_1_deltaR[iev]);
      cout << "Test7" << endl;
    } // end of particles present if

    store1.clear();
    reader1.endOfEvent();
  } // end of loop over events

///////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// 2 //////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

  auto reader2 = podio::ROOTReader();
  auto store2 = podio::EventStore();
  reader2.openFile(rootname2.c_str());
  store2.setReader(&reader2);

  for(int iev=0; iev<nnn; ++iev) {

    b_2_deltaR[iev] = 1e13;
    b_2_pt    [iev] = 1e13;
    b_2_px    [iev] = 1e13;
    b_2_py    [iev] = 1e13;
    b_2_pz    [iev] = 1e13;
    b_2_Tpt   [iev] = 1e13;
    b_2_eta   [iev] = 1e13;
    first_2_x [iev] = 1e13;
    first_2_y [iev] = 1e13;
    first_2_z [iev] = 1e13;
    first_2_t [iev] = 1e13;

    const fcc::MCParticleCollection* MCparticles;
    bool MCparticlePresents = store2.get("GenParticles", MCparticles);

    TLorentzVector vMC;
    if(MCparticlePresents){
      for(const auto& MCparticle : *MCparticles){
        double local_px = MCparticle.core().p4.px;
        double local_py = MCparticle.core().p4.py;
        double local_pz = MCparticle.core().p4.pz;
        vMC.SetXYZM(local_px,local_py,local_pz,wino_mass);
      }
    }

    const fcc::ParticleCollection* particles2;
    bool particlesPresent2 = store2.get("TrackRecoParticles", particles2);

    if (particlesPresent2) {
      b_2_deltaR[iev]=1e8;
      for(const auto& particle : *particles2){

          TLorentzVector v;
          double local_px = particle.core().p4.px;
          double local_py = particle.core().p4.py;
          double local_pz = particle.core().p4.pz;
          double local_mass = wino_mass;
          v.SetXYZM(local_px,local_py,local_pz,local_mass);

          for(auto track = particle.tracks_begin(); track != particle.tracks_end(); ++track) {
            if(track->isAvailable()) {
              if(b_2_deltaR[iev] > v.DeltaR(vMC)){
              for(auto state = track->states_begin(); state !=track->states_end(); ++state){
                   b_2_deltaR[iev] = v.DeltaR(vMC);
                   b_2_pt[iev]     = v.Pt();
                   b_2_px[iev]     = v.Px();
                   b_2_py[iev]     = v.Py();
                   b_2_pz[iev]     = v.Pz();
                   b_2_Tpt[iev]    = abs(1./state->qOverP());
                   b_2_eta[iev]    = v.Eta();
                 } // loop over states
                 for(auto hit = track->hits_begin(); hit !=track->hits_end(); ++hit){
                    if(hit==track->hits_begin()){
                      first_2_x[iev] = hit->x();
                      first_2_y[iev] = hit->y();
                      first_2_z[iev] = hit->z();
                      first_2_t[iev] = hit->core().time;
                    }
                    // last_2_x[iev] = hit->x();
                    // last_2_y[iev] = hit->y();
                    // last_2_z[iev] = hit->z();
                    // last_2_t[iev] = hit->core().time;
                 } // end hit loop
              } // closes best if
            } // if available
          } // end of loop over reco tracks
      } // end for of particles reco

      h_2_pt->Fill(b_2_pt[iev]);
      h_2_px->Fill(b_2_px[iev]);
      h_2_py->Fill(b_2_py[iev]);
      h_2_pz->Fill(b_2_pz[iev]);
      h_2_Tpt->Fill(b_2_Tpt[iev]);
      h_2_deltaR->Fill(b_2_deltaR[iev]);
    } // end of particles present if

    store2.clear();
    reader2.endOfEvent();
  } // end of loop over events

  for(int i = 0; i< nnn; i++){
    cout << "Event number " << i<< endl;
    h2_pt1_vs_pt2->Fill(b_1_pt[i],b_2_pt[i]);

    h_Dx  ->Fill(first_1_x[i]-first_2_x[i]);
    h_Dy  ->Fill(first_1_y[i]-first_2_y[i]);
    h_Dz  ->Fill(first_1_z[i]-first_2_z[i]);
    h_Dr  ->Fill(sqrt(first_1_x[i]*first_1_x[i]+first_1_y[i]*first_1_y[i])-sqrt(first_2_x[i]*first_2_x[i]+first_2_y[i]*first_2_y[i]));
    h_Dpt ->Fill(b_1_pt[i]-b_2_pt[i]);
    h_Deta->Fill(b_1_eta[i]-b_2_eta[i]);

    cout << "Dx: " << first_1_x[i]-first_2_x[i] << endl;
    cout << "Dy: " << first_1_y[i]-first_2_y[i] << endl;
    cout << "Dz: " << first_1_z[i]-first_2_z[i] << endl;
    cout << "Dr: " << sqrt(first_1_x[i]*first_1_x[i]+first_1_y[i]*first_1_y[i])-sqrt(first_2_x[i]*first_2_x[i]+first_2_y[i]*first_2_y[i]) << endl;
    cout << "Dpt: " << b_1_pt[i]-b_2_pt[i] << endl;
    cout << "Deta: " << b_1_eta[i]-b_2_eta[i] << endl;
  }


  cout << "Write to .root" << endl;
  string sss = "/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_2/winos_smeared_test.root";
  auto f1 = TFile::Open(sss.c_str(), "RECREATE");
  h_1_pt       ->Write();
  h_1_px       ->Write();
  h_1_py       ->Write();
  h_1_pz       ->Write();
  h_1_Tpt      ->Write();
  h_1_deltaR   ->Write();
  h_2_pt       ->Write();
  h_2_px       ->Write();
  h_2_py       ->Write();
  h_2_pz       ->Write();
  h_2_Tpt      ->Write();
  h_2_deltaR   ->Write();
  h2_pt1_vs_pt2->Write();
  h_Dx         ->Write();
  h_Dy         ->Write();
  h_Dz         ->Write();
  h_Dr         ->Write();
  h_Dpt        ->Write();
  h_Deta       ->Write();
  f1->Close();

  cout <<"Delete" << endl;
  delete h_1_pt       ;
  delete h_1_px       ;
  delete h_1_py       ;
  delete h_1_pz       ;
  delete h_1_Tpt      ;
  delete h_1_deltaR   ;
  delete h_2_pt       ;
  delete h_2_px       ;
  delete h_2_py       ;
  delete h_2_pz       ;
  delete h_2_Tpt      ;
  delete h_2_deltaR   ;
  delete h2_pt1_vs_pt2;
  delete h_Dx         ;
  delete h_Dy         ;
  delete h_Dz         ;
  delete h_Dr         ;
  delete h_Dpt        ;
  delete h_Deta       ;

 cout << "***************** Finished *********************" << endl;
}
