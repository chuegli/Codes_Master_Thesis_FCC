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

    TH1D* c_h_vertex_r_e1 = (TH1D*)f->Get("h_vertex_r_e1");
    TH1D* c_h_vertex_r_e2 = (TH1D*)f->Get("h_vertex_r_e2");
    TH1D* c_h_vertex_r_e3 = (TH1D*)f->Get("h_vertex_r_e3");
    TH1D* c_h_vertex_z_e1 = (TH1D*)f->Get("h_vertex_z_e1");
    TH1D* c_h_vertex_z_e2 = (TH1D*)f->Get("h_vertex_z_e2");
    TH1D* c_h_vertex_z_e3 = (TH1D*)f->Get("h_vertex_z_e3");

    cout << "********************* Start plotting *********************" << endl;
    make_canvas(outputname,c_h_vertex_r_e1,";Vertex r[mm]; Efficiency at least 1 reco particle;",0,false,0);
    make_canvas(outputname,c_h_vertex_r_e2,";Vertex r[mm]; Efficiency delta R < 0.001;",1,false,0);
    make_canvas(outputname,c_h_vertex_r_e3,";Vertex r[mm]; Efficiency delta R < 0.0001;",1,false,0);
    make_canvas(outputname,c_h_vertex_z_e1,";Vertex z[mm]; Efficiency at least 1 reco particle;",1,false,0);
    make_canvas(outputname,c_h_vertex_z_e2,";Vertex z[mm]; Efficiency delta R < 0.001;",1,false,0);
    make_canvas(outputname,c_h_vertex_z_e3,";Vertex z[mm]; Efficiency delta R < 0.0001;",2,false,0);

}

void make_canvas(string outputname, TH1D* h1, string title, int pos, bool logy, double max){
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
