#include <TFile.h>
#include <TTree.h>
#include <TTreeReader.h>
#include <TTreeReaderArray.h>
#include <TLorentzVector.h>
#include <TVector2.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TLegend.h>
#include <TPaveStats.h>
#include <TChain.h>
#include <TString.h>
#include <TSystemDirectory.h>
#include <TSystemFile.h>

#include <math.h>
#include <typeinfo>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
///////////// What this .cc does:
// This .cc concerns the BG samples only.
//// What it does:
// 1) It produces histograms for the BG dynamic (leading jet pt, met,...) for
// the paper comparison
// 2) It saves them to .root files (histo_dyn_c3_)
//// How to run it:
// Location: /afs/cern.ch/user/c/chugli/private/fast_sim/
// Command: root -q "./code/dyn/BG_kin_sel.cc+(\"multijets\")"
// root -q "BG_kin_sel.cc+(\"multijets\")"
////////////////////////////////////////////////////////////////////////////////

double dphi(double A, double B);
void list_files(string filename_t, string BGstring_t, string HTrange_s_t, double ntot_t);
void make_hist(TChain* myChain_t, string BGstring_t, string HTrange_s_t, double ntot_t);

void BG_kin_sel(string BGstring) {
  //////////////////////////////////////////////////////////////////////////////
  ////////// Definitions:
  map<string, int> BGtype = {
    {"W+jets",0},
    {"Z+jets",1},
    {"ttbar",2},
    {"topsingle",3},
    {"multijets",4}
  };

  map<string,double> HTrange_ntot;

  string a[] = {"0_150", "150_300", "300_500", "500_1000", "1000_2000", "2000_5000", "5000_100000"};
  string c[] = {"0_600", "600_1200", "1200_2100", "2100_3400", "3400_5300", "5300_8100", "8100_15000",
  "15000_25000", "25000_35000", "35000_100000"};
  string d[] = {""};
  string e[] = {"0_500", "500_1000", "1000_2000", "2000_4000", "4000_7200", "7200_15000",
  "15000_25000", "25000_35000", "35000_100000"};
  // string e[] = {"35000_100000"};
  // string e[] = {"4000_7200", "7200_15000","15000_25000", "25000_35000", "35000_100000"};
  string *myfolders[5] = {a,a,c,d,e};

  double da[] = {1479000, 83770, 24930, 10370, 1917, 273.7, 11.11}; //xsec in pb
  double db[] = {465800, 29440, 8958, 3756, 703.8, 102.3, 4.196};
  double dc[] = {32070, 8883, 1737, 284.3, 44.91, 6.484, 0.8583, 0.0219, 0.0004247, 1.459e-5};
  double dd[] = {7524};
  double de[] = {6517000000, 16420000, 1673000, 132000, 7316, 474.9, 7.349, 0.1759, 0.007654};
  // double de[] = {0.007654};
  // double de[] = {7316, 474.9, 7.349, 0.1759, 0.007654};
  double *myxsec[5] = {da,db,dc,dd,de};

  int mylength[5] = {7,7,10,1,9};
  // int mylength[5] = {7,7,10,1,6};
  // int mylength[5] = {7,7,10,1,1};

  int BGpos = BGtype[BGstring]; // corresponding index to BG type

  double lumi_int = 30e6; //pb-1 => since xsec also in pb-1

  string f_start  = "/eos/experiment/fcc/hh/generation/DelphesEvents/fcc_v02/"; //BG on lxplus

  string f_type[5] = {"mgp8_pp_w0123j_4f_HT_","mgp8_pp_z0123j_4f_HT_",
  "mgp8_pp_tt012j_5f_HT_","mgp8_pp_t123j_5f","mgp8_pp_jj012j_5f_HT_"};


  /////////////////////////////////////////////////////////////////////////////
  /////////////// Calculate the tot number of expected entries per HT range:
  for(int j=0; j<mylength[BGpos]; j++){
    double extra = myxsec[BGpos][j]*lumi_int;
    HTrange_ntot.insert(pair<string, double>(myfolders[BGpos][j], extra));
  }


  /////////////////////////////////////////////////////////////////////////////
  /////////////// Calculate the tot number of entries in the samples:
  for(int j = 0; j < mylength[BGpos]; j++){
    string filename = f_start+f_type[BGpos]+myfolders[BGpos][j]+"/";
    cout << "\nStart folder " << myfolders[BGpos][j] << endl;
    list_files(filename, BGstring, myfolders[BGpos][j], HTrange_ntot[myfolders[BGpos][j]]);
  }

} // close main



