#include <TH1D.h>
#include <TH2D.h>
#include <TH3D.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TStyle.h>
#include <TLegend.h>
#include <TLorentzVector.h>
#include <TRandom.h>
#include "TROOT.h"
#include "TTree.h"
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TF1.h>

#include <iostream>

using namespace std;


// auto make_fit(TH1D* c_h_beta, bool plot, string nr);

auto make_fit(TH1D* c_h_beta, bool plot, string nr){
  cout << "****** test 1 *******" << endl;
  struct returno {        // Declare a local structure
    double sigma, sigma_err;
  };
  double s;
  double s_err;
  cout << "****** test 2 *******" << endl;
  if(plot){
    cout << "****** test 3 *******" << endl;
    TCanvas *canvas = new TCanvas("canvas","");
    canvas->SetGrid();
    gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
    gStyle->SetOptTitle(0);
    gStyle->SetOptStat(0);

    string ss2 = "../plots/wino_fit_size_2_beta_"+nr+".pdf";

    cout << "****** test 4 *******" << endl;
    TF1 *myfit5 = new TF1("myfit5","[0]*exp(-0.5*((x-[1])/[2])^2/(sqrt(2*3.1415926535897932384626)*[2]))");
    cout << "****** test 4.5 *******" << endl;
    myfit5->SetParameters(30,c_h_beta->GetMean(),c_h_beta->GetRMS());
    cout << "****** test 5 *******" << endl;
    c_h_beta->Fit("myfit5","b v", "h");
    cout << "****** test 6 *******" << endl;
    TF1* myf5 = c_h_beta->GetFunction("myfit5");
    cout << "ndf: "  << myf5->GetNDF() << endl;
    cout << "chi2: " << myf5->GetChisquare() << endl;
    cout << "prob: " << myf5->GetProb() << endl;
    cout << "sigma: " << myf5->GetParameter(2) << endl;
    cout << "sigma err: " << myf5->GetParError(2) << endl;

    c_h_beta->GetXaxis()->SetNdivisions(5);
    c_h_beta->GetYaxis()->SetLabelSize(0.05);
    c_h_beta->GetXaxis()->SetLabelSize(0.05);
    c_h_beta->GetYaxis()->SetTitleSize(0.05);
    c_h_beta->GetXaxis()->SetTitleSize(0.05);
    canvas->SaveAs(ss2.c_str());

    s = myf5->GetParameter(2);
    s_err = myf5->GetParError(2);
    cout << "****** test 7 *******" << endl;
  }else{
    TF1 *myfit5 = new TF1("myfit5","[0]*exp(-0.5*((x-[1])/[2])^2/(sqrt(2*3.1415926535897932384626)*[2]))");
    myfit5->SetParameters(30,c_h_beta->GetMean(),c_h_beta->GetRMS());
    c_h_beta->Fit("myfit5","b v", "h");
    TF1* myf5 = c_h_beta->GetFunction("myfit5");
    cout << "ndf: "  << myf5->GetNDF() << endl;
    cout << "chi2: " << myf5->GetChisquare() << endl;
    cout << "prob: " << myf5->GetProb() << endl;
    cout << "sigma: " << myf5->GetParameter(2) << endl;

    s = myf5->GetParameter(2);
    s_err = myf5->GetParError(2);
  }

  return returno {s,s_err};
}

void make_fit_beta();

int main(int argc, char **argv){
  make_fit_beta();
  cout << "***************** Finished ****************" << endl << endl;

    return 0;
}

