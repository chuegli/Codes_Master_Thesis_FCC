// Data model
#include "datamodel/TrackCollection.h"
#include "datamodel/ParticleCollection.h"
#include "datamodel/TrackStateCollection.h"
#include "datamodel/MCParticleCollection.h"
#include "datamodel/PositionedTrackHitCollection.h"

// podio specific includes: https://github.com/AIDASoft/podio/tree/master/include/podio
#include "podio/EventStore.h"
#include "podio/ROOTReader.h"

#include <ostream>
#include <TLorentzVector.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TH3D.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TStyle.h>
#include <TGraph.h>
#include <TRandom.h>
#include <map>
#include <vector>
#include <TLegend.h>


using namespace std;

void compare_sme_trk_hits();
void make_canvas(TGraph* h1, TGraph* h2, string title, bool rz, string event_n, int pos);

int main(int argc, char **argv){

    compare_sme_trk_hits();

    return 0;
}

void compare_sme_trk_hits(){

  string rootname1 = "/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_50.root";
  string rootname2 = "/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/pileup_200_50.root";

  auto reader2 = podio::ROOTReader();
  auto store2 = podio::EventStore();
  reader2.openFile(rootname2.c_str());
  store2.setReader(&reader2);

  map<int, vector<double>> hits_x;
  map<int, vector<double>> hits_y;
  map<int, vector<double>> hits_z;
  map<int, vector<double>> hits_r;

  map<int, vector<double>> s_hits_x;
  map<int, vector<double>> s_hits_y;
  map<int, vector<double>> s_hits_z;
  map<int, vector<double>> s_hits_r;

  int counter = 0;
  for(unsigned iev=0; iev<10; ++iev) {
    vector<double> x;
    vector<double> y;
    vector<double> z;
    vector<double> r;

    const fcc::ParticleCollection* particles;
    bool particlesPresent = store2.get("TrackRecoParticles", particles);

    bool bool_reco = false;
    double xx[4],yy[4],zz[4],rr[4];
    if (particlesPresent) {
      for(const auto& particle : *particles){
          bool_reco = true;

          for(auto track = particle.tracks_begin(); track != particle.tracks_end(); ++track) {
            if(track->isAvailable()) {
                int hit_counter = 0;
                for(auto hit = track->hits_begin(); hit !=track->hits_end(); ++hit){
                    xx[hit_counter]=hit->x();
                    yy[hit_counter]=hit->y();
                    zz[hit_counter]=hit->z();
                    rr[hit_counter]=sqrt(hit->x()*hit->x()+hit->y()*hit->y());
                    hit_counter++;
                }// loop over hits
                if(hit_counter!=4){cout << hit_counter << endl;}
            } // if track present
          } // end of loop over reco tracks
      } // end for of particles reco
    }

    if(bool_reco){
      for(int i = 0;i<4;i++){
        x.push_back(xx[i]);
        y.push_back(yy[i]);
        z.push_back(zz[i]);
        r.push_back(rr[i]);
      }
      s_hits_x[counter] = x;
      s_hits_y[counter] = y;
      s_hits_z[counter] = z;
      s_hits_r[counter] = r;
      counter++;
    }

    store2.clear();
    reader2.endOfEvent();
  }

  ////////////////////////////////////////////////////////////////////////////////////////////////
  cout << "Start second part" << endl;

  auto reader = podio::ROOTReader();
  auto store = podio::EventStore();
  reader.openFile(rootname1.c_str());
  store.setReader(&reader);

  int counter_2 = 0;
  for(unsigned iev=0; iev<10; ++iev) {
    vector<double> x;
    vector<double> y;
    vector<double> z;
    vector<double> r;

    const fcc::ParticleCollection* particles;
    bool particlesPresent = store.get("TrackRecoParticles", particles);

    bool bool_reco = false;
    double xx[4],yy[4],zz[4],rr[4];
    if (particlesPresent) {
      for(const auto& particle : *particles){
          bool_reco = true;

          for(auto track = particle.tracks_begin(); track != particle.tracks_end(); ++track) {
            if(track->isAvailable()) {
                int hit_counter = 0;
                for(auto hit = track->hits_begin(); hit !=track->hits_end(); ++hit){
                    xx[hit_counter]=hit->x();
                    yy[hit_counter]=hit->y();
                    zz[hit_counter]=hit->z();
                    rr[hit_counter]=sqrt(hit->x()*hit->x()+hit->y()*hit->y());
                    hit_counter++;
                }// loop over hits
                if(hit_counter!=4){cout << hit_counter << endl;}
            } // if track present
          } // end of loop over reco tracks
      } // end for of particles reco
    }

    if(bool_reco){
      for(int i = 0;i<4;i++){
        x.push_back(xx[i]);
        y.push_back(yy[i]);
        z.push_back(zz[i]);
        r.push_back(rr[i]);
      }
      hits_x[counter_2] = x;
      hits_y[counter_2] = y;
      hits_z[counter_2] = z;
      hits_r[counter_2] = r;
      counter_2++;
    }

    store.clear();
    reader.endOfEvent();
  }

  ////////////////////////////////////////////////////////////////////////////////////////////////
  cout << "Plotting part" << endl;

  cout << "Trackerhits: " << hits_r[0].size() << " " << hits_r[1].size() << " " << hits_r[2].size() << " " \
       << hits_r[3].size() << " " << hits_r[4].size() << " " << hits_r[5].size() << " "\
       << hits_r[6].size() << " " << hits_r[7].size() << " " << hits_r[8].size() << " "\
       << hits_r[9].size() << endl;

  cout << "Smeared hits: " << s_hits_r[0].size() << " " << s_hits_r[1].size() << " " << s_hits_r[2].size() << " " \
       << s_hits_r[3].size() << " " << s_hits_r[4].size() << " " << s_hits_r[5].size() << " "\
       << s_hits_r[6].size() << " " << s_hits_r[7].size() << " " << s_hits_r[8].size() << " "\
       << s_hits_r[9].size() << endl;

  TGraph* t_rz_0 = new TGraph(  hits_r[0].size(),  hits_z[0].data(),  hits_r[0].data());
  TGraph* s_rz_0 = new TGraph(s_hits_r[0].size(),s_hits_z[0].data(),s_hits_r[0].data());
  TGraph* t_rz_1 = new TGraph(  hits_r[1].size(),  hits_z[1].data(),  hits_r[1].data());
  TGraph* s_rz_1 = new TGraph(s_hits_r[1].size(),s_hits_z[1].data(),s_hits_r[1].data());
  TGraph* t_rz_2 = new TGraph(  hits_r[2].size(),  hits_z[2].data(),  hits_r[2].data());
  TGraph* s_rz_2 = new TGraph(s_hits_r[2].size(),s_hits_z[2].data(),s_hits_r[2].data());
  TGraph* t_rz_3 = new TGraph(  hits_r[3].size(),  hits_z[3].data(),  hits_r[3].data());
  TGraph* s_rz_3 = new TGraph(s_hits_r[3].size(),s_hits_z[3].data(),s_hits_r[3].data());
  TGraph* t_rz_4 = new TGraph(  hits_r[4].size(),  hits_z[4].data(),  hits_r[4].data());
  TGraph* s_rz_4 = new TGraph(s_hits_r[4].size(),s_hits_z[4].data(),s_hits_r[4].data());
  TGraph* t_rz_5 = new TGraph(  hits_r[5].size(),  hits_z[5].data(),  hits_r[5].data());
  TGraph* s_rz_5 = new TGraph(s_hits_r[5].size(),s_hits_z[5].data(),s_hits_r[5].data());
  TGraph* t_rz_6 = new TGraph(  hits_r[6].size(),  hits_z[6].data(),  hits_r[6].data());
  TGraph* s_rz_6 = new TGraph(s_hits_r[6].size(),s_hits_z[6].data(),s_hits_r[6].data());
  TGraph* t_rz_7 = new TGraph(  hits_r[7].size(),  hits_z[7].data(),  hits_r[7].data());
  TGraph* s_rz_7 = new TGraph(s_hits_r[7].size(),s_hits_z[7].data(),s_hits_r[7].data());
  TGraph* t_rz_8 = new TGraph(  hits_r[8].size(),  hits_z[8].data(),  hits_r[8].data());
  TGraph* s_rz_8 = new TGraph(s_hits_r[8].size(),s_hits_z[8].data(),s_hits_r[8].data());
  TGraph* t_rz_9 = new TGraph(  hits_r[9].size(),  hits_z[9].data(),  hits_r[9].data());
  TGraph* s_rz_9 = new TGraph(s_hits_r[9].size(),s_hits_z[9].data(),s_hits_r[9].data());

  TGraph* t_xy_0 = new TGraph(  hits_x[0].size(),  hits_x[0].data(),   hits_y[0].data());
  TGraph* s_xy_0 = new TGraph(s_hits_x[0].size(),s_hits_x[0].data(), s_hits_y[0].data());
  TGraph* t_xy_1 = new TGraph(  hits_x[1].size(),  hits_x[1].data(),   hits_y[1].data());
  TGraph* s_xy_1 = new TGraph(s_hits_x[1].size(),s_hits_x[1].data(), s_hits_y[1].data());
  TGraph* t_xy_2 = new TGraph(  hits_x[2].size(),  hits_x[2].data(),   hits_y[2].data());
  TGraph* s_xy_2 = new TGraph(s_hits_x[2].size(),s_hits_x[2].data(), s_hits_y[2].data());
  TGraph* t_xy_3 = new TGraph(  hits_x[3].size(),  hits_x[3].data(),   hits_y[3].data());
  TGraph* s_xy_3 = new TGraph(s_hits_x[3].size(),s_hits_x[3].data(), s_hits_y[3].data());
  TGraph* t_xy_4 = new TGraph(  hits_x[4].size(),  hits_x[4].data(),   hits_y[4].data());
  TGraph* s_xy_4 = new TGraph(s_hits_x[4].size(),s_hits_x[4].data(), s_hits_y[4].data());
  TGraph* t_xy_5 = new TGraph(  hits_x[5].size(),  hits_x[5].data(),   hits_y[5].data());
  TGraph* s_xy_5 = new TGraph(s_hits_x[5].size(),s_hits_x[5].data(), s_hits_y[5].data());
  TGraph* t_xy_6 = new TGraph(  hits_x[6].size(),  hits_x[6].data(),   hits_y[6].data());
  TGraph* s_xy_6 = new TGraph(s_hits_x[6].size(),s_hits_x[6].data(), s_hits_y[6].data());
  TGraph* t_xy_7 = new TGraph(  hits_x[7].size(),  hits_x[7].data(),   hits_y[7].data());
  TGraph* s_xy_7 = new TGraph(s_hits_x[7].size(),s_hits_x[7].data(), s_hits_y[7].data());
  TGraph* t_xy_8 = new TGraph(  hits_x[8].size(),  hits_x[8].data(),   hits_y[8].data());
  TGraph* s_xy_8 = new TGraph(s_hits_x[8].size(),s_hits_x[8].data(), s_hits_y[8].data());
  TGraph* t_xy_9 = new TGraph(  hits_x[9].size(),  hits_x[9].data(),   hits_y[9].data());
  TGraph* s_xy_9 = new TGraph(s_hits_x[9].size(),s_hits_x[9].data(), s_hits_y[9].data());

  make_canvas(t_rz_0,s_rz_0,"Event 0; z [mm]; r [mm]",true,"0",0);
  make_canvas(t_rz_1,s_rz_1,"Event 1; z [mm]; r [mm]",true,"1",1);
  make_canvas(t_rz_2,s_rz_2,"Event 2; z [mm]; r [mm]",true,"2",1);
  make_canvas(t_rz_3,s_rz_3,"Event 3; z [mm]; r [mm]",true,"3",1);
  make_canvas(t_rz_4,s_rz_4,"Event 4; z [mm]; r [mm]",true,"4",1);
  make_canvas(t_rz_5,s_rz_5,"Event 5; z [mm]; r [mm]",true,"5",1);
  make_canvas(t_rz_6,s_rz_6,"Event 6; z [mm]; r [mm]",true,"6",1);
  make_canvas(t_rz_7,s_rz_7,"Event 7; z [mm]; r [mm]",true,"7",1);
  make_canvas(t_rz_8,s_rz_8,"Event 8; z [mm]; r [mm]",true,"8",1);
  make_canvas(t_rz_9,s_rz_9,"Event 9; z [mm]; r [mm]",true,"9",1);

  make_canvas(t_xy_0,s_xy_0,"Event 0; x [mm]; y [mm]",false,"0",1);
  make_canvas(t_xy_1,s_xy_1,"Event 1; x [mm]; y [mm]",false,"1",1);
  make_canvas(t_xy_2,s_xy_2,"Event 2; x [mm]; y [mm]",false,"2",1);
  make_canvas(t_xy_3,s_xy_3,"Event 3; x [mm]; y [mm]",false,"3",1);
  make_canvas(t_xy_4,s_xy_4,"Event 4; x [mm]; y [mm]",false,"4",1);
  make_canvas(t_xy_5,s_xy_5,"Event 5; x [mm]; y [mm]",false,"5",1);
  make_canvas(t_xy_6,s_xy_6,"Event 6; x [mm]; y [mm]",false,"6",1);
  make_canvas(t_xy_7,s_xy_7,"Event 7; x [mm]; y [mm]",false,"7",1);
  make_canvas(t_xy_8,s_xy_8,"Event 8; x [mm]; y [mm]",false,"8",1);
  make_canvas(t_xy_9,s_xy_9,"Event 9; x [mm]; y [mm]",false,"9",2);

 cout << "***************** Finished *********************" << endl;
}

