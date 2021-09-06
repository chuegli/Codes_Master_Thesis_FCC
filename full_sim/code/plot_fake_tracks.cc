#include <TCanvas.h>
#include <TGraph.h>


void make_canvas(TGraph* g1, TGraph* g2, TGraph* g3);
void make_canvas(TGraph* g1, TGraph* g2, TGraph* g3, TGraph* g4, int pos, bool fake, double max);
void make_canvas(TGraph* g1, int pos, bool fake);

void plot_fake_tracks(){
  double nevents[] = {1,10,100,1000};
  double time_1[]  = {1.121,2.138,9.867,96.228}; // time in s for 1 pileup for different number of events
  double time_2[]  = {1.176,2.549,14.756,146.794};
  double time_4[]  = {1.294,3.474,23.943,243.95};
  double pileups_1[11]   = {1,2,4,8,16,32,64,128,256,512,1024};
  double pileups_10[9]   = {1,2,4,8,16,32,64,128,256};
  double pileups_100[6]  = {1,2,4,8,16,32};
  double pileups_1000[3] = {1,2,4};
  double fake_tracks_1[11]   = {0,0,1,6,28,47,94,282,4424,46321,543398}; // number of fake tracks (=reco particles) for different pileups and 1 event
  double fake_tracks_10[9]   = {62,66,103,131,299,669,1533,7118,54283}; // number of fake tracks (=reco particles) for different pileups and 10 event
  double fake_tracks_100[6]  = {324,677,1357,2409,3510,6400};
  double fake_tracks_1000[3] = {4620,8341,14419};
  double gen_particles_1[11]   = {124,272,1197,3354,8014,14419,25231,46680,105720,311131,419422};
  double gen_particles_10[9]   = {5477,9080,17163,31169,59462,128902,262993,531913,1088847};
  double gen_particles_100[6]  = {37927,78379,159961,327979,669625,1363975};
  double gen_particles_1000[3] = {410389,841849,1713821};

  double time[11] = {1.121,1.176,1.294,1.874,2.106,3.103,4.251,7.267,14.455,32.288,123.798}; // time for 1 event for different pileups


  TGraph* time_vs_events_1 = new TGraph(4,nevents,time_1);
  TGraph* time_vs_events_2 = new TGraph(4,nevents,time_2);
  TGraph* time_vs_events_4 = new TGraph(4,nevents,time_4);

  TGraph* time_vs_pileups = new TGraph(11,pileups_1,time);
  TGraph* time_vs_tracks = new TGraph(11,fake_tracks_1,time);

  TGraph* fake_vs_pileup_1    = new TGraph(11,pileups_1   ,fake_tracks_1   );
  TGraph* fake_vs_pileup_10   = new TGraph(9,pileups_10  ,fake_tracks_10  );
  TGraph* fake_vs_pileup_100  = new TGraph(6,pileups_100 ,fake_tracks_100 );
  TGraph* fake_vs_pileup_1000 = new TGraph(3,pileups_1000,fake_tracks_1000);

  TGraph* gen_vs_pileup_1    = new TGraph(11,pileups_1   ,gen_particles_1   );
  TGraph* gen_vs_pileup_10   = new TGraph(9,pileups_10  ,gen_particles_10  );
  TGraph* gen_vs_pileup_100  = new TGraph(6,pileups_100 ,gen_particles_100 );
  TGraph* gen_vs_pileup_1000 = new TGraph(3,pileups_1000,gen_particles_1000);

  make_canvas(time_vs_events_4,time_vs_events_2,time_vs_events_1);

  make_canvas(time_vs_pileups,0,false);
  make_canvas(time_vs_tracks,2,true);

  make_canvas(fake_vs_pileup_1,fake_vs_pileup_10,fake_vs_pileup_100,fake_vs_pileup_1000,0,true,1e7);
  make_canvas(gen_vs_pileup_1,gen_vs_pileup_10,gen_vs_pileup_100,gen_vs_pileup_1000,    2,false,1e7);
}