void make_fit_beta(){
  cout << "************* Read histogram delta qOverP **********************" << endl;
  string rootname = "/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_beta_5x5_time.root";
  TFile *f = new TFile(rootname.c_str());

  TH1D* c_h_beta_5  = (TH1D*)f->Get("h_Delta_beta_5");
  TH1D* c_h_beta_10 = (TH1D*)f->Get("h_Delta_beta_10");
  TH1D* c_h_beta_15 = (TH1D*)f->Get("h_Delta_beta_15");
  TH1D* c_h_beta_20 = (TH1D*)f->Get("h_Delta_beta_20");
  TH1D* c_h_beta_25 = (TH1D*)f->Get("h_Delta_beta_25");
  TH1D* c_h_beta_30 = (TH1D*)f->Get("h_Delta_beta_30");
  TH1D* c_h_beta_35 = (TH1D*)f->Get("h_Delta_beta_35");
  TH1D* c_h_beta_40 = (TH1D*)f->Get("h_Delta_beta_40");
  TH1D* c_h_beta_45 = (TH1D*)f->Get("h_Delta_beta_45");
  TH1D* c_h_beta_50 = (TH1D*)f->Get("h_Delta_beta_50");


  cout << "********************* Start fitting *********************" << endl;
  //https://root.cern.ch/root/htmldoc/guides/users-guide/FittingHistograms.html

  double beta_resolution[10];
  double beta_resolutions_err[10];
  double t_resolution[10] = {5,10,15,20,25,30,35,40,45,50}; // in ps

  cout << endl << "********** Fit to 5 ps **************" << endl;
  auto [v1,v11] = make_fit(c_h_beta_5, true, "5");
  cout << "****** test 0 *******" << endl;
  beta_resolution[0] = v1;
  beta_resolutions_err[0] = v11;

  cout << endl << "********** Fit to 10 ps **************" << endl;
  auto [v2,v22] = make_fit(c_h_beta_10, true, "10");
  beta_resolution[1] = v2;
  beta_resolutions_err[1] = v22;

  cout << endl << "********** Fit to 15 ps **************" << endl;
  auto [v3,v33] = make_fit(c_h_beta_15, true, "15");
  beta_resolution[2] = v3;
  beta_resolutions_err[2] = v33;

  cout << endl << "********** Fit to 20 ps **************" << endl;
  auto [v4,v44] = make_fit(c_h_beta_20, true, "20");
  beta_resolution[3] = v4;
  beta_resolutions_err[3] = v44;

  cout << endl << "********** Fit to 25 ps **************" << endl;
  auto [v5,v55] = make_fit(c_h_beta_25, true, "25");
  beta_resolution[4] = v5;
  beta_resolutions_err[4] = v55;

  cout << endl << "********** Fit to 30 ps **************" << endl;
  auto [v6,v66] = make_fit(c_h_beta_30, true, "30");
  beta_resolution[5] = v6;
  beta_resolutions_err[5] = v66;

  cout << endl << "********** Fit to 35 ps **************" << endl;
  auto [v7,v77] = make_fit(c_h_beta_35, true, "35");
  beta_resolution[6] = v7;
  beta_resolutions_err[6] = v77;

  cout << endl << "********** Fit to 40 ps **************" << endl;
  auto [v8,v88] = make_fit(c_h_beta_40, true, "40");
  beta_resolution[7] = v8;
  beta_resolutions_err[7] = v88;

  cout << endl << "********** Fit to 45 ps **************" << endl;
  auto [v9,v99] = make_fit(c_h_beta_45, true, "45");
  beta_resolution[8] = v9;
  beta_resolutions_err[8] = v99;

  cout << endl << "********** Fit to 50 ps **************" << endl;
  auto [v0,v00] = make_fit(c_h_beta_50, true, "50");
  beta_resolution[9] = v0;
  beta_resolutions_err[9] = v00;
  cout << "Test: " << beta_resolution[9] << "   " << beta_resolutions_err[9] << endl;


  TCanvas *canvas = new TCanvas("canvas","");
  canvas->SetGrid();
  gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  string ss1 = "/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/plots/wino_beta_versus_time.pdf[";
  string ss2 = "/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/plots/wino_beta_versus_time.pdf";
  string ss3 = "/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/plots/wino_beta_versus_time.pdf]";

  double ex[10]= {0,0,0,0,0,0,0,0,0,0};
  auto gr = new TGraphErrors(10,t_resolution,beta_resolution,ex,beta_resolutions_err);
  // gr->SetTitle("TGraphErrors Example");
  gr->SetMarkerColor(4);
  gr->SetMarkerStyle(21);
  gr->Draw("ALP");

  // TGraph* gr = new TGraph(10,t_resolution,beta_resolution);
  // gr->Draw("AC*");

  string title = "; Time resolution [ps]; Beta resolution [ ]";
  gr->SetTitle(title.c_str());
  gr->GetXaxis()->SetNdivisions(10);
  gr->GetYaxis()->SetLabelSize(0.05);
  gr->GetXaxis()->SetLabelSize(0.05);
  gr->GetYaxis()->SetTitleSize(0.05);
  gr->GetXaxis()->SetTitleSize(0.05);
  canvas->SaveAs(ss1.c_str());
  canvas->SaveAs(ss2.c_str());

  canvas->Clear();

  double xx[10];
  xx[0] = c_h_beta_5->GetRMS();
  xx[1] = c_h_beta_10->GetRMS();
  xx[2] = c_h_beta_15->GetRMS();
  xx[3] = c_h_beta_20->GetRMS();
  xx[4] = c_h_beta_25->GetRMS();
  xx[5] = c_h_beta_30->GetRMS();
  xx[6] = c_h_beta_35->GetRMS();
  xx[7] = c_h_beta_40->GetRMS();
  xx[8] = c_h_beta_45->GetRMS();
  xx[9] = c_h_beta_50->GetRMS();
  auto gr2 = new TGraph(10,t_resolution,xx);
  gr2->SetMarkerColor(4);
  gr2->SetMarkerStyle(21);
  gr2->Draw("ALP");
  gr2->SetTitle(title.c_str());
  gr2->GetXaxis()->SetNdivisions(10);
  gr2->GetYaxis()->SetLabelSize(0.05);
  gr2->GetXaxis()->SetLabelSize(0.05);
  gr2->GetYaxis()->SetTitleSize(0.05);
  gr2->GetXaxis()->SetTitleSize(0.05);
  canvas->SaveAs(ss2.c_str());
  canvas->SaveAs(ss3.c_str());

  cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
  cout << c_h_beta_5->GetRMS()  << "  " << c_h_beta_5 ->GetRMSError() << endl;
  cout << c_h_beta_10->GetRMS() << "  " << c_h_beta_10->GetRMSError() << endl;
  cout << c_h_beta_15->GetRMS() << "  " << c_h_beta_15->GetRMSError() << endl;
  cout << c_h_beta_20->GetRMS() << "  " << c_h_beta_20->GetRMSError() << endl;
  cout << c_h_beta_25->GetRMS() << "  " << c_h_beta_25->GetRMSError() << endl;
  cout << c_h_beta_30->GetRMS() << "  " << c_h_beta_30->GetRMSError() << endl;
  cout << c_h_beta_35->GetRMS() << "  " << c_h_beta_35->GetRMSError() << endl;
  cout << c_h_beta_40->GetRMS() << "  " << c_h_beta_40->GetRMSError() << endl;
  cout << c_h_beta_45->GetRMS() << "  " << c_h_beta_45->GetRMSError() << endl;
  cout << c_h_beta_50->GetRMS() << "  " << c_h_beta_50->GetRMSError() << endl;
cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;

}