void make_canvas(TGraph* h1, TGraph* h2, string title, bool rz, string event_n, int pos){
  TCanvas *canvas = new TCanvas("canvas","");
  canvas->SetGrid();
  gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
  gStyle->SetOptStat(0);
  string ss1 = "../plots/sme_trk_comparison.pdf[";
  string ss2 = "../plots/sme_trk_comparison.pdf";
  string ss3 = "../plots/sme_trk_comparison.pdf]";

  h2->SetMarkerColor(2);
  h1->SetMarkerColor(1);
  h1->Draw("AP*");
  // h1->GetXaxis()->SetRangeUser(-600,600);
  // if(rz){h1->GetYaxis()->SetRangeUser(0,200);}
  // else{h1->GetYaxis()->SetRangeUser(-0.01,0.01);}
  // h1->Draw("AP*");
  canvas->Update();
  h2->Draw("P*same");
  if(rz){
    h1->GetXaxis()->SetTitle("z [mm]");
    h1->GetYaxis()->SetTitle("r [mm]");
    string s = "Event number "+event_n;
    h1->SetTitle(s.c_str());
  }else{
    h1->GetXaxis()->SetTitle("x [mm]");
    h1->GetYaxis()->SetTitle("y [mm]");
    string s = "Event number "+event_n;
    h1->SetTitle(s.c_str());
  }
  TLegend* legend = new TLegend(0.75,0.8,0.98,0.98);//x1,y1,x2,y2
  gStyle->SetLegendTextSize(0.04);
  legend->AddEntry(h1,"TrackerHits","p");
  legend->AddEntry(h2,"SmearedHits","p");
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
