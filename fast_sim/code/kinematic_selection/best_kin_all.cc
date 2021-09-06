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

void make_arrays_wino(double fake_rate, int part);
void make_arrays_higgsino(double fake_rate);

void best_kin_all(){
  // double fake_rate = 2e-7; // corresonds to configuration: Nhits = 5, layout 3, pileup condition = <200>
  // fake_rate = 1e-5; // corresonds to configuration: Nhits = 5, layout 3, pileup condition = <500>
  double fake_rate = 3.6e-7;

  // need different parts each 20 mass values due to memory problems (I assume):
  // cout << "*********** Wino 0 *************" << endl;
  // make_arrays_wino(fake_rate,0); // 0-19 = 700-2600 C1N1
  // cout << "*********** Wino 1 *************" << endl;
  // make_arrays_wino(fake_rate,1); // 20-39 = 2600-4600 C1N1
  cout << "*********** Wino 2 *************" << endl;
  make_arrays_wino(fake_rate,2); // 40-59 = 700-2600 C1C1
  // cout << "*********** Wino 3 *************" << endl;
  // make_arrays_wino(fake_rate,3); // 60-79 = 2600-4600 C1C1
  cout << "*********** Higgsino *************" << endl;
  make_arrays_higgsino(fake_rate);
  cout << "*********** Finished *************" << endl;
}

