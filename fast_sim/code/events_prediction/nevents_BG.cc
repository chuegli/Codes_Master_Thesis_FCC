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
// 1) It calculates the total number of expected events for the BGs considering
//    an integrated luminosity of 30ab-1. => hist_ntot
// 2) It calculated the number of events present in the sample => hist_n
// 3) It calculates the number of events passing the cuts of the cuts => hist_c1, hist_c2
// 4) It calculates the efficiency of the cut passing => hist_e1, hist_e2
// 5) It calculates the number of expected events to pass the cut => hist_n1, hist_n2
// 6) It saves hist_n1, hist_n2 to .root to use for plotting later
////////////////////////////////////////////////////////////////////////////////

void list_files(string filename_t, string BGstring_t, string HTrange_s_t, double ntot_t);
void make_hist(TChain* myChain_t, string BGstring_t, string HTrange_s_t, double ntot_t);

void nevents_BG(string BGstring) {
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
    cout << "make_efficiency start" << endl;
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


  TH1D* hist_n  = new TH1D("hist_n",  "hist_n; HT [GeV];  Entries / 200 GeV", 500, 0, 1e5); // number of events in the sample
  TH1D* hist_c1 = new TH1D("hist_c1", "hist_c1; HT [GeV]; Entries / 200 GeV", 500, 0, 1e5); // number of events passing the first cut
  TH1D* hist_c2 = new TH1D("hist_c2", "hist_c2; HT [GeV]; Entries / 200 GeV", 500, 0, 1e5); // number of events passing the second cut
  TH1D* hist_c3 = new TH1D("hist_c3", "hist_c3; HT [GeV]; Entries / 200 GeV", 500, 0, 1e5); // number of events passing the second cut


  // Double_t edges[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 200, 300,\
  // 400, 500, 600, 700, 800, 900, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 800, 900, 1000, 2000, 3000, \
  // 4000, 5000, 6000, 7000, 8000, 9000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};
  // Double_t edges[8] = {0, 150, 300, 500, 1000, 2000, 5000, 100000};
  // Int_t NBINS = 7;
  // TH1D* hist_n  = new TH1D("hist_n",  "hist_n; HT [GeV]; Number of entries", NBINS, edges);  // number of events in the sample
  // TH1D* hist_c1 = new TH1D("hist_c1", "hist_c1; HT [GeV]; Number of entries", NBINS, edges); // number of events passing the first cut
  // TH1D* hist_c2 = new TH1D("hist_c2", "hist_c2; HT [GeV]; Number of entries", NBINS, edges); // number of events passing the second cut


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
      double jet_HT = 0;
      for(int i=0; i<n_jets; i++){
          TLorentzVector p4;
          p4.SetXYZM(
              jets_px.At(i),
              jets_py.At(i),
              jets_pz.At(i),
              jets_mass.At(i)
          );
          jet_HT = jet_HT + p4.Pt();
          // leading jet
          if(p4.Pt()>jet_leading_pt){
            jet_leading_pt  = p4.Pt();
            jet_leading_eta = p4.Eta();
          }
      }

      // Reco MET
      TVector2 met;
      met.SetMagPhi(
          met_magnitude.At(0),
          met_phi.At(0)
      );

      /// Filling of histograms:
      if(jet_leading_pt > 1000){hist_c1->Fill(abs(jet_HT));}
      if(met.Mod() > 1000){hist_c2->Fill(abs(jet_HT));}
      if(c3){hist_c3->Fill(abs(jet_HT));}
      hist_n->Fill(abs(jet_HT));

      counter++;
      if(counter%500000==0){
        cout << "Entry: " << counter << endl;
      }
  } // end of reader.Next


  //////////////////////////////////////////////////////////////////////////////
  /////////// Calculate histograms:
  TH1D* hist_ntot = (TH1D*)hist_n->Clone("hist_ntot");
  hist_ntot->Scale(1./hist_n->GetEntries());
  hist_ntot->Scale(ntot_t);

  TH1D* hist_e1 = (TH1D*)hist_c1->Clone("hist_e1");
  hist_e1->Divide(hist_n);

  TH1D* hist_e2 = (TH1D*)hist_c2->Clone("hist_e2");
  hist_e2->Divide(hist_n);

  TH1D* hist_e3 = (TH1D*)hist_c3->Clone("hist_e3");
  hist_e3->Divide(hist_n);

  TH1D* hist_n1 = (TH1D*)hist_e1->Clone("hist_n1");
  hist_n1->Multiply(hist_ntot);

  TH1D* hist_n2 = (TH1D*)hist_e2->Clone("hist_n2");
  hist_n2->Multiply(hist_ntot);

  TH1D* hist_n3 = (TH1D*)hist_e3->Clone("hist_n3");
  hist_n3->Multiply(hist_ntot);


  //////////////////////////////////////////////////////////////////////////////
  //////////////// Save histograms to .root files:
  string rootname = "/afs/cern.ch/user/c/chugli/private/histos/histo_" +BGstring_t+"_"+HTrange_s_t+".root";
  const char* foutname = rootname.c_str();
  cout << foutname << endl;

  auto f = TFile::Open(foutname, "RECREATE");
  hist_n->Write();
  hist_ntot->Write();
  hist_n1->Write();
  hist_n2->Write();
  hist_n3->Write();
  hist_c1->Write();
  hist_c2->Write();
  hist_c3->Write();
  hist_e1->Write();
  hist_e2->Write();
  hist_e3->Write();
  f->Close();

}
