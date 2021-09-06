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

void compare_thickness_all(){

    cout << "************* Read histograms **********************" << endl;

    string rootname1 = "/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_2_thick_1/winos_pt_thickness.root";
    string rootname2 = "/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_2_thick_2/winos_pt_thickness.root";
    string rootname3 = "/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_2_thick_3/winos_pt_thickness.root";
    string rootname4 = "/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_2_thick_4/winos_pt_thickness.root";
    string rootname5 = "/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_2_thick_5/winos_pt_thickness.root";
    string rootname6 = "/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_2/winos_pt_thickness.root";

    TFile *f1 = new TFile(rootname1.c_str());
    TFile *f2 = new TFile(rootname2.c_str());
    TFile *f3 = new TFile(rootname3.c_str());
    TFile *f4 = new TFile(rootname4.c_str());
    TFile *f5 = new TFile(rootname5.c_str());
    TFile *f6 = new TFile(rootname6.c_str());

    TH1D* c1_h_Tpt        = (TH1D*)f1->Get("h_Tpt");
    TH1D* c2_h_Tpt        = (TH1D*)f2->Get("h_Tpt");
    TH1D* c3_h_Tpt        = (TH1D*)f3->Get("h_Tpt");
    TH1D* c4_h_Tpt        = (TH1D*)f4->Get("h_Tpt");
    TH1D* c5_h_Tpt        = (TH1D*)f5->Get("h_Tpt");
    TH1D* c6_h_Tpt        = (TH1D*)f6->Get("h_Tpt");

    double mean[6];
    mean[0] = c1_h_Tpt->GetMean();
    mean[1] = c2_h_Tpt->GetMean();
    mean[2] = c3_h_Tpt->GetMean();
    mean[3] = c4_h_Tpt->GetMean();
    mean[4] = c5_h_Tpt->GetMean();
    mean[5] = c6_h_Tpt->GetMean();

    double thick[6] = {0.01,0.02,0.04,0.06,0.08,0.1};

    TCanvas *canvas = new TCanvas("canvas","");
    canvas->SetGrid();
    gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
    gStyle->SetOptTitle(0);
    gStyle->SetOptStat(0);
    string ss2 = "./plots/wino_fit_size_2_thick_vs_mean.pdf";
    auto gr = new TGraph(6,thick,mean);
    gr->SetMarkerColor(4);
    gr->SetMarkerStyle(21);
    gr->Draw("AC*");
    string title = "; Sensor thickness [mm];Mean of track pt distribution [GeV]";
    gr->SetTitle(title.c_str());
    gr->GetXaxis()->SetNdivisions(10);
    gr->GetYaxis()->SetLabelSize(0.05);
    gr->GetXaxis()->SetLabelSize(0.05);
    gr->GetYaxis()->SetTitleSize(0.05);
    gr->GetXaxis()->SetTitleSize(0.05);
    canvas->SaveAs(ss2.c_str());

}
