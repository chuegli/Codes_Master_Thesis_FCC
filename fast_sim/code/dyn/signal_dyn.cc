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

#include <math.h>
#include <typeinfo>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
///////////// What this .cc does:
// This .cc concerns the signal samples only.
// 1) It produces histograms for the dynamics (met, jet pt,...)
// 2) It saves them to .root
////////////////////////////////////////////////////////////////////////////////


void make_efficiency(TString filename, string f_type, string f, double ntot_t);

void signal_dyn(){
  // string f_start = "/home/saito/datafiles/FCC/AMSB_EW/renamed/mAMSB_"; // on login.icepp.jp
  string f_start = "/eos/user/m/masaito/FCC/AMSB_EW/mAMSB_"; //on lxplus
  string f_type1  = "C1N1";
  string f_type2  = "C1C1";
  string f_middle[40];

  ////////////////////////////////////////////////////////////////////////////
  ////////////// Extract total number of expected events:
  cout << "Start reading Nr_Events_signal.txt" << endl;
  ifstream MyReadFile("/afs/cern.ch/user/c/chugli/private/txt/Nr_Events_signal.txt"); // Read from the text file
  string s;
  string delimiter = ",";
  int counter = 0;
  int i = 0, i1=0, i2=0;
  Int_t n = 80;
  Double_t n_tot1[n], n_tot2[n];
  while (getline (MyReadFile, s)) {
    if(counter>1 && counter < 82){
      size_t found1 = s.find(delimiter,0); // position of first delimiter
      size_t found2 = s.find(delimiter,found1+1);
      string s1 = s.substr(0, found1); //BG type
      string s2 = s.substr(found1+2, found2-found1-2); // HT range
      string s3 = s.substr(found2+2,-3); // # events
      if(i%2==0){n_tot1[i1]= stod(s3);i1++;}
      else{n_tot2[i2]= stod(s3);i2++;}
      i++;
      // cout << "s: " << s << endl;
      // cout << "s1: " << s1 << endl;
      // cout << "s2: " << s2 << endl;
      // cout << "s3: " << s3 << endl;
    }else if(counter >= 82){
      break;
    }
    counter++;
  }
  MyReadFile.close();
  //// end of extract events

  for (int i = 0; i < 40; i++){
      f_middle[i] = to_string(700+100*i);
      make_efficiency(f_start,f_type1,f_middle[i],n_tot1[i]);
      make_efficiency(f_start,f_type2,f_middle[i],n_tot2[i]);
  }

}

void make_efficiency(TString filename, string f_type, string f, double ntot_t){
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


  // TH1D* h_met         = new TH1D("met",         "met; met p_T [GeV]; Number of entries", 100, -200, 7000);
  // TH1D* h_LgenJet_pt  = new TH1D("LgenJet_pt",  "LgenJet_pt; LgenJet p_T [GeV]; Number of entries", 100, -500, 6000);
  TH1D* h_met         = new TH1D("met",         "met; met p_T [GeV]; Number of entries", 25, 0, 5000);
  TH1D* h_LgenJet_pt  = new TH1D("LgenJet_pt",  "LgenJet_pt; LgenJet p_T [GeV]; Number of entries", 25, 0, 5000);
  TH1D* h_LgenJet_eta = new TH1D("LgenJet_eta", "LgenJet_eta; LgenJet p_T [GeV]; Number of entries", 100, -10, 10);
  TH1D* h_genJet_pt   = new TH1D("genJet_pt",   "genJet; p_T [GeV]; Number of entries", 100, -100, 2500);
  TH1D* h_genJet_eta  = new TH1D("genJet_eta",  "genJet; eta; Number of entries", 100, -10, 10);

  ////////////// Reader Loop:
  while(reader.Next()){
      bool c3 = true;
      // Loop over reco electrons
      int n_electrons = electrons_px.GetSize();
      for(int i=0; i<n_electrons; i++){
          TLorentzVector p4;
          p4.SetXYZM(
              electrons_px.At(i),
              electrons_py.At(i),
              electrons_pz.At(i),
              electrons_mass.At(i)
          );
          if(p4.Pt()>10){c3=false;}
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
            if(p4.Pt()>10){c3=false;}
      }

      // Loop over reco jets
      int n_jets = jets_px.GetSize();
      double jet_leading_pt = 0;
      double jet_leading_eta;
      double jet_HT = 0;
      for(int i=0; i<n_jets; i++){
          TLorentzVector p4;
          p4.SetXYZM(
              jets_px.At(i),
              jets_py.At(i),
              jets_pz.At(i),
              jets_mass.At(i)
          );
          // leading jet
          if(p4.Pt()>jet_leading_pt){
            jet_leading_pt  = p4.Pt();
            jet_leading_eta = p4.Eta();
          }
          if(c3){h_genJet_pt->Fill(p4.Pt());}
          if(c3){h_genJet_eta->Fill(p4.Eta());}
          jet_HT = jet_HT + p4.Pt();
      }
      if(c3){h_LgenJet_pt->Fill(jet_leading_pt);}
      if(c3){h_LgenJet_eta->Fill(jet_leading_eta);}

      // Reco MET
      TVector2 met;
      met.SetMagPhi(
          met_magnitude.At(0),
          met_phi.At(0)
      );
      if(c3){h_met->Fill(met.Mod());}

  } // end of reader.Next


  //////////////////////////////////////////////////////////////////////////////
  //////////////// Save histograms to .root files:
  string rootname = "/afs/cern.ch/user/c/chugli/private/histos/histo_dyn_c3_" +f_type+"_"+f+".root";
  const char* foutname = rootname.c_str();
  cout << foutname << endl;
  auto f1 = TFile::Open(foutname, "RECREATE");
  h_met->Write();
  h_LgenJet_pt->Write();
  // h_LgenJet_eta->Write();
  // h_genJet_pt->Write();
  // h_genJet_eta->Write();
  f1->Close();
}
