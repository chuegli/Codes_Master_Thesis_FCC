// Data model
#include "datamodel/TrackCollection.h"
#include "datamodel/ParticleCollection.h"
#include "datamodel/TrackStateCollection.h"
#include "datamodel/MCParticleCollection.h"
#include "datamodel/PositionedTrackHitCollection.h"

// podio specific includes: https://github.com/AIDASoft/podio/tree/master/include/podio
#include "podio/EventStore.h"
#include "podio/ROOTReader.h"

#include <TLorentzVector.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TStyle.h>
#include <TGraph.h>
#include <TGraph2D.h>

using namespace std;

void wino_beta_plots();
void make_beta();
void my_beta_test();

int main(int argc, char **argv){
  my_beta_test();
  wino_beta_plots();
  cout << "***************** Finished *********************" << endl;
  return 0;
}

// void my_beta(){
//   // make_beta();
//   my_beta_test();
//   wino_beta_plots();
//   cout << "***************** Finished *********************" << endl;
// }

void my_beta_test(){
  auto reader = podio::ROOTReader();
  auto store = podio::EventStore(); // is the store of events
  string rootname = "winos_for_seeding_tracks_stable.root";
  reader.openFile(rootname.c_str());
  store.setReader(&reader); // connect the store to the .root file
  unsigned nevents= reader.getEntries();
  cout << "Number of entries: " << nevents << endl;

  ///// Plotting ongli the best deltaR:
  // TH1D* h_beta = new TH1D("h_beta",    "h_beta", 100,0.995,1.015);
  TH1D* h_beta = new TH1D("h_beta",    "h_beta", 1000,-50,400);

  double speed_light = 299.792458; //mm/ns

  for(unsigned iev=0; iev<nevents; ++iev) {
    // cout << iev<< endl;
    // Read TrackerHitsPosition
    const fcc::PositionedTrackHitCollection* trackhits;
    bool trackhitsPresent = store.get("TrackerHitsPosition", trackhits);

    double x1=0,y1=0,z1=0,t1=0,x2=0,y2=0,z2=0,t2=0;
    if (trackhitsPresent){
      int counter = 0;
      for(const auto& hit : *trackhits){
        if(counter==0){
          x1 = hit.position().x;
          y1 = hit.position().y;
          z1 = hit.position().z;
          t1 = hit.core().time;
        }else{
          x2 = hit.position().x;
          y2 = hit.position().y;
          z2 = hit.position().z;
          t2 = hit.core().time;
        }
        counter++;
      }
      double r = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
      double t = t2-t1;
      h_beta->Fill(r/t);
      // cout << "number of event: " << iev << " v: " << r/t << endl;
    }

    store.clear();
    reader.endOfEvent();

    // if(iev > 10) break;
  }
  cout << "Write to .root" << endl;
  rootname = "winos_beta_test.root";
  auto f1 = TFile::Open(rootname.c_str(), "RECREATE");
  h_beta ->Write();
  f1->Close();

  cout <<"Delete" << endl;
  delete h_beta ;
}
//
// void make_beta(){
//   auto reader = podio::ROOTReader();
//   auto store = podio::EventStore(); // is the store of events
//   string rootname = "wino_for_seeding_tracks_test.root";
//   reader.openFile(rootname.c_str());
//   store.setReader(&reader); // connect the store to the .root file
//   unsigned nevents= reader.getEntries();
//   cout << "Number of entries: " << nevents << endl;
//
//   ///// Plotting ongli the best deltaR:
//   // TH1D* h_beta = new TH1D("h_beta",    "h_beta", 100,0.995,1.015);
//   TH1D* h_beta = new TH1D("h_beta",    "h_beta", 100,0,50);
//
//   double speed_light = 299.792458; //mm/ns
//
//   for(unsigned iev=0; iev<nevents; ++iev) {
//   // for(unsigned iev=0; iev<1; ++iev) {
//     // cout << "processing event " << iev << endl;
//     int n = 100;
//     double x1, y1, z1, t1, x2[n], y2[n], z2[n], t2[n];
//     double DR[n];
//
//     for(int i=0;i<n;i++){
//       x2[i] = 0;
//       y2[i] = 0;
//       z2[i] = 0;
//       t2[i] = 0;
//       DR[i] = 0;
//     }
//
//     // Read Tracks
//     const fcc::TrackCollection* tracks;
//     bool tracksPresent = store.get("Tracks", tracks);
//
//     if (tracksPresent) {
//       double a=0,b=0,c=0;
//       double z_pred;
//       x1 = 0;
//       y1 = 0;
//       z1 = 0;
//       t1 = 0;
//       for(const auto& track : *tracks){
//         int hit_counter = 0;
//         for(auto hit = track.hits_begin(); hit != track.hits_end(); ++hit) {
//           if(hit->isAvailable()) {
//             hit_counter++;
//             if(hit_counter==1){
//               x1 = hit->x();
//               y1 = hit->y();
//               z1 = hit->z();
//               t1 = hit->time();
//               x2[hit_counter-1] = hit->x();
//               y2[hit_counter-1] = hit->y();
//               z2[hit_counter-1] = hit->z();
//               t2[hit_counter-1] = hit->time();
//             }else{
//               double r = sqrt(x2[hit_counter-2]*x2[hit_counter-2]+y2[hit_counter-2]*y2[hit_counter-2]+z2[hit_counter-2]*z2[hit_counter-2]);
//               double theta = acos(z2[hit_counter-2]/r);
//               double phi = acos(x2[hit_counter-2]/r);
//               double eta = -log(tan(theta/2));
//               DR[hit_counter-1] = sqrt(eta*eta+phi*phi);
//               x2[hit_counter-1] = hit->x();
//               y2[hit_counter-1] = hit->y();
//               z2[hit_counter-1] = hit->z();
//               t2[hit_counter-1] = hit->time();
//             }
//             if(hit_counter>=3){
//                 double b_part1 = (z2[hit_counter-1]*(x2[hit_counter-2]-x2[hit_counter-3]));
//                 double b_part2 = (z2[hit_counter-2]*(x2[hit_counter-1]-x2[hit_counter-3]));
//                 double b_part3 = (z2[hit_counter-3]*(x2[hit_counter-2]-x2[hit_counter-1]));
//                 double b_part4 = (y2[hit_counter-1]-y2[hit_counter-3])*(x2[hit_counter-2]-x2[hit_counter-3]);
//                 double b_part5 = (y2[hit_counter-2]-y2[hit_counter-3])*(x2[hit_counter-1]-x2[hit_counter-3]);
//                 if((b_part4-b_part5)!=0){
//                    b = (b_part1-b_part2-b_part3)/(b_part4-b_part5);
//                 }
//                 if((x2[hit_counter-1]-x2[hit_counter-3])!=0){
//                   a = (z2[hit_counter-1]-b*(y2[hit_counter-1]-y2[hit_counter-3])-z2[hit_counter-3])/(x2[hit_counter-1]-x2[hit_counter-3]);
//                 }
//                 c = z2[hit_counter-3]-a*x2[hit_counter-3]-b*y2[hit_counter-3];
//             }
//             if(hit_counter>3){
//                 z_pred = x2[hit_counter-1]*a+y2[hit_counter-1]*b+c;
//                 if(abs(z2[hit_counter-1]-z_pred)>0.001){
//                   cout << "(z-z_pred) = difference: " << "(" << z2[hit_counter-1] << " - " \
//                   << z_pred << ") = "<< abs(z2[hit_counter-1]-z_pred) << endl;
//                 }
//             }
//           }// hit isAvailable
//           if(hit_counter>3){
//               z_pred = x2[hit_counter-1]*a+y2[hit_counter-1]*b+c;
//               if(abs(z2[hit_counter-1]-z_pred)>0.001){
//                 cout << "(z-z_pred) = difference: " << "(" << z2[hit_counter-1] << " - " \
//                 << z_pred << ") = "<< abs(z2[hit_counter-1]-z_pred) << endl;
//               }
//           }
//         } // loop over hits
//         if(hit_counter!=0){
//           double s, t;
//           s = sqrt((x1-x2[hit_counter-1])*(x1-x2[hit_counter-1])+(y1-y2[hit_counter-1])*(y1-y2[hit_counter-1])+(z1-z2[hit_counter-1])*(z1-z2[hit_counter-1]));
//           t = t2[hit_counter-1]-t1;
//           double beta = s/(t*speed_light);
//           cout << s/t << endl;
//           h_beta->Fill(s/t);
//           // cout << "Delta t: " << t << endl;
//           // cout << "Delta s: " << s << endl;
//           // cout << "beta: " << beta << endl;
//         }
//         // cout << "iev, Number of hits: " << iev << ", " << hit_counter << endl;
//       }
//     }
//
//     store.clear();
//     reader.endOfEvent();
//     // if(iev > 100) break;
//   } // end of loop over events
//   // cout << "yey!" << endl;
//
//   cout << "Write to .root" << endl;
//   rootname = "winos_beta_test.root";
//   auto f1 = TFile::Open(rootname.c_str(), "RECREATE");
//   h_beta ->Write();
//   f1->Close();
//
//   cout <<"Delete" << endl;
//   delete h_beta ;
//
// }


void wino_beta_plots(){
    // cout << "************* Read histograms **********************" << endl;
    string rootname = "winos_beta_test.root";
    TFile *f = new TFile(rootname.c_str());

    TH1D* c_h_beta  = (TH1D*)f->Get("h_beta");

    // cout << "********************* Start plotting *********************" << endl;
    TCanvas *canvas = new TCanvas("c","");
    canvas->SetGrid();
    gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
    // canvas->SetLogy();
    gStyle->SetOptTitle(0);
    gStyle->SetOptStat(0);

    string ss2 = "plots/wino_v_test_plots.pdf";

    string ss;

    c_h_beta->Draw("h");
    gPad->Update();
    ss = "; Track v";
    c_h_beta->SetTitle(ss.c_str());
    c_h_beta->GetYaxis()->SetLabelSize(0.05);
    c_h_beta->GetXaxis()->SetLabelSize(0.05);
    c_h_beta->GetXaxis()->SetNdivisions(5);
    c_h_beta->GetYaxis()->SetTitleSize(0.05);
    c_h_beta->GetXaxis()->SetTitleSize(0.05);
    canvas->SaveAs(ss2.c_str());

}
