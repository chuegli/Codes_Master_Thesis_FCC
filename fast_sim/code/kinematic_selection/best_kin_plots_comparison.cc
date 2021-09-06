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

void best_kin_plots_comparison(){
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
    double sign_all[40], pt_all[40], met_all[40], mass_all[40];
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

            mass_all[i] = stod(s3);
            pt_all[i]   = stod(s4);
            met_all[i]  = stod(s5);
            sign_all[i] = stod(s6);

            i++;
        }else if(counter >= 40){
            break;
        }
        counter++;
    }
    MyReadFile2.close();
    //// end of extract events

    ///////////////////////////////////////////////////////////////////////////
    //// Read .txt to extrect significance and cuts:
    myname = "/afs/cern.ch/user/c/chugli/private/txt/kinematic_selection_wino_short_tot_"+fake_rate_s+".txt";
    cout << "Start reading " << myname << endl;

    ifstream MyReadFile1(myname.c_str());
    counter = 0;
    i = 0;
    j = 0;
    delimiter = ",";
    Double_t sign[8][40], pt[8][40], met[8][40], mass[8][40];
    // higgsino/wino, mass, C1C1/C1N1, leading jet pt cut, met cut, sign
    while (getline (MyReadFile1, s)) {
        if(counter>0 && counter < 321){
            cout << "counter: " << counter << endl;
            if(i==40){j++;i=0;}
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
        }else if(counter >= 320){
            break;
        }
        counter++;
    }
    MyReadFile1.close();
    //// end of extract events


    ///////////////////////////////////////////////////////////////////////////
    //// Plot everything:
    cout << "********************* Start plotting *********************" << endl;
    TCanvas *canvas = new TCanvas("c","");
    canvas->SetGrid();
    gPad->SetMargin(0.1,0.1,0.1,0.1);//l,r,b,t
    gStyle->SetOptTitle(0);
    gStyle->SetOptStat(0);

    TGraph *g0 = new TGraph(40, mass_all, sign_all);
    TGraph *g1 = new TGraph(40, mass[0], sign[0]);
    TGraph *g2 = new TGraph(40, mass[1], sign[1]);
    TGraph *g3 = new TGraph(40, mass[2], sign[2]);
    TGraph *g4 = new TGraph(40, mass[3], sign[3]);

    g0->SetNameTitle("name", "Best all");
    g1->SetNameTitle("name", "C1N1 1000");
    g2->SetNameTitle("name", "C1N1 2000");
    g3->SetNameTitle("name", "C1N1 3000");
    g4->SetNameTitle("name", "C1N1 4000");

    graph_styling(g0, 1);
    graph_styling(g1, 2);
    graph_styling(g2, 3);
    graph_styling(g3, 4);
    graph_styling(g4, 5);

    string ss1 = "/afs/cern.ch/user/c/chugli/private/plots/kinematic_selection/plot_sign_best_wino_comparison_"+fake_rate_s+".pdf[";
    string ss2 = "/afs/cern.ch/user/c/chugli/private/plots/kinematic_selection/plot_sign_best_wino_comparison_"+fake_rate_s+".pdf";
    string ss3 = "/afs/cern.ch/user/c/chugli/private/plots/kinematic_selection/plot_sign_best_wino_comparison_"+fake_rate_s+".pdf]";


    g0->Draw();
    g1->Draw("same");
    g2->Draw("same");
    g3->Draw("same");
    g4->Draw("same");
    gPad->Update();
    canvas->BuildLegend(0.7,0.7,0.9,0.9);
    canvas->SaveAs(ss1.c_str());
    canvas->SaveAs(ss2.c_str());
    canvas->Clear();

    canvas->SetLogy();

    g0->SetMinimum(1);
    g0->SetMaximum(1e3);
    g0->Draw();
    g1->Draw("same");
    g2->Draw("same");
    g3->Draw("same");
    g4->Draw("same");
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
