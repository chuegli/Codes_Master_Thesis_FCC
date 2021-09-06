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
#include <TGraphErrors.h>
#include <TColor.h>
#include <TSystemDirectory.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TPad.h>
#include <TH2D.h>
#include <TGraph2D.h>

#include <math.h>
#include <typeinfo>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
///////////// What this .cc does:
// Needs:
// kinematic_selection_wino_short_tot ... .txt
// kinematic_selection_higgsino_short_tot ... .txt
//
// 1) Reads kinematic_selection_wino/higgsino_short_tot
// 2) Plots them
////////////////////////////////////////////////////////////////////////////////

// scp best_kin_short_plots.cc chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/fast_sim/code/kinematic_selection/
// root -q -b best_kin_short_plots.cc
// scp chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/plot_sign_best_wino_3e-7.pdf ./

void graph_styling(TGraph* g, int j);
void h_graph_styling(TGraph* gr, int j);
void make_wino();
void make_higgsino();

void best_kin_short_plots(){
    make_wino();
    make_higgsino();
}

void make_wino(){

    ////// wino:
    Double_t mass[40] = {700 ,800 ,900 ,1000,1100,1200,1300,1400,1500,1600 ,1700,1800,1900 ,2000,2100,2200,2300,2400 ,2500,2600,2700,2800,2900,3000,3100 ,3200 ,3300,3400,3500,3600 ,3700,3800 ,3900 ,4000,4100,4200 ,4300,4400 ,4500,4600};
    Double_t pt[40]   = {1000,1000,1000,1000,1000,1000,1000,1000,1000,10000,1000,2000,10000,9600,2000,4400,2000,10000,9700,1000,1000,9600,1000,2000,10000,10000,9600,1000,2000,10000,2000,10000,10000,9500,1000,10000,3700,10000,1000,1000};
    Double_t met[40]  = {2000,2000,2000,2000,2000,3000,2000,4200,3000,5000 ,3400,4200,7200 ,9000,4100,4300,4200,9600 ,8300,7000,9500,9000,4200,4300,10000,10000,9000,3000,4300,10000,4900,10000,10000,9000,4300,10000,6500,10000,4100,10000};
    Double_t inf = 1e10;
    Double_t sign[40] = {8910.9,6380.03,4729.81,3642.26,2985.67,2375.16,1849.38,1559.51,1178.96,833.519,822.152,870.254,779.198,1350.2,548.553,355.505,382.831,529.707,964.474,254.325,643.307,187.418,160.166,144.225,123.698,138.37,118.743,62.0537,66.3301,65.386,56.4491,45.4086,59.6015,44.5608,32.4293,47.6626,28.2923,48.9298,19.649,23.4238};
    Double_t err[40] = {};
    Double_t err_0[40] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    ///////////////////////////////////////////////////////////////////////////
    Double_t sign_short1[32], mass_short1[32], sign_short2[22], mass_short2[22], err_short1[32], err_short2[22],err0_short1[32], err0_short2[22];

    for(int i=0; i<40;i++){
        if(i>=8){
          sign_short1[i-8] = sign[i];
          mass_short1[i-8] = mass[i];
          err_short1[i-8]  = err[i];
          err0_short1[i-8] = err_0[i];
        }
        if(i>=18){
          sign_short2[i-18] = sign[i];
          mass_short2[i-18] = mass[i];
          err_short2[i-18]  = err[i];
          err0_short2[i-18] = err_0[i];
        }
    }


    ///////////////////////////////////////////////////////////////////////////
    //// Plot everything:
    cout << "********************* Start plotting *********************" << endl;
    TCanvas *canvas = new TCanvas("c","");
    canvas->SetGrid();
    gPad->SetMargin(0.17,0.1,0.15,0.1);//l,r,b,t
    gStyle->SetOptTitle(0);
    gStyle->SetOptStat(0);

    TGraph *g0 = new TGraph(40, mass, sign);
    TGraph *gs0 = new TGraph(32, mass_short1, sign_short1);
    TGraph *gss0 = new TGraph(22, mass_short2, sign_short2);

    auto g0   = new TGraphErrors(40,mass,sign,err_0,err);
    auto gs0  = new TGraphErrors(32,mass_short1, sign_short1,err0_short1,err_short1);
    auto gss0 = new TGraphErrors(22,mass_short2, sign_short2,err0_short2,err_short2);

    graph_styling(g0, 9);
    graph_styling(gs0, 9);
    graph_styling(gss0, 9);

    string ss1 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/plot_sign_best_wino_3e-7.pdf[";
    string ss2 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/plot_sign_best_wino_3e-7.pdf";
    string ss3 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/plot_sign_best_wino_3e-7.pdf]";

    gs0->SetMaximum(1600);
    gs0->SetMinimum(0);
    // gs0->SetMinimum(limits_min[0]);
    gs0->Draw("AP");
    gPad->Update();
    // canvas->BuildLegend(0.7,0.7,0.9,0.9);
    canvas->SaveAs(ss1.c_str());
    canvas->SaveAs(ss2.c_str());
    canvas->Clear();

    // gss0->SetMaximum(limits_max[1]);
    // gss0->SetMinimum(limits_min[1]);
    gss0->SetMinimum(0);
    gss0->SetMaximum(300);
    gss0->Draw("AP");
    gPad->Update();
    // canvas->BuildLegend(0.7,0.7,0.9,0.9);
    canvas->SaveAs(ss2.c_str());
    canvas->Clear();

    canvas->SetLogy();

    // g0->SetMaximum(limits_max[2]);
    // g0->SetMinimum(limits_min[2]);
    g0->Draw("AP");
    g0->SetMinimum(1);
    gPad->Update();
    // canvas->BuildLegend(0.7,0.7,0.9,0.9);
    canvas->SaveAs(ss2.c_str());
    canvas->Clear();

    g0->SetMaximum(20000);
    g0->SetMinimum(1);
    g0->Draw("AP");
    gPad->Update();
    // canvas->BuildLegend(0.7,0.7,0.9,0.9);
    canvas->SaveAs(ss2.c_str());
    canvas->SaveAs(ss3.c_str());
    canvas->Close();
}

