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
// if not already done you need to run first signal_dyn.cc
//
// This .cc concerns the signal samples only.
//
// 1) It reads the n,n1,n2,... histograms saved in .root files
// 2) It adds them to THStacks
// 3) It plots the THStacks
// 4) It saves the plots in a .pdf
////////////////////////////////////////////////////////////////////////////////

void histo_sytling(TH1D* h, int j, const char* tit);
void make_canvas(THStack* hs, string ftype, int pos = 1);

void plots_signal(){
  ////////// Definition part:
  string f_type1  = "C1N1";
  string f_type2  = "C1C1";
  string f_middle[40];

  for (int j=0; j<2; j++){
      THStack *hs1 = new THStack("hs1","Nr. events after selction 1"); // include only events with leading jet pt > 1TeV
      THStack *hs2 = new THStack("hs2","Nr. events after selction 2"); // include only events with met > 1 TeV
      THStack *hs3 = new THStack("hs3","Nr. events after selction 3"); // lepton veto: exclude events with lepton pt > 10 GeV
      THStack *hs4 = new THStack("hs4","Nr. events predicted");
      THStack *hs5 = new THStack("hs5","Nr. events samples");

      string ftype;
      int ii;
      if(j==0){ftype=f_type1;}
      else{ftype=f_type2;}

      for(int i = 0; i < 40; i++){
          f_middle[i] = to_string(700+100*i);

          string filename = "/afs/cern.ch/user/c/chugli/private/histos/histo_" +ftype+"_"+f_middle[i]+".root";
          const char* dirname = filename.c_str();
          TFile *f = new TFile(dirname);

          TH1D* hist_n1   = (TH1D*)f->Get("hist_n1");
          TH1D* hist_n2   = (TH1D*)f->Get("hist_n2");
          TH1D* hist_n3   = (TH1D*)f->Get("hist_n3");
          TH1D* hist_ntot = (TH1D*)f->Get("hist_ntot");
          TH1D* hist_n    = (TH1D*)f->Get("hist_n");

          const char* tit = f_middle[i].c_str();

          histo_sytling(hist_n1,i,tit);
          histo_sytling(hist_n2,i,tit);
          histo_sytling(hist_n3,i,tit);
          histo_sytling(hist_ntot,i,tit);
          histo_sytling(hist_n,i,tit);

          hs1->Add(hist_n1);
          hs2->Add(hist_n2);
          hs3->Add(hist_n3);
          hs4->Add(hist_ntot);
          hs5->Add(hist_n);
      } // end of i

    ///////// Plotting part:

    make_canvas(hs1, ftype, 0);
    make_canvas(hs2, ftype);
    make_canvas(hs3, ftype);
    make_canvas(hs4, ftype);
    make_canvas(hs5, ftype, 2);
  } // end of j = loop over {C1C1, C1N1}
}

void make_canvas(THStack* hs, string ftype, int pos = 1){
  TCanvas *canvas = new TCanvas("c","");
  gPad->SetMargin(0.1,0.1,0.1,0.1);//l,r,b,t
  canvas->SetLogy();
  canvas->SetLogx();
  hs->SetMaximum(1e13);
  hs->SetMinimum(1);
  hs->Draw("hist p");
  hs->GetYaxis()->SetTitle("Number of events");
  hs->GetXaxis()->SetTitle("HT");
  canvas->BuildLegend(0.85,0.4,0.9,0.9);
  gPad->Modified();
  string f1 = "/afs/cern.ch/user/c/chugli/private/plots/events_prediction/plots_"+ftype+".pdf[";
  const char* d1 = f1.c_str();
  string f2 = "/afs/cern.ch/user/c/chugli/private/plots/events_prediction/plots_"+ftype+".pdf";
  const char* d2 = f2.c_str();
  string f3 = "/afs/cern.ch/user/c/chugli/private/plots/events_prediction/plots_"+ftype+".pdf]";
  const char* d3 = f3.c_str();
  if(pos == 0){
    canvas->SaveAs(d1);
    canvas->SaveAs(d2);
  }else if(pos==1){
    canvas->SaveAs(d2);
  }else if(pos==2){
    canvas->SaveAs(d2);
    canvas->SaveAs(d3);
  }
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
