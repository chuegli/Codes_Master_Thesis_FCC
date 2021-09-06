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
// 1) Reads the best cuts obtained from best_kin_short.txt
// 2) Calculates the efficiency for this cuts for each mass and writes them to a .txt
////////////////////////////////////////////////////////////////////////////////

void make_sign(double fake_rate, int a, int b, int part);
void h_make_sign(double fake_rate, int a, int b);
void make_wino(double fake_rate);
void make_higgsino(double fake_rate);

void best_kin_short_tot(){
    // double fake_rate = 2e-7; // corresonds to configuration: Nhits = 5, layout 3, pileup condition = <200>
    // double fake_rate = 1e-5; // corresonds to configuration: Nhits = 5, layout 3, pileup condition = <500>
    double fake_rate = 3.6e-7;

    // cout << "*********** Wino 2e-7 *************" << endl;
    // make_wino(fake_rate);
    // cout << "*********** Higgsino 2e-7 *************" << endl;
    // make_higgsino(fake_rate);
    // fake_rate = 1e-5;
    // cout << "*********** Wino 1e-5 *************" << endl;
    // make_wino(fake_rate);
    // cout << "*********** Higgsino 1e-5 *************" << endl;
    // make_higgsino(fake_rate);
    cout << "*********** Wino 3.6e-7 *************" << endl;
    make_wino(fake_rate);
    // cout << "*********** Higgsino 3.6e-7 *************" << endl;
    // make_higgsino(fake_rate);
    cout << "*********** Finished *************" << endl;
}

void make_wino(double fake_rate){
    ////////////////////////////////////////////////////////////////////////////
    //// Read .txt to extrect significance and cuts:
    ostringstream streamObj;
    streamObj << fake_rate;
    string fake_rate_s = streamObj.str();
    string myname = "/afs/cern.ch/user/c/chugli/private/fast_sim/txt/kinematic_selection_wino_short_"+fake_rate_s+".txt";
    cout << "Start reading " << myname << endl;

    ifstream MyReadFile2(myname.c_str());
    int counter = 0;
    int i1 = 0;
    Int_t n = 4;
    string s;
    string delimiter = ",";
    Double_t sig[n], pt[n], met[n], m[n];
    //mystring = "Wino, "+mass+", "+pt+", "+met+", "+sign+";"+"\n";
    while (getline (MyReadFile2, s)) {
        if(counter>0 && counter < 5){
            // cout << "counter: " << counter << endl;
            size_t found1 = s.find(delimiter,0);
            size_t found2 = s.find(delimiter,found1+1);
            size_t found3 = s.find(delimiter,found2+1);
            size_t found4 = s.find(delimiter,found3+1);
            string s1 = s.substr(found1+2, found2-found1-2); // mass
            string s2 = s.substr(found2+2, found3-found2-2); // pt
            string s3 = s.substr(found3+2, found4-found3-2); // met
            string s4 = s.substr(found4+2, -1); // sign
            cout << "s: " << s << endl;
            cout << "s1: " << s1 << endl;
            cout << "s2: " << s2 << endl;
            cout << "s3: " << s3 << endl;
            cout << "s4: " << s4 << endl;
            m[i1]   = stod(s1);
            pt[i1]  = stod(s2);
            met[i1] = stod(s3);
            sig[i1] = stod(s4);
            i1++;
        }else if(counter >= 5){
            break;
        }
        counter++;
    }
    MyReadFile2.close();
    //// end of extract events


    ///////////////////////////////////////////////////////////////////////////
    ///////// Calculate significance for all masses:
    cout << "Start make sign for all masses" << endl;
    ofstream MyFile;
    myname = "/afs/cern.ch/user/c/chugli/private/fast_sim/txt/kinematic_selection_wino_short_tot_"+fake_rate_s+".txt";
    MyFile.open(myname.c_str()); // Create and open a text file
    MyFile << "// higgsino/wino, mass, leading jet pt cut, met cut, sign \n";
    MyFile.close();
    cout<< endl << "******************** Round 1/4 *******************"<< endl;
    make_sign(fake_rate, pt[0]/10, met[0]/10, 0);
    make_sign(fake_rate, pt[0]/10, met[0]/10, 1);
    cout<< endl << "******************** Round 2/4 *******************"<< endl;
    make_sign(fake_rate, pt[1]/10, met[1]/10, 0);
    make_sign(fake_rate, pt[1]/10, met[1]/10, 1);
    cout<< endl << "******************** Round 3/4 *******************"<< endl;
    make_sign(fake_rate, pt[2]/10, met[2]/10, 0);
    make_sign(fake_rate, pt[2]/10, met[2]/10, 1);
    cout<< endl << "******************** Round 4/4 *******************"<< endl;
    make_sign(fake_rate, pt[3]/10, met[3]/10, 0);
    make_sign(fake_rate, pt[3]/10, met[3]/10, 1);

    cout<< endl << "******************** Finished !!! *******************"<< endl;

}

