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
#include <TMultiGraph.h>
#include <TGraph.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TStyle.h>
#include <TH2D.h>
#include <THStack.h>

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
// The program consists of two big functions:
// A) It reads the efficiency in function of mass from reco_track_e_signal_2.txt
// and calculated the number of expected events using Nr_Events_signal.txt (in
// function of the chargino mass)
// B) Reads the histograms in function of HT, sums them with THStack and plots them to .pdf
////////////////////////////////////////////////////////////////////////////////

void histo_styling(TH1D* h, int j, const char* tit);
void histo_styling(TH2D* h, int j, const char* tit);
void make_canvas(string particle, THStack* hs, string ftype, double start, double end, const char* titx, const char* tity, int pos = 1, bool stack = true, bool logy = true, bool logx = true, bool etatrue = false);
void make_canvas(string particle, TH2D* h2, string ftype, double start, double end, const char* titx, const char* tity, int pos = 1, bool logx = false, bool logy = false);
// void make_effi_vs_mass_wino();
// void make_effi_vs_HT_wino();
// void make_effi_vs_mass_higgsino();
void make_canvas(TGraph* gr1, TGraph* gr2, const char* titx, const char* tity, int pos = 1, bool higgsino = false,bool logy = false, bool logx = false);
void make_wino();
void make_higgsino();
void make_kinematic_plots(string particle);

void reco_track_e_signal_plots(){
  // make_effi_vs_mass_wino();
  // // make_effi_vs_HT_wino();
  // make_effi_vs_mass_higgsino();
  // make_wino();
  // make_higgsino();
  make_kinematic_plots("wino");
  make_kinematic_plots("higgsino");
  cout << "************* Finished ***************" << endl;
}

///////////////////////////////////////////////////////////////////////////////
///////////// Functions:

void make_kinematic_plots(string particle){
  int n;
  string extra;
  if(particle=="wino"){
    n = 40;
    extra = "";
  }
  else if(particle=="higgsino"){
    n = 9;
    extra = "higgsino_";
  }else{
    cout << endl << "ERROR !!!!" << endl << endl;
  }
  ////////// Definition part:
  string f_type1  = "C1N1";
  string f_type2  = "C1C1";
  string f_middle[n];

  for (int j=0; j<2; j++){
      THStack *hs_events_HT           = new THStack("hs_events_HT","");
      THStack *hs_events_LJetpt       = new THStack("hs_events_LJetpt","");
      THStack *hs_events_chargino_eta = new THStack("hs_events_chargino_eta","");
      THStack *hs_betagamma           = new THStack("hs_betagamma","");
      THStack *hs_prob                = new THStack("hs_prob","");

      TH2D* hh2_e_HT           = new TH2D("hh2_e_HT",           "hh2_e_HT;           HT [GeV]; Entries / 500 GeV",             500, 0, 1e5, 100, 0, 1);
      TH2D* hh2_e_LJetpt       = new TH2D("hh2_e_LJetpt",       "hh2_e_LJetpt;       Leading jet pt [GeV]; Entries / 500 GeV", 500, 0, 1e5, 100, 0, 1);
      TH2D* hh2_e_chargino_eta = new TH2D("hh2_e_chargino_eta", "hh2_e_chargino_eta; chargino_eta []; Entries / 500 GeV",      100, -10, 10, 100, 0, 1);

      double betagamma_mean[n], y[n];

      string ftype;
      int ii;
      if(j==0){ftype=f_type1;}
      else{ftype=f_type2;}

      for(int i = 0; i < n; i++){
          f_middle[i] = to_string(700+100*i);
          y[i] = 700+100*i;

          string filename = "/afs/cern.ch/user/c/chugli/private/fast_sim/histos/histo_kin_" +extra+ftype+"_"+f_middle[i]+".root";
          const char* dirname = filename.c_str();
          TFile *f = new TFile(dirname);

          TH2D* c_h2_e_HT               = (TH2D*)f->Get("h2_e_HT");
          TH1D* c_h_events_HT           = (TH1D*)f->Get("h_events_HT");
          TH2D* c_h2_e_LJetpt           = (TH2D*)f->Get("h2_e_LJetpt");
          TH1D* c_h_events_LJetpt       = (TH1D*)f->Get("h_events_LJetpt");
          TH2D* c_h2_e_chargino_eta     = (TH2D*)f->Get("h2_e_chargino_eta");
          TH1D* c_h_events_chargino_eta = (TH1D*)f->Get("h_events_chargino_eta");
          TH1D* c_h_betagamma           = (TH1D*)f->Get("h_betagamma");
          TH1D* c_h_prob                = (TH1D*)f->Get("h_prob");

          const char* tit = f_middle[i].c_str();

          histo_styling(c_h2_e_HT              ,i,tit);
          histo_styling(c_h_events_HT          ,i,tit);
          histo_styling(c_h2_e_LJetpt          ,i,tit);
          histo_styling(c_h_events_LJetpt      ,i,tit);
          histo_styling(c_h2_e_chargino_eta    ,i,tit);
          histo_styling(c_h_events_chargino_eta,i,tit);
          histo_styling(c_h_betagamma          ,i,tit);
          histo_styling(c_h_prob               ,i,tit);

          // cout <<c_h_events_chargino_eta->GetEntries() << endl;

          hh2_e_HT               ->Add(c_h2_e_HT);
          hs_events_HT           ->Add(c_h_events_HT);
          hh2_e_LJetpt           ->Add(c_h2_e_LJetpt);
          hs_events_LJetpt       ->Add(c_h_events_LJetpt);
          hh2_e_chargino_eta     ->Add(c_h2_e_chargino_eta);
          hs_events_chargino_eta ->Add(c_h_events_chargino_eta);
          hs_betagamma           ->Add(c_h_betagamma);
          hs_prob                ->Add(c_h_prob);
      } // end of i

    ///////// Plotting part:
    // int pos = 1, bool stack = true, bool logy = true, bool logx = true
    make_canvas(particle,hs_events_HT          , ftype, 1, 1e6, "HT [GeV]","Events/500 GeV",0);
    make_canvas(particle,hs_events_LJetpt      , ftype, 1, 1e6, "Leading jet pt [GeV]","Events/500 GeV");
    make_canvas(particle,hs_events_chargino_eta, ftype, 1, 1e6, "Chargino eta []","Events",1,true,true,false,true);
    make_canvas(particle,hs_betagamma          , ftype, 1, 1e6, "Betagamma []","Events",1,true,true,false);
    make_canvas(particle,hs_prob               , ftype, 1, 1e6, "Reconstruction probability []","Events",2,true,true,false);

    make_canvas(particle,hh2_e_HT              , ftype, 0, 100, "HT [GeV]","Reconstruction efficiency",0,true,true);
    make_canvas(particle,hh2_e_LJetpt          , ftype, 0, 100, "Leading jet pt [GeV]","Reconstruction efficiency",1,true, true);
    make_canvas(particle,hh2_e_chargino_eta    , ftype, 46, 55, "Chargino eta []","Reconstruction efficiency",2,false,true);
  }
}

