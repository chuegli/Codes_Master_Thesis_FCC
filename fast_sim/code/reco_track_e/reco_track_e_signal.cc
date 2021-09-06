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

#include <math.h>
#include <typeinfo>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
///////////// What this .cc does:
// This .cc concerns the signal samples only.
//
// 1) It calculates the efficiency for chargino track reconstruction
// It assumes: chargino lifetime = 0.2 ns and a chargino will be reconstructed
// if it decays after radius = 150 mm.
//
// attention 1: the decay has an exponential distribution !!!
// attention 2: the silicon tracker is cylindrical not spherical
////////////////////////////////////////////////////////////////////////////////


double make_efficiency(TString filename, string f_type, string f, double ntot_t);
void make_wino();
void make_higgsino();

void reco_track_e_signal(){
  make_wino();
  make_higgsino();
}

///////////////////////////////////////////////////////////////////////////////
//////////////// Functions:

double make_efficiency(TString filename, string f_type, string f, double ntot_t, double lifetime){
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
  cout << "Entries: " << entries_start << endl;

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

  // TH1D* hist_n         = new TH1D("hist_n",         "hist_n;         HT [GeV];                Entries / 500 GeV", 500, 0, 1e5); // number of events in the sample
  // TH1D* hist_c1        = new TH1D("hist_c1",        "hist_c1;        HT [GeV];                Entries / 500 GeV", 500, 0, 1e5); // number of events chargino reco
  // TH1D* hist_gamma     = new TH1D("hist_gamma",     "hist_gamma;     gamma;                   Entries", 60, 0, 60); // number of events in the sample
  // TH1D* hist_betagamma = new TH1D("hist_betagamma", "hist_betagamma; betagamma;               Entries", 60, 0, 60); // number of events in the sample
  // TH1D* hist_prob      = new TH1D("hist_prob",      "hist_prob;      prob chargino detection; Entries", 100, 0, 1); // number of events chargino reco
  //
  // TH2D* h2_HT_betagamma = new TH2D("h2_HT_betagamma", "h2_HT_betagamma; HT [GeV]; betagamma",          100, 0, 1e5, 10, 0, 60);
  // TH2D* h2_HT_prob      = new TH2D("h2_HT_prob",      "h2_HT_prob; HT [GeV]; prob chargino detection", 100, 0, 1e5, 10, 0, 1);
  // TH2D* h2_HT_pt        = new TH2D("h2_HT_pt",       "h2_HT_ppt; HT [GeV]; chargino pt [GeV]",         100, 0, 1e5, 100, 0, 3e4);

  ////////////// Reader Loop:
  double e_counter = 0;
  double tot_counter = 0;
  while(reader.Next()){
    ////////////////////////////////////////////////////////////////////////////
    //////// Lepton veto:
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
    double jet_HT = 0;
    for(int i=0; i<n_jets; i++){
        TLorentzVector p4;
        p4.SetXYZM(
            jets_px.At(i),
            jets_py.At(i),
            jets_pz.At(i),
            jets_mass.At(i)
        );
        jet_HT = jet_HT + p4.Pt();
    } // lop over jets

    // Loop over truth (generated) particles
    int n_genParticles = genParticles_px.GetSize();
    double w = 0;
    int chargi = 0;
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
        if(abs(genParticles_pdgId.At(i)) == 1000024 && abs(p4.Eta())<1.0){
            chargi++;
            double tau = lifetime;
            double c = 299792458; // m/s
            double gamma = p4.Gamma();
            double beta = p4.Beta();
            double s = 0.15;
            double betagamma = beta*gamma;
            double min_time = s/(betagamma*c)/sin(p4.Theta()); // s
            double prob = exp(-min_time/tau);

            if(c3){w = 1-(1-w)*(1-prob);}

            /// histo filling:
            // hist_n->Fill(abs(jet_HT));
            // hist_c1->Fill(abs(jet_HT), prob);
            // hist_betagamma->Fill(betagamma);
            // hist_gamma->Fill(gamma);
            // hist_prob->Fill(prob);
            // h2_HT_betagamma->Fill(abs(jet_HT), betagamma);
            // h2_HT_prob->Fill(abs(jet_HT), prob);
            // h2_HT_pt->Fill(abs(jet_HT), p4.Pt());
        }
    } // end of loop over generator particles
    if(w!=0 && tot_counter>99980){cout << f_type << " w: " << w << endl;}
    e_counter += w;
    tot_counter++;
    // cout << e_counter << ", " << tot_counter << endl;
    // cout << "Number of charginos: " << chargi << endl;

  } // end of reader.Next
  cout << e_counter << ", " << tot_counter << endl;

  //////////////////////////////////////////////////////////////////////////////
  /////////// Calculate histograms:
  // TH1D* hist_ntot = (TH1D*)hist_n->Clone("hist_ntot");
  // hist_ntot->Scale(1./hist_n->GetEntries());
  // hist_ntot->Scale(ntot_t);
  //
  // TH1D* hist_e1 = (TH1D*)hist_c1->Clone("hist_e1");
  // hist_e1->Divide(hist_n);
  //
  // TH1D* hist_n1 = (TH1D*)hist_e1->Clone("hist_n1");
  // hist_n1->Multiply(hist_ntot);

  //////////////////////////////////////////////////////////////////////////////
  //////////////// Save histograms to .root files:
  // string rootname = "/afs/cern.ch/user/c/chugli/private/histos/histo_ch_reco" +f_type+"_"+f+".root";
  // const char* foutname = rootname.c_str();
  // cout << foutname << endl;
  // auto f2 = TFile::Open(foutname, "RECREATE");
  // hist_n->Write();
  // hist_ntot->Write();
  // hist_n1->Write();
  // hist_c1->Write();
  // hist_e1->Write();
  // hist_betagamma->Write();
  // hist_gamma->Write();
  // hist_prob->Write();
  // h2_HT_betagamma->Write();
  // h2_HT_prob->Write();
  // h2_HT_pt->Write();
  // f2->Close();
  // cout << e_counter << endl;
  // cout << tot_counter << endl;
  return e_counter/tot_counter;

} // end of make_efficiency

