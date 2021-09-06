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
#include <TROOT.h>
#include <TTree.h>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////
//// What this code does:
//  Put trees into histograms
//
//// How to run it:
// the code is located in: /afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/code/
// 1) Make
// 2)
////////////////////////////////////////////////////////////////////////////////

void my_make_histo(string rootname, string outputname);

int main(int argc, char **argv){
    string filename   = argv[1];
    string outputname = argv[2];
    my_make_histo(filename, outputname);

    return 0;
}

void my_make_histo(string rootname, string outputname){

  //// Pileup & signal comparison (no offline selection):
  TH1D* h_track_pt     = new TH1D("h_track_pt",     "h_track_pt",     100,-500,4000);
  TH1D* h_hit_beta_5   = new TH1D("h_hit_beta_5",   "h_hit_beta_5",   125,0,1.5);
  TH1D* h_hit_beta_10  = new TH1D("h_hit_beta_10",  "h_hit_beta_10",  125,0,1.5);
  TH1D* h_hit_beta_50  = new TH1D("h_hit_beta_50",  "h_hit_beta_50",  125,0,1.5);
  TH1D* h_track_z0     = new TH1D("h_track_z0",     "h_track_z0",     100,-3000,3000);
  TH1D* h_track_d0     = new TH1D("h_track_d0",     "h_track_d0",     100,-200,200);
  TH1D* h_track_phi    = new TH1D("h_track_phi",    "h_track_phi",    100,-4,4);
  TH1D* h_track_theta  = new TH1D("h_track_theta",  "h_track_theta",  100,-2,2);
  TH1D* h_track_eta    = new TH1D("h_track_eta",    "h_track_eta",    100,-0.5,3);
  TH1D* h_track_qOverP = new TH1D("h_track_qOverP", "h_track_qOverP", 100,-0.015,0.015);
  TH1D* h_nhit         = new TH1D("h_nhit",         "h_nhit",         11,-0.5,10.5);

  // TFile *f = new TFile("/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_tree.root"); //default pixel size
  TFile *f = new TFile(rootname.c_str());
  TTree *T = (TTree*)f->Get("t");
  Double_t eta, pt, z0, d0, phi, theta, qOverP, beta_5, beta_10, beta_50, nhits;
  T->SetBranchAddress("eta"    ,&eta    );
  T->SetBranchAddress("pt"     ,&pt     );
  T->SetBranchAddress("z0"     ,&z0     );
  T->SetBranchAddress("d0"     ,&d0     );
  T->SetBranchAddress("phi"    ,&phi    );
  T->SetBranchAddress("theta"  ,&theta  );
  T->SetBranchAddress("qOverP" ,&qOverP );
  T->SetBranchAddress("beta_5" ,&beta_5) ;
  T->SetBranchAddress("beta_10",&beta_10);
  T->SetBranchAddress("beta_50",&beta_50);
  T->SetBranchAddress("nhits"  ,&nhits  );

  //read all entries and fill the histograms
  Int_t nentries = (Int_t)T->GetEntries();
  for (Int_t i=0; i<nentries; i++) {
     T->GetEntry(i);
     h_track_eta   ->Fill(eta);
     h_track_pt    ->Fill(pt);
     h_track_z0    ->Fill(z0);
     h_track_d0    ->Fill(d0);
     h_track_phi   ->Fill(phi);
     h_track_theta ->Fill(theta);
     h_track_qOverP->Fill(qOverP);
     h_hit_beta_5  ->Fill(beta_5);
     h_hit_beta_10 ->Fill(beta_10);
     h_hit_beta_50 ->Fill(beta_50);
     h_nhit        ->Fill(nhits);

  }
  if (gROOT->IsBatch()) return;
  f->Close();

  cout << "Write to .root" << endl;
  // string sss = "/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_tree_histo.root"; // default
  auto f1 = TFile::Open(outputname.c_str(), "RECREATE");
  h_track_pt    ->Write();
  h_hit_beta_5  ->Write();
  h_hit_beta_10 ->Write();
  h_hit_beta_50 ->Write();
  h_track_z0    ->Write();
  h_track_d0    ->Write();
  h_track_phi   ->Write();
  h_track_theta ->Write();
  h_track_eta   ->Write();
  h_track_qOverP->Write();
  h_nhit        ->Write();
  f1->Close();

  cout <<"Delete" << endl;
  delete h_track_pt    ;
  delete h_hit_beta_5  ;
  delete h_hit_beta_10 ;
  delete h_hit_beta_50 ;
  delete h_track_z0    ;
  delete h_track_d0    ;
  delete h_track_phi   ;
  delete h_track_theta ;
  delete h_track_eta   ;
  delete h_track_qOverP;
  delete h_nhit        ;

 cout << "***************** Finished *********************" << endl;
}