void make_wino(){
      ////////////////////////////////////////////////////////////////////////////
      ////////////// Extract total number of expected events:
      cout << "Start reading wino_arrays.txt" << endl;
      ifstream MyReadFile("/afs/cern.ch/user/c/chugli/private/fast_sim/txt/wino_arrays.txt"); // Read from the text file
      string s;
      string delimiter = ",";
      int counter = 0;
      int i = 0, i1=0, i2=0;
      map<string, int> mappy = {{"mass",0},{"betagammasintheta",1},{"tot_charginos",2},{"tot_charginos_eta",3},\
      {"entries",4},{"integral",5},{"e_counter/tot_events",6},{"e_counter_single/tot_events",7},\
      {"e_counter/tot_charginos",8},{"e_counter_single/tot_charginos",9},{"e_counter/tot_charginos_eta",10},{"e_counter_single/tot_charginos_eta",11}};
      double C1N1[12][40], C1C1[12][40];
      // mass, C1C1/C1N1, mean betagamma, tot_charginos, tot_events, entries h2_pred, tot integral of histo, reconstruciton efficiency, reconstruction efficiency single
      while (getline (MyReadFile, s)) {
        if(counter>0 && counter < 82){
          size_t found1 = s.find(delimiter,0);
          size_t found2 = s.find(delimiter,found1+1);
          size_t found3 = s.find(delimiter,found2+1);
          size_t found4 = s.find(delimiter,found3+1);
          size_t found5 = s.find(delimiter,found4+1);
          size_t found6 = s.find(delimiter,found5+1);
          size_t found7 = s.find(delimiter,found6+1);
          size_t found8 = s.find(delimiter,found7+1);
          size_t found9 = s.find(delimiter,found8+1);
          string s1 = s.substr(0, found1); //mass
          string s2 = s.substr(found1+2, found2-found1-2); // type
          string s3 = s.substr(found2+2, found3-found2-2); // mean betagamma sintheta
          string s4 = s.substr(found3+2, found4-found3-2); // tot_charginos
          string s5 = s.substr(found4+2, found5-found4-2); // tot_charginos_eta
          string s6 = s.substr(found5+2, found6-found5-2); // tot_events
          string s7 = s.substr(found6+2, found7-found6-2); // entries h2_pred
          string s8 = s.substr(found7+2, found8-found7-2); // integral
          string s9 = s.substr(found8+2, found9-found8-2); // e_counter
          string s10 = s.substr(found9+2, -5); // e_counter_single
          cout << "Wino: " << s << endl;
          // cout << "s1: " << s1 << endl;
          // cout << "s2: " << s2 << endl;
          // cout << "s3: " << s3 << endl;
          // cout << "s4: " << s4 << endl;
          // cout << "s5: " << s5 << endl;
          // cout << "s6: " << s6 << endl;
          // cout << "s7: " << s7 << endl;
          // cout << "s8: " << s8 << endl;
          // cout << "s9: " << s9 << endl;
          // cout << "s10: " << s10 << endl;

          if(i%2==0){
            C1N1[mappy["mass"]][i1]              = stod(s1);
            C1N1[mappy["betagammasintheta"]][i1] = stod(s3);
            C1N1[mappy["tot_charginos"]][i1]     = stod(s4);
            C1N1[mappy["tot_charginos"]][i1]     = stod(s5);
            C1N1[mappy["entries"]][i1]           = stod(s7);
            C1N1[mappy["integral"]][i1]          = stod(s8);
            double a = stod(s9); // e_counter
            double as = stod(s10); //e_counter_single
            double b1 = stod(s6); //tot-events
            double b2 = stod(s4); //tot_charginos
            double b3 = stod(s5); //tot_charignos-eta
            C1N1[mappy["e_counter/tot_events"]][i1]               = a/b1;
            C1N1[mappy["e_counter_single/tot_events"]][i1]        = as/b1;
            C1N1[mappy["e_counter/tot_charginos"]][i1]            = a/b2;
            C1N1[mappy["e_counter_single/tot_charginos"]][i1]     = as/b2;
            C1N1[mappy["e_counter/tot_charginos_eta"]][i1]        = a/b3;
            C1N1[mappy["e_counter_single/tot_charginos_eta"]][i1] = as/b3;
            if(s1=="3000"){
              cout << C1N1[mappy["e_counter/tot_events"]][i1]              << ", " << \
              C1N1[mappy["e_counter_single/tot_events"]][i1]        << ", " << \
              C1N1[mappy["e_counter/tot_charginos"]][i1]           << ", " << \
              C1N1[mappy["e_counter_single/tot_charginos"]][i1]     << ", " << \
              C1N1[mappy["e_counter/tot_charginos_eta"]][i1]       << ", " << \
              C1N1[mappy["e_counter_single/tot_charginos_eta"]][i1] << endl;
            }
            i1++;
          }
          else{
            C1C1[mappy["mass"]][i2]              = stod(s1);
            C1C1[mappy["betagammasintheta"]][i2] = stod(s3);
            C1C1[mappy["tot_charginos"]][i2]     = stod(s4);
            C1C1[mappy["tot_charginos"]][i2]     = stod(s5);
            C1C1[mappy["entries"]][i2]           = stod(s7);
            C1C1[mappy["integral"]][i2]          = stod(s8);
            double a = stod(s9); // e_counter
            double as = stod(s10); //e_counter_single
            double b1 = stod(s6); //tot-events
            double b2 = stod(s4); //tot_charginos
            double b3 = stod(s5); //tot_charignos-eta
            C1C1[mappy["e_counter/tot_events"]][i2]               = a/b1;
            C1C1[mappy["e_counter_single/tot_events"]][i2]        = as/b1;
            C1C1[mappy["e_counter/tot_charginos"]][i2]            = a/b2;
            C1C1[mappy["e_counter_single/tot_charginos"]][i2]     = as/b2;
            C1C1[mappy["e_counter/tot_charginos_eta"]][i2]        = a/b3;
            C1C1[mappy["e_counter_single/tot_charginos_eta"]][i2] = as/b3;
            if(s1=="3000"){
              cout << C1C1[mappy["e_counter/tot_events"]][i2]   << ", " << \
              C1C1[mappy["e_counter_single/tot_events"]][i2]    << ", " << \
              C1C1[mappy["e_counter/tot_charginos"]][i2]        << ", " << \
              C1C1[mappy["e_counter_single/tot_charginos"]][i2] << ", " << \
              C1C1[mappy["e_counter/tot_charginos_eta"]][i2]    << ", " << \
              C1C1[mappy["e_counter_single/tot_charginos_eta"]][i2] << endl;
            }
            i2++;
          }
          i++;
        }else if(counter >= 82){
          break;
        }
        counter++;
      }
      MyReadFile.close();
      //// end of extract events

      //////////////////////////////////////////////////////////////////////////////
      /////////////////// Make plots:
      TGraph* gr1 = new TGraph(40,C1N1[mappy["mass"]],C1N1[mappy["betagammasintheta"]]);
      TGraph* gr2 = new TGraph(40,C1C1[mappy["mass"]],C1C1[mappy["betagammasintheta"]]);
      make_canvas(gr1, gr2, "Chargino mass [GeV]", "mean betagamma*sin(theta) []", 0);

      TGraph* gr3 = new TGraph(40,C1N1[mappy["mass"]],C1N1[mappy["entries"]]);
      TGraph* gr4 = new TGraph(40,C1C1[mappy["mass"]],C1C1[mappy["entries"]]);
      make_canvas(gr3, gr4, "Chargino mass [GeV]", "h2_pred entries []");

      TGraph* gr5 = new TGraph(40,C1N1[mappy["mass"]],C1N1[mappy["integral"]]);
      TGraph* gr6 = new TGraph(40,C1C1[mappy["mass"]],C1C1[mappy["integral"]]);
      make_canvas(gr5, gr6, "Chargino mass [GeV]", "h2_pred integral []");

      TGraph* gr7 = new TGraph(40,C1N1[mappy["mass"]],C1N1[mappy["tot_charginos"]]);
      TGraph* gr8 = new TGraph(40,C1C1[mappy["mass"]],C1C1[mappy["tot_charginos"]]);
      make_canvas(gr7, gr8, "Chargino mass [GeV]", "tot_charginos []");

      TGraph* gr9  = new TGraph(40,C1N1[mappy["mass"]],C1N1[mappy["e_counter/tot_events"]]);
      TGraph* gr10 = new TGraph(40,C1C1[mappy["mass"]],C1C1[mappy["e_counter/tot_events"]]);
      make_canvas(gr9, gr10, "Chargino mass [GeV]", "e_counter/tot_events []");

      TGraph* gr11 = new TGraph(40,C1N1[mappy["mass"]],C1N1[mappy["e_counter_single/tot_events"]]);
      TGraph* gr12 = new TGraph(40,C1C1[mappy["mass"]],C1C1[mappy["e_counter_single/tot_events"]]);
      make_canvas(gr11, gr12, "Chargino mass [GeV]", "e_counter_single/tot_events []");

      TGraph* gr13 = new TGraph(40,C1N1[mappy["mass"]],C1N1[mappy["e_counter/tot_charginos"]]);
      TGraph* gr14 = new TGraph(40,C1C1[mappy["mass"]],C1C1[mappy["e_counter/tot_charginos"]]);
      make_canvas(gr13, gr14, "Chargino mass [GeV]", "e_counter/tot_charginos []");

      TGraph* gr15 = new TGraph(40,C1N1[mappy["mass"]],C1N1[mappy["e_counter_single/tot_charginos"]]);
      TGraph* gr16 = new TGraph(40,C1C1[mappy["mass"]],C1C1[mappy["e_counter_single/tot_charginos"]]);
      make_canvas(gr15, gr16, "Chargino mass [GeV]", "e_counter_single/tot_charginos []");

      TGraph* gr17 = new TGraph(40,C1N1[mappy["mass"]],C1N1[mappy["e_counter/tot_charginos_eta"]]);
      TGraph* gr18 = new TGraph(40,C1C1[mappy["mass"]],C1C1[mappy["e_counter/tot_charginos_eta"]]);
      make_canvas(gr17, gr18, "Chargino mass [GeV]", "e_counter/tot_charginos_eta []");

      TGraph* gr19 = new TGraph(40,C1N1[mappy["mass"]],C1N1[mappy["e_counter_single/tot_charginos_eta"]]);
      TGraph* gr20 = new TGraph(40,C1C1[mappy["mass"]],C1C1[mappy["e_counter_single/tot_charginos_eta"]]);
      make_canvas(gr19, gr20, "Chargino mass [GeV]", "e_counter_single/tot_charginos_eta []",2);


}

