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
#include <TH2D.h>
#include <TGraph2D.h>

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
// if not already done you need to run first signal_kin.cc and BG_kin.cc
//
// This .cc concerns both signals and BGs samples.
//
// 1) It first extracts the histograms for the predicted number of BG events and
// predicted number of signal events
// 2) It calculates a histogram with the significance (sig = signal/sqrt(BG))
// 3) It plots everything in plots_kin.pdf
//
// 2D plots of significance, signal and BG are produced
////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// "/afs/cern.ch/user/c/chugli/private/txt/arrays_1.txt" = vecchio con histo fill only in loop events
// "/afs/cern.ch/user/c/chugli/private/txt/arrays_2.txt" = new correct one with histo fill in loop events, loop gen particles, if wino fill
///////////////////////////////////////////////////////////////////////////////

void make_arrays_wino();
void make_plots_wino(double fake_rate);
void make_arrays_higgsino();
void make_plots_higgsino(double fake_rate);

void plots_kin(){
  // make_arrays_wino();
  make_arrays_higgsino();

  // cout << "************** Start fake rate 2e-7 ****************" << endl;
  // double fake_rate = 2e-7;
  // make_plots_wino(fake_rate);
  // make_plots_higgsino(fake_rate);
  //
  // cout << "************** Start fake rate 1e-5 ****************" << endl;
  // fake_rate = 1e-5;
  // make_plots_wino(fake_rate);
  // make_plots_higgsino(fake_rate);
  //
  // cout << "************** Start fake rate 3.6e-7 ****************" << endl;
  // fake_rate = 3.6e-7;
  // make_plots_wino(fake_rate);
  // make_plots_higgsino(fake_rate);
  // cout << "************* Finished ***************" << endl;
}

