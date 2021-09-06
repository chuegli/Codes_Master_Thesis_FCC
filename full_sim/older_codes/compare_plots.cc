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

void make_canvas(TH1D* h1, TH1D* h2, bool two, string title, bool MC = false, int pos = 1, bool logy = false, double max = 0);
void make_canvas(TH2D* h2, string title, int pos = 1);

void compare_plots(){
    cout << "************* Read histograms **********************" << endl;
    string rootname1 = "root_files/wino_1000.root";
    // string rootname2 = "wino_stable.root";
    string rootname2 = "root_files/wino_stable_1000.root";
    // string rootname2 = "wino_stabe1.root";
    TFile *f1 = new TFile(rootname1.c_str());
    TFile *f2 = new TFile(rootname2.c_str());

    TH1D* c1_h_eta               = (TH1D*)f1->Get("h_eta");
    TH1D* c1_h_phi               = (TH1D*)f1->Get("h_phi");
    TH1D* c1_h_pt                = (TH1D*)f1->Get("h_pt");
    TH1D* c1_h_px                = (TH1D*)f1->Get("h_px");
    TH1D* c1_h_py                = (TH1D*)f1->Get("h_py");
    TH1D* c1_h_pz                = (TH1D*)f1->Get("h_pz");
    TH1D* c1_h_betagammasintheta = (TH1D*)f1->Get("h_betagammasintheta");
    TH1D* c1_h_E                 = (TH1D*)f1->Get("h_E");
    TH1D* c1_h_hit_energy        = (TH1D*)f1->Get("h_hit_energy");
    TH1D* c1_h_hit_time          = (TH1D*)f1->Get("h_hit_time");

    TH1D* c2_h_eta               = (TH1D*)f2->Get("h_eta");
    TH1D* c2_h_phi               = (TH1D*)f2->Get("h_phi");
    TH1D* c2_h_pt                = (TH1D*)f2->Get("h_pt");
    TH1D* c2_h_px                = (TH1D*)f2->Get("h_px");
    TH1D* c2_h_py                = (TH1D*)f2->Get("h_py");
    TH1D* c2_h_pz                = (TH1D*)f2->Get("h_pz");
    TH1D* c2_h_betagammasintheta = (TH1D*)f2->Get("h_betagammasintheta");
    TH1D* c2_h_E                 = (TH1D*)f2->Get("h_E");
    TH1D* c2_h_hit_energy        = (TH1D*)f2->Get("h_hit_energy");
    TH1D* c2_h_hit_time          = (TH1D*)f2->Get("h_hit_time");


    ///// Normalization for comparison:
    // c1_h_eta              ->Scale(1./c1_h_eta->Integral());
    // c1_h_phi              ->Scale(1./c1_h_phi->Integral());
    // c1_h_pt               ->Scale(1./c1_h_pt->Integral());
    // c1_h_px               ->Scale(1./c1_h_px->Integral());
    // c1_h_py               ->Scale(1./c1_h_py->Integral());
    // c1_h_pz               ->Scale(1./c1_h_pz->Integral());
    // c1_h_betagammasintheta->Scale(1./c1_h_betagammasintheta->Integral());
    // c1_h_E                ->Scale(1./c1_h_E->Integral());
    // c2_h_eta              ->Scale(1./c2_h_eta->Integral());
    // c2_h_phi              ->Scale(1./c2_h_phi->Integral());
    // c2_h_pt               ->Scale(1./c2_h_pt->Integral());
    // c2_h_px               ->Scale(1./c2_h_px->Integral());
    // c2_h_py               ->Scale(1./c2_h_py->Integral());
    // c2_h_pz               ->Scale(1./c2_h_pz->Integral());
    // c2_h_betagammasintheta->Scale(1./c2_h_betagammasintheta->Integral());
    // c2_h_E                ->Scale(1./c2_h_E->Integral());
    c2_h_hit_energy->Scale(1./c2_h_hit_energy->Integral());
    c2_h_hit_time  ->Scale(1./c2_h_hit_time->Integral());
    c1_h_hit_energy->Scale(1./c1_h_hit_energy->Integral());
    c1_h_hit_time  ->Scale(1./c1_h_hit_time->Integral());


    cout << "********************* Start plotting *********************" << endl;
    make_canvas(c1_h_eta              ,c2_h_eta,              true,"; MC eta;Entries",false,0,false);
    make_canvas(c1_h_phi              ,c2_h_phi,              true,"; MC phi;Entries",false,1,false);
    make_canvas(c1_h_pt               ,c2_h_pt,               true,"; MC pt;Entries",false,1,false);
    make_canvas(c1_h_px               ,c2_h_px,               true,"; MC px;Entries",false,1,false);
    make_canvas(c1_h_py               ,c2_h_py,               true,"; MC py;Entries",false,1,false);
    make_canvas(c1_h_pz               ,c2_h_pz,               true,"; MC pz;Entries");
    make_canvas(c1_h_betagammasintheta,c2_h_betagammasintheta,true,"; MC beta*gamma*sin(theta);Entries");
    make_canvas(c1_h_E                ,c2_h_E,                true,"; MC energy;Entries");
    make_canvas(c1_h_hit_energy       ,c2_h_hit_energy,       true,"; Hit energy; Normalized entries",false,1,true);
    make_canvas(c1_h_hit_time         ,c2_h_hit_time,         true,"; Hit time; Normalized entries",false,2,true);

}

void make_canvas(TH1D* h1, TH1D* h2, bool two, string title, bool MC = false, int pos = 1, bool logy = false, double max = 0){
  TCanvas *canvas = new TCanvas("canvas","");
  canvas->SetGrid();

  if(logy){
    canvas->SetLogy();
    h1->SetMinimum(1);
  }

  gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  string ss1 = "plots/winos_plots_stable_comparison.pdf[";
  string ss2 = "plots/winos_plots_stable_comparison.pdf";
  string ss3 = "plots/winos_plots_stable_comparison.pdf]";
  if(two){
      h1->Draw("hist h");
      if(max!=0){h1->SetMaximum(max);}
      h1->SetNdivisions(5);
      h2->SetLineColor(2);
      h2->Draw("hist h same");
      h1->SetTitle(title.c_str());
      h1->GetYaxis()->SetLabelSize(0.05);
      h1->GetXaxis()->SetLabelSize(0.05);
      h1->GetYaxis()->SetTitleSize(0.05);
      h1->GetXaxis()->SetTitleSize(0.05);
      TLegend* legend = new TLegend(0.58,0.8,0.98,0.98);//x1,y1,x2,y2
      gStyle->SetLegendTextSize(0.04);
      // if(MC){legend->AddEntry(h1,"MC Particles","l");}
      // else{legend->AddEntry(h1,"All Reco Particles","l");}
      // legend->AddEntry(h2,"Best Reco Particles","l");

      legend->AddEntry(h1,"Stable","l");
      legend->AddEntry(h2,"Not stable","l");

      // legend->AddEntry(h1,"Normal","l");
      // legend->AddEntry(h2,"Test test","l");
      legend->Draw();
  }else{
      h1->Draw("hist h");
      if(max!=0){h1->SetMaximum(max);}
      h1->SetTitle(title.c_str());
      h1->GetYaxis()->SetLabelSize(0.05);
      h1->GetXaxis()->SetLabelSize(0.05);
      h1->GetYaxis()->SetTitleSize(0.05);
      h1->GetXaxis()->SetTitleSize(0.05);
  }
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