void make_higgsino(){
    ////////////////////////////////////////////////////////////////////////////
    ////////////// Extract total number of expected events:
    cout << "Start reading higgsino_arrays.txt" << endl;
    ifstream MyReadFile("/afs/cern.ch/user/c/chugli/private/fast_sim/txt/higgsino_arrays.txt"); // Read from the text file
    string s;
    string delimiter = ",";
    int counter = 0;
    int i = 0, i1=0, i2=0;
    map<string, int> mappy = {{"mass",0},{"betagammasintheta",1},{"tot_charginos",2},{"tot_charginos_eta",3},\
    {"entries",4},{"integral",5},{"e_counter/tot_events",6},{"e_counter_single/tot_events",7},\
    {"e_counter/tot_charginos",8},{"e_counter_single/tot_charginos",9},{"e_counter/tot_charginos_eta",10},{"e_counter_single/tot_charginos_eta",11}};
    double C1N1[12][40], C1C1[12][40];
    // mass, C1C1/C1N1, mean betagamma, tot_charginos, tot_events, entries h2_pred
    while (getline (MyReadFile, s)) {
      if(counter>0 && counter < 20){
        size_t found1 = s.find(delimiter,0);
        size_t found2 = s.find(delimiter,found1+1);
        size_t found3 = s.find(delimiter,found2+1);
        size_t found4 = s.find(delimiter,found3+1);
        size_t found5 = s.find(delimiter,found4+1);
        size_t found6 = s.find(delimiter,found5+1);
        size_t found7 = s.find(delimiter,found6+1);
        size_t found8 = s.find(delimiter,found7+1);
        size_t found9 = s.find(delimiter,found8+1);
        string s1 = s.substr(0, found1); //mass
        string s2 = s.substr(found1+2, found2-found1-2); // type
        string s3 = s.substr(found2+2, found3-found2-2); // mean betagamma sintheta
        string s4 = s.substr(found3+2, found4-found3-2); // tot_charginos
        string s5 = s.substr(found4+2, found5-found4-2); // tot_charginos_eta
        string s6 = s.substr(found5+2, found6-found5-2); // tot_events
        string s7 = s.substr(found6+2, found7-found6-2); // entries h2_pred
        string s8 = s.substr(found7+2, found8-found7-2); // integral
        string s9 = s.substr(found8+2, found9-found8-2); // e_counter
        string s10 = s.substr(found9+2, -5); // e_counter_single
        cout << "Higgsino: " << s << endl;
        // cout << "s1: " << s1 << endl;
        // cout << "s2: " << s2 << endl;
        // cout << "s3: " << s3 << endl;
        // cout << "s4: " << s4 << endl;
        // cout << "s5: " << s5 << endl;
        // cout << "s6: " << s6 << endl;
        // cout << "s7: " << s7 << endl;
        // cout << "s8: " << s8 << endl;
        // cout << "s9: " << s9 << endl;
        // cout << "s10: " << s10 << endl;

        if(i%2==0){
          C1N1[mappy["mass"]][i1]              = stod(s1);
          C1N1[mappy["betagammasintheta"]][i1] = stod(s3);
          C1N1[mappy["tot_charginos"]][i1]     = stod(s4);
          C1N1[mappy["tot_charginos"]][i1]     = stod(s5);
          C1N1[mappy["entries"]][i1]           = stod(s7);
          C1N1[mappy["integral"]][i1]          = stod(s8);
          double a = stod(s9); // e_counter
          double as = stod(s10); //e_counter_single
          double b1 = stod(s6); //tot-events
          double b2 = stod(s4); //tot_charginos
          double b3 = stod(s5); //tot_charignos-eta
          C1N1[mappy["e_counter/tot_events"]][i1]               = a/b1;
          C1N1[mappy["e_counter_single/tot_events"]][i1]        = as/b1;
          C1N1[mappy["e_counter/tot_charginos"]][i1]            = a/b2;
          C1N1[mappy["e_counter_single/tot_charginos"]][i1]     = as/b2;
          C1N1[mappy["e_counter/tot_charginos_eta"]][i1]        = a/b3;
          C1N1[mappy["e_counter_single/tot_charginos_eta"]][i1] = as/b3;
          if(s1=="1000"){
            cout << C1N1[mappy["e_counter/tot_events"]][i1]              << ", " << \
            C1N1[mappy["e_counter_single/tot_events"]][i1]        << ", " << \
            C1N1[mappy["e_counter/tot_charginos"]][i1]           << ", " << \
            C1N1[mappy["e_counter_single/tot_charginos"]][i1]     << ", " << \
            C1N1[mappy["e_counter/tot_charginos_eta"]][i1]       << ", " << \
            C1N1[mappy["e_counter_single/tot_charginos_eta"]][i1] << endl;
          }
          i1++;
        }
        else{
          C1C1[mappy["mass"]][i2]              = stod(s1);
          C1C1[mappy["betagammasintheta"]][i2] = stod(s3);
          C1C1[mappy["tot_charginos"]][i2]     = stod(s4);
          C1C1[mappy["tot_charginos"]][i2]     = stod(s5);
          C1C1[mappy["entries"]][i2]           = stod(s7);
          C1C1[mappy["integral"]][i2]          = stod(s8);
          double a = stod(s9); // e_counter
          double as = stod(s10); //e_counter_single
          double b1 = stod(s6); //tot-events
          double b2 = stod(s4); //tot_charginos
          double b3 = stod(s5); //tot_charignos-eta
          C1C1[mappy["e_counter/tot_events"]][i2]               = a/b1;
          C1C1[mappy["e_counter_single/tot_events"]][i2]        = as/b1;
          C1C1[mappy["e_counter/tot_charginos"]][i2]            = a/b2;
          C1C1[mappy["e_counter_single/tot_charginos"]][i2]     = as/b2;
          C1C1[mappy["e_counter/tot_charginos_eta"]][i2]        = a/b3;
          C1C1[mappy["e_counter_single/tot_charginos_eta"]][i2] = as/b3;
          if(s1=="1000"){
            cout << C1C1[mappy["e_counter/tot_events"]][i2]   << ", " << \
            C1C1[mappy["e_counter_single/tot_events"]][i2]    << ", " << \
            C1C1[mappy["e_counter/tot_charginos"]][i2]        << ", " << \
            C1C1[mappy["e_counter_single/tot_charginos"]][i2] << ", " << \
            C1C1[mappy["e_counter/tot_charginos_eta"]][i2]    << ", " << \
            C1C1[mappy["e_counter_single/tot_charginos_eta"]][i2] << endl;
          }
          i2++;
        }
        i++;
      }else if(counter >= 20){
        break;
      }
      counter++;
    }
    MyReadFile.close();
    //// end of extract events

    //////////////////////////////////////////////////////////////////////////////
    /////////////////// Make plots:
    //////////////////////////////////////////////////////////////////////////////
    /////////////////// Make plots:
    TGraph* gr1 = new TGraph(9,C1N1[mappy["mass"]],C1N1[mappy["betagammasintheta"]]);
    TGraph* gr2 = new TGraph(9,C1C1[mappy["mass"]],C1C1[mappy["betagammasintheta"]]);
    make_canvas(gr1, gr2, "Chargino mass [GeV]", "mean betagamma*sin(theta) []", 0, true);

    TGraph* gr3 = new TGraph(9,C1N1[mappy["mass"]],C1N1[mappy["entries"]]);
    TGraph* gr4 = new TGraph(9,C1C1[mappy["mass"]],C1C1[mappy["entries"]]);
    make_canvas(gr3, gr4, "Chargino mass [GeV]", "h2_pred entries []",1,true);

    TGraph* gr5 = new TGraph(9,C1N1[mappy["mass"]],C1N1[mappy["integral"]]);
    TGraph* gr6 = new TGraph(9,C1C1[mappy["mass"]],C1C1[mappy["integral"]]);
    make_canvas(gr5, gr6, "Chargino mass [GeV]", "h2_pred integral []", 1,true);

    TGraph* gr7 = new TGraph(9,C1N1[mappy["mass"]],C1N1[mappy["tot_charginos"]]);
    TGraph* gr8 = new TGraph(9,C1C1[mappy["mass"]],C1C1[mappy["tot_charginos"]]);
    make_canvas(gr7, gr8, "Chargino mass [GeV]", "tot_charginos []",1,true);

    TGraph* gr9  = new TGraph(9,C1N1[mappy["mass"]],C1N1[mappy["e_counter/tot_events"]]);
    TGraph* gr10 = new TGraph(9,C1C1[mappy["mass"]],C1C1[mappy["e_counter/tot_events"]]);
    make_canvas(gr9, gr10, "Chargino mass [GeV]", "e_counter/tot_events []",1,true);

    TGraph* gr11 = new TGraph(9,C1N1[mappy["mass"]],C1N1[mappy["e_counter_single/tot_events"]]);
    TGraph* gr12 = new TGraph(9,C1C1[mappy["mass"]],C1C1[mappy["e_counter_single/tot_events"]]);
    make_canvas(gr11, gr12, "Chargino mass [GeV]", "e_counter_single/tot_events []",1,true);

    TGraph* gr13 = new TGraph(9,C1N1[mappy["mass"]],C1N1[mappy["e_counter/tot_charginos"]]);
    TGraph* gr14 = new TGraph(9,C1C1[mappy["mass"]],C1C1[mappy["e_counter/tot_charginos"]]);
    make_canvas(gr13, gr14, "Chargino mass [GeV]", "e_counter/tot_charginos []",1,true);

    TGraph* gr15 = new TGraph(9,C1N1[mappy["mass"]],C1N1[mappy["e_counter_single/tot_charginos"]]);
    TGraph* gr16 = new TGraph(9,C1C1[mappy["mass"]],C1C1[mappy["e_counter_single/tot_charginos"]]);
    make_canvas(gr15, gr16, "Chargino mass [GeV]", "e_counter_single/tot_charginos []",1,true);

    TGraph* gr17 = new TGraph(9,C1N1[mappy["mass"]],C1N1[mappy["e_counter/tot_charginos_eta"]]);
    TGraph* gr18 = new TGraph(9,C1C1[mappy["mass"]],C1C1[mappy["e_counter/tot_charginos_eta"]]);
    make_canvas(gr17, gr18, "Chargino mass [GeV]", "e_counter/tot_charginos_eta []",1,true);

    TGraph* gr19 = new TGraph(9,C1N1[mappy["mass"]],C1N1[mappy["e_counter_single/tot_charginos_eta"]]);
    TGraph* gr20 = new TGraph(9,C1C1[mappy["mass"]],C1C1[mappy["e_counter_single/tot_charginos_eta"]]);
    make_canvas(gr19, gr20, "Chargino mass [GeV]", "e_counter_single/tot_charginos_eta []",2,true);
}