void make_arrays_wino(){
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

  TH2D* h2_BG_tot = new TH2D("", "", 6e3,0,6e4,6e3,0,6e4);

  for(int i=0; i<5;i++){ // put <5 to include multijets
      const char* BGchar = BGtype[i].c_str();
      cout << "********************* Start BG " << BGtype[i] << " *********************" << endl;

      for(int j=0; j<mylength[i]; j++){
          string filename = "/afs/cern.ch/user/c/chugli/private/fast_sim/histos/histo_kin_" +BGtype[i]+"_"+myfolders[i][j]+".root";
          const char* dirname = filename.c_str();
          TFile *f = new TFile(dirname);

          TH2D* c_h2_pred    = (TH2D*)f->Get("h2_pred");

          h2_BG_tot->Add(c_h2_pred);
      } // end of j
  } //end of i


  /////////////////////////////////////////////////////////////////////////////
  /////////////////// Signal part:

  cout << "********************* Start signal part *********************" << endl;
  string f_type1  = "C1N1";
  string f_type2  = "C1C1";
  string f_middle[2] = {"1000","3000"};
  int index = 0;
  string mytitle [4] = {"C1N1 1000 GeV","C1N1 3000 GeV","C1C1 1000 GeV","C1C1 3000 GeV"};
  map<int,TH2D*> h_map;

  for (int j=0; j<2; j++){
      string ftype;
      if(j==0){ftype=f_type1;}
      else{ftype=f_type2;}
      cout << "********************* Start signal " << ftype << " *********************" << endl;

      for(int i = 0; i < 2; i++){
          const char* ftype_c = mytitle[index].c_str();

          cout << "signal type, mass, index: " << ftype << ", " << f_middle[i] << ", " << index << endl;
          string filename = "/afs/cern.ch/user/c/chugli/private/fast_sim/histos/histo_kin_" +ftype+"_"+f_middle[i]+".root";
          const char* dirname = filename.c_str();
          TFile *f = new TFile(dirname);

          TH2D* c_h2_pred    = (TH2D*)f->Get("h2_pred");

          h_map[index] = c_h2_pred;
          index++;
      } // end of i
  } // end of j = loop over {C1C1, C1N1}


  ////////////////////////////////////////////////////////////////////////////////
  /////////// Significance calculation:
  const double selection[73] = {1000,2000,3000,\
                                3100,3200,3300,3400,3500,3600,3700,3800,3900,4000,\
                                4100,4200,4300,4400,4500,4600,4700,4800,4900,5000,\
                                5100,5200,5300,5400,5500,5600,5700,5800,5900,6000,\
                                6100,6200,6300,6400,6500,6600,6700,6800,6900,7000,\
                                7100,7200,7300,7400,7500,7600,7700,7800,7900,8000,\
                                8100,8200,8300,8400,8500,8600,8700,8800,8900,9000,\
                                9100,9200,9300,9400,9500,9600,9700,9800,9900,10000};

  double x[5329],y[5329],z[4][5329],n_sig[4][5329],n_BG[5329];

  ofstream MyFile("/afs/cern.ch/user/c/chugli/private/fast_sim/txt/arrays_wino.txt"); // Create and open a text file
  string mystring;

  MyFile << "// x, y, n_BG, n_sig(C1N1 1TeV), n_sig(C1N1 3TeV), n_sig(C1C1 1TeV), n_sig(C1C1 3TeV) \n";

  int counter = 0;
  cout << "Start selection loops" << endl;
  for(int i=0; i<73;i++){
      for(int j=0; j<73;j++){
          int a = selection[i]/10+1;
          int b = selection[j]/10+1;
          n_BG[counter]  = h2_BG_tot->Integral(a,6e3,b,6e3);

          n_sig[0][counter] = h_map[0]->Integral(a,6e3,b,6e3);
          n_sig[1][counter] = h_map[1]->Integral(a,6e3,b,6e3);
          n_sig[2][counter] = h_map[2]->Integral(a,6e3,b,6e3);
          n_sig[3][counter] = h_map[3]->Integral(a,6e3,b,6e3);

          cout << "wino counter: " << counter << endl;//", " << i << ", " << j << ", " << n_sig[1][counter] << endl;
          // cout << "tot entries: " << h_map[1]->GetEntries() << ", " << h_map[3]->GetEntries() << endl;
          // cout << "tot integral: " << h_map[1]->Integral(0,4e3,0,4e3) << ", "<< h_map[3]->Integral(0,4e3,0,4e3) << endl;
          // cout << "selection: " << a << ", " << b << endl;
          // cout << "signal: " << n_sig[1][counter] << ", " << n_sig[3][counter] << endl;

          x[counter]= selection[i];
          y[counter]= selection[j];

          ostringstream streamObj;
          streamObj << x[counter];
          string s1 = streamObj.str();

          ostringstream streamObj2;
          streamObj2 << y[counter];
          string s2 = streamObj2.str();

          ostringstream streamObj3;
          streamObj3 << n_BG[counter];
          string s3 = streamObj3.str();

          ostringstream streamObj4;
          streamObj4 << n_sig[0][counter];
          string s4 = streamObj4.str();

          ostringstream streamObj5;
          streamObj5 << n_sig[1][counter];
          string s5 = streamObj5.str();

          ostringstream streamObj6;
          streamObj6 << n_sig[2][counter];
          string s6 = streamObj6.str();

          ostringstream streamObj7;
          streamObj7 << n_sig[3][counter];
          string s7 = streamObj7.str();

          mystring = s1+", "+s2+", "+s3+", "+s4+", "+s5+", "+s6+", "+s7+";"+"\n";
          MyFile << mystring;

          if(counter>5320){cout << mystring << endl;}

          counter++;
      }
  }

  MyFile.close();
}

