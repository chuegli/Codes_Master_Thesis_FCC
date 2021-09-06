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
#include <TH2D.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TStyle.h>

#include <math.h>
#include <typeinfo>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
///////////// What this .cc does:
// This .cc needs Nr_Events_signal.txt
//
// 1) Fills a 2D histogram of leading jet pt vs met with the finest possible scalaing (Events/10 GeV)
// 2) It scales it witht eh true numebr of events read from Nr_Events_signal.txt
// 3) It saves the histograms to .root files
//
// scp signal_kin_sel.cc chugli@lxplus.cern.ch:/afs/cern.ch/user/c/chugli/private/fast_sim/code/dyn/
// root -q signal_kin_sel.cc+
////////////////////////////////////////////////////////////////////////////////

double dphi(double A, double B);
void make_efficiency(TString filename, string f_type, string f, double ntot_t, bool higgsino);
void make_wino();
void make_higgsino();

void signal_kin_sel(){
    make_wino();
    make_higgsino();
    cout << "************* Finished ***************" << endl;
}

void make_efficiency(TString filename, string f_type, string f, double ntot_t, bool higgsino){
  TChain* myChain = new TChain("events");
  TString filename1;
  filename = filename+f_type+".";
  string f_end   = ".root";
  cout << "Current: " << f_type << ", " << f << endl;
  if(stod(f)<=1500){
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
  // Truth Particles
  TTreeReaderArray<float> genParticles_px(reader, "skimmedGenParticles.core.p4.px");
  TTreeReaderArray<float> genParticles_py(reader, "skimmedGenParticles.core.p4.py");
  TTreeReaderArray<float> genParticles_pz(reader, "skimmedGenParticles.core.p4.pz");
  TTreeReaderArray<float> genParticles_mass(reader, "skimmedGenParticles.core.p4.mass");
  TTreeReaderArray<int> genParticles_pdgId(reader, "skimmedGenParticles.core.pdgId");
  TTreeReaderArray<unsigned int> genParticles_status(reader, "skimmedGenParticles.core.status");
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

  TH1D* h_eta        = new TH1D("h_eta",       "; Leading jet #eta [ ];        Entries", 100, -6, 6);
  TH1D* h_phi        = new TH1D("h_phi",       "; Leading jet #phi [ ];        Entries", 100, -4, 4);
  TH1D* h_theta      = new TH1D("h_theta",     "; Leading jet #theta [ ];      Entries", 100, -1, 4);
  TH1D* h_beta       = new TH1D("h_beta",      "; Leading jet #beta [ ];       Entries", 100, 0.8, 1.1);
  TH1D* h_gamma      = new TH1D("h_gamma",     "; Leading jet #gamma [ ];      Entries", 100, 0, 5000);
  TH1D* h_betagamma  = new TH1D("h_betagamma", "; Leading jet #beta#gamma [ ]; Entries", 100, 0, 5000);
  TH1D* h_met        = new TH1D("h_met",       "; met p_T [GeV];               Entries", 100, 0, 5000);
  TH1D* h_met_phi    = new TH1D("h_met_phi",   "; met #phi [ ];                Entries", 100, -4, 4);
  TH1D* h_delta_phi  = new TH1D("h_delta_phi", "; #Delta #phi [ ];             Entries", 100, -1, 4);
  TH1D* h_delta_pt   = new TH1D("h_delta_pt",  "; #Delta p_T [GeV];            Entries", 100, 0, 7000);

  TH1D* c1h_eta        = new TH1D("c1h_eta",       "; Leading jet #eta [ ];        Cut MET entries", 100, -4, 4);
  TH1D* c1h_phi        = new TH1D("c1h_phi",       "; Leading jet #phi [ ];        Cut MET entries", 100, -4, 4);
  TH1D* c1h_theta      = new TH1D("c1h_theta",     "; Leading jet #theta [ ];      Cut MET entries", 100, -1, 4);
  TH1D* c1h_beta       = new TH1D("c1h_beta",      "; Leading jet #beta [ ];       Cut MET entries", 100, 0.9, 1.1);
  TH1D* c1h_gamma      = new TH1D("c1h_gamma",     "; Leading jet #gamma [ ];      Cut MET entries", 100, 0, 800);
  TH1D* c1h_betagamma  = new TH1D("c1h_betagamma", "; Leading jet #beta#gamma [ ]; Cut MET entries", 100, 0, 800);
  TH1D* c1h_met        = new TH1D("c1h_met",       "; met p_T [GeV];               Cut MET entries", 100, 3000, 10000);
  TH1D* c1h_met_phi    = new TH1D("c1h_met_phi",   "; met #phi [ ];                Cut MET entries", 100, -4, 4);
  TH1D* c1h_delta_phi  = new TH1D("c1h_delta_phi", "; #Delta #phi [ ];             Cut MET entries", 100, -1, 4);
  TH1D* c1h_delta_pt   = new TH1D("c1h_delta_pt",  "; #Delta p_T [GeV];            Cut MET entries", 100, 0, 10000);

  TH1D* c2h_eta        = new TH1D("c2h_eta",       "; Leading jet #eta [ ];        Cut LJet entries", 100, -4, 4);
  TH1D* c2h_phi        = new TH1D("c2h_phi",       "; Leading jet #phi [ ];        Cut LJet entries", 100, -4, 4);
  TH1D* c2h_theta      = new TH1D("c2h_theta",     "; Leading jet #theta [ ];      Cut LJet entries", 100, -1, 4);
  TH1D* c2h_beta       = new TH1D("c2h_beta",      "; Leading jet #beta [ ];       Cut LJet entries", 100, 0.9, 1.1);
  TH1D* c2h_gamma      = new TH1D("c2h_gamma",     "; Leading jet #gamma [ ];      Cut LJet entries", 100, 0, 1500);
  TH1D* c2h_betagamma  = new TH1D("c2h_betagamma", "; Leading jet #beta#gamma [ ]; Cut LJet entries", 100, 0, 1500);
  TH1D* c2h_met        = new TH1D("c2h_met",       "; met p_T [GeV];               Cut LJet entries", 100, 0, 10000);
  TH1D* c2h_met_phi    = new TH1D("c2h_met_phi",   "; met #phi [ ];                Cut LJet entries", 100, -4, 4);
  TH1D* c2h_delta_phi  = new TH1D("c2h_delta_phi", "; #Delta #phi [ ];             Cut LJet entries", 100, -1, 4);
  TH1D* c2h_delta_pt   = new TH1D("c2h_delta_pt",  "; #Delta p_T [GeV];            Cut LJet entries", 100, 0, 10000);

  //////// 2D histos:
  TH2D* Jh_eta        = new TH2D("Jh_eta",       "; Leading jet #eta [ ];        Leading jet p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
  TH2D* Jh_phi        = new TH2D("Jh_phi",       "; Leading jet #phi [ ];        Leading jet p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
  TH2D* Jh_theta      = new TH2D("Jh_theta",     "; Leading jet #theta [ ];      Leading jet p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
  TH2D* Jh_beta       = new TH2D("Jh_beta",      "; Leading jet #beta [ ];       Leading jet p_T [GeV]; Entries", 100, -1.2, 1.2,  100,0,5000);
  TH2D* Jh_gamma      = new TH2D("Jh_gamma",     "; Leading jet #gamma [ ];      Leading jet p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);
  TH2D* Jh_betagamma  = new TH2D("Jh_betagamma", "; Leading jet #beta#gamma [ ]; Leading jet p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);
  TH2D* Jh_met        = new TH2D("Jh_met",       "; met p_T [GeV];               Leading jet p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);
  TH2D* Jh_met_phi    = new TH2D("Jh_met_phi",   "; met #phi [ ];                Leading jet p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
  TH2D* Jh_delta_phi  = new TH2D("Jh_delta_phi", "; #Delta #phi [ ];             Leading jet p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
  TH2D* Jh_delta_pt   = new TH2D("Jh_delta_pt",  "; #Delta p_T [GeV];            Leading jet p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);

  TH2D* Mh_eta        = new TH2D("Mh_eta",       "; Leading jet #eta [ ];        MET p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
  TH2D* Mh_phi        = new TH2D("Mh_phi",       "; Leading jet #phi [ ];        MET p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
  TH2D* Mh_theta      = new TH2D("Mh_theta",     "; Leading jet #theta [ ];      MET p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
  TH2D* Mh_beta       = new TH2D("Mh_beta",      "; Leading jet #beta [ ];       MET p_T [GeV]; Entries", 100, -1.2, 1.2,  100,0,5000);
  TH2D* Mh_gamma      = new TH2D("Mh_gamma",     "; Leading jet #gamma [ ];      MET p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);
  TH2D* Mh_betagamma  = new TH2D("Mh_betagamma", "; Leading jet #beta#gamma [ ]; MET p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);
  TH2D* Mh_met        = new TH2D("Mh_met",       "; met p_T [GeV];               MET p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);
  TH2D* Mh_met_phi    = new TH2D("Mh_met_phi",   "; met #phi [ ];                MET p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
  TH2D* Mh_delta_phi  = new TH2D("Mh_delta_phi", "; #Delta #phi [ ];             MET p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
  TH2D* Mh_delta_pt   = new TH2D("Mh_delta_pt",  "; #Delta p_T [GeV];            MET p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);


  ////////////// Reader Loop:
  int counter = 0;
  int counter_veto = 0;
  int counter_phi = 0;
  int counter_veto_phi = 0;
  int counter_tot = 0;
  ////// Check the number of signal after each cut:
  int c_tot = 0;
  int c_veto = 0;
  int c_met = 0;
  int c_pt = 0;
  int c_phi = 0;
  while(reader.Next()){
    c_tot++;
    counter++;
    ////////////////////////////////////////////////////////////////////////////
    //////// Lepton veto:
    bool c3 = true;
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

    TVector2 met;
    met.SetMagPhi(
        met_magnitude.At(0),
        met_phi.At(0)
    );

    /////// Leading jet pt:
    int n_jets = jets_px.GetSize();
    double L_pt    = 0;
    double L_phi   = 0;
    double L_eta   = 0;
    double L_theta = 0;
    double L_beta  = 0;
    double L_gamma = 0;
    double delta_phi = 100;
    for(int i=0; i<n_jets; i++){
        TLorentzVector p4;
        p4.SetXYZM(
            jets_px.At(i),
            jets_py.At(i),
            jets_pz.At(i),
            jets_mass.At(i)
        );
        if(p4.Pt()>L_pt){
          L_pt    = p4.Pt();
          L_phi   = p4.Phi();
          L_eta   = p4.Eta();
          L_theta = p4.Theta();
          L_beta  = p4.Beta();
          L_gamma = p4.Gamma();
        }
        // delta_phi = min(delta_phi,abs(dphi(p4.Phi(),dphi(met.Phi(),0))));
        // delta_phi = min(delta_phi,abs(dphi(p4.Phi(),dphi(met.Phi(),M_PI))));
        if(p4.Pt()>100){delta_phi = min(delta_phi,abs(dphi(p4.Phi(),dphi(met.Phi(),0))));}
    }
    // delta_phi = abs(dphi(L_phi,dphi(met.Phi(),0)));

    if(c3){
      c_veto++;
      if(met.Mod() > 4000){
        c_met++;
        if(L_pt >1000){
          c_pt++;
          if(abs(delta_phi)>0.5){c_phi++;}
        }
      }
    }

    if(met.Mod() > 4000 && L_pt >1000){
      if(c3){counter_veto++;}
      if(abs(delta_phi)>0.5){counter_phi++;}
      if(c3 && abs(delta_phi)>0.5){counter_veto_phi++;}
      counter_tot++;
    }

    if(c3){
      h_eta      ->Fill(L_eta);
      h_phi      ->Fill(L_phi);
      h_theta    ->Fill(L_theta);
      h_beta     ->Fill(L_beta);
      h_gamma    ->Fill(L_gamma);
      h_betagamma->Fill(L_beta*L_gamma);
      h_met      ->Fill(met.Mod());
      h_met_phi  ->Fill(dphi(met.Phi(),0));
      h_delta_phi->Fill(delta_phi);
      h_delta_pt ->Fill(abs(met.Mod()-L_pt));
      Jh_eta      ->Fill(L_eta,L_pt);
      Jh_phi      ->Fill(L_phi,L_pt);
      Jh_theta    ->Fill(L_theta,L_pt);
      Jh_beta     ->Fill(L_beta,L_pt);
      Jh_gamma    ->Fill(L_gamma,L_pt);
      Jh_betagamma->Fill(L_beta*L_gamma,L_pt);
      Jh_met      ->Fill(met.Mod(),L_pt);
      Jh_met_phi  ->Fill(dphi(met.Phi(),0),L_pt);
      Jh_delta_phi->Fill(delta_phi,L_pt);
      Jh_delta_pt ->Fill(abs(met.Mod()-L_pt),L_pt);
      Mh_eta      ->Fill(L_eta,met.Mod());
      Mh_phi      ->Fill(L_phi,met.Mod());
      Mh_theta    ->Fill(L_theta,met.Mod());
      Mh_beta     ->Fill(L_beta,met.Mod());
      Mh_gamma    ->Fill(L_gamma,met.Mod());
      Mh_betagamma->Fill(L_beta*L_gamma,met.Mod());
      Mh_met      ->Fill(met.Mod(),met.Mod());
      Mh_met_phi  ->Fill(dphi(met.Phi(),0),met.Mod());
      Mh_delta_phi->Fill(delta_phi,met.Mod());
      Mh_delta_pt ->Fill(abs(met.Mod()-L_pt),met.Mod());
      if(met.Mod()>3500){
        c1h_eta      ->Fill(L_eta);
        c1h_phi      ->Fill(L_phi);
        c1h_theta    ->Fill(L_theta);
        c1h_beta     ->Fill(L_beta);
        c1h_gamma    ->Fill(L_gamma);
        c1h_betagamma->Fill(L_beta*L_gamma);
        c1h_met      ->Fill(met.Mod());
        c1h_met_phi  ->Fill(dphi(met.Phi(),0));
        c1h_delta_phi->Fill(delta_phi);
        c1h_delta_pt ->Fill(abs(met.Mod()-L_pt));
      }
      if(met.Mod()>3500 && L_pt>3500){
        c2h_eta      ->Fill(L_eta);
        c2h_phi      ->Fill(L_phi);
        c2h_theta    ->Fill(L_theta);
        c2h_beta     ->Fill(L_beta);
        c2h_gamma    ->Fill(L_gamma);
        c2h_betagamma->Fill(L_beta*L_gamma);
        c2h_met      ->Fill(met.Mod());
        c2h_met_phi  ->Fill(dphi(met.Phi(),0));
        c2h_delta_phi->Fill(delta_phi);
        c2h_delta_pt ->Fill(abs(met.Mod()-L_pt));
      }
    }
  } // end of reader.Next

  cout << "*********************************************************" << endl;
  cout << "Total counter: " << counter_tot << endl;
  cout << "Passing veto: " << counter_veto << endl;
  cout << "Passing phi: " << counter_phi << endl;
  cout << "Passing veto and phi: " << counter_veto_phi << endl;
  cout << "Super total: " << counter << endl;
  cout <<"---------------------------------------------------------------------" << endl << endl;
  cout << "Total counter: " << c_tot << endl;
  cout << "Passing lepton veto: " << c_veto << endl;
  cout << "Passing lepton veto and met cut: " << c_met << endl;
  cout << "Passing lepton veto, met and pt cut: " << c_pt << endl;
  cout << "Passing lepton veto, met, pt and phi cut: " << c_phi << endl;
  cout <<"*********************************************************" << endl << endl;

  //////////////////////////////////////////////////////////////////////////////
  //////////////// Save histograms to .root files:
  cout << "Write to .root" << endl;
  string rootname;
  if(higgsino){rootname = "/afs/cern.ch/work/c/chugli/private/fast_sim/histo_kin_sel_higgsino_" +f_type+"_"+f+".root";}
  else{rootname = "/afs/cern.ch/work/c/chugli/private/fast_sim/histo_kin_sel_" +f_type+"_"+f+".root";}
  const char* foutname = rootname.c_str();
  cout << foutname << endl;
  auto f1 = TFile::Open(foutname, "RECREATE");
  h_eta        ->Write();
  h_phi        ->Write();
  h_theta      ->Write();
  h_beta       ->Write();
  h_gamma      ->Write();
  h_betagamma  ->Write();
  h_met        ->Write();
  h_met_phi    ->Write();
  h_delta_phi  ->Write();
  h_delta_pt   ->Write();
  Jh_eta       ->Write();
  Jh_phi       ->Write();
  Jh_theta     ->Write();
  Jh_beta      ->Write();
  Jh_gamma     ->Write();
  Jh_betagamma ->Write();
  Jh_met       ->Write();
  Jh_met_phi   ->Write();
  Jh_delta_phi ->Write();
  Jh_delta_pt  ->Write();
  Mh_eta       ->Write();
  Mh_phi       ->Write();
  Mh_theta     ->Write();
  Mh_beta      ->Write();
  Mh_gamma     ->Write();
  Mh_betagamma ->Write();
  Mh_met       ->Write();
  Mh_met_phi   ->Write();
  Mh_delta_phi ->Write();
  Mh_delta_pt  ->Write();
  c1h_eta      ->Write();
  c1h_phi      ->Write();
  c1h_theta    ->Write();
  c1h_beta     ->Write();
  c1h_gamma    ->Write();
  c1h_betagamma->Write();
  c1h_met      ->Write();
  c1h_met_phi  ->Write();
  c1h_delta_phi->Write();
  c1h_delta_pt ->Write();
  c2h_eta      ->Write();
  c2h_phi      ->Write();
  c2h_theta    ->Write();
  c2h_beta     ->Write();
  c2h_gamma    ->Write();
  c2h_betagamma->Write();
  c2h_met      ->Write();
  c2h_met_phi  ->Write();
  c2h_delta_phi->Write();
  c2h_delta_pt ->Write();
  f1->Close();

  delete h_eta        ;
  delete h_phi        ;
  delete h_theta      ;
  delete h_beta       ;
  delete h_gamma      ;
  delete h_betagamma  ;
  delete h_met        ;
  delete h_met_phi    ;
  delete h_delta_phi  ;
  delete h_delta_pt   ;
  delete Jh_eta       ;
  delete Jh_phi       ;
  delete Jh_theta     ;
  delete Jh_beta      ;
  delete Jh_gamma     ;
  delete Jh_betagamma ;
  delete Jh_met       ;
  delete Jh_met_phi   ;
  delete Jh_delta_phi ;
  delete Jh_delta_pt  ;
  delete Mh_eta       ;
  delete Mh_phi       ;
  delete Mh_theta     ;
  delete Mh_beta      ;
  delete Mh_gamma     ;
  delete Mh_betagamma ;
  delete Mh_met       ;
  delete Mh_met_phi   ;
  delete Mh_delta_phi ;
  delete Mh_delta_pt  ;
  delete c1h_eta      ;
  delete c1h_phi      ;
  delete c1h_theta    ;
  delete c1h_beta     ;
  delete c1h_gamma    ;
  delete c1h_betagamma;
  delete c1h_met      ;
  delete c1h_met_phi  ;
  delete c1h_delta_phi;
  delete c1h_delta_pt ;
  delete c2h_eta      ;
  delete c2h_phi      ;
  delete c2h_theta    ;
  delete c2h_beta     ;
  delete c2h_gamma    ;
  delete c2h_betagamma;
  delete c2h_met      ;
  delete c2h_met_phi  ;
  delete c2h_delta_phi;
  delete c2h_delta_pt ;

}

////////////////////////////////////////////////////////////////////////////////
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
      cout << y << endl;
      make_efficiency(f_start,f_type1,f_middle[i],n_tot1[i],false);
      make_efficiency(f_start,f_type2,f_middle[i],n_tot2[i],false);
  }
} // end make_wino()

///////////////////////////////////////////////////////////////////////////////
void make_higgsino(){
  // string f_start = "/home/saito/datafiles/FCC/AMSB_EW/renamed/mAMSB_"; // on login.icepp.jp
  string f_start = "/eos/user/m/masaito/FCC/AMSB_EW/mAMSB_"; //on lxplus
  string f_type1  = "C1N1";
  string f_type2  = "C1C1";
  string f_middle[9];

  ////////////////////////////////////////////////////////////////////////////
  ////////////// Extract total number of expected events:
  cout << "Start reading Nr_Events_signal_higgsino.txt" << endl;
  ifstream MyReadFile("/afs/cern.ch/user/c/chugli/private/fast_sim/txt/Nr_Events_signal_higgsino.txt"); // Read from the text file
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
      make_efficiency(f_start,f_type1,f_middle[i],n_tot1[i],true);
      make_efficiency(f_start,f_type2,f_middle[i],n_tot2[i],true);
  }
}

double dphi(double A, double B){
  double delta_phi = A-B;
  if(delta_phi>M_PI){delta_phi = delta_phi-2*M_PI;}
  else if(delta_phi<-M_PI){delta_phi = delta_phi+2*M_PI;}
  return delta_phi;
}
