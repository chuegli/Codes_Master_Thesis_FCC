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
// kinematic_selection_wino_short_tot ... .txt
// kinematic_selection_higgsino_short_tot ... .txt
//
// 1) Reads kinematic_selection_wino/higgsino_short_tot
// 2) Plots them
////////////////////////////////////////////////////////////////////////////////

void graph_styling(TGraph* g, int j);
void h_graph_styling(TGraph* gr, int j);
void make_wino(double fake_rate);
void make_higgsino(double fake_rate);

void best_kin_short_plots(){
    double fake_rate = 2e-7; // corresonds to configuration: Nhits = 5, layout 3, pileup condition = <200>
    // // double fake_rate = 1e-5; // corresonds to configuration: Nhits = 5, layout 3, pileup condition = <500>
    //
    make_wino(fake_rate);
    make_higgsino(fake_rate);
    fake_rate = 1e-5; // corresonds to configuration: Nhits = 5, layout 3, pileup condition = <500>
    make_wino(fake_rate);
    make_higgsino(fake_rate);
    cout << "*********** Finished *************" << endl;
}

void make_wino(double fake_rate){
    ///////////////////////////////////////////////////////////////////////////
    //// Read .txt to extrect significance and cuts:
    ostringstream streamObj;
    streamObj << fake_rate;
    string fake_rate_s = streamObj.str();
    string myname = "/afs/cern.ch/user/c/chugli/private/fast_sim/txt/kinematic_selection_wino_short_tot_"+fake_rate_s+".txt";
    cout << "Start reading " << myname << endl;

    ifstream MyReadFile2(myname.c_str());
    int counter = 0;
    int i = 0;
    int j = 0;
    string s;
    string delimiter = ",";
    Double_t sign[4][40], pt[4][40], met[4][40], mass[4][40];
    // higgsino/wino, mass, leading jet pt cut, met cut, sign
    while (getline (MyReadFile2, s)) {
        if(counter>0 && counter < 161){
            cout << "counter: " << counter << endl;
            if(i==40){j++;i=0;}
            cout << "j, i: " << j <<", " << i << endl;
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

            mass[j][i] = stod(s1);
            pt[j][i]   = stod(s2);
            met[j][i]  = stod(s3);
            sign[j][i] = stod(s4);

            i++;
        }else if(counter >= 161){
            break;
        }
        counter++;
    }
    MyReadFile2.close();
    //// end of extract events


    ///////////////////////////////////////////////////////////////////////////
    Double_t sign_short1[4][32], mass_short1[4][32], sign_short2[4][22], mass_short2[4][22];

    for(int i=0; i<40;i++){
        if(i>=8){
          for(int j=0;j<4;j++){
            sign_short1[j][i-8] = sign[j][i];
            mass_short1[j][i-8] = mass[j][i];
          }
        }
        if(i>=18){
          for(int j=0;j<4;j++){
            sign_short2[j][i-18] = sign[j][i];
            mass_short2[j][i-18] = mass[j][i];
          }
        }
    }


    ///////////////////////////////////////////////////////////////////////////
    //// Plot everything:
    cout << "********************* Start plotting *********************" << endl;
    TCanvas *canvas = new TCanvas("c","");
    canvas->SetGrid();
    gPad->SetMargin(0.17,0.1,0.15,0.1);//l,r,b,t
    gStyle->SetOptTitle(0);
    gStyle->SetOptStat(0);

    TGraph *g0 = new TGraph(40, mass[0], sign[0]);
    TGraph *g1 = new TGraph(40, mass[1], sign[1]);
    TGraph *g2 = new TGraph(40, mass[2], sign[2]);
    TGraph *g3 = new TGraph(40, mass[3], sign[3]);

    TGraph *gs0 = new TGraph(32, mass_short1[0], sign_short1[0]);
    TGraph *gs1 = new TGraph(32, mass_short1[1], sign_short1[1]);
    TGraph *gs2 = new TGraph(32, mass_short1[2], sign_short1[2]);
    TGraph *gs3 = new TGraph(32, mass_short1[3], sign_short1[3]);

    TGraph *gss0 = new TGraph(22, mass_short2[0], sign_short2[0]);
    TGraph *gss1 = new TGraph(22, mass_short2[1], sign_short2[1]);
    TGraph *gss2 = new TGraph(22, mass_short2[2], sign_short2[2]);
    TGraph *gss3 = new TGraph(22, mass_short2[3], sign_short2[3]);

    g0->SetNameTitle("name", "1000");
    g1->SetNameTitle("name", "2000");
    g2->SetNameTitle("name", "3000");
    g3->SetNameTitle("name", "4000");

    gs0->SetNameTitle("name", "1000");
    gs1->SetNameTitle("name", "2000");
    gs2->SetNameTitle("name", "3000");
    gs3->SetNameTitle("name", "4000");

    gss0->SetNameTitle("name", "1000");
    gss1->SetNameTitle("name", "2000");
    gss2->SetNameTitle("name", "3000");
    gss3->SetNameTitle("name", "4000");

    graph_styling(g0, 1);
    graph_styling(g1, 2);
    graph_styling(g2, 3);
    graph_styling(g3, 4);

    graph_styling(gs0, 1);
    graph_styling(gs1, 2);
    graph_styling(gs2, 3);
    graph_styling(gs3, 4);

    graph_styling(gss0, 1);
    graph_styling(gss1, 2);
    graph_styling(gss2, 3);
    graph_styling(gss3, 4);

    string ss1 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/plot_sign_best_wino_"+fake_rate_s+".pdf[";
    string ss2 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/plot_sign_best_wino_"+fake_rate_s+".pdf";
    string ss3 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/plot_sign_best_wino_"+fake_rate_s+".pdf]";

    double limits_max[3];
    double limits_min[3];
    double la1[3] = {700,300,1e4};
    double li1[3] = {0,0,1e-2};
    double la2[3] = {1800,700,1e4};
    double li2[3] = {0,0,1e-2};
    if(fake_rate==1e-5){
      for(int i=0;i<3;i++){
        limits_max[i] = la1[i];
        limits_min[i] = li1[i];
      }
    }
    else{
      for(int i=0;i<3;i++){
        limits_max[i] = la2[i];
        limits_min[i] = li2[i];
      }
    }

    gs0->SetMaximum(limits_max[0]);
    gs0->SetMinimum(limits_min[0]);
    gs0->Draw("AP");
    gs1->Draw("same P");
    gs2->Draw("same P");
    gs3->Draw("same P");
    gPad->Update();
    canvas->BuildLegend(0.7,0.7,0.9,0.9);
    canvas->SaveAs(ss1.c_str());
    canvas->SaveAs(ss2.c_str());
    canvas->Clear();

    gss0->SetMaximum(limits_max[1]);
    gss0->SetMinimum(limits_min[1]);
    gss0->Draw("AP");
    gss1->Draw("same P");
    gss2->Draw("same P");
    gss3->Draw("same P");
    gPad->Update();
    canvas->BuildLegend(0.7,0.7,0.9,0.9);
    canvas->SaveAs(ss2.c_str());
    canvas->Clear();

    canvas->SetLogy();

    g0->SetMaximum(limits_max[2]);
    g0->SetMinimum(limits_min[2]);
    g0->Draw("AP");
    g1->Draw("same P");
    g2->Draw("same P");
    g3->Draw("same P");
    gPad->Update();
    canvas->BuildLegend(0.7,0.7,0.9,0.9);
    canvas->SaveAs(ss2.c_str());
    canvas->SaveAs(ss3.c_str());
    canvas->Close();

}

