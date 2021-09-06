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
#include <map>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
///////////// What this .cc does:
// This .cc concerns the BG samples only.
// 1) It produces histograms for the lepton study (number of leptons, pt,..)
// 2) It saves them to .root files
////////////////////////////////////////////////////////////////////////////////

void list_files(string filename_t, string BGstring_t, string HTrange_s_t, double ntot_t);
void make_hist(TChain* myChain_t, string BGstring_t, string HTrange_s_t, double ntot_t);

void BG_lep(string BGstring) {
  //////////////////////////////////////////////////////////////////////////////
  ////////// Definitions:
  map<string, int> BGtype = {
    {"W+jets",0},
    {"Z+jets",1},
    {"ttbar",2},
    {"topsingle",3},
    {"multijets",4}
  };

  map<string,double> HTrange_ntot;

  string a[] = {"0_150", "150_300", "300_500", "500_1000", "1000_2000", "2000_5000", "5000_100000"};
  string c[] = {"0_600", "600_1200", "1200_2100", "2100_3400", "3400_5300", "5300_8100", "8100_15000",
  "15000_25000", "25000_35000", "35000_100000"};
  string d[] = {""};
  string e[] = {"0_500", "500_1000", "1000_2000", "2000_4000", "4000_7200", "7200_15000",
  "15000_25000", "25000_35000", "35000_100000"};
  string *myfolders[5] = {a,a,c,d,e};

  double da[] = {1479000, 83770, 24930, 10370, 1917, 273.7, 11.11}; //xsec in pb
  double db[] = {465800, 29440, 8958, 3756, 703.8, 102.3, 4.196};
  double dc[] = {32070, 8883, 1737, 284.3, 44.91, 6.484, 0.8583, 0.0219, 0.0004247, 1.459e-5};
  double dd[] = {7524};
  double de[] = {6517000000, 16420000, 1673000, 132000, 7316, 474.9, 7.349, 0.1759, 0.007654};
  double *myxsec[5] = {da,db,dc,dd,de};

  int mylength[5] = {7,7,10,1,9};

  int BGpos = BGtype[BGstring]; // corresponding index to BG type

  double lumi_int = 30e6; //pb-1 => since xsec also in pb-1

  string f_start  = "/eos/experiment/fcc/hh/generation/DelphesEvents/fcc_v02/"; //BG on lxplus

  string f_type[5] = {"mgp8_pp_w0123j_4f_HT_","mgp8_pp_z0123j_4f_HT_",
  "mgp8_pp_tt012j_5f_HT_","mgp8_pp_t123j_5f","mgp8_pp_jj012j_5f_HT_"};


  /////////////////////////////////////////////////////////////////////////////
  /////////////// Calculate the tot number of expected entries per HT range:
  for(int j=0; j<mylength[BGpos]; j++){
    double extra = myxsec[BGpos][j]*lumi_int;
    HTrange_ntot.insert(pair<string, double>(myfolders[BGpos][j], extra));
  }


  /////////////////////////////////////////////////////////////////////////////
  /////////////// Calculate the tot number of entries in the samples:
  for(int j = 0; j < mylength[BGpos]; j++){
    string filename = f_start+f_type[BGpos]+myfolders[BGpos][j]+"/";
    cout << "\nStart folder " << myfolders[BGpos][j] << endl;
    list_files(filename, BGstring, myfolders[BGpos][j], HTrange_ntot[myfolders[BGpos][j]]);
  }

} // close main



/////////////////////////////////////////////////////////////////////////////////
///////////////// Functions:
void list_files(string filename_t, string BGstring_t, string HTrange_s_t, double ntot_t){
  const char* dirname = filename_t.c_str();
  cout << dirname << endl;
  TSystemDirectory dir(dirname, dirname);
  TList* files = dir.GetListOfFiles();
  TChain* myChain = new TChain("events");
  if(files){
    TSystemFile* file;
    TString fname;
    TIter next(files);
    while ((file=(TSystemFile*)next())){
      fname = file->GetName();
      if(!file->IsDirectory() && fname.EndsWith(".root")){
        TString mys = dirname+fname;
        myChain->Add(mys);
      }
    } // end of while
    cout << "make histo start" << endl;
    make_hist(myChain, BGstring_t,  HTrange_s_t, ntot_t);
    files->Clear();
  } else{
    cout << endl << "Error in " << HTrange_s_t << endl << endl;
  }
}


