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

void Delta_q_p();
void Delta_beta();

void wino_fitting(){
  Delta_q_p();
  // Delta_beta();
  cout << "***************** Finished ****************" << endl << endl;
}

void Delta_q_p(){
  cout << "************* Read histogram delta qOverP **********************" << endl;
  string rootname1 = "root_files_size_1/winos_10000_Delta_q_pt.root";
  string rootname2 = "root_files_size_2/winos_10000_Delta_q_pt.root";
  string rootname3 = "root_files_size_3/winos_10000_Delta_q_pt.root";
  TFile *f1 = new TFile(rootname1.c_str());
  TFile *f2 = new TFile(rootname2.c_str());
  TFile *f3 = new TFile(rootname3.c_str());

  TH1D* c1_h_Delta_q_pt = (TH1D*)f1->Get("h_Delta_q_pt");
  TH1D* c2_h_Delta_q_pt = (TH1D*)f2->Get("h_Delta_q_pt");
  TH1D* c3_h_Delta_q_pt = (TH1D*)f3->Get("h_Delta_q_pt");

  cout << "********************* Start fitting *********************" << endl;
  //https://root.cern.ch/root/htmldoc/guides/users-guide/FittingHistograms.html

  TCanvas *canvas = new TCanvas("canvas","");
  canvas->SetGrid();
  // canvas->SetLogy();
  gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  string ss1 = "plots/wino_fit_size_1_Delta_qOverP.pdf";
  string ss2 = "plots/wino_fit_size_2_Delta_qOverP.pdf";
  string ss3 = "plots/wino_fit_size_3_Delta_qOverP.pdf";

  cout << endl << "********** Fit to size 1 **************" << endl;
  TF1 *myfit1 = new TF1("myfit1","[0]*exp(-0.5*((x-[1])/[2])^2/(sqrt(2*3.1415926535897932384626)*[2]))",-0.005,0.005);
  myfit1->SetParameters(70,c1_h_Delta_q_pt->GetMean(),c1_h_Delta_q_pt->GetRMS());
  c1_h_Delta_q_pt->Fit("myfit1","b v", "h");
  TF1* myf1 = c1_h_Delta_q_pt->GetFunction("myfit1");
  cout << "ndf: "  << myf1->GetNDF() << endl;
  cout << "chi2: " << myf1->GetChisquare() << endl;
  cout << "prob: " << myf1->GetProb() << endl;
  string title = "; Delta qOverP; Entries";
  c1_h_Delta_q_pt->SetTitle(title.c_str());
  c1_h_Delta_q_pt->GetXaxis()->SetNdivisions(5);
  c1_h_Delta_q_pt->GetYaxis()->SetLabelSize(0.05);
  c1_h_Delta_q_pt->GetXaxis()->SetLabelSize(0.05);
  c1_h_Delta_q_pt->GetYaxis()->SetTitleSize(0.05);
  c1_h_Delta_q_pt->GetXaxis()->SetTitleSize(0.05);
  canvas->SaveAs(ss1.c_str());

  cout << endl << "********** Fit to size 2 **************" << endl;
  TF1 *myfit2 = new TF1("myfit2","[0]*exp(-0.5*((x-[1])/[2])^2/(sqrt(2*3.1415926535897932384626)*[2]))",-0.005,0.005);
  myfit2->SetParameters(70,c2_h_Delta_q_pt->GetMean(),c2_h_Delta_q_pt->GetRMS());
  c2_h_Delta_q_pt->Fit("myfit2","b v", "h");
  TF1* myf2 = c2_h_Delta_q_pt->GetFunction("myfit2");
  cout << "ndf: "  << myf2->GetNDF() << endl;
  cout << "chi2: " << myf2->GetChisquare() << endl;
  cout << "prob: " << myf2->GetProb() << endl;
  title = "; Delta qOverP; Entries";
  c2_h_Delta_q_pt->SetTitle(title.c_str());
  c2_h_Delta_q_pt->GetXaxis()->SetNdivisions(5);
  c2_h_Delta_q_pt->GetYaxis()->SetLabelSize(0.05);
  c2_h_Delta_q_pt->GetXaxis()->SetLabelSize(0.05);
  c2_h_Delta_q_pt->GetYaxis()->SetTitleSize(0.05);
  c2_h_Delta_q_pt->GetXaxis()->SetTitleSize(0.05);
  canvas->SaveAs(ss2.c_str());

  cout << endl << "********** Fit to size 3 **************" << endl;
  TF1 *myfit3 = new TF1("myfit3","[0]*exp(-0.5*((x-[1])/[2])^2/(sqrt(2*3.1415926535897932384626)*[2]))",-0.005,0.005);
  myfit3->SetParameters(30,c3_h_Delta_q_pt->GetMean(),c3_h_Delta_q_pt->GetRMS());
  c3_h_Delta_q_pt->Fit("myfit3","b v", "h");
  TF1* myf3 = c3_h_Delta_q_pt->GetFunction("myfit3");
  cout << "ndf: "  << myf3->GetNDF() << endl;
  cout << "chi2: " << myf3->GetChisquare() << endl;
  cout << "prob: " << myf3->GetProb() << endl;
  title = "; Delta qOverP; Entries";
  c3_h_Delta_q_pt->SetTitle(title.c_str());
  c3_h_Delta_q_pt->GetXaxis()->SetNdivisions(5);
  c3_h_Delta_q_pt->GetYaxis()->SetLabelSize(0.05);
  c3_h_Delta_q_pt->GetXaxis()->SetLabelSize(0.05);
  c3_h_Delta_q_pt->GetYaxis()->SetTitleSize(0.05);
  c3_h_Delta_q_pt->GetXaxis()->SetTitleSize(0.05);
  canvas->SaveAs(ss3.c_str());
  canvas->Close();


}