void make_canvas(TGraph* gr1, TGraph* gr2, const char* titx, const char* tity, int pos = 1, bool higgsino = false, bool logy = false, bool logx = false){
  TCanvas *canvas = new TCanvas("c","");
  if(logy){canvas->SetLogy();}
  if(logx){canvas->SetLogx();}
  gPad->SetMargin(0.17,0.1,0.12,0.1);//l,r,b,t
  gr1->SetMarkerColor(1);
  gr1->SetMarkerSize(0.5);
  gr1->SetMarkerStyle(7);
  gr1->SetNameTitle("","C1N1");
  gr2->SetMarkerColor(2);
  gr2->SetMarkerSize(0.5);
  gr2->SetMarkerStyle(7);
  gr2->SetNameTitle("","C1C1");
  TMultiGraph *mg = new TMultiGraph();
  mg->Add(gr1);
  mg->Add(gr2);
  mg->GetYaxis()->SetLabelSize(0.05);
  mg->GetXaxis()->SetLabelSize(0.05);
  mg->GetYaxis()->SetTitleSize(0.05);
  mg->GetXaxis()->SetTitleSize(0.05);
  mg->Draw("AP");
  mg->GetXaxis()->SetTitle(titx);
  mg->GetYaxis()->SetTitle(tity);
  canvas->BuildLegend(0.8,0.8,0.9,0.9);
  gPad->Modified();
  string f1;
  string f2;
  string f3;
  if(higgsino){
    f1 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/reco_plots_higgsino.pdf[";
    f2 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/reco_plots_higgsino.pdf";
    f3 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/reco_plots_higgsino.pdf]";
  }else{
    f1 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/reco_plots_wino.pdf[";
    f2 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/reco_plots_wino.pdf";
    f3 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/reco_plots_wino.pdf]";
  }
  const char* d1 = f1.c_str();
  const char* d2 = f2.c_str();
  const char* d3 = f3.c_str();
  if(pos == 0){
    canvas->SaveAs(d1);
    canvas->SaveAs(d2);
  }else if(pos==1){
    canvas->SaveAs(d2);
  }else if(pos==2){
    canvas->SaveAs(d2);
    canvas->SaveAs(d3);
  }
  canvas->Close();
}

