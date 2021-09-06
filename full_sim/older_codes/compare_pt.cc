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

void make_canvas(TH1D* h1, TH1D* h2, TH1D* h3, TH1D* h4, TH1D* h5, TH1D* h6, string title, int pos = 1, bool logy = false, double max = 0);

void make_canvas(TH1D* h2, TH1D* h3, TH1D* h4, TH1D* h5, TH1D* h6, string title, int pos = 1, bool logy = false, double max = 0);


void compare_pt(){
    cout << "************* Read histograms **********************" << endl;
    // string rootname1 = "/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_2/winos_other_30GeV.root";
    string rootname2 = "/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_2/winos_other_100GeV.root";
    string rootname3 = "/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_2/winos_other_500GeV.root";
    string rootname4 = "/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_2/winos_other_1TeV.root";
    string rootname5 = "/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_2/winos_other_10TeV.root";
    string rootname6 = "/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_2/winos_other_30TeV.root";


    // TFile *f1 = new TFile(rootname1.c_str());
    TFile *f2 = new TFile(rootname2.c_str());
    TFile *f3 = new TFile(rootname3.c_str());
    TFile *f4 = new TFile(rootname4.c_str());
    TFile *f5 = new TFile(rootname5.c_str());
    TFile *f6 = new TFile(rootname6.c_str());

    // TH1D* c1_h_hit_energy = (TH1D*)f1->Get("h_hit_energy");
    TH1D* c2_h_hit_energy = (TH1D*)f2->Get("h_hit_energy");
    TH1D* c3_h_hit_energy = (TH1D*)f3->Get("h_hit_energy");
    TH1D* c4_h_hit_energy = (TH1D*)f4->Get("h_hit_energy");
    TH1D* c5_h_hit_energy = (TH1D*)f5->Get("h_hit_energy");
    TH1D* c6_h_hit_energy = (TH1D*)f6->Get("h_hit_energy");


    ///// Normalization for comparison:
    // c1_h_hit_energy->Scale(1./c1_h_hit_energy->Integral());
    c2_h_hit_energy->Scale(1./c2_h_hit_energy->Integral());
    c3_h_hit_energy->Scale(1./c3_h_hit_energy->Integral());
    c4_h_hit_energy->Scale(1./c4_h_hit_energy->Integral());
    c5_h_hit_energy->Scale(1./c5_h_hit_energy->Integral());
    c6_h_hit_energy->Scale(1./c6_h_hit_energy->Integral());


    cout << "********************* Start plotting *********************" << endl;

    // make_canvas(c1_h_hit_energy,c2_h_hit_energy,c3_h_hit_energy,c4_h_hit_energy,c5_h_hit_energy,c6_h_hit_energy," ; Hit energy; Normalized entries",0,false,0);
    // cout << "HHHHHHHHH" << endl;
    // make_canvas(c1_h_hit_energy,c2_h_hit_energy,c3_h_hit_energy,c4_h_hit_energy,c5_h_hit_energy,c6_h_hit_energy," ; Hit energy; Normalized entries",1,false,0);
    // make_canvas(c1_h_hit_energy,c2_h_hit_energy,c3_h_hit_energy,c4_h_hit_energy,c5_h_hit_energy,c6_h_hit_energy," ; Hit energy; Normalized entries",2,false,0);

    make_canvas(c2_h_hit_energy,c3_h_hit_energy,c4_h_hit_energy,c5_h_hit_energy,c6_h_hit_energy," ; Hit energy; Normalized entries",0,false,0);
    make_canvas(c2_h_hit_energy,c3_h_hit_energy,c4_h_hit_energy,c5_h_hit_energy,c6_h_hit_energy," ; Hit energy; Normalized entries",2,false,0);


    cout << "********************* Start plotting *********************" << endl;

    double mean_E[5];
    mean_E[0] = c2_h_hit_energy->GetMean();
    mean_E[1] = c3_h_hit_energy->GetMean();
    mean_E[2] = c4_h_hit_energy->GetMean();
    mean_E[3] = c5_h_hit_energy->GetMean();
    mean_E[4] = c6_h_hit_energy->GetMean();

    double Energy[5] = {100,500,1000,10000,30000};

    TCanvas *c1 = new TCanvas("c1","",200,10,500,300);
    c1->SetLogx();
    TGraph* gr = new TGraph(5,Energy,mean_E);
    gr->Draw("AC*");
    c1->SaveAs("./plots/comparison_size_2_bethe_mean.pdf");
    c1->Close();

    cout << "****************** Finished **************************" << endl;

}

