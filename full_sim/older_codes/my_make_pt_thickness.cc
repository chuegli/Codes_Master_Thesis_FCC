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
#include <TRandom.h>

using namespace std;

void my_make_histo(string rootname, string outputname, double pt_true, double res_z);

int main(int argc, char **argv){
    // std::cout << "Have " << argc << " arguments:" << std::endl;
    string filename,outputname;
    double pt_true, res_z;
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }
    filename   = argv[1];
    outputname = argv[2];
    pt_true    = stod(argv[3]);
    res_z      = stod(argv[4]);
    cout << "Check: " << pt_true << "   " << res_z << endl;
    my_make_histo(filename, outputname, pt_true, res_z);

    return 0;
}

void my_make_histo(string rootname, string outputname, double pt_true, double res_z){
  // auto pt_true = 30; // 3000 = 3 TeV
  // double res_z = 0.001; //1um

  auto reader = podio::ROOTReader();
  auto store = podio::EventStore();
  reader.openFile(rootname.c_str());
  store.setReader(&reader);
  unsigned nevents= reader.getEntries();


  TH1D* h_pt  = new TH1D("h_pt",  "h_pt", 100,-500,5000);
  TH1D* h_px           = new TH1D("h_px",                "h_px", 100,-7000,7000);
  TH1D* h_py           = new TH1D("h_py",                "h_py", 100,-7000,7000);
  TH1D* h_pz           = new TH1D("h_pz",                "h_pz", 100,-15000,15000);

  TH2D* h2_MCpt_vs_Ppt = new TH2D("h2_MCpt_vs_Ppt", "h2_MCpt_vs_Ppt", 100,-500,5000,100,-500,5000);

  TH1D* a_h_pt = new TH1D("a_h_pt", "a_h_pt", 100,-500,5000);
  TH1D* a_h_px = new TH1D("a_h_px", "a_h_px", 100,-7000,7000);
  TH1D* a_h_py = new TH1D("a_h_py", "a_h_py", 100,-7000,7000);
  TH1D* a_h_pz = new TH1D("a_h_pz", "a_h_pz", 100,-15000,15000);

  TH1D* b_h_pt = new TH1D("b_h_pt", "b_h_pt", 100,-500,5000);
  TH1D* b_h_px = new TH1D("b_h_px", "b_h_px", 100,-7000,7000);
  TH1D* b_h_py = new TH1D("b_h_py", "b_h_py", 100,-7000,7000);
  TH1D* b_h_pz = new TH1D("b_h_pz", "b_h_pz", 100,-15000,15000);

  TH1D* h_qOverP = new TH1D("h_qOverP", "h_qOverP", 100,-0.05,0.05);
  // TH1D* h_Tpt = new TH1D("h_Tpt", "h_Tpt", 200,-500,5000);
  TH1D* h_Tpt = new TH1D("h_Tpt", "h_Tpt", 200,100,5000);

  TH1D* h_Delta_q_pt  = new TH1D("h_Delta_q_pt",  "h_Delta_q_pt",  300,-0.005,0.005);

  cout << endl << " yes I am doing what you want " << endl << endl;

  TH2D* h2_MCeta_vs_Ppt   = new TH2D("h2_MCeta_vs_Ppt",   "h2_MCeta_vs_Ppt",   100,-3,3,100,-500,15000);
  TH2D* h2_MCphi_vs_Ppt   = new TH2D("h2_MCphi_vs_Ppt",   "h2_MCphi_vs_Ppt",   100,-4,4,100,-500,15000);
  TH2D* h2_MCrho_vs_Ppt   = new TH2D("h2_MCrho_vs_Ppt",   "h2_MCrho_vs_Ppt",   100,2000,13000,100,-500,15000);
  TH2D* h2_MCtheta_vs_Ppt = new TH2D("h2_MCtheta_vs_Ppt", "h2_MCtheta_vs_Ppt", 100,0,3.5,100,-500,15000);
  TH2D* h2_Delta_R_vs_Ppt = new TH2D("h2_Delta_R_vs_Ppt", "h2_Delta_R_vs_Ppt", 100,-0.001,0.002,100,-500,15000);
  TH2D* h2_MCpx_vs_Ppx = new TH2D("h2_MCpx_vs_Ppx", "h2_MCpx_vs_Ppx", 100,-7000,7000,100,-7000,7000);
  TH2D* h2_MCpy_vs_Ppy = new TH2D("h2_MCpy_vs_Ppy", "h2_MCpy_vs_Ppy", 100,-7000,7000,100,-7000,7000);
  TH2D* h2_MCpz_vs_Ppz = new TH2D("h2_MCpz_vs_Ppz", "h2_MCpz_vs_Ppz", 100,-15000,15000,100,-15000,15000);
  TH2D* h2_MCp_vs_Pp = new TH2D("h2_MCp_vs_Pp", "h2_MCp_vs_Pp", 100,0,15000,100,0,15000);

  TH1D* h_Tpt_2 = new TH1D("h_Tpt_2", "h_Tpt_2", 100,-500,5000);
  TH1D* h_qOverP_2 = new TH1D("h_qOverP_2", "h_qOverP_2", 100,-0.05,0.05);

  TH1D* h_teo_pt  = new TH1D("h_teo_pt",  "h_teo_pt",  100,-10,10);

  double wino_mass = 3000.000+0.000165; //GeV (better cause beta sim 1 comma ca)
  // double wino_mass = 0.1056583745;
  double speed_light = 299.792458; //mm/ns


  for(unsigned iev=0; iev<nevents; ++iev) {

    const fcc::MCParticleCollection* MCparticles;
    bool MCparticlePresents = store.get("GenParticles", MCparticles);

    const fcc::ParticleCollection* particles;
    bool particlesPresent = store.get("TrackRecoParticles", particles);

    double b_deltaR       = 1e8;
    double b_pt           = -1e8;
    double b_px           = -1e8;
    double b_py           = -1e8;
    double b_pz           = -1e8;
    double b_p            = -1e8;
    double b_Tpt          = -1e8;
    double b_T_Delta_q_pt = -1e8;
    double pt_smeared     = -1e8;
    double b_qOverP       = -1e8;
    double b_qOverP_track = 1e8;
    double b_Tpt_track    = 1e8;
    double b_teo_res_pt   = 1e8;

    double first_x = 0;
    double first_y = 0;
    double first_z = 0;
    double first_t = 0;
    double last_x = 0;
    double last_y = 0;
    double last_z = 0;
    double last_t = 0;

    TLorentzVector vMC;
    if(MCparticlePresents){
      for(const auto& MCparticle : *MCparticles){
        double local_px = MCparticle.core().p4.px;
        double local_py = MCparticle.core().p4.py;
        double local_pz = MCparticle.core().p4.pz;
        vMC.SetXYZM(local_px,local_py,local_pz,wino_mass);
        h_px               ->Fill(vMC.Px());
        h_py               ->Fill(vMC.Py());
        h_pz               ->Fill(vMC.Pz());

        double qoverpt_resolution = 1e-2; // GeV^-1 = 1e-2
        auto qoverpt = 1 / pt_true; // GeV^-1
        qoverpt += gRandom->Gaus(0., qoverpt_resolution); // Add gaussian noise
        pt_smeared = fabs(1 / qoverpt); // GeV // float absolute value
        h_pt->Fill(pt_smeared);
      }
    }

    if (particlesPresent) {
      for(const auto& particle : *particles){

          TLorentzVector v;
          double local_px = particle.core().p4.px;
          double local_py = particle.core().p4.py;
          double local_pz = particle.core().p4.pz;
          double local_mass = wino_mass;
          v.SetXYZM(local_px,local_py,local_pz,local_mass);

          a_h_pt               ->Fill(v.Pt());
          a_h_px               ->Fill(v.Px());
          a_h_py               ->Fill(v.Py());
          a_h_pz               ->Fill(v.Pz());

          for(auto track = particle.tracks_begin(); track != particle.tracks_end(); ++track) {
            if(track->isAvailable()) {
              if(b_deltaR > v.DeltaR(vMC)){
              for(auto state = track->states_begin(); state !=track->states_end(); ++state){
                   b_deltaR = v.DeltaR(vMC);
                   b_pt     = v.Pt();
                   b_px     = v.Px();
                   b_py     = v.Py();
                   b_pz     = v.Pz();
                   b_qOverP = state->qOverP();
                   b_Tpt = abs(1./state->qOverP());
                   b_T_Delta_q_pt = state->qOverP()-1./vMC.Pt();
                   b_p = v.P();
                 } // loop over states
                 for(auto hit = track->hits_begin(); hit !=track->hits_end(); ++hit){
                    if(hit==track->hits_begin()){
                      first_x = hit->x();
                      first_y = hit->y();
                      first_z = hit->z();
                      first_t = hit->core().time;
                    }
                    last_x = hit->x();
                    last_y = hit->y();
                    last_z = hit->z();
                    last_t = hit->core().time;

                    double d_x = last_x-first_x;
                    double d_y = last_y-first_y;
                    double d_z = last_z-first_z;
                    double d_t = last_t-first_t;
                    double d_r = sqrt(d_x*d_x+d_y*d_y);
                    double d_S = sqrt(d_x*d_x+d_y*d_y+d_z*d_z);

                    double last_v = d_S/d_t;
                    double last_gamma = 1./sqrt((1-last_v*last_v/(speed_light*speed_light)));
                    double last_theta = atan(d_r/d_z);
                    double last_p = v.M()*last_v*last_gamma;

                    ///// Theoretical resolution of trippletPt:
                    double res_r = 40; // 40 mm
                    double res_t = 0.01; //10ps

                    double d_s = sqrt(2)/d_S*sqrt((d_r*res_r)*(d_r*res_r)+(d_z*res_z)*(d_z*res_z));
                    double dd_t = sqrt(2)*res_t;
                    double d_v = 1./d_t*sqrt(d_s*d_s+(d_s/d_t*dd_t)*(d_s/d_t*dd_t));
                    double d_gamma = abs(d_v*last_v/((1-last_v*last_v/(speed_light*speed_light))*sqrt((1-last_v*last_v/(speed_light*speed_light)))*speed_light*speed_light));
                    double d_p = v.M()*sqrt((last_v*d_gamma)*(last_v*d_gamma)+(last_gamma*d_v)*(last_gamma*d_v));
                    double d_theta = abs(1./(d_z*(1+(d_r/d_z)*(d_r/d_z))))*sqrt(res_r*res_r + (d_r/d_z*res_z)*(d_r/d_z*res_z));
                    b_teo_res_pt = sqrt((sin(last_theta)*d_p)*(sin(last_theta)*d_p)+(last_p*cos(last_theta)*d_theta)*(last_p*cos(last_theta*d_theta)));
                 }
              } // closes best if
            }
          } // end of loop over reco tracks
      } // end for of particles reco

      b_h_pt->Fill(b_pt);
      b_h_px->Fill(b_px);
      b_h_py->Fill(b_py);
      b_h_pz->Fill(b_pz);
      h_Tpt->Fill(b_Tpt);
      h_Delta_q_pt->Fill(b_T_Delta_q_pt);
      h_qOverP ->Fill(b_qOverP);
      h_teo_pt->Fill(b_teo_res_pt);
      // if(b_teo_res_pt!=1e8){cout << b_teo_res_pt << endl;};

      h2_MCpt_vs_Ppt->Fill(pt_smeared,b_pt);
      h2_MCeta_vs_Ppt  ->Fill(vMC.Eta(),b_pt);
      h2_MCphi_vs_Ppt  ->Fill(vMC.Phi(),b_pt);
      h2_MCrho_vs_Ppt  ->Fill(vMC.Rho(),b_pt);
      h2_MCtheta_vs_Ppt->Fill(vMC.Theta(),b_pt);
      h2_Delta_R_vs_Ppt->Fill(b_deltaR,b_pt);
      h2_MCpx_vs_Ppx->Fill(vMC.Px(),b_px);
      h2_MCpy_vs_Ppy->Fill(vMC.Py(),b_py);
      h2_MCpz_vs_Ppz->Fill(vMC.Pz(),b_pz);
      h2_MCp_vs_Pp->Fill(vMC.P(),b_p);
    } // end of particles present if

    ////// Tracks:
    const fcc::TrackStateCollection* states;
    bool statesPresent = store.get("TrackStates", states);

    if(statesPresent){
      for(const auto& state: *states){
           double extra = state.qOverP() - 1./vMC.Pt();
           if(b_qOverP_track > extra){
             b_qOverP_track = extra;
             b_Tpt_track = abs(1./state.qOverP());
           }
        }
    }
    h_Tpt_2->Fill(b_Tpt_track);
    h_qOverP_2->Fill(b_qOverP_track);


    store.clear();
    reader.endOfEvent();
    // if(iev==1000){break;}
  } // end of loop over events

  cout << "Write to .root" << endl;
  string sss = outputname+".root";
  auto f1 = TFile::Open(sss.c_str(), "RECREATE");
  h_pt             ->Write();
  a_h_pt           ->Write();
  a_h_px           ->Write();
  a_h_py           ->Write();
  a_h_pz           ->Write();
  b_h_pt           ->Write();
  b_h_px           ->Write();
  b_h_py           ->Write();
  b_h_pz           ->Write();
  h_qOverP         ->Write();
  h_Delta_q_pt     ->Write();
  h_Tpt            ->Write();
  h_px             ->Write();
  h_py             ->Write();
  h_pz             ->Write();
  h2_MCeta_vs_Ppt  ->Write();
  h2_MCphi_vs_Ppt  ->Write();
  h2_MCrho_vs_Ppt  ->Write();
  h2_MCtheta_vs_Ppt->Write();
  h2_Delta_R_vs_Ppt->Write();
  h_Tpt_2          ->Write();
  h_qOverP_2       ->Write();
  h2_MCpt_vs_Ppt   ->Write();
  h2_MCpx_vs_Ppx   ->Write();
  h2_MCpy_vs_Ppy   ->Write();
  h2_MCpz_vs_Ppz   ->Write();
  h2_MCp_vs_Pp     ->Write();
  h_teo_pt         ->Write();
  f1->Close();

  cout << "test" << endl;
  rootname = outputname+"_Delta_q_pt.root";
  auto f2 = TFile::Open(rootname.c_str(), "RECREATE");
  h_Delta_q_pt->Write();
  f2->Close();

  cout <<"Delete" << endl;
  delete h_pt             ;
  delete a_h_pt           ;
  delete a_h_px           ;
  delete a_h_py           ;
  delete a_h_pz           ;
  delete b_h_pt           ;
  delete b_h_px           ;
  delete b_h_py           ;
  delete b_h_pz           ;
  delete h_qOverP         ;
  delete h_Delta_q_pt     ;
  delete h_Tpt            ;
  delete h_px             ;
  delete h_py             ;
  delete h_pz             ;
  delete h2_MCeta_vs_Ppt  ;
  delete h2_MCphi_vs_Ppt  ;
  delete h2_MCrho_vs_Ppt  ;
  delete h2_MCtheta_vs_Ppt;
  delete h2_Delta_R_vs_Ppt;
  delete h_Tpt_2          ;
  delete h_qOverP_2       ;
  delete h2_MCpt_vs_Ppt   ;
  delete h2_MCpx_vs_Ppx   ;
  delete h2_MCpy_vs_Ppy   ;
  delete h2_MCpz_vs_Ppz   ;
  delete h2_MCp_vs_Pp     ;
  delete h_teo_pt         ;

 cout << "***************** Finished *********************" << endl;
}