////////////////////////////////////////////////////////////////////////////////
void make_plots_wino(double fake_rate){
  string number;
  if(fake_rate==2e-7){number = "2";}
  else if(fake_rate==1e-5){number = "3";}
  else{number = "1";}

  /////////////// Efficiency vs chargino mass:
  cout << "Start reading arrays_2.txt" << endl;
  ifstream MyReadFile2("/afs/cern.ch/user/c/chugli/private/fast_sim/txt/arrays_wino.txt"); // Read from the text file
  // n_BG is without fake rate considerations
  double x[5329],y[5329],z[5329],n_sig[5329],n_BG[5329];
  int counter = 0;
  int i = 0;
  string s;
  string delimiter = ",";

  Double_t low[74] = {1000,2000,3000,\
                                3100,3200,3300,3400,3500,3600,3700,3800,3900,4000,\
                                4100,4200,4300,4400,4500,4600,4700,4800,4900,5000,\
                                5100,5200,5300,5400,5500,5600,5700,5800,5900,6000,\
                                6100,6200,6300,6400,6500,6600,6700,6800,6900,7000,\
                                7100,7200,7300,7400,7500,7600,7700,7800,7900,8000,\
                                8100,8200,8300,8400,8500,8600,8700,8800,8900,9000,\
                                9100,9200,9300,9400,9500,9600,9700,9800,9900,10000,11000};
  Int_t nn = 73;
  TH2D* h2_significance = new TH2D("h2_significance","h2_significance",nn,low,nn,low);
  TH2D* h2_signal       = new TH2D("h2_signal","h2_signal",nn,low,nn,low);
  TH2D* h2_BG           = new TH2D("h2_BG","h2_BG",nn,low,nn,low);

  // MyFile << "// x, y, n_BG, n_sig0, n_sig1, n_sig2, n_sig3 \n";
  while (getline (MyReadFile2, s)) {
    if(counter>0 && counter < 5330){
      size_t found1 = s.find(delimiter,0);
      size_t found2 = s.find(delimiter,found1+1);
      size_t found3 = s.find(delimiter,found2+1);
      size_t found4 = s.find(delimiter,found3+1);
      size_t found5 = s.find(delimiter,found4+1);
      size_t found6 = s.find(delimiter,found5+1);
      string s1 = s.substr(0, found1); // leading jet cut
      string s2 = s.substr(found1+2, found2-found1-2); // met cut
      string s3 = s.substr(found2+2, found3-found2-2); // BG
      string s4 = s.substr(found3+2, found4-found3-2); // C1N1 1000
      string s5 = s.substr(found4+2, found5-found4-2); // C1N1 3000
      string s6 = s.substr(found5+2, found6-found5-2); // C1C1 1000
      string s7 = s.substr(found6+2,-3); // C1C1 3000
      x[i]    = stod(s1);
      y[i]    = stod(s2);
      n_BG[i]  = stod(s3)*(fake_rate+1e-6); // consider scattering with tracker material (physical BG)
      n_sig[i] = stod(s5)+stod(s7);
      z[i] = n_sig[i]/(sqrt(n_BG[i]));
      // cout << "counter: " << counter << "i: " << i << " x: " << x[i]+1 << " y: " << y[i]+1 << endl;

      // double z0;
      // if(z[i]==0){z0= 1e-16;}
      // else{z0= z[i];}
      // h2_significance->Fill(x[i]+1,y[i]+1,z0);
      h2_significance->Fill(x[i]+1,y[i]+1,z[i]);

      // double n_sig0;
      // if(n_sig[i]==0){n_sig0= 1e-16;}
      // else{n_sig0= n_sig[i];}
      // h2_signal->Fill(x[i]+1,y[i]+1,n_sig0);
      h2_signal->Fill(x[i]+1,y[i]+1,n_sig[i]);

      // double zbg;
      // if(n_BG[i]==0){zbg= 1e-26;}
      // else{zbg= n_BG[i];}
      // h2_BG->Fill(x[i]+1,y[i]+1,zbg);
      h2_BG->Fill(x[i]+1,y[i]+1,n_BG[i]);

      i++;
    }else if(counter >= 5330){
      break;
    }
    counter++;
  }
  MyReadFile2.close();
  //// end of extract events


  ////////// Plotting part:
  string mytitle [4] = {"C1N1 1000 GeV","C1N1 3000 GeV","C1C1 1000 GeV","C1C1 3000 GeV"};
  cout << "********************* Start plotting *********************" << endl;
  TCanvas *canvas = new TCanvas("c","");
  canvas->SetGrid();
  gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
  // canvas->SetLogy();
  // gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  string ss1 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/plot_sign_"+number+".pdf[";
  string ss2 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/plot_sign_"+number+".pdf";
  string ss3 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/plot_sign_"+number+".pdf]";

  h2_significance->GetXaxis()->SetNdivisions(-5);
  h2_significance->Draw("colz");
  gPad->Update();
  string ss = "Significance; Leading jet p_T selection [GeV]; MET selection [GeV]";
  h2_significance->SetTitle(ss.c_str());
  h2_significance->GetYaxis()->SetLabelSize(0.05);
  h2_significance->GetXaxis()->SetLabelSize(0.05);
  h2_significance->GetYaxis()->SetTitleSize(0.05);
  h2_significance->GetXaxis()->SetTitleSize(0.05);
  canvas->SaveAs(ss1.c_str());
  canvas->SaveAs(ss2.c_str());

  h2_signal->GetXaxis()->SetNdivisions(-5);
  h2_signal->Draw("colz");
  gPad->Update();
  ss = "Signal; Leading jet p_T selection [GeV]; MET selection [GeV]";
  h2_signal->SetTitle(ss.c_str());
  h2_signal->GetYaxis()->SetLabelSize(0.05);
  h2_signal->GetXaxis()->SetLabelSize(0.05);
  h2_signal->GetYaxis()->SetTitleSize(0.05);
  h2_signal->GetXaxis()->SetTitleSize(0.05);
  canvas->SaveAs(ss2.c_str());

  h2_BG->GetXaxis()->SetNdivisions(-5);
  h2_BG->Draw("colz");
  gPad->Update();
  ss = "BG ; Leading jet p_T selection [GeV]; MET selection [GeV]";
  h2_BG->SetTitle(ss.c_str());
  h2_BG->GetYaxis()->SetLabelSize(0.05);
  h2_BG->GetXaxis()->SetLabelSize(0.05);
  h2_BG->GetYaxis()->SetTitleSize(0.05);
  h2_BG->GetXaxis()->SetTitleSize(0.05);
  canvas->SaveAs(ss2.c_str());
  canvas->SaveAs(ss3.c_str());
  canvas->Close();


  delete h2_significance;
  delete h2_signal;
  delete h2_BG;
}