void make_arrays_wino(double fake_rate, int part){
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

  for(int i=0; i<5;i++){
      const char* BGchar = BGtype[i].c_str();
      cout << "********************* Start BG " << BGtype[i] << " *********************" << endl;

      for(int j=0; j<mylength[i]; j++){
          string filename = "/afs/cern.ch/user/c/chugli/private/fast_sim/histos/histo_kin_" +BGtype[i]+"_"+myfolders[i][j]+".root";
          const char* dirname = filename.c_str();
          TFile *f = new TFile(dirname);

          TH2D* h2_extra  = (TH2D*)f->Get("h2_pred");

          h2_BG_tot->Add(h2_extra);
          // delete h2_extra;
          f->Close();
      } // end of j
  } //end of i




  /////////////////////////////////////////////////////////////////////////////
  /////////////////// Signal part:
  cout << "********************* Start signal part *********************" << endl;
  ///Read efficiencies form .txt
  cout << "Start reading reco_track_e_signal_2.txt" << endl;
  ifstream MyReadFile2("/afs/cern.ch/user/c/chugli/private/fast_sim/txt/reco_track_e_signal_2.txt"); // Read from the text file
  int counter = 0;
  int i = 0;
  Int_t n = 40;
  string s;
  string delimiter = ",";
  Double_t e_C1N1[n], e_C1C1[n];
  while (getline (MyReadFile2, s)) {
      if(counter>3 && counter < 44){
          size_t found1 = s.find(delimiter,0); // position of first delimiter
          size_t found2 = s.find(delimiter,found1+1);
          string s1 = s.substr(0, found1); // chargino mass
          string s2 = s.substr(found1+2, found2-found1-2); // efficiency C1N1
          string s3 = s.substr(found2+2,-3); // efficiency C1C1
          e_C1N1[i]= stod(s2);
          e_C1C1[i]= stod(s3);
          i++;
      }else if(counter >= 44){
          break;
      }
      counter++;
  }
  MyReadFile2.close();
  //// end of extract events


  /////////////////////////////////////////////////////////////////////////////
  ///////////// Read signal histograms:
  string f_type1  = "C1N1";
  string f_type2  = "C1C1";
  string f_middle[40];
  int index = 0;
  string mytitle[80];
  string ftype;

  int i_start[4] = {0,20,0,20};
  int i_end[4]   = {20,40,20,40};

  if(part==0 || part==0){
    ftype=f_type1;
  }else{
    ftype=f_type2;
  }

  cout << "********************* Start signal " << ftype << " *********************" << endl;

  map<int, TH2D*> h2_sig;

  for(int i = i_start[part]; i < i_end[part]; i++){
  // for(int i = i_start[part]; i < 5; i++){
      f_middle[i] = to_string(700+100*i);
      mytitle[i] = ftype+" "+f_middle[i]+" GeV";
      const char* ftype_c = mytitle[i].c_str();

      cout << "signal type, mass, i: " << ftype << ", " << f_middle[i] << ", " << i << endl;

      ///////////// Read histogram form .root:
      string filename = "/afs/cern.ch/user/c/chugli/private/fast_sim/histos/histo_kin_" +ftype+"_"+f_middle[i]+".root";
      const char* dirname = filename.c_str();
      TFile *f = new TFile(dirname);

      TH2D* h2_signal = (TH2D*)f->Get("h2_pred");
      h2_signal->SetTitle(ftype_c);
      h2_sig[i] = h2_signal;
      // cout << "Entries 0: " << h2_sig[i]->Integral(0,4e3,0,4e3) << " end"<< endl;
      // cout << "effi: " << e_C1N1[i] << "  " << e_C1C1[i] << endl;

      ///// Scale histogram with reconstruction efficiency from .txt:
      if(ftype=="C1N1"){h2_sig[i]->Scale(e_C1N1[i]);}
      else{h2_sig[i]->Scale(e_C1C1[i]);}
      // cout << "Entries 1: " << h2_sig[i]->Integral(0,4e3,0,4e3) << " end"<< endl;
      // f->Close();
      // delete h2_signal;
      // cout << "test" << endl;
  } // end of i

  ////////////////////////////////////////////////////////////////////////////////
  /////////// Significance calculation:
  const double selection[40] = {100,200,300,400,500,600,700,800,900,1000,\
                                1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,\
                                2100,2200,2300,2400,2500,2600,2700,2800,2900,3000,\
                                3100,3200,3300,3400,3500,3600,3700,3800,3900,4000};

  double max_sig[3][20];

  for(int k=0; k<20; k++){
    max_sig[0][k] = 0;
    max_sig[1][k] = 0;
    max_sig[2][k] = 0;
  }

  counter = 0;
  cout << "Start selection loops" << endl;
  for(int i=0; i<40;i++){
      for(int j=0; j<40;j++){
          cout << "counter: " << counter << endl;
          int a = selection[i]/10+1;
          int b = selection[j]/10+1;

          double n_BG = h2_BG_tot->Integral(a,4e3,b,4e3);
          n_BG = n_BG*(fake_rate+1e-6); // considering the additional physical BG !!!
          n_BG = sqrt(n_BG);

          int counter2 = 0;
          for(int k=i_start[part]; k<i_end[part]; k++){
              // cout << "k: " << k << endl;
              // cout << "Entries: " << h2_sig[k]->GetEntries() << " end"<< endl;
              // cout << "Tot integral: " << h2_sig[k]->Integral(0,4e3,0,4e3) << " end"<< endl;
              // n_sig[counter2][counter] = h2_sig[k]->Integral(a,4e3,b,4e3);
              // cout << n_sig[counter2][counter]<< endl;
              double z = h2_sig[k]->Integral(a,4e3,b,4e3)/n_BG;
              if(max_sig[0][counter2] < z){
                  max_sig[0][counter2] = z; // significance
                  max_sig[1][counter2] = selection[i];    // jeading jet pt cut
                  max_sig[2][counter2] = selection[j];    // met cut
              }
              counter2++;
          }
          // cout << "0: " << max_sig[0][0] << " 1: " << max_sig[0][1] << endl;

          counter++;
      }
  }

  /////////////////////////////////////////////////////////////////////////////
  ////////////// Save the best cut to a file:
  ostringstream streamObj;
  streamObj << fake_rate;
  string fake_rate_s = streamObj.str();

  ofstream MyFile;
  string myname = "/afs/cern.ch/user/c/chugli/private/fast_sim/txt/kinematic_selection_wino_"+fake_rate_s+".txt";
  if(part==0){
    MyFile.open(myname.c_str()); // Create and open a text file
    MyFile << "// higgsino/wino, mass, C1C1/C1N1, leading jet pt cut, met cut \n";
  }else{
    MyFile.open(myname.c_str(),ios_base::app);
  }
  string mystring;

  for(int k=0; k<20; k++){
      string type;
      string mass;

      if(part==0 || part ==1){
        type = "C1N1";
        double d_mass;
        if(part==0){d_mass = 700+100*k;}
        else{d_mass = 700+100*(k+20);}
        ostringstream streamObj;
        streamObj << d_mass;
        mass = streamObj.str();
      }else{
        type = "C1C1";
        double d_mass;
        if(part==2){d_mass = 700+100*k;}
        else{d_mass = 700+100*(k+20);}
        ostringstream streamObj;
        streamObj << d_mass;
        mass = streamObj.str();
      }

      ostringstream streamObj;
      streamObj << max_sig[1][k];
      string pt = streamObj.str();

      ostringstream streamObj1;
      streamObj1 << max_sig[2][k];
      string met = streamObj1.str();

      ostringstream streamObj2;
      streamObj2 << max_sig[0][k];
      string sign = streamObj2.str();

      mystring = "Wino, "+type+", "+mass+", "+pt+", "+met+", "+sign+";"+"\n";
      MyFile << mystring;
  }

  MyFile.close();


  cout << "Delete" << endl;

  for(int i = i_start[part]; i < i_end[part]; i++){
    delete h2_sig[i];
  }
  delete h2_BG_tot;

  cout << "Finished" << endl;
}