void make_canvas(TH1D* h1, TH1D* h2, TH1D* h3, TH1D* h4, TH1D* h5, TH1D* h6, string title, int pos = 1, bool logy = false, double max = 0){
  TCanvas *canvas = new TCanvas("canvas","");
  canvas->SetGrid();

  if(logy){
    canvas->SetLogy();
    h1->SetMinimum(1e-3);
  }

  gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  string ss1 = "./plots/comparison_size_2_bethe.pdf[";
  string ss2 = "./plots/comparison_size_2_bethe.pdf";
  string ss3 = "./plots/comparison_size_2_bethe.pdf]";

  cout << "test1" << endl;

  h1->Draw("hist h");
  if(max!=0){h1->SetMaximum(max);}
  h1->SetNdivisions(5);
  h1->SetLineColor(1);
  h2->SetLineColor(2);
  h3->SetLineColor(8);
  h4->SetLineColor(14);
  h5->SetLineColor(51);
  h6->SetLineColor(94);
  cout << "test2" << endl;
  h2->Draw("hist h same");
  h3->Draw("hist h same");
  h4->Draw("hist h same");
  h5->Draw("hist h same");
  h6->Draw("hist h same");
  cout << "test3" << endl;
  h1->SetTitle(title.c_str());
  h1->GetYaxis()->SetLabelSize(0.05);
  h1->GetXaxis()->SetLabelSize(0.05);
  h1->GetYaxis()->SetTitleSize(0.05);
  h1->GetXaxis()->SetTitleSize(0.05);
  cout << "test4" << endl;
  TLegend* legend = new TLegend(0.58,0.8,0.98,0.98);//x1,y1,x2,y2
  gStyle->SetLegendTextSize(0.04);

  legend->AddEntry(h1,"30 GeV","l");
  legend->AddEntry(h2,"100 GeV","l");
  legend->AddEntry(h3,"500 GeV","l");
  legend->AddEntry(h4,"1 TeV","l");
  legend->AddEntry(h5,"10 TeV","l");
  legend->AddEntry(h6,"30 TeV","l");
  legend->Draw();

  cout << "test5" << endl;

  if(pos==0){
    cout << " soy position 0-0" << endl;
    canvas->SaveAs(ss1.c_str());
    cout << " soy position 0-1" << endl;
    canvas->SaveAs(ss2.c_str());
    cout << " soy position 0-2" << endl;
  }else if(pos==1){
    cout << " soy position 1" << endl;
    canvas->SaveAs(ss2.c_str());
  }else{
    cout << " soy position altro" << endl;
    canvas->SaveAs(ss2.c_str());
    canvas->SaveAs(ss3.c_str());
  }
  cout << "test6" << endl;
  canvas->Close();
}

void make_canvas(TH1D* h2, TH1D* h3, TH1D* h4, TH1D* h5, TH1D* h6, string title, int pos = 1, bool logy = false, double max = 0){
  TCanvas *canvas = new TCanvas("canvas","");
  canvas->SetGrid();

  if(logy){
    canvas->SetLogy();
    h2->SetMinimum(1e-3);
  }

  gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  string ss1 = "./plots/comparison_size_2_bethe.pdf[";
  string ss2 = "./plots/comparison_size_2_bethe.pdf";
  string ss3 = "./plots/comparison_size_2_bethe.pdf]";

  h2->Draw("hist h");
  if(max!=0){h2->SetMaximum(max);}
  h2->SetNdivisions(5);
  h2->SetLineColor(1);
  h3->SetLineColor(8);
  h4->SetLineColor(14);
  h5->SetLineColor(51);
  h6->SetLineColor(94);
  h3->Draw("hist h same");
  h4->Draw("hist h same");
  h5->Draw("hist h same");
  h6->Draw("hist h same");
  h2->SetTitle(title.c_str());
  h2->GetYaxis()->SetLabelSize(0.05);
  h2->GetXaxis()->SetLabelSize(0.05);
  h2->GetYaxis()->SetTitleSize(0.05);
  h2->GetXaxis()->SetTitleSize(0.05);
  TLegend* legend = new TLegend(0.58,0.8,0.98,0.98);//x1,y1,x2,y2
  gStyle->SetLegendTextSize(0.04);

  legend->AddEntry(h2,"100 GeV","l");
  legend->AddEntry(h3,"500 GeV","l");
  legend->AddEntry(h4,"1 TeV","l");
  legend->AddEntry(h5,"10 TeV","l");
  legend->AddEntry(h6,"30 TeV","l");
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
