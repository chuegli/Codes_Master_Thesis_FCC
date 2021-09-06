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

///////////////////////////////////////////////////////////////////////////////
// takes the pileup and wino samples and plots them in comparison
//
// #&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
// #&&&&&&&&&&&&&&&&&&&&&&&&& Selected and anylsis:
// #&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
// 1) Find the good files using test.py
// 2) Run the run_shell_custom.sh file
// 3) Put files together using: read_selected.cc
// 4) Put entries in histos: look_selected.cc
// 5) DO the same for the signal: select_save.cc + look_selected
// 5) Compare the 2 root files for pileup and winos: comparison_plots_selected
//
// scp Makefile read_selected.cc look_selected.cc comparison_plots_selected.cc chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/code/
// root -b -q read_selected.cc # change stuff when changing pixel size
// ./look_selected  "/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_tree_5x5.root" "/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_tree_histo_5x5.root"
// ./select_save '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/winos_for_seeding_tracks_10000_5.root' /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/wino_5x5_selected.root
// ./look_selected /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/wino_5x5_selected.root /afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/wino_5x5_selected_histo.root
// ./comparison_plots_selected '/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/wino_5x5_selected_histo.root' "/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_tree_histo_5x5.root" '../plots/selected_pileup_vs_signal_5x5'
// scp -r chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/plots/selected_pileup_vs_signal.pdf ./plots/
///////////////////////////////////////////////////////////////////////////////

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
    cout << "test 0" << endl;
    TFile *f2 = new TFile(rootname2.c_str());
    cout << "test 1" << endl;

    TH1D* c1_h_track_pt     = (TH1D*)f1->Get("h_track_pt"    );
    TH1D* c1_h_hit_beta_10  = (TH1D*)f1->Get("h_hit_beta_10" );
    TH1D* c1_h_hit_beta_50  = (TH1D*)f1->Get("h_hit_beta_50" );
    TH1D* c1_h_track_z0     = (TH1D*)f1->Get("h_track_z0"    );
    TH1D* c1_h_track_d0     = (TH1D*)f1->Get("h_track_d0"    );
    TH1D* c1_h_track_phi    = (TH1D*)f1->Get("h_track_phi"   );
    TH1D* c1_h_track_theta  = (TH1D*)f1->Get("h_track_theta" );
    TH1D* c1_h_track_eta    = (TH1D*)f1->Get("h_track_eta"   );
    TH1D* c1_h_track_qOverP = (TH1D*)f1->Get("h_track_qOverP");
    TH1D* c1_h_nhits        = (TH1D*)f1->Get("h_nhit"       );
    cout << "test 2" << endl;

    TH1D* c2_h_track_pt     = (TH1D*)f2->Get("h_track_pt"    );
    TH1D* c2_h_hit_beta_10  = (TH1D*)f2->Get("h_hit_beta_10" );
    TH1D* c2_h_hit_beta_50  = (TH1D*)f2->Get("h_hit_beta_50" );
    TH1D* c2_h_track_z0     = (TH1D*)f2->Get("h_track_z0"    );
    TH1D* c2_h_track_d0     = (TH1D*)f2->Get("h_track_d0"    );
    TH1D* c2_h_track_phi    = (TH1D*)f2->Get("h_track_phi"   );
    TH1D* c2_h_track_theta  = (TH1D*)f2->Get("h_track_theta" );
    TH1D* c2_h_track_eta    = (TH1D*)f2->Get("h_track_eta"   );
    TH1D* c2_h_track_qOverP = (TH1D*)f2->Get("h_track_qOverP");
    TH1D* c2_h_nhits        = (TH1D*)f2->Get("h_nhit"       );

    cout << "test 3" << endl;

    ////// Get number of signal and pileups in the beta windows:
    /// charginos:
    double n_s_10 = c1_h_hit_beta_10 ->Integral(135,145);
    cout << "test 4" << endl;
    double n_s_50 = c1_h_hit_beta_50 ->Integral(125,155);
    cout << "test 5" << endl;
    /// Pileups:
    double n_p_10 = c2_h_hit_beta_10 ->Integral(135,145);
    cout << "test 6" << endl;
    double n_p_50 = c2_h_hit_beta_50 ->Integral(125,155);

    cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
    cout << "10ps: Number of signal = " << n_s_10 << " Number of pileups = " << n_p_10 << endl;
    cout << "50ps: Number of signal = " << n_s_50 << " Number of pileups = " << n_p_50 << endl;
    cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;

    c1_h_track_pt    ->Scale(1./c1_h_track_pt    ->Integral());
    c1_h_hit_beta_10 ->Scale(1./c1_h_hit_beta_10 ->Integral());
    c1_h_hit_beta_50 ->Scale(1./c1_h_hit_beta_50 ->Integral());
    c1_h_track_z0    ->Scale(1./c1_h_track_z0    ->Integral());
    c1_h_track_d0    ->Scale(1./c1_h_track_d0    ->Integral());
    c1_h_track_phi   ->Scale(1./c1_h_track_phi   ->Integral());
    c1_h_track_theta ->Scale(1./c1_h_track_theta ->Integral());
    c1_h_track_eta   ->Scale(1./c1_h_track_eta   ->Integral());
    c1_h_track_qOverP->Scale(1./c1_h_track_qOverP->Integral());
    c1_h_nhits       ->Scale(1./c1_h_nhits       ->Integral());

    c2_h_track_pt    ->Scale(1./c2_h_track_pt    ->Integral());
    c2_h_hit_beta_10 ->Scale(1./c2_h_hit_beta_10 ->Integral());
    c2_h_hit_beta_50 ->Scale(1./c2_h_hit_beta_50 ->Integral());
    c2_h_track_z0    ->Scale(1./c2_h_track_z0    ->Integral());
    c2_h_track_d0    ->Scale(1./c2_h_track_d0    ->Integral());
    c2_h_track_phi   ->Scale(1./c2_h_track_phi   ->Integral());
    c2_h_track_theta ->Scale(1./c2_h_track_theta ->Integral());
    c2_h_track_eta   ->Scale(1./c2_h_track_eta   ->Integral());
    c2_h_track_qOverP->Scale(1./c2_h_track_qOverP->Integral());
    c2_h_nhits       ->Scale(1./c2_h_nhits       ->Integral());


    cout << "********************* Start plotting *********************" << endl;
    ///////////////////// 1D plots:
    make_canvas(outputname,c1_h_track_pt    ,c2_h_track_pt    , "; Track reco pt [GeV] ; Normalized entries",0,false,0.3);
    make_canvas(outputname,c1_h_hit_beta_10 ,c2_h_hit_beta_10 , "; Hit beta 10 ps [ ]  ; Normalized entries",1,false,0.25);
    make_canvas(outputname,c1_h_hit_beta_50 ,c2_h_hit_beta_50 , "; Hit beta 50 ps [ ]  ; Normalized entries",1,false,0.25);
    make_canvas(outputname,c1_h_track_z0    ,c2_h_track_z0    , "; Track z0 [mm]       ; Normalized entries",1,false,0.6);
    make_canvas(outputname,c1_h_track_d0    ,c2_h_track_d0    , "; Track d0 [mm]       ; Normalized entries",1,false,0.6);
    make_canvas(outputname,c1_h_track_phi   ,c2_h_track_phi   , "; Track phi [ ]       ; Normalized entries",1,false,0.04);
    make_canvas(outputname,c1_h_track_theta ,c2_h_track_theta , "; Track theta [ ]     ; Normalized entries",1,false,0.14);
    make_canvas(outputname,c1_h_track_eta   ,c2_h_track_eta   , "; Track eta [ ]       ; Normalized entries",1,false,0.06);
    make_canvas(outputname,c1_h_track_qOverP,c2_h_track_qOverP, "; Track qOverP [1/GeV]; Normalized entries",1,false,0.18);
    make_canvas(outputname,c1_h_nhits       ,c2_h_nhits       , "; Number of hits per track [ ]; Normalized entries",2,false,1.1);
    /// Not normalized:
    // make_canvas(outputname,c1_h_track_pt    ,c2_h_track_pt    , "; Track reco pt [GeV]         ; Entries",0,false,650);
    // make_canvas(outputname,c1_h_hit_beta_10 ,c2_h_hit_beta_10 , "; Hit beta 10 ps [ ]          ; Entries",1,false,650);
    // make_canvas(outputname,c1_h_hit_beta_50 ,c2_h_hit_beta_50 , "; Hit beta 50 ps [ ]          ; Entries",1,false,650);
    // make_canvas(outputname,c1_h_track_z0    ,c2_h_track_z0    , "; Track z0 [mm]               ; Entries",1,false,0.0);
    // make_canvas(outputname,c1_h_track_d0    ,c2_h_track_d0    , "; Track d0 [mm]               ; Entries",1,false,0.0);
    // make_canvas(outputname,c1_h_track_phi   ,c2_h_track_phi   , "; Track phi [ ]               ; Entries",1,false,60);
    // make_canvas(outputname,c1_h_track_theta ,c2_h_track_theta , "; Track theta [ ]             ; Entries",1,false,320);
    // make_canvas(outputname,c1_h_track_eta   ,c2_h_track_eta   , "; Track eta [ ]               ; Entries",1,false,130);
    // make_canvas(outputname,c1_h_track_qOverP,c2_h_track_qOverP, "; Track qOverP [1/GeV]        ; Entries",1,false,70);
    // make_canvas(outputname,c1_h_nhits       ,c2_h_nhits       , "; Number of hits per track [ ]; Entries",2,false,2500);

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
