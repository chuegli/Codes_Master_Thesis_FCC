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
////////////////////////////////////////////////////////////////////////////////

double dphi(double A, double B);
void make_efficiency(TString filename, string f_type, string f, double ntot_t, bool higgsino);
void make_wino();
void make_higgsino();

void signal_kin(){
    // make_wino();
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

  TH2D* h2   = new TH2D("h2", "h2", 1e3,0,1e4,1e3,0,1e4);

  //// Some kinematic histograms:
  TH1D* h_events_HT                = new TH1D("h_events_HT",           "h_events_HT;           HT [GeV]; Entries / 500 GeV",             500, 0, 1e5);
  TH1D* h_events_LJetpt            = new TH1D("h_events_LJetpt",       "h_events_LJetpt;       Leading jet pt [GeV]; Entries / 500 GeV", 500, 0, 1e5);
  TH1D* h_events_chargino_eta      = new TH1D("h_events_chargino_eta", "h_events_chargino_eta; chargino_eta []; Entries",                100, -1.5, 1.5);

  TH1D* h_betagamma = new TH1D("h_betagamma", "h_betagamma; betagamma;               Entries", 60, 0, 60); // number of events in the sample
  TH1D* h_prob      = new TH1D("h_prob",      "h_prob;      prob chargino detection per event; Entries", 100, 0, 1); // number of events chargino reco

  TH2D* h2_e_HT           = new TH2D("h2_e_HT",           "h2_e_HT;           HT [GeV]; Entries / 500 GeV",             500, 0, 1e5, 100, 0, 1);
  TH2D* h2_e_LJetpt       = new TH2D("h2_e_LJetpt",       "h2_e_LJetpt;       Leading jet pt [GeV]; Entries / 500 GeV", 500, 0, 1e5, 100, 0, 1);
  TH2D* h2_e_chargino_eta = new TH2D("h2_e_chargino_eta", "h2_e_chargino_eta; chargino_eta []; Entries",                100, -10, 10, 100, 0, 1);




  ////////////// Reader Loop:
  double totbetagamma     = 0;
  double tot_charginos    = 0;
  double tot_charginos_eta= 0;
  double tot_events       = 0;
  double e_counter        = 0;
  double e_counter_single = 0;

  double lifetime;
  if(higgsino){lifetime = 0.023e-9;}
  else{lifetime = 0.2e-9;}

  while(reader.Next()){
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

    ////////////////////////////////////////////////////////////////////////////
    /////// MET:
    TVector2 met;
    met.SetMagPhi(
        met_magnitude.At(0),
        met_phi.At(0)
    );

    ////////////////////////////////////////////////////////////////////////////
    /////// Leading jet pt:
    int n_jets = jets_px.GetSize();
    double jet_leading_pt = 0;
    double jet_HT = 0;
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
        if(abs(p4.Pt())>jet_leading_pt){
          jet_leading_pt  = abs(p4.Pt());
        }
        jet_HT = jet_HT + p4.Pt();
        // delta_phi = min(delta_phi,abs(dphi(p4.Phi(),dphi(met.Phi(),0))));
        if(p4.Pt()>100){delta_phi = min(delta_phi,abs(dphi(p4.Phi(),dphi(met.Phi(),0))));}
    }


    // Loop over truth (generated) particles
    int n_genParticles = genParticles_px.GetSize();

    double w = 0;
    int check = 0;
    for(int i=0; i<n_genParticles; i++){
        if(genParticles_status.At(i) != 1) continue;

        TLorentzVector p4;
        p4.SetXYZM(
            genParticles_px.At(i),
            genParticles_py.At(i),
            genParticles_pz.At(i),
            genParticles_mass.At(i)
        );

        // Filter charged wino
        if(abs(genParticles_pdgId.At(i)) == 1000024){tot_charginos++;}
        if(abs(genParticles_pdgId.At(i)) == 1000024 && abs(p4.Eta())<1.0){
          check++;
          double tau = lifetime;
          double c = 299792458; // m/s
          double s = 0.15;
          double betagamma = p4.Beta()*p4.Gamma();
          double min_time = s/(betagamma*c)/sin(p4.Theta()); // s
          double prob = exp(-min_time/tau);
          totbetagamma += betagamma*sin(p4.Theta());
          tot_charginos_eta++;

          w = 1-(1-w)*(1-prob);
          if(c3){
            e_counter_single+=prob;
            h2_e_chargino_eta->Fill(p4.Eta(),prob);
            h_events_chargino_eta->Fill(p4.Eta(),prob);
          }

          h_betagamma->Fill(betagamma);
        }
    } // end of loop over generator particles
    if(c3 && abs(delta_phi)>0.5){
      h2->Fill(jet_leading_pt, met.Mod(), w);
      e_counter+=w;

      h_prob->Fill(w);
      h2_e_HT->Fill(jet_HT,w);
      h2_e_LJetpt->Fill(jet_leading_pt,w);
      h_events_HT->Fill(jet_HT,w);
      h_events_LJetpt->Fill(jet_leading_pt,w);
    }
    tot_events++;

  } // end of reader.Next


  //////////////////////////////////////////////////////////////////////////////
  /////////// Calculate histograms:
  cout << endl << "TEST: " << h2->Integral(0,1e3,0,1e3) << ", e_counter: " << e_counter<< ", entries: " << tot_events;

  TH2D* h2_pred = (TH2D*)h2->Clone("h2_pred");
  h2_pred->Scale(1./tot_events);
  h2_pred->Scale(ntot_t);

  h_events_HT->Scale(1./tot_events);
  h_events_HT->Scale(ntot_t);

  h_events_LJetpt->Scale(1./tot_events);
  h_events_LJetpt->Scale(ntot_t);

  h_events_chargino_eta->Scale(1./tot_events);
  h_events_chargino_eta->Scale(ntot_t);

  h2_e_HT->Scale(1./tot_events);
  h2_e_LJetpt->Scale(1./tot_events);
  h2_e_chargino_eta->Scale(1./tot_charginos);

  cout << "  dopo: " << h2_pred->Integral(0,1e3,0,1e3) << endl << endl;

  //////////////////////////////////////////////////////////////////////////////
  //////////////// Save histograms to .root files:
  cout << "Write to .root" << endl;
  string rootname;
  if(higgsino){rootname = "/afs/cern.ch/user/c/chugli/private/fast_sim/histos/histo_kin_higgsino_" +f_type+"_"+f+".root";}
  else{rootname = "/afs/cern.ch/user/c/chugli/private/fast_sim/histos/histo_kin_" +f_type+"_"+f+".root";}
  const char* foutname = rootname.c_str();
  cout << foutname << endl;
  auto f1 = TFile::Open(foutname, "RECREATE");
  h2_pred->Write();
  h2_e_HT               ->Write();
  h_events_HT           ->Write();
  h2_e_LJetpt           ->Write();
  h_events_LJetpt       ->Write();
  h2_e_chargino_eta     ->Write();
  h_events_chargino_eta ->Write();
  h_betagamma           ->Write();
  h_prob                ->Write();
  f1->Close();

  //// Write things to a .txt:
  double m_betagamma = totbetagamma/tot_charginos;
  ostringstream streamObj1;
  streamObj1 << m_betagamma;
  string m_betagamma_s = streamObj1.str();

  ostringstream streamObj2;
  streamObj2 << h2_pred->GetEntries();
  string entries = streamObj2.str();

  ostringstream streamObj3;
  streamObj3 << h2_pred->Integral();
  string integral_entries = streamObj3.str();

  ostringstream streamObj4;
  streamObj4 << e_counter;
  string e_counter_s = streamObj4.str();

  ostringstream streamObj5;
  streamObj5 << e_counter_single;
  string e_counter_single_s = streamObj5.str();

  ofstream MyFile;
  string extra;
  if(higgsino){extra = "higgsino";}
  else{extra = "wino";}
  string myname = "/afs/cern.ch/user/c/chugli/private/fast_sim/txt/"+extra+"_arrays.txt";
  cout << "Write to "<< myname << endl;
  MyFile.open(myname.c_str(), ios_base::app); // Create and open a text file
  string mystring = f + ", " + f_type + ", " + m_betagamma_s + ", " + \
  to_string(tot_charginos) + ", " + to_string(tot_charginos_eta) + ", " + to_string(tot_events) + ", " + entries \
  + ", " + integral_entries + ", " + e_counter_s + ", " + e_counter_single_s + "\n";
  MyFile << mystring;
  MyFile.close();

  // TCanvas *canvas = new TCanvas("c","");
  // canvas->SetGrid();
  // gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
  // gStyle->SetOptStat(0);
  // string ss2 = "/afs/cern.ch/user/c/chugli/private/plots/kinematic_selection/effi_"+extra+"_"+f_type+"_"+f+".pdf";
  // effi->Draw("colz");
  // gPad->Update();
  // effi->SetTitle("Effi ; Leading jet p_T selection [GeV]; MET selection [GeV]");
  // effi->GetYaxis()->SetLabelSize(0.05);
  // effi->GetXaxis()->SetLabelSize(0.05);
  // effi->GetYaxis()->SetTitleSize(0.05);
  // effi->GetXaxis()->SetTitleSize(0.05);
  // canvas->SaveAs(ss2.c_str());
  // canvas->Close();


  delete h2;
  delete h2_pred;
  delete h2_e_HT;
  delete h_events_HT;
  delete h2_e_LJetpt;
  delete h_events_LJetpt;
  delete h2_e_chargino_eta;
  delete h_events_chargino_eta;
  delete h_betagamma;
  delete h_prob;

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

  ofstream MyFile;
  string myname = "/afs/cern.ch/user/c/chugli/private/fast_sim/txt/wino_arrays.txt";
  MyFile.open(myname.c_str()); // Create and open a text file
  MyFile << "// mass, C1C1/C1N1, mean betagamma, tot_charginos, tot_charginos_eta, tot_events, \
  entries h2_pred, tot integral of histo, e_counter, e_counter_single \n";
  MyFile.close();

  for (int i = 0; i < 40; i++){
  // for (int i = 25; i < 40; i++){
      f_middle[i] = to_string(700+100*i);
      double y = 700+100*i;
      cout << y << endl;
      if(y==3000){
          make_efficiency(f_start,f_type1,f_middle[i],n_tot1[i],false);
          make_efficiency(f_start,f_type2,f_middle[i],n_tot2[i],false);
      }
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

  ofstream MyFile;
  string myname = "/afs/cern.ch/user/c/chugli/private/fast_sim/txt/higgsino_arrays.txt";
  MyFile.open(myname.c_str()); // Create and open a text file
  MyFile << "// mass, C1C1/C1N1, mean betagamma, tot_charginos, tot_charginos_eta, tot_events, \
  entries h2_pred, tot integral of histo, e_counter, e_counter_single \n";
  MyFile.close();

  for (int i = 0; i < 9; i++){
      f_middle[i] = to_string(700+100*i);
      double y = 700+100*i;
      if(y==1000){
          cout << "Total number: " << n_tot1[i] << ",  " << n_tot2[i] << endl;
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
