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

using namespace std;

double make_delta_angle(double a, double b);
void my_read_datamodel(string rootname, string outputname);

int main(int argc, char **argv){
    // std::cout << "Have " << argc << " arguments:" << std::endl;
    string filename,outputname;
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }
    filename = argv[1];
    outputname= argv[2];
    my_read_datamodel(filename, outputname);

    return 0;
}

void my_read_datamodel(string rootname, string outputname){
  auto reader = podio::ROOTReader();
  auto store = podio::EventStore(); // is the store of events
  // string rootname = "wino_for_seeding_tracks.root";
  reader.openFile(rootname.c_str());
  store.setReader(&reader); // connect the store to the .root file
  unsigned nevents= reader.getEntries();
  // cout << "Number of entries: " << nevents << endl;

  ///// True particles:
  TH1D* h_eta               = new TH1D("h_eta",               "h_eta", 100,-3,3);
  TH1D* h_phi               = new TH1D("h_phi",               "h_phi", 100,-4,4);
  TH1D* h_pt                = new TH1D("h_pt",                "h_pt", 100,2900,3100);
  TH1D* h_px                = new TH1D("h_px",                "h_px", 100,-5000,5000);
  TH1D* h_py                = new TH1D("h_py",                "h_py", 100,-5000,5000);
  TH1D* h_pz                = new TH1D("h_pz",                "h_pz", 100,-10000,10000);
  TH1D* h_betagammasintheta = new TH1D("h_betagammasintheta", "h_betagammasintheta", 100,-0.01,0.1);
  TH1D* h_E                 = new TH1D("h_E",                 "h_E", 100,-100,4e6);
  TH1D* h_hit_energy        = new TH1D("h_hit_energy",        "h_hit_energy", 100,-0.0001,0.0003);
  TH1D* h_hit_time          = new TH1D("h_hit_time",          "h_hit_time", 100,-2,6);

  TH1D* h_eta_e  = new TH1D("h_eta_e",  "h_eta_e", 100,-3,3);
  TH1D* h_phi_e  = new TH1D("h_phi_e",  "h_phi_e", 100,-4,4);
  TH1D* h_pt_e   = new TH1D("h_pt_e",   "h_pt_e", 100,0,150);

  TH1D* yes_h_eta               = new TH1D("yes_h_eta",               "yes_h_eta", 100,-3,3);
  TH1D* yes_h_phi               = new TH1D("yes_h_phi",               "yes_h_phi", 100,-4,4);
  TH1D* yes_h_pt                = new TH1D("yes_h_pt",                "yes_h_pt", 101,2999,3001);
  TH1D* yes_h_px                = new TH1D("yes_h_px",                "yes_h_px", 100,-4000,4000);
  TH1D* yes_h_py                = new TH1D("yes_h_py",                "yes_h_py", 100,-4000,4000);
  TH1D* yes_h_pz                = new TH1D("yes_h_pz",                "yes_h_pz", 100,-2e4,2e4);
  TH1D* yes_h_betagammasintheta = new TH1D("yes_h_betagammasintheta", "yes_h_betagammasintheta", 100,0.0008,0.0012);
  TH1D* yes_h_E                 = new TH1D("yes_h_E",                 "yes_h_E", 1000,2.95e6,3.05e6);
  TH1D* yes_h_hit_energy        = new TH1D("yes_h_hit_energy",        "yes_h_hit_energy", 101,-1e-4,0.3e-3);
  TH1D* yes_h_hit_time          = new TH1D("yes_h_hit_time",          "yes_h_hit_time", 101,-5,30);

  TH1D* no_h_eta               = new TH1D("no_h_eta",               "no_h_eta", 100,-3,3);
  TH1D* no_h_phi               = new TH1D("no_h_phi",               "no_h_phi", 100,-4,4);
  TH1D* no_h_pt                = new TH1D("no_h_pt",                "no_h_pt", 101,2999,3001);
  TH1D* no_h_px                = new TH1D("no_h_px",                "no_h_px", 100,-4000,4000);
  TH1D* no_h_py                = new TH1D("no_h_py",                "no_h_py", 100,-4000,4000);
  TH1D* no_h_pz                = new TH1D("no_h_pz",                "no_h_pz", 100,-2e4,2e4);
  TH1D* no_h_betagammasintheta = new TH1D("no_h_betagammasintheta", "no_h_betagammasintheta", 100,0.0008,0.0012);
  TH1D* no_h_E                 = new TH1D("no_h_E",                 "no_h_E", 1000,2.95e6,3.05e6);
  TH1D* no_h_hit_energy        = new TH1D("no_h_hit_energy",        "no_h_hit_energy", 101,-1e-4,0.3e-3);
  TH1D* no_h_hit_time          = new TH1D("no_h_hit_time",          "no_h_hit_time", 101,-5,30);

  //// checks
  TH2D* h2_MCeta_vs_Peta      = new TH2D("h2_MCeta_vs_Peta", "h2_MCeta_vs_Peta", 100,-2.5  ,2.5  ,100,-3,3);
  TH2D* h2_MCphi_vs_Pphi      = new TH2D("h2_MCphi_vs_Pphi", "h2_MCphi_vs_Pphi", 100,-4  ,4  ,100,-6,6);
  TH2D* h2_MCpt_vs_Ppt        = new TH2D("h2_MCpt_vs_Ppt", "h2_MCpt_vs_Ppt", 100,0  ,120  ,100,0,120);
  TH2D* h2_MCrho_vs_Prho      = new TH2D("h2_MCrho_vs_Prho", "h2_MCrho_vs_Prho", 100,-100,500,100,-100,500);
  TH2D* h2_MCtheta_vs_Ptheta  = new TH2D("h2_MCtheta_vs_Ptheta", "h2_MCtheta_vs_Ptheta", 100,0  ,3.5  ,100,0,3.5);

  TH2D* h2_MCtheta_vs_Ttheta  = new TH2D("h2_MCtheta_vs_Ttheta", "h2_MCtheta_vs_Ttheta", 100, 0  ,3.5  ,100,0,3.5);
  TH2D* h2_MCphi_vs_Tphi      = new TH2D("h2_MCphi_vs_Tphi", "h2_MCphi_vs_Tphi", 100,-4  ,4  ,100,-4,4);

  ///// Recoparticles:
  TH1D* h_particles_per_event = new TH1D("h_particles_per_event",   "h_particles_per_event", 45,-5,40);
  TH2D* h2_deltaR_vs_eta      = new TH2D("h2_deltaR_vs_eta", "h2_deltaR_vs_eta", 50,-2.5,2.5,50,-0.001,0.001);
  TH2D* h2_deltaR_vs_pt       = new TH2D("h2_deltaR_vs_pt",  "h2_deltaR_vs_pt",  50,0   ,110,50,-0.001,0.001);
  TH2D* h2_deltaR_vs_phi      = new TH2D("h2_deltaR_vs_phi", "h2_deltaR_vs_phi", 50,-4  ,4  ,50,-0.001,0.001);

  TH1D* a_h_deltaR            = new TH1D("a_h_deltaR",            "a_h_deltaR",            1000,-0.001,0.01);
  TH1D* a_h_eta               = new TH1D("a_h_eta",               "a_h_eta",               100,-3,3);
  TH1D* a_h_theta             = new TH1D("a_h_theta",             "a_h_theta",             100,-0.5,3.5);
  TH1D* a_h_phi               = new TH1D("a_h_phi",               "a_h_phi",               100,-4,4); //reconstructed particle phi
  TH1D* a_h_pt                = new TH1D("a_h_pt",                "a_h_pt",                100,0,150);
  TH1D* a_h_betagammasintheta = new TH1D("a_h_betagammasintheta", "a_h_betagammasintheta", 200,50,1300);
  TH1D* a_h_rho               = new TH1D("a_h_rho",               "a_h_rho",               100,-100,700);
  TH1D* a_h_E                 = new TH1D("a_h_E",                 "a_h_E",                 100,-100,500);
  TH1D* a_h_px                = new TH1D("a_h_px",                "a_h_px",                100,-150,150);
  TH1D* a_h_py                = new TH1D("a_h_py",                "a_h_py",                100,-150,150);
  TH1D* a_h_pz                = new TH1D("a_h_pz",                "a_h_pz",                100,-400,400);

  TH1D* b_h_deltaR            = new TH1D("b_h_deltaR",            "b_h_deltaR",            1000,-0.001,0.01);
  TH1D* b_h_eta               = new TH1D("b_h_eta",               "b_h_eta",               100,-3,3);
  TH1D* b_h_theta             = new TH1D("b_h_theta",             "b_h_theta",             100,-0.5,3.5);
  TH1D* b_h_phi               = new TH1D("b_h_phi",               "b_h_phi",               100,-4,4); //reconstructed particle phi
  TH1D* b_h_pt                = new TH1D("b_h_pt",                "b_h_pt",                100,0,150);
  TH1D* b_h_betagammasintheta = new TH1D("b_h_betagammasintheta", "b_h_betagammasintheta", 200,50,1300);
  TH1D* b_h_rho               = new TH1D("b_h_rho",               "b_h_rho",               100,-100,700);
  TH1D* b_h_E                 = new TH1D("b_h_E",                 "b_h_E",                 100,-100,500);
  TH1D* b_h_px                = new TH1D("b_h_px",                "b_h_px",                100,-150,150);
  TH1D* b_h_py                = new TH1D("b_h_py",                "b_h_py",                100,-150,150);
  TH1D* b_h_pz                = new TH1D("b_h_pz",                "b_h_pz",                100,-400,400);

  //// Tracks:
  TH1D* h_nhits   = new TH1D("h_nhits",   "h_nhits",   30,0,30);
  TH1D* h_ntracks   = new TH1D("h_ntracks",   "h_ntracks",   55,-5,50);
  TH1D* h_chi2   = new TH1D("h_chi2",   "h_chi2",   100,-1,1);
  TH1D* h_Tphi   = new TH1D("h_Tphi",   "h_Tphi",   50,-4,4);
  TH1D* h_Ttheta = new TH1D("h_Ttheta", "h_Ttheta", 100,-3.5,3.5);
  TH1D* h_qOverP = new TH1D("h_qOverP", "h_qOverP", 200,-0.1,0.3);
  TH1D* h_d0     = new TH1D("h_d0",     "h_d0",     100,-0.5,0.5);
  TH1D* h_z0     = new TH1D("h_z0",     "h_z0",     100,-200,200);


  TH2D* h2_MCpt_vs_Tpt = new TH2D("h2_MCpt_vs_Tpt", "h2_MCpt_vs_Tpt", 100,0,120,100,0,120);
  TH1D* h_Delta_phi   = new TH1D("h_Delta_phi",   "h_Delta_phi",   100,-0.001,0.01);
  TH1D* h_Delta_theta = new TH1D("h_Delta_theta", "h_Delta_theta", 100,-0.0001,0.0035);
  TH1D* h_Delta_q_pt  = new TH1D("h_Delta_q_pt",  "h_Delta_q_pt",  100,-0.06,0.1);
  TH1D* h_Delta_eta   = new TH1D("h_Delta_eta",  "h_Delta_eta",    100,-0.0001,0.004);

  TH2D* h2_Delta_phi_vs_MCpt   = new TH2D("h2_Delta_phi_vs_MCpt",   "h2_Delta_phi_vs_MCpt",   100,0,120,100,-0.001,0.01);
  TH2D* h2_Delta_theta_vs_MCpt = new TH2D("h2_Delta_theta_vs_MCpt", "h2_Delta_theta_vs_MCpt", 100,0,120,100,-0.0001,0.0035);
  TH2D* h2_Delta_q_pt_vs_MCpt  = new TH2D("h2_Delta_q_pt_vs_MCpt",  "h2_Delta_q_pt_vs_MCpt",  100,0,120,100,-0.08,0.08);
  TH2D* h2_Delta_eta_vs_MCpt   = new TH2D("h2_Delta_eta_vs_MCpt",   "h2_Delta_eta_vs_MCpt",   100,0,120,100,-0.0001,0.004);

  TH2D* h2_Delta_R_vs_hit_time   = new TH2D("h2_Delta_R_vs_hit_time",   "h2_Delta_R_vs_hit_time",    100,-0.001,0.01,100,-2,6);
  TH2D* h2_Delta_R_vs_hit_energy = new TH2D("h2_Delta_R_vs_hit_energy", "h2_Delta_R_vs_hit_energy",  100,-0.001,0.01,100,-0.0001,0.0003);


  // double wino_mass = 3000000+165; //MeV
  double wino_mass = 3000.000+0.000165; //GeV (better cause beta sim 1 comma ca)

  int reco_counter = 0;
  int extra_counter = 0;
  int layer1_c = 0;
  int layer2_c = 0;
  int layer3_c = 0;
  int layer4_c = 0;
  for(unsigned iev=0; iev<nevents; ++iev) {
    // cout << endl << "Event number: " << iev << endl;

    const fcc::MCParticleCollection* MCparticles; // create a particle collections
    bool MCparticlePresents = store.get("GenParticles", MCparticles);

    const fcc::ParticleCollection* particles; // create a particle collections
    bool particlesPresent = store.get("TrackRecoParticles", particles);

    double b_deltaR            = 10000;
    double b_eta               = -10000;
    double b_theta             = -10000;
    double b_phi               = -10000;
    double b_pt                = -10000;
    double b_betagammasintheta = -10000;
    double b_rho               = -10000;
    double b_E                 = -10000;
    double b_px                = -10000;
    double b_py                = -10000;
    double b_pz                = -10000;

    TLorentzVector vMC;
    if(MCparticlePresents){
      for(const auto& MCparticle : *MCparticles){
        double local_px = MCparticle.core().p4.px;
        double local_py = MCparticle.core().p4.py;
        double local_pz = MCparticle.core().p4.pz;
        double local_mass = wino_mass; // original is 0 or close to it
        vMC.SetXYZM(local_px,local_py,local_pz,local_mass);
        h_eta->Fill(vMC.Eta());
        h_phi->Fill(vMC.Phi());
        h_pt->Fill(vMC.Pt());
        h_px->Fill(vMC.Px());
        h_py->Fill(vMC.Py());
        h_pz->Fill(vMC.Pz());
        h_betagammasintheta->Fill(vMC.Beta()*vMC.Gamma()*sin(vMC.Theta()));
        h_E->Fill(vMC.E());
        // cout << "MC mass: " << vMC.M() << endl;
      }
    }

    int particle_counter = 0;
    if (particlesPresent) {
      // cout << "reco particle size: " << particles->size() << endl;
      for(const auto& particle : *particles){
          // cout << "reco particle" << endl;
          particle_counter++;

          TLorentzVector v;
          double local_px = particle.core().p4.px;
          double local_py = particle.core().p4.py;
          double local_pz = particle.core().p4.pz;
          double local_mass = wino_mass; // original is always = 0
          v.SetXYZM(local_px,local_py,local_pz,local_mass);

          // cout << "reco pdgid: " << particle.core().pdgId << endl; // = 0

          a_h_deltaR           ->Fill(v.DeltaR(vMC));
          a_h_eta              ->Fill(v.Eta());
          a_h_theta            ->Fill(v.Theta());
          a_h_phi              ->Fill(v.Phi());
          a_h_pt               ->Fill(v.Pt());
          a_h_betagammasintheta->Fill(v.Beta()*v.Gamma()*sin(v.Theta()));
          a_h_rho              ->Fill(v.Rho());
          a_h_E                ->Fill(v.E());
          a_h_px               ->Fill(v.Px());
          a_h_py               ->Fill(v.Py());
          a_h_pz               ->Fill(v.Pz());

          h_ntracks->Fill(particle.tracks().size());
          if(b_deltaR > v.DeltaR(vMC)){
            b_deltaR            = v.DeltaR(vMC);
            b_eta               = v.Eta();
            b_theta             = v.Theta();
            b_phi               = v.Phi();
            b_pt                = v.Pt();
            b_betagammasintheta = v.Beta()*v.Gamma()*sin(v.Theta());
            b_rho               = v.Rho();
            b_E                 = v.E();
            b_px                = v.Px();
            b_py                = v.Py();
            b_pz                = v.Pz();
          }
          // cout << "reco track size: " << particle.tracks().size() << endl;
          for(auto track = particle.tracks_begin(); track != particle.tracks_end(); ++track) {
            // cout << "ciao0" << endl;
            if(track->isAvailable()) {
              // cout << "Track" << endl;
              // cout << "reco track state size: " << track->states().size() << endl;
              h_nhits  ->Fill(track->hits().size());
              h_chi2   ->Fill(track->chi2());
              double last_x=0, last_y=0, last_z=0;
              // cout << "number of hits: " << track->hits().size() << endl;
              // cout << "ciao1" << endl;
                // cout << "ciao2" << endl;
                for(auto hit = track->hits_begin(); hit !=track->hits_end(); ++hit){
                    // cout << "ciao3" << endl;
                    last_x = hit->x();
                    last_y = hit->y();
                    last_z = hit->z();
                    h_hit_time->Fill(hit->core().time);
                    h_hit_energy->Fill(hit->core().energy);
                    h2_Delta_R_vs_hit_time  ->Fill(v.DeltaR(vMC),hit->core().time);
                    h2_Delta_R_vs_hit_energy->Fill(v.DeltaR(vMC),hit->core().energy);
                    // cout << "time: " << hit->core().time << " energy: " << hit->core().energy << endl;
                }
              // cout << "decay radius: " << sqrt(last_x*last_x+last_y*last_y+last_z*last_z) << endl;
              for(auto state = track->states_begin(); state !=track->states_end(); ++state){
                 // cout << "state is available!!!" << endl;
                 // cout <<" track state phi: " << state->phi() << endl;
                 h_Tphi   ->Fill(state->phi());
                 h_Ttheta ->Fill(state->theta());
                 h_qOverP ->Fill(state->qOverP());
                 h_d0     ->Fill(state->d0());
                 h_z0     ->Fill(state->z0());
                 double theta_extra = state->theta();
                 if(theta_extra<0){theta_extra+=TMath::Pi();}
                 h2_MCtheta_vs_Ttheta->Fill(vMC.Theta(),theta_extra);
                 h2_MCphi_vs_Tphi->Fill(vMC.Phi(),state->phi());
                 h2_MCpt_vs_Tpt->Fill(vMC.Pt(),1./state->qOverP());

                 h_Delta_phi->Fill(make_delta_angle(state->phi(),vMC.Phi()));
                 h_Delta_theta->Fill(make_delta_angle(theta_extra,vMC.Theta()));
                 h_Delta_q_pt->Fill(state->qOverP()-1./vMC.Pt());
                 // cout << state->qOverP()-1./vMC.Pt() << endl;
                 double cosTheta = cos(state->theta());
                 double eta_extra;
                 if(cosTheta*cosTheta < 1){eta_extra = -0.5* TMath::Log((1.0-cosTheta)/(1.0+cosTheta));}
                 else{eta_extra = -10e10;}
                 h_Delta_eta->Fill(make_delta_angle(eta_extra,abs(vMC.Eta())));
                 h2_Delta_phi_vs_MCpt  ->Fill(vMC.Pt(),make_delta_angle(state->phi(),vMC.Phi()));
                 h2_Delta_theta_vs_MCpt->Fill(vMC.Pt(),make_delta_angle(theta_extra,vMC.Theta()));
                 h2_Delta_q_pt_vs_MCpt ->Fill(vMC.Pt(),state->qOverP()-1./vMC.Pt());
                 h2_Delta_eta_vs_MCpt  ->Fill(vMC.Pt(),make_delta_angle(eta_extra,abs(vMC.Eta())));
              }
            }
          } // end of loop over reco tracks
      } // end for of particles reco
      b_h_deltaR           ->Fill(b_deltaR);
      b_h_eta              ->Fill(b_eta);
      b_h_theta            ->Fill(b_theta);
      b_h_phi              ->Fill(b_phi);
      b_h_pt               ->Fill(b_pt);
      b_h_betagammasintheta->Fill(b_betagammasintheta);
      b_h_rho              ->Fill(b_rho);
      b_h_E                ->Fill(b_E);
      b_h_px               ->Fill(b_px);
      b_h_py               ->Fill(b_py);
      b_h_pz               ->Fill(b_pz);

      h2_MCeta_vs_Peta->Fill(vMC.Eta(),b_eta);
      h2_MCphi_vs_Pphi->Fill(vMC.Phi(),b_phi);
      h2_MCrho_vs_Prho->Fill(vMC.Rho(),b_rho);
      h2_MCpt_vs_Ppt->Fill(vMC.Pt(),b_pt);
      h2_MCtheta_vs_Ptheta->Fill(vMC.Theta(),b_theta);
    } // end of particles present if
    h2_deltaR_vs_eta->Fill(vMC.Eta(),b_deltaR);
    h2_deltaR_vs_phi->Fill(vMC.Phi(),b_deltaR);
    h2_deltaR_vs_pt->Fill(vMC.Pt(),b_deltaR);
    h_particles_per_event->Fill(particle_counter);

    if(particle_counter>=1){
      // cout << "Reconstructed particle at event number " << iev << endl;
      reco_counter++;
      h_eta_e->Fill(vMC.Eta());
      h_phi_e->Fill(vMC.Phi());
      h_pt_e->Fill(vMC.Pt());

      yes_h_eta              ->Fill(vMC.Eta());
      yes_h_phi              ->Fill(vMC.Phi());
      yes_h_pt               ->Fill(vMC.Pt());
      yes_h_px               ->Fill(vMC.Px());
      yes_h_py               ->Fill(vMC.Py());
      yes_h_pz               ->Fill(vMC.Pz());
      yes_h_betagammasintheta->Fill(vMC.Beta()*vMC.Gamma()*sin(vMC.Theta()));
      yes_h_E                ->Fill(vMC.E());
    } else{
      no_h_eta              ->Fill(vMC.Eta());
      no_h_phi              ->Fill(vMC.Phi());
      no_h_pt               ->Fill(vMC.Pt());
      no_h_px               ->Fill(vMC.Px());
      no_h_py               ->Fill(vMC.Py());
      no_h_pz               ->Fill(vMC.Pz());
      no_h_betagammasintheta->Fill(vMC.Beta()*vMC.Gamma()*sin(vMC.Theta()));
      no_h_E                ->Fill(vMC.E());
      // cout << "Event " << iev << " is not reconstructed :(((" << endl;
    }


    // Read TrackerHitsPosition
    // const fcc::PositionedTrackHitCollection* trackhits;
    // // bool trackhitsPresent = store.get("TrackerHitsPosition", trackhits);
    // bool trackhitsPresent = store.get("SmearedTrackerHits", trackhits);
    //
    // if (trackhitsPresent){
    //   int l1 = 0;
    //   int l2 = 0;
    //   int l3 = 0;
    //   int l4 = 0;
    //   for(const auto& hit : *trackhits){
    //     //// Hit test:
    //     double r = sqrt(hit.position().x*hit.position().x+hit.position().y*hit.position().y);
    //     if(r<35){l1++;}
    //     else if(r>50&&r<70){l2++;}
    //     else if(r>90&&r<110){l3++;}
    //     else if(r>140&&r<160){l4++;}
    //   }
    //   int cut = 1;
    //   if(l1>=cut&&l2>=cut&&l3>=cut&&l4>=cut){layer4_c++;}//cout << "4 events nr " << iev << endl;}
    //   else if(l1>=cut&&l2>=cut&&l3>=cut){layer3_c++;cout << "3 events nr " << iev << endl;}
    //   else if(l1>=cut&&l2>=cut){layer2_c++;cout << "2 events nr " << iev << endl;}
    //   else if(l1>=cut){layer1_c++;cout << "1 events nr " << iev << endl;}
    //   else{cout << "Event " << iev << " not reconstructed :(" << endl;}
    // }
    //
    // if (trackhitsPresent){
    //   for(const auto& hit : *trackhits){
    //     double r = sqrt(hit.position().x*hit.position().x+hit.position().y*hit.position().y);
    //     if(particle_counter>=1){
    //       yes_h_hit_energy->Fill(hit.core().energy);
    //       yes_h_hit_time  ->Fill(hit.core().time);
    //     } else{
    //       no_h_hit_energy ->Fill(hit.core().energy);
    //       no_h_hit_time   ->Fill(hit.core().time);
    //     }
    //     h_hit_energy ->Fill(hit.core().energy);
    //     h_hit_time   ->Fill(hit.core().time);
    //   }
    // }


    store.clear();
    reader.endOfEvent();
    // if(iev == 100) break; // nevents
  } // end of loop over events
  double events = nevents;
  cout << endl << "Layers hitten (1,2,3,4):" << layer1_c << ", "<< layer2_c << ", "<< layer3_c << ", "<< layer4_c << endl;
  cout << "reco counter: " << reco_counter << endl;
  cout << "extra counter: " << extra_counter << endl;
  cout << "events: " << events << endl;
  cout << "particle efficiency: " << reco_counter/events << endl;

  ///// Histogram salvation:
  // h_eta_e->Divide(h_eta);
  // h_phi_e->Divide(h_phi);
  // h_pt_e->Divide(h_pt);

  cout << "Write to .root" << endl;
  auto f1 = TFile::Open(outputname.c_str(), "RECREATE");
  h_eta                ->Write();
  h_phi                ->Write();
  h_pt                 ->Write();
  h_px                 ->Write();
  h_py                 ->Write();
  h_pz                 ->Write();
  h_betagammasintheta  ->Write();
  h_E                  ->Write();
  h_eta_e              ->Write();
  h_phi_e              ->Write();
  h_pt_e               ->Write();
  h2_MCeta_vs_Peta     ->Write();
  h2_MCphi_vs_Pphi     ->Write();
  h2_MCpt_vs_Ppt       ->Write();
  h2_MCrho_vs_Prho     ->Write();
  h2_MCtheta_vs_Ptheta ->Write();
  h2_MCtheta_vs_Ttheta ->Write();
  h2_MCphi_vs_Tphi     ->Write();
  h_particles_per_event->Write();
  h2_deltaR_vs_eta     ->Write();
  h2_deltaR_vs_pt      ->Write();
  h2_deltaR_vs_phi     ->Write();
  a_h_deltaR           ->Write();
  a_h_eta              ->Write();
  a_h_theta            ->Write();
  a_h_phi              ->Write();
  a_h_pt               ->Write();
  a_h_betagammasintheta->Write();
  a_h_rho              ->Write();
  a_h_E                ->Write();
  a_h_px               ->Write();
  a_h_py               ->Write();
  a_h_pz               ->Write();
  b_h_deltaR           ->Write();
  b_h_eta              ->Write();
  b_h_theta            ->Write();
  b_h_phi              ->Write();
  b_h_pt               ->Write();
  b_h_betagammasintheta->Write();
  b_h_rho              ->Write();
  b_h_E                ->Write();
  b_h_px               ->Write();
  b_h_py               ->Write();
  b_h_pz               ->Write();
  h_nhits              ->Write();
  h_ntracks            ->Write();
  h_chi2               ->Write();
  h_Tphi               ->Write();
  h_Ttheta             ->Write();
  h_qOverP             ->Write();
  h_d0                 ->Write();
  h_z0                 ->Write();
  h2_MCpt_vs_Tpt       ->Write();
  h_Delta_phi          ->Write();
  h_Delta_theta        ->Write();
  h_Delta_q_pt         ->Write();
  h_Delta_eta          ->Write();
  h2_Delta_phi_vs_MCpt  ->Write();
  h2_Delta_theta_vs_MCpt->Write();
  h2_Delta_q_pt_vs_MCpt ->Write();
  h2_Delta_eta_vs_MCpt  ->Write();
  yes_h_eta              ->Write();
  yes_h_phi              ->Write();
  yes_h_pt               ->Write();
  yes_h_px               ->Write();
  yes_h_py               ->Write();
  yes_h_pz               ->Write();
  yes_h_betagammasintheta->Write();
  yes_h_E                ->Write();
  no_h_eta               ->Write();
  no_h_phi               ->Write();
  no_h_pt                ->Write();
  no_h_px                ->Write();
  no_h_py                ->Write();
  no_h_pz                ->Write();
  no_h_betagammasintheta ->Write();
  no_h_E                 ->Write();
  yes_h_hit_energy       ->Write();
  yes_h_hit_time         ->Write();
  no_h_hit_energy        ->Write();
  no_h_hit_time          ->Write();
  h_hit_energy        ->Write();
  h_hit_time          ->Write();
  h2_Delta_R_vs_hit_time  ->Write();
  h2_Delta_R_vs_hit_energy->Write();
  f1->Close();

  cout <<"Delete" << endl;
  delete h_eta                ;
  delete h_phi                ;
  delete h_pt                 ;
  delete h_px                 ;
  delete h_py                 ;
  delete h_pz                 ;
  delete h_betagammasintheta   ;
  delete h_E                  ;
  delete h_eta_e              ;
  delete h_phi_e              ;
  delete h_pt_e               ;
  delete h2_MCeta_vs_Peta     ;
  delete h2_MCphi_vs_Pphi     ;
  delete h2_MCpt_vs_Ppt       ;
  delete h2_MCrho_vs_Prho     ;
  delete h2_MCtheta_vs_Ptheta ;
  delete h2_MCtheta_vs_Ttheta ;
  delete h2_MCphi_vs_Tphi     ;
  delete h_particles_per_event;
  delete h2_deltaR_vs_eta     ;
  delete h2_deltaR_vs_pt      ;
  delete h2_deltaR_vs_phi     ;
  delete a_h_deltaR           ;
  delete a_h_eta              ;
  delete a_h_theta            ;
  delete a_h_phi              ;
  delete a_h_pt               ;
  delete a_h_betagammasintheta;
  delete a_h_rho              ;
  delete a_h_E                ;
  delete a_h_px               ;
  delete a_h_py               ;
  delete a_h_pz               ;
  delete b_h_deltaR           ;
  delete b_h_eta              ;
  delete b_h_theta            ;
  delete b_h_phi              ;
  delete b_h_pt               ;
  delete b_h_betagammasintheta;
  delete b_h_rho              ;
  delete b_h_E                ;
  delete b_h_px               ;
  delete b_h_py               ;
  delete b_h_pz               ;
  delete h_nhits              ;
  delete h_ntracks            ;
  delete h_chi2               ;
  delete h_Tphi               ;
  delete h_Ttheta             ;
  delete h_qOverP             ;
  delete h_d0                 ;
  delete h_z0                 ;
  delete h2_MCpt_vs_Tpt       ;
  delete h_Delta_q_pt         ;
  delete h_Delta_phi          ;
  delete h_Delta_theta        ;
  delete h_Delta_eta          ;
  delete h2_Delta_phi_vs_MCpt  ;
  delete h2_Delta_theta_vs_MCpt;
  delete h2_Delta_q_pt_vs_MCpt ;
  delete h2_Delta_eta_vs_MCpt  ;
  delete yes_h_eta              ;
  delete yes_h_phi              ;
  delete yes_h_pt               ;
  delete yes_h_px               ;
  delete yes_h_py               ;
  delete yes_h_pz               ;
  delete yes_h_betagammasintheta;
  delete yes_h_E                ;
  delete no_h_eta               ;
  delete no_h_phi               ;
  delete no_h_pt                ;
  delete no_h_px                ;
  delete no_h_py                ;
  delete no_h_pz                ;
  delete no_h_betagammasintheta ;
  delete no_h_E                 ;
  delete yes_h_hit_energy       ;
  delete yes_h_hit_time         ;
  delete no_h_hit_energy        ;
  delete no_h_hit_time          ;
  delete h_hit_energy        ;
  delete h_hit_time          ;
  delete h2_Delta_R_vs_hit_time  ;
  delete h2_Delta_R_vs_hit_energy;

 cout << "***************** Finished *********************" << endl;
}


double make_delta_angle(double a, double b){
   double two_pi = TMath::Pi()*2;
   double x = a-b;
   while(x<-TMath::Pi()){x+=two_pi;}
   while(x>=TMath::Pi()){x-=two_pi;}
   if(x>TMath::Pi() || x<-TMath::Pi()){cout << endl << "********* ERROR in make_delta_angle ***************" << endl << endl;}
   return abs(x);
}