void make_hist(TChain* myChain_t, string BGstring_t, string HTrange_s_t, double ntot_t){
  double entries_start = myChain_t->GetEntries();
  cout << "Entries in myChain: " << entries_start << endl;

  ////////////// TTreeReader
  TTreeReader reader(myChain_t);
  // Reco MET
  TTreeReaderArray<float> met_magnitude(reader, "met.magnitude");
  TTreeReaderArray<float> met_phi(reader, "met.phi");
  // Reco Jet
  TTreeReaderArray<float> jets_px(  reader, "genjets04.core.p4.px");
  TTreeReaderArray<float> jets_py(  reader, "genjets04.core.p4.py");
  TTreeReaderArray<float> jets_pz(  reader, "genjets04.core.p4.pz");
  TTreeReaderArray<float> jets_mass(reader, "genjets04.core.p4.mass");
  //04 is refered to the conse size of jet construction: dR = 0.4for anti-kt algorithm
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
  TH1D* h_genLep_phi  = new TH1D("h_genLep_phi", "h_genLep_phi; genLep phi; Number of entries",         100, -5 , 5   );
  TH1D* h_genLep_pt   = new TH1D("h_genLep_pt",  "h_genLep_pt; genLep p_T [GeV]; Number of entries",    100, -10, 600);
  TH1D* h_genLep_eta  = new TH1D("h_genLep_eta", "h_genLep_eta; genLep eta; Number of entries",         100, -15, 15  );
  TH1D* h_LgenLep_pt  = new TH1D("h_LgenLep_pt",  "h_LgenLep_pt; LgenLep p_T [GeV]; Number of entries", 100, -10, 600);
  TH1D* h_LgenLep_eta = new TH1D("h_LgenLep_eta", "h_LgenLep_eta; LgenLep eta; Number of entries",      100, -15, 15  );

  TH1D* h_Lep_n    = new TH1D("h_Lep_n",   "h_Lep_n; Number of Lep; Number of entries",     51,  -0.5 , 50.5);
  TH1D* h_Lep_phi  = new TH1D("h_Lep_phi", "h_Lep_phi; Lep phi; Number of entries",         100, -5 , 5   );
  TH1D* h_Lep_pt   = new TH1D("h_Lep_pt",  "h_Lep_pt; Lep p_T [GeV]; Number of entries",    100, -10, 600);
  TH1D* h_Lep_eta  = new TH1D("h_Lep_eta", "h_Lep_eta; Lep eta; Number of entries",         100, -10, 10  );
  TH1D* h_LLep_pt  = new TH1D("h_LLep_pt",  "h_LLep_pt; LLep p_T [GeV]; Number of entries", 100, -10, 600);
  TH1D* h_LLep_eta = new TH1D("h_LLep_eta", "h_LLep_eta; LLep eta; Number of entries",      100, -10, 10  );


  ////////////// Reader Loop:
  while(reader.Next()){
      // Loop over truth (generated) particles
      int n_genParticles = genParticles_px.GetSize();
      int lep_counter1 = 0;
      double leading_lep_pt = 0;
      double leading_lep_eta = 0;
      bool lep_exist = false;
      TLorentzVector vectorsum(0,0,0,0);
      for(int i=0; i<n_genParticles; i++){
          if(genParticles_status.At(i) != 1) continue;
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
      } // endo of loop over reco muons
      if(lep_exist){
        h_Lep_n   ->Fill(lep_counter2);
        h_LLep_pt ->Fill(leading_lep_pt2);
        h_LLep_eta->Fill(leading_lep_eta2);
      }

  } // end of reader.Next


  //////////////////////////////////////////////////////////////////////////////
  //////////////// Save histograms to .root files:
  string rootname = "/afs/cern.ch/user/c/chugli/private/histos/histo_lepton_study_" +BGstring_t+"_"+HTrange_s_t+".root";
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
