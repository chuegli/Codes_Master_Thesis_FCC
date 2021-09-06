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

    TH1D* c_h_eta                 = (TH1D*)f->Get("h_eta");
    TH1D* c_h_phi                 = (TH1D*)f->Get("h_phi");
    TH1D* c_h_pt                  = (TH1D*)f->Get("h_pt");
    TH1D* c_h_eta_e               = (TH1D*)f->Get("h_eta_e");
    TH1D* c_h_phi_e               = (TH1D*)f->Get("h_phi_e");
    TH1D* c_h_pt_e                = (TH1D*)f->Get("h_pt_e");
    TH2D* c_h2_MCeta_vs_Peta      = (TH2D*)f->Get("h2_MCeta_vs_Peta");
    TH2D* c_h2_MCphi_vs_Pphi      = (TH2D*)f->Get("h2_MCphi_vs_Pphi");
    TH2D* c_h2_MCrho_vs_Prho      = (TH2D*)f->Get("h2_MCrho_vs_Prho");
    TH2D* c_h2_MCtheta_vs_Ptheta  = (TH2D*)f->Get("h2_MCtheta_vs_Ptheta");
    TH2D* c_h2_MCtheta_vs_Ttheta  = (TH2D*)f->Get("h2_MCtheta_vs_Ttheta");
    TH2D* c_h2_MCphi_vs_Tphi      = (TH2D*)f->Get("h2_MCphi_vs_Tphi");
    TH1D* c_h_particles_per_event = (TH1D*)f->Get("h_particles_per_event");
    TH2D* c_h2_deltaR_vs_eta      = (TH2D*)f->Get("h2_deltaR_vs_eta");
    TH2D* c_h2_deltaR_vs_phi      = (TH2D*)f->Get("h2_deltaR_vs_phi");
    TH1D* c_a_h_deltaR            = (TH1D*)f->Get("a_h_deltaR");
    TH1D* c_a_h_eta               = (TH1D*)f->Get("a_h_eta");
    TH1D* c_a_h_theta             = (TH1D*)f->Get("a_h_theta");
    TH1D* c_a_h_phi               = (TH1D*)f->Get("a_h_phi");
    TH1D* c_a_h_pt                = (TH1D*)f->Get("a_h_pt");
    TH1D* c_a_h_betagammasintheta = (TH1D*)f->Get("a_h_betagammasintheta");
    TH1D* c_a_h_rho               = (TH1D*)f->Get("a_h_rho");
    TH1D* c_a_h_E                 = (TH1D*)f->Get("a_h_E");
    TH1D* c_a_h_px                = (TH1D*)f->Get("a_h_px");
    TH1D* c_a_h_py                = (TH1D*)f->Get("a_h_py");
    TH1D* c_a_h_pz                = (TH1D*)f->Get("a_h_pz");
    TH1D* c_b_h_deltaR            = (TH1D*)f->Get("b_h_deltaR");
    TH1D* c_b_h_eta               = (TH1D*)f->Get("b_h_eta");
    TH1D* c_b_h_theta             = (TH1D*)f->Get("b_h_theta");
    TH1D* c_b_h_phi               = (TH1D*)f->Get("b_h_phi");
    TH1D* c_b_h_pt                = (TH1D*)f->Get("b_h_pt");
    TH1D* c_b_h_betagammasintheta = (TH1D*)f->Get("b_h_betagammasintheta");
    TH1D* c_b_h_rho               = (TH1D*)f->Get("b_h_rho");
    TH1D* c_b_h_E                 = (TH1D*)f->Get("b_h_E");
    TH1D* c_b_h_px                = (TH1D*)f->Get("b_h_px");
    TH1D* c_b_h_py                = (TH1D*)f->Get("b_h_py");
    TH1D* c_b_h_pz                = (TH1D*)f->Get("b_h_pz");
    TH1D* c_h_nhits               = (TH1D*)f->Get("h_nhits");
    TH1D* c_h_ntracks             = (TH1D*)f->Get("h_ntracks");
    TH1D* c_h_chi2                = (TH1D*)f->Get("h_chi2");
    TH1D* c_h_Tphi                = (TH1D*)f->Get("h_Tphi");
    TH1D* c_h_Ttheta              = (TH1D*)f->Get("h_Ttheta");
    TH1D* c_h_qOverP              = (TH1D*)f->Get("h_qOverP");
    TH1D* c_h_d0                  = (TH1D*)f->Get("h_d0");
    TH1D* c_h_z0                  = (TH1D*)f->Get("h_z0");
    TH1D* c_h_Delta_q_pt          = (TH1D*)f->Get("h_Delta_q_pt");
    TH1D* c_h_Delta_phi           = (TH1D*)f->Get("h_Delta_phi");
    TH1D* c_h_Delta_theta         = (TH1D*)f->Get("h_Delta_theta");
    TH1D* c_h_Delta_eta           = (TH1D*)f->Get("h_Delta_eta");
    TH1D* c_h_Tpt                 = (TH1D*)f->Get("h_Tpt");
    TH1D* c_h_px                  = (TH1D*)f->Get("h_px");
    TH1D* c_h_py                  = (TH1D*)f->Get("h_py");
    TH1D* c_h_pz                  = (TH1D*)f->Get("h_pz");
    TH1D* c_h_betagammasintheta   = (TH1D*)f->Get("h_betagammasintheta");
    TH1D* c_h_E                   = (TH1D*)f->Get("h_E");

    TH1D* c_h_radius = (TH1D*)f->Get("h_radius");
    TH2D* c_h2_z_vs_radius = (TH2D*)f->Get("h2_z_vs_radius");

    TH2D* c_h2_MCeta_vs_Ppt   = (TH2D*)f->Get("h2_MCeta_vs_Ppt");
    TH2D* c_h2_MCphi_vs_Ppt   = (TH2D*)f->Get("h2_MCphi_vs_Ppt");
    TH2D* c_h2_MCrho_vs_Ppt   = (TH2D*)f->Get("h2_MCrho_vs_Ppt");
    TH2D* c_h2_MCtheta_vs_Ppt = (TH2D*)f->Get("h2_MCtheta_vs_Ppt");
    TH2D* c_h2_Delta_R_vs_Ppt = (TH2D*)f->Get("h2_Delta_R_vs_Ppt");
    TH2D* c_h2_nhits_vs_Ppt   = (TH2D*)f->Get("h2_nhits_vs_Ppt");

    TH1D* c_h_dE_dx           = (TH1D*)f->Get("h_dE_dx");

    TH2D* c_h2_MCBeta_vs_hitBeta   = (TH2D*)f->Get("h2_MCBeta_vs_hitBeta");
    TH2D* c_h2_recoBeta_vs_hitBeta = (TH2D*)f->Get("h2_recoBeta_vs_hitBeta");

    TH1D* c_h_Delta_beta = (TH1D*)f->Get("h_Delta_beta");

    TH2D* c_h2_DeltaR_vs_hitBeta = (TH2D*)f->Get("h2_DeltaR_vs_hitBeta");

    TH1D* c_h_hit_time   = (TH1D*)f->Get("h_hit_time");
    TH1D* c_h_hit_energy = (TH1D*)f->Get("h_hit_energy");

    TH1D* c_h_theoretical_beta = (TH1D*)f->Get("h_theoretical_beta");

    TH2D* c_h2_MCpt_vs_Ppt = (TH2D*)f->Get("h2_MCpt_vs_Ppt");



    ///// Normalization for comparison:
    c_b_h_deltaR           ->Scale(1./c_b_h_deltaR->Integral());
    c_b_h_eta              ->Scale(1./c_b_h_eta->Integral());
    c_b_h_theta            ->Scale(1./c_b_h_theta->Integral());
    c_b_h_phi              ->Scale(1./c_b_h_phi->Integral());
    c_b_h_pt               ->Scale(1./c_b_h_pt->Integral());
    c_b_h_betagammasintheta->Scale(1./c_b_h_betagammasintheta->Integral());
    c_b_h_rho              ->Scale(1./c_b_h_rho->Integral());
    c_b_h_E                ->Scale(1./c_b_h_E->Integral());
    c_b_h_px               ->Scale(1./c_b_h_px->Integral());
    c_b_h_py               ->Scale(1./c_b_h_py->Integral());
    c_b_h_pz               ->Scale(1./c_b_h_pz->Integral());

    c_a_h_deltaR           ->Scale(1./c_a_h_deltaR->Integral());
    c_a_h_eta              ->Scale(1./c_a_h_eta->Integral());
    c_a_h_theta            ->Scale(1./c_a_h_theta->Integral());
    c_a_h_phi              ->Scale(1./c_a_h_phi->Integral());
    c_a_h_pt               ->Scale(1./c_a_h_pt->Integral());
    c_a_h_betagammasintheta->Scale(1./c_a_h_betagammasintheta->Integral());
    c_a_h_rho              ->Scale(1./c_a_h_rho->Integral());
    c_a_h_E                ->Scale(1./c_a_h_E->Integral());
    c_a_h_px               ->Scale(1./c_a_h_px->Integral());
    c_a_h_py               ->Scale(1./c_a_h_py->Integral());
    c_a_h_pz               ->Scale(1./c_a_h_pz->Integral());

    c_h_px               ->Scale(1./c_h_px->Integral());
    c_h_py               ->Scale(1./c_h_py->Integral());
    c_h_pz               ->Scale(1./c_h_pz->Integral());
    c_h_betagammasintheta->Scale(1./c_h_betagammasintheta->Integral());
    c_h_E                ->Scale(1./c_h_E->Integral());
    c_h_pt->Scale(1./c_h_pt->Integral());
    c_h_phi->Scale(1./c_h_phi->Integral());
    c_h_eta->Scale(1./c_h_eta->Integral());

    c_h_Tpt->Scale(1./c_h_Tpt->Integral());

    cout << "********************* Start plotting *********************" << endl;
    /////////////////////////////////////////////////////////////////////////////////////
    ///////////////////// 1D plots:
    make_canvas(outputname,c_h_eta_e, c_h_eta_e, false, "; MC eta; Track reconstruction efficiency", true,0,false,0);
    make_canvas(outputname,c_h_phi_e, c_h_phi_e, false, "; MC phi; Track reconstruction efficiency",false,1,false,0);
    // make_canvas(c_h_pt_e, c_h_pt_e, false, "; MC pt; Track reconstruction efficiency");
    //// Comparisons:
    make_canvas(outputname,c_h_eta, c_b_h_eta, true, "; eta; Entires normalized", true,1,false,0.035);
    make_canvas(outputname,c_h_phi, c_b_h_phi, true, "; phi; Entires normalized", true,1,false,0.03);
    make_canvas(outputname,c_h_pt, c_b_h_pt, true, "; pt [GeV]; Entires normalized", true,1,false,0.1);
    make_canvas(outputname,c_h_px, c_b_h_px, true, "; px [GeV]; Entires normalized", true,1,false,0.4);
    make_canvas(outputname,c_h_py, c_b_h_py, true, "; py [GeV]; Entires normalized", true,1,false,0.4);
    make_canvas(outputname,c_h_pz, c_b_h_pz, true, "; pz [GeV]; Entires normalized", true,1,false,0.4);
    make_canvas(outputname,c_h_betagammasintheta, c_b_h_betagammasintheta, true, "; beta*gamma*sin(theta); Entires normalized", true,1,false,1.1);
    make_canvas(outputname,c_h_E, c_b_h_E, true, "; Energy [GeV]; Entires normalized", true,1,false,1.2);
    //// Comparisons best vs all:
    make_canvas(outputname,c_a_h_deltaR, c_b_h_deltaR, true, "; Delta R; Entires normalized",false, 1,true,1.1);
    make_canvas(outputname,c_a_h_eta, c_b_h_eta, true, "; eta; Entires normalized",false,1,false,0.04);
    make_canvas(outputname,c_a_h_theta, c_b_h_theta, true, "; theta; Entires normalized", false,1,false,0.07);
    make_canvas(outputname,c_a_h_phi, c_b_h_phi, true, "; phi; Entires normalized",false,1,false,0.028);
    make_canvas(outputname,c_a_h_pt, c_b_h_pt, true, "; pt [GeV]; Entires normalized",false,1,false,0.25);
    make_canvas(outputname,c_a_h_rho, c_b_h_rho, true, "; rho; Entires normalized", false,1,false,0.2);
    ///// Other reco particles:
    make_canvas(outputname,c_h_particles_per_event, c_h_particles_per_event, false, "; Reconstructed particles per event; Entires ",false, 1,true,0);
    ////// Tracks:
    make_canvas(outputname,c_h_Ttheta, c_h_Ttheta, false, ";Track theta; Entires ",false,1,false,0);
    make_canvas(outputname,c_h_Tphi, c_h_Tphi, false, ";Track phi; Entires ",false,1,false,0);
    make_canvas(outputname,c_h_chi2, c_h_chi2, false, ";Track chi2; Entires ", false, 1,true,0);
    make_canvas(outputname,c_h_qOverP, c_h_qOverP, false, ";Track qOverP; Entires ",false,1,false,0);
    make_canvas(outputname,c_h_d0, c_h_d0, false, ";Track d0 [mm]; Entires ",false,1,false,0);
    make_canvas(outputname,c_h_z0, c_h_z0, false, ";Track z0 [mm]; Entires ",false,1,false,0);
    make_canvas(outputname,c_h_ntracks, c_h_ntracks, false, ";Number of tracks per Reco particle; Entires ", false, 1, true,0);
    make_canvas(outputname,c_h_nhits, c_h_nhits, false, ";Number of hits per event; Entires ", false, 1, true,0);

    make_canvas(outputname,c_h_Delta_q_pt ,c_h_z0, false, ";Delta qOverPt; Entries",false,1,false,0);
    make_canvas(outputname,c_h_Delta_phi  ,c_h_z0, false, ";Delta phi; Entries",false,1,true,0);
    make_canvas(outputname,c_h_Delta_theta,c_h_z0, false, ";Delta theta; Entries",false,1,true,0);
    make_canvas(outputname,c_h_Delta_eta  ,c_h_z0, false, ";Delta eta; Entries",false,1,true,0);

    make_canvas(outputname,c_h_radius  ,c_h_z0, false, "; Decay radius [mm]; Entries",false,1,true,0);

    make_canvas(outputname,c_h_pt,c_h_Tpt,true, "; pt [GeV]; Entries",true,1,false,1.2);
    make_canvas(outputname,c_h_dE_dx,c_h_dE_dx,false,";dE/dx; Entries",false,1,false,0);
    make_canvas(outputname,c_h_Delta_beta,c_h_Delta_beta,false,";Best Delta beta (hits); Entries",false,1,false,0);

    make_canvas(outputname,c_h_hit_time  ,c_h_hit_time,false,"; Hit time [ns]; Entries",false,1,false,0);
    make_canvas(outputname,c_h_hit_energy,c_h_hit_time,false,"; Hit energy [GeV]; Entries",false,1,false,0);

    make_canvas(outputname,c_h_theoretical_beta,c_h_hit_time,false,"; Theoretical Delta beta; Entries",false,1,false,0);

    make_canvas(outputname,c_h_pz,c_h_hit_time,false,"; MC pz [GeV]; Entries",false,2,false,0);

    /////////////////////////////////////////////////////////////////////////////////////
    ///////////////////// 2D plots:
    //// Checks:
    make_canvas(outputname,c_h2_MCeta_vs_Peta, "; MC eta; Best particle eta", 0,false);
    make_canvas(outputname,c_h2_MCphi_vs_Pphi, "; MC phi; Best particle phi",1,false);
    make_canvas(outputname,c_h2_MCrho_vs_Prho, "; MC rho; Best particle rho",1,false);
    make_canvas(outputname,c_h2_MCtheta_vs_Ptheta, "; MC theta; Best particle theta",1,false);
    make_canvas(outputname,c_h2_MCtheta_vs_Ttheta, "; MC theta; Track theta",1,false);
    make_canvas(outputname,c_h2_MCphi_vs_Tphi, "; MC phi; Track phi",1,false);
    ///// Other reco particles:
    make_canvas(outputname,c_h2_deltaR_vs_eta, "; MC eta; Best Delta R",1,false);
    make_canvas(outputname,c_h2_deltaR_vs_phi, "; MC phi; Best Delta R",1,false);
    make_canvas(outputname,c_h2_z_vs_radius, "; z; Radius",1,false);

    make_canvas(outputname,c_h2_MCeta_vs_Ppt  ,"; MC eta; Best particle pt",1,true);
    make_canvas(outputname,c_h2_MCphi_vs_Ppt  ,"; MC phi; Best particle pt",1,true);
    make_canvas(outputname,c_h2_MCrho_vs_Ppt  ,"; MC rho; Best particle pt",1,true);
    make_canvas(outputname,c_h2_MCtheta_vs_Ppt,"; MC theta; Best particle pt",1,true);
    make_canvas(outputname,c_h2_Delta_R_vs_Ppt,"; Delta R ; Best particle pt",1,true);
    make_canvas(outputname,c_h2_nhits_vs_Ppt  ,"; Number of hits; Best particle pt",1,true);

    make_canvas(outputname,c_h2_recoBeta_vs_hitBeta,"; Best reco beta; best reco hit beta",1,false);
    make_canvas(outputname,c_h2_MCBeta_vs_hitBeta  ,"; MC beta; best reco hit beta",1,false);

    make_canvas(outputname,c_h2_DeltaR_vs_hitBeta,";Delta R; best reco hit beta",1,false);

    make_canvas(outputname,c_h2_MCpt_vs_Ppt,";MC pt; Best reco pt",2,false);

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
