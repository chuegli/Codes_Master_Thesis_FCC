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
//
////////////////////////////////////////////////////////////////////////////////

void graph_styling(TGraph* g, int j);
void h_graph_styling(TGraph* gr, int j);
void make_wino(double fake_rate);
void make_higgsino(double fake_rate);

void best_kin_plots(){
    double fake_rate = 2e-7; // corresonds to configuration: Nhits = 5, layout 3, pileup condition = <200>
    // double fake_rate = 1e-5; // corresonds to configuration: Nhits = 5, layout 3, pileup condition = <500>

    make_wino(fake_rate);
    // make_higgsino(fake_rate);
    cout << "*********** Finished *************" << endl;
}

void make_wino(double fake_rate){
    ///////////////////////////////////////////////////////////////////////////
    //// Read .txt to extrect significance and cuts:
    ostringstream streamObj;
    streamObj << fake_rate;
    string fake_rate_s = streamObj.str();
    string myname = "/afs/cern.ch/user/c/chugli/private/txt/kinematic_selection_wino_"+fake_rate_s+".txt";
    cout << "Start reading " << myname << endl;

    ifstream MyReadFile2(myname.c_str());
    int counter = 0;
    int i = 0;
    int j = 0;
    string s;
    string delimiter = ",";
    double sign[40], pt[40], met[40], mass[40];
    // higgsino/wino, mass, C1C1/C1N1, leading jet pt cut, met cut, sign
    while (getline (MyReadFile2, s)) {
        if(counter>0 && counter < 40){
            cout << "counter: " << counter << endl;
            cout << "i: " << i << endl;
            // if(i==40){j++;i=0;}
            // cout << "j, i: " << j <<", " << i << endl;
            size_t found1 = s.find(delimiter,0);
            size_t found2 = s.find(delimiter,found1+1);
            size_t found3 = s.find(delimiter,found2+1);
            size_t found4 = s.find(delimiter,found3+1);
            size_t found5 = s.find(delimiter,found4+1);
            string s2 = s.substr(found1+2, found2-found1-2); // type
            string s3 = s.substr(found2+2, found3-found2-2); // mass
            string s4 = s.substr(found3+2, found4-found3-2); // pt
            string s5 = s.substr(found4+2, found5-found4-2); // met
            string s6 = s.substr(found5+2, -1); // sign
            cout << "s: " << s << endl;
            cout << "s2: " << s2 << endl;
            cout << "s3: " << s3 << endl;
            cout << "s4: " << s4 << endl;
            cout << "s5: " << s5 << endl;
            cout << "s6: " << s6 << endl;

            // mass[j][i] = stod(s2);
            // pt[j][i]   = stod(s4);
            // met[j][i]  = stod(s5);
            // sign[j][i] = stod(s6);

            mass[i] = stod(s3);
            pt[i]   = stod(s4);
            met[i]  = stod(s5);
            sign[i] = stod(s6);

            i++;
        }else if(counter >= 40){
            break;
        }
        counter++;
    }
    MyReadFile2.close();
    //// end of extract events


    // ///////////////////////////////////////////////////////////////////////////
    // Double_t sign_short1[8][32], mass_short1[8][32], sign_short2[8][22], mass_short2[8][22];
    //
    // for(int i=0; i<40;i++){
    //     if(i>=8){
    //       for(int j=0;j<8;j++){
    //         sign_short1[j][i-8] = sign[j][i];
    //         mass_short1[j][i-8] = mass[j][i];
    //       }
    //     }
    //     if(i>=18){
    //       for(int j=0;j<8;j++){
    //         sign_short2[j][i-18] = sign[j][i];
    //         mass_short2[j][i-18] = mass[j][i];
    //       }
    //     }
    // }


    ///////////////////////////////////////////////////////////////////////////
    //// Plot everything:
    cout << "********************* Start plotting *********************" << endl;
    TCanvas *canvas = new TCanvas("c","");
    canvas->SetGrid();
    gPad->SetMargin(0.1,0.1,0.1,0.1);//l,r,b,t
    gStyle->SetOptTitle(0);
    gStyle->SetOptStat(0);

    TGraph *g0 = new TGraph(40, mass, sign);
    // TGraph *g1 = new TGraph(40, mass[1], sign[1]);
    // TGraph *g2 = new TGraph(40, mass[2], sign[2]);
    // TGraph *g3 = new TGraph(40, mass[3], sign[3]);
    // TGraph *g4 = new TGraph(40, mass[4], sign[4]);
    // TGraph *g5 = new TGraph(40, mass[5], sign[5]);
    // TGraph *g6 = new TGraph(40, mass[6], sign[6]);
    // TGraph *g7 = new TGraph(40, mass[7], sign[7]);
    //
    // TGraph *gs0 = new TGraph(32, mass_short1[0], sign_short1[0]);
    // TGraph *gs1 = new TGraph(32, mass_short1[1], sign_short1[1]);
    // TGraph *gs2 = new TGraph(32, mass_short1[2], sign_short1[2]);
    // TGraph *gs3 = new TGraph(32, mass_short1[3], sign_short1[3]);
    // TGraph *gs4 = new TGraph(32, mass_short1[4], sign_short1[4]);
    // TGraph *gs5 = new TGraph(32, mass_short1[5], sign_short1[5]);
    // TGraph *gs6 = new TGraph(32, mass_short1[6], sign_short1[6]);
    // TGraph *gs7 = new TGraph(32, mass_short1[7], sign_short1[7]);
    //
    // TGraph *gss0 = new TGraph(22, mass_short2[0], sign_short2[0]);
    // TGraph *gss1 = new TGraph(22, mass_short2[1], sign_short2[1]);
    // TGraph *gss2 = new TGraph(22, mass_short2[2], sign_short2[2]);
    // TGraph *gss3 = new TGraph(22, mass_short2[3], sign_short2[3]);
    // TGraph *gss4 = new TGraph(22, mass_short2[4], sign_short2[4]);
    // TGraph *gss5 = new TGraph(22, mass_short2[5], sign_short2[5]);
    // TGraph *gss6 = new TGraph(22, mass_short2[6], sign_short2[6]);
    // TGraph *gss7 = new TGraph(22, mass_short2[7], sign_short2[7]);

    // g0->SetNameTitle("name", "C1N1 1000");
    // g1->SetNameTitle("name", "C1N1 2000");
    // g2->SetNameTitle("name", "C1N1 3000");
    // g3->SetNameTitle("name", "C1N1 4000");
    // g4->SetNameTitle("name", "C1C1 1000");
    // g5->SetNameTitle("name", "C1C1 2000");
    // g6->SetNameTitle("name", "C1C1 3000");
    // g7->SetNameTitle("name", "C1C1 4000");
    //
    // gs0->SetNameTitle("name", "C1N1 1000");
    // gs1->SetNameTitle("name", "C1N1 2000");
    // gs2->SetNameTitle("name", "C1N1 3000");
    // gs3->SetNameTitle("name", "C1N1 4000");
    // gs4->SetNameTitle("name", "C1C1 1000");
    // gs5->SetNameTitle("name", "C1C1 2000");
    // gs6->SetNameTitle("name", "C1C1 3000");
    // gs7->SetNameTitle("name", "C1C1 4000");
    //
    // gss0->SetNameTitle("name", "C1N1 1000");
    // gss1->SetNameTitle("name", "C1N1 2000");
    // gss2->SetNameTitle("name", "C1N1 3000");
    // gss3->SetNameTitle("name", "C1N1 4000");
    // gss4->SetNameTitle("name", "C1C1 1000");
    // gss5->SetNameTitle("name", "C1C1 2000");
    // gss6->SetNameTitle("name", "C1C1 3000");
    // gss7->SetNameTitle("name", "C1C1 4000");

    graph_styling(g0, 1);
    // graph_styling(g1, 2);
    // graph_styling(g2, 3);
    // graph_styling(g3, 4);
    // graph_styling(g4, 5);
    // graph_styling(g5, 6);
    // graph_styling(g6, 7);
    // graph_styling(g7, 8);
    //
    // graph_styling(gs0, 1);
    // graph_styling(gs1, 2);
    // graph_styling(gs2, 3);
    // graph_styling(gs3, 4);
    // graph_styling(gs4, 5);
    // graph_styling(gs5, 6);
    // graph_styling(gs6, 7);
    // graph_styling(gs7, 8);
    //
    // graph_styling(gss0, 1);
    // graph_styling(gss1, 2);
    // graph_styling(gss2, 3);
    // graph_styling(gss3, 4);
    // graph_styling(gss4, 5);
    // graph_styling(gss5, 6);
    // graph_styling(gss6, 7);
    // graph_styling(gss7, 8);

    string ss1 = "/afs/cern.ch/user/c/chugli/private/plots/kinematic_selection/plot_sign_best_wino_all_"+fake_rate_s+".pdf[";
    string ss2 = "/afs/cern.ch/user/c/chugli/private/plots/kinematic_selection/plot_sign_best_wino_all_"+fake_rate_s+".pdf";
    string ss3 = "/afs/cern.ch/user/c/chugli/private/plots/kinematic_selection/plot_sign_best_wino_all_"+fake_rate_s+".pdf]";


    g0->Draw();
    gPad->Update();
    // canvas->BuildLegend(0.7,0.7,0.9,0.9);
    canvas->SaveAs(ss1.c_str());
    canvas->SaveAs(ss2.c_str());
    canvas->Clear();

    canvas->SetLogy();

    g0->SetMinimum(1);
    g0->SetMaximum(1e3);
    g0->Draw();
    gPad->Update();
    // canvas->BuildLegend(0.7,0.7,0.9,0.9);
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
    string myname = "/afs/cern.ch/user/c/chugli/private/txt/kinematic_selection_higgsino_short_tot_"+fake_rate_s+".txt";
    cout << "Start reading " << myname << endl;

    ifstream MyReadFile2(myname.c_str());
    int counter = 0;
    int i = 0;
    int j = 0;
    string s;
    string delimiter = ",";
    Double_t sign[2][9], pt[2][9], met[2][9], mass[2][9];
    // higgsino/wino, mass, C1C1/C1N1, leading jet pt cut, met cut, sign
    while (getline (MyReadFile2, s)) {
        if(counter>0 && counter < 18){
            cout << "counter: " << counter << endl;
            if(i==9){j++;i=0;}
            cout << "j, i: " << j <<", " << i << endl;
            size_t found1 = s.find(delimiter,0);
            size_t found2 = s.find(delimiter,found1+1);
            size_t found3 = s.find(delimiter,found2+1);
            size_t found4 = s.find(delimiter,found3+1);
            size_t found5 = s.find(delimiter,found4+1);
            string s2 = s.substr(found1+2, found2-found1-2); // mass
            string s3 = s.substr(found2+2, found3-found2-2); // type
            string s4 = s.substr(found3+2, found4-found3-2); // pt
            string s5 = s.substr(found4+2, found5-found4-2); // met
            string s6 = s.substr(found5+2, -1); // sign
            cout << "s: " << s << endl;
            cout << "s2: " << s2 << endl;
            cout << "s3: " << s3 << endl;
            cout << "s4: " << s4 << endl;
            cout << "s5: " << s5 << endl;
            cout << "s6: " << s6 << endl;

            mass[j][i] = stod(s2);
            pt[j][i]   = stod(s4);
            met[j][i]  = stod(s5);
            sign[j][i] = stod(s6);

            i++;
        }else if(counter >= 18){
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
    gPad->SetMargin(0.1,0.1,0.1,0.1);//l,r,b,t
    gStyle->SetOptTitle(0);
    gStyle->SetOptStat(0);

    TGraph *g0 = new TGraph(9, mass[0], sign[0]);
    TGraph *g1 = new TGraph(9, mass[1], sign[1]);

    g0->SetNameTitle("name", "C1N1 1000");
    g1->SetNameTitle("name", "C1C1 1000");

    h_graph_styling(g0, 1);
    h_graph_styling(g1, 2);

    string ss1 = "/afs/cern.ch/user/c/chugli/private/plots/kinematic_selection/plot_sign_best_higgsino_"+fake_rate_s+".pdf[";
    string ss2 = "/afs/cern.ch/user/c/chugli/private/plots/kinematic_selection/plot_sign_best_higgsino_"+fake_rate_s+".pdf";
    string ss3 = "/afs/cern.ch/user/c/chugli/private/plots/kinematic_selection/plot_sign_best_higgsino_"+fake_rate_s+".pdf]";


    g0->Draw();
    g1->Draw("same");
    gPad->Update();
    canvas->BuildLegend(0.7,0.7,0.9,0.9);
    canvas->SaveAs(ss1.c_str());
    canvas->SaveAs(ss2.c_str());
    canvas->Clear();

    canvas->SetLogy();

    g0->SetMinimum(1e-2);
    g0->Draw();
    g1->Draw("same");
    gPad->Update();
    canvas->BuildLegend(0.7,0.7,0.9,0.9);
    canvas->SaveAs(ss2.c_str());
    canvas->SaveAs(ss3.c_str());
    canvas->Close();

}


void graph_styling(TGraph* gr, int j){
  gr->SetLineColor(j);
  // gr->SetLineWidth(4);
  // gr->SetMarkerColor(4);
  // gr->SetMarkerSize(1.5);
  // gr->SetMarkerStyle(21);
  gr->GetXaxis()->SetTitle("Wino mass");
  gr->GetYaxis()->SetTitle("Significance");
}

void h_graph_styling(TGraph* gr, int j){
  gr->SetLineColor(j);
  // gr->SetLineWidth(4);
  // gr->SetMarkerColor(4);
  // gr->SetMarkerSize(1.5);
  // gr->SetMarkerStyle(21);
  gr->GetXaxis()->SetTitle("Higgsino mass");
  gr->GetYaxis()->SetTitle("Significance");
}
