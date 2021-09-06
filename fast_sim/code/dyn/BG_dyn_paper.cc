#include <TFile.h>
#include <TTree.h>
#include <TTreeReader.h>
#include <TTreeReaderArray.h>
#include <TLorentzVector.h>
#include <TVector2.h>
#include <TH1D.h>
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
// Command: root -q "./code/dyn/BG_dyn_paper.cc+(\"multijets\")"
////////////////////////////////////////////////////////////////////////////////

double dphi(double A, double B);
void list_files(string filename_t, string BGstring_t, string HTrange_s_t, double ntot_t);
void make_hist(TChain* myChain_t, string BGstring_t, string HTrange_s_t, double ntot_t);

void BG_dyn_paper(string BGstring) {
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
  // string e[] = {"15000_25000", "25000_35000", "35000_100000"};
  string *myfolders[5] = {a,a,c,d,e};

  double da[] = {1479000, 83770, 24930, 10370, 1917, 273.7, 11.11}; //xsec in pb
  double db[] = {465800, 29440, 8958, 3756, 703.8, 102.3, 4.196};
  double dc[] = {32070, 8883, 1737, 284.3, 44.91, 6.484, 0.8583, 0.0219, 0.0004247, 1.459e-5};
  double dd[] = {7524};
  double de[] = {6517000000, 16420000, 1673000, 132000, 7316, 474.9, 7.349, 0.1759, 0.007654};
  // double de[] = {7.349, 0.1759, 0.007654};
  double *myxsec[5] = {da,db,dc,dd,de};

  int mylength[5] = {7,7,10,1,9};
  // int mylength[5] = {7,7,10,1,3};

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

  TH1D* h_met  = new TH1D("h_met",  "met; met p_T [GeV]; Number of entries",            25, 0, 5000);
  TH1D* h_pt   = new TH1D("h_pt",   "LgenJet_pt; LgenJet p_T [GeV]; Number of entries", 25, 0, 5000);
  TH1D* hh_met = new TH1D("hh_met", "met; met p_T [GeV]; Number of entries",            25, 0, 5000);
  TH1D* hh_pt  = new TH1D("hh_pt",  "LgenJet_pt; LgenJet p_T [GeV]; Number of entries", 25, 0, 5000);

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
      double jet_leading_pt = 0;
      double jet_leading_phi = 0;
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
          if(p4.Pt()>jet_leading_pt){
            jet_leading_pt  = p4.Pt();
            jet_leading_phi = p4.Phi();
          }
          // delta_phi = min(delta_phi,abs(dphi(p4.Phi(),dphi(met.Phi(),0))));
          if(p4.Pt()>100){delta_phi = min(delta_phi,abs(dphi(p4.Phi(),dphi(met.Phi(),0))));}
      }
      // delta_phi = abs(dphi(jet_leading_phi,dphi(met.Phi(),0)));

      if(met.Mod() > 4000 && jet_leading_pt >1000){
        if(c3){counter_veto++;}
        if(abs(delta_phi)>0.5){counter_phi++;}
        if(c3 && abs(delta_phi)>0.5){counter_veto_phi++;}
        counter_tot++;
      }
      // if(c3 && abs(delta_phi)>0.5){
      //     h_met->Fill(met.Mod());
      //     h_pt->Fill(jet_leading_pt);
      // }
      if(c3){
          h_met->Fill(met.Mod());
          h_pt->Fill(jet_leading_pt);
      }
      hh_met->Fill(met.Mod());
      hh_pt->Fill(jet_leading_pt);

      counter++;
      if(counter%100000==0){
        cout << "Entry: " << counter << endl;
      }
  } // end of reader.Next


  //////////////////////////////////////////////////////////////////////////////
  /////////// Calculate histograms:
  // leading jet pt:
  TH1D* hh_pt_tot = (TH1D*)hh_pt->Clone("hh_pt_tot");
  hh_pt_tot->Scale(1./hh_pt->GetEntries());
  hh_pt_tot->Scale(ntot_t);

  TH1D* h_pt_e = (TH1D*)h_pt->Clone("h_pt_e");
  h_pt_e->Divide(hh_pt);

  TH1D* h_pt_n = (TH1D*)h_pt_e->Clone("h_pt_n");
  h_pt_n->Multiply(hh_pt_tot);

  // MET:
  TH1D* hh_met_tot = (TH1D*)hh_met->Clone("hh_met_tot");
  hh_met_tot->Scale(1./hh_met->GetEntries());
  hh_met_tot->Scale(ntot_t);

  TH1D* h_met_e = (TH1D*)h_met->Clone("h_met_e");
  h_met_e->Divide(hh_met);

  TH1D* h_met_n = (TH1D*)h_met_e->Clone("h_met_n");
  h_met_n->Multiply(hh_met_tot);

  cout << "*********************************************************" << endl;
  cout << "Total counter: " << counter_tot << endl;
  cout << "Passing veto: " << counter_veto << endl;
  cout << "Passing phi: " << counter_phi << endl;
  cout << "Passing veto and phi: " << counter_veto_phi << endl;
  cout <<"*********************************************************" << endl << endl;

  //////////////////////////////////////////////////////////////////////////////
  //////////////// Save histograms to .root files:
  string rootname = "/afs/cern.ch/user/c/chugli/private/fast_sim/histos/histo_dyn_c3_" +BGstring_t+"_"+HTrange_s_t+".root";
  const char* foutname = rootname.c_str();
  cout << foutname << endl;
  auto f = TFile::Open(foutname, "RECREATE");
  h_met     ->Write(); // histogram with just the sample number of events with lepton veto
  h_pt      ->Write(); // histogram with just the sample number of events with lepton veto
  hh_pt     ->Write(); // histogram with just the sample number without any selection
  hh_met    ->Write(); // histogram with just the sample number without any selection
  hh_pt_tot ->Write(); // histogram with the expected number of events without any selection
  hh_met_tot->Write(); // histogram with the expected number of events without any selection
  h_pt_e    ->Write(); // histogram with the efficiency of the lepton selection
  h_met_e   ->Write(); // histogram with the efficiency of the lepton selection
  h_pt_n    ->Write(); // histogram with the expected number of events with lepton veto
  h_met_n   ->Write(); // histogram with the expected number of events with lepton veto
  f->Close();

}

double dphi(double A, double B){
  double delta_phi = A-B;
  if(delta_phi>=M_PI){delta_phi = delta_phi-2*M_PI;}
  else if(delta_phi<-M_PI){delta_phi = delta_phi+2*M_PI;}
  return delta_phi;
}
