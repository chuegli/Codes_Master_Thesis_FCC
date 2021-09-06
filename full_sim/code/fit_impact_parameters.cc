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


///////////////////////////////////////////////////////////////////////////////
// Fits the d0 and z0 distributions to find their resolutions
//
// scp fit_impact_parameters.cc chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/code/
// root -q fit_impact_parameters.cc


void make_fit_beta();

void fit_impact_parameters(){
  make_fit_beta();
  cout << "***************** Finished ****************" << endl << endl;
}

void make_fit_beta(){
  string rootname1 = "/afs/cern.ch/work/c/chugli/private/FCCSW_3/charginos/root_files_size_2/winos_other.root";
  TFile *f1 = new TFile(rootname1.c_str());

  TH1D* c1_h_d0= (TH1D*)f1->Get("h_d0");
  TH1D* c1_h_z0= (TH1D*)f1->Get("h_z0");

  cout << "********************* Start fitting *********************" << endl;
  //https://root.cern.ch/root/htmldoc/guides/users-guide/FittingHistograms.html
  cout << endl << "********** Fit to d0 **************" << endl;
  TF1 *myfit1 = new TF1("myfit1","[0]*exp(-0.5*((x-[1])/[2])^2/(sqrt(2*3.1415926535897932384626)*[2]))");
  myfit1->SetParameters(30,c1_h_d0->GetMean(),c1_h_d0->GetRMS());
  myfit1->SetParNames ("Constant","Mean_value","Sigma");
  c1_h_d0->Fit("myfit1","b v", "h");
  TF1* myf1 = c1_h_d0->GetFunction("myfit1");
  cout << "ndf: "  << myf1->GetNDF() << endl;
  cout << "chi2: " << myf1->GetChisquare() << endl;
  cout << "prob: " << myf1->GetProb() << endl;
  // cout << "" << g1->GetParameter(0);
  // fit->GetParError(0);

  TCanvas *canvas = new TCanvas("canvas","");
  canvas->SetGrid();
  // canvas->SetLogy();
  gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  cout << endl << "********** Fit to z0 **************" << endl;
  TF1 *myfit2 = new TF1("myfit2","[0]*exp(-0.5*((x-[1])/[2])^2/(sqrt(2*3.1415926535897932384626)*[2]))");
  myfit2->SetParameters(30,c1_h_z0->GetMean(),c1_h_z0->GetRMS());
  myfit2->SetParNames ("Constant","Mean_value","Sigma");
  c1_h_z0->Fit("myfit2","b v", "h");
  TF1* myf2 = c1_h_z0->GetFunction("myfit2");
  cout << "ndf: "  << myf2->GetNDF() << endl;
  cout << "chi2: " << myf2->GetChisquare() << endl;
  cout << "prob: " << myf2->GetProb() << endl;
  string title = "; Delta beta; Entries";
  c1_h_z0->SetTitle(title.c_str());
  c1_h_z0->GetXaxis()->SetNdivisions(5);
  c1_h_z0->GetYaxis()->SetLabelSize(0.05);
  c1_h_z0->GetXaxis()->SetLabelSize(0.05);
  c1_h_z0->GetYaxis()->SetTitleSize(0.05);
  c1_h_z0->GetXaxis()->SetTitleSize(0.05);
  canvas->SaveAs("../plots/impact_parameters.pdf");


}