void make_higgsino(double fake_rate){
    ////////////////////////////////////////////////////////////////////////////
    //// Read .txt to extrect significance and cuts:
    ostringstream streamObj;
    streamObj << fake_rate;
    string fake_rate_s = streamObj.str();
    string myname = "/afs/cern.ch/user/c/chugli/private/fast_sim/txt/kinematic_selection_higgsino_short_"+fake_rate_s+".txt";
    cout << "Start reading " << myname << endl;

    ifstream MyReadFile2(myname.c_str());
    int counter = 0;
    int i1 = 0;
    int i2 = 0;
    Int_t n = 3;
    string s;
    string delimiter = ",";
    Double_t sig[n], pt[n], met[n], m[n];
    //mystring = "Wino, "+mass+", "+pt+", "+met+", "+sign+";"+"\n";
    while (getline (MyReadFile2, s)) {
        if(counter>0 && counter < 4){
          size_t found1 = s.find(delimiter,0);
          size_t found2 = s.find(delimiter,found1+1);
          size_t found3 = s.find(delimiter,found2+1);
          size_t found4 = s.find(delimiter,found3+1);
          string s1 = s.substr(found1+2, found2-found1-2); // mass
          string s2 = s.substr(found2+2, found3-found2-2); // pt
          string s3 = s.substr(found3+2, found4-found3-2); // met
          string s4 = s.substr(found4+2, -1); // sign
          // cout << "s: " << s << endl;
          // cout << "s1: " << s1 << endl;
          // cout << "s2: " << s2 << endl;
          // cout << "s3: " << s3 << endl;
          // cout << "s4: " << s4 << endl;
          m[i1]   = stod(s1);
          pt[i1]  = stod(s2);
          met[i1] = stod(s3);
          sig[i1] = stod(s4);
          i1++;
        }else if(counter >= 4){
            break;
        }
        counter++;
    }
    MyReadFile2.close();
    //// end of extract events

    ///////////////////////////////////////////////////////////////////////////
    ///////// Calculate significance for all masses:
    ofstream MyFile;
    myname = "/afs/cern.ch/user/c/chugli/private/fast_sim/txt/kinematic_selection_higgsino_short_tot_"+fake_rate_s+".txt";
    MyFile.open(myname.c_str()); // Create and open a text file
    MyFile << "// higgsino/wino, mass, leading jet pt cut, met cut, sign \n";
    MyFile.close();
    cout << endl << "*********** Round 1/3 *************" << endl;
    h_make_sign(fake_rate, pt[0]/10, met[0]/10);
    cout << endl << "*********** Round 2/3 *************" << endl;
    h_make_sign(fake_rate, pt[1]/10, met[1]/10);
    cout << endl << "*********** Round 3/3 *************" << endl;
    h_make_sign(fake_rate, pt[2]/10, met[2]/10);

    cout << endl << "*********** Finished *************" << endl;

}