void make_higgsino(double fake_rate){
    ///////////////////////////////////////////////////////////////////////////
    //// Read .txt to extrect significance and cuts:
    ostringstream streamObj;
    streamObj << fake_rate;
    string fake_rate_s = streamObj.str();
    string myname = "/afs/cern.ch/user/c/chugli/private/fast_sim/txt/kinematic_selection_higgsino_short_tot_"+fake_rate_s+".txt";
    cout << "Start reading " << myname << endl;

    ifstream MyReadFile2(myname.c_str());
    int counter = 0;
    int i = 0;
    int j = 0;
    string s;
    string delimiter = ",";
    Double_t sign[3][9], pt[3][9], met[3][9], mass[3][9];
    // higgsino/wino, mass, leading jet pt cut, met cut, sign
    while (getline (MyReadFile2, s)) {
        if(counter>0 && counter < 28){
            cout << "counter: " << counter << endl;
            if(i==9){j++;i=0;}
            cout << "j, i: " << j <<", " << i << endl;
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

            mass[j][i] = stod(s1);
            pt[j][i]   = stod(s2);
            met[j][i]  = stod(s3);
            sign[j][i] = stod(s4);

            i++;
        }else if(counter >= 28){
            break;
        }
        counter++;
    }
    MyReadFile2.close();
    //// end of extract events

    ///////////////////////////////////////////////////////////////////////////
    //// Plot everything:
    cout << "********************* Start plotting *********************" << endl;
    TCanvas *canvas = new TCanvas("c","");
    canvas->SetGrid();
    gPad->SetMargin(0.15,0.1,0.15,0.1);//l,r,b,t
    gStyle->SetOptTitle(0);
    gStyle->SetOptStat(0);

    // mass[6][9]: mass[0-2][:]= C1N1, mass[3-5][:]=C1C1
    // mass[6][9]: mass[:][0] = 700, => 800,900,1000,...,1500
    TGraph *g0 = new TGraph(9, mass[0], sign[0]);
    TGraph *g1 = new TGraph(9, mass[1], sign[1]);
    TGraph *g2 = new TGraph(9, mass[2], sign[2]);

    g0->SetNameTitle("name", "700");
    g1->SetNameTitle("name", "1000");
    g2->SetNameTitle("name", "1500");

    h_graph_styling(g0, 1);
    h_graph_styling(g1, 2);
    h_graph_styling(g2, 3);

    string ss1 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/plot_sign_best_higgsino_"+fake_rate_s+".pdf[";
    string ss2 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/plot_sign_best_higgsino_"+fake_rate_s+".pdf";
    string ss3 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/kinematic_selection/plot_sign_best_higgsino_"+fake_rate_s+".pdf]";

    double limits_max[2];
    double limits_min[2];
    double la1[2] = {70,100};
    double li1[2] = {0,1e-2};
    double la2[2] = {100,500};
    double li2[2] = {0,1e-2};
    if(fake_rate==1e-5){
      for(int i=0;i<2;i++){
        limits_max[i] = la1[i];
        limits_min[i] = li1[i];
      }
    }
    else{
      for(int i=0;i<2;i++){
        limits_max[i] = la2[i];
        limits_min[i] = li2[i];
      }
    }

    g0->SetMaximum(limits_max[0]);
    g0->SetMinimum(limits_min[0]);
    g0->Draw("AP");
    g1->Draw("same P");
    g2->Draw("same P");
    gPad->Update();
    canvas->BuildLegend(0.7,0.7,0.9,0.9);
    canvas->SaveAs(ss1.c_str());
    canvas->SaveAs(ss2.c_str());
    canvas->Clear();

    canvas->SetLogy();

    g0->SetMaximum(limits_max[1]);
    g0->SetMinimum(limits_min[1]);
    g0->Draw("AP");
    g1->Draw("same P");
    g2->Draw("same P");
    gPad->Update();
    canvas->BuildLegend(0.7,0.7,0.9,0.9);
    canvas->SaveAs(ss2.c_str());
    canvas->SaveAs(ss3.c_str());
    canvas->Close();

}