void make_higgsino(){

    ////// higgsino:
    Double_t mass[9] = {700 ,800 ,900 ,1000,1100,1200,1300,1400,1500};
    Double_t pt[9]   = {100 ,100 ,4600,1600,2600,6000,6000,2800,5200};
    Double_t met[9]  = {3000,6000,5000,4300,4500,5400,5600,5200,5400};
    Double_t sign[9] = {45.6516,77.6932,30.7038,28.7923,9.21131,15.2976,8.02581,6.51943,3.1318};
    Double_t err[9] = {};
    Double_t err_0[9] = {0,0,0,0,0,0,0,0,0,0};

    ///////////////////////////////////////////////////////////////////////////
    //// Plot everything:
    cout << "********************* Start plotting *********************" << endl;
    TCanvas *canvas = new TCanvas("c","");
    canvas->SetGrid();
    gPad->SetMargin(0.17,0.1,0.15,0.1);//l,r,b,t
    gStyle->SetOptTitle(0);
    gStyle->SetOptStat(0);

    auto g0 = new TGraphErrors(9,mass,sign,err_0,err);

    graph_styling(g0, 9);

    string ss1 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/plot_sign_best_higgsino_3e-7.pdf[";
    string ss2 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/plot_sign_best_higgsino_3e-7.pdf";
    string ss3 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/plot_sign_best_higgsino_3e-7.pdf]";

    // gs0->SetMaximum(1600);
    g0->SetMinimum(0);
    // gs0->SetMinimum(limits_min[0]);
    g0->Draw("AP");
    gPad->Update();
    // canvas->BuildLegend(0.7,0.7,0.9,0.9);
    canvas->SaveAs(ss1.c_str());
    canvas->SaveAs(ss2.c_str());
    canvas->Clear();

    canvas->SetLogy();

    // g0->SetMaximum(limits_max[2]);
    // g0->SetMinimum(limits_min[2]);
    g0->Draw("AP");
    g0->SetMinimum(1);
    gPad->Update();
    // canvas->BuildLegend(0.7,0.7,0.9,0.9);
    canvas->SaveAs(ss2.c_str());
    canvas->SaveAs(ss3.c_str());
    canvas->Close();
}

void graph_styling(TGraphErrors* gr, int j){
  if(j==5){j=94;}
  gr->SetLineColor(j);
  gr->SetLineWidth(1);
  gr->SetMarkerColor(j);
  gr->SetMarkerSize(1);
  gr->SetMarkerStyle(8);
  gr->GetXaxis()->SetTitle("Higgsino mass [GeV]");
  gr->GetYaxis()->SetTitle("Significance");
  gr->GetYaxis()->SetLabelSize(0.05);
  gr->GetXaxis()->SetLabelSize(0.05);
  gr->GetYaxis()->SetTitleSize(0.05);
  gr->GetXaxis()->SetTitleSize(0.05);
  // gr->GetXaxis()->SetNdivisions(5,10,1);
}

void h_graph_styling(TGraph* gr, int j){
  if(j==5){j=94;}
  gr->SetLineColor(j);
  gr->SetLineWidth(1);
  gr->SetMarkerColor(j);
  gr->SetMarkerSize(1);
  gr->SetMarkerStyle(8);
  gr->GetXaxis()->SetTitle("Higgsino mass");
  gr->GetYaxis()->SetTitle("Significance");
  gr->GetYaxis()->SetLabelSize(0.05);
  gr->GetXaxis()->SetLabelSize(0.05);
  gr->GetYaxis()->SetTitleSize(0.05);
  gr->GetXaxis()->SetTitleSize(0.05);
}
