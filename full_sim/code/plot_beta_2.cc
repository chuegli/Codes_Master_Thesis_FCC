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
void plot_beta(string filename1, string filename2, string filename3, string outputname);

int main(int argc, char **argv){
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }
    string filename1 = argv[1];
    string filename2 = argv[2];
    string filename3 = argv[3];
    string outputname= argv[4];
    plot_beta(filename1, filename2, filename3, outputname);

    return 0;
}

void plot_beta(string filename1, string filename2, string filename3, string outputname){
    cout << "************* Read histograms **********************" << endl;
    TFile *f1 = new TFile(filename1.c_str());
    TFile *f2 = new TFile(filename2.c_str());
    TFile *f3 = new TFile(filename3.c_str());

    TH1D* c1_h_hit_beta_10 = (TH1D*)f1->Get("h_hit_beta_10");
    TH1D* c2_h_hit_beta_10 = (TH1D*)f2->Get("h_hit_beta_10");
    TH1D* c3_h_hit_beta_10 = (TH1D*)f3->Get("h_hit_beta_10");
    make_canvas(outputname,c1_h_hit_beta_10,c2_h_hit_beta_10,c3_h_hit_beta_10, "; hit beta [ ] ; Entries");

}

void make_canvas(string outputname,TH1D* h1, TH1D* h2, TH1D* h3, string title){
  TCanvas *canvas = new TCanvas("canvas","");
  canvas->SetGrid();
  // canvas->SetLogy();

  gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  string ss1 = outputname+"_comparison_2.pdf[";
  string ss2 = outputname+"_comparison_2.pdf";
  string ss3 = outputname+"_comparison_2.pdf]";

  h1->Draw("hist h");
  h1->SetMaximum(30);
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
  TLegend* legend = new TLegend(0.63,0.7,0.84,0.89);//x1,y1,x2,y2
  gStyle->SetLegendTextSize(0.04);
  legend->AddEntry(h1,"1#mumx1#mum","l");
  legend->AddEntry(h2,"5#mumx5#mum","l");
  legend->AddEntry(h3,"50#mumx50#mum","l");
  legend->Draw();

  canvas->SaveAs(ss2.c_str());
  canvas->Close();
}
