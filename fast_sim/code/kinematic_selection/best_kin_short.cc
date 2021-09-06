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
// Needs:
// The histograms and .txt files (reconstruction.txt)
//
// 1) reads the histo.root for BG and signal.
// 2) Scales the signal histo by the reconstruciton efficiency
// 3) Scales the BG by (fake rate + 1e-6)
// 4) Calculates the integrals
// 5) Saves the best kinematic selection for each mass to a .txt
////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// "/afs/cern.ch/user/c/chugli/private/fast_sim/txt/arrays_1.txt" = vecchio con histo fill only in loop events
// "/afs/cern.ch/user/c/chugli/private/fast_sim/txt/arrays_2.txt" = new correct one with histo fill in loop events, loop gen particles, if wino fill
///////////////////////////////////////////////////////////////////////////////

void make_arrays_wino(double fake_rate);
void make_arrays_higgsino(double fake_rate);

void best_kin_short(){
  double fake_rate = 2e-7; // corresonds to configuration: Nhits = 5, layout 3, pileup condition = <200>
  // double fake_rate = 1e-5; // corresonds to configuration: Nhits = 5, layout 3, pileup condition = <500>

  // calculate best significance for 1000,2000,3000 and 4000 only
  cout << "************** Wino part 2e-7 *****************" << endl;
  // make_arrays_wino(fake_rate);
  // cout << "************** Higgsino part 2e-7 *****************" << endl;
  make_arrays_higgsino(fake_rate);
  // fake_rate = 1e-5; // corresonds to configuration: Nhits = 5, layout 3, pileup condition = <500>
  // cout << "************** Wino part 1e-5 *****************" << endl;
  // make_arrays_wino(fake_rate);
  // cout << "************** Higgsino part 1e-5 *****************" << endl;
  // make_arrays_higgsino(fake_rate);
  cout << "*********** Finished *************" << endl;
}