/////////////////////////////////////////////////////////////////////////////////
void make_arrays_higgsino(){
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

  TH2D* h2_BG_tot = new TH2D("", "", 6e3,0,6e4,6e3,0,6e4);

  for(int i=0; i<5;i++){
      const char* BGchar = BGtype[i].c_str();
      cout << "********************* Start BG " << BGtype[i] << " *********************" << endl;

      for(int j=0; j<mylength[i]; j++){
          string filename = "/afs/cern.ch/user/c/chugli/private/fast_sim/histos/histo_kin_" +BGtype[i]+"_"+myfolders[i][j]+".root";
          const char* dirname = filename.c_str();
          TFile *f = new TFile(dirname);

          TH2D* c_h2_pred    = (TH2D*)f->Get("h2_pred");

          h2_BG_tot->Add(c_h2_pred);

          f->Close();
      } // end of j
  } //end of i


  /////////////////////////////////////////////////////////////////////////////
  /////////////////// Signal part:
  cout << "********************* Start signal part *********************" << endl;
  string f_type1  = "C1N1";
  string f_type2  = "C1C1";
  string f_middle[2] = {"1000"};
  int index = 0;
  string mytitle [4] = {"C1N1 1000 GeV","C1C1 1000 GeV"};

  map<int,TH2D*>h_map;

  for (int j=0; j<2; j++){
      string ftype;
      if(j==0){ftype=f_type1;}
      else{ftype=f_type2;}
      cout << "********************* Start signal " << ftype << " *********************" << endl;

      for(int i = 0; i < 1; i++){
          const char* ftype_c = mytitle[index].c_str();

          cout << "signal type, mass, index: " << ftype << ", " << f_middle[i] << ", " << index << endl;
          string filename = "/afs/cern.ch/user/c/chugli/private/fast_sim/histos/histo_kin_higgsino_" +ftype+"_"+f_middle[i]+".root";
          const char* dirname = filename.c_str();
          TFile *f = new TFile(dirname);

          TH2D* c_h2_pred    = (TH2D*)f->Get("h2_pred");

          h_map[index] = c_h2_pred;
          index++;
      } // end of i
  } // end of j = loop over {C1C1, C1N1}

  ////////////////////////////////////////////////////////////////////////////////
  /////////// Significance calculation:
  const double selection[73] = {1000,2000,3000,\
                                3100,3200,3300,3400,3500,3600,3700,3800,3900,4000,\
                                4100,4200,4300,4400,4500,4600,4700,4800,4900,5000,\
                                5100,5200,5300,5400,5500,5600,5700,5800,5900,6000,\
                                6100,6200,6300,6400,6500,6600,6700,6800,6900,7000,\
                                7100,7200,7300,7400,7500,7600,7700,7800,7900,8000,\
                                8100,8200,8300,8400,8500,8600,8700,8800,8900,9000,\
                                9100,9200,9300,9400,9500,9600,9700,9800,9900,10000};

  double x[5329],y[5329],z[2][5329],n_sig[2][5329],n_BG[5329];

  ofstream MyFile("/afs/cern.ch/user/c/chugli/private/fast_sim/txt/arrays_higgsino.txt"); // Create and open a text file
  string mystring;

  MyFile << "// x, y, n_BG, n_sig C1N1 1000, n_sig C1C1 1000 \n";

  int counter = 0;
  cout << "Start selection loops" << endl;
  for(int i=0; i<73;i++){
      for(int j=0; j<73;j++){
          int a = selection[i]/10+1;
          int b = selection[j]/10+1;
          n_BG[counter]  = h2_BG_tot->Integral(a,6e3,b,6e3);

          n_sig[0][counter] = h_map[0]->Integral(a,6e3,b,6e3);
          n_sig[1][counter] = h_map[1]->Integral(a,6e3,b,6e3);

          cout << "counter: " << counter << endl;
          // cout << "tot entries: " << h_map[0]->GetEntries() << ", " << h_map[1]->GetEntries() << endl;
          // cout << "tot integral: " << h_map[0]->Integral(0,4e3,0,4e3) << ", "<< h_map[1]->Integral(0,4e3,0,4e3) << endl;
          // cout << "selection: " << a << ", " << b << endl;
          // cout << "signal: " << n_sig[0][counter] << ", " << n_sig[1][counter] << endl;

          x[counter]= selection[i];
          y[counter]= selection[j];

          ostringstream streamObj;
          streamObj << x[counter];
          string s1 = streamObj.str();

          ostringstream streamObj2;
          streamObj2 << y[counter];
          string s2 = streamObj2.str();

          ostringstream streamObj3;
          streamObj3 << n_BG[counter];
          string s3 = streamObj3.str();

          ostringstream streamObj4;
          streamObj4 << n_sig[0][counter];
          string s4 = streamObj4.str();

          ostringstream streamObj5;
          streamObj5 << n_sig[1][counter];
          string s5 = streamObj5.str();

          mystring = s1+", "+s2+", "+s3+", "+s4+", "+s5+";"+"\n";
          MyFile << mystring;

          counter++;
      }
  }

  MyFile.close();
}

