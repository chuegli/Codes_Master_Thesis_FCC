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

void make_canvas(string outputname,TH1D* h1, string title);
void make_canvas(string outputname,TH1D* h1, TH1D* h2, TH1D* h3, string title);
void make_canvas(string outputname,TH1D* h1, TH1D* h2, string title);
void plot_beta(string rootname, string outputname);

int main(int argc, char **argv){
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }
    string filename1 = argv[1];
    string outputname= argv[2];
    plot_beta(filename1, outputname);

    return 0;
}

void plot_beta(string rootname, string outputname){
    cout << "************* Read histograms **********************" << endl;
    string rootname1 = "/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/wino_5x5_selected_histo.root";
    string rootname2 = "/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_bea_5x5.root";
    cout << "test 0" << endl;
    TFile *f1 = new TFile(rootname1.c_str());
    TFile *f2 = new TFile(rootname2.c_str());

    // cout << "test 1" << endl;
    //
    // TH1D* c_h_hit_beta_5  = (TH1D*)f1->Get("h_hit_beta_5");
    // TH1D* c_h_hit_beta_10 = (TH1D*)f1->Get("h_hit_beta_10");
    // TH1D* c_h_hit_beta_50 = (TH1D*)f1->Get("h_hit_beta_50");
    // c_h_hit_beta_5->Scale(1./c_h_hit_beta_5->Integral());
    // c_h_hit_beta_10->Scale(1./c_h_hit_beta_10->Integral());
    // c_h_hit_beta_50->Scale(1./c_h_hit_beta_50->Integral());
    // cout << "test 2" << endl;
    // // make_canvas(outputname,c_h_hit_beta_10, "; hit beta [ ] ; Entries");
    // make_canvas(outputname,c_h_hit_beta_5,c_h_hit_beta_10,c_h_hit_beta_50, "; hit beta [ ] ; Entries");
    // cout << "test 3" << endl;


    TH1D* c_h_hit_beta_10_2 = (TH1D*)f1->Get("h_hit_beta_10");
    TH1D* c_h_Delta_beta_10 = (TH1D*)f2->Get("h_Delta_beta_10");
    TH1D* c_h_Delta_beta_MC = (TH1D*)f2->Get("h_Delta_beta_MC");
    c_h_Delta_beta_MC->Scale(1./c_h_Delta_beta_MC->Integral());
    c_h_Delta_beta_10->Scale(1./c_h_Delta_beta_10->Integral());
    c_h_hit_beta_10_2->Scale(1./c_h_hit_beta_10_2->Integral());
    make_canvas(outputname,c_h_hit_beta_10_2,c_h_Delta_beta_MC, "; hit beta [ ] ; Entries");
    // make_canvas(outputname,c_h_Delta_beta_10,c_h_Delta_beta_MC, "; hit beta [ ] ; Entries");
}

void make_canvas(string outputname,TH1D* h1, string title){
  TCanvas *canvas = new TCanvas("canvas","");
  canvas->SetGrid();
  // canvas->SetLogy();
  gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  string ss1 = outputname+".pdf[";
  string ss2 = outputname+".pdf";
  string ss3 = outputname+".pdf]";

  h1->Draw("hist h");
  // h1->SetMaximum(max);
  h1->SetNdivisions(5);
  h1->SetTitle(title.c_str());
  h1->GetYaxis()->SetLabelSize(0.05);
  h1->GetXaxis()->SetLabelSize(0.05);
  h1->GetYaxis()->SetTitleSize(0.05);
  h1->GetXaxis()->SetTitleSize(0.05);

  canvas->SaveAs(ss2.c_str());
  canvas->Close();
}

void make_canvas(string outputname,TH1D* h1, TH1D* h2, TH1D* h3, string title){
  TCanvas *canvas = new TCanvas("canvas","");
  canvas->SetGrid();
  // canvas->SetLogy();

  gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  string ss1 = outputname+"_comparison.pdf[";
  string ss2 = outputname+"_comparison.pdf";
  string ss3 = outputname+"_comparison.pdf]";

  h1->Draw("hist h");
  // h1->SetMaximum(max);
  h1->SetNdivisions(5);
  h2->SetLineColor(2);
  h3->SetLineColor(8);
  h2->Draw("hist h same");
  h3->Draw("hist h same");
  h1->SetTitle(title.c_str());
  h1->GetYaxis()->SetLabelSize(0.05);
  h1->GetXaxis()->SetLabelSize(0.05);
  h1->GetYaxis()->SetTitleSize(0.05);
  h1->GetXaxis()->SetTitleSize(0.05);
  TLegend* legend = new TLegend(0.68,0.7,0.84,0.89);//x1,y1,x2,y2
  gStyle->SetLegendTextSize(0.04);
  legend->AddEntry(h1,"5 ps","l");
  legend->AddEntry(h2,"10 ps","l");
  legend->AddEntry(h3,"50 ps","l");
  legend->Draw();

  canvas->SaveAs(ss2.c_str());
  canvas->Close();
}

void make_canvas(string outputname,TH1D* h1, TH1D* h2, string title){
  TCanvas *canvas = new TCanvas("canvas","");
  canvas->SetGrid();
  // canvas->SetLogy();

  gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  string ss1 = outputname+"_comparison_MC.pdf[";
  string ss2 = outputname+"_comparison_MC.pdf";
  string ss3 = outputname+"_comparison_MC.pdf]";

  h1->Draw("hist h");
  h1->SetMaximum(0.15);
  h1->SetNdivisions(5);
  h2->SetLineColor(2);
  h2->Draw("hist h same");
  h1->SetTitle(title.c_str());
  h1->GetYaxis()->SetLabelSize(0.05);
  h1->GetXaxis()->SetLabelSize(0.05);
  h1->GetYaxis()->SetTitleSize(0.05);
  h1->GetXaxis()->SetTitleSize(0.05);
  TLegend* legend = new TLegend(0.64,0.7,0.84,0.89);//x1,y1,x2,y2
  gStyle->SetLegendTextSize(0.04);
  legend->AddEntry(h1,"reco 10 ps","l");
  legend->AddEntry(h2,"true","l");
  legend->Draw();

  canvas->SaveAs(ss2.c_str());
  canvas->Close();
}