void make_wino(){
  string f_start = "/eos/user/m/masaito/FCC/AMSB_EW/mAMSB_"; //on lxplus
  string f_type1  = "C1N1";
  string f_type2  = "C1C1";
  string f_middle[40];
  double effi_C1C1[40], effi_C1N1[40], y[40], betagamma_C1C1[40], betagamma_C1N1[40];

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


  ofstream MyFile("/afs/cern.ch/user/c/chugli/private/txt/reco_track_e_signal_2.txt"); // Create and open a text file
  string mystring;

  MyFile << "// Signal for fast simulation \n";
  MyFile << "// The efficiency for chargino track reconstruction is saved here \n";
  MyFile << "// Assumed: chargino lifetime = 0.2 ns  and chargino is reconstructed if it decays in a radius >= 150 mm\n";
  MyFile << "// mass, efficiency for C1N1, efficiency for C1C1, betagamma for C1N1, betagamma for C1C1 \n";

  for (int i = 0; i < 40; i++){
      f_middle[i] = to_string(700+100*i);
      y[i] = 700+100*i;

      effi_C1N1[i] = make_efficiency(f_start,f_type1,f_middle[i],n_tot1[i],0.2e-9);
      effi_C1C1[i] = make_efficiency(f_start,f_type2,f_middle[i],n_tot2[i],0.2e-9);
      cout << effi_C1C1[i] << ", " << effi_C1N1[i] << endl;

      ostringstream streamObj; // use this to get scientific notation and rounding
      streamObj << effi_C1N1[i];
      string s1 = streamObj.str();
      ostringstream streamObj2;
      streamObj2 << effi_C1C1[i];
      string s2 = streamObj2.str();
      mystring = f_middle[i]+", "+s1+", "+s2+";"+"\n";
      MyFile << mystring;
  }
  MyFile.close();
}

void make_higgsino(){
  string f_start = "/eos/user/m/masaito/FCC/AMSB_EW/mAMSB_"; //on lxplus
  string f_type1  = "C1N1";
  string f_type2  = "C1C1";
  string f_middle[9];
  double effi_C1C1[9], effi_C1N1[9], y[9], betagamma_C1C1[9], betagamma_C1N1[9];

  ////////////////////////////////////////////////////////////////////////////
  ////////////// Extract total number of expected events:
  cout << "Start reading Nr_Events_signal_higgsino.txt" << endl;
  ifstream MyReadFile("/afs/cern.ch/user/c/chugli/private/txt/Nr_Events_signal_higgsino.txt"); // Read from the text file
  string s;
  string delimiter = ",";
  int counter = 0;
  int i = 0, i1=0, i2=0;
  Int_t n = 18;
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


  ofstream MyFile("/afs/cern.ch/user/c/chugli/private/txt/reco_track_e_signal_higgsino.txt"); // Create and open a text file
  string mystring;

  MyFile << "// Signal for fast simulation \n";
  MyFile << "// The efficiency for chargino track reconstruction is saved here \n";
  MyFile << "// Assumed: higgsino lifetime = 0.023 ns  and chargino is reconstructed if it decays in a radius >= 150 mm\n";
  MyFile << "// mass, efficiency for C1N1, efficiency for C1C1, betagamma for C1N1, betagamma for C1C1 \n";

  for (int i = 0; i < 9; i++){
      f_middle[i] = to_string(700+100*i);
      y[i] = 700+100*i;

      effi_C1N1[i] = make_efficiency(f_start,f_type1,f_middle[i],n_tot1[i], 0.023e-9);
      effi_C1C1[i] = make_efficiency(f_start,f_type2,f_middle[i],n_tot2[i], 0.023e-9);
      cout << effi_C1C1[i] << ", " << effi_C1N1[i] << endl;

      ostringstream streamObj; // use this to get scientific notation and rounding
      streamObj << effi_C1N1[i];
      string s1 = streamObj.str();
      ostringstream streamObj2;
      streamObj2 << effi_C1C1[i];
      string s2 = streamObj2.str();
      mystring = f_middle[i]+", "+s1+", "+s2+";"+"\n";
      MyFile << mystring;
  }
  MyFile.close();
}
