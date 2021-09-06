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
// 1) It produces histograms for the dynamics (met, jet pt,...) for the paper comparison
// 2) It saves them to .root
// root -q signal_dyn_paper.cc+
////////////////////////////////////////////////////////////////////////////////

double dphi(double A, double B);
void make_efficiency(TString filename, string f_type, string f, double ntot_t, bool higgsino);
void make_wino();
void make_higgsino();

void signal_dyn_paper(){
  make_wino();
  make_higgsino();
}

void make_efficiency(TString filename, string f_type, string f, double ntot_t, bool higgsino){
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


  TH1D* h_met  = new TH1D("h_met",  "met; met p_T [GeV]; Number of entries",            25, 0, 5000);
  TH1D* h_pt   = new TH1D("h_pt",   "LgenJet_pt; LgenJet p_T [GeV]; Number of entries", 25, 0, 5000);
  TH1D* hh_met = new TH1D("hh_met", "met; met p_T [GeV]; Number of entries",            25, 0, 5000);
  TH1D* hh_pt  = new TH1D("hh_pt",  "LgenJet_pt; LgenJet p_T [GeV]; Number of entries", 25, 0, 5000);


  ////////////// Reader Loop:
  int counter_veto = 0;
  int counter_phi = 0;
  int counter_veto_phi = 0;
  int counter_tot = 0;
  int counter = 0;
  ////// Check the number of signal after each cut:
  int c_tot = 0;
  int c_veto = 0;
  int c_met = 0;
  int c_pt = 0;
  int c_phi = 0;
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

      // Reco MET
      TVector2 met;
      met.SetMagPhi(
          met_magnitude.At(0),
          met_phi.At(0)
      );

      // Loop over reco jets
      int n_jets = jets_px.GetSize();
      double jet_leading_pt = 0;
      double jet_leading_phi = 0;
      double delta_phi = 100;
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
            jet_leading_phi  = p4.Phi();
          }
          // delta_phi = min(delta_phi,dphi(p4.Phi(),dphi(met.Phi(),0)));
          if(p4.Pt()>100){delta_phi = min(delta_phi,abs(dphi(p4.Phi(),dphi(met.Phi(),0))));}
      }
      // delta_phi = abs(dphi(jet_leading_phi,dphi(met.Phi(),0)));

      if(c3){
        c_veto++;
        if(met.Mod() > 4000){
          c_met++;
          if(jet_leading_pt >1000){
            c_pt++;
            if(abs(delta_phi)>0.5){c_phi++;}
          }
        }
      }

      if(met.Mod() > 4000 && jet_leading_pt >1000){
        if(c3){counter_veto++;}
        if(abs(delta_phi)>0.5){counter_phi++;}
        if(c3 && abs(delta_phi)>0.5){counter_veto_phi++;}
        counter_tot++;
      }

      // if(c3 && abs(delta_phi)>0.5){
      //     h_met->Fill(met.Mod());
      //     h_pt->Fill(jet_leading_pt);
      // }
      if(c3){
          h_met->Fill(met.Mod());
          h_pt->Fill(jet_leading_pt);
      }
      hh_met->Fill(met.Mod());
      hh_pt->Fill(jet_leading_pt);

      counter++;
      if(counter%100000==0){
        cout << "Entry: " << counter << endl;
      }
  } // end of reader.Next


  //////////////////////////////////////////////////////////////////////////////
  /////////// Calculate histograms:
  // leading jet pt:
  TH1D* hh_pt_tot = (TH1D*)hh_pt->Clone("hh_pt_tot");
  hh_pt_tot->Scale(1./hh_pt->GetEntries());
  hh_pt_tot->Scale(ntot_t);

  TH1D* h_pt_e = (TH1D*)h_pt->Clone("h_pt_e");
  h_pt_e->Divide(hh_pt);

  TH1D* h_pt_n = (TH1D*)h_pt_e->Clone("h_pt_n");
  h_pt_n->Multiply(hh_pt_tot);

  // MET:
  TH1D* hh_met_tot = (TH1D*)hh_met->Clone("hh_met_tot");
  hh_met_tot->Scale(1./hh_met->GetEntries());
  hh_met_tot->Scale(ntot_t);

  TH1D* h_met_e = (TH1D*)h_met->Clone("h_met_e");
  h_met_e->Divide(hh_met);

  TH1D* h_met_n = (TH1D*)h_met_e->Clone("h_met_n");
  h_met_n->Multiply(hh_met_tot);

  cout << "*********************************************************" << endl;
  cout << "Total counter: " << counter_tot << endl;
  cout << "Passing veto: " << counter_veto << endl;
  cout << "Passing phi: " << counter_phi << endl;
  cout << "Passing veto and phi: " << counter_veto_phi << endl;
  cout <<"---------------------------------------------------------------------" << endl << endl;
  cout << "Total counter: " << c_tot << endl;
  cout << "Total predicted: " << ntot_t << endl;
  cout << "Passing lepton veto: " << c_veto << endl;
  cout << "Passing lepton veto and met cut: " << c_met << endl;
  cout << "Passing lepton veto, met and pt cut: " << c_pt << endl;
  cout << "Passing lepton veto, met, pt and phi cut: " << c_phi << endl;
  cout <<"*********************************************************" << endl << endl;

  //////////////////////////////////////////////////////////////////////////////
  //////////////// Save histograms to .root files:
  string rootname;
  if(higgsino){rootname = "/afs/cern.ch/user/c/chugli/private/fast_sim/histos/histo_dyn_c3_higgsino__" +f_type+"_"+f+".root";}
  else{rootname = "/afs/cern.ch/user/c/chugli/private/fast_sim/histos/histo_dyn_c3_" +f_type+"_"+f+".root";}
  const char* foutname = rootname.c_str();
  cout << foutname << endl;
  auto f1 = TFile::Open(foutname, "RECREATE");
  h_met     ->Write(); // histogram with just the sample number of events with lepton veto
  h_pt      ->Write(); // histogram with just the sample number of events with lepton veto
  hh_pt     ->Write(); // histogram with just the sample number without any selection
  hh_met    ->Write(); // histogram with just the sample number without any selection
  hh_pt_tot ->Write(); // histogram with the expected number of events without any selection
  hh_met_tot->Write(); // histogram with the expected number of events without any selection
  h_pt_e    ->Write(); // histogram with the efficiency of the lepton selection
  h_met_e   ->Write(); // histogram with the efficiency of the lepton selection
  h_pt_n    ->Write(); // histogram with the expected number of events with lepton veto
  h_met_n   ->Write(); // histogram with the expected number of events with lepton veto
  f1->Close();
}