void Delta_beta(){
  cout << "************* Read histogram beta **********************" << endl;
  string rootname = "root_files/wino_Delta_beta_10000.root";
  TFile *f = new TFile(rootname.c_str());

  TH1D* c_h_Delta_beta                 = (TH1D*)f->Get("h_Delta_beta");

  cout << "********************* Start fitting *********************" << endl;
  //https://root.cern.ch/root/htmldoc/guides/users-guide/FittingHistograms.html

  TCanvas *canvas = new TCanvas("canvas","");
  canvas->SetGrid();
  gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  string ss1 = "plots/wino_fit_beta.pdf[";
  string ss2 = "plots/wino_fit_beta.pdf";
  string ss3 = "plots/wino_fit_beta.pdf]";

  // TF1 *myfit = new TF1("myfit","[0]*exp(-0.5*((x-[1])/[2])^2/(sqrt(2*3.1415926535897932384626)*[2]))",-0.01,0.01);
  // myfit->SetParameters(100,c_h_Delta_beta->GetMean(),c_h_Delta_beta->GetRMS());

  TF1 *myfit = new TF1("myfit","crystalball",-0.02,0.01);
  myfit->SetParameters(190, c_h_Delta_beta->GetMean(), c_h_Delta_beta->GetRMS(), 10, 10);
  c_h_Delta_beta->Draw();
  // c_h_Delta_beta->Fit("myfit","b v", "h");
  // TF1* myf = c_h_Delta_beta->GetFunction("myfit");
  // cout << "ndf: " << myf->GetNDF() << endl;
  // cout << "chi2: " << myf->GetChisquare() << endl;
  // cout << "prob: " << myf->GetProb() << endl;
  string title = "; Delta beta; Entries";
  c_h_Delta_beta->SetTitle(title.c_str());
  c_h_Delta_beta->GetXaxis()->SetNdivisions(5);
  c_h_Delta_beta->GetYaxis()->SetLabelSize(0.05);
  c_h_Delta_beta->GetXaxis()->SetLabelSize(0.05);
  c_h_Delta_beta->GetYaxis()->SetTitleSize(0.05);
  c_h_Delta_beta->GetXaxis()->SetTitleSize(0.05);
  // canvas->SaveAs(ss1.c_str());
  canvas->SaveAs(ss2.c_str());

  // c_h_Delta_beta->Draw();
  // myfit->SetParameters(190, c_h_Delta_beta->GetMean(), c_h_Delta_beta->GetRMS(), 1, 1);
  // myfit->Draw("same");
  // title = "; Delta beta; Entries";
  // c_h_Delta_beta->SetTitle(title.c_str());
  // c_h_Delta_beta->GetXaxis()->SetNdivisions(5);
  // c_h_Delta_beta->GetYaxis()->SetLabelSize(0.05);
  // c_h_Delta_beta->GetXaxis()->SetLabelSize(0.05);
  // c_h_Delta_beta->GetYaxis()->SetTitleSize(0.05);
  // c_h_Delta_beta->GetXaxis()->SetTitleSize(0.05);
  // canvas->SaveAs(ss2.c_str());
  //
  // c_h_Delta_beta->Draw();
  // myfit->SetParameters(190, c_h_Delta_beta->GetMean(), c_h_Delta_beta->GetRMS(), 0.1, 0.1);
  // myfit->Draw("same");
  // title = "; Delta beta; Entries";
  // c_h_Delta_beta->SetTitle(title.c_str());
  // c_h_Delta_beta->GetXaxis()->SetNdivisions(5);
  // c_h_Delta_beta->GetYaxis()->SetLabelSize(0.05);
  // c_h_Delta_beta->GetXaxis()->SetLabelSize(0.05);
  // c_h_Delta_beta->GetYaxis()->SetTitleSize(0.05);
  // c_h_Delta_beta->GetXaxis()->SetTitleSize(0.05);
  // canvas->SaveAs(ss2.c_str());
  //
  // c_h_Delta_beta->Draw();
  // myfit->SetParameters(190, c_h_Delta_beta->GetMean(), c_h_Delta_beta->GetRMS(), 10, 10);
  // myfit->Draw("same");
  // title = "; Delta beta; Entries";
  // c_h_Delta_beta->SetTitle(title.c_str());
  // c_h_Delta_beta->GetXaxis()->SetNdivisions(5);
  // c_h_Delta_beta->GetYaxis()->SetLabelSize(0.05);
  // c_h_Delta_beta->GetXaxis()->SetLabelSize(0.05);
  // c_h_Delta_beta->GetYaxis()->SetTitleSize(0.05);
  // c_h_Delta_beta->GetXaxis()->SetTitleSize(0.05);
  // canvas->SaveAs(ss2.c_str());
  //
  // c_h_Delta_beta->Draw();
  // myfit->SetParameters(190, c_h_Delta_beta->GetMean(), c_h_Delta_beta->GetRMS(), 0.1, 10);
  // myfit->Draw("same");
  // title = "; Delta beta; Entries";
  // c_h_Delta_beta->SetTitle(title.c_str());
  // c_h_Delta_beta->GetXaxis()->SetNdivisions(5);
  // c_h_Delta_beta->GetYaxis()->SetLabelSize(0.05);
  // c_h_Delta_beta->GetXaxis()->SetLabelSize(0.05);
  // c_h_Delta_beta->GetYaxis()->SetTitleSize(0.05);
  // c_h_Delta_beta->GetXaxis()->SetTitleSize(0.05);
  // canvas->SaveAs(ss2.c_str());
  // canvas->SaveAs(ss3.c_str());
  canvas->Close();
}
