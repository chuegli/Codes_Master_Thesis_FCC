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

// scp 
////////////////////////////////////////////////////////////////////////////////

map<TString, TH1*> make_histograms(TString filename, TString f);

void plots_dyn(){
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
  // for(int i=0; i<4;i++){
    cout << "********************* Start " << BGtype[i] << " *********************" << endl;
    const char* BGchar = BGtype[i].c_str();
    string name = BGtype[i]+"; met [GeV]; Number of entries";
    const char* name1 = name.c_str();
    name = BGtype[i]+"; LgenJet p_T [GeV]; Number of entries";
    const char* name2 = name.c_str();
    name = BGtype[i]+"; #Delta #phi [ ]; Number of entries";
    const char* name3 = name.c_str();
    // name = BGtype[i]+"; LgenJet eta [GeV]; Number of entries";
    // const char* name3 = name.c_str();
    // name = BGtype[i]+"; genJet p_T [GeV]; Number of entries";
    // const char* name4 = name.c_str();
    // name = BGtype[i]+"; genJet eta; Number of entries";
    // const char* name5 = name.c_str();
    HStack_h["met"]         = new TH1D(BGchar, name1, 25, 0, 5000);
    HStack_h["LgenJet_pt"]  = new TH1D(BGchar, name2, 25, 0, 5000);
    HStack_h["delta_phi"]   = new TH1D(BGchar, name3, 100, -5, 5);
    // HStack_h["met"]         = new TH1D(BGchar, name1, 100, -200, 7000);
    // HStack_h["LgenJet_pt"]  = new TH1D(BGchar, name2, 100, -500, 6000);
    // HStack_h["LgenJet_eta"] = new TH1D(BGchar, name3, 100, -10, 10);
    // HStack_h["genJet_pt"]   = new TH1D(BGchar, name4, 100, -100, 2500);
    // HStack_h["genJet_eta"]  = new TH1D(BGchar, name5, 100, -10, 10);

    for(int j=0; j<mylength[i]; j++){
      string filename = "/afs/cern.ch/user/c/chugli/private/fast_sim/histos/histo_dyn_c3_" +BGtype[i]+"_"+myfolders[i][j]+".root";
      const char* dirname = filename.c_str();
      TFile *f = new TFile(dirname);

      TH1D* h_met         = (TH1D*)f->Get("met");
      TH1D* h_LgenJet_pt  = (TH1D*)f->Get("LgenJet_pt");
      TH1D* h_delta_phi   = (TH1D*)f->Get("delta_phi");
      // TH1D* h_LgenJet_eta = (TH1D*)f->Get("LgenJet_eta");
      // TH1D* h_genJet_pt   = (TH1D*)f->Get("genJet_pt");
      // TH1D* h_genJet_eta  = (TH1D*)f->Get("genJet_eta");

      int ii = i+1;

      HStack_h["met"]        ->SetLineColor(ii);
      HStack_h["LgenJet_pt"] ->SetLineColor(ii);
      HStack_h["delta_phi"]  ->SetLineColor(ii);
      // HStack_h["LgenJet_eta"]->SetLineColor(ii);
      // HStack_h["genJet_pt"]  ->SetLineColor(ii);
      // HStack_h["genJet_eta"] ->SetLineColor(ii);

      HStack_h["met"]        ->SetMarkerColor(ii);
      HStack_h["LgenJet_pt"] ->SetMarkerColor(ii);
      HStack_h["delta_phi"]  ->SetMarkerColor(ii);
      // HStack_h["LgenJet_eta"]->SetMarkerColor(ii);
      // HStack_h["genJet_pt"]  ->SetMarkerColor(ii);
      // HStack_h["genJet_eta"] ->SetMarkerColor(ii);

      HStack_h["met"]        ->SetLineWidth(2);
      HStack_h["LgenJet_pt"] ->SetLineWidth(2);
      HStack_h["delta_phi"]  ->SetLineWidth(2);
      // HStack_h["LgenJet_eta"]->SetLineWidth(2);
      // HStack_h["genJet_pt"]  ->SetLineWidth(2);
      // HStack_h["genJet_eta"] ->SetLineWidth(2);

      HStack_h["met"]        ->Add(h_met);
      HStack_h["LgenJet_pt"] ->Add(h_LgenJet_pt);
      HStack_h["delta_phi"]  ->Add(h_delta_phi);
      // HStack_h["LgenJet_eta"]->Add(h_LgenJet_eta);
      // HStack_h["genJet_pt"]  ->Add(h_genJet_pt);
      // HStack_h["genJet_eta"] ->Add(h_genJet_eta);
    } // end of j

    h_map[i] = HStack_h;

  } //end of i

  /////////////////////////////////////////////////////////////////////////////
  /////////////////// Signal part:
  cout << "********************* Start signal part *********************" << endl;
  string f_type1  = "C1N1";
  string f_type2  = "C1C1";
  string f_middle[40];

  for (int j=0; j<2; j++){
      string ftype;
      int ii;
      if(j==0){ftype=f_type1;ii=6;}
      else{ftype=f_type2;ii=7;}
      cout << "********************* Start " << ftype << " *********************" << endl;
      string name = ftype+"; met[GeV]; Number of entries";
      const char* name1 = name.c_str();
      name = ftype+"; LgenJet p_T [GeV]; Number of entries";
      const char* name2 = name.c_str();
      // name = ftype+"; LgenJet eta [GeV]; Number of entries";
      // const char* name3 = name.c_str();
      // name = ftype+"; genJet p_T [GeV]; Number of entries";
      // const char* name4 = name.c_str();
      // name = ftype+"; genJet eta; Number of entries";
      // const char* name5 = name.c_str();
      HStack_h["met"]         = new TH1D("", name1, 25, 0, 5000);
      HStack_h["LgenJet_pt"]  = new TH1D("", name2, 25, 0, 5000);
      // HStack_h["met"]         = new TH1D("", name1, 100, -200, 7000);
      // HStack_h["LgenJet_pt"]  = new TH1D("", name2, 100, -500, 6000);
      // HStack_h["LgenJet_eta"] = new TH1D("", name3, 100, -10, 10);
      // HStack_h["genJet_pt"]   = new TH1D("", name4, 100, -100, 2500);
      // HStack_h["genJet_eta"]  = new TH1D("", name5, 100, -10, 10);
      for(int i = 0; i < 40; i++){
        f_middle[i] = to_string(700+100*i);
        string filename = "/afs/cern.ch/user/c/chugli/private/fast_sim/histos/histo_dyn_c3_" +ftype+"_"+f_middle[i]+".root";
        const char* dirname = filename.c_str();
        TFile *f = new TFile(dirname);

        TH1D* h_met         = (TH1D*)f->Get("met");
        TH1D* h_LgenJet_pt  = (TH1D*)f->Get("LgenJet_pt");
        // TH1D* h_LgenJet_eta = (TH1D*)f->Get("LgenJet_eta");
        // TH1D* h_genJet_pt   = (TH1D*)f->Get("genJet_pt");
        // TH1D* h_genJet_eta  = (TH1D*)f->Get("genJet_eta");

        //////
        h_met->Scale(1000);
        h_LgenJet_pt->Scale(1000);
        //////

        HStack_h["met"]        ->SetLineColor(ii);
        HStack_h["LgenJet_pt"] ->SetLineColor(ii);
        // HStack_h["LgenJet_eta"]->SetLineColor(ii);
        // HStack_h["genJet_pt"]  ->SetLineColor(ii);
        // HStack_h["genJet_eta"] ->SetLineColor(ii);

        HStack_h["met"]        ->SetMarkerColor(ii);
        HStack_h["LgenJet_pt"] ->SetMarkerColor(ii);
        // HStack_h["LgenJet_eta"]->SetMarkerColor(ii);
        // HStack_h["genJet_pt"]  ->SetMarkerColor(ii);
        // HStack_h["genJet_eta"] ->SetMarkerColor(ii);

        HStack_h["met"]        ->SetLineWidth(2);
        HStack_h["LgenJet_pt"] ->SetLineWidth(2);
        // HStack_h["LgenJet_eta"]->SetLineWidth(2);
        // HStack_h["genJet_pt"]  ->SetLineWidth(2);
        // HStack_h["genJet_eta"] ->SetLineWidth(2);

        HStack_h["met"]        ->Add(h_met);
        HStack_h["LgenJet_pt"] ->Add(h_LgenJet_pt);
        // HStack_h["LgenJet_eta"]->Add(h_LgenJet_eta);
        // HStack_h["genJet_pt"]  ->Add(h_genJet_pt);
        // HStack_h["genJet_eta"] ->Add(h_genJet_eta);
    } // end of i
    if(j==0){h_map[5] = HStack_h;}
    else{h_map[6] = HStack_h;}
} // end of j = loop over {C1C1, C1N1}



  ////////// Plotting part:
