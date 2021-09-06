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

  string rootname2 = "/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_2/winos_for_seeding_tracks_10000.root";
  string rootname1 = "/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_2/winos_for_seeding_tracks_10000_test.root";

  auto reader1 = podio::ROOTReader();
  auto store1 = podio::EventStore();
  reader1.openFile(rootname1.c_str());
  store1.setReader(&reader1);

  TH1D* h_Dx   = new TH1D("h_Dx",   "h_Dx",   200,-0.1,0.1);
  TH1D* h_Dy   = new TH1D("h_Dy",   "h_Dy",   200,-0.1,0.1);
  TH1D* h_Dz   = new TH1D("h_Dz",   "h_Dz",   200,-0.01,0.01);
  TH1D* h_Dt   = new TH1D("h_Dt",   "h_Dt",   200,-0.01,0.01);
  TH1D* h_De   = new TH1D("h_De",   "h_De",   200,-0.01,0.01);
  TH1D* h_Dr   = new TH1D("h_Dr",   "h_Dr",   200,-0.1,0.1);

  int nnn = 10000;

  double x1[nnn];
  double y1[nnn];
  double z1[nnn];
  double t1[nnn];
  double e1[nnn];

  double x2[nnn];
  double y2[nnn];
  double z2[nnn];
  double t2[nnn];
  double e2[nnn];

  double OcellID[nnn];

  for(int iev=0; iev<nnn; ++iev) {

    const fcc::PositionedTrackHitCollection* Shits;
    bool ShitsPresent = store1.get("TrackerHitsPosition", Shits);

    if (ShitsPresent) {
      x1[iev] = 1e8;
      y1[iev] = 1e8;
      z1[iev] = 1e8;
      t1[iev] = 1e8;
      e1[iev] = 1e8;

      int i = 0;
      for(const auto& Shit : *Shits){
        x1[iev] = Shit.position().x;
        y1[iev] = Shit.position().y;
        z1[iev] = Shit.position().z;
        t1[iev] = Shit.core().time;
        e1[iev] = Shit.core().energy;
        // cout << Shit.core().time << "   " << sqrt(Shit.position().x*Shit.position().x+Shit.position().y*Shit.position().y+Shit.position().z*Shit.position().z) << "   " << Shit.core().cellId<< endl;
        OcellID[iev] = Shit.core().cellId;
        i++;
        if(i==1){break;}
      }
    } // end of particles present if

    store1.clear();
    reader1.endOfEvent();
  } // end of loop over events

///////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// 2 //////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

cout << "************** smeared **************" << endl;
vector<double> ScellIDs;

  auto reader2 = podio::ROOTReader();
  auto store2 = podio::EventStore();
  reader2.openFile(rootname2.c_str());
  store2.setReader(&reader2);

  for(int iev=0; iev<nnn; ++iev) {
    const fcc::PositionedTrackHitCollection* Shits;
    bool ShitsPresent = store2.get("SmearedTrackerHits", Shits);

    if (ShitsPresent) {
      x2[iev] = 1e8;
      y2[iev] = 1e8;
      z2[iev] = 1e8;
      t2[iev] = 1e8;
      e2[iev] = 1e8;
      for(const auto& Shit : *Shits){
        if(Shit.core().cellId==OcellID[iev]){
          x2[iev] = Shit.position().x;
          y2[iev] = Shit.position().y;
          z2[iev] = Shit.position().z;
          t2[iev] = Shit.core().time;
          e2[iev] = Shit.core().energy;
          // cout << Shit.core().time << "   " << sqrt(Shit.position().x*Shit.position().x+Shit.position().y*Shit.position().y+Shit.position().z*Shit.position().z) << "   " << Shit.core().cellId<< endl;
        }
      }
    } // end of particles present if

    store2.clear();
    reader2.endOfEvent();
  } // end of loop over events


  for(int i = 0; i< nnn; i++){
    // cout << "Event number " << i<< endl;

    h_Dx->Fill(x1[i]-x2[i]);
    h_Dy->Fill(y1[i]-y2[i]);
    h_Dz->Fill(z1[i]-z2[i]);
    h_Dt->Fill(t1[i]-t2[i]);
    h_De->Fill(e1[i]-e2[i]);
    h_Dr->Fill(sqrt(x1[i]*x1[i]+y1[i]*y1[i])-sqrt(x2[i]*x2[i]+y2[i]*y2[i]));

    // cout << "Dx: " << x1[i]-x2[i] << endl;
    // cout << "Dy: " << y1[i]-y2[i] << endl;
    // cout << "Dz: " << z1[i]-z2[i] << endl;
    // cout << "Dt: " << t1[i]-t2[i] << endl;
    // cout << "De: " << e1[i]-e2[i] << endl;
    // cout << "Dr: " << sqrt(x1[i]*x1[i]+y1[i]*y1[i])-sqrt(x2[i]*x2[i]+y2[i]*y2[i]) << endl;

  }


  cout << "Write to /afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_2/winos_smeared_test.root" << endl;
  string sss = "/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_2/winos_smeared_test.root";
  auto f1 = TFile::Open(sss.c_str(), "RECREATE");
  h_Dx->Write();
  h_Dy->Write();
  h_Dz->Write();
  h_Dt->Write();
  h_De->Write();
  h_Dr->Write();
  f1->Close();

  cout <<"Delete" << endl;
  delete h_Dx;
  delete h_Dy;
  delete h_Dz;
  delete h_Dt;
  delete h_De;
  delete h_Dr;

 cout << "***************** Finished *********************" << endl;
}
