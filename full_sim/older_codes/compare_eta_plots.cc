#include <TH1D.h>
#include <TH2D.h>
#include <TH3D.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TStyle.h>
#include <TLegend.h>

#include <iostream>

using namespace std;

void make_canvas(TH1D* h1, TH1D* h2, TH1D* h3, string title, int pos = 1, bool logy = false, double max = 0,string number = "1");


void compare_eta_plots(string number){

    cout << "************* Read histograms **********************" << endl;

    string rootname1 = "/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_"+number+"/winos_pt_eta_0.root";
    string rootname2 = "/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_"+number+"/winos_pt_eta_2.root";
    string rootname3 = "/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_"+number+"/winos_pt.root";

    TFile *f1 = new TFile(rootname1.c_str());
    TFile *f2 = new TFile(rootname2.c_str());
    TFile *f3 = new TFile(rootname3.c_str());

    TH1D* c1_h_Tpt    = (TH1D*)f1->Get("h_Tpt");
    TH1D* c1_h_qOverP = (TH1D*)f1->Get("h_qOverP");

    TH1D* c2_h_Tpt    = (TH1D*)f2->Get("h_Tpt");
    TH1D* c2_h_qOverP = (TH1D*)f2->Get("h_qOverP");

    TH1D* c3_h_Tpt    = (TH1D*)f3->Get("h_Tpt");
    TH1D* c3_h_qOverP = (TH1D*)f3->Get("h_qOverP");


    ///// Normalization for comparison:
    c1_h_Tpt        ->Scale(1./c1_h_Tpt->Integral());
    c2_h_Tpt        ->Scale(1./c2_h_Tpt->Integral());
    c3_h_Tpt        ->Scale(1./c3_h_Tpt->Integral());

    c1_h_qOverP->Scale(1./c1_h_qOverP->Integral());
    c2_h_qOverP->Scale(1./c2_h_qOverP->Integral());
    c3_h_qOverP->Scale(1./c3_h_qOverP->Integral());


    cout << "********************* Start plotting *********************" << endl;
    if(number =="1"){
      make_canvas(c1_h_Tpt,c2_h_Tpt,c3_h_Tpt,"; Track pt; Normalized entries",0,false,0.12,number);
      make_canvas(c1_h_qOverP,c2_h_qOverP,c3_h_qOverP,"; Best reco delta qOverP; Normalized entries",2,false,0.25,number);
    }else if(number =="2"){
      make_canvas(c1_h_Tpt,c2_h_Tpt,c3_h_Tpt,"; Track pt; Normalized entries",0,false,0.15,number);
      make_canvas(c1_h_qOverP,c2_h_qOverP,c3_h_qOverP,"; Best reco delta qOverP; Normalized entries",2,false,0.25,number);
    }else if(number =="3"){
      make_canvas(c1_h_Tpt,c2_h_Tpt,c3_h_Tpt,"; Track pt; Normalized entries",0,false,0.35,number);
      make_canvas(c1_h_qOverP,c2_h_qOverP,c3_h_qOverP,"; Best reco delta qOverP; Normalized entries",2,false,0.15,number);
    }

}

void make_canvas(TH1D* h1, TH1D* h2, TH1D* h3, string title, int pos = 1, bool logy = false, double max = 0,string number = "1"){
  TCanvas *canvas = new TCanvas("canvas","");
  canvas->SetGrid();

  if(logy){
    canvas->SetLogy();
    h1->SetMinimum(1);
  }

  gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  string ss1 = "plots/winos_plots_eta_comparison_size_"+number+".pdf[";
  string ss2 = "plots/winos_plots_eta_comparison_size_"+number+".pdf";
  string ss3 = "plots/winos_plots_eta_comparison_size_"+number+".pdf]";

  h1->Draw("hist h");
  if(max!=0){h1->SetMaximum(max);}
  h1->SetNdivisions(5);
  h1->SetLineColor(1);
  h2->SetLineColor(2);
  h3->SetLineColor(8);
  h2->Draw("hist h same");
  h3->Draw("hist h same");
  h1->SetTitle(title.c_str());
  h1->GetYaxis()->SetLabelSize(0.05);
  h1->GetXaxis()->SetLabelSize(0.05);
  h1->GetYaxis()->SetTitleSize(0.05);
  h1->GetXaxis()->SetTitleSize(0.05);
  TLegend* legend = new TLegend(0.58,0.8,0.98,0.98);//x1,y1,x2,y2
  gStyle->SetLegendTextSize(0.04);

  legend->AddEntry(h1,"eta = 0","l");
  legend->AddEntry(h2,"eta = 2","l");
  legend->AddEntry(h3,"|eta|<=2","l");
  legend->Draw();

  if(pos==0){
    canvas->SaveAs(ss1.c_str());
    canvas->SaveAs(ss2.c_str());
  }else if(pos==1){
    canvas->SaveAs(ss2.c_str());
  }else{
    canvas->SaveAs(ss2.c_str());
    canvas->SaveAs(ss3.c_str());
  }
  canvas->Close();
}
