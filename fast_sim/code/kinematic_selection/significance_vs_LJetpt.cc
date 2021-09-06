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

void make_sign(double fake_rate, int part);
void h_make_sign(double fake_rate, string ftype);
void make_wino(double fake_rate);
void make_higgsino(double fake_rate);

void make_wino_plots(double fake_rate, string ftype);
void make_higgsino_plots(double fake_rate, string ftype);

void significance_vs_LJetpt(){
    double fake_rate = 2e-7; // corresonds to configuration: Nhits = 5, layout 3, pileup condition = <200>
    // double fake_rate = 1e-5; // corresonds to configuration: Nhits = 5, layout 3, pileup condition = <500>

    cout << "*********** Wino 2e-7 *************" << endl;
    make_wino(fake_rate);
    cout << "*********** Higgsino 2e-7 *************" << endl;
    make_higgsino(fake_rate);

    make_higgsino_plots(fake_rate, "C1N1");
    make_higgsino_plots(fake_rate, "C1C1");
    make_wino_plots(fake_rate, "C1N1");
    make_wino_plots(fake_rate, "C1C1");

    fake_rate = 1e-5;
    cout << "*********** Wino 1e-5 *************" << endl;
    make_wino(fake_rate);
    cout << "*********** Higgsino 1e-5 *************" << endl;
    make_higgsino(fake_rate);

    make_higgsino_plots(fake_rate, "C1N1");
    make_higgsino_plots(fake_rate, "C1C1");
    make_wino_plots(fake_rate, "C1N1");
    make_wino_plots(fake_rate, "C1C1");
    cout << "*********** Finished *************" << endl;
}

void make_wino(double fake_rate){
    ///////////////////////////////////////////////////////////////////////////
    ///////// Calculate significance for all masses:
    cout << "Start make sign vs pt" << endl;
    ostringstream streamObj;
    streamObj << fake_rate;
    string fake_rate_s = streamObj.str();
    ofstream MyFile;
    string myname = "/afs/cern.ch/user/c/chugli/private/txt/wino_sign_vs_pt_C1C1_"+fake_rate_s+".txt";
    MyFile.open(myname.c_str()); // Create and open a text file
    MyFile << "// Wino with mass 3 TeV \n";
    MyFile << "// leading jet pt, n_BG, n_sig, significance \n";
    MyFile.close();
    ofstream MyFile2;
    myname = "/afs/cern.ch/user/c/chugli/private/txt/wino_sign_vs_pt_C1N1_"+fake_rate_s+".txt";
    MyFile2.open(myname.c_str()); // Create and open a text file
    MyFile2 << "// Wino with mass 3 TeV \n";
    MyFile2 << "// leading jet pt, n_BG, n_sig, significance \n";
    MyFile2.close();
    make_sign(fake_rate, 0); // C1N1
    make_sign(fake_rate, 2); // C1C1
    cout<< endl << "******************** Finished !!! *******************"<< endl;

}

