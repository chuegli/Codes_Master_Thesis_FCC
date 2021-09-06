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

void make_canvas(TH1D* h1, TH1D* h2, TH1D* h3, TH1D* h4, TH1D* h5, string title, int pos = 1, bool logy = false, double max = 0);
void make_canvas(TH1D* h1, TH1D* h2, TH1D* h3, string title, int pos = 1, bool logy = false, double max = 0);


void compare_size_plots(){
    cout << "************* Read histograms **********************" << endl;
    string rootname1 = "/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_1/winos_10000.root";
    string rootname2 = "/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_2/winos_10000.root";
    string rootname3 = "/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_3/winos_10000.root";
    // string rootname3 = "/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_test/winos_10000.root";
    string rootname4 = "/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_4/winos_10000.root";
    string rootname5 = "/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_5/winos_10000.root";

    TFile *f1 = new TFile(rootname1.c_str());
    TFile *f2 = new TFile(rootname2.c_str());
    TFile *f3 = new TFile(rootname3.c_str());
    TFile *f4 = new TFile(rootname4.c_str());
    TFile *f5 = new TFile(rootname5.c_str());

    TH1D* c1_h_pt         = (TH1D*)f1->Get("b_h_pt");
    TH1D* c1_h_Tpt        = (TH1D*)f1->Get("h_Tpt");
    TH1D* c1_h_Tpt_2      = (TH1D*)f1->Get("h_Tpt_2");
    TH1D* c1_h_qOverP_2   = (TH1D*)f1->Get("h_qOverP_2");
    TH1D* c1_h_Delta_q_pt = (TH1D*)f1->Get("h_Delta_q_pt");

    TH1D* c2_h_pt         = (TH1D*)f2->Get("b_h_pt");
    TH1D* c2_h_Tpt        = (TH1D*)f2->Get("h_Tpt");
    TH1D* c2_h_Tpt_2      = (TH1D*)f2->Get("h_Tpt_2");
    TH1D* c2_h_qOverP_2   = (TH1D*)f2->Get("h_qOverP_2");
    TH1D* c2_h_Delta_q_pt = (TH1D*)f2->Get("h_Delta_q_pt");

    TH1D* c3_h_pt         = (TH1D*)f3->Get("b_h_pt");
    TH1D* c3_h_Tpt        = (TH1D*)f3->Get("h_Tpt");
    TH1D* c3_h_Tpt_2      = (TH1D*)f3->Get("h_Tpt_2");
    TH1D* c3_h_qOverP_2   = (TH1D*)f3->Get("h_qOverP_2");
    TH1D* c3_h_Delta_q_pt = (TH1D*)f3->Get("h_Delta_q_pt");

    TH1D* c4_h_pt         = (TH1D*)f4->Get("b_h_pt");
    TH1D* c4_h_Tpt        = (TH1D*)f4->Get("h_Tpt");
    TH1D* c4_h_Tpt_2      = (TH1D*)f4->Get("h_Tpt_2");
    TH1D* c4_h_qOverP_2   = (TH1D*)f4->Get("h_qOverP_2");
    TH1D* c4_h_Delta_q_pt = (TH1D*)f4->Get("h_Delta_q_pt");

    TH1D* c5_h_pt         = (TH1D*)f5->Get("b_h_pt");
    TH1D* c5_h_Tpt        = (TH1D*)f5->Get("h_Tpt");
    TH1D* c5_h_Tpt_2      = (TH1D*)f5->Get("h_Tpt_2");
    TH1D* c5_h_qOverP_2   = (TH1D*)f5->Get("h_qOverP_2");
    TH1D* c5_h_Delta_q_pt = (TH1D*)f5->Get("h_Delta_q_pt");



    ///// Normalization for comparison:
    c1_h_pt        ->Scale(1./c1_h_pt->Integral());
    c2_h_pt        ->Scale(1./c2_h_pt->Integral());
    c3_h_pt        ->Scale(1./c3_h_pt->Integral());
    c4_h_pt        ->Scale(1./c4_h_pt->Integral());
    c5_h_pt        ->Scale(1./c5_h_pt->Integral());

    c1_h_Tpt        ->Scale(1./c1_h_Tpt->Integral());
    c2_h_Tpt        ->Scale(1./c2_h_Tpt->Integral());
    c3_h_Tpt        ->Scale(1./c3_h_Tpt->Integral());
    c4_h_Tpt        ->Scale(1./c4_h_Tpt->Integral());
    c5_h_Tpt        ->Scale(1./c5_h_Tpt->Integral());

    c1_h_Delta_q_pt->Scale(1./c1_h_Delta_q_pt->Integral());
    c2_h_Delta_q_pt->Scale(1./c2_h_Delta_q_pt->Integral());
    c3_h_Delta_q_pt->Scale(1./c3_h_Delta_q_pt->Integral());
    c4_h_Delta_q_pt->Scale(1./c4_h_Delta_q_pt->Integral());
    c5_h_Delta_q_pt->Scale(1./c5_h_Delta_q_pt->Integral());

    c1_h_Tpt_2->Scale(1./c1_h_Tpt_2->Integral());
    c2_h_Tpt_2->Scale(1./c2_h_Tpt_2->Integral());
    c3_h_Tpt_2->Scale(1./c3_h_Tpt_2->Integral());
    c4_h_Tpt_2->Scale(1./c4_h_Tpt_2->Integral());
    c5_h_Tpt_2->Scale(1./c5_h_Tpt_2->Integral());

    c1_h_qOverP_2->Scale(1./c1_h_qOverP_2->Integral());
    c2_h_qOverP_2->Scale(1./c2_h_qOverP_2->Integral());
    c3_h_qOverP_2->Scale(1./c3_h_qOverP_2->Integral());
    c4_h_qOverP_2->Scale(1./c4_h_qOverP_2->Integral());
    c5_h_qOverP_2->Scale(1./c5_h_qOverP_2->Integral());


    cout << "********************* Start plotting *********************" << endl;
    make_canvas(c1_h_pt,c2_h_pt,c3_h_pt,c4_h_pt,c5_h_pt,"; Best reco pt; Normalized entries",0,false,0.15);
    make_canvas(c1_h_Tpt,c2_h_Tpt,c3_h_Tpt,c4_h_Tpt,c5_h_Tpt,"; Best track pt; Normalized entries",1,false,0.3);
    make_canvas(c1_h_Tpt_2,c2_h_Tpt_2,c3_h_Tpt_2,c4_h_Tpt_2,c5_h_Tpt_2,"; New best track pt; Normalized entries",1,false,0.3);
    make_canvas(c1_h_qOverP_2,c2_h_qOverP_2,c3_h_qOverP_2,c4_h_qOverP_2,c5_h_qOverP_2,"; New best delta qOverP; Normalized entries",1,false,0.3);
    make_canvas(c1_h_Delta_q_pt,c2_h_Delta_q_pt,c3_h_Delta_q_pt,c4_h_Delta_q_pt,c5_h_Delta_q_pt,"; Best reco delta qOverP; Normalized entries",2,false,0.3);

    make_canvas(c1_h_pt,c2_h_pt,c3_h_pt,"; Best reco pt; Normalized entries",0,false,0.1);
    make_canvas(c1_h_Tpt,c2_h_Tpt,c3_h_Tpt,"; Track pt; Normalized entries",1,false,0.3); // from qOverP
    make_canvas(c1_h_Tpt_2,c2_h_Tpt_2,c3_h_Tpt_2,"; New best track pt; Normalized entries",1,false,0.3);
    make_canvas(c1_h_qOverP_2,c2_h_qOverP_2,c3_h_qOverP_2,"; New best delta qOverP; Normalized entries",1,false,0.2);
    make_canvas(c1_h_Delta_q_pt,c2_h_Delta_q_pt,c3_h_Delta_q_pt,"; Best reco delta qOverP; Normalized entries",2,false,0.2);


}