void make_canvas(TGraph* g1, TGraph* g2, TGraph* g3){
  TCanvas *canvas = new TCanvas("canvas","");
  canvas->SetGrid();

  canvas->SetLogy();
  canvas->SetLogx();
  g1->SetMinimum(1);


  gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  string ss1 = "../plots/plots_coputing_time.pdf[";
  string ss2 = "../plots/plots_coputing_time.pdf";
  string ss3 = "../plots/plots_coputing_time.pdf]";

  g1->SetMarkerColor(1);
  g2->SetMarkerColor(2);
  g3->SetMarkerColor(8);
  g1->SetLineColor(1);
  g2->SetLineColor(2);
  g3->SetLineColor(8);
  g1->Draw("ACP*");
  // g1->GetXaxis()->SetRangeUser(-600,600);
  // if(rz){g1->GetYaxis()->SetRangeUser(0,200);}
  // else{g1->GetYaxis()->SetRangeUser(-0.01,0.01);}
  canvas->Update();
  g2->Draw("CP*same");
  g3->Draw("CP*same");
  g1->GetXaxis()->SetTitle("Number of events [ ]");
  g1->GetYaxis()->SetTitle("Computing time [s]");
  g1->SetTitle("Computing time in function of number of events");

  TLegend* legend = new TLegend(0.25,0.8,0.4,0.98);//x1,y1,x2,y2
  gStyle->SetLegendTextSize(0.04);
  legend->AddEntry(g3,"1 pileup","p");
  legend->AddEntry(g2,"2 pileups","p");
  legend->AddEntry(g1,"4 pileups","p");
  legend->Draw();

  canvas->SaveAs(ss2.c_str());
  canvas->Close();
}

void make_canvas(TGraph* g1, TGraph* g2, TGraph* g3, TGraph* g4, int pos, bool fake, double max){
  TCanvas *canvas = new TCanvas("canvas","");
  canvas->SetGrid();

  canvas->SetLogy();
  canvas->SetLogx();
  g1->SetMinimum(1e-1);
  g1->SetMaximum(max);

  gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  string ss1 = "../plots/plots_fake_tracks.pdf[";
  string ss2 = "../plots/plots_fake_tracks.pdf";
  string ss3 = "../plots/plots_fake_tracks.pdf]";

  g1->SetMarkerColor(1);
  g2->SetMarkerColor(2);
  g3->SetMarkerColor(8);
  g4->SetMarkerColor(94);
  g1->SetLineColor(1);
  g2->SetLineColor(2);
  g3->SetLineColor(8);
  g4->SetLineColor(94);
  g1->Draw("ACP*");
  // g1->GetXaxis()->SetRangeUser(-600,600);
  // if(rz){g1->GetYaxis()->SetRangeUser(0,200);}
  // else{g1->GetYaxis()->SetRangeUser(-0.01,0.01);}
  canvas->Update();
  g2->Draw("CP*same");
  g3->Draw("CP*same");
  g4->Draw("CP*same");
  g1->GetXaxis()->SetTitle("Number of pileups [ ]");
  if(fake){g1->GetYaxis()->SetTitle("Number of fake tracks [ ]");}
  else{g1->GetYaxis()->SetTitle("Number of gen particles [ ]");}

  TLegend* legend = new TLegend(0.75,0.8,0.98,0.98);//x1,y1,x2,y2
  gStyle->SetLegendTextSize(0.04);
  legend->AddEntry(g1,"1 event","p");
  legend->AddEntry(g2,"10 events","p");
  legend->AddEntry(g3,"100 events","p");
  legend->AddEntry(g4,"1000 events","p");
  legend->Draw();

  if(pos==0){
    canvas->SaveAs(ss1.c_str());
    canvas->SaveAs(ss2.c_str());
  }else if(pos==1){
    canvas->SaveAs(ss2.c_str());
  }else{
    canvas->SaveAs(ss2.c_str());
    canvas->SaveAs(ss3.c_str());
  }
  canvas->Close();
}


void make_canvas(TGraph* g1, int pos, bool fake){
  TCanvas *canvas = new TCanvas("canvas","");
  canvas->SetGrid();

  canvas->SetLogy();
  canvas->SetLogx();
  g1->SetMinimum(1);


  gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  string ss1 = "../plots/plots_coputing_time_2.pdf[";
  string ss2 = "../plots/plots_coputing_time_2.pdf";
  string ss3 = "../plots/plots_coputing_time_2.pdf]";

  g1->SetMarkerColor(1);
  g1->SetLineColor(1);
  g1->Draw("ACP*");
  // g1->GetXaxis()->SetRangeUser(-600,600);
  // if(rz){g1->GetYaxis()->SetRangeUser(0,200);}
  // else{g1->GetYaxis()->SetRangeUser(-0.01,0.01);}
  canvas->Update();
  g1->GetYaxis()->SetTitle("Computing time [s]");
  if(fake){g1->GetXaxis()->SetTitle("Number of fake tracks [ ]");}
  else{g1->GetXaxis()->SetTitle("Number of pileups [ ]");}

  if(pos==0){
    canvas->SaveAs(ss1.c_str());
    canvas->SaveAs(ss2.c_str());
  }else if(pos==1){
    canvas->SaveAs(ss2.c_str());
  }else{
    canvas->SaveAs(ss2.c_str());
    canvas->SaveAs(ss3.c_str());
  }
  canvas->Close();
}