void make_sign(double fake_rate, int part){
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

  for(int i=0; i<4; i++){
      const char* BGchar = BGtype[i].c_str();
      // cout << "********************* Start BG " << BGtype[i] << " *********************" << endl;

      for(int j=0; j<mylength[i]; j++){
          string filename = "/afs/cern.ch/user/c/chugli/private/histos/histo_kin_" +BGtype[i]+"_"+myfolders[i][j]+".root";
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
  string f_type1  = "C1N1";
  string f_type2  = "C1C1";
  int index = 0;
  string ftype;

  int I;

  if(part==0 || part==1){
    ftype=f_type1;
    I = 23;
  }else{
    ftype=f_type2;
    I = 62;
  }

  cout << "********************* Start signal " << ftype << " *********************" << endl;

  map<int, TH2D*> h2_sig;

  string f_middle = "3000";
  string mytitle = ftype+" "+f_middle+" GeV";
  const char* ftype_c = mytitle.c_str();

  cout << "signal type, mass, I: " << ftype << ", " << f_middle << ", " << I << endl;

  ///////////// Read histogram form .root:
  string filename = "/afs/cern.ch/user/c/chugli/private/histos/histo_kin_" +ftype+"_"+f_middle+".root";
  const char* dirname = filename.c_str();
  TFile *f = new TFile(dirname);

  TH2D* h2_signal = (TH2D*)f->Get("h2_pred");
  h2_signal->SetTitle(ftype_c);

  h2_sig[I] = h2_signal;


  ////////////////////////////////////////////////////////////////////////////////
  /////////// Significance calculation:
  cout << "*************** Significance *************" << endl;

  ofstream MyFile;
  ostringstream streamObj;
  streamObj << fake_rate;
  string fake_rate_s = streamObj.str();
  string myname = "/afs/cern.ch/user/c/chugli/private/txt/wino_sign_vs_pt_"+ftype+"_"+fake_rate_s+".txt";
  MyFile.open(myname.c_str(), ios_base::app); // Create and open a text file

  TH1D* h1_BG = h2_BG_tot->ProjectionX("projX_BG");
  TH1D* h1_sig = h2_sig[I]->ProjectionX("projX_sig");

  h1_BG->SetFillColor(2);
  h1_sig->SetFillColor(3);
  h1_BG->SetLineColor(2);
  h1_sig->SetLineColor(3);

  string myname1 = "/afs/cern.ch/user/c/chugli/private/plots/kinematic_selection/wino_sign_pt_BG_sig_"+ftype+"_"+fake_rate_s+".pdf[";
  string myname2 = "/afs/cern.ch/user/c/chugli/private/plots/kinematic_selection/wino_sign_pt_BG_sig_"+ftype+"_"+fake_rate_s+".pdf";
  string myname3 = "/afs/cern.ch/user/c/chugli/private/plots/kinematic_selection/wino_sign_pt_BG_sig_"+ftype+"_"+fake_rate_s+".pdf]";


  TCanvas *canvas = new TCanvas("c","");
  canvas->SetLogy();
  canvas->SetGrid();
  gPad->SetMargin(0.15,0.15,0.12,0.1);//l,r,b,t
  gStyle->SetOptStat(0);

  h1_BG->Draw("h hist");
  h1_sig->Draw("h hist same");
  canvas->BuildLegend();
  gPad->Update();
  canvas->SaveAs(myname1.c_str());
  canvas->SaveAs(myname2.c_str());
  canvas->Clear();

  h1_BG->Draw("h hist");
  // canvas->BuildLegend();
  gPad->Update();
  canvas->SaveAs(myname2.c_str());
  canvas->Clear();

  h1_sig->Draw("h hist");
  // canvas->BuildLegend();
  gPad->Update();
  canvas->SaveAs(myname2.c_str());
  canvas->SaveAs(myname3.c_str());
  canvas->Close();

  for(int i=0; i<4e3;i++){
  // for(int i=0; i<10;i++){
      double pt=i*10+5;
      ostringstream streamObj0;
      streamObj0 << pt;
      string s1 = streamObj0.str();

      double z = h1_sig->GetBinContent(i);
      double b = h1_BG->GetBinContent(i);
      // cout << "Signal: " << z << ", BG: " << b << endl;
      b = b*(fake_rate+1e-6);
      double r;
      if(b!=0){r= z/sqrt(b);}
      else{r=-1;}
      // cout << "Significance: " << r << endl;

      ostringstream streamObj1;
      streamObj1 << r;
      string s = streamObj1.str();
      ostringstream streamObj2;
      streamObj2 << b;
      string b_s = streamObj2.str();
      ostringstream streamObj3;
      streamObj3 << z;
      string z_s = streamObj3.str();

      string mystring = s1+", "+b_s+", "+z_s+", "+s+";\n";
      MyFile << mystring;

      // cout << "mystring: " << mystring << endl;

      if(i%1000==0){cout << i<< endl;cout << mystring << endl;}
  }

  MyFile.close();

  cout << "Delete" << endl;

  delete h2_sig[I];
  delete h2_BG_tot;
  delete h1_BG;
  delete h1_sig;

  cout << "Finished" << endl;

}

void make_higgsino(double fake_rate){
    ///////////////////////////////////////////////////////////////////////////
    ///////// Calculate significance for all masses:
    ostringstream streamObj;
    streamObj << fake_rate;
    string fake_rate_s = streamObj.str();
    ofstream MyFile;
    string myname = "/afs/cern.ch/user/c/chugli/private/txt/higgsino_sign_vs_pt_C1N1_"+fake_rate_s+".txt";
    MyFile.open(myname.c_str()); // Create and open a text file
    MyFile << "// higgsino/wino, mass, C1C1/C1N1, leading jet pt cut, met cut, sign \n";
    MyFile.close();
    ofstream MyFile2;
    myname = "/afs/cern.ch/user/c/chugli/private/txt/higgsino_sign_vs_pt_C1C1_"+fake_rate_s+".txt";
    MyFile2.open(myname.c_str()); // Create and open a text file
    MyFile2 << "// higgsino/wino, mass, C1C1/C1N1, leading jet pt cut, met cut, sign \n";
    MyFile2.close();
    cout << endl << "*********** Round 1/2 *************" << endl;
    h_make_sign(fake_rate, "C1N1");
    cout << endl << "*********** Round 2/2 *************" << endl;
    h_make_sign(fake_rate, "C1C1");
    cout << endl << "*********** Finished *************" << endl;

}

void h_make_sign(double fake_rate, string ftype){
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
          string filename = "/afs/cern.ch/user/c/chugli/private/histos/histo_kin_" +BGtype[i]+"_"+myfolders[i][j]+".root";
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

    map<int, TH2D*> h2_sig;

    cout << "********************* Start signal " << ftype << " *********************" << endl;

    int I;
    if(ftype=="C1N1"){I=3;}
    else{I=12;}

    string f_middle = "1000";
    string mytitle = ftype+" "+f_middle+" GeV";
    const char* ftype_c = mytitle.c_str();

    ///// Read the .root file:
    string filename = "/afs/cern.ch/user/c/chugli/private/histos/histo_kin_higgsino_" +ftype+"_"+f_middle+".root";
    const char* dirname = filename.c_str();
    TFile *f = new TFile(dirname);

    TH2D* h2_signal = (TH2D*)f->Get("h2_pred");
    h2_signal->SetTitle(ftype_c);

    h2_sig[I] = h2_signal;


    ////////////////////////////////////////////////////////////////////////////////
    /////////// Significance calculation:
    cout << "*************** Significance *************" << endl;

    ofstream MyFile;
    ostringstream streamObj;
    streamObj << fake_rate;
    string fake_rate_s = streamObj.str();
    string myname = "/afs/cern.ch/user/c/chugli/private/txt/higgsino_sign_vs_pt_"+ftype+"_"+fake_rate_s+".txt";
    MyFile.open(myname.c_str(), ios_base::app); // Create and open a text file

    TH1D* h1_BG = h2_BG_tot->ProjectionX("projX_BG");
    TH1D* h1_sig = h2_sig[I]->ProjectionX("projX_sig");

    h1_BG->SetFillColor(2);
    h1_sig->SetFillColor(3);
    h1_BG->SetLineColor(2);
    h1_sig->SetLineColor(3);

    string myname1 = "/afs/cern.ch/user/c/chugli/private/plots/kinematic_selection/higgsino_sign_pt_BG_sig_"+ftype+"_"+fake_rate_s+".pdf[";
    string myname2 = "/afs/cern.ch/user/c/chugli/private/plots/kinematic_selection/higgsino_sign_pt_BG_sig_"+ftype+"_"+fake_rate_s+".pdf";
    string myname3 = "/afs/cern.ch/user/c/chugli/private/plots/kinematic_selection/higgsino_sign_pt_BG_sig_"+ftype+"_"+fake_rate_s+".pdf]";

    TCanvas *canvas = new TCanvas("c","");
    canvas->SetLogy();
    canvas->SetGrid();
    gPad->SetMargin(0.15,0.15,0.12,0.1);//l,r,b,t
    gStyle->SetOptStat(0);

    h1_BG->Draw("h hist");
    h1_sig->Draw("h hist same");
    canvas->BuildLegend();
    gPad->Update();
    canvas->SaveAs(myname1.c_str());
    canvas->SaveAs(myname2.c_str());
    canvas->Clear();

    h1_BG->Draw("h hist");
    // canvas->BuildLegend();
    gPad->Update();
    canvas->SaveAs(myname2.c_str());
    canvas->Clear();

    h1_sig->Draw("h hist");
    // canvas->BuildLegend();
    gPad->Update();
    canvas->SaveAs(myname2.c_str());
    canvas->SaveAs(myname3.c_str());
    canvas->Close();

    for(int i=0; i<4e3;i++){
    // for(int i=0; i<10;i++){
        double pt=i*10+5;
        ostringstream streamObj0;
        streamObj0 << pt;
        string s1 = streamObj0.str();

        double z = h1_sig->GetBinContent(i);
        double b = h1_BG->GetBinContent(i);
        // cout << "Signal: " << z << ", BG: " << b << endl;
        b = b*(fake_rate+1e-6);
        double r;
        if(b!=0){r= z/sqrt(b);}
        else{r=-1;}
        // cout << "Significance: " << r << endl;

        ostringstream streamObj1;
        streamObj1 << r;
        string s = streamObj1.str();
        ostringstream streamObj2;
        streamObj2 << b;
        string b_s = streamObj2.str();
        ostringstream streamObj3;
        streamObj3 << z;
        string z_s = streamObj3.str();

        string mystring = s1+", "+b_s+", "+z_s+", "+s+";\n";
        MyFile << mystring;

        // cout << "mystring: " << mystring << endl;

        if(i%1000==0){cout << i<< endl;cout << mystring << endl;}
    }

    MyFile.close();

    cout << "Delete" << endl;

    delete h2_sig[I];
    delete h2_BG_tot;
    delete h1_BG;
    delete h1_sig;

    cout << "Finished" << endl;
}

void make_wino_plots(double fake_rate, string ftype){
  ////////////////////////////////////////////////////////////////////////////
  //// Read .txt to extrect significance and cuts:
  ostringstream streamObj;
  streamObj << fake_rate;
  string fake_rate_s = streamObj.str();
  string myname = "/afs/cern.ch/user/c/chugli/private/txt/wino_sign_vs_pt_"+ftype+"_"+fake_rate_s+".txt";
  cout << "Start reading " << myname << endl;

  ifstream MyReadFile2(myname.c_str());
  int counter = 0;
  int i = 0;
  Int_t n = 4e3;
  string s;
  string delimiter = ",";
  Double_t pt[n], BG[n], sig[n], significance[n];
  // leading jet pt, n_BG, n_sig, significance
  while (getline (MyReadFile2, s)) {
      if(counter>1 && counter < 4002){
          // cout << "counter: " << counter << endl;
          size_t found1 = s.find(delimiter,0);
          size_t found2 = s.find(delimiter,found1+1);
          size_t found3 = s.find(delimiter,found2+1);
          string s1 = s.substr(0, found1); // pt
          string s2 = s.substr(found1+2, found2-found1-2); // BG
          string s3 = s.substr(found2+2, found3-found2-2); // signal
          string s4 = s.substr(found3+2, -2); // significance
          // cout << "s: " << s << endl;
          // cout << "s1: " << s1 << endl;
          // cout << "s2: " << s2 << endl;
          // cout << "s3: " << s3 << endl;
          // cout << "s4: " << s4 << endl;
          pt[i]           = stod(s1);
          BG[i]           = stod(s2);
          sig[i]          = stod(s3);
          significance[i] = stod(s4);
          i++;
      }else if(counter >= 4002){
          break;
      }
      counter++;
  }
  MyReadFile2.close();
  //// end of extract events

  ///////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////
  cout << "********************* Start plotting *********************" << endl;
  TCanvas *canvas = new TCanvas("c","");
  canvas->SetGrid();
  gPad->SetMargin(0.15,0.15,0.12,0.1);//l,r,b,t
  canvas->SetLogy();
  canvas->SetLogx();
  // gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  TGraph *g0 = new TGraph(4000, pt, BG);
  TGraph *g1 = new TGraph(4000, pt, sig);
  TGraph *g2 = new TGraph(4000, pt, significance);

  g0->SetLineColor(1);
  g0->SetFillColor(2);
  g0->SetMarkerColor(3);
  g0->SetMarkerSize(0.7);
  g0->SetMarkerStyle(8);

  g1->SetLineColor(1);
  g1->SetFillColor(3);
  g1->SetMarkerColor(4);
  g1->SetMarkerSize(0.7);
  g1->SetMarkerStyle(8);

  g2->SetLineColor(1);
  g2->SetFillColor(4);
  g2->SetMarkerColor(5);
  g2->SetMarkerSize(0.7);
  g2->SetMarkerStyle(8);

  string ss1 = "/afs/cern.ch/user/c/chugli/private/plots/kinematic_selection/wino_sign_vs_pt_"+ftype+"_"+fake_rate_s+".pdf[";
  string ss2 = "/afs/cern.ch/user/c/chugli/private/plots/kinematic_selection/wino_sign_vs_pt_"+ftype+"_"+fake_rate_s+".pdf";
  string ss3 = "/afs/cern.ch/user/c/chugli/private/plots/kinematic_selection/wino_sign_vs_pt_"+ftype+"_"+fake_rate_s+".pdf]";

  g0->SetMinimum(1);
  g0->SetMaximum(1e9);
  g0->Draw("AB");
  gPad->Update();
  g0->SetTitle("BG events; Leading jet p_T [GeV]; # BG events");
  g0->GetYaxis()->SetLabelSize(0.05);
  g0->GetXaxis()->SetLabelSize(0.05);
  g0->GetYaxis()->SetTitleSize(0.05);
  g0->GetXaxis()->SetTitleSize(0.05);
  canvas->SaveAs(ss1.c_str());
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  g1->SetMinimum(1e-2);
  g1->SetMaximum(1e3);
  g1->Draw("AB");
  gPad->Update();
  g1->SetTitle("Signal events; Leading jet p_T [GeV]; # signal events");
  g1->GetYaxis()->SetLabelSize(0.05);
  g1->GetXaxis()->SetLabelSize(0.05);
  g1->GetYaxis()->SetTitleSize(0.05);
  g1->GetXaxis()->SetTitleSize(0.05);
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  g2->Draw("AB");
  gPad->Update();
  g2->SetTitle("Significance; Leading jet p_T [GeV]; Significance");
  g2->GetYaxis()->SetLabelSize(0.05);
  g2->GetXaxis()->SetLabelSize(0.05);
  g2->GetYaxis()->SetTitleSize(0.05);
  g2->GetXaxis()->SetTitleSize(0.05);
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  g0->SetMinimum(1e-2);
  g0->SetMaximum(1e9);
  g0->Draw("AB");
  g1->Draw("SAME B");
  gPad->Update();
  g0->SetTitle("BG events; Leading jet p_T [GeV]; # BG/signal events");
  g1->SetTitle("Signal events; Leading jet p_T [GeV]; # BG/signal events");
  canvas->SaveAs(ss2.c_str());
  canvas->SaveAs(ss3.c_str());
}

void make_higgsino_plots(double fake_rate, string ftype){
  ////////////////////////////////////////////////////////////////////////////
  //// Read .txt to extrect significance and cuts:
  ostringstream streamObj;
  streamObj << fake_rate;
  string fake_rate_s = streamObj.str();
  string myname = "/afs/cern.ch/user/c/chugli/private/txt/higgsino_sign_vs_pt_"+ftype+"_"+fake_rate_s+".txt";
  cout << "Start reading " << myname << endl;

  ifstream MyReadFile2(myname.c_str());
  int counter = 0;
  int i = 0;
  Int_t n = 4e3-1;
  string s;
  string delimiter = ",";
  Double_t pt[n], BG[n], sig[n], significance[n];
  // leading jet pt, n_BG, n_sig, significance
  while (getline (MyReadFile2, s)) {
      if(counter>1 && counter < 4002){
          // cout << "counter: " << counter << endl;
          size_t found1 = s.find(delimiter,0);
          size_t found2 = s.find(delimiter,found1+1);
          size_t found3 = s.find(delimiter,found2+1);
          string s1 = s.substr(0, found1); // pt
          string s2 = s.substr(found1+2, found2-found1-2); // BG
          string s3 = s.substr(found2+2, found3-found2-2); // signal
          string s4 = s.substr(found3+2, -2); // significance
          // cout << "s: " << s << endl;
          // cout << "s1: " << s1 << endl;
          // cout << "s2: " << s2 << endl;
          // cout << "s3: " << s3 << endl;
          // cout << "s4: " << s4 << endl;
          pt[i]           = stod(s1);
          BG[i]           = stod(s2);
          sig[i]          = stod(s3);
          significance[i] = stod(s4);
          // cout << "i: " << i << endl;
          // cout << "pt: " << pt[i] << endl;
          i++;
      }else if(counter >= 4002){
          break;
      }
      counter++;
  }
  MyReadFile2.close();
  //// end of extract events

  ///////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////
  cout << "********************* Start plotting *********************" << endl;
  TCanvas *canvas = new TCanvas("c","");
  canvas->SetGrid();
  gPad->SetMargin(0.15,0.15,0.12,0.1);//l,r,b,t
  canvas->SetLogy();
  canvas->SetLogx();
  // gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  TGraph *g0 = new TGraph(4000-1, pt, BG);
  TGraph *g1 = new TGraph(4000-1, pt, sig);
  TGraph *g2 = new TGraph(4000-1, pt, significance);

  g0->SetLineColor(1);
  g0->SetFillColor(2);
  g0->SetMarkerColor(3);
  g0->SetMarkerSize(0.7);
  g0->SetMarkerStyle(8);

  g1->SetLineColor(1);
  g1->SetFillColor(3);
  g1->SetMarkerColor(4);
  g1->SetMarkerSize(0.7);
  g1->SetMarkerStyle(8);

  g2->SetLineColor(1);
  g2->SetFillColor(4);
  g2->SetMarkerColor(5);
  g2->SetMarkerSize(0.7);
  g2->SetMarkerStyle(8);

  string ss1 = "/afs/cern.ch/user/c/chugli/private/plots/kinematic_selection/higgsino_sign_vs_pt_"+ftype+"_"+fake_rate_s+".pdf[";
  string ss2 = "/afs/cern.ch/user/c/chugli/private/plots/kinematic_selection/higgsino_sign_vs_pt_"+ftype+"_"+fake_rate_s+".pdf";
  string ss3 = "/afs/cern.ch/user/c/chugli/private/plots/kinematic_selection/higgsino_sign_vs_pt_"+ftype+"_"+fake_rate_s+".pdf]";

  g0->SetMinimum(1e-2);
  g0->SetMaximum(1e9);
  g0->Draw("AB");
  gPad->Update();
  g0->SetTitle("BG events; Leading jet p_T [GeV]; # BG events");
  g0->GetYaxis()->SetLabelSize(0.05);
  g0->GetXaxis()->SetLabelSize(0.05);
  g0->GetYaxis()->SetTitleSize(0.05);
  g0->GetXaxis()->SetTitleSize(0.05);
  canvas->SaveAs(ss1.c_str());
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  g1->SetMinimum(1e-2);
  g1->SetMaximum(1e1);
  g1->Draw("AB");
  gPad->Update();
  g1->SetTitle("Signal events; Leading jet p_T [GeV]; # signal events");
  g1->GetYaxis()->SetLabelSize(0.05);
  g1->GetXaxis()->SetLabelSize(0.05);
  g1->GetYaxis()->SetTitleSize(0.05);
  g1->GetXaxis()->SetTitleSize(0.05);
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  g2->Draw("AB");
  gPad->Update();
  g2->SetTitle("Significance; Leading jet p_T [GeV]; Significance");
  g2->GetYaxis()->SetLabelSize(0.05);
  g2->GetXaxis()->SetLabelSize(0.05);
  g2->GetYaxis()->SetTitleSize(0.05);
  g2->GetXaxis()->SetTitleSize(0.05);
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  g0->SetMinimum(1e-2);
  g0->SetMaximum(1e9);
  g0->Draw("AB");
  g1->Draw("SAME B");
  gPad->Update();
  g0->SetTitle("BG events; Leading jet p_T [GeV]; # BG/signal events");
  g1->SetTitle("Signal events; Leading jet p_T [GeV]; # BG/signal events");
  canvas->SaveAs(ss2.c_str());
  canvas->SaveAs(ss3.c_str());
}
