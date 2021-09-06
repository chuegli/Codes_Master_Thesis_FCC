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
#include <TSystemFile.h>
#include <TSystemDirectory.h>

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
// 1) It produces histograms for the BG dynamic (leading jet pt, met,...)
// 2) It saves them to .root files
//////////// How to run:
// Location: /afs/cern.ch/user/c/chugli/private/fast_sim/code/dyn/
// Command: root -q "./code/dyn/BG_dyn.cc+(\"multijets\")"
////////////////////////////////////////////////////////////////////////////////

void list_files(string filename_t, string BGstring_t, string HTrange_s_t, double ntot_t);
void make_hist(TChain* myChain_t, string BGstring_t, string HTrange_s_t, double ntot_t);

void BG_dyn(string BGstring) {
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
  string *myfolders[5] = {a,a,c,d,e};

  double da[] = {1479000, 83770, 24930, 10370, 1917, 273.7, 11.11}; //xsec in pb
  double db[] = {465800, 29440, 8958, 3756, 703.8, 102.3, 4.196};
  double dc[] = {32070, 8883, 1737, 284.3, 44.91, 6.484, 0.8583, 0.0219, 0.0004247, 1.459e-5};
  double dd[] = {7524};
  double de[] = {6517000000, 16420000, 1673000, 132000, 7316, 474.9, 7.349, 0.1759, 0.007654};
  double *myxsec[5] = {da,db,dc,dd,de};

  int mylength[5] = {7,7,10,1,9};

  int BGpos = BGtype[BGstring]; // corresponding index to BG type

  double lumi_int = 3e6; //30e6 = 30ab-1, pb-1 => since xsec also in pb-1

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

  // TH1D* h_met         = new TH1D("met",         "met; met p_T [GeV]; Number of entries", 100, -200, 7000);
  // TH1D* h_LgenJet_pt  = new TH1D("LgenJet_pt",  "LgenJet_pt; LgenJet p_T [GeV]; Number of entries", 100, -500, 6000);
  TH1D* h_met         = new TH1D("met",         "met; met p_T [GeV]; Number of entries", 25, 0, 5000);
  TH1D* h_LgenJet_pt  = new TH1D("LgenJet_pt",  "LgenJet_pt; LgenJet p_T [GeV]; Number of entries", 25, 0, 5000);
  TH1D* h_LgenJet_eta = new TH1D("LgenJet_eta", "LgenJet_eta; LgenJet p_T [GeV]; Number of entries", 100, -10, 10);
  TH1D* h_genJet_pt   = new TH1D("genJet_pt",   "genJet; p_T [GeV]; Number of entries", 100, -100, 2500);
  TH1D* h_genJet_eta  = new TH1D("genJet_eta",  "genJet; eta; Number of entries", 100, -10, 10);
  TH1D* h_delta_phi   = new TH1D("delta_phi",   "; #Delta #phi; Number of entries", 100, -10, 10);

  ////////////// Reader Loop:
  int counter = 0;
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

      // Loop over reco jets
      int n_jets = jets_px.GetSize();
      double jet_leading_pt = 0;
      double jet_leading_eta;
      double jet_leading_phi;
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
            jet_leading_eta = p4.Eta();
            jet_leading_phi = p4.Phi();
          }
          if(c3){h_genJet_pt->Fill(p4.Pt());}
          if(c3){h_genJet_eta->Fill(p4.Eta());}
      }
      if(c3){h_LgenJet_pt->Fill(jet_leading_pt);}
      if(c3){h_LgenJet_eta->Fill(jet_leading_eta);}

      // Reco MET
      TVector2 met;
      met.SetMagPhi(
          met_magnitude.At(0),
          met_phi.At(0)
      );
      if(c3){
        h_met->Fill(met.Mod());
        double delta_phi = met.Phi()-jet_leading_phi;
        if(delta_phi>M_PI){delta_phi = delta_phi-2*M_PI;}
        else if(delta_phi<-M_PI){delta_phi = delta_phi+2*M_PI;}
        h_delta_phi->Fill(delta_phi);
        if(met.Mod()>3500){
          cout << "Leading jet pt: " << jet_leading_pt << endl;
          cout << "Leading jet phi: " << jet_leading_phi << endl;
          cout << "Met phi: " << met.Phi() << endl;
          cout << "Delta phi: " << delta_phi << endl;
        }
      }

      counter++;
      if(counter%500000==0){
        cout << "Entry: " << counter << endl;
      }
  } // end of reader.Next


  //////////////////////////////////////////////////////////////////////////////
  //////////////// Save histograms to .root files:
  string rootname = "/afs/cern.ch/user/c/chugli/private/fast_sim/histos/histo_dyn_c3_" +BGstring_t+"_"+HTrange_s_t+".root";
  const char* foutname = rootname.c_str();
  cout << foutname << endl;
  auto f = TFile::Open(foutname, "RECREATE");
  h_met->Write();
  h_LgenJet_pt->Write();
  h_delta_phi->Write();
  // h_LgenJet_eta->Write();
  // h_genJet_pt->Write();
  // h_genJet_eta->Write();
  f->Close();

}
