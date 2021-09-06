#include <TFile.h>
#include <TTree.h>
#include <TTreeReader.h>
#include <TTreeReaderArray.h>
#include <TLorentzVector.h>
#include <TVector2.h>
#include <TH1D.h>
#include <TLegend.h>
#include <TPaveStats.h>
#include <TChain.h>
#include <TString.h>
#include <TPaveLabel.h>
#include <TMultiGraph.h>
#include <TGraph.h>
#include <TColor.h>
#include <TSystemDirectory.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TPad.h>

#include <math.h>
#include <typeinfo>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
///////////// What this .cc does:
// !!! Important !!!
// if not already done you need to run first signal_lep.cc and BG_lep.cc
//
// This .cc concerns both signals and BGs samples.
//
// 1) It first extracts the dynamic histograms for the BGs and saves them to THStacks
// 2) It does the same for the signals
// 3) It plots both in plots_lep.pdf
////////////////////////////////////////////////////////////////////////////////

void histo_sytling(TH1D* h, int ii);
map<TString, TH1*> make_histograms(TString filename, TString f);

void plots_lep(){
  ////////// Definition part:
  cout << "********************* Start BG part *********************" << endl;

  string BGtype[5] = {"W+jets","Z+jets","ttbar","topsingle","multijets"};

  int mylength[5] = {7,7,10,1,9};

  string a[] = {"0_150", "150_300", "300_500", "500_1000", "1000_2000", "2000_5000", "5000_100000"};
  string c[] = {"0_600", "600_1200", "1200_2100", "2100_3400", "3400_5300", "5300_8100", "8100_15000",
  "15000_25000", "25000_35000", "35000_100000"};
  string d[] = {""};
  string e[] = {"0_500", "500_1000", "1000_2000", "2000_4000", "4000_7200", "7200_15000",
  "15000_25000", "25000_35000", "35000_100000"};
  string *myfolders[5] = {a,a,c,d,e};

  map<TString, TH1D*> HStack_h;
  map<int, map<TString, TH1D*>> h_map;

  // for(int i=0; i<5;i++){
  for(int i=0; i<4;i++){
    const char* BGchar = BGtype[i].c_str();
    cout << "********************* Start BG " << BGtype[i] << " *********************" << endl;

    HStack_h["genLep_n"]    = new TH1D(BGchar, BGchar, 51, -0.5 , 50.5);
    HStack_h["genLep_phi"]  = new TH1D(BGchar, BGchar, 100, -5 , 5   );
    HStack_h["genLep_pt"]   = new TH1D(BGchar, BGchar, 100, -10, 600);
    HStack_h["genLep_eta"]  = new TH1D(BGchar, BGchar, 100, -15, 15  );
    HStack_h["LgenLep_pt"]  = new TH1D(BGchar, BGchar, 100, -10, 600);
    HStack_h["LgenLep_eta"] = new TH1D(BGchar, BGchar, 100, -15, 15  );

    HStack_h["Lep_n"]    = new TH1D(BGchar, BGchar, 51, -0.5 , 50.5);
    HStack_h["Lep_phi"]  = new TH1D(BGchar, BGchar, 100, -5 , 5   );
    HStack_h["Lep_pt"]   = new TH1D(BGchar, BGchar, 100, -10, 600);
    HStack_h["Lep_eta"]  = new TH1D(BGchar, BGchar, 100, -10, 10  );
    HStack_h["LLep_pt"]  = new TH1D(BGchar, BGchar, 100, -10, 600);
    HStack_h["LLep_eta"] = new TH1D(BGchar, BGchar, 100, -10, 10  );

    for(int j=0; j<mylength[i]; j++){
      string filename = "/afs/cern.ch/user/c/chugli/private/histos/histo_lepton_study_" +BGtype[i]+"_"+myfolders[i][j]+".root";
      const char* dirname = filename.c_str();
      TFile *f = new TFile(dirname);

      TH1D* genLep_n    = (TH1D*)f->Get("h_genLep_n");
      TH1D* genLep_phi  = (TH1D*)f->Get("h_genLep_phi");
      TH1D* genLep_pt   = (TH1D*)f->Get("h_genLep_pt");
      TH1D* genLep_eta  = (TH1D*)f->Get("h_genLep_eta");
      TH1D* LgenLep_pt  = (TH1D*)f->Get("h_LgenLep_pt");
      TH1D* LgenLep_eta = (TH1D*)f->Get("h_LgenLep_eta");

      TH1D* Lep_n    = (TH1D*)f->Get("h_Lep_n");
      TH1D* Lep_phi  = (TH1D*)f->Get("h_Lep_phi");
      TH1D* Lep_pt   = (TH1D*)f->Get("h_Lep_pt");
      TH1D* Lep_eta  = (TH1D*)f->Get("h_Lep_eta");
      TH1D* LLep_pt  = (TH1D*)f->Get("h_LLep_pt");
      TH1D* LLep_eta = (TH1D*)f->Get("h_LLep_eta");

      int ii = i+1;

      histo_sytling(HStack_h["genLep_n"]   ,ii);
      histo_sytling(HStack_h["genLep_phi"] ,ii);
      histo_sytling(HStack_h["genLep_pt"]  ,ii);
      histo_sytling(HStack_h["genLep_eta"] ,ii);
      histo_sytling(HStack_h["LgenLep_pt"] ,ii);
      histo_sytling(HStack_h["LgenLep_eta"],ii);
      histo_sytling(HStack_h["Lep_n"]      ,ii);
      histo_sytling(HStack_h["Lep_phi"]    ,ii);
      histo_sytling(HStack_h["Lep_pt"]     ,ii);
      histo_sytling(HStack_h["Lep_eta"]    ,ii);
      histo_sytling(HStack_h["LLep_pt"]    ,ii);
      histo_sytling(HStack_h["LLep_eta"]   ,ii);

      HStack_h["genLep_n"]   ->Add(genLep_n);
      HStack_h["genLep_phi"] ->Add(genLep_phi);
      HStack_h["genLep_pt"]  ->Add(genLep_pt);
      HStack_h["genLep_eta"] ->Add(genLep_eta);
      HStack_h["LgenLep_pt"] ->Add(LgenLep_pt);
      HStack_h["LgenLep_eta"]->Add(LgenLep_eta);
      HStack_h["Lep_n"]      ->Add(Lep_n);
      HStack_h["Lep_phi"]    ->Add(Lep_phi);
      HStack_h["Lep_pt"]     ->Add(Lep_pt);
      HStack_h["Lep_eta"]    ->Add(Lep_eta);
      HStack_h["LLep_pt"]    ->Add(LLep_pt);
      HStack_h["LLep_eta"]   ->Add(LLep_eta);
    } // end of j

    h_map[i] = HStack_h;

  } //end of i

  /////////////////////////////////////////////////////////////////////////////
  /////////////////// Signal part:
  cout << "********************* Start signal part *********************" << endl;
  string f_type1  = "C1N1";
  string f_type2  = "C1C1";
  string f_middle[40];

  for (int j=0; j<2; j++){
      string ftype;
      int ii;
      if(j==0){ftype=f_type1;ii=6;}
      else{ftype=f_type2;ii=7;}
      cout << "********************* Start signal " << ftype << " *********************" << endl;

      const char* ftype_c = ftype.c_str();

      HStack_h["genLep_n"]    = new TH1D(ftype_c, ftype_c, 51,  -0.5 , 50.5);
      HStack_h["genLep_phi"]  = new TH1D(ftype_c, ftype_c, 100, -5 , 5   );
      HStack_h["genLep_pt"]   = new TH1D(ftype_c, ftype_c, 100, -10, 600);
      HStack_h["genLep_eta"]  = new TH1D(ftype_c, ftype_c, 100, -15, 15  );
      HStack_h["LgenLep_pt"]  = new TH1D(ftype_c, ftype_c, 100, -10, 600);
      HStack_h["LgenLep_eta"] = new TH1D(ftype_c, ftype_c, 100, -15, 15  );

      HStack_h["Lep_n"]    = new TH1D(ftype_c, ftype_c, 51,  -0.5 , 50.5);
      HStack_h["Lep_phi"]  = new TH1D(ftype_c, ftype_c, 100, -5 , 5   );
      HStack_h["Lep_pt"]   = new TH1D(ftype_c, ftype_c, 100, -10, 600);
      HStack_h["Lep_eta"]  = new TH1D(ftype_c, ftype_c, 100, -10, 10  );
      HStack_h["LLep_pt"]  = new TH1D(ftype_c, ftype_c, 100, -10, 600);
      HStack_h["LLep_eta"] = new TH1D(ftype_c, ftype_c, 100, -10, 10  );

      for(int i = 0; i < 40; i++){
        f_middle[i] = to_string(700+100*i);
        string filename = "/afs/cern.ch/user/c/chugli/private/histos/histo_lepton_study_" +ftype+"_"+f_middle[i]+".root";
        const char* dirname = filename.c_str();
        TFile *f = new TFile(dirname);

        TH1D* genLep_n    = (TH1D*)f->Get("h_genLep_n");
        TH1D* genLep_phi  = (TH1D*)f->Get("h_genLep_phi");
        TH1D* genLep_pt   = (TH1D*)f->Get("h_genLep_pt");
        TH1D* genLep_eta  = (TH1D*)f->Get("h_genLep_eta");
        TH1D* LgenLep_pt  = (TH1D*)f->Get("h_LgenLep_pt");
        TH1D* LgenLep_eta = (TH1D*)f->Get("h_LgenLep_eta");

        TH1D* Lep_n    = (TH1D*)f->Get("h_Lep_n");
        TH1D* Lep_phi  = (TH1D*)f->Get("h_Lep_phi");
        TH1D* Lep_pt   = (TH1D*)f->Get("h_Lep_pt");
        TH1D* Lep_eta  = (TH1D*)f->Get("h_Lep_eta");
        TH1D* LLep_pt  = (TH1D*)f->Get("h_LLep_pt");
        TH1D* LLep_eta = (TH1D*)f->Get("h_LLep_eta");

        histo_sytling(HStack_h["genLep_n"]   ,ii);
        histo_sytling(HStack_h["genLep_phi"] ,ii);
        histo_sytling(HStack_h["genLep_pt"]  ,ii);
        histo_sytling(HStack_h["genLep_eta"] ,ii);
        histo_sytling(HStack_h["LgenLep_pt"] ,ii);
        histo_sytling(HStack_h["LgenLep_eta"],ii);
        histo_sytling(HStack_h["Lep_n"]      ,ii);
        histo_sytling(HStack_h["Lep_phi"]    ,ii);
        histo_sytling(HStack_h["Lep_pt"]     ,ii);
        histo_sytling(HStack_h["Lep_eta"]    ,ii);
        histo_sytling(HStack_h["LLep_pt"]    ,ii);
        histo_sytling(HStack_h["LLep_eta"]   ,ii);

        HStack_h["genLep_n"]   ->Add(genLep_n);
        HStack_h["genLep_phi"] ->Add(genLep_phi);
        HStack_h["genLep_pt"]  ->Add(genLep_pt);
        HStack_h["genLep_eta"] ->Add(genLep_eta);
        HStack_h["LgenLep_pt"] ->Add(LgenLep_pt);
        HStack_h["LgenLep_eta"]->Add(LgenLep_eta);
        HStack_h["Lep_n"]      ->Add(Lep_n);
        HStack_h["Lep_phi"]    ->Add(Lep_phi);
        HStack_h["Lep_pt"]     ->Add(Lep_pt);
        HStack_h["Lep_eta"]    ->Add(Lep_eta);
        HStack_h["LLep_pt"]    ->Add(LLep_pt);
        HStack_h["LLep_eta"]   ->Add(LLep_eta);
    } // end of i
    if(j==0){h_map[5] = HStack_h;}
    else{h_map[6] = HStack_h;}
} // end of j = loop over {C1C1, C1N1}



  cout << "********************* Start plotting *********************" << endl;
  ////////// Plotting part:
  TCanvas *canvas = new TCanvas("c","");
  canvas->SetGrid();
  gPad->SetMargin(0.15,0.1,0.1,0.1);//l,r,b,t
  canvas->SetLogy();
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  h_map[1]["genLep_n"]->GetXaxis()->SetTitle("Number of genLep");
  h_map[1]["genLep_n"]->GetYaxis()->SetTitle("Number of entries");
  h_map[1]["genLep_n"]->SetMaximum(1e7);
  h_map[1]["genLep_n"]->SetMinimum(1);
  h_map[1]["genLep_n"]->Draw("cp");
  h_map[0]["genLep_n"]->Draw("same cp");
  h_map[2]["genLep_n"]->Draw("same cp");
  h_map[3]["genLep_n"]->Draw("same cp");
  h_map[5]["genLep_n"]->Draw("same cp");
  h_map[6]["genLep_n"]->Draw("same cp");
  canvas->BuildLegend(0.8,0.7,0.9,0.9);
  canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/plots/lepton_study/plot_lep.pdf[");
  canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/plots/lepton_study/plot_lep.pdf");
  h_map[1]["genLep_phi"]->GetXaxis()->SetTitle("genLep phi");
  h_map[1]["genLep_phi"]->GetYaxis()->SetTitle("Number of entries");
  h_map[1]["genLep_phi"]->SetMaximum(1e6);
  h_map[1]["genLep_phi"]->SetMinimum(1);
  h_map[1]["genLep_phi"]->Draw("cp");
  h_map[0]["genLep_phi"]->Draw("same cp");
  h_map[2]["genLep_phi"]->Draw("same cp");
  h_map[3]["genLep_phi"]->Draw("same cp");
  h_map[5]["genLep_phi"]->Draw("same cp");
  h_map[6]["genLep_phi"]->Draw("same cp");
  canvas->BuildLegend(0.8,0.7,0.9,0.9);
  canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/plots/lepton_study/plot_lep.pdf");
  h_map[1]["genLep_pt"]->GetXaxis()->SetTitle("genLep p_T [GeV]");
  h_map[1]["genLep_pt"]->GetYaxis()->SetTitle("Number of entries");
  h_map[1]["genLep_pt"]->SetMaximum(1e7);
  h_map[1]["genLep_pt"]->SetMinimum(1);
  h_map[1]["genLep_pt"]->Draw("cp");
  h_map[0]["genLep_pt"]->Draw("same cp");
  h_map[2]["genLep_pt"]->Draw("same cp");
  h_map[3]["genLep_pt"]->Draw("same cp");
  h_map[5]["genLep_pt"]->Draw("same cp");
  h_map[6]["genLep_pt"]->Draw("same cp");
  canvas->BuildLegend(0.8,0.7,0.9,0.9);
  canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/plots/lepton_study/plot_lep.pdf");
  h_map[2]["genLep_eta"]->GetXaxis()->SetTitle("genLep eta");
  h_map[2]["genLep_eta"]->GetYaxis()->SetTitle("Number of entries");
  // h_map[1]["genLep_eta"]->SetMaximum(1e5);
  // h_map[1]["genLep_eta"]->SetMinimum(1e-3);
  h_map[2]["genLep_eta"]->Draw("cp");
  h_map[0]["genLep_eta"]->Draw("same cp");
  h_map[1]["genLep_eta"]->Draw("same cp");
  h_map[3]["genLep_eta"]->Draw("same cp");
  h_map[5]["genLep_eta"]->Draw("same cp");
  h_map[6]["genLep_eta"]->Draw("same cp");
  canvas->BuildLegend(0.8,0.7,0.9,0.9);
  canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/plots/lepton_study/plot_lep.pdf");
  h_map[1]["LgenLep_pt"]->GetXaxis()->SetTitle("Leading genLep p_T [GeV]");
  h_map[1]["LgenLep_pt"]->GetYaxis()->SetTitle("Number of entries");
  h_map[1]["LgenLep_pt"]->SetMaximum(1e6);
  h_map[1]["LgenLep_pt"]->SetMinimum(1);
  h_map[1]["LgenLep_pt"]->Draw("cp");
  h_map[0]["LgenLep_pt"]->Draw("same cp");
  h_map[2]["LgenLep_pt"]->Draw("same cp");
  h_map[3]["LgenLep_pt"]->Draw("same cp");
  h_map[5]["LgenLep_pt"]->Draw("same cp");
  h_map[6]["LgenLep_pt"]->Draw("same cp");
  canvas->BuildLegend(0.8,0.7,0.9,0.9);
  canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/plots/lepton_study/plot_lep.pdf");
  h_map[1]["LgenLep_eta"]->GetXaxis()->SetTitle("Leading genLep eta");
  h_map[1]["LgenLep_eta"]->GetYaxis()->SetTitle("Number of entries");
  h_map[1]["LgenLep_eta"]->SetMaximum(1e6);
  h_map[1]["LgenLep_eta"]->SetMinimum(1);
  h_map[1]["LgenLep_eta"]->Draw("cp");
  h_map[0]["LgenLep_eta"]->Draw("same cp");
  h_map[2]["LgenLep_eta"]->Draw("same cp");
  h_map[3]["LgenLep_eta"]->Draw("same cp");
  h_map[5]["LgenLep_eta"]->Draw("same cp");
  h_map[6]["LgenLep_eta"]->Draw("same cp");
  canvas->BuildLegend(0.8,0.7,0.9,0.9);
  canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/plots/lepton_study/plot_lep.pdf");
  // canvas->SetLogy();
  h_map[1]["Lep_n"]->GetXaxis()->SetTitle("Number of Lep");
  h_map[1]["Lep_n"]->GetYaxis()->SetTitle("Number of entries");
  h_map[1]["Lep_n"]->SetMaximum(1e7);
  h_map[1]["Lep_n"]->SetMinimum(1);
  h_map[1]["Lep_n"]->Draw("cp");
  h_map[0]["Lep_n"]->Draw("same cp");
  h_map[2]["Lep_n"]->Draw("same cp");
  h_map[3]["Lep_n"]->Draw("same cp");
  h_map[5]["Lep_n"]->Draw("same cp");
  h_map[6]["Lep_n"]->Draw("same cp");
  canvas->BuildLegend(0.8,0.7,0.9,0.9);
  canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/plots/lepton_study/plot_lep.pdf");
  h_map[2]["Lep_phi"]->GetXaxis()->SetTitle("Lep phi");
  h_map[2]["Lep_phi"]->GetYaxis()->SetTitle("Number of entries");
  h_map[2]["Lep_phi"]->SetMaximum(1e6);
  h_map[2]["Lep_phi"]->SetMinimum(1);
  h_map[2]["Lep_phi"]->Draw("cp");
  h_map[0]["Lep_phi"]->Draw("same cp");
  h_map[1]["Lep_phi"]->Draw("same cp");
  h_map[3]["Lep_phi"]->Draw("same cp");
  h_map[5]["Lep_phi"]->Draw("same cp");
  h_map[6]["Lep_phi"]->Draw("same cp");
  canvas->BuildLegend(0.8,0.7,0.9,0.9);
  canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/plots/lepton_study/plot_lep.pdf");
  h_map[1]["Lep_pt"]->GetXaxis()->SetTitle("Lep p_T [GeV]");
  h_map[1]["Lep_pt"]->GetYaxis()->SetTitle("Number of entries");
  h_map[1]["Lep_pt"]->SetMaximum(1e8);
  h_map[1]["Lep_pt"]->SetMinimum(1);
  h_map[1]["Lep_pt"]->Draw("cp");
  h_map[0]["Lep_pt"]->Draw("same cp");
  h_map[2]["Lep_pt"]->Draw("same cp");
  h_map[3]["Lep_pt"]->Draw("same cp");
  h_map[5]["Lep_pt"]->Draw("same cp");
  h_map[6]["Lep_pt"]->Draw("same cp");
  canvas->BuildLegend(0.8,0.7,0.9,0.9);
  canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/plots/lepton_study/plot_lep.pdf");
  h_map[2]["Lep_eta"]->GetXaxis()->SetTitle("Lep eta");
  h_map[2]["Lep_eta"]->GetYaxis()->SetTitle("Number of entries");
  h_map[2]["Lep_eta"]->SetMaximum(1e7);
  h_map[2]["Lep_eta"]->SetMinimum(1);
  h_map[2]["Lep_eta"]->Draw("cp");
  h_map[0]["Lep_eta"]->Draw("same cp");
  h_map[1]["Lep_eta"]->Draw("same cp");
  h_map[3]["Lep_eta"]->Draw("same cp");
  h_map[5]["Lep_eta"]->Draw("same cp");
  h_map[6]["Lep_eta"]->Draw("same cp");
  canvas->BuildLegend(0.8,0.7,0.9,0.9);
  canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/plots/lepton_study/plot_lep.pdf");
  h_map[1]["LLep_pt"]->GetXaxis()->SetTitle("Leading Lep p_T [GeV]");
  h_map[1]["LLep_pt"]->GetYaxis()->SetTitle("Number of entries");
  h_map[1]["LLep_pt"]->SetMaximum(1e7);
  h_map[1]["LLep_pt"]->SetMinimum(1);
  h_map[1]["LLep_pt"]->Draw("cp");
  h_map[0]["LLep_pt"]->Draw("same cp");
  h_map[2]["LLep_pt"]->Draw("same cp");
  h_map[3]["LLep_pt"]->Draw("same cp");
  h_map[5]["LLep_pt"]->Draw("same cp");
  h_map[6]["LLep_pt"]->Draw("same cp");
  canvas->BuildLegend(0.8,0.7,0.9,0.9);
  canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/plots/lepton_study/plot_lep.pdf");
  h_map[1]["LLep_eta"]->GetXaxis()->SetTitle("Leading Lep eta");
  h_map[1]["LLep_eta"]->GetYaxis()->SetTitle("Number of entries");
  h_map[1]["LLep_eta"]->SetMaximum(1e7);
  h_map[1]["LLep_eta"]->SetMinimum(1);
  h_map[1]["LLep_eta"]->Draw("cp");
  h_map[0]["LLep_eta"]->Draw("same cp");
  h_map[2]["LLep_eta"]->Draw("same cp");
  h_map[3]["LLep_eta"]->Draw("same cp");
  h_map[5]["LLep_eta"]->Draw("same cp");
  h_map[6]["LLep_eta"]->Draw("same cp");
  canvas->BuildLegend(0.8,0.7,0.9,0.9);
  canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/plots/lepton_study/plot_lep.pdf");
  canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/plots/lepton_study/plot_lep.pdf]");
  canvas->Close();

} // end of main

void histo_sytling(TH1D* h, int ii){
  h->SetLineColor(ii);
  h->SetMarkerColor(ii+1);
  h->SetLineWidth(2);
  // h->SetLineWidth(0);
}