void make_arrays_higgsino(double fake_rate){
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

  for(int i=0; i<5;i++){
      const char* BGchar = BGtype[i].c_str();
      cout << "********************* Start BG " << BGtype[i] << " *********************" << endl;

      for(int j=0; j<mylength[i]; j++){
          string filename = "/afs/cern.ch/user/c/chugli/private/fast_sim/histos/histo_kin_" +BGtype[i]+"_"+myfolders[i][j]+".root";
          const char* dirname = filename.c_str();
          TFile *f = new TFile(dirname);

          TH2D* h2_extra  = (TH2D*)f->Get("h2_pred");

          h2_BG_tot->Add(h2_extra);
      } // end of j
  } //end of i


  /////////////////////////////////////////////////////////////////////////////
  /////////////////// Signal part:
  cout << "******************* Start the signal part *****************" << endl;
  //// Read the reconstruction efficientcy from the.txt file:
  cout << "Start reading reco_track_e_signal_higgsino.txt" << endl;
  ifstream MyReadFile2("/afs/cern.ch/user/c/chugli/private/fast_sim/txt/reco_track_e_signal_higgsino.txt"); // Read from the text file
  int counter = 0;
  int i = 0;
  Int_t n = 9; // from 700 to 1500. The cross section does not exist for the others. See GetXsec_simple_higgsino.txt
  string s;
  string delimiter = ",";
  Double_t e_C1N1[n], e_C1C1[n];
  while (getline (MyReadFile2, s)) {
      if(counter>3 && counter < 13){
          size_t found1 = s.find(delimiter,0);
          size_t found2 = s.find(delimiter,found1+1);
          string s1 = s.substr(0, found1);
          string s2 = s.substr(found1+2, found2-found1-2); // efficiency C1N1
          string s3 = s.substr(found2+2,-3); // efficiency C1C1
          e_C1N1[i]= stod(s2);
          e_C1C1[i]= stod(s3);
          cout << "Efficiency reading: " << e_C1N1[i] << ", " << e_C1C1[i] << endl;
          i++;
      }else if(counter >= 13){
          break;
      }
      counter++;
  }
  MyReadFile2.close();
  //// end of extract events


    /////////////////////////////////////////////////////////////////////////////
    ///////////// Read signal histograms:
    string f_type1  = "C1N1";
    string f_type2  = "C1C1";
    string f_middle[9];
    int index = 0;
    string mytitle[18];

    map<int, TH2D*> h2_sig;

    for (int j=0; j<2; j++){
        string ftype;
        if(j==0){ftype=f_type1;}
        else{ftype=f_type2;}
        cout << "********************* Start signal " << ftype << " *********************" << endl;

        for(int i = 0; i < 9; i++){
            f_middle[i] = to_string(700+100*i);
            mytitle[index] = ftype+" "+f_middle[i]+" GeV";
            const char* ftype_c = mytitle[index].c_str();

            cout << "signal type, mass, index: " << ftype << ", " << f_middle[i] << ", " << index << endl;

            ///// Read the .root file:
            string filename = "/afs/cern.ch/user/c/chugli/private/fast_sim/histos/histo_kin_higgsino_" +ftype+"_"+f_middle[i]+".root";
            const char* dirname = filename.c_str();
            TFile *f = new TFile(dirname);

            TH2D* h2_signal = (TH2D*)f->Get("h2_pred");
            h2_signal->SetTitle(ftype_c);

            h2_sig[index] = h2_signal;

            ///// Scale histogram with reconstruction efficiency from .txt:
            if(ftype=="C1N1"){h2_sig[index]->Scale(e_C1N1[i]);}
            else{h2_sig[index]->Scale(e_C1C1[i]);}

            index++;
        } // end of i
    } // end of j = loop over {C1C1, C1N1}


    ////////////////////////////////////////////////////////////////////////////////
    /////////// Significance calculation:
    const double selection[40] = {100,200,300,400,500,600,700,800,900,1000,\
                                  1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,\
                                  2100,2200,2300,2400,2500,2600,2700,2800,2900,3000,\
                                  3100,3200,3300,3400,3500,3600,3700,3800,3900,4000};

    double significance[18][40][40];
    // remember mytitle[4]

    double x[1600],y[1600],z[18][1600],n_sig[18][1600],n_BG[1600], max_sig[3][18]={};

    counter = 0;
    cout << "Start selection loops" << endl;
    for(int i=0; i<40;i++){
        for(int j=0; j<40;j++){
            cout << "counter: " << counter << " max_sig[0]"<< max_sig[0] << endl;
            int a = selection[i]/10+1;
            int b = selection[j]/10+1;

            x[counter]= selection[i];
            y[counter]= selection[j];

            n_BG[counter] = h2_BG_tot->Integral(a,4e3,b,4e3);
            n_BG[counter] = n_BG[counter]*(fake_rate+1e-6); // Physical BG OK!!!!

            for(int k=0; k<18; k++){
                n_sig[k][counter] = h2_sig[k]->Integral(a,4e3,b,4e3);
                z[k][counter] = n_sig[k][counter]/(sqrt(n_BG[counter]));
                if(max_sig[0][k] < z[k][counter]){
                    max_sig[0][k] = z[k][counter]; // significance
                    max_sig[1][k] = x[counter];    // jeading jet pt cut
                    max_sig[2][k] = y[counter];    // met cut
                }
            }

            counter++;
        }
    }


    ///////// Save best cuts to a .txt file:
    ostringstream streamObj;
    streamObj << fake_rate;
    string fake_rate_s = streamObj.str();
    string myname = "/afs/cern.ch/user/c/chugli/private/fast_sim/txt/kinematic_selection_higgsino_"+fake_rate_s+".txt";
    ofstream MyFile(myname.c_str()); // Create and open a text file
    string mystring;

    MyFile << "// higgsino/wino, mass, C1C1/C1N1, leading jet pt cut, met cut \n";

    for(int k=0; k<18; k++){
        string type;
        string mass;

        if(k<9){
          type = "C1N1";
          double d_mass;
          d_mass = 700+100*k;
          ostringstream streamObj;
          streamObj << d_mass;
          mass = streamObj.str();
        }else{
          type = "C1C1";
          double d_mass;
          d_mass = 700+100*(k-9);
          ostringstream streamObj;
          streamObj << d_mass;
          mass = streamObj.str();
        }

        ostringstream streamObj;
        streamObj << max_sig[1][k];
        string pt = streamObj.str();

        ostringstream streamObj1;
        streamObj1 << max_sig[2][k];
        string met = streamObj1.str();

        ostringstream streamObj2;
        streamObj2 << max_sig[0][k];
        string sign = streamObj2.str();

        mystring = "Higgsino, "+type+", "+mass+", "+pt+", "+met+", "+sign+";"+"\n";
        MyFile << mystring;
    }

    MyFile.close();


    cout << "Delete" << endl;

    for(int i = 0; i < 18; i++){
      delete h2_sig[i];
    }
    delete h2_BG_tot;

    cout << "Finished" << endl;
}