void make_canvas(TH1D* h1, TH1D* h2, TH1D* h3, TH1D* h4, TH1D* h5, string title, int pos = 1, bool logy = false, double max = 0){
  TCanvas *canvas = new TCanvas("canvas","");
  canvas->SetGrid();

  if(logy){
    canvas->SetLogy();
    h1->SetMinimum(1);
  }

  gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  string ss1 = "plots/winos_plots_size_comparison_all.pdf[";
  string ss2 = "plots/winos_plots_size_comparison_all.pdf";
  string ss3 = "plots/winos_plots_size_comparison_all.pdf]";

  h1->Draw("hist h");
  if(max!=0){h1->SetMaximum(max);}
  h1->SetNdivisions(5);
  h1->SetLineColor(1);
  h2->SetLineColor(2);
  h3->SetLineColor(8);
  h4->SetLineColor(4);
  h5->SetLineColor(94);
  h2->Draw("hist h same");
  h3->Draw("hist h same");
  h4->Draw("hist h same");
  h5->Draw("hist h same");
  h1->SetTitle(title.c_str());
  h1->GetYaxis()->SetLabelSize(0.05);
  h1->GetXaxis()->SetLabelSize(0.05);
  h1->GetYaxis()->SetTitleSize(0.05);
  h1->GetXaxis()->SetTitleSize(0.05);
  TLegend* legend = new TLegend(0.58,0.8,0.98,0.98);//x1,y1,x2,y2
  gStyle->SetLegendTextSize(0.04);

  // legend->AddEntry(h1,"50x50 in 18x18","l");
  legend->AddEntry(h1,"1x1","l");
  legend->AddEntry(h2,"5x5","l");
  legend->AddEntry(h3,"50x50","l");
  legend->AddEntry(h4,"1x5","l");
  legend->AddEntry(h5,"5x1","l");
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

void make_canvas(TH1D* h1, TH1D* h2, TH1D* h3, string title, int pos = 1, bool logy = false, double max = 0){
  TCanvas *canvas = new TCanvas("canvas","");
  canvas->SetGrid();

  if(logy){
    canvas->SetLogy();
    h1->SetMinimum(1);
  }

  gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  string ss1 = "plots/winos_plots_size_comparison.pdf[";
  string ss2 = "plots/winos_plots_size_comparison.pdf";
  string ss3 = "plots/winos_plots_size_comparison.pdf]";

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

  // legend->AddEntry(h1,"50x50 in 18x18","l");
  legend->AddEntry(h1,"1x1","l");
  legend->AddEntry(h2,"5x5","l");
  legend->AddEntry(h3,"50x50","l");
  // legend->AddEntry(h3,"5x5 no scattering","l");
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