/////////////////////////////////////////////////////////////////////////////////
///////////////// Functions:
void list_files(string filename_t, string BGstring_t, string HTrange_s_t, double ntot_t){
  const char* dirname = filename_t.c_str();
  cout << dirname << endl;
  TSystemDirectory dir(dirname, dirname);
  TList* files = dir.GetListOfFiles();
  TChain* myChain = new TChain("events");
  if(files){
    TSystemFile* file;
    TString fname;
    TIter next(files);
    while ((file=(TSystemFile*)next())){
      fname = file->GetName();
      if(!file->IsDirectory() && fname.EndsWith(".root")){
        TString mys = dirname+fname;
        myChain->Add(mys);
      }
    } // end of while
    cout << "make histo start" << endl;
    make_hist(myChain, BGstring_t,  HTrange_s_t, ntot_t);
    files->Clear();
  } else{
    cout << endl << "Error in " << HTrange_s_t << endl << endl;
  }
}


void make_hist(TChain* myChain_t, string BGstring_t, string HTrange_s_t, double ntot_t){
  double entries_start = myChain_t->GetEntries();
  cout << "Entries in myChain: " << entries_start << endl;

  ////////////// TTreeReader
  TTreeReader reader(myChain_t);
  // Reco MET
  TTreeReaderArray<float> met_magnitude(reader, "met.magnitude");
  TTreeReaderArray<float> met_phi(reader, "met.phi");
  // Reco Jet
  TTreeReaderArray<float> jets_px(  reader, "genjets04.core.p4.px");
  TTreeReaderArray<float> jets_py(  reader, "genjets04.core.p4.py");
  TTreeReaderArray<float> jets_pz(  reader, "genjets04.core.p4.pz");
  TTreeReaderArray<float> jets_mass(reader, "genjets04.core.p4.mass");
  //04 is refered to the conse size of jet construction: dR = 0.4for anti-kt algorithm
  // Reco Electron
  TTreeReaderArray<float> electrons_px(reader, "electrons.core.p4.px");
  TTreeReaderArray<float> electrons_py(reader, "electrons.core.p4.py");
  TTreeReaderArray<float> electrons_pz(reader, "electrons.core.p4.pz");
  TTreeReaderArray<float> electrons_mass(reader, "electrons.core.p4.mass");
  // Reco Muon
  TTreeReaderArray<float> muons_px(reader, "muons.core.p4.px");
  TTreeReaderArray<float> muons_py(reader, "muons.core.p4.py");
  TTreeReaderArray<float> muons_pz(reader, "muons.core.p4.pz");
  TTreeReaderArray<float> muons_mass(reader, "muons.core.p4.mass");

  //////// 1D histos:
  TH1D* h_eta        = new TH1D("h_eta",       "; Leading jet #eta [ ];        Entries", 100, -6, 6);
  TH1D* h_phi        = new TH1D("h_phi",       "; Leading jet #phi [ ];        Entries", 100, -4, 4);
  TH1D* h_theta      = new TH1D("h_theta",     "; Leading jet #theta [ ];      Entries", 100, -1, 4);
  TH1D* h_beta       = new TH1D("h_beta",      "; Leading jet #beta [ ];       Entries", 100, 0.8, 1.1);
  TH1D* h_gamma      = new TH1D("h_gamma",     "; Leading jet #gamma [ ];      Entries", 100, 0, 5000);
  TH1D* h_betagamma  = new TH1D("h_betagamma", "; Leading jet #beta#gamma [ ]; Entries", 100, 0, 5000);
  TH1D* h_met        = new TH1D("h_met",       "; met p_T [GeV];               Entries", 100, 0, 5000);
  TH1D* h_met_phi    = new TH1D("h_met_phi",   "; met #phi [ ];                Entries", 100, -4, 4);
  TH1D* h_delta_phi  = new TH1D("h_delta_phi", "; #Delta #phi [ ];             Entries", 100, -1, 4);
  TH1D* h_delta_pt   = new TH1D("h_delta_pt",  "; #Delta p_T [GeV];            Entries", 100, 0, 7000);

  TH1D* c1h_eta        = new TH1D("c1h_eta",       "; Leading jet #eta [ ];        Cut MET entries", 100, -4, 4);
  TH1D* c1h_phi        = new TH1D("c1h_phi",       "; Leading jet #phi [ ];        Cut MET entries", 100, -4, 4);
  TH1D* c1h_theta      = new TH1D("c1h_theta",     "; Leading jet #theta [ ];      Cut MET entries", 100, -1, 4);
  TH1D* c1h_beta       = new TH1D("c1h_beta",      "; Leading jet #beta [ ];       Cut MET entries", 100, 0.9, 1.1);
  TH1D* c1h_gamma      = new TH1D("c1h_gamma",     "; Leading jet #gamma [ ];      Cut MET entries", 100, 0, 800);
  TH1D* c1h_betagamma  = new TH1D("c1h_betagamma", "; Leading jet #beta#gamma [ ]; Cut MET entries", 100, 0, 800);
  TH1D* c1h_met        = new TH1D("c1h_met",       "; met p_T [GeV];               Cut MET entries", 100, 3000, 10000);
  TH1D* c1h_met_phi    = new TH1D("c1h_met_phi",   "; met #phi [ ];                Cut MET entries", 100, -4, 4);
  TH1D* c1h_delta_phi  = new TH1D("c1h_delta_phi", "; #Delta #phi [ ];             Cut MET entries", 100, -1, 4);
  TH1D* c1h_delta_pt   = new TH1D("c1h_delta_pt",  "; #Delta p_T [GeV];            Cut MET entries", 100, 0, 10000);

  TH1D* c2h_eta        = new TH1D("c2h_eta",       "; Leading jet #eta [ ];        Cut LJet entries", 100, -4, 4);
  TH1D* c2h_phi        = new TH1D("c2h_phi",       "; Leading jet #phi [ ];        Cut LJet entries", 100, -4, 4);
  TH1D* c2h_theta      = new TH1D("c2h_theta",     "; Leading jet #theta [ ];      Cut LJet entries", 100, -1, 4);
  TH1D* c2h_beta       = new TH1D("c2h_beta",      "; Leading jet #beta [ ];       Cut LJet entries", 100, 0.9, 1.1);
  TH1D* c2h_gamma      = new TH1D("c2h_gamma",     "; Leading jet #gamma [ ];      Cut LJet entries", 100, 0, 1500);
  TH1D* c2h_betagamma  = new TH1D("c2h_betagamma", "; Leading jet #beta#gamma [ ]; Cut LJet entries", 100, 0, 1500);
  TH1D* c2h_met        = new TH1D("c2h_met",       "; met p_T [GeV];               Cut LJet entries", 100, 0, 10000);
  TH1D* c2h_met_phi    = new TH1D("c2h_met_phi",   "; met #phi [ ];                Cut LJet entries", 100, -4, 4);
  TH1D* c2h_delta_phi  = new TH1D("c2h_delta_phi", "; #Delta #phi [ ];             Cut LJet entries", 100, -1, 4);
  TH1D* c2h_delta_pt   = new TH1D("c2h_delta_pt",  "; #Delta p_T [GeV];            Cut LJet entries", 100, 0, 10000);

  //////// 2D histos:
  TH2D* Jh_eta        = new TH2D("Jh_eta",       "; Leading jet #eta [ ];        Leading jet p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
  TH2D* Jh_phi        = new TH2D("Jh_phi",       "; Leading jet #phi [ ];        Leading jet p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
  TH2D* Jh_theta      = new TH2D("Jh_theta",     "; Leading jet #theta [ ];      Leading jet p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
  TH2D* Jh_beta       = new TH2D("Jh_beta",      "; Leading jet #beta [ ];       Leading jet p_T [GeV]; Entries", 100, -1.2, 1.2,  100,0,5000);
  TH2D* Jh_gamma      = new TH2D("Jh_gamma",     "; Leading jet #gamma [ ];      Leading jet p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);
  TH2D* Jh_betagamma  = new TH2D("Jh_betagamma", "; Leading jet #beta#gamma [ ]; Leading jet p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);
  TH2D* Jh_met        = new TH2D("Jh_met",       "; met p_T [GeV];               Leading jet p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);
  TH2D* Jh_met_phi    = new TH2D("Jh_met_phi",   "; met #phi [ ];                Leading jet p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
  TH2D* Jh_delta_phi  = new TH2D("Jh_delta_phi", "; #Delta #phi [ ];             Leading jet p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
  TH2D* Jh_delta_pt   = new TH2D("Jh_delta_pt",  "; #Delta p_T [GeV];            Leading jet p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);

  TH2D* Mh_eta        = new TH2D("Mh_eta",       "; Leading jet #eta [ ];        MET p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
  TH2D* Mh_phi        = new TH2D("Mh_phi",       "; Leading jet #phi [ ];        MET p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
  TH2D* Mh_theta      = new TH2D("Mh_theta",     "; Leading jet #theta [ ];      MET p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
  TH2D* Mh_beta       = new TH2D("Mh_beta",      "; Leading jet #beta [ ];       MET p_T [GeV]; Entries", 100, -1.2, 1.2,  100,0,5000);
  TH2D* Mh_gamma      = new TH2D("Mh_gamma",     "; Leading jet #gamma [ ];      MET p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);
  TH2D* Mh_betagamma  = new TH2D("Mh_betagamma", "; Leading jet #beta#gamma [ ]; MET p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);
  TH2D* Mh_met        = new TH2D("Mh_met",       "; met p_T [GeV];               MET p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);
  TH2D* Mh_met_phi    = new TH2D("Mh_met_phi",   "; met #phi [ ];                MET p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
  TH2D* Mh_delta_phi  = new TH2D("Mh_delta_phi", "; #Delta #phi [ ];             MET p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
  TH2D* Mh_delta_pt   = new TH2D("Mh_delta_pt",  "; #Delta p_T [GeV];            MET p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);


  ////////////// Reader Loop:
  int counter = 0;
  int counter_veto = 0;
  int counter_phi = 0;
  int counter_veto_phi = 0;
  int counter_tot = 0;
  while(reader.Next()){
      bool c3 = true;
      // Loop over reco electrons
      int n_electrons = electrons_px.GetSize();
      for(int i=0; i<n_electrons; i++){
          TLorentzVector p4;
          p4.SetXYZM(
              electrons_px.At(i),
              electrons_py.At(i),
              electrons_pz.At(i),
              electrons_mass.At(i)
          );
          if(p4.Pt()>10){c3=false;}
      }
      // Loop over reco muons
      int n_muons = muons_px.GetSize();
      for(int i=0; i<n_muons; i++){
            TLorentzVector p4;
            p4.SetXYZM(
                muons_px.At(i),
                muons_py.At(i),
                muons_pz.At(i),
                muons_mass.At(i)
            );
            if(p4.Pt()>10){c3=false;}
      }

      // Reco MET
      TVector2 met;
      met.SetMagPhi(
          met_magnitude.At(0),
          met_phi.At(0)
      );

      // Loop over reco jets
      int n_jets = jets_px.GetSize();
      double L_pt    = 0;
      double L_phi   = 0;
      double L_eta   = 0;
      double L_theta = 0;
      double L_beta  = 0;
      double L_gamma = 0;
      double delta_phi = 100;
      for(int i=0; i<n_jets; i++){
          TLorentzVector p4;
          p4.SetXYZM(
              jets_px.At(i),
              jets_py.At(i),
              jets_pz.At(i),
              jets_mass.At(i)
          );
          // leading jet
          if(p4.Pt()>L_pt){
            L_pt    = p4.Pt();
            L_phi   = p4.Phi();
            L_eta   = p4.Eta();
            L_theta = p4.Theta();
            L_beta  = p4.Beta();
            L_gamma = p4.Gamma();
          }
          // cout << "Met phi: " << met.Phi() << " mio met: " << met.Phi()-M_PI << " masahikos met: " << dphi(met.Phi(),M_PI) << " test met: " << dphi(met.Phi(),0) << endl;
          // cout << "old delta phi: " << dphi(p4.Phi(),met.Phi()-M_PI) << " new delta phi: " << dphi(p4.Phi(),dphi(met.Phi(),0)) << endl;
          if(p4.Pt()>100){delta_phi = min(delta_phi,abs(dphi(p4.Phi(),dphi(met.Phi(),0))));}
      }
      // delta_phi = abs(dphi(L_phi,dphi(met.Phi(),0)));

      if(met.Mod() > 4000 && L_pt >1000){
        if(c3){counter_veto++;}
        if(abs(delta_phi)>0.5){counter_phi++;}
        if(c3 && abs(delta_phi)>0.5){counter_veto_phi++;}
        counter_tot++;
      }

      if(c3){
        h_eta      ->Fill(L_eta);
        h_phi      ->Fill(L_phi);
        h_theta    ->Fill(L_theta);
        h_beta     ->Fill(L_beta);
        h_gamma    ->Fill(L_gamma);
        h_betagamma->Fill(L_beta*L_gamma);
        h_met      ->Fill(met.Mod());
        h_met_phi  ->Fill(dphi(met.Phi(),0));
        h_delta_phi->Fill(delta_phi);
        h_delta_pt ->Fill(abs(met.Mod()-L_pt));
        Jh_eta      ->Fill(L_eta,L_pt);
        Jh_phi      ->Fill(L_phi,L_pt);
        Jh_theta    ->Fill(L_theta,L_pt);
        Jh_beta     ->Fill(L_beta,L_pt);
        Jh_gamma    ->Fill(L_gamma,L_pt);
        Jh_betagamma->Fill(L_beta*L_gamma,L_pt);
        Jh_met      ->Fill(met.Mod(),L_pt);
        Jh_met_phi  ->Fill(dphi(met.Phi(),0),L_pt);
        Jh_delta_phi->Fill(delta_phi,L_pt);
        Jh_delta_pt ->Fill(abs(met.Mod()-L_pt),L_pt);
        Mh_eta      ->Fill(L_eta,met.Mod());
        Mh_phi      ->Fill(L_phi,met.Mod());
        Mh_theta    ->Fill(L_theta,met.Mod());
        Mh_beta     ->Fill(L_beta,met.Mod());
        Mh_gamma    ->Fill(L_gamma,met.Mod());
        Mh_betagamma->Fill(L_beta*L_gamma,met.Mod());
        Mh_met      ->Fill(met.Mod(),met.Mod());
        Mh_met_phi  ->Fill(dphi(met.Phi(),0),met.Mod());
        Mh_delta_phi->Fill(delta_phi,met.Mod());
        Mh_delta_pt ->Fill(abs(met.Mod()-L_pt),met.Mod());
        if(met.Mod()>3500){
          c1h_eta      ->Fill(L_eta);
          c1h_phi      ->Fill(L_phi);
          c1h_theta    ->Fill(L_theta);
          c1h_beta     ->Fill(L_beta);
          c1h_gamma    ->Fill(L_gamma);
          c1h_betagamma->Fill(L_beta*L_gamma);
          c1h_met      ->Fill(met.Mod());
          c1h_met_phi  ->Fill(dphi(met.Phi(),0));
          c1h_delta_phi->Fill(delta_phi);
          c1h_delta_pt ->Fill(abs(met.Mod()-L_pt));
        }
        if(L_pt>3500){
          c2h_eta      ->Fill(L_eta);
          c2h_phi      ->Fill(L_phi);
          c2h_theta    ->Fill(L_theta);
          c2h_beta     ->Fill(L_beta);
          c2h_gamma    ->Fill(L_gamma);
          c2h_betagamma->Fill(L_beta*L_gamma);
          c2h_met      ->Fill(met.Mod());
          c2h_met_phi  ->Fill(dphi(met.Phi(),0));
          c2h_delta_phi->Fill(delta_phi);
          c2h_delta_pt ->Fill(abs(met.Mod()-L_pt));
        }
      }

      counter++;
      if(counter%100000==0){
        cout << "Entry: " << counter << endl;
      }
  } // end of reader.Next

  cout << "*********************************************************" << endl;
  cout << "Total counter: " << counter_tot << endl;
  cout << "Passing veto: " << counter_veto << endl;
  cout << "Passing phi: " << counter_phi << endl;
  cout << "Passing veto and phi: " << counter_veto_phi << endl;
  cout << "Super total: " << counter << endl;
  cout <<"*********************************************************" << endl << endl;


  //////////////////////////////////////////////////////////////////////////////
  //////////////// Save histograms to .root files:
  string rootname = "/afs/cern.ch/work/c/chugli/private/fast_sim/histo_kin_sel_" +BGstring_t+"_"+HTrange_s_t+".root";
  const char* foutname = rootname.c_str();
  cout << foutname << endl;
  auto f = TFile::Open(foutname, "RECREATE");
  h_eta        ->Write();
  h_phi        ->Write();
  h_theta      ->Write();
  h_beta       ->Write();
  h_gamma      ->Write();
  h_betagamma  ->Write();
  h_met        ->Write();
  h_met_phi    ->Write();
  h_delta_phi  ->Write();
  h_delta_pt   ->Write();
  Jh_eta       ->Write();
  Jh_phi       ->Write();
  Jh_theta     ->Write();
  Jh_beta      ->Write();
  Jh_gamma     ->Write();
  Jh_betagamma ->Write();
  Jh_met       ->Write();
  Jh_met_phi   ->Write();
  Jh_delta_phi ->Write();
  Jh_delta_pt  ->Write();
  Mh_eta       ->Write();
  Mh_phi       ->Write();
  Mh_theta     ->Write();
  Mh_beta      ->Write();
  Mh_gamma     ->Write();
  Mh_betagamma ->Write();
  Mh_met       ->Write();
  Mh_met_phi   ->Write();
  Mh_delta_phi ->Write();
  Mh_delta_pt  ->Write();
  c1h_eta      ->Write();
  c1h_phi      ->Write();
  c1h_theta    ->Write();
  c1h_beta     ->Write();
  c1h_gamma    ->Write();
  c1h_betagamma->Write();
  c1h_met      ->Write();
  c1h_met_phi  ->Write();
  c1h_delta_phi->Write();
  c1h_delta_pt ->Write();
  c2h_eta      ->Write();
  c2h_phi      ->Write();
  c2h_theta    ->Write();
  c2h_beta     ->Write();
  c2h_gamma    ->Write();
  c2h_betagamma->Write();
  c2h_met      ->Write();
  c2h_met_phi  ->Write();
  c2h_delta_phi->Write();
  c2h_delta_pt ->Write();
  f->Close();


    delete h_eta        ;
    delete h_phi        ;
    delete h_theta      ;
    delete h_beta       ;
    delete h_gamma      ;
    delete h_betagamma  ;
    delete h_met        ;
    delete h_met_phi    ;
    delete h_delta_phi  ;
    delete h_delta_pt   ;
    delete Jh_eta       ;
    delete Jh_phi       ;
    delete Jh_theta     ;
    delete Jh_beta      ;
    delete Jh_gamma     ;
    delete Jh_betagamma ;
    delete Jh_met       ;
    delete Jh_met_phi   ;
    delete Jh_delta_phi ;
    delete Jh_delta_pt  ;
    delete Mh_eta       ;
    delete Mh_phi       ;
    delete Mh_theta     ;
    delete Mh_beta      ;
    delete Mh_gamma     ;
    delete Mh_betagamma ;
    delete Mh_met       ;
    delete Mh_met_phi   ;
    delete Mh_delta_phi ;
    delete Mh_delta_pt  ;
    delete c1h_eta      ;
    delete c1h_phi      ;
    delete c1h_theta    ;
    delete c1h_beta     ;
    delete c1h_gamma    ;
    delete c1h_betagamma;
    delete c1h_met      ;
    delete c1h_met_phi  ;
    delete c1h_delta_phi;
    delete c1h_delta_pt ;
    delete c2h_eta      ;
    delete c2h_phi      ;
    delete c2h_theta    ;
    delete c2h_beta     ;
    delete c2h_gamma    ;
    delete c2h_betagamma;
    delete c2h_met      ;
    delete c2h_met_phi  ;
    delete c2h_delta_phi;
    delete c2h_delta_pt ;

}

double dphi(double A, double B){
  double delta_phi = A-B;
  if(delta_phi>=M_PI){delta_phi = delta_phi-2*M_PI;}
  else if(delta_phi<-M_PI){delta_phi = delta_phi+2*M_PI;}
  return delta_phi;
}
