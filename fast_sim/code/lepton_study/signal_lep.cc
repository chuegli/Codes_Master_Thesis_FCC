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
#include <TSystemDirectory.h>

#include <math.h>
#include <typeinfo>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
///////////// What this .cc does:
// This .cc concerns the signal samples only.
// 1) It produces histograms for the study of leptons (pt, eta, numbers, ...)
// 2) It saves them to .root
////////////////////////////////////////////////////////////////////////////////


void make_efficiency(TString filename, string f_type, string f);

void signal_lep(){
  // string f_start = "/home/saito/datafiles/FCC/AMSB_EW/renamed/mAMSB_"; // on login.icepp.jp
  string f_start = "/eos/user/m/masaito/FCC/AMSB_EW/mAMSB_"; //on lxplus
  string f_type1  = "C1N1";
  string f_type2  = "C1C1";
  string f_middle[40];

  for (int i = 0; i < 40; i++){
      f_middle[i] = to_string(700+100*i);
      make_efficiency(f_start,f_type1,f_middle[i]);
      make_efficiency(f_start,f_type2,f_middle[i]);
  }

}

void make_efficiency(TString filename, string f_type, string f){
  TChain* myChain = new TChain("events");
  TString filename1;
  filename = filename+f_type+".";
  string f_end   = ".root";
  if(stod(f)<=1500){
    cout << "Current: " << f_type << ", " << f << endl;
    string extra ="";
    if(stod(f)<1000){extra= "0";}
    for(int i=1; i<10;i++){
      filename1 = filename+extra+f+"GeV.00"+to_string(i)+f_end;
      myChain->Add(filename1);
    } // for over i
    filename1 = filename+extra+f+"GeV.010"+f_end;
  }else{
    filename1 = filename+f+"GeV"+f_end;
  }
  myChain->Add(filename1);

  double entries_start = myChain->GetEntries();
  cout << entries_start << endl;

  ////////////// TTreeReader
  TTreeReader reader(myChain);
  // Reco MET
  TTreeReaderArray<float> met_magnitude(reader, "met.magnitude");
  TTreeReaderArray<float> met_phi(reader, "met.phi");
  // Truth Jet
  TTreeReaderArray<float> jets_px(reader, "genJets.core.p4.px");
  TTreeReaderArray<float> jets_py(reader, "genJets.core.p4.py");
  TTreeReaderArray<float> jets_pz(reader, "genJets.core.p4.pz");
  TTreeReaderArray<float> jets_mass(reader, "genJets.core.p4.mass");
  // Reco Electron
  TTreeReaderArray<float> electrons_px(reader, "electrons.core.p4.px");
  TTreeReaderArray<float> electrons_py(reader, "electrons.core.p4.py");
  TTreeReaderArray<float> electrons_pz(reader, "electrons.core.p4.pz");
  TTreeReaderArray<float> electrons_mass(reader, "electrons.core.p4.mass");
  // Reco Muon
  TTreeReaderArray<float> muons_px(reader, "muons.core.p4.px");
  TTreeReaderArray<float> muons_py(reader, "muons.core.p4.py");
  TTreeReaderArray<float> muons_pz(reader, "muons.core.p4.pz");
  TTreeReaderArray<float> muons_mass(reader, "muons.core.p4.mass");
  // Truth Particles
  TTreeReaderArray<float> genParticles_px(reader, "skimmedGenParticles.core.p4.px");
  TTreeReaderArray<float> genParticles_py(reader, "skimmedGenParticles.core.p4.py");
  TTreeReaderArray<float> genParticles_pz(reader, "skimmedGenParticles.core.p4.pz");
  TTreeReaderArray<float> genParticles_mass(reader, "skimmedGenParticles.core.p4.mass");
  TTreeReaderArray<int> genParticles_pdgId(reader, "skimmedGenParticles.core.pdgId");
  TTreeReaderArray<unsigned int> genParticles_status(reader, "skimmedGenParticles.core.status");

  ////////// Histogram creation:
  TH1D* h_genLep_n    = new TH1D("h_genLep_n",   "h_genLep_n; Number of genLep; Number of entries",     51,  -0.5 , 50.5);
  TH1D* h_genLep_phi  = new TH1D("h_genLep_phi", "h_genLep_phi; genLep phi; Number of entries",         100, -5 , 5  );
  TH1D* h_genLep_pt   = new TH1D("h_genLep_pt",  "h_genLep_pt; genLep p_T [GeV]; Number of entries",    100, -10, 600);
  TH1D* h_genLep_eta  = new TH1D("h_genLep_eta", "h_genLep_eta; genLep eta; Number of entries",         100, -15, 15 );
  TH1D* h_LgenLep_pt  = new TH1D("h_LgenLep_pt",  "h_LgenLep_pt; LgenLep p_T [GeV]; Number of entries", 100, -10, 600);
  TH1D* h_LgenLep_eta = new TH1D("h_LgenLep_eta", "h_LgenLep_eta; LgenLep eta; Number of entries",      100, -15, 15 );

  TH1D* h_Lep_n    = new TH1D("h_Lep_n",   "h_Lep_n; Number of Lep; Number of entries",     51,  -0.5 , 50.5);
  TH1D* h_Lep_phi  = new TH1D("h_Lep_phi", "h_Lep_phi; Lep phi; Number of entries",         100, -5 , 5  );
  TH1D* h_Lep_pt   = new TH1D("h_Lep_pt",  "h_Lep_pt; Lep p_T [GeV]; Number of entries",    100, -10, 600);
  TH1D* h_Lep_eta  = new TH1D("h_Lep_eta", "h_Lep_eta; Lep eta; Number of entries",         100, -10, 10 );
  TH1D* h_LLep_pt  = new TH1D("h_LLep_pt",  "h_LLep_pt; LLep p_T [GeV]; Number of entries", 100, -10, 600);
  TH1D* h_LLep_eta = new TH1D("h_LLep_eta", "h_LLep_eta; LLep eta; Number of entries",      100, -10, 10 );


  ////////////// Reader Loop:
  while(reader.Next()){
      // Loop over truth (generated) particles
      int n_genParticles = genParticles_px.GetSize();
      int lep_counter1 = 0;
      double leading_lep_pt = 0;
      double leading_lep_eta;
      bool lep_exist = false;
      TLorentzVector vectorsum(0,0,0,0);
      for(int i=0; i<n_genParticles; i++){
          // if(genParticles_status.At(i) != 1) continue;
          TLorentzVector p4;
          p4.SetXYZM(
              genParticles_px.At(i),
              genParticles_py.At(i),
              genParticles_pz.At(i),
              genParticles_mass.At(i)
          );

          // Count electrons and muons:
          if((abs(genParticles_pdgId.At(i)) == 11 || abs(genParticles_pdgId.At(i)) == 13) && genParticles_status.At(i)==1 && p4.Pt()>10){
          // if((abs(genParticles_pdgId.At(i)) == 11 || abs(genParticles_pdgId.At(i)) == 13) && genParticles_status.At(i)==0){
                lep_counter1++;
                // Leading:
                if(p4.Pt() > leading_lep_pt){
                  leading_lep_pt  = p4.Pt();
                  leading_lep_eta = p4.Eta();
                }

                h_genLep_pt ->Fill(p4.Pt());
                h_genLep_eta->Fill(p4.Eta());
                h_genLep_phi->Fill(p4.Phi());

                lep_exist = true;
          }
      } // end of loop over gen particles
      if(lep_exist){
        h_genLep_n   ->Fill(lep_counter1);
        h_LgenLep_pt ->Fill(leading_lep_pt);
        h_LgenLep_eta->Fill(leading_lep_eta);
      }

      lep_exist = false;
      // Loop over reco electrons
      int lep_counter2 = 0;
      double leading_lep_pt2 = 0;
      double leading_lep_eta2 = 0;
      int n_electrons = electrons_px.GetSize();
      for(int i=0; i<n_electrons; i++){
          TLorentzVector p4;
          p4.SetXYZM(
              electrons_px.At(i),
              electrons_py.At(i),
              electrons_pz.At(i),
              electrons_mass.At(i)
          );
          h_Lep_pt ->Fill(p4.Pt());
          h_Lep_eta->Fill(p4.Eta());
          h_Lep_phi->Fill(p4.Phi());
          lep_counter2++;

          // Leading:
          if(p4.Pt() > leading_lep_pt){
            leading_lep_pt2  = p4.Pt();
            leading_lep_eta2 = p4.Eta();
          }

          lep_exist = true;
      }
      // Loop over reco muons
      int n_muons = muons_px.GetSize();
      for(int i=0; i<n_muons; i++){
            TLorentzVector p4;
            p4.SetXYZM(
                muons_px.At(i),
                muons_py.At(i),
                muons_pz.At(i),
                muons_mass.At(i)
            );
            h_Lep_pt ->Fill(p4.Pt());
            h_Lep_eta->Fill(p4.Eta());
            h_Lep_phi->Fill(p4.Phi());
            lep_counter2++;

            // Leading:
            if(p4.Pt() > leading_lep_pt){
              leading_lep_pt2  = p4.Pt();
              leading_lep_eta2 = p4.Eta();
            }

            lep_exist = true;
      }
      if(lep_exist){
        h_Lep_n   ->Fill(lep_counter2);
        h_LLep_pt ->Fill(leading_lep_pt2);
        h_LLep_eta->Fill(leading_lep_eta2);
      }

  } // end of reader.Next


  //////////////////////////////////////////////////////////////////////////////
  //////////////// Save histograms to .root files:
  string rootname = "/afs/cern.ch/user/c/chugli/private/histos/histo_lepton_study_" +f_type+"_"+f+".root";
  const char* foutname = rootname.c_str();
  cout << foutname << endl;
  auto f1 = TFile::Open(foutname, "RECREATE");
  h_genLep_n    ->Write();
  h_genLep_phi  ->Write();
  h_genLep_pt   ->Write();
  h_genLep_eta  ->Write();
  h_LgenLep_pt  ->Write();
  h_LgenLep_eta ->Write();
  h_Lep_n       ->Write();
  h_Lep_phi     ->Write();
  h_Lep_pt      ->Write();
  h_Lep_eta     ->Write();
  h_LLep_pt     ->Write();
  h_LLep_eta    ->Write();
  f1->Close();
}