void make_canvas(string particle, THStack* hs, string ftype, double start, double end, const char* titx, const char* tity, int pos = 1, bool stack = true, bool logy = true, bool logx = true, bool etatrue = false){
  TCanvas *canvas = new TCanvas("c","");
  gPad->SetMargin(0.15,0.1,0.12,0.1);//l,r,b,t
  if(logy){canvas->SetLogy();}
  if(logx){canvas->SetLogx();}
  hs->SetMaximum(end);
  hs->SetMinimum(start);
  if(stack){hs->Draw("hist bar");}
  else{hs->Draw("nostack hist bar");}
  if(etatrue){hs->GetXaxis()->SetRange(46,55);}
  hs->GetYaxis()->SetTitle(tity);
  hs->GetXaxis()->SetTitle(titx);
  hs->GetYaxis()->SetLabelSize(0.05);
  hs->GetXaxis()->SetLabelSize(0.05);
  hs->GetYaxis()->SetTitleSize(0.05);
  hs->GetXaxis()->SetTitleSize(0.05);
  canvas->BuildLegend(0.85,0.25,0.9,0.9);
  gPad->Modified();
  string f1 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/"+particle+"_kinematic_plots_"+ftype+".pdf[";
  const char* d1 = f1.c_str();
  string f2 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/"+particle+"_kinematic_plots_"+ftype+".pdf";
  const char* d2 = f2.c_str();
  string f3 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/"+particle+"_kinematic_plots_"+ftype+".pdf]";
  const char* d3 = f3.c_str();
  if(pos == 0){
    canvas->SaveAs(d1);
    canvas->SaveAs(d2);
  }else if(pos==1){
    canvas->SaveAs(d2);
  }else if(pos==2){
    canvas->SaveAs(d2);
    canvas->SaveAs(d3);
  }
  canvas->Close();
}