void make_wino(){
  // string f_start = "/home/saito/datafiles/FCC/AMSB_EW/renamed/mAMSB_"; // on login.icepp.jp
  string f_start = "/eos/user/m/masaito/FCC/AMSB_EW/mAMSB_"; //on lxplus
  string f_type1  = "C1N1";
  string f_type2  = "C1C1";
  string f_middle[40];

  ////////////////////////////////////////////////////////////////////////////
  ////////////// Extract total number of expected events:
  cout << "Start reading Nr_Events_signal.txt" << endl;
  ifstream MyReadFile("/afs/cern.ch/user/c/chugli/private/fast_sim/txt/Nr_Events_signal.txt"); // Read from the text file
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
    }else if(counter >= 82){
      break;
    }
    counter++;
  }
  MyReadFile.close();
  //// end of extract events

  for (int i = 0; i < 40; i++){
      f_middle[i] = to_string(700+100*i);
      double y = 700+100*i;
      if(y==3000 || y==1000){
          make_efficiency(f_start,f_type1,f_middle[i],n_tot1[i],false);
          make_efficiency(f_start,f_type2,f_middle[i],n_tot2[i],false);
      }
  }
}

void make_higgsino(){
  // string f_start = "/home/saito/datafiles/FCC/AMSB_EW/renamed/mAMSB_"; // on login.icepp.jp
  string f_start = "/eos/user/m/masaito/FCC/AMSB_EW/mAMSB_"; //on lxplus
  string f_type1  = "C1N1";
  string f_type2  = "C1C1";
  string f_middle[9];

  ////////////////////////////////////////////////////////////////////////////
  ////////////// Extract total number of expected events:
  cout << "Start reading Nr_Events_signal_higgsino.txt" << endl;
  ifstream MyReadFile("/afs/cern.ch/user/c/chugli/private/txt/Nr_Events_signal_higgsino.txt"); // Read from the text file
  string s;
  string delimiter = ",";
  int counter = 0;
  int i = 0, i1=0, i2=0;
  Int_t n = 9;
  Double_t n_tot1[n], n_tot2[n];
  while (getline (MyReadFile, s)) {
    if(counter>1 && counter < 20){
      size_t found1 = s.find(delimiter,0);
      size_t found2 = s.find(delimiter,found1+1);
      string s1 = s.substr(0, found1); // mass
      string s2 = s.substr(found1+2, found2-found1-2); // BG type
      string s3 = s.substr(found2+2,-3); // # events
      if(i%2==0){n_tot1[i1]= stod(s3);i1++;}
      else{n_tot2[i2]= stod(s3);i2++;}
      i++;
      cout << "s: " << s << endl;
      cout << "s1: " << s1 << endl;
      cout << "s2: " << s2 << endl;
      cout << "s3: " << s3 << endl;
    }else if(counter >= 20){
      break;
    }
    counter++;
  }
  MyReadFile.close();
  //// end of extract events


  for (int i = 0; i < 9; i++){
      f_middle[i] = to_string(700+100*i);
      double y = 700+100*i;
      if(y==1000){
          make_efficiency(f_start,f_type1,f_middle[i],n_tot1[i],true);
          make_efficiency(f_start,f_type2,f_middle[i],n_tot2[i],true);
      }
  }
}

double dphi(double A, double B){
  double delta_phi = A-B;
  if(delta_phi>=M_PI){delta_phi = delta_phi-2*M_PI;}
  else if(delta_phi<-M_PI){delta_phi = delta_phi+2*M_PI;}
  return delta_phi;
}
