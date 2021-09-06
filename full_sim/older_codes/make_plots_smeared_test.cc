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

void make_canvas(TH1D* h1, string title, int pos, bool logy, double max);
void make_plots_2();

int main(int argc, char **argv){
    make_plots_2();
    return 0;
}

void make_plots_2(){
    cout << "************* Read histograms **********************" << endl;
    TFile *f = new TFile("/afs/cern.ch/work/c/chugli/private/FCCSW_2/charginos/root_files_size_2/winos_smeared_test.root");

    TH1D* c_h_Dx   = (TH1D*)f->Get("h_Dx");
    TH1D* c_h_Dy   = (TH1D*)f->Get("h_Dy");
    TH1D* c_h_Dz   = (TH1D*)f->Get("h_Dz");
    TH1D* c_h_Dt   = (TH1D*)f->Get("h_Dt");
    TH1D* c_h_De   = (TH1D*)f->Get("h_De");
    TH1D* c_h_Dr   = (TH1D*)f->Get("h_Dr");

    cout << "********************* Start plotting *********************" << endl;
    ///////////////////// 1D plots:
    make_canvas(c_h_Dx, "; First hit Delta x[mm]; Entires ",0,false,0);
    make_canvas(c_h_Dy, "; First hit Delta y[mm]; Entires ",1,false,0);
    make_canvas(c_h_Dz, "; First hit Delta z[mm]; Entires ",1,false,0);
    make_canvas(c_h_Dt, "; First hit Delta t[ns]; Entires ",1,false,0);
    make_canvas(c_h_De, "; First hit Delta e[GeV]; Entires ",1,false,0);
    make_canvas(c_h_Dr, "; First hit Delta r[mm]; Entires ",2,false,0);


}

void make_canvas(TH1D* h1, string title, int pos, bool logy, double max){
  TCanvas *canvas = new TCanvas("canvas","");
  canvas->SetGrid();

  if(logy){canvas->SetLogy();}

  gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  string ss1 = "./plots/winos_smeared_test.pdf[";
  string ss2 = "./plots/winos_smeared_test.pdf";
  string ss3 = "./plots/winos_smeared_test.pdf]";

  h1->Draw("hist h");
  if(max!=0){h1->SetMaximum(max);}
  h1->SetNdivisions(6);
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
