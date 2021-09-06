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

void make_canvas(string outputname, TH1D* h1, TH1D* h2, bool two, string title, bool MC, int pos, bool logy, double max);
void make_canvas(string outputname,TH1D* h1, TH1D* h2, string title,int pos, bool logy, double max);
void make_plots_2(string rootname1, string rootname2, string outputname);

int main(int argc, char **argv){
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }
    string filename1 = argv[1];
    string filename2 = argv[2];
    string outputname= argv[3];
    make_plots_2(filename1, filename2, outputname);

    return 0;
}

void make_plots_2(string rootname1, string rootname2, string outputname){
    cout << "************* Read histograms **********************" << endl;
    TFile *f1 = new TFile(rootname1.c_str());
    TFile *f2 = new TFile(rootname2.c_str());

    TH1D* c1_h_track_pt     = (TH1D*)f1->Get("h_track_pt"    );
    TH1D* c1_h_hit_beta     = (TH1D*)f1->Get("h_hit_beta"    );
    TH1D* c1_h_track_z0     = (TH1D*)f1->Get("h_track_z0"    );
    TH1D* c1_h_track_d0     = (TH1D*)f1->Get("h_track_d0"    );
    TH1D* c1_h_track_phi    = (TH1D*)f1->Get("h_track_phi"   );
    TH1D* c1_h_track_theta  = (TH1D*)f1->Get("h_track_theta" );
    TH1D* c1_h_track_eta    = (TH1D*)f1->Get("h_track_eta"   );
    TH1D* c1_h_track_qOverP = (TH1D*)f1->Get("h_track_qOverP");
    TH1D* c1_h_ntrack       = (TH1D*)f1->Get("h_ntrack"      );

    TH1D* c2_h_track_pt     = (TH1D*)f2->Get("h_track_pt"    );
    TH1D* c2_h_hit_beta     = (TH1D*)f2->Get("h_hit_beta"    );
    TH1D* c2_h_track_z0     = (TH1D*)f2->Get("h_track_z0"    );
    TH1D* c2_h_track_d0     = (TH1D*)f2->Get("h_track_d0"    );
    TH1D* c2_h_track_phi    = (TH1D*)f2->Get("h_track_phi"   );
    TH1D* c2_h_track_theta  = (TH1D*)f2->Get("h_track_theta" );
    TH1D* c2_h_track_eta    = (TH1D*)f2->Get("h_track_eta"   );
    TH1D* c2_h_track_qOverP = (TH1D*)f2->Get("h_track_qOverP");
    TH1D* c2_h_ntrack       = (TH1D*)f2->Get("h_ntrack"      );

    c1_h_track_pt    ->Scale(1./c1_h_track_pt    ->Integral());
    c1_h_hit_beta    ->Scale(1./c1_h_hit_beta    ->Integral());
    c1_h_track_z0    ->Scale(1./c1_h_track_z0    ->Integral());
    c1_h_track_d0    ->Scale(1./c1_h_track_d0    ->Integral());
    c1_h_track_phi   ->Scale(1./c1_h_track_phi   ->Integral());
    c1_h_track_theta ->Scale(1./c1_h_track_theta ->Integral());
    c1_h_track_eta   ->Scale(1./c1_h_track_eta   ->Integral());
    c1_h_track_qOverP->Scale(1./c1_h_track_qOverP->Integral());
    c1_h_ntrack      ->Scale(1./c1_h_ntrack      ->Integral());
    c2_h_track_pt    ->Scale(1./c2_h_track_pt    ->Integral());
    c2_h_hit_beta    ->Scale(1./c2_h_hit_beta    ->Integral());
    c2_h_track_z0    ->Scale(1./c2_h_track_z0    ->Integral());
    c2_h_track_d0    ->Scale(1./c2_h_track_d0    ->Integral());
    c2_h_track_phi   ->Scale(1./c2_h_track_phi   ->Integral());
    c2_h_track_theta ->Scale(1./c2_h_track_theta ->Integral());
    c2_h_track_eta   ->Scale(1./c2_h_track_eta   ->Integral());
    c2_h_track_qOverP->Scale(1./c2_h_track_qOverP->Integral());
    c2_h_ntrack      ->Scale(1./c2_h_ntrack      ->Integral());


    cout << "********************* Start plotting *********************" << endl;
    ///////////////////// 1D plots:
    make_canvas(outputname,c1_h_track_pt    ,c2_h_track_pt    , "; Track reco pt [GeV] ; Normalized entries",0,false,1.1);
    make_canvas(outputname,c1_h_hit_beta    ,c2_h_hit_beta    , "; Hit beta [ ]        ; Normalized entries",1,false,0.15);
    make_canvas(outputname,c1_h_track_z0    ,c2_h_track_z0    , "; Track z0 [mm]       ; Normalized entries",1,false,0.5);
    make_canvas(outputname,c1_h_track_d0    ,c2_h_track_d0    , "; Track d0 [mm]       ; Normalized entries",1,false,0.5);
    make_canvas(outputname,c1_h_track_phi   ,c2_h_track_phi   , "; Track phi [ ]       ; Normalized entries",1,false,0.05);
    make_canvas(outputname,c1_h_track_theta ,c2_h_track_theta , "; Track theta [ ]     ; Normalized entries",1,false,0.5);
    make_canvas(outputname,c1_h_track_eta   ,c2_h_track_eta   , "; Track eta [ ]       ; Normalized entries",1,false,0.15);
    make_canvas(outputname,c1_h_track_qOverP,c2_h_track_qOverP, "; Track qOverP [1/GeV]; Normalized entries",1,false,0.5);
    make_canvas(outputname,c1_h_ntrack      ,c2_h_ntrack      , "; Number of tracks per event [ ]; Normalized entries",2,false,1.1);

}

void make_canvas(string outputname,TH1D* h1, TH1D* h2, string title,int pos, bool logy, double max){
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
  h2->SetLineColor(2);
  h2->Draw("hist h same");
  h1->SetTitle(title.c_str());
  h1->GetYaxis()->SetLabelSize(0.05);
  h1->GetXaxis()->SetLabelSize(0.05);
  h1->GetYaxis()->SetTitleSize(0.05);
  h1->GetXaxis()->SetTitleSize(0.05);
  TLegend* legend = new TLegend(0.58,0.8,0.98,0.98);//x1,y1,x2,y2
  gStyle->SetLegendTextSize(0.04);
  legend->AddEntry(h1,"Chargino","l");
  legend->AddEntry(h2,"Pileups","l");
  legend->Draw();

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

void make_canvas(string outputname,TH2D* h2, string title, int pos, bool logy){
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
  h2->GetYaxis()->SetLabelSize(0.05);
  h2->GetXaxis()->SetLabelSize(0.05);
  h2->GetYaxis()->SetTitleSize(0.05);
  h2->GetXaxis()->SetTitleSize(0.05);
  h2->GetXaxis()->SetNdivisions(5);

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