void graph_styling(TGraph* gr, int j){
  if(j==5){j=94;}
  gr->SetLineColor(j);
  gr->SetLineWidth(1);
  gr->SetMarkerColor(j);
  gr->SetMarkerSize(1);
  gr->SetMarkerStyle(8);
  gr->GetXaxis()->SetTitle("Wino mass");
  gr->GetYaxis()->SetTitle("Significance");
  gr->GetYaxis()->SetLabelSize(0.05);
  gr->GetXaxis()->SetLabelSize(0.05);
  gr->GetYaxis()->SetTitleSize(0.05);
  gr->GetXaxis()->SetTitleSize(0.05);
  // gr->GetXaxis()->SetNdivisions(5,10,1);
}

void h_graph_styling(TGraph* gr, int j){
  if(j==5){j=94;}
  gr->SetLineColor(j);
  gr->SetLineWidth(1);
  gr->SetMarkerColor(j);
  gr->SetMarkerSize(1);
  gr->SetMarkerStyle(8);
  gr->GetXaxis()->SetTitle("Higgsino mass");
  gr->GetYaxis()->SetTitle("Significance");
  gr->GetYaxis()->SetLabelSize(0.05);
  gr->GetXaxis()->SetLabelSize(0.05);
  gr->GetYaxis()->SetTitleSize(0.05);
  gr->GetXaxis()->SetTitleSize(0.05);
}