void make_sign(double fake_rate, int a, int b, int part){
  /////////////////////////////////////////////////////////////////////////////
  /////////////////// BG part:
  // Read BG histograms
  cout << "********************* Start BG part *********************" << endl;

  string BGtype[5] = {"W+jets","Z+jets","ttbar","topsingle","multijets"};

  int mylength[5] = {7,7,10,1,9};

  string aa[] = {"0_150", "150_300", "300_500", "500_1000", "1000_2000", "2000_5000", "5000_100000"};
  string c[] = {"0_600", "600_1200", "1200_2100", "2100_3400", "3400_5300", "5300_8100", "8100_15000",
  "15000_25000", "25000_35000", "35000_100000"};
  string d[] = {""};
  string e[] = {"0_500", "500_1000", "1000_2000", "2000_4000", "4000_7200", "7200_15000",
  "15000_25000", "25000_35000", "35000_100000"};
  string *myfolders[5] = {aa,aa,c,d,e};

  TH2D* h2_BG_tot = new TH2D("", "", 4e3,0,4e4,4e3,0,4e4);

  for(int i=0; i<4;i++){
      const char* BGchar = BGtype[i].c_str();
      // cout << "********************* Start BG " << BGtype[i] << " *********************" << endl;

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
  cout << "********************* Start signal part *********************" << endl;
  ///// Read signal histograms:
  string ftype1  = "C1N1";
  string ftype2  = "C1C1";
  string f_middle[40];
  int index = 0;
  string mytitle[80];

  int i_start[2] = {0,20};
  int i_end[2]   = {20,40};

  cout << "********************* Start signal *********************" << endl;

  map<int, TH2D*> h2_sig;

  for(int i = i_start[part]; i < i_end[part]; i++){
      f_middle[i] = to_string(700+100*i);

      cout << "mass, i: " << ", " << f_middle[i] << ", " << i << endl;

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
  } // end of i

  ////////////////////////////////////////////////////////////////////////////////
  /////////// Significance calculation:

  int counter = 0;
  cout << "*************** Start Integrals *************" << endl;
  cout << "pt: " << a << "; " << "met: " << b << endl;
  a +=1;
  b +=1;

  double n_BG = h2_BG_tot->Integral(a,4e3,b,4e3);
  n_BG = n_BG*(fake_rate+1e-6); // considering the additional physical BG !!!
  n_BG = sqrt(n_BG);

  ofstream MyFile;
  ostringstream streamObj;
  streamObj << fake_rate;
  string fake_rate_s = streamObj.str();
  string myname = "/afs/cern.ch/user/c/chugli/private/fast_sim/txt/kinematic_selection_wino_short_tot_"+fake_rate_s+".txt";
  MyFile.open(myname.c_str(), ios_base::app); // Create and open a text file

  string mystring;

  // cout << "n_BG: " << n_BG << endl;

  for(int k=i_start[part]; k<i_end[part]; k++){
      double z = h2_sig[k]->Integral(a,4e3,b,4e3)/n_BG;
      // cout << "z int tot: " << h2_sig[k]->Integral(0,4e3,0,4e3) << endl;
      // cout << "z: " << k << ", "<< z << endl;
      ostringstream streamObj0;
      streamObj0 << z;
      string s = streamObj0.str();
      mystring = "Wino, "+to_string(700+100*k)+", "+(a-1)*10+", "+(b-1)*10+", "+z+";\n";
      cout << mystring << endl;
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

void h_make_sign(double fake_rate, int a, int b){
  /////////////////////////////////////////////////////////////////////////////
  /////////////////// BG part:
  // Read BG histograms
  cout << "********************* Start BG part *********************" << endl;

  string BGtype[5] = {"W+jets","Z+jets","ttbar","topsingle","multijets"};

  int mylength[5] = {7,7,10,1,9};

  string aa[] = {"0_150", "150_300", "300_500", "500_1000", "1000_2000", "2000_5000", "5000_100000"};
  string c[] = {"0_600", "600_1200", "1200_2100", "2100_3400", "3400_5300", "5300_8100", "8100_15000",
  "15000_25000", "25000_35000", "35000_100000"};
  string d[] = {""};
  string e[] = {"0_500", "500_1000", "1000_2000", "2000_4000", "4000_7200", "7200_15000",
  "15000_25000", "25000_35000", "35000_100000"};
  string *myfolders[5] = {aa,aa,c,d,e};

  TH2D* h2_BG_tot = new TH2D("", "", 4e3,0,4e4,4e3,0,4e4);

  for(int i=0; i<4;i++){
      const char* BGchar = BGtype[i].c_str();
      // cout << "********************* Start BG " << BGtype[i] << " *********************" << endl;

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
    string f_middle[9];
    string mytitle[18];
    string ftype1  = "C1N1";
    string ftype2  = "C1C1";

    map<int, TH2D*> h2_sig;

    cout << "********************* Start signal *********************" << endl;

    for(int i = 0; i < 9; i++){
        f_middle[i] = to_string(700+100*i);

        ///////////// Read histogram form .root:
        string filename = "/afs/cern.ch/user/c/chugli/private/fast_sim/histos/histo_kin_higgsino_" +ftype1+"_"+f_middle[i]+".root";
        const char* dirname = filename.c_str();
        TFile *f = new TFile(dirname);

        TH2D* h2_signal = (TH2D*)f->Get("h2_pred");
        string mytitle1 = ftype1+" "+f_middle[i]+" GeV";
        const char* ftype_c = mytitle1.c_str();
        h2_signal->SetTitle(ftype_c);

        filename = "/afs/cern.ch/user/c/chugli/private/fast_sim/histos/histo_kin_higgsino_" +ftype2+"_"+f_middle[i]+".root";
        const char* dirname2 = filename.c_str();
        TFile *f2 = new TFile(dirname2);

        TH2D* h2_signal2 = (TH2D*)f2->Get("h2_pred");
        string mytitle2 = ftype1+" "+f_middle[i]+" GeV";
        const char* ftype_c2 = mytitle2.c_str();
        h2_signal2->SetTitle(ftype_c2);

        // cout << h2_signal->GetEntries() << endl;
        // cout << h2_signal2->GetEntries() << endl;

        h2_signal->Add(h2_signal2);
        h2_sig[i] = h2_signal;

        // cout << "Entries: " << h2_signal->GetEntries() << endl;
    } // end of i



  ////////////////////////////////////////////////////////////////////////////////
  /////////// Significance calculation:

  int counter = 0;
  cout << "************ Start Integrals *************" << endl;
  cout << "a: " << a << ", " << "b: " << b << endl;
  a +=1;
  b +=1;

  double n_BG = h2_BG_tot->Integral(a,4e3,b,4e3);
  n_BG = n_BG*(fake_rate+1e-6); // considering the additional physical BG !!!
  n_BG = sqrt(n_BG);

  cout << "n_BG: " << n_BG << endl;

  ofstream MyFile;
  ostringstream streamObj;
  streamObj << fake_rate;
  string fake_rate_s = streamObj.str();
  string myname = "/afs/cern.ch/user/c/chugli/private/fast_sim/txt/kinematic_selection_higgsino_short_tot_"+fake_rate_s+".txt";
  MyFile.open(myname.c_str(), ios_base::app); // Create and open a text file

  string mystring;

  for(int k=0; k<9; k++){
      // cout << "mass: " << 700+100*k<< endl;
      // cout << "(a, b) " << a << ", " << b << endl;
      double z = h2_sig[k]->Integral(a,4e3,b,4e3)/n_BG;
      // cout << "signal: " << h2_sig[k]->Integral(0,4e3,0,4e3) << endl;
      // cout << "z: " << z << endl;
      // cout << "a, b: " << a << ", " << b << endl;
      // cout << "z: " << z << endl;
      ostringstream streamObj0;
      streamObj0 << z;
      string s = streamObj0.str();
      mystring = "Higgsino, "+to_string(700+100*k)+", "+(a-1)*10+", "+(b-1)*10+", "+z+";\n";
      cout << mystring << endl;
      MyFile << mystring;
  }

  MyFile.close();


  cout << "Delete" << endl;

  for(int i = 0; i < 9; i++){
    delete h2_sig[i];
  }
  delete h2_BG_tot;

  cout << "Finished" << endl;


}
