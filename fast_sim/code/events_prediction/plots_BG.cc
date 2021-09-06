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
// if not already done you need to run first nevents.cc
//
// This .cc concerns the BG samples only.
//
// 1) It reads the n,n1,n2,... histograms saved in .root files
// 2) It adds them to THStacks
// 3) It plots the THStacks
// 4) It saves the plots in a .pdf
////////////////////////////////////////////////////////////////////////////////

void histo_sytling(TH1D* h, int j, const char* tit);

void plots_BG(string BGstring){
  ////////// Definition part:
  map<string, int> BGtype = { // map to identify BG
    {"W+jets",0},
    {"Z+jets",1},
    {"ttbar",2},
    {"topsingle",3},
    {"multijets",4}
  };

  int BGpos = BGtype[BGstring]; // corresponding index to BG type

  int mylength[5] = {7,7,10,1,9};

  string a[] = {"0_150", "150_300", "300_500", "500_1000", "1000_2000", "2000_5000", "5000_100000"};
  string c[] = {"0_600", "600_1200", "1200_2100", "2100_3400", "3400_5300", "5300_8100", "8100_15000",
  "15000_25000", "25000_35000", "35000_100000"};
  string d[] = {""};
  string e[] = {"0_500", "500_1000", "1000_2000", "2000_4000", "4000_7200", "7200_15000",
  "15000_25000", "25000_35000", "35000_100000"};
  string *myfolders[5] = {a,a,c,d,e};

  THStack *hs1 = new THStack("hs1","Nr. events after selction 1"); // include only events with leading jet pt > 1TeV
  THStack *hs2 = new THStack("hs2","Nr. events after selction 2"); // include only events with met > 1 TeV
  THStack *hs3 = new THStack("hs3","Nr. events after selction 3"); // lepton veto: exclude events with lepton pt > 10 GeV
  THStack *hs4 = new THStack("hs4","Nr. events predicted");
  THStack *hs5 = new THStack("hs5","Nr. events samples");

  ////////// Reading part:
  for(int j=0; j<mylength[BGpos]; j++){

    string filename = "/afs/cern.ch/user/c/chugli/private/histos/histo_" +BGstring+"_"+myfolders[BGpos][j]+".root";
    const char* dirname = filename.c_str();
    TFile *f = new TFile(dirname);
    TH1D* hist_n1   = (TH1D*)f->Get("hist_n1");
    TH1D* hist_n2   = (TH1D*)f->Get("hist_n2");
    TH1D* hist_n3   = (TH1D*)f->Get("hist_n3");
    TH1D* hist_ntot = (TH1D*)f->Get("hist_ntot");
    TH1D* hist_n    = (TH1D*)f->Get("hist_n");

    const char* tit = myfolders[BGpos][j].c_str();

    histo_sytling(hist_n1  ,j,tit);
    histo_sytling(hist_n2  ,j,tit);
    histo_sytling(hist_n3  ,j,tit);
    histo_sytling(hist_ntot,j,tit);
    histo_sytling(hist_n   ,j,tit);

    hs1->Add(hist_n1);
    hs2->Add(hist_n2);
    hs3->Add(hist_n3);
    hs4->Add(hist_ntot);
    hs5->Add(hist_n);
  }

  ////////// Plotting part:
  TCanvas *canvas = new TCanvas("c","");
  string f1 = "/afs/cern.ch/user/c/chugli/private/plots/events_prediction/plots_"+BGstring+".pdf[";
  const char* d1 = f1.c_str();
  string f2 = "/afs/cern.ch/user/c/chugli/private/plots/events_prediction/plots_"+BGstring+".pdf";
  const char* d2 = f2.c_str();
  string f3 = "/afs/cern.ch/user/c/chugli/private/plots/events_prediction/plots_"+BGstring+".pdf]";
  const char* d3 = f3.c_str();

  gPad->SetMargin(0.1,0.1,0.1,0.1);//l,r,b,t
  canvas->SetLogy();
  canvas->SetLogx();
  // hs1->Draw("hist cp"); // nicely colored => too heavy as a pdf ... :(
  hs1->SetMaximum(1e13);
  hs1->SetMinimum(1);
  hs1->Draw("hist p");
  hs1->GetYaxis()->SetTitle("Number of events");
  hs1->GetXaxis()->SetTitle("HT");
  canvas->BuildLegend(0.8,0.6,0.9,0.9);
  gPad->Modified();
  canvas->SaveAs(d1);
  canvas->SaveAs(d2);
  hs2->SetMaximum(1e13);
  hs2->SetMinimum(1);
  hs2->Draw("hist p");
  hs2->GetYaxis()->SetTitle("Number of events");
  hs2->GetXaxis()->SetTitle("HT");
  canvas->BuildLegend(0.8,0.6,0.9,0.9);
  gPad->Modified();
  canvas->SaveAs(d2);
  hs3->SetMaximum(1e13);
  hs3->SetMinimum(1);
  hs3->Draw("hist p");
  hs3->GetYaxis()->SetTitle("Number of events");
  hs3->GetXaxis()->SetTitle("HT");
  canvas->BuildLegend(0.8,0.6,0.9,0.9);
  gPad->Modified();
  canvas->SaveAs(d2);
  hs4->SetMaximum(1e13);
  hs4->SetMinimum(1);
  hs4->Draw("hist p");
  hs4->GetYaxis()->SetTitle("Number of events");
  hs4->GetXaxis()->SetTitle("HT");
  canvas->BuildLegend(0.8,0.6,0.9,0.9);
  gPad->Modified();
  canvas->SaveAs(d2);
  hs5->SetMaximum(1e13);
  hs5->SetMinimum(1);
  hs5->Draw("hist p");
  hs5->GetYaxis()->SetTitle("Number of events");
  hs5->GetXaxis()->SetTitle("HT");
  canvas->BuildLegend(0.8,0.6,0.9,0.9);
  gPad->Modified();
  canvas->SaveAs(d2);
  canvas->SaveAs(d3);
  canvas->Close();

}

void histo_sytling(TH1D* h, int j, const char* tit){
  h->SetFillColor(j+1);
  h->SetMarkerColor(j+1);
  h->SetLineColor(j+1);
  h->SetMarkerStyle(1);
  h->SetMarkerSize(0);
  h->SetTitle(tit);
  // h->SetLineWidth(0);
}