///////////////////////////////////////////////////////////////////////////////
void make_plots_higgsino(double fake_rate){
  string number;
  if(fake_rate==2e-7){number = "2";}
  else if(fake_rate==1e-5){number = "3";}
  else{number = "1";}
  /////////////// Efficiency vs chargino mass:
  cout << "Start reading arrays_higgsino.txt" << endl;
  ifstream MyReadFile2("/afs/cern.ch/user/c/chugli/private/fast_sim/txt/arrays_higgsino.txt"); // Read from the text file
  // n_BG is without fake rate considerations
  double x[5329],y[5329],z[5329],n_sig[5329],n_BG[5329];
  int counter = 0;
  int i = 0;
  // Int_t n = 50;
  string s;
  string delimiter = ",";


  Double_t low[74] = {1000,2000,3000,\
                                3100,3200,3300,3400,3500,3600,3700,3800,3900,4000,\
                                4100,4200,4300,4400,4500,4600,4700,4800,4900,5000,\
                                5100,5200,5300,5400,5500,5600,5700,5800,5900,6000,\
                                6100,6200,6300,6400,6500,6600,6700,6800,6900,7000,\
                                7100,7200,7300,7400,7500,7600,7700,7800,7900,8000,\
                                8100,8200,8300,8400,8500,8600,8700,8800,8900,9000,\
                                9100,9200,9300,9400,9500,9600,9700,9800,9900,10000,11000};
  Int_t nn = 73;
  TH2D* h2_significance = new TH2D("h2_significance","h2_significance",nn,low,nn,low);
  TH2D* h2_signal = new TH2D("h2_signal","h2_signal",nn,low,nn,low);
  TH2D* h2_BG = new TH2D("h2_BG","h2_BG",nn,low,nn,low);

  // MyFile << "// x, y, n_BG, n_sig0, n_sig1 \n";
  while (getline (MyReadFile2, s)) {
    if(counter>0 && counter < 5330){
      size_t found1 = s.find(delimiter,0);
      size_t found2 = s.find(delimiter,found1+1);
      size_t found3 = s.find(delimiter,found2+1);
      size_t found4 = s.find(delimiter,found3+1);
      string s1 = s.substr(0, found1);
      string s2 = s.substr(found1+2, found2-found1-2);
      string s3 = s.substr(found2+2, found3-found2-2);
      string s4 = s.substr(found3+2, found4-found3-2);
      string s5 = s.substr(found4+2,-3);
      x[i]    = stod(s1);
      y[i]    = stod(s2);
      n_BG[i] = stod(s3)*(fake_rate+1e-6);
      n_sig[i] = stod(s4)+stod(s5);
      z[i] = n_sig[i]/(sqrt(n_BG[i]));

      // double z0;
      // if(z[0][i]==0){z0= 1e-36;}
      // else{z0= z[i];}
      // h2_significance->Fill(x[i]+1,y[i]+1,z0);
      h2_significance->Fill(x[i]+1,y[i]+1,z[i]);

      // double n_sig0;
      // if(n_sig[0][i]==0){n_sig0= 1e-36;}
      // else{n_sig0= n_sig[i];}
      // h2_signal->Fill(x[i]+1,y[i]+1,n_sig0);
      h2_signal->Fill(x[i]+1,y[i]+1,n_sig[i]);

      // double zbg;
      // if(n_BG[i]==0){zbg= 1e-26;}
      // else{zbg= n_BG[i];}
      // h2_BG->Fill(x[i]+1,y[i]+1,zbg);
      h2_BG->Fill(x[i]+1,y[i]+1,n_BG[i]);
      // cout << "i: " << i << endl;
      i++;
    }else if(counter >= 5330){
      break;
    }
    counter++;
  }
  MyReadFile2.close();
  //// end of extract events


  ////////// Plotting part:
  string mytitle [4] = {"C1N1 1000 GeV","C1C1 1000 GeV"};
  cout << "********************* Start plotting *********************" << endl;
  TCanvas *canvas = new TCanvas("c","");
  canvas->SetGrid();
  gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
  // canvas->SetLogy();
  // canvas->SetLogx();
  // gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  string ss1 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/plot_sign_higgsino_"+number+".pdf[";
  string ss2 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/plot_sign_higgsino_"+number+".pdf";
  string ss3 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/plot_sign_higgsino_"+number+".pdf]";

  h2_significance->GetXaxis()->SetNdivisions(-5);
  h2_significance->Draw("colz");
  gPad->Update();
  string ss = "Significance; Leading jet p_T selection [GeV]; MET selection [GeV]";
  h2_significance->SetTitle(ss.c_str());
  h2_significance->GetYaxis()->SetLabelSize(0.05);
  h2_significance->GetXaxis()->SetLabelSize(0.05);
  h2_significance->GetYaxis()->SetTitleSize(0.05);
  h2_significance->GetXaxis()->SetTitleSize(0.05);
  canvas->SaveAs(ss1.c_str());
  canvas->SaveAs(ss2.c_str());

  h2_signal->GetXaxis()->SetNdivisions(-5);
  h2_signal->Draw("colz");
  gPad->Update();
  ss = "Signal ; Leading jet p_T selection [GeV]; MET selection [GeV]";
  h2_signal->SetTitle(ss.c_str());
  h2_signal->GetYaxis()->SetLabelSize(0.05);
  h2_signal->GetXaxis()->SetLabelSize(0.05);
  h2_signal->GetYaxis()->SetTitleSize(0.05);
  h2_signal->GetXaxis()->SetTitleSize(0.05);
  canvas->SaveAs(ss2.c_str());

  h2_BG->GetXaxis()->SetNdivisions(-5);
  h2_BG->Draw("colz");
  gPad->Update();
  ss = "# BG events; Leading jet p_T selection [GeV]; MET selection [GeV]";
  h2_BG->SetTitle(ss.c_str());
  h2_BG->GetYaxis()->SetLabelSize(0.05);
  h2_BG->GetXaxis()->SetLabelSize(0.05);
  h2_BG->GetYaxis()->SetTitleSize(0.05);
  h2_BG->GetXaxis()->SetTitleSize(0.05);
  canvas->SaveAs(ss2.c_str());
  canvas->SaveAs(ss3.c_str());
  canvas->Close();

  delete h2_significance;
  delete h2_signal;
  delete h2_BG;


}
