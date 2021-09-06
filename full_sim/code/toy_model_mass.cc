#include <ostream>
#include <TGraph.h>
#include <TGraph2D.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TStyle.h>
#include <TRandom.h>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////
// Toy model to estimate the mass resolution based on the beta and qOverP resolutions
// How to run:
// go in /afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/code/
// command: root -q -b toy_model_mass.cc
/////////////////////////////////////////////////////////////////////////////////

void toy_model_mass(){
    const int n_sampling = 10000;
    vector<double> masses(n_sampling);
    vector<double> sigmas_qOverP = {1e-8, 1e-7, 1e-6, 1e-5, 1e-4, 1e-3, 1e-2, 1e-1, 1e-0}; // qOverP resolutions
    vector<double> sigmas_beta   = {1e-8, 1e-7, 1e-6, 1e-5, 1e-4, 1e-3, 1e-2, 1e-1, 1e-0}; // beta resolutions
    // vector<double> sigmas_qOverP = {1e-4, 0.5e-3, 1e-3, 0.5e-2, 1e-2, 0.5e-1, 1e-1, 0.5e+0, 1e+0}; // qOverP resolutions
    // vector<double> sigmas_beta   = {1e-4, 0.5e-3, 1e-3, 0.5e-2, 1e-2, 0.5e-1, 1e-1, 0.5e+0, 1e+0}; // beta resolutions
    vector<double> results;
    vector<double> results_mass;
    Double_t x[81]; // beta resolution
    Double_t y[81]; // qOverP resolution
    Double_t z[81]; // results in array
    vector<double> results_vs_beta;
    vector<double> results_vs_qOverP;

    int tot_counter = 0;
    int counter_beta = 0;
    cout << "qOverP resolution, beta resolution, mass mean, mass RMS " << endl;
    for(auto sigma_beta : sigmas_beta){
      counter_beta++;
      int counter = 0;
      for(auto sigma_qOverP : sigmas_qOverP){
        counter ++;
        TH1D* h_mass = new TH1D("h_mass","; mass [GeV]; Number of entries", 20000, -10000, 10000);
        // cout << "qOverP resolution: " << sigma_qOverP << ", beta resolution: " << sigma_beta << endl;
        int correct = 0;
        for(int i=0; i<n_sampling; i++){
            double beta   = gRandom->Gaus(0.707106781, sigma_beta/2);
            double qOverP = gRandom->Gaus(1.0/3000.0, sigma_qOverP/2);
            // double beta   = gRandom->Gaus(0, sigma_beta/2);
            // double qOverP = gRandom->Gaus(0, sigma_qOverP/2);
            if((1-beta*beta)>=0 && beta !=0 && qOverP!=0){
              masses[correct] = sqrt(1-beta*beta)/beta/qOverP;
              correct++;
              h_mass->Fill(sqrt(1-beta*beta)/beta/qOverP);
            }
        }
        cout << sigma_qOverP << ", " << sigma_beta << ", " << TMath::Mean(correct, masses.data()) << ", " << TMath::RMS(correct, masses.data()) << endl;
        results.push_back(TMath::RMS(correct, masses.data()));
        x[tot_counter] = sigma_beta;
        y[tot_counter] = sigma_qOverP;
        z[tot_counter] = TMath::RMS(correct, masses.data());
        tot_counter++;
        if(counter == 1){results_vs_beta.push_back(TMath::RMS(correct, masses.data()));}
        if(counter_beta==1){results_vs_qOverP.push_back(TMath::RMS(correct, masses.data()));}

        ///// Plot mass distribution:
        TCanvas *canvas = new TCanvas("canvas","");
        gStyle->SetOptTitle(0);
        gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
        h_mass->Draw("hist h");
        string title = "#sigma #beta = "+to_string(sigma_beta)+", #sigma qOverP = "+ to_string(sigma_qOverP);
        h_mass->SetTitle(title.c_str());
        h_mass->GetYaxis()->SetLabelSize(0.05);
        h_mass->GetXaxis()->SetLabelSize(0.05);
        h_mass->GetYaxis()->SetTitleSize(0.05);
        h_mass->GetXaxis()->SetTitleSize(0.05);
        if(tot_counter==1){canvas->SaveAs("../plots/toy_model_mass_distributions.pdf[");}
        canvas->SaveAs("../plots/toy_model_mass_distributions.pdf");
        if(tot_counter==81){canvas->SaveAs("../plots/toy_model_mass_distributions.pdf]");}
      }
    }

    TCanvas *canvas = new TCanvas("canvas","");
    gStyle->SetOptTitle(0);
    gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
    gPad->SetGrid();
    auto g = new TGraph(sigmas_beta.size(), sigmas_beta.data(), results_vs_beta.data());
    g->Draw("AP*");
    gPad->SetLogx();
    gPad->SetLogy();
    // g->SetMaximum(1e6);
    g->GetXaxis()->SetTitle("#beta resolution");
    g->GetYaxis()->SetTitle("RMS of mass");
    canvas->SaveAs("../plots/toy_model_mass.pdf[");
    canvas->SaveAs("../plots/toy_model_mass.pdf");
    canvas->Clear();

    auto g1 = new TGraph(sigmas_qOverP.size(), sigmas_qOverP.data(), results_vs_qOverP.data());
    g1->Draw("AP*");
    gPad->SetLogx();
    gPad->SetLogy();
    g1->GetXaxis()->SetTitle("qOverP resolution");
    g1->GetYaxis()->SetTitle("RMS of mass");
    canvas->SaveAs("../plots/toy_model_mass.pdf");
    canvas->SaveAs("../plots/toy_model_mass.pdf]");

    // cout << x.size() << endl;
    // cout << y.size() << endl;
    // cout << results.size() << endl;
    TCanvas *canvas2 = new TCanvas("canvas2","");
    // gStyle->SetOptTitle(0);
    // gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
    // gPad->SetGrid();
    TGraph2D *gg = new TGraph2D(81, x, y, z);
    // gg->SetMarkerStyle(4);
    gg->Draw("pcol");
    // gg->Draw("p0 same");
    // gPad->SetLogx();
    // gPad->SetLogy();
    // gPad->SetLogz();
    // gg->Draw();
    // gPad->Update();
    gg->GetXaxis()->SetTitle("#beta resolution");
    gg->GetYaxis()->SetTitle("qOverP resolution");
    gg->GetZaxis()->SetTitle("RMS of mass");
    canvas2->SaveAs("../plots/toy_model_mass_2D.pdf");
}
