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

void make_plots(){
    cout << "************* Read histograms **********************" << endl;
    string rootname = "root_files/wino_1000.root";
    TFile *f = new TFile(rootname.c_str());

    // TH1D* c_h_eta                 = (TH1D*)f->Get("h_eta");
    // TH1D* c_h_phi                 = (TH1D*)f->Get("h_phi");
    // TH1D* c_h_pt                  = (TH1D*)f->Get("h_pt");
    // TH1D* c_h_px                  = (TH1D*)f->Get("h_px");
    // TH1D* c_h_py                  = (TH1D*)f->Get("h_py");
    // TH1D* c_h_pz                  = (TH1D*)f->Get("h_pz");
    // TH1D* c_h_betagammasintheta   = (TH1D*)f->Get("h_betagammasintheta");
    // TH1D* c_h_E                   = (TH1D*)f->Get("h_E");
    // TH1D* c_h_eta_e               = (TH1D*)f->Get("h_eta_e");
    // TH1D* c_h_phi_e               = (TH1D*)f->Get("h_phi_e");
    // TH1D* c_h_pt_e                = (TH1D*)f->Get("h_pt_e");
    // TH2D* c_h2_MCeta_vs_Peta      = (TH2D*)f->Get("h2_MCeta_vs_Peta");
    // TH2D* c_h2_MCphi_vs_Pphi      = (TH2D*)f->Get("h2_MCphi_vs_Pphi");
    // TH2D* c_h2_MCpt_vs_Ppt        = (TH2D*)f->Get("h2_MCpt_vs_Ppt");
    // TH2D* c_h2_MCrho_vs_Prho      = (TH2D*)f->Get("h2_MCrho_vs_Prho");
    // TH2D* c_h2_MCtheta_vs_Ptheta  = (TH2D*)f->Get("h2_MCtheta_vs_Ptheta");
    // TH2D* c_h2_MCtheta_vs_Ttheta  = (TH2D*)f->Get("h2_MCtheta_vs_Ttheta");
    // TH2D* c_h2_MCphi_vs_Tphi      = (TH2D*)f->Get("h2_MCphi_vs_Tphi");
    // TH1D* c_h_particles_per_event = (TH1D*)f->Get("h_particles_per_event");
    // TH2D* c_h2_deltaR_vs_eta      = (TH2D*)f->Get("h2_deltaR_vs_eta");
    // TH2D* c_h2_deltaR_vs_pt       = (TH2D*)f->Get("h2_deltaR_vs_pt");
    // TH2D* c_h2_deltaR_vs_phi      = (TH2D*)f->Get("h2_deltaR_vs_phi");
    // TH1D* c_a_h_deltaR            = (TH1D*)f->Get("a_h_deltaR");
    // TH1D* c_a_h_eta               = (TH1D*)f->Get("a_h_eta");
    // TH1D* c_a_h_theta             = (TH1D*)f->Get("a_h_theta");
    // TH1D* c_a_h_phi               = (TH1D*)f->Get("a_h_phi");
    // TH1D* c_a_h_pt                = (TH1D*)f->Get("a_h_pt");
    // TH1D* c_a_h_betagammasintheta = (TH1D*)f->Get("a_h_betagammasintheta");
    // TH1D* c_a_h_rho               = (TH1D*)f->Get("a_h_rho");
    // TH1D* c_a_h_E                 = (TH1D*)f->Get("a_h_E");
    // TH1D* c_a_h_px                = (TH1D*)f->Get("a_h_px");
    // TH1D* c_a_h_py                = (TH1D*)f->Get("a_h_py");
    // TH1D* c_a_h_pz                = (TH1D*)f->Get("a_h_pz");
    // TH1D* c_b_h_deltaR            = (TH1D*)f->Get("b_h_deltaR");
    // TH1D* c_b_h_eta               = (TH1D*)f->Get("b_h_eta");
    // TH1D* c_b_h_theta             = (TH1D*)f->Get("b_h_theta");
    // TH1D* c_b_h_phi               = (TH1D*)f->Get("b_h_phi");
    // TH1D* c_b_h_pt                = (TH1D*)f->Get("b_h_pt");
    // TH1D* c_b_h_betagammasintheta = (TH1D*)f->Get("b_h_betagammasintheta");
    // TH1D* c_b_h_rho               = (TH1D*)f->Get("b_h_rho");
    // TH1D* c_b_h_E                 = (TH1D*)f->Get("b_h_E");
    // TH1D* c_b_h_px                = (TH1D*)f->Get("b_h_px");
    // TH1D* c_b_h_py                = (TH1D*)f->Get("b_h_py");
    // TH1D* c_b_h_pz                = (TH1D*)f->Get("b_h_pz");
    // TH1D* c_h_nhits               = (TH1D*)f->Get("h_nhits");
    // TH1D* c_h_ntracks             = (TH1D*)f->Get("h_ntracks");
    // TH1D* c_h_chi2                = (TH1D*)f->Get("h_chi2");
    // TH1D* c_h_Tphi                = (TH1D*)f->Get("h_Tphi");
    // TH1D* c_h_Ttheta              = (TH1D*)f->Get("h_Ttheta");
    // TH1D* c_h_qOverP              = (TH1D*)f->Get("h_qOverP");
    // TH1D* c_h_d0                  = (TH1D*)f->Get("h_d0");
    // TH1D* c_h_z0                  = (TH1D*)f->Get("h_z0");
    // TH2D* c_h2_MCpt_vs_Tpt        = (TH2D*)f->Get("h2_MCpt_vs_Tpt");
    // TH1D* c_h_Delta_q_pt          = (TH1D*)f->Get("h_Delta_q_pt");
    // TH1D* c_h_Delta_phi           = (TH1D*)f->Get("h_Delta_phi");
    // TH1D* c_h_Delta_theta         = (TH1D*)f->Get("h_Delta_theta");
    // TH1D* c_h_Delta_eta           = (TH1D*)f->Get("h_Delta_eta");
    // TH2D* c_h2_Delta_phi_vs_MCpt    = (TH2D*)f->Get("h2_Delta_phi_vs_MCpt");
    // TH2D* c_h2_Delta_theta_vs_MCpt  = (TH2D*)f->Get("h2_Delta_theta_vs_MCpt");
    // TH2D* c_h2_Delta_q_pt_vs_MCpt   = (TH2D*)f->Get("h2_Delta_q_pt_vs_MCpt");
    // TH2D* c_h2_Delta_eta_vs_MCpt    = (TH2D*)f->Get("h2_Delta_eta_vs_MCpt");
    TH1D* c_yes_h_eta               = (TH1D*)f->Get("yes_h_eta");
    TH1D* c_yes_h_phi               = (TH1D*)f->Get("yes_h_phi");
    TH1D* c_yes_h_pt                = (TH1D*)f->Get("yes_h_pt");
    TH1D* c_yes_h_px                = (TH1D*)f->Get("yes_h_px");
    TH1D* c_yes_h_py                = (TH1D*)f->Get("yes_h_py");
    TH1D* c_yes_h_pz                = (TH1D*)f->Get("yes_h_pz");
    TH1D* c_yes_h_betagammasintheta = (TH1D*)f->Get("yes_h_betagammasintheta");
    TH1D* c_yes_h_E                 = (TH1D*)f->Get("yes_h_E");
    TH1D* c_no_h_eta                = (TH1D*)f->Get("no_h_eta");
    TH1D* c_no_h_phi                = (TH1D*)f->Get("no_h_phi");
    TH1D* c_no_h_pt                 = (TH1D*)f->Get("no_h_pt");
    TH1D* c_no_h_px                 = (TH1D*)f->Get("no_h_px");
    TH1D* c_no_h_py                 = (TH1D*)f->Get("no_h_py");
    TH1D* c_no_h_pz                 = (TH1D*)f->Get("no_h_pz");
    TH1D* c_no_h_betagammasintheta  = (TH1D*)f->Get("no_h_betagammasintheta");
    TH1D* c_no_h_E                  = (TH1D*)f->Get("no_h_E");
    TH1D* c_no_h_hit_energy           = (TH1D*)f->Get("no_h_hit_energy");
    TH1D* c_no_h_hit_time             = (TH1D*)f->Get("no_h_hit_time");
    TH1D* c_yes_h_hit_energy          = (TH1D*)f->Get("yes_h_hit_energy");
    TH1D* c_yes_h_hit_time            = (TH1D*)f->Get("yes_h_hit_time");
    // TH1D* c_h_vertex_r_e            = (TH1D*)f->Get("h_vertex_r_e");
    // TH1D* c_h_vertex_z_e            = (TH1D*)f->Get("h_vertex_z_e");
    TH2D* c_h2_Delta_R_vs_hit_time   =(TH2D*)f->Get("h2_Delta_R_vs_hit_time");
    TH2D* c_h2_Delta_R_vs_hit_energy =(TH2D*)f->Get("h2_Delta_R_vs_hit_energy");

    ///// Normalization for comparison:
    // c_b_h_deltaR           ->Scale(1./c_b_h_deltaR->Integral());
    // c_b_h_eta              ->Scale(1./c_b_h_eta->Integral());
    // c_b_h_theta            ->Scale(1./c_b_h_theta->Integral());
    // c_b_h_phi              ->Scale(1./c_b_h_phi->Integral());
    // c_b_h_pt               ->Scale(1./c_b_h_pt->Integral());
    // c_b_h_betagammasintheta->Scale(1./c_b_h_betagammasintheta->Integral());
    // c_b_h_rho              ->Scale(1./c_b_h_rho->Integral());
    // c_b_h_E                ->Scale(1./c_b_h_E->Integral());
    // c_b_h_px               ->Scale(1./c_b_h_px->Integral());
    // c_b_h_py               ->Scale(1./c_b_h_py->Integral());
    // c_b_h_pz               ->Scale(1./c_b_h_pz->Integral());
    //
    // c_a_h_deltaR           ->Scale(1./c_a_h_deltaR->Integral());
    // c_a_h_eta              ->Scale(1./c_a_h_eta->Integral());
    // c_a_h_theta            ->Scale(1./c_a_h_theta->Integral());
    // c_a_h_phi              ->Scale(1./c_a_h_phi->Integral());
    // c_a_h_pt               ->Scale(1./c_a_h_pt->Integral());
    // c_a_h_betagammasintheta->Scale(1./c_a_h_betagammasintheta->Integral());
    // c_a_h_rho              ->Scale(1./c_a_h_rho->Integral());
    // c_a_h_E                ->Scale(1./c_a_h_E->Integral());
    // c_a_h_px               ->Scale(1./c_a_h_px->Integral());
    // c_a_h_py               ->Scale(1./c_a_h_py->Integral());
    // c_a_h_pz               ->Scale(1./c_a_h_pz->Integral());

    c_yes_h_eta              ->Scale(1./c_yes_h_eta->Integral());
    c_yes_h_phi              ->Scale(1./c_yes_h_phi->Integral());
    c_yes_h_pt               ->Scale(1./c_yes_h_pt->Integral());
    c_yes_h_px               ->Scale(1./c_yes_h_px->Integral());
    c_yes_h_py               ->Scale(1./c_yes_h_py->Integral());
    c_yes_h_pz               ->Scale(1./c_yes_h_pz->Integral());
    c_yes_h_betagammasintheta->Scale(1./c_yes_h_betagammasintheta->Integral());
    c_yes_h_E                ->Scale(1./c_yes_h_E->Integral());
    c_no_h_eta               ->Scale(1./c_no_h_eta->Integral());
    c_no_h_phi               ->Scale(1./c_no_h_phi->Integral());
    c_no_h_pt                ->Scale(1./c_no_h_pt->Integral());
    c_no_h_px                ->Scale(1./c_no_h_px->Integral());
    c_no_h_py                ->Scale(1./c_no_h_py->Integral());
    c_no_h_pz                ->Scale(1./c_no_h_pz->Integral());
    c_no_h_betagammasintheta ->Scale(1./c_no_h_betagammasintheta->Integral());
    c_no_h_E                 ->Scale(1./c_no_h_E->Integral());
    c_no_h_hit_energy        ->Scale(1./c_no_h_hit_energy->Integral());
    c_no_h_hit_time          ->Scale(1./c_no_h_hit_time->Integral());
    c_yes_h_hit_energy       ->Scale(1./c_yes_h_hit_energy->Integral());
    c_yes_h_hit_time         ->Scale(1./c_yes_h_hit_time->Integral());

    cout << "********************* Start plotting *********************" << endl;
    /////////////////////////////////////////////////////////////////////////////////////
    ///////////////////// 1D plots:
    // make_canvas(c_h_eta_e, c_h_eta_e, false, "; MC eta; Track reconstruction efficiency", true,0);
    // make_canvas(c_h_phi_e, c_h_phi_e, false, "; MC phi; Track reconstruction efficiency");
    // make_canvas(c_h_pt_e, c_h_pt_e, false, "; MC pt; Track reconstruction efficiency");
    // //// Comparisons:
    // c_h_eta->Scale(1./c_h_eta->Integral());
    // make_canvas(c_h_eta, c_b_h_eta, true, "; eta; Entires normalized", true,1,false,0.04);
    // c_h_phi->Scale(1./c_h_phi->Integral());
    // make_canvas(c_h_phi, c_b_h_phi, true, "; phi; Entires normalized", true,1,false,0.04);
    // c_h_pt->Scale(1./c_h_pt->Integral());
    // make_canvas(c_h_pt, c_b_h_pt, true, "; pt; Entires normalized", true,1,false,0.04);
    // c_h_px->Scale(1./c_h_px->Integral());
    // make_canvas(c_h_px, c_b_h_px, true, "; px; Entires normalized", true,1,false,0.045);
    // c_h_py->Scale(1./c_h_py->Integral());
    // make_canvas(c_h_py, c_b_h_py, true, "; py; Entires normalized", true);
    // c_h_pz->Scale(1./c_h_pz->Integral());
    // make_canvas(c_h_pz, c_b_h_pz, true, "; pz; Entires normalized", true,1,false,0.08);
    // c_h_betagammasintheta->Scale(1./c_h_betagammasintheta->Integral());
    // make_canvas(c_h_betagammasintheta, c_b_h_betagammasintheta, true, "; beta*gamma*sin(theta); Entires normalized", true,1,false,0.02);
    // c_h_E->Scale(1./c_h_E->Integral());
    // make_canvas(c_h_E, c_b_h_E, true, "; E; Entires normalized", true, 1,true);
    // //// Comparisons best vs all:
    // make_canvas(c_a_h_deltaR, c_b_h_deltaR, true, "; Delta R; Entires normalized",false, 1,true,1);
    // make_canvas(c_a_h_eta, c_b_h_eta, true, "; eta; Entires normalized",false,1,false,0.22);
    // make_canvas(c_a_h_theta, c_b_h_theta, true, "; theta; Entires normalized");
    // make_canvas(c_a_h_phi, c_b_h_phi, true, "; phi; Entires normalized");
    // make_canvas(c_a_h_pt, c_b_h_pt, true, "; pt; Entires normalized");
    // make_canvas(c_a_h_rho, c_b_h_rho, true, "; rho; Entires normalized");
    // ///// Other reco particles:
    // make_canvas(c_h_particles_per_event, c_h_particles_per_event, false, "; Reconstructed particles per event; Entires ",false, 1,true);
    // ////// Tracks:
    // make_canvas(c_h_Ttheta, c_h_Ttheta, false, ";Track theta; Entires ");
    // make_canvas(c_h_Tphi, c_h_Tphi, false, ";Track phi; Entires ");
    // make_canvas(c_h_chi2, c_h_chi2, false, ";Track chi2; Entires ", false, 1,true);
    // make_canvas(c_h_qOverP, c_h_qOverP, false, ";Track qOverP; Entires ");
    // make_canvas(c_h_d0, c_h_d0, false, ";Track d0; Entires ");
    // make_canvas(c_h_z0, c_h_z0, false, ";Track z0; Entires ");
    // make_canvas(c_h_ntracks, c_h_ntracks, false, ";Number of tracks per Reco particle; Entires ", false, 1, true);
    // make_canvas(c_h_nhits, c_h_nhits, false, ";Number of hits per event; Entires ", false, 1, true);
    //
    // make_canvas(c_h_Delta_q_pt ,c_h_z0, false, ";Delta qOverPt; Entries");
    // make_canvas(c_h_Delta_phi  ,c_h_z0, false, ";Delta phi; Entries",false,1,true);
    // make_canvas(c_h_Delta_theta,c_h_z0, false, ";Delta theta; Entries",false,1,true);
    // make_canvas(c_h_Delta_eta  ,c_h_z0, false, ";Delta eta; Entries",false,1,true);

    ///// Reconstructed versus not reconstructed true MC variables:
    // make_canvas(c_h_Ttheta, c_h_Ttheta, false, ";Track theta; Entires ");
    // make_canvas(c_yes_h_eta              ,c_no_h_eta,              true,"; MC eta;Entries",false,0,false,0.08);
    // make_canvas(c_yes_h_phi              ,c_no_h_phi,              true,"; MC phi;Entries",false,1,false,0.05);
    // make_canvas(c_yes_h_pt               ,c_no_h_pt,               true,"; MC pt;Entries",false,1,true,1.1);
    // make_canvas(c_yes_h_px               ,c_no_h_px,               true,"; MC px;Entries",false,1,false,0.09);
    // make_canvas(c_yes_h_py               ,c_no_h_py,               true,"; MC py;Entries",false,1,false,0.1);
    // make_canvas(c_yes_h_pz               ,c_no_h_pz,               true,"; MC pz;Entries",false,1,false,0.07);
    // make_canvas(c_yes_h_betagammasintheta,c_no_h_betagammasintheta,true,"; MC beta*gamma*sin(theta);Entries");
    // make_canvas(c_yes_h_E                ,c_no_h_E,                true,"; MC energy;Entries");
    // make_canvas(c_yes_h_hit_energy       ,c_no_h_hit_energy,       true,"; Hit energy;Entries");
    // make_canvas(c_yes_h_hit_time         ,c_no_h_hit_time,         true,"; Hit time;Entries",false,2,false,0.25);

    make_canvas(c_yes_h_eta              ,c_no_h_eta,              true,"; MC eta;Entries",false,0,false,0.06);
    make_canvas(c_yes_h_phi              ,c_no_h_phi,              true,"; MC phi;Entries",false,1,false,0.05);
    make_canvas(c_yes_h_pt               ,c_no_h_pt,               true,"; MC pt;Entries",false,1,true,1.1);
    make_canvas(c_yes_h_px               ,c_no_h_px,               true,"; MC px;Entries",false,1,false,0.08);
    make_canvas(c_yes_h_py               ,c_no_h_py,               true,"; MC py;Entries",false,1,false,0.1);
    make_canvas(c_yes_h_pz               ,c_no_h_pz,               true,"; MC pz;Entries",false,1,false,0.07);
    make_canvas(c_yes_h_betagammasintheta,c_no_h_betagammasintheta,true,"; MC beta*gamma*sin(theta);Entries");
    make_canvas(c_yes_h_E                ,c_no_h_E,                true,"; MC energy;Entries");
    make_canvas(c_yes_h_hit_energy       ,c_no_h_hit_energy,       true,"; Hit energy;Entries");
    make_canvas(c_yes_h_hit_time         ,c_no_h_hit_time,         true,"; Hit time;Entries",false,2,false,0.2);

    // make_canvas(c_h_vertex_r_e, c_h_vertex_r_e, false,"; GenVertex r; Reconstruction efficiency");
    // make_canvas(c_h_vertex_z_e, c_h_vertex_r_e, false,"; GenVertex r; Reconstruction efficiency", false,2);

    make_canvas(c_h2_Delta_R_vs_hit_time, "; Delta R; hit time",0);
    make_canvas(c_h2_Delta_R_vs_hit_energy, "; Delta R; hit energy",2);

    /////////////////////////////////////////////////////////////////////////////////////
    ///////////////////// 2D plots:
    //// Checks:
    // make_canvas(c_h2_MCeta_vs_Peta, "; MC eta; Best particle eta", 0);
    // make_canvas(c_h2_MCphi_vs_Pphi, "; MC phi; Best particle phi");
    // make_canvas(c_h2_MCpt_vs_Ppt, "; MC pt; Best particle pt");
    // make_canvas(c_h2_MCrho_vs_Prho, "; MC rho; Best particle rho");
    // make_canvas(c_h2_MCtheta_vs_Ptheta, "; MC theta; Best particle theta");
    // make_canvas(c_h2_MCtheta_vs_Ttheta, "; MC theta; Track theta");
    // make_canvas(c_h2_MCphi_vs_Tphi, "; MC phi; Track phi");
    // ///// Other reco particles:
    // make_canvas(c_h2_deltaR_vs_eta, "; MC eta; Best Delta R");
    // make_canvas(c_h2_deltaR_vs_phi, "; MC phi; Best Delta R");
    // make_canvas(c_h2_deltaR_vs_pt, "; MC pt; Best Delta R");
    //
    // make_canvas(c_h2_MCpt_vs_Tpt, "; MC pt; Track pt");
    // make_canvas(c_h2_Delta_phi_vs_MCpt  , "; MC pt; Delta phi");
    // make_canvas(c_h2_Delta_theta_vs_MCpt, "; MC pt; Delta theta");
    // make_canvas(c_h2_Delta_q_pt_vs_MCpt , "; MC pt; Delta q/pt");
    // make_canvas(c_h2_Delta_eta_vs_MCpt  , "; MC pt; Delta eta",2);

}

void make_canvas(TH1D* h1, TH1D* h2, bool two, string title, bool MC = false, int pos = 1, bool logy = false, double max = 0){
  TCanvas *canvas = new TCanvas("canvas","");
  canvas->SetGrid();

  if(logy){canvas->SetLogy();}

  gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  string ss1 = "plots/winos_plots.pdf[";
  string ss2 = "plots/winos_plots.pdf";
  string ss3 = "plots/winos_plots.pdf]";
    if(two){
      h1->Draw("hist h");
      if(max!=0){h1->SetMaximum(max);}
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
      legend->AddEntry(h1,"Reconstructed","l");
      legend->AddEntry(h2,"Not reconstructed","l");
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

void make_canvas(TH2D* h2, string title, int pos = 1){
  TCanvas *canvas = new TCanvas("canvas","");
  canvas->SetGrid();

  gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  string ss1 = "plots/muon_plots_2D.pdf[";
  string ss2 = "plots/muon_plots_2D.pdf";
  string ss3 = "plots/muon_plots_2D.pdf]";

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
