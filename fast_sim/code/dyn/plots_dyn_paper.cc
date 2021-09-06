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
#include <TColor.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TPad.h>
#include <THStack.h>

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
// if not already done you need to run first signal_dyn_paper.cc and BG_dyn_paper.cc
//
// This .cc concerns both signals and BGs samples.
//
//// What it does:
// 1) It first extracts the dynamic histograms for the BGs and saves them to THStacks
// 2) It does the same for the signals
// 3) It plots both in plot_dyn_c3.pdf
//// How to run it:
// Location:
// Command:
////////////////////////////////////////////////////////////////////////////////

void histo_styling(TH1D* h, int j, bool fiiling = true);
map<TString, TH1*> make_histograms(TString filename, TString f);

void plots_dyn_paper(){
  /////////////////////////////////////////////////////////////////////////////
  /////////////////// Signal part:
  cout << "********************* Start signal part *********************" << endl;
  string f_type1  = "C1N1";
  string f_type2  = "C1C1";
  string f_middle[2] = {"1000","3000"};
  int index = 0;
  int mycolor2[4] = {2,95,6,51};

  map<TString, TH1D*> HStack_h;
  map<int, map<TString, TH1D*>> h_map;

  for (int j=0; j<2; j++){
      string ftype;
      if(j==0){ftype=f_type1;}
      else{ftype=f_type2;}
      cout << "********************* Start " << ftype << " *********************" << endl;

      for(int i = 0; i < 2; i++){
        cout << "index: " << index << endl;
        cout << "i,j: " << i << ", " << j << endl;
        string filename;
        if(i==0){filename = "/afs/cern.ch/user/c/chugli/private/histos/histo_dyn_c3_higgsino_" +ftype+"_"+f_middle[i]+".root";}
        else{filename = "/afs/cern.ch/user/c/chugli/private/histos/histo_dyn_c3_" +ftype+"_"+f_middle[i]+".root";}
        const char* dirname = filename.c_str();
        TFile *f = new TFile(dirname);

        string chargname[2] = {"Higgsino", "Wino"};
        string chargname2[2] = {"1", "3"};
        string name11 = chargname[i]+"("+ftype+")"+" x 1000 "+", m = "+chargname2[i]+" TeV";
        const char* name1 = name11.c_str();
        string name22 = chargname[i]+"("+ftype+")"+", m = "+chargname2[i]+" TeV";
        const char* name2 = name22.c_str();
        cout << "name1: " << name1 << endl;

        HStack_h["h_met"]      = new TH1D("", name2, 25, 0, 5000);
        HStack_h["h_pt"]       = new TH1D("", name2, 25, 0, 5000);
        HStack_h["hh_pt"]      = new TH1D("", name2, 25, 0, 5000);
        HStack_h["hh_met"]     = new TH1D("", name2, 25, 0, 5000);
        HStack_h["hh_pt_tot"]  = new TH1D("", name2, 25, 0, 5000);
        HStack_h["hh_met_tot"] = new TH1D("", name2, 25, 0, 5000);
        HStack_h["h_pt_n"]     = new TH1D("", name1, 25, 0, 5000);
        HStack_h["h_met_n"]    = new TH1D("", name1, 25, 0, 5000);

        TH1D* c_h_met      = (TH1D*)f->Get("h_met");
        TH1D* c_h_pt       = (TH1D*)f->Get("h_pt");
        TH1D* c_hh_pt      = (TH1D*)f->Get("hh_pt");
        TH1D* c_hh_met     = (TH1D*)f->Get("hh_met");
        TH1D* c_hh_pt_tot  = (TH1D*)f->Get("hh_pt_tot");
        TH1D* c_hh_met_tot = (TH1D*)f->Get("hh_met_tot");
        TH1D* c_h_pt_n     = (TH1D*)f->Get("h_pt_n");
        TH1D* c_h_met_n    = (TH1D*)f->Get("h_met_n");

        //////
        c_h_met_n->Scale(1000);
        c_h_pt_n ->Scale(1000);
        //////

        histo_styling(HStack_h["h_met"]     , mycolor2[index], false);
        histo_styling(HStack_h["h_pt"]      , mycolor2[index], false);
        histo_styling(HStack_h["hh_pt"]     , mycolor2[index], false);
        histo_styling(HStack_h["hh_met"]    , mycolor2[index], false);
        histo_styling(HStack_h["hh_pt_tot"] , mycolor2[index], false);
        histo_styling(HStack_h["hh_met_tot"], mycolor2[index], false);
        histo_styling(HStack_h["h_pt_n"]    , mycolor2[index], false);
        histo_styling(HStack_h["h_met_n"]   , mycolor2[index], false);

        HStack_h["h_met"]     ->Add(c_h_met);
        HStack_h["h_pt"]      ->Add(c_h_pt);
        HStack_h["hh_pt"]     ->Add(c_hh_pt);
        HStack_h["hh_met"]    ->Add(c_hh_met);
        HStack_h["hh_pt_tot"] ->Add(c_hh_pt_tot);
        HStack_h["hh_met_tot"]->Add(c_hh_met_tot);
        HStack_h["h_pt_n"]    ->Add(c_h_pt_n);
        HStack_h["h_met_n"]   ->Add(c_h_met_n);

        h_map[index] = HStack_h;
        index++;
    } // end of i
} // end of j = loop over {C1C1, C1N1}


  ////////// Definition part:
  cout << "********************* Start BG part *********************" << endl;

  string BGtype[5] = {"ttbar","topsingle","W+jets","Z+jets","multijets"};

  int mylength[5] = {10,1,7,7,9};
  int mycolor[5] = {68,65,8,9,1};

  string W_r[] = {"0_150", "150_300", "300_500", "500_1000", "1000_2000", "2000_5000", "5000_100000"};
  string tt_r[] = {"0_600", "600_1200", "1200_2100", "2100_3400", "3400_5300", "5300_8100", "8100_15000",
  "15000_25000", "25000_35000", "35000_100000"};
  string t_r[] = {""};
  string m_r[] = {"0_500", "500_1000", "1000_2000", "2000_4000", "4000_7200", "7200_15000",
  "15000_25000", "25000_35000", "35000_100000"};
  string *myfolders[5] = {tt_r,t_r,W_r,W_r,m_r};

  THStack *s_h_met        = new THStack("s_h_met",      "");
  THStack *s_h_pt         = new THStack("s_h_pt",       "");
  THStack *s_hh_pt        = new THStack("s_hh_pt",      "");
  THStack *s_hh_met       = new THStack("s_hh_met",     "");
  THStack *s_hh_pt_tot    = new THStack("s_hh_pt_tot",  "");
  THStack *s_hh_met_tot   = new THStack("s_hh_met_tot", "");
  THStack *s_h_pt_e       = new THStack("s_h_pt_e",     "");
  THStack *s_h_met_e      = new THStack("s_h_met_e",    "");
  THStack *s_h_pt_n       = new THStack("s_h_pt_n ",    "");
  THStack *s_h_met_n      = new THStack("s_h_met_n",    "");

  for(int i=0; i<5;i++){ // put <5 to include multijets
    cout << "********************* Start " << BGtype[i] << " *********************" << endl;
    const char* BGchar = BGtype[i].c_str();
    string name = BGtype[i];
    const char* name1 = name.c_str();

    TH1D* t_h_met        = new TH1D("", name1, 25, 0, 5000); // histogram with just the sample number of events with lepton veto
    TH1D* t_h_pt         = new TH1D("", name1, 25, 0, 5000); // histogram with just the sample number of events with lepton veto
    TH1D* t_hh_pt        = new TH1D("", name1, 25, 0, 5000); // histogram with just the sample number without any selection
    TH1D* t_hh_met       = new TH1D("", name1, 25, 0, 5000); // histogram with just the sample number without any selection
    TH1D* t_hh_pt_tot    = new TH1D("", name1, 25, 0, 5000); // histogram with the expected number of events without any selection
    TH1D* t_hh_met_tot   = new TH1D("", name1, 25, 0, 5000); // histogram with the expected number of events without any selection
    TH1D* t_h_pt_n       = new TH1D("", name1, 25, 0, 5000); // histogram with the expected number of events with lepton veto
    TH1D* t_h_met_n      = new TH1D("", name1, 25, 0, 5000); // histogram with the expected number of events with lepton veto

    int ii = mycolor[i];

    for(int j=0; j<mylength[i]; j++){
      string filename = "/afs/cern.ch/user/c/chugli/private/histos/histo_dyn_c3_" +BGtype[i]+"_"+myfolders[i][j]+".root";
      const char* dirname = filename.c_str();
      TFile *f = new TFile(dirname);

      TH1D* c_h_met      = (TH1D*)f->Get("h_met");
      TH1D* c_h_pt       = (TH1D*)f->Get("h_pt");
      TH1D* c_hh_pt      = (TH1D*)f->Get("hh_pt");
      TH1D* c_hh_met     = (TH1D*)f->Get("hh_met");
      TH1D* c_hh_pt_tot  = (TH1D*)f->Get("hh_pt_tot");
      TH1D* c_hh_met_tot = (TH1D*)f->Get("hh_met_tot");
      TH1D* c_h_pt_n     = (TH1D*)f->Get("h_pt_n");
      TH1D* c_h_met_n    = (TH1D*)f->Get("h_met_n");

      t_h_met     ->Add(c_h_met);
      t_h_pt      ->Add(c_h_pt);
      t_hh_pt     ->Add(c_hh_pt);
      t_hh_met    ->Add(c_hh_met);
      t_hh_pt_tot ->Add(c_hh_pt_tot);
      t_hh_met_tot->Add(c_hh_met_tot);
      t_h_pt_n    ->Add(c_h_pt_n);
      t_h_met_n   ->Add(c_h_met_n);
    } // end of j

    histo_styling(t_h_met     , ii);
    histo_styling(t_h_pt      , ii);
    histo_styling(t_hh_pt     , ii);
    histo_styling(t_hh_met    , ii);
    histo_styling(t_hh_pt_tot , ii);
    histo_styling(t_hh_met_tot, ii);
    histo_styling(t_h_pt_n    , ii);
    histo_styling(t_h_met_n   , ii);

    s_h_met     ->Add(t_h_met);
    s_h_pt      ->Add(t_h_pt);
    s_hh_pt     ->Add(t_hh_pt);
    s_hh_met    ->Add(t_hh_met);
    s_hh_pt_tot ->Add(t_hh_pt_tot);
    s_hh_met_tot->Add(t_hh_met_tot);
    s_h_pt_n    ->Add(t_h_pt_n);
    s_h_met_n   ->Add(t_h_met_n);
  } //end of i


  //////////////////////////////////////////////////////////////////////////////
  ////////// Plotting part:
  cout << "********************* Start plotting *********************" << endl;
  TCanvas *canvas = new TCanvas("c","");
  gPad->SetMargin(0.15,0.1,0.12,0.1);//l,r,b,t
  canvas->SetLogy();
  // gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetLegendBorderSize(0);

  s_h_pt_n->SetMaximum(1e14);
  s_h_pt_n->SetMinimum(1e4);
  s_h_pt_n->SetTitle("Expected events with lepton veto; Leading jets p_T [GeV]; Events / 200 GeV");
  s_h_pt_n->Draw("h");
  s_h_pt_n->GetYaxis()->SetLabelSize(0.05);
  s_h_pt_n->GetXaxis()->SetLabelSize(0.05);
  s_h_pt_n->GetYaxis()->SetTitleSize(0.05);
  s_h_pt_n->GetXaxis()->SetTitleSize(0.05);
  s_h_pt_n->GetXaxis()->SetNdivisions(5,10,1);
  h_map[0]["h_pt_n"]->Draw("same hist h"); // signal for C1N1 1000 TeV
  h_map[1]["h_pt_n"]->Draw("same hist h"); // signal for C1N1 3000 TeV
  h_map[2]["h_pt_n"]->Draw("same hist h"); // signal for C1C1 1000 TeV
  h_map[3]["h_pt_n"]->Draw("same hist h"); // signal for C1C1 3000 TeV
  canvas->BuildLegend(0.4,0.55,0.87,0.87); //x1,y1,x2,y2
  gPad->RedrawAxis();
  gPad->SetTicks(1,1);
  gPad->Modified();
  canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/plots/dyn/plots_dyn_c3_with_higgsino.pdf[");
  canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/plots/dyn/plots_dyn_c3_with_higgsino.pdf");

  s_h_met_n->SetMaximum(1e14);
  s_h_met_n->SetMinimum(1e4);
  s_h_met_n->Draw("h");
  s_h_met_n->GetYaxis()->SetLabelSize(0.05);
  s_h_met_n->GetXaxis()->SetLabelSize(0.05);
  s_h_met_n->GetYaxis()->SetTitleSize(0.05);
  s_h_met_n->GetXaxis()->SetTitleSize(0.05);
  s_h_met_n->GetXaxis()->SetNdivisions(5,10,1);
  h_map[0]["h_met_n"]->Draw("same hist h"); // signal for C1N1 1000 TeV
  h_map[1]["h_met_n"]->Draw("same hist h"); // signal for C1N1 3000 TeV
  h_map[2]["h_met_n"]->Draw("same hist h"); // signal for C1C1 1000 TeV
  h_map[3]["h_met_n"]->Draw("same hist h"); // signal for C1C1 3000 TeV
  s_h_met_n->SetTitle("Expected events with lepton veto; Missing E_T [GeV]; Events / 200 GeV");
  canvas->BuildLegend(0.4,0.55,0.87,0.87);
  gPad->RedrawAxis();
  gPad->SetTicks(1,1);
  gPad->Modified();
  canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/plots/dyn/plots_dyn_c3_with_higgsino.pdf");

  s_hh_pt_tot->SetMaximum(1e14);
  s_hh_pt_tot->SetMinimum(1e4);
  s_hh_pt_tot->SetTitle("Expected number of events without selection; Leading jets p_T [GeV]; Events / 200 GeV");
  s_hh_pt_tot->Draw("h");
  s_hh_pt_tot->GetYaxis()->SetLabelSize(0.05);
  s_hh_pt_tot->GetXaxis()->SetLabelSize(0.05);
  s_hh_pt_tot->GetYaxis()->SetTitleSize(0.05);
  s_hh_pt_tot->GetXaxis()->SetTitleSize(0.05);
  s_hh_pt_tot->GetXaxis()->SetNdivisions(5,10,1);
  h_map[0]["hh_pt_tot"]->Draw("same h"); // signal for C1N1 1000 TeV
  h_map[1]["hh_pt_tot"]->Draw("same h"); // signal for C1N1 3000 TeV
  h_map[2]["hh_pt_tot"]->Draw("same h"); // signal for C1C1 1000 TeV
  h_map[3]["hh_pt_tot"]->Draw("same h"); // signal for C1C1 3000 TeV
  canvas->BuildLegend(0.45,0.55,0.87,0.87);
  gPad->RedrawAxis();
  gPad->SetTicks(1,1);
  gPad->Modified();
  canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/plots/dyn/plots_dyn_c3_with_higgsino.pdf");

  s_hh_met_tot->SetMaximum(1e14);
  s_hh_met_tot->SetMinimum(1e4);
  s_hh_met_tot->SetTitle("Expected number of events without selection; Missing E_T [GeV]; Events / 200 GeV");
  s_hh_met_tot->Draw("h");
  s_hh_met_tot->GetYaxis()->SetLabelSize(0.05);
  s_hh_met_tot->GetXaxis()->SetLabelSize(0.05);
  s_hh_met_tot->GetYaxis()->SetTitleSize(0.05);
  s_hh_met_tot->GetXaxis()->SetTitleSize(0.05);
  s_hh_met_tot->GetXaxis()->SetNdivisions(5,10,1);
  h_map[0]["hh_met_tot"]->Draw("same h"); // signal for C1N1 1000 TeV
  h_map[1]["hh_met_tot"]->Draw("same h"); // signal for C1N1 3000 TeV
  h_map[2]["hh_met_tot"]->Draw("same h"); // signal for C1C1 1000 TeV
  h_map[3]["hh_met_tot"]->Draw("same h"); // signal for C1C1 3000 TeV
  canvas->BuildLegend(0.45,0.55,0.87,0.87);
  gPad->RedrawAxis();
  gPad->SetTicks(1,1);
  gPad->Modified();
  canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/plots/dyn/plots_dyn_c3_with_higgsino.pdf");
  canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/plots/dyn/plots_dyn_c3_with_higgsino.pdf]");
  canvas->Close();

}

void histo_styling(TH1D* h, int j, bool fiiling = true){
  if(fiiling){
    h->SetFillColor(j);
    h->SetLineColor(1);
    h->SetMarkerColor(j);
    h->SetMarkerSize(0);
    h->SetLineWidth(1);
  } else{
    h->SetLineColor(j);
    h->SetMarkerColor(j);
    h->SetMarkerSize(0);
    h->SetLineStyle(2);
    h->SetLineWidth(2);
  }
  // h->SetLabelSize(1,"xy");
  // h->SetMarkerColor(j);
  // h->SetMarkerStyle(8);
  // h->SetMarkerSize(0);
  // h->SetTitle(tit);
  // h->GetXaxis()->SetTitle(tit_x);
  // h->GetYaxis()->SetTitle(tit_y);
}
