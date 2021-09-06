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

void make_canvas(string outputname, TH1D* h1, string title, int pos, bool logy, double max);
void make_canvas(string outputname,TH2D* h2, string title, int pos, bool logy, bool five);
void make_plots_2(string rootname, string outputname);

int main(int argc, char **argv){
    // std::cout << "Have " << argc << " arguments:" << std::endl;
    string filename,outputname;
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }
    filename = argv[1];
    outputname= argv[2];
    make_plots_2(filename, outputname);

    return 0;
}

void make_plots_2(string rootname, string outputname){
    cout << "************* Read histograms **********************" << endl;
    TFile *f = new TFile(rootname.c_str());

    TH2D* c_h2_z_vs_radius  = (TH2D*)f->Get("h2_z_vs_radius");
    TH1D* c_h1_radius_all   = (TH1D*)f->Get("h1_radius_all");
    TH1D* c_h1_radius_reco  = (TH1D*)f->Get("h1_radius_reco");
    TH2D* c_h2_pt_vs_radius = (TH2D*)f->Get("h2_pt_vs_radius");
    TH2D* c_h2_Reta_Seta    = (TH2D*)f->Get("h2_Reta_Seta");
    TH2D* c_h2_Rpz_Spz      = (TH2D*)f->Get("h2_Rpz_Spz");
    TH1D* c_h1_decay_z      = (TH1D*)f->Get("h1_decay_z");

    cout << "********************* Start plotting *********************" << endl;
    ///////////////////// 1D plots:
    make_canvas(outputname,c_h1_radius_reco, "; decay radius [mm]; Reconstruction efficiency", 0,false,0);
    make_canvas(outputname,c_h1_decay_z,  "; decay z [mm]; Entries", 1,false,0);
    make_canvas(outputname,c_h1_radius_all,  "; decay radius [mm]; Entries", 2,false,0);

    ///////////////////// 2D plots:
    make_canvas(outputname,c_h2_z_vs_radius, "; decay position z [mm]; decay radius [mm]",0,false,false);
    make_canvas(outputname,c_h2_Reta_Seta,"; Reconstructed eta; Simulated eta",1,false,false);
    make_canvas(outputname,c_h2_Rpz_Spz,"; Reconstructed pz [GeV]; Simulated pz [GeV]",1,false,true);
    make_canvas(outputname,c_h2_pt_vs_radius,"; Reconstructed pt [GeV]; decay radius [mm]",2,false,false);

}

void make_canvas(string outputname,TH1D* h1, string title, int pos, bool logy, double max){
  TCanvas *canvas = new TCanvas("canvas","");
  canvas->SetGrid();

  if(logy){canvas->SetLogy();}

  gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  string ss1 = outputname+".pdf[";
  string ss2 = outputname+".pdf";
  string ss3 = outputname+".pdf]";

  h1->Draw("hist h");
  if(max!=0){h1->SetMaximum(max);}
  h1->SetNdivisions(5);
  h1->SetTitle(title.c_str());
  h1->GetYaxis()->SetLabelSize(0.05);
  h1->GetXaxis()->SetLabelSize(0.05);
  h1->GetYaxis()->SetTitleSize(0.05);
  h1->GetXaxis()->SetTitleSize(0.05);

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

void make_canvas(string outputname,TH2D* h2, string title, int pos, bool logy, bool five){
  TCanvas *canvas = new TCanvas("canvas","");
  canvas->SetGrid();
  if(logy){canvas->SetLogy();}

  gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  string ss1 = outputname+"_2D.pdf[";
  string ss2 = outputname+"_2D.pdf";
  string ss3 = outputname+"_2D.pdf]";

  h2->Draw("colz");
  h2->SetTitle(title.c_str());
  if(five){h2->GetXaxis()->SetNdivisions(5);}
  h2->GetYaxis()->SetLabelSize(0.05);
  h2->GetXaxis()->SetLabelSize(0.05);
  h2->GetYaxis()->SetTitleSize(0.05);
  h2->GetXaxis()->SetTitleSize(0.05);

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