void make_canvas(string particle, TH2D* h2, string ftype, double start, double end, const char* titx, const char* tity, int pos = 1, bool logx = false, bool logy = false){
  TCanvas *canvas = new TCanvas("c","");
  gPad->SetMargin(0.12,0.1,0.12,0.1);//l,r,b,t
  gStyle->SetOptTitle(0);
  // canvas->SetLogy();
  // canvas->SetLogx();
  // if(logx){canvas->SetLogx();}
  // if(logy){canvas->SetLogy();}
  h2->Draw("colz");
  // h2->GetXaxis()->SetRange(start,end);
  h2->GetYaxis()->SetRange(0,100);
  h2->GetXaxis()->SetRange(start,end);
  gPad->Update();
  gStyle->SetOptStat(0);
  h2->GetYaxis()->SetTitle(tity);
  h2->GetXaxis()->SetTitle(titx);
  h2->GetYaxis()->SetLabelSize(0.05);
  h2->GetXaxis()->SetLabelSize(0.05);
  h2->GetYaxis()->SetTitleSize(0.05);
  h2->GetXaxis()->SetTitleSize(0.05);
  // canvas->BuildLegend(0.85,0.25,0.9,0.9);
  // gPad->Modified();
  string f1 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/"+particle+"_kinematic_plots_2D_"+ftype+".pdf[";
  const char* d1 = f1.c_str();
  string f2 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/"+particle+"_kinematic_plots_2D_"+ftype+".pdf";
  const char* d2 = f2.c_str();
  string f3 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/"+particle+"_kinematic_plots_2D_"+ftype+".pdf]";
  const char* d3 = f3.c_str();
  if(pos == 0){
    canvas->SaveAs(d1);
    canvas->SaveAs(d2);
  }else if(pos==1){
    canvas->SaveAs(d2);
  }else if(pos==2){
    canvas->SaveAs(d2);
    canvas->SaveAs(d3);
  }
  canvas->Close();
}

void histo_styling(TH1D* h, int j, const char* tit){
  h->SetFillColor(j+1);
  h->SetMarkerColor(j+1);
  h->SetLineColor(j+1);
  h->SetMarkerStyle(1);
  h->SetMarkerSize(0);
  h->SetTitle(tit);
  // h->SetLineWidth(0);
}

void histo_styling(TH2D* h, int j, const char* tit){
  h->SetFillColor(j+1);
  h->SetMarkerColor(j+1);
  h->SetLineColor(j+1);
  h->SetMarkerStyle(1);
  h->SetMarkerSize(0);
  h->SetTitle(tit);
  // h->SetLineWidth(0);
}


