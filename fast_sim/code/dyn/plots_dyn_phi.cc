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
#include <TPaveLabel.h>
#include <TMultiGraph.h>
#include <TGraph.h>
#include <TColor.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TPad.h>

#include <math.h>
#include <typeinfo>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
///////////// What this .cc does:
// !!! Important !!!
// if not already done you need to run first signal_dyn.cc and BG_dyn.cc
//
// This .cc concerns both signals and BGs samples.
//
// 1) It first extracts the dynamic histograms for the BGs and saves them to THStacks
// 2) It does the same for the signals
// 3) It plots both in plot_dyn.pdf

// scp chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/fast_sim/plots/dyn/plots_dyn_phi.pdf ../../plots/dyn/
////////////////////////////////////////////////////////////////////////////////

map<TString, TH1*> make_histograms(TString filename, TString f);

void plots_dyn_phi(){
  ////////// Definition part:
  cout << "********************* Start BG part *********************" << endl;
  string BGtype[5] = {"W+jets","Z+jets","ttbar","topsingle","multijets"};

  int mylength[5] = {7,7,10,1,9};

  string a[] = {"0_150", "150_300", "300_500", "500_1000", "1000_2000", "2000_5000", "5000_100000"};
  string c[] = {"0_600", "600_1200", "1200_2100", "2100_3400", "3400_5300", "5300_8100", "8100_15000",
  "15000_25000", "25000_35000", "35000_100000"};
  string d[] = {""};
  string e[] = {"0_500", "500_1000", "1000_2000", "2000_4000", "4000_7200", "7200_15000",
  "15000_25000", "25000_35000", "35000_100000"};
  string *myfolders[5] = {a,a,c,d,e};

  map<TString, TH1D*> HStack_h;
  map<int, map<TString, TH1D*>> h_map;

  for(int i=0; i<5;i++){
    cout << "********************* Start " << BGtype[i] << " *********************" << endl;
    string name = BGtype[i]+"; #Delta #phi [ ]; Number of entries";

    HStack_h["delta_phi"]   = new TH1D(BGtype[i].c_str(), name.c_str(), 100, -10, 10);

    for(int j=0; j<mylength[i]; j++){
      string filename = "/afs/cern.ch/user/c/chugli/private/fast_sim/histos/histo_dyn_c3_" +BGtype[i]+"_"+myfolders[i][j]+".root";
      const char* dirname = filename.c_str();
      TFile *f = new TFile(dirname);

      TH1D* h_delta_phi   = (TH1D*)f->Get("delta_phi");

      int ii = i+1;

      HStack_h["delta_phi"]  ->SetLineColor(ii);
      HStack_h["delta_phi"]  ->SetMarkerColor(ii);
      HStack_h["delta_phi"]  ->SetLineWidth(2);
      HStack_h["delta_phi"]  ->Add(h_delta_phi);
    } // end of j

    h_map[i] = HStack_h;

  } //end of i

  h_map[4]["delta_phi"]->Scale(1./h_map[4]["delta_phi"]->Integral());
  h_map[0]["delta_phi"]->Scale(1./h_map[0]["delta_phi"]->Integral());
  h_map[2]["delta_phi"]->Scale(1./h_map[2]["delta_phi"]->Integral());
  h_map[3]["delta_phi"]->Scale(1./h_map[3]["delta_phi"]->Integral());
  h_map[1]["delta_phi"]->Scale(1./h_map[1]["delta_phi"]->Integral());

  ////////// Plotting part:
  cout << "********************* Start plotting *********************" << endl;
  TCanvas *canvas = new TCanvas("c","");
  gPad->SetMargin(0.1,0.1,0.1,0.1);//l,r,b,t
  // canvas->SetLogy();
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  h_map[3]["delta_phi"]->GetXaxis()->SetTitle("#Delta #phi [ ]");
  h_map[3]["delta_phi"]->GetYaxis()->SetTitle("Events");
  h_map[3]["delta_phi"]->SetMaximum(0.1);
  // h_map[1]["delta_phi"]->SetMinimum(1e4);
  h_map[3]["delta_phi"]->Draw("hist cp");
  h_map[0]["delta_phi"]->Draw("same hist cp");
  h_map[2]["delta_phi"]->Draw("same hist cp");
  h_map[4]["delta_phi"]->Draw("same hist cp");
  h_map[1]["delta_phi"]->Draw("same hist cp");
  canvas->BuildLegend();
  canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/fast_sim/plots/dyn/plots_dyn_phi.pdf");
  canvas->Close();

}
