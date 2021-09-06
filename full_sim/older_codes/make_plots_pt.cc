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
void make_canvas(string outputname,TH2D* h2, string title, int pos, bool logy);
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

    TH1D* c_h_pt         = (TH1D*)f->Get("h_pt");
    TH1D* c_h_px         = (TH1D*)f->Get("h_px");
    TH1D* c_h_py         = (TH1D*)f->Get("h_py");
    TH1D* c_h_pz         = (TH1D*)f->Get("h_pz");
    TH1D* c_a_h_pt       = (TH1D*)f->Get("a_h_pt");
    TH1D* c_a_h_px       = (TH1D*)f->Get("a_h_px");
    TH1D* c_a_h_py       = (TH1D*)f->Get("a_h_py");
    TH1D* c_a_h_pz       = (TH1D*)f->Get("a_h_pz");
    TH1D* c_b_h_pt       = (TH1D*)f->Get("b_h_pt");
    TH1D* c_b_h_px       = (TH1D*)f->Get("b_h_px");
    TH1D* c_b_h_py       = (TH1D*)f->Get("b_h_py");
    TH1D* c_b_h_pz       = (TH1D*)f->Get("b_h_pz");
    TH1D* c_h_qOverP     = (TH1D*)f->Get("h_qOverP");
    TH1D* c_h_Tpt        = (TH1D*)f->Get("h_Tpt");
    TH1D* c_h_Delta_q_pt = (TH1D*)f->Get("h_Delta_q_pt");
    TH1D* c_h_Tpt_2      = (TH1D*)f->Get("h_Tpt_2");
    TH1D* c_h_qOverP_2   = (TH1D*)f->Get("h_qOverP_2");
    TH1D* c_h_teo_pt     = (TH1D*)f->Get("h_teo_pt");

    TH2D* c_h2_MCpt_vs_Ppt    = (TH2D*)f->Get("h2_MCpt_vs_Ppt"   );
    TH2D* c_h2_MCeta_vs_Ppt   = (TH2D*)f->Get("h2_MCeta_vs_Ppt"  );
    TH2D* c_h2_MCphi_vs_Ppt   = (TH2D*)f->Get("h2_MCphi_vs_Ppt"  );
    TH2D* c_h2_MCrho_vs_Ppt   = (TH2D*)f->Get("h2_MCrho_vs_Ppt"  );
    TH2D* c_h2_MCtheta_vs_Ppt = (TH2D*)f->Get("h2_MCtheta_vs_Ppt");
    TH2D* c_h2_Delta_R_vs_Ppt = (TH2D*)f->Get("h2_Delta_R_vs_Ppt");
    TH2D* c_h2_MCpx_vs_Ppx    = (TH2D*)f->Get("h2_MCpx_vs_Ppx");
    TH2D* c_h2_MCpy_vs_Ppy    = (TH2D*)f->Get("h2_MCpy_vs_Ppy");
    TH2D* c_h2_MCpz_vs_Ppz    = (TH2D*)f->Get("h2_MCpz_vs_Ppz");
    TH2D* c_h2_MCp_vs_Pp      = (TH2D*)f->Get("h2_MCp_vs_Pp");


    ///// Normalization for comparison:
    c_h_pt  ->Scale(1./c_h_pt->Integral());
    c_h_px  ->Scale(1./c_h_px->Integral());
    c_h_py  ->Scale(1./c_h_py->Integral());
    c_h_pz  ->Scale(1./c_h_pz->Integral());
    c_a_h_pt->Scale(1./c_a_h_pt->Integral());
    c_a_h_px->Scale(1./c_a_h_px->Integral());
    c_a_h_py->Scale(1./c_a_h_py->Integral());
    c_a_h_pz->Scale(1./c_a_h_pz->Integral());
    c_b_h_pt->Scale(1./c_b_h_pt->Integral());
    c_b_h_px->Scale(1./c_b_h_px->Integral());
    c_b_h_py->Scale(1./c_b_h_py->Integral());
    c_b_h_pz->Scale(1./c_b_h_pz->Integral());
    c_h_Tpt->Scale(1./c_h_Tpt->Integral());
    c_h_Tpt_2->Scale(1./c_h_Tpt_2->Integral());


    cout << "********************* Start plotting *********************" << endl;
    ///////////////////// 1D plots:
    make_canvas(outputname,c_h_pt, c_b_h_pt, true, "; pt [GeV]; Entires normalized", true,0,false,1.3);
    make_canvas(outputname,c_h_px, c_b_h_px, true, "; px [GeV]; Entires normalized", true,1,false,0.1);
    make_canvas(outputname,c_h_py, c_b_h_py, true, "; py [GeV]; Entires normalized", true,1,false,0.1);
    make_canvas(outputname,c_h_pz, c_b_h_pz, true, "; pz [GeV]; Entires normalized", true,1,false,0.06);
    make_canvas(outputname,c_a_h_pt, c_b_h_pt, true, "; pt [GeV]; Entires normalized",false,1,false,0.25);
    make_canvas(outputname,c_h_qOverP, c_h_qOverP, false, ";Track qOverP; Entires ",false,1,false,0);
    make_canvas(outputname,c_h_pt,c_h_Tpt,true, "; pt [GeV]; Entries",true,1,false,1.2);
    make_canvas(outputname,c_h_teo_pt,c_h_teo_pt,false, "; teo tripplet res pt [GeV]; Entries",true,2,false,1.2);

    ///////////////////// 2D plots:
    make_canvas(outputname,c_h2_MCeta_vs_Ppt  ,"; MC eta; Best particle pt",0,true);
    make_canvas(outputname,c_h2_MCphi_vs_Ppt  ,"; MC phi; Best particle pt",1,true);
    make_canvas(outputname,c_h2_MCrho_vs_Ppt  ,"; MC rho; Best particle pt",1,true);
    make_canvas(outputname,c_h2_MCtheta_vs_Ppt,"; MC theta; Best particle pt",1,true);
    make_canvas(outputname,c_h2_Delta_R_vs_Ppt,"; Delta R ; Best particle pt",1,true);
    make_canvas(outputname,c_h2_MCpt_vs_Ppt,";MC pt; Best reco pt",1,false);
    make_canvas(outputname,c_h2_MCpx_vs_Ppx,";MC px; Best reco px",1,false);
    make_canvas(outputname,c_h2_MCpy_vs_Ppy,";MC py; Best reco py",1,false);
    make_canvas(outputname,c_h2_MCpz_vs_Ppz,";MC pz; Best reco pz",1,false);
    make_canvas(outputname,c_h2_MCp_vs_Pp,";MC p; Best reco p",2,false);

}

void make_canvas(string outputname,TH1D* h1, TH1D* h2, bool two, string title, bool MC, int pos, bool logy, double max){
  TCanvas *canvas = new TCanvas("canvas","");
  canvas->SetGrid();

  if(logy){canvas->SetLogy();}

  gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  string ss1 = outputname+".pdf[";
  string ss2 = outputname+".pdf";
  string ss3 = outputname+".pdf]";
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
      if(MC){legend->AddEntry(h1,"MC Particles","l");}
      else{legend->AddEntry(h1,"All Reco Particles","l");}
      legend->AddEntry(h2,"Best Reco Particles","l");
      legend->Draw();
    }else{
      h1->Draw("hist h");
      if(max!=0){h1->SetMaximum(max);}
      h1->SetNdivisions(5);
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
