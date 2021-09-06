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

void make_fit_beta();

void wino_fitting_beta(){
  make_fit_beta();
  cout << "***************** Finished ****************" << endl << endl;
}

void make_fit_beta(){
  cout << "************* Read histogram delta qOverP **********************" << endl;
  string rootname1 = "/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_1/winos_beta.root";
  string rootname2 = "/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_2/winos_beta.root";
  string rootname3 = "/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_3/winos_beta.root";
  TFile *f1 = new TFile(rootname1.c_str());
  TFile *f2 = new TFile(rootname2.c_str());
  TFile *f3 = new TFile(rootname3.c_str());

  TH1D* c1_h_beta = (TH1D*)f1->Get("h_Delta_beta");
  TH1D* c2_h_beta = (TH1D*)f2->Get("h_Delta_beta");
  TH1D* c3_h_beta = (TH1D*)f3->Get("h_Delta_beta");

  cout << "********************* Start fitting *********************" << endl;
  //https://root.cern.ch/root/htmldoc/guides/users-guide/FittingHistograms.html

  TCanvas *canvas = new TCanvas("canvas","");
  canvas->SetGrid();
  // canvas->SetLogy();
  gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  string ss1 = "plots/wino_fit_size_1_beta.pdf";
  string ss2 = "plots/wino_fit_size_2_beta.pdf";
  string ss3 = "plots/wino_fit_size_3_beta.pdf";

  cout << endl << "********** Fit to size 1 **************" << endl;
  TF1 *myfit1 = new TF1("myfit1","[0]*exp(-0.5*((x-[1])/[2])^2/(sqrt(2*3.1415926535897932384626)*[2]))",-0.05,0.05);
  myfit1->SetParameters(30,c1_h_beta->GetMean(),c1_h_beta->GetRMS());
  c1_h_beta->Fit("myfit1","b v", "h");
  TF1* myf1 = c1_h_beta->GetFunction("myfit1");
  cout << "ndf: "  << myf1->GetNDF() << endl;
  cout << "chi2: " << myf1->GetChisquare() << endl;
  cout << "prob: " << myf1->GetProb() << endl;
  string title = "; Delta beta; Entries";
  c1_h_beta->SetTitle(title.c_str());
  c1_h_beta->GetXaxis()->SetNdivisions(5);
  c1_h_beta->GetYaxis()->SetLabelSize(0.05);
  c1_h_beta->GetXaxis()->SetLabelSize(0.05);
  c1_h_beta->GetYaxis()->SetTitleSize(0.05);
  c1_h_beta->GetXaxis()->SetTitleSize(0.05);
  canvas->SaveAs(ss1.c_str());

  cout << endl << "********** Fit to size 2 **************" << endl;
  TF1 *myfit2 = new TF1("myfit2","[0]*exp(-0.5*((x-[1])/[2])^2/(sqrt(2*3.1415926535897932384626)*[2]))",-0.05,0.05);
  myfit2->SetParameters(30,c2_h_beta->GetMean(),c2_h_beta->GetRMS());
  c2_h_beta->Fit("myfit2","b v", "h");
  TF1* myf2 = c2_h_beta->GetFunction("myfit2");
  cout << "ndf: "  << myf2->GetNDF() << endl;
  cout << "chi2: " << myf2->GetChisquare() << endl;
  cout << "prob: " << myf2->GetProb() << endl;
  title = "; Delta beta; Entries";
  c2_h_beta->SetTitle(title.c_str());
  c2_h_beta->GetXaxis()->SetNdivisions(5);
  c2_h_beta->GetYaxis()->SetLabelSize(0.05);
  c2_h_beta->GetXaxis()->SetLabelSize(0.05);
  c2_h_beta->GetYaxis()->SetTitleSize(0.05);
  c2_h_beta->GetXaxis()->SetTitleSize(0.05);
  canvas->SaveAs(ss2.c_str());

  cout << endl << "********** Fit to size 3 **************" << endl;
  TF1 *myfit3 = new TF1("myfit3","[0]*exp(-0.5*((x-[1])/[2])^2/(sqrt(2*3.1415926535897932384626)*[2]))",-0.05,0.05);
  myfit3->SetParameters(30,c3_h_beta->GetMean(),c3_h_beta->GetRMS());
  c3_h_beta->Fit("myfit3","b v", "h");
  TF1* myf3 = c3_h_beta->GetFunction("myfit3");
  cout << "ndf: "  << myf3->GetNDF() << endl;
  cout << "chi2: " << myf3->GetChisquare() << endl;
  cout << "prob: " << myf3->GetProb() << endl;
  title = "; Delta beta; Entries";
  c3_h_beta->SetTitle(title.c_str());
  c3_h_beta->GetXaxis()->SetNdivisions(5);
  c3_h_beta->GetYaxis()->SetLabelSize(0.05);
  c3_h_beta->GetXaxis()->SetLabelSize(0.05);
  c3_h_beta->GetYaxis()->SetTitleSize(0.05);
  c3_h_beta->GetXaxis()->SetTitleSize(0.05);
  canvas->SaveAs(ss3.c_str());
  canvas->Close();


}