void make_arrays_wino(double fake_rate){
  /////////////////////////////////////////////////////////////////////////////
  /////////////////// BG part:
  // Read BG histograms
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

  TH2D* h2_BG_tot = new TH2D("", "", 4e3,0,4e4,4e3,0,4e4);

  for(int i=0; i<4;i++){
      const char* BGchar = BGtype[i].c_str();
      cout << "********************* Start BG " << BGtype[i] << " *********************" << endl;

      for(int j=0; j<mylength[i]; j++){
          string filename = "/afs/cern.ch/user/c/chugli/private/fast_sim/histos/histo_kin_" +BGtype[i]+"_"+myfolders[i][j]+".root";
          const char* dirname = filename.c_str();
          TFile *f = new TFile(dirname);

          TH2D* h2_extra  = (TH2D*)f->Get("h2_pred");

          h2_BG_tot->Add(h2_extra);

          f->Close();
      } // end of j
  } //end of i


  /////////////////////////////////////////////////////////////////////////////
  ///////////// Read signal histograms:
  string ftype1  = "C1N1";
  string ftype2  = "C1C1";
  string f_middle[4] = {"1000", "2000", "3000","4000"};

  cout << "********************* Start signal *********************" << endl;

  map<int, TH2D*> h2_sig;

  for(int i = 0; i < 4; i++){
      cout << " mass, i: " << f_middle[i] << ", " << i << endl;

      ///////////// Read histogram form .root:
      string filename = "/afs/cern.ch/user/c/chugli/private/fast_sim/histos/histo_kin_" +ftype1+"_"+f_middle[i]+".root";
      const char* dirname = filename.c_str();
      TFile *f = new TFile(dirname);

      TH2D* h2_signal = (TH2D*)f->Get("h2_pred");
      string mytitle1 = ftype1+" "+f_middle[i]+" GeV";
      const char* ftype_c = mytitle1.c_str();
      h2_signal->SetTitle(ftype_c);

      filename = "/afs/cern.ch/user/c/chugli/private/fast_sim/histos/histo_kin_" +ftype2+"_"+f_middle[i]+".root";
      const char* dirname2 = filename.c_str();
      TFile *f2 = new TFile(dirname2);

      TH2D* h2_signal2 = (TH2D*)f->Get("h2_pred");
      string mytitle2 = ftype1+" "+f_middle[i]+" GeV";
      const char* ftype_c2 = mytitle2.c_str();
      h2_signal2->SetTitle(ftype_c2);

      h2_signal->Add(h2_signal2);
      h2_sig[i] = h2_signal;
  }

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

  double max_sig[3][4];

  for(int k=0; k<4; k++){
    max_sig[0][k] = 0;
    max_sig[1][k] = 0;
    max_sig[2][k] = 0;
  }

  int counter = 0;
  cout << "Start selection loops" << endl;
  for(int i=0; i<73;i++){
      for(int j=0; j<73;j++){
          cout << "wino counter: " << counter << endl;
          int a = selection[i]/10+1;
          int b = selection[j]/10+1;

          double n_BG = h2_BG_tot->Integral(a,4e3,b,4e3);
          n_BG = n_BG*(fake_rate+1e-6); // considering the additional physical BG !!!
          n_BG = sqrt(n_BG);

          for(int k=0; k<4; k++){
              double z = h2_sig[k]->Integral(a,4e3,b,4e3)/n_BG;
              if(max_sig[0][k] < z){
                  max_sig[0][k] = z; // significance
                  max_sig[1][k] = selection[i];    // jeading jet pt cut
                  max_sig[2][k] = selection[j];    // met cut
              }
              cout << k << ": " << max_sig[0][k] <<", "<< max_sig[1][k] <<", "<< max_sig[2][k] << endl;
          }

          counter++;
      }
  }

  /////////////////////////////////////////////////////////////////////////////
  ////////////// Save the best cut to a file:
  ostringstream streamObj;
  streamObj << fake_rate;
  string fake_rate_s = streamObj.str();

  ofstream MyFile;
  string myname = "/afs/cern.ch/user/c/chugli/private/fast_sim/txt/kinematic_selection_wino_short_"+fake_rate_s+".txt";
  MyFile.open(myname.c_str()); // Create and open a text file
  MyFile << "// higgsino/wino, mass, C1C1/C1N1, leading jet pt cut, met cut \n";

  string mystring;

  for(int k=0; k<4; k++){
      string mass = f_middle[k];

      ostringstream streamObj0;
      streamObj0 << max_sig[1][k];
      string pt = streamObj0.str();

      ostringstream streamObj1;
      streamObj1 << max_sig[2][k];
      string met = streamObj1.str();

      ostringstream streamObj2;
      streamObj2 << max_sig[0][k];
      string sign = streamObj2.str();

      mystring = "Wino, "+mass+", "+pt+", "+met+", "+sign+";"+"\n";
      MyFile << mystring;
  }

  MyFile.close();


  cout << "Delete" << endl;

  for(int i = 0; i < 4; i++){
    delete h2_sig[i];
  }
  delete h2_BG_tot;

  cout << "********** Finished ************" << endl;
}