// void make_effi_vs_mass_wino(){
//   ////////////////////////////////////////////////////////////////////////////
//   ////////////// Extract total number of expected events:
//   cout << "Start reading Nr_Events_signal.txt" << endl;
//   ifstream MyReadFile("/afs/cern.ch/user/c/chugli/private/txt/Nr_Events_signal.txt"); // Read from the text file
//   string s;
//   string delimiter = ",";
//   int counter = 0;
//   int i = 0, i1=0, i2=0;
//   double n_tot_C1N1[40], n_tot_C1C1[40];
//   while (getline (MyReadFile, s)) {
//     if(counter>1 && counter < 82){
//       size_t found1 = s.find(delimiter,0); // position of first delimiter
//       size_t found2 = s.find(delimiter,found1+1);
//       string s1 = s.substr(0, found1); //BG type
//       string s2 = s.substr(found1+2, found2-found1-2); // HT range
//       string s3 = s.substr(found2+2,-5); // # events
//       // cout << endl << "i: " << i << endl;
//       if(i%2==0){
//         n_tot_C1N1[i1] = stod(s3);
//         i1++;
//       }
//       else{
//         n_tot_C1C1[i2]= stod(s3);
//         i2++;
//       }
//       i++;
//     }else if(counter >= 82){
//       break;
//     }
//     counter++;
//   }
//   MyReadFile.close();
//   //// end of extract events
//
//   /////////////////////////////////////////////////////////////////////////////
//   /////////////// Efficiency vs chargino mass:
//   cout << "Start reading reco_track_e_signal_2.txt" << endl;
//   ifstream MyReadFile2("/afs/cern.ch/user/c/chugli/private/txt/reco_track_e_signal_2.txt"); // Read from the text file
//   counter = 0;
//   i = 0;
//   Int_t n = 40;
//   Double_t e_C1N1[n], e_C1C1[n], y[n];
//   Double_t n_C1N1[n], n_C1C1[n];
//   while (getline (MyReadFile2, s)) {
//     if(counter>3 && counter < 44){
//       size_t found1 = s.find(delimiter,0); // position of first delimiter
//       size_t found2 = s.find(delimiter,found1+1);
//       string s1 = s.substr(0, found1); // chargino mass
//       string s2 = s.substr(found1+2, found2-found1-2); // efficiency C1N1
//       string s3 = s.substr(found2+2,-3); // efficiency C1C1
//       y[i] = stod(s1);
//       e_C1N1[i]= stod(s2);
//       e_C1C1[i]= stod(s3);
//       n_C1N1[i]=e_C1N1[i]*n_tot_C1N1[i];
//       n_C1C1[i]=e_C1C1[i]*n_tot_C1C1[i];
//       i++;
//     }else if(counter >= 44){
//       break;
//     }
//     counter++;
//   }
//   MyReadFile2.close();
//   //// end of extract events
//
//
//   //////////////////////////////////////////////////////////////////////////////
//   /////////////////// Make plots:
//   cout<< "Start plotting" << endl;
//   TCanvas *canvas = new TCanvas("c","");
//   gPad->SetMargin(0.15,0.1,0.1,0.1);//l,r,b,t
//   TGraph* gr1 = new TGraph(40,y,e_C1C1);
//   TGraph* gr2 = new TGraph(40,y,e_C1N1);
//   gr1->SetMarkerColor(1);
//   gr1->SetMarkerSize(0.5);
//   gr1->SetMarkerStyle(7);
//   gr1->SetNameTitle("ciaociao","e_C1C1");
//   gr2->SetMarkerColor(2);
//   gr2->SetMarkerSize(0.5);
//   gr2->SetMarkerStyle(7);
//   gr2->SetNameTitle("ciaociao","e_C1N1");
//   TMultiGraph *mg = new TMultiGraph();
//   mg->Add(gr1);
//   mg->Add(gr2);
//   mg->Draw("AP");
//   mg->GetXaxis()->SetTitle("Chargino mass [GeV]");
//   mg->GetYaxis()->SetTitle("Chargino reconstruction efficiency []");
//   canvas->BuildLegend(0.8,0.8,0.9,0.9);
//   gPad->Modified();
//   canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/plots/reco_track_e/effi_vs_mass.pdf[");
//   canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/plots/reco_track_e/effi_vs_mass.pdf");
//
//   canvas->SetLogy();
//   TGraph* gr3 = new TGraph(40,y,n_C1C1);
//   TGraph* gr4 = new TGraph(40,y,n_C1N1);
//   gr3->SetMarkerColor(1);
//   gr3->SetMarkerSize(0.5);
//   gr3->SetMarkerStyle(7);
//   gr3->SetNameTitle("ciaociao","n_C1C1");
//   gr4->SetMarkerColor(2);
//   gr4->SetMarkerSize(0.5);
//   gr4->SetMarkerStyle(7);
//   gr4->SetNameTitle("ciaociao","n_C1N1");
//   TMultiGraph *mg2 = new TMultiGraph();
//   mg2->Add(gr3);
//   mg2->Add(gr4);
//   mg2->Draw("AP");
//   mg2->GetXaxis()->SetTitle("Chargino mass [GeV]");
//   mg2->GetYaxis()->SetTitle("Expected number of events for chargino reconstruction []");
//   canvas->BuildLegend(0.8,0.8,0.9,0.9);
//   gPad->Modified();
//   canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/plots/reco_track_e/effi_vs_mass.pdf");
//   canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/plots/reco_track_e/effi_vs_mass.pdf]");
//   canvas->Close();
// }
//
// void make_effi_vs_HT_wino(){
//   ////////// Definition part:
//   string f_type1  = "C1N1";
//   string f_type2  = "C1C1";
//   string f_middle[40];
//
//   for (int j=0; j<2; j++){
//       THStack *hs1 = new THStack("hs1","Nr. events predicted chargino reconstruction prob"); // the chargino is reconstructed
//       THStack *hs2 = new THStack("hs2","Nr. events predicted without selection");
//       THStack *hs22 = new THStack("hs22","Nr. events sample without selection");
//       THStack *hs3 = new THStack("hs3","Efficiency (nostack)");
//       THStack *hs4 = new THStack("hs4","Nr. events sample chargino reconstruction prob");
//       THStack *hs5 = new THStack("hs5","Betagamma");
//       THStack *hs55 = new THStack("hs55","Gamma");
//       THStack *hs6 = new THStack("hs6","Probability");
//       TH2D* h27 = new TH2D("h27", "T vs. betagamma",    100, 0, 1e5, 10, 0, 60);
//       TH2D* h28 = new TH2D("h28", "HT vs. probability", 100, 0, 1e5, 10, 0, 1);
//       TH2D* h29 = new TH2D("h29", "HT vs. p_T",         100, 0, 1e5, 100, 0, 3e4);
//
//       double betagamma_mean[40], y[40];
//
//       string ftype;
//       int ii;
//       if(j==0){ftype=f_type1;}
//       else{ftype=f_type2;}
//
//       for(int i = 0; i < 40; i++){
//           f_middle[i] = to_string(700+100*i);
//           y[i] = 700+100*i;
//
//           string filename = "/afs/cern.ch/user/c/chugli/private/histos/histo_ch_reco" +ftype+"_"+f_middle[i]+".root";
//           const char* dirname = filename.c_str();
//           TFile *f = new TFile(dirname);
//
//           TH1D* c_hist_n1         = (TH1D*)f->Get("hist_n1");
//           TH1D* c_hist_ntot       = (TH1D*)f->Get("hist_ntot");
//           TH1D* c_hist_n          = (TH1D*)f->Get("hist_n");
//           TH1D* c_hist_e1         = (TH1D*)f->Get("hist_e1");
//           TH1D* c_hist_c1         = (TH1D*)f->Get("hist_c1");
//           TH1D* c_hist_gamma      = (TH1D*)f->Get("hist_gamma");
//           TH1D* c_hist_betagamma  = (TH1D*)f->Get("hist_betagamma");
//           TH1D* c_hist_prob       = (TH1D*)f->Get("hist_prob");
//           TH2D* c_h2_HT_betagamma = (TH2D*)f->Get("h2_HT_betagamma");
//           TH2D* c_h2_HT_prob      = (TH2D*)f->Get("h2_HT_prob");
//           TH2D* c_h2_HT_pt        = (TH2D*)f->Get("h2_HT_pt");
//
//           betagamma_mean[i] = c_hist_betagamma->GetMean();
//           cout << "betagamma mean: " << c_hist_betagamma->GetMean() << endl;
//
//
//           const char* tit = f_middle[i].c_str();
//
//           histo_styling(c_hist_n1,i,tit);
//           histo_styling(c_hist_ntot,i,tit);
//           histo_styling(c_hist_n,i,tit);
//           histo_styling(c_hist_e1,i,tit);
//           histo_styling(c_hist_c1,i,tit);
//           histo_styling(c_hist_betagamma,i,tit);
//           histo_styling(c_hist_gamma,i,tit);
//           histo_styling(c_hist_prob,i,tit);
//
//           hs1->Add(c_hist_n1);
//           hs2->Add(c_hist_ntot);
//           hs22->Add(c_hist_n);
//           hs3->Add(c_hist_e1);
//           hs4->Add(c_hist_c1);
//           hs5->Add(c_hist_betagamma );
//           hs55->Add(c_hist_gamma );
//           hs6->Add(c_hist_prob      );
//           h27->Add(c_h2_HT_betagamma);
//           h28->Add(c_h2_HT_prob     );
//           h29->Add(c_h2_HT_pt       );
//       } // end of i
//
//     ///////// Plotting part:
//
//     make_canvas(hs1, ftype, 1, 1e10, "HT [GeV]", "Events / 200 GeV", 0);
//     make_canvas(hs2, ftype, 1, 1e10, "HT [GeV]", "Events / 200 GeV");
//     make_canvas(hs22, ftype, 1, 1e10, "HT [GeV]", "Events / 200 GeV");
//     make_canvas(hs3, ftype, 0, 1   , "HT [GeV]", "Events / 200 GeV",    1, false, false);
//     make_canvas(hs4, ftype, 1, 1e10, "HT [GeV]", "Events / 200 GeV");
//     make_canvas(hs55, ftype, 1, 1e10, "gamma", "Number of events",   1, true , true , false);
//     make_canvas(hs5, ftype, 1, 1e10, "betagamma", "Number of events",   1, true , true , false);
//     make_canvas(hs6, ftype, 1, 1e10, "probability", "Number of events", 2, true , true , false);
//     make_canvas(h27, ftype, 1, 1e10, "HT [GeV]", "betagamma"  , 0);
//     make_canvas(h28, ftype, 1, 1e10, "HT [GeV]", "probability");
//     make_canvas(h29, ftype, 1, 1e10, "HT [GeV]", "chargino p_T [GeV]",2);
//
//     TCanvas *canvas = new TCanvas("c","");
//     gPad->SetMargin(0.15,0.1,0.1,0.1);//l,r,b,t
//     TGraph* gr1 = new TGraph(40,y,betagamma_mean);
//     gr1->SetMarkerColor(1);
//     gr1->SetMarkerSize(0.5);
//     gr1->SetMarkerStyle(7);
//     // gr1->SetNameTitle("ciaociao","e_C1C1");
//     TMultiGraph *mg = new TMultiGraph();
//     mg->Add(gr1);
//     mg->Draw("AP");
//     mg->GetXaxis()->SetTitle("Chargino mass [GeV]");
//     mg->GetYaxis()->SetTitle("Betagamma mean []");
//     canvas->BuildLegend(0.8,0.8,0.9,0.9);
//     gPad->Modified();
//     string f1 = "/afs/cern.ch/user/c/chugli/private/plots/reco_track_e/betagamma_"+ftype+".pdf";
//     const char* d1 = f1.c_str();
//     canvas->SaveAs(d1);
//
//     // cout << "betagamma mean tot: " << h5->GetMean() << endl;
//   } // end of j = loop over {C1C1, C1N1}
// }
//
// void make_effi_vs_mass_higgsino(){
//   ////////////////////////////////////////////////////////////////////////////
//   ////////////// Extract total number of expected events:
//   cout << "Start reading Nr_Events_signal_higgsino.txt" << endl;
//   ifstream MyReadFile("/afs/cern.ch/user/c/chugli/private/txt/Nr_Events_signal_higgsino.txt"); // Read from the text file
//   string s;
//   string delimiter = ",";
//   int counter = 0;
//   int i = 0, i1=0, i2=0;
//   Int_t n = 9;
//   Double_t n_tot_C1N1[n], n_tot_C1C1[n];
//   while (getline (MyReadFile, s)) {
//     if(counter>1 && counter < 20){
//       size_t found1 = s.find(delimiter,0);
//       size_t found2 = s.find(delimiter,found1+1);
//       string s1 = s.substr(0, found1); // mass
//       string s2 = s.substr(found1+2, found2-found1-2); // BG type
//       string s3 = s.substr(found2+2,-5); // # events
//       if(i%2==0){n_tot_C1N1[i1]= stod(s3);i1++;}
//       else{n_tot_C1C1[i2]= stod(s3);i2++;}
//       i++;
//       cout << "s: " << s << endl;
//       cout << "s1: " << s1 << endl;
//       cout << "s2: " << s2 << endl;
//       cout << "s3: " << s3 << endl;
//     }else if(counter >= 20){
//       break;
//     }
//     counter++;
//   }
//   MyReadFile.close();
//   //// end of extract events
//
//   /////////////////////////////////////////////////////////////////////////////
//   /////////////// Efficiency vs chargino mass:
//   cout << "Start reading reco_track_e_signal_higgsino.txt" << endl;
//   ifstream MyReadFile2("/afs/cern.ch/user/c/chugli/private/txt/reco_track_e_signal_higgsino.txt"); // Read from the text file
//   counter = 0;
//   i = 0;
//   n = 9;
//   delimiter = ",";
//   Double_t e_C1N1[n], e_C1C1[n], y[n];
//   Double_t n_C1N1[n], n_C1C1[n];
//   while (getline (MyReadFile2, s)) {
//       if(counter>3 && counter < 13){
//           size_t found1 = s.find(delimiter,0);
//           size_t found2 = s.find(delimiter,found1+1);
//           string s1 = s.substr(0, found1);
//           string s2 = s.substr(found1+2, found2-found1-2); // efficiency C1N1
//           string s3 = s.substr(found2+2,-3); // efficiency C1C1
//           y[i]     = stod(s1);
//           e_C1N1[i]= stod(s2);
//           e_C1C1[i]= stod(s3);
//           n_C1N1[i]= e_C1N1[i]*n_tot_C1N1[i];
//           n_C1C1[i]= e_C1C1[i]*n_tot_C1C1[i];
//           cout << "Tot # expected reco events: " << n_C1N1[i] << ", " << n_C1C1[i] << endl;
//           i++;
//       }else if(counter >= 13){
//           break;
//       }
//       counter++;
//   }
//   MyReadFile2.close();
//   //// end of extract events
//
//   //////////////////////////////////////////////////////////////////////////////
//   /////////////////// Make plots:
//   TCanvas *canvas = new TCanvas("c","");
//   gPad->SetMargin(0.15,0.1,0.1,0.1);//l,r,b,t
//   TGraph* gr1 = new TGraph(9,y,e_C1C1);
//   TGraph* gr2 = new TGraph(9,y,e_C1N1);
//   gr1->SetMarkerColor(1);
//   gr1->SetMarkerSize(0.5);
//   gr1->SetMarkerStyle(7);
//   gr1->SetNameTitle("ciaociao","e_C1C1");
//   gr2->SetMarkerColor(2);
//   gr2->SetMarkerSize(0.5);
//   gr2->SetMarkerStyle(7);
//   gr2->SetNameTitle("ciaociao","e_C1N1");
//   TMultiGraph *mg = new TMultiGraph();
//   mg->Add(gr1);
//   mg->Add(gr2);
//   mg->Draw("AP");
//   mg->GetXaxis()->SetTitle("Chargino mass [GeV]");
//   mg->GetYaxis()->SetTitle("Chargino reconstruction efficiency []");
//   canvas->BuildLegend(0.8,0.8,0.9,0.9);
//   gPad->Modified();
//   canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/plots/reco_track_e/effi_vs_mass_higgsino.pdf[");
//   canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/plots/reco_track_e/effi_vs_mass_higgsino.pdf");
//
//   canvas->SetLogy();
//   TGraph* gr3 = new TGraph(9,y,n_C1C1);
//   TGraph* gr4 = new TGraph(9,y,n_C1N1);
//   gr3->SetMarkerColor(1);
//   gr3->SetMarkerSize(0.5);
//   gr3->SetMarkerStyle(7);
//   gr3->SetNameTitle("ciaociao","n_C1C1");
//   gr4->SetMarkerColor(2);
//   gr4->SetMarkerSize(0.5);
//   gr4->SetMarkerStyle(7);
//   gr4->SetNameTitle("ciaociao","n_C1N1");
//   TMultiGraph *mg2 = new TMultiGraph();
//   mg2->Add(gr3);
//   mg2->Add(gr4);
//   mg2->Draw("AP");
//   mg2->GetXaxis()->SetTitle("Chargino mass [GeV]");
//   mg2->GetYaxis()->SetTitle("Expected number of events for chargino reconstruction []");
//   canvas->BuildLegend(0.8,0.8,0.9,0.9);
//   gPad->Modified();
//   canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/plots/reco_track_e/effi_vs_mass_higgsino.pdf");
//   canvas->SaveAs("/afs/cern.ch/user/c/chugli/private/plots/reco_track_e/effi_vs_mass_higgsino.pdf]");
//   canvas->Close();
// }
