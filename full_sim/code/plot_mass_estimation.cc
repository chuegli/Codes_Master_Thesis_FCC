#include <TGraph2D.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TPad.h>
#include <TH2D.h>

using namespace std;

void plot_mass_estimation(){
  string ss1 = "../plots/plot_mass_estimation.pdf[";
  string ss2 = "../plots/plot_mass_estimation.pdf";
  string ss3 = "../plots/plot_mass_estimation.pdf]";

  TCanvas *canvas = new TCanvas("canvas","");
  canvas->SetLogx();
  canvas->SetLogy();
  canvas->SetLogz();

  /////// mass_estimation without abs:
   double qOverP[] = {1e-8,1e-7,1e-6,1e-5,1e-4,1e-3,1e-2,1e-1,1e-8,1e-7,1e-6,1e-5,1e-4,1e-3,1e-2,1e-1,1e-8,1e-7,1e-6,1e-5,1e-4,1e-3,1e-2,1e-1,1e-8,1e-7,1e-6,1e-5,1e-4,1e-3,1e-2,1e-1,1e-8,1e-7,1e-6,1e-5,1e-4,1e-3,1e-2,1e-1,1e-8,1e-7,1e-6,1e-5,1e-4,1e-3,1e-2,1e-1,1e-8,1e-7,1e-6,1e-5,1e-4,1e-3,1e-2,1e-1,1e-8,1e-7,1e-6,1e-5,1e-4,1e-3,1e-2,1e-1};
   double beta[]   = {1e-8,1e-8,1e-8,1e-8,1e-8,1e-8,1e-8,1e-8,1e-7,1e-7,1e-7,1e-7,1e-7,1e-7,1e-7,1e-7,1e-6,1e-6,1e-6,1e-6,1e-6,1e-6,1e-6,1e-6,1e-5,1e-5,1e-5,1e-5,1e-5,1e-5,1e-5,1e-5,1e-4,1e-4,1e-4,1e-4,1e-4,1e-4,1e-4,1e-4,1e-3,1e-3,1e-3,1e-3,1e-3,1e-3,1e-3,1e-3,1e-2,1e-2,1e-2,1e-2,1e-2,1e-2,1e-2,1e-2,1e-1,1e-1,1e-1,1e-1,1e-1,1e-1,1e-1,1e-1};
   double mass_mean[] = {3000,3000,3000,3000.26,3081.26,5462.33,515.189,74.4325,3000,3000,2999.96,3000.95,3073.61,-937.261,14.894,76.8877,3000,2999.99,2999.96,3000.19,3080.89,4359.94,-1498.39,86.1015,3000,3000,3000.02,3000.34,3074.24,-4400.5,296.388,-78.8716,3000,3000.01,2999.95,3000.47,3080.28,3783.34,-557.798,6.81413,3000.02,3000,2999.85,3000.34,3077.01,6632.52,402.353,13.1396,2999.83,2999.64,3000.27,3000.12,3074.49,-1540.33,159.001,-19.1615,3014.59,3012.73,3012.15,3009.24,3094.4,1050.78,-361.723,-8.63801};
   double mass_rms[] = {0.0448427,0.452338,4.48732,45.0504,504.092,384332,45095.3,6869.72,0.0448162,0.457344,4.51453,45.1979,498.132,165044,14840.3,9164,0.0452258,0.453558,4.50174,45.3624,507.116,197790,111557,9047.39,0.0613352,0.45434,4.47653,45.1054,501.157,641777,24018.4,6788.14,0.434279,0.616954,4.60425,44.794,505.578,211819,150221,907.893,4.24761,4.26128,6.19344,45.0102,504.116,321679,45756.6,1500.77,42.4182,42.11,42.509,61.9394,498.602,333805,15977.7,1850.24,430.524,429.576,431.806,439.832,667.356,138344,25157.2,1150.92};
  // /////// mass_estimation with abs (new):
  //  double qOverP[] = {1e-8,1e-7,1e-6,1e-5,1e-4,1e-3,1e-2,1e-1,1e-8,1e-7,1e-6,1e-5,1e-4,1e-3,1e-2,1e-1,1e-8,1e-7,1e-6,1e-5,1e-4,1e-3,1e-2,1e-1,1e-8,1e-7,1e-6,1e-5,1e-4,1e-3,1e-2,1e-1,1e-8,1e-7,1e-6,1e-5,1e-4,1e-3,1e-2,1e-1,1e-8,1e-7,1e-6,1e-5,1e-4,1e-3,1e-2,1e-1,1e-8,1e-7,1e-6,1e-5,1e-4,1e-3,1e-2,1e-1,1e-8,1e-7,1e-6,1e-5,1e-4,1e-3,1e-2,1e-1};
  //  double beta[]   = {1e-8,1e-8,1e-8,1e-8,1e-8,1e-8,1e-8,1e-8,1e-7,1e-7,1e-7,1e-7,1e-7,1e-7,1e-7,1e-7,1e-6,1e-6,1e-6,1e-6,1e-6,1e-6,1e-6,1e-6,1e-5,1e-5,1e-5,1e-5,1e-5,1e-5,1e-5,1e-5,1e-4,1e-4,1e-4,1e-4,1e-4,1e-4,1e-4,1e-4,1e-3,1e-3,1e-3,1e-3,1e-3,1e-3,1e-3,1e-3,1e-2,1e-2,1e-2,1e-2,1e-2,1e-2,1e-2,1e-2,1e-1,1e-1,1e-1,1e-1,1e-1,1e-1,1e-1,1e-1};
  //  double mass_mean[] = {3000,3000,3000,3000.26,3081.26,15459.3,1880.28,209.119,3000,3000,2999.96,3000.95,3073.61,12084.3,1418.15,237.835,3000,2999.99,2999.96,3000.19,3080.89,13135.1,3002.95,270.738,3000,3000,3000.02,3000.34,3074.24,16925.9,1806.54,238.008,3000,3000.01,2999.95,3000.47,3080.28,11547.1,3307.51,128.367,3000.02,3000,2999.85,3000.34,3077.01,15959.4,2047.76,151.905,2999.83,2999.64,3000.27,3000.12,3074.49,15767.3,1396.17,164.362,3014.59,3012.73,3012.15,3009.24,3094.4,12489.2,1550.89,129};
  //  double mass_rms[] = {0.0448427,0.452338,4.48732,45.0504,504.092,384060,45059.1,6866.93,0.0448162,0.457344,4.51453,45.1979,498.132,164603,14772.4,9161.23,0.0452258,0.453558,4.50174,45.3624,507.116,197401,111527,9043.75,0.0613352,0.45434,4.47653,45.1054,501.157,641569,23952.2,6784.42,0.434279,0.616954,4.60425,44.794,505.578,211538,150186,898.797,4.24761,4.26128,6.19344,45.0102,504.116,321351,45712.6,1493.12,42.4182,42.11,42.509,61.9394,498.602,333436,15917.4,1843.02,430.524,429.576,431.806,439.832,667.356,137783,25112,1143.7};


   cout << "Check: " << sizeof(qOverP) << " = " << sizeof(beta) << " = " << sizeof(mass_mean) << " = " << sizeof(mass_rms) << endl;
   // double low[9] = {1.1e-9,1.1e-8,1.1e-7,1.1e-6,1.1e-5,1.1e-4,1.1e-3,1.1e-2,1.1e-1};
   // TH2D* h_mean = new TH2D("h_mean","h_mean", 9,low,9,low);
   // TH2D* h_rms  = new TH2D("h_rms" ,"h_rms" , 9,low,9,low);
   double low[9] = {4e-9,4e-8,4e-7,4e-6,4e-5,4e-4,4e-3,4e-2,4e-1};
   TH2D* h_mean = new TH2D("h_mean","h_mean", 8,low,8,low);
   TH2D* h_rms  = new TH2D("h_rms" ,"h_rms" , 8,low,8,low);
   for(int i=0; i<sizeof(qOverP);i++){
          h_mean->Fill(qOverP[i],beta[i],abs(mass_mean[i]-3000));
          h_rms ->Fill(qOverP[i],beta[i],mass_rms[i]);
   }

   gStyle->SetPalette(1);
   gPad->SetMargin(0.15,0.17,0.15,0.05);//l,r,b,t
   gStyle->SetOptTitle(0);
   gStyle->SetOptStat(0);
   gStyle->SetPaintTextFormat("3.1e");
   gStyle->SetHistMinimumZero();
   // gStyle->SetTextFont(0.01); // cambia il font non il size !!!
   // h_mean->GetZaxis()->SetRangeUser(1e5,1e-2);
   // h_mean->Draw("z");
   // canvas->Clear();

   h_mean->Draw("colz text");
   h_mean->SetMarkerSize(1.5);
   canvas->SetGrid();
   h_mean->SetMinimum(1e-2);
   string title = ";qOverP resolution; #beta resolution; mass mean difference [GeV]";
   h_mean->SetTitle(title.c_str());
   // h_mean->SetNdivisions(5);
   h_mean->GetYaxis()->SetLabelSize(0.05);
   h_mean->GetXaxis()->SetLabelSize(0.05);
   h_mean->GetYaxis()->SetTitleSize(0.05);
   h_mean->GetXaxis()->SetTitleSize(0.05);
   h_mean->GetZaxis()->SetLabelSize(0.05);
   h_mean->GetZaxis()->SetTitleSize(0.05);
   h_mean->GetXaxis()->SetTitleOffset(1.2);
   // h_mean->GetXaxis()->SetRangeUser(1.1e-9,1.1e-1);
   // h_mean->GetYaxis()->SetRangeUser(1.1e-9,1.1e-1);
   canvas->SaveAs(ss1.c_str());
   canvas->SaveAs(ss2.c_str());
   canvas->Clear();


   h_rms->Draw("colz text");
   h_rms->SetMarkerSize(1.5);
   canvas->SetGrid();
   // h1->SetMaximum(max);
   title = ";qOverP resolution; #beta resolution; RMS of mass [GeV]";
   h_rms->SetTitle(title.c_str());
   // h_rms->SetNdivisions(5);
   h_rms->GetYaxis()->SetLabelSize(0.05);
   h_rms->GetXaxis()->SetLabelSize(0.05);
   h_rms->GetYaxis()->SetTitleSize(0.05);
   h_rms->GetXaxis()->SetTitleSize(0.05);
   h_rms->GetZaxis()->SetLabelSize(0.05);
   h_rms->GetZaxis()->SetTitleSize(0.05);
   h_rms->GetXaxis()->SetTitleOffset(1.2);
   // h_rms->GetXaxis()->SetRangeUser(1.1e-9,1.1e-1);
   // h_rms->GetYaxis()->SetRangeUser(1.1e-9,1.1e-1);
   // h_rms->GetZaxis()->SetRangeUser(1e6,1e-2);
   canvas->SaveAs(ss2.c_str());
   canvas->SaveAs(ss3.c_str());
}