cout << "********************* Start plotting *********************" << endl;
  TCanvas *canvas = new TCanvas("c","");
  gPad->SetMargin(0.1,0.1,0.1,0.1);//l,r,b,t
  canvas->SetLogy();
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  // h_map[1]["LgenJet_eta"]->GetXaxis()->SetTitle("LgenJet eta");
  // h_map[1]["LgenJet_eta"]->SetMaximum(1e6);
  // h_map[1]["LgenJet_eta"]->SetMinimum(1);
  // h_map[1]["LgenJet_eta"]->Draw("hist cp");
  // h_map[0]["LgenJet_eta"]->Draw("same hist cp");
  // h_map[2]["LgenJet_eta"]->Draw("same hist cp");
  // h_map[3]["LgenJet_eta"]->Draw("same hist cp");
  // // h_map[4]["LgenJet_eta"]->Draw("same hist cp");
  // h_map[5]["LgenJet_eta"]->Draw("same hist cp");
  // h_map[6]["LgenJet_eta"]->Draw("same hist cp");
  // canvas->BuildLegend();
  // canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/fast_sim/plots/dyn/plots_dyn_c3.pdf[");
  // canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/fast_sim/plots/dyn/plots_dyn_c3.pdf");
  // h_map[1]["genJet_eta"]->GetXaxis()->SetTitle("genJet eta");
  // h_map[1]["genJet_eta"]->SetMaximum(1e6);
  // h_map[1]["genJet_eta"]->SetMinimum(1);
  // h_map[1]["genJet_eta"]->Draw("hist c");
  // h_map[0]["genJet_eta"]->Draw("same hist c");
  // h_map[2]["genJet_eta"]->Draw("same hist c");
  // h_map[3]["genJet_eta"]->Draw("same hist c");
  // // h_map[4]["genJet_eta"]->Draw("same hist c");
  // h_map[5]["genJet_eta"]->Draw("same hist c");
  // h_map[6]["genJet_eta"]->Draw("same hist c");
  // canvas->BuildLegend();
  // canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/fast_sim/plots/dyn/plots_dyn_c3.pdf");
  // canvas->SetLogx();
  h_map[1]["LgenJet_pt"]->GetXaxis()->SetTitle("Leading jets p_T [GeV]");
  h_map[1]["LgenJet_pt"]->GetYaxis()->SetTitle("Events / 200 GeV");
  h_map[1]["LgenJet_pt"]->SetMaximum(1e14);
  h_map[1]["LgenJet_pt"]->SetMinimum(1e4);
  h_map[1]["LgenJet_pt"]->Draw("hist p");
  h_map[0]["LgenJet_pt"]->Draw("same hist p");
  h_map[2]["LgenJet_pt"]->Draw("same hist p");
  h_map[3]["LgenJet_pt"]->Draw("same hist p");
  // h_map[4]["LgenJet_pt"]->Draw("same hist cp");
  h_map[5]["LgenJet_pt"]->Draw("same hist p");
  h_map[6]["LgenJet_pt"]->Draw("same hist p");
  canvas->BuildLegend();
  canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/fast_sim/plots/dyn/plots_dyn_c3.pdf[");
  canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/fast_sim/plots/dyn/plots_dyn_c3.pdf");
  h_map[1]["met"]->GetXaxis()->SetTitle("Missing E_T [GeV]");
  h_map[1]["met"]->GetYaxis()->SetTitle("Events / 200 GeV");
  h_map[1]["met"]->SetMaximum(1e14);
  h_map[1]["met"]->SetMinimum(1e4);
  h_map[1]["met"]->Draw("p");
  h_map[0]["met"]->Draw("same p");
  h_map[2]["met"]->Draw("same p");
  h_map[3]["met"]->Draw("same p");
  // h_map[4]["met"]->Draw("same c");
  h_map[5]["met"]->Draw("same p");
  h_map[6]["met"]->Draw("same p");
  canvas->BuildLegend();
  canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/fast_sim/plots/dyn/plots_dyn_c3.pdf");
  // h_map[1]["genJet_pt"]->GetXaxis()->SetTitle("genJet p_T [GeV]");
  // h_map[1]["genJet_pt"]->SetMaximum(1e8);
  // h_map[1]["genJet_pt"]->SetMinimum(1);
  // h_map[1]["genJet_pt"]->Draw("cp");
  // h_map[0]["genJet_pt"]->Draw("same cp");
  // h_map[2]["genJet_pt"]->Draw("same cp");
  // h_map[3]["genJet_pt"]->Draw("same cp");
  // // h_map[4]["genJet_pt"]->Draw("same cp");
  // h_map[5]["genJet_pt"]->Draw("same cp");
  // h_map[6]["genJet_pt"]->Draw("same cp");
  // canvas->BuildLegend();
  // canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/fast_sim/plots/dyn/plots_dyn_c3.pdf");
  // canvas->SetLogx();
  // h_map[1]["genJet_pt"]->GetXaxis()->SetTitle("genJet p_T [GeV]");
  // h_map[1]["genJet_pt"]->SetMaximum(1e8);
  // h_map[1]["genJet_pt"]->SetMinimum(1);
  // h_map[1]["genJet_pt"]->Draw("cp");
  // h_map[0]["genJet_pt"]->Draw("same cp");
  // h_map[2]["genJet_pt"]->Draw("same cp");
  // h_map[3]["genJet_pt"]->Draw("same cp");
  // // h_map[4]["genJet_pt"]->Draw("same cp");
  // h_map[5]["genJet_pt"]->Draw("same cp");
  // h_map[6]["genJet_pt"]->Draw("same cp");
  // canvas->BuildLegend();
  // canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/fast_sim/plots/dyn/plots_dyn_c3.pdf");
  canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/fast_sim/plots/dyn/plots_dyn_c3.pdf]");
  canvas->Close();

}