void make_arrays_higgsino(double fake_rate){
  //////////////////////////////////////////////////////////////////////////////
  ////////////// BG part:
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

  TH2D* h2_BG_tot = new TH2D("", "", 4e3,0,4e4,4e3,0,4e4);

  for(int i=0; i<4;i++){
      const char* BGchar = BGtype[i].c_str();
      cout << "********************* Start BG " << BGtype[i] << " *********************" << endl;

      for(int j=0; j<mylength[i]; j++){
          string filename = "/afs/cern.ch/user/c/chugli/private/fast_sim/histos/histo_kin_" +BGtype[i]+"_"+myfolders[i][j]+".root";
          const char* dirname = filename.c_str();
          TFile *f = new TFile(dirname);

          TH2D* h2_extra  = (TH2D*)f->Get("h2_pred");

          h2_BG_tot->Add(h2_extra);

          f->Close();
      } // end of j
  } //end of i


  /////////////////////////////////////////////////////////////////////////////
  /////////////////// Signal part:
  cout << "******************* Start the signal part *****************" << endl;
    /////////////////////////////////////////////////////////////////////////////
    ///////////// Read signal histograms:
    string f_type1  = "C1N1";
    string f_type2  = "C1C1";
    string f_middle[3] = {"700", "1000", "1500"};
    int index = 0;

    map<int, TH2D*> h2_sig;

    cout << "********************* Start signal *********************" << endl;

    for(int i = 0; i < 3; i++){
        cout << " mass, index: " << f_middle[i] << ", " << i << endl;

        ///// Read the .root file:
        string filename = "/afs/cern.ch/user/c/chugli/private/fast_sim/histos/histo_kin_higgsino_" +f_type1+"_"+f_middle[i]+".root";
        const char* dirname = filename.c_str();
        TFile *f = new TFile(dirname);

        TH2D* h2_signal = (TH2D*)f->Get("h2_pred");
        string mytitle1 = f_type1+" "+f_middle[i]+" GeV";
        const char* ftype_c = mytitle1.c_str();
        h2_signal->SetTitle(ftype_c);

        filename = "/afs/cern.ch/user/c/chugli/private/fast_sim/histos/histo_kin_higgsino_" +f_type2+"_"+f_middle[i]+".root";
        const char* dirname2 = filename.c_str();
        TFile *f2 = new TFile(dirname2);

        TH2D* h2_signal2 = (TH2D*)f2->Get("h2_pred");
        string mytitle2 = f_type2+" "+f_middle[i]+" GeV";
        const char* ftype_c2 = mytitle2.c_str();
        h2_signal2->SetTitle(ftype_c2);

        h2_signal->Add(h2_signal2);
        h2_sig[i] = h2_signal;
        cout << "Entries: " << h2_signal->GetEntries() << endl;
    }


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


    double max_sig[3][3];

    for(int k=0; k<3; k++){
      max_sig[0][k] = 0;
      max_sig[1][k] = 0;
      max_sig[2][k] = 0;
    }

    int counter = 0;
    cout << "Start selection loops" << endl;
    for(int i=0; i<73;i++){
        for(int j=0; j<73;j++){
            cout << "higgsino counter: " << counter << endl;
            int a = selection[i]/10+1;
            int b = selection[j]/10+1;

            double n_BG = h2_BG_tot->Integral(a,4e3,b,4e3);
            n_BG = n_BG*(fake_rate+1e-6); // Physical BG OK!!!!
            n_BG = sqrt(n_BG);

            cout << "n_BG: " << n_BG << endl;

            for(int k=0; k<3; k++){
                double z = h2_sig[k]->Integral(a,4e3,b,4e3)/n_BG;
                // cout << "signal: " << h2_sig[k]->Integral(0,4e3,0,4e3) << endl;
                // cout << "z: " << z << endl;
                // cout << "a, b: " << a << ", " << b << endl;
                if(max_sig[0][k] < z){
                    max_sig[0][k] = z; // significance
                    max_sig[1][k] = selection[i];    // jeading jet pt cut
                    max_sig[2][k] = selection[j];    // met cut
                }
                if(counter > 5320){
                  cout << k << ": " << max_sig[0][k] <<", "<< max_sig[1][k] <<", "<< max_sig[2][k] << endl;
                }
            }


            counter++;
        }
    }

    ///////// Save best cuts to a .txt file:
    ostringstream streamObj;
    streamObj << fake_rate;
    string fake_rate_s = streamObj.str();
    string myname = "/afs/cern.ch/user/c/chugli/private/fast_sim/txt/kinematic_selection_higgsino_short_"+fake_rate_s+".txt";
    ofstream MyFile(myname.c_str()); // Create and open a text file
    string mystring;

    MyFile << "// higgsino/wino, mass, C1C1/C1N1, leading jet pt cut, met cut \n";

    string mass_s[3]={"700","1000","1500"};

    for(int k=0; k<3; k++){
        ostringstream streamObj;
        streamObj << max_sig[1][k];
        string pt = streamObj.str();

        ostringstream streamObj1;
        streamObj1 << max_sig[2][k];
        string met = streamObj1.str();

        ostringstream streamObj2;
        streamObj2 << max_sig[0][k];
        string sign = streamObj2.str();

        mystring = "Higgsino, "+mass_s[k]+", "+pt+", "+met+", "+sign+";"+"\n";
        MyFile << mystring;
    }

    MyFile.close();


    cout << "Delete" << endl;

    for(int i = 0; i < 3; i++){
      delete h2_sig[i];
    }
    delete h2_BG_tot;

    cout << "Finished" << endl;
}
