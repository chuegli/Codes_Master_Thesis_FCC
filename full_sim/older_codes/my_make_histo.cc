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

double make_delta_angle(double a, double b);
void my_make_histo(string rootname, string outputname);

int main(int argc, char **argv){
    // std::cout << "Have " << argc << " arguments:" << std::endl;
    string filename,outputname;
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }
    filename = argv[1];
    outputname= argv[2];
    my_make_histo(filename, outputname);

    return 0;
}

void my_make_histo(string rootname, string outputname){
  auto reader = podio::ROOTReader();
  auto store = podio::EventStore();
  reader.openFile(rootname.c_str());
  store.setReader(&reader);
  unsigned nevents= reader.getEntries();

  // cout << "Declare histograms" << endl;
  ///// True particles:
  TH1D* h_eta = new TH1D("h_eta", "h_eta", 100,-3,3);
  TH1D* h_phi = new TH1D("h_phi", "h_phi", 100,-4,4);
  TH1D* h_pt  = new TH1D("h_pt",  "h_pt", 100,-500,5000);
  TH1D* h_px                = new TH1D("h_px",                "h_px", 100,-7000,7000);
  TH1D* h_py                = new TH1D("h_py",                "h_py", 100,-7000,7000);
  TH1D* h_pz                = new TH1D("h_pz",                "h_pz", 100,-15000,15000);
  TH1D* h_betagammasintheta = new TH1D("h_betagammasintheta", "h_betagammasintheta", 100,0,1.1);
  TH1D* h_E                 = new TH1D("h_E",                 "h_E", 100,0,5e4);

  TH1D* h_eta_e  = new TH1D("h_eta_e",  "h_eta_e", 100,-3,3);
  TH1D* h_phi_e  = new TH1D("h_phi_e",  "h_phi_e", 100,-4,4);
  TH1D* h_pt_e   = new TH1D("h_pt_e",   "h_pt_e", 100,-500,5000);

  //// checks
  TH2D* h2_MCeta_vs_Peta      = new TH2D("h2_MCeta_vs_Peta", "h2_MCeta_vs_Peta", 100,-2.5  ,2.5  ,100,-3,3);
  TH2D* h2_MCphi_vs_Pphi      = new TH2D("h2_MCphi_vs_Pphi", "h2_MCphi_vs_Pphi", 100,-4  ,4  ,100,-6,6);
  TH2D* h2_MCrho_vs_Prho      = new TH2D("h2_MCrho_vs_Prho", "h2_MCrho_vs_Prho", 50,2000,10000,50,-1000,10000);
  TH2D* h2_MCtheta_vs_Ptheta  = new TH2D("h2_MCtheta_vs_Ptheta", "h2_MCtheta_vs_Ptheta", 100,0  ,3.5  ,100,0,3.5);
  TH2D* h2_MCpt_vs_Ppt      = new TH2D("h2_MCpt_vs_Ppt", "h2_MCpt_vs_Ppt", 100,-500,5000,100,-500,5000);

  TH2D* h2_MCtheta_vs_Ttheta  = new TH2D("h2_MCtheta_vs_Ttheta", "h2_MCtheta_vs_Ttheta", 100, 0  ,3.5  ,100,0,3.5);
  TH2D* h2_MCphi_vs_Tphi      = new TH2D("h2_MCphi_vs_Tphi", "h2_MCphi_vs_Tphi", 100,-4  ,4  ,100,-4,4);

  ///// Recoparticles:
  TH1D* h_particles_per_event = new TH1D("h_particles_per_event",   "h_particles_per_event", 13,-2.5,10.5);
  TH2D* h2_deltaR_vs_eta      = new TH2D("h2_deltaR_vs_eta", "h2_deltaR_vs_eta", 50,-2.5,2.5,50,-0.0001,0.001);
  TH2D* h2_deltaR_vs_phi      = new TH2D("h2_deltaR_vs_phi", "h2_deltaR_vs_phi", 50,-4  ,4  ,50,-0.0001,0.001);

  TH1D* a_h_deltaR            = new TH1D("a_h_deltaR",            "a_h_deltaR",            100,-0.001,0.01);
  TH1D* a_h_eta               = new TH1D("a_h_eta",               "a_h_eta",               100,-3,3);
  TH1D* a_h_theta             = new TH1D("a_h_theta",             "a_h_theta",             100,-0.5,3.5);
  TH1D* a_h_phi               = new TH1D("a_h_phi",               "a_h_phi",               100,-4,4); //reconstructed particle phi
  TH1D* a_h_pt                = new TH1D("a_h_pt",                "a_h_pt",                100,-500,5000);
  TH1D* a_h_betagammasintheta = new TH1D("a_h_betagammasintheta", "a_h_betagammasintheta", 100,0,1.1);
  TH1D* a_h_rho               = new TH1D("a_h_rho",               "a_h_rho",               100,-1000,7000);
  TH1D* a_h_E                 = new TH1D("a_h_E",                 "a_h_E",                 100,0,5e4);
  TH1D* a_h_px                = new TH1D("a_h_px",                "a_h_px",                100,-7000,7000);
  TH1D* a_h_py                = new TH1D("a_h_py",                "a_h_py",                100,-7000,7000);
  TH1D* a_h_pz                = new TH1D("a_h_pz",                "a_h_pz",                100,-15000,15000);

  TH1D* b_h_deltaR            = new TH1D("b_h_deltaR",            "b_h_deltaR",            100,-0.001,0.01);
  TH1D* b_h_eta               = new TH1D("b_h_eta",               "b_h_eta",               100,-3,3);
  TH1D* b_h_theta             = new TH1D("b_h_theta",             "b_h_theta",             100,-0.5,3.5);
  TH1D* b_h_phi               = new TH1D("b_h_phi",               "b_h_phi",               100,-4,4); //reconstructed particle phi
  TH1D* b_h_pt                = new TH1D("b_h_pt",                "b_h_pt",                100,-500,5000);
  TH1D* b_h_betagammasintheta = new TH1D("b_h_betagammasintheta", "b_h_betagammasintheta", 100,0,1.1);
  TH1D* b_h_rho               = new TH1D("b_h_rho",               "b_h_rho",               100,-1000,7000);
  TH1D* b_h_E                 = new TH1D("b_h_E",                 "b_h_E",                 100,0,5e4);
  TH1D* b_h_px                = new TH1D("b_h_px",                "b_h_px",                100,-7000,7000);
  TH1D* b_h_py                = new TH1D("b_h_py",                "b_h_py",                100,-7000,7000);
  TH1D* b_h_pz                = new TH1D("b_h_pz",                "b_h_pz",                100,-15000,15000);

  //// Tracks:
  TH1D* h_nhits   = new TH1D("h_nhits",   "h_nhits",   21,-0.5,20.5);
  TH1D* h_ntracks   = new TH1D("h_ntracks",   "h_ntracks",   11,-1.5,9.5);
  TH1D* h_chi2   = new TH1D("h_chi2",   "h_chi2",   100,-1,10);
  TH1D* h_Tphi   = new TH1D("h_Tphi",   "h_Tphi",   50,-4,4);
  TH1D* h_Ttheta = new TH1D("h_Ttheta", "h_Ttheta", 100,-3.5,3.5);
  TH1D* h_qOverP = new TH1D("h_qOverP", "h_qOverP", 100,-0.05,0.05);
  TH1D* h_d0     = new TH1D("h_d0",     "h_d0",     100,-0.1,0.1);
  TH1D* h_z0     = new TH1D("h_z0",     "h_z0",     100,-0.5,0.5);
  TH1D* h_Tpt = new TH1D("h_Tpt", "h_Tpt", 100,-500,5000);


  TH1D* h_Delta_phi   = new TH1D("h_Delta_phi",   "h_Delta_phi",   100,-0.0001,0.005);
  TH1D* h_Delta_theta = new TH1D("h_Delta_theta", "h_Delta_theta", 100,-0.0001,0.002);
  TH1D* h_Delta_q_pt  = new TH1D("h_Delta_q_pt",  "h_Delta_q_pt",  100,-0.05,0.05);
  TH1D* h_Delta_eta   = new TH1D("h_Delta_eta",  "h_Delta_eta",    100,-0.0001,0.0025);

  //// Decay radius:
  TH1D* h_radius = new TH1D("h_radius",  "h_radius", 100,145,160);
  TH2D* h2_z_vs_radius = new TH2D("h2_z_vs_radius","h2_z_vs_radius",100,-800,800,50,145,160);

  TH2D* h2_MCeta_vs_Ppt   = new TH2D("h2_MCeta_vs_Ppt",   "h2_MCeta_vs_Ppt",   100,-3,3,100,-500,15000);
  TH2D* h2_MCphi_vs_Ppt   = new TH2D("h2_MCphi_vs_Ppt",   "h2_MCphi_vs_Ppt",   100,-4,4,100,-500,15000);
  TH2D* h2_MCrho_vs_Ppt   = new TH2D("h2_MCrho_vs_Ppt",   "h2_MCrho_vs_Ppt",   100,2000,13000,100,-500,15000);
  TH2D* h2_MCtheta_vs_Ppt = new TH2D("h2_MCtheta_vs_Ppt", "h2_MCtheta_vs_Ppt", 100,0,3.5,100,-500,15000);
  TH2D* h2_Delta_R_vs_Ppt = new TH2D("h2_Delta_R_vs_Ppt", "h2_Delta_R_vs_Ppt", 100,-0.001,0.002,100,-500,15000);
  TH2D* h2_nhits_vs_Ppt   = new TH2D("h2_nhits_vs_Ppt",   "h2_nhits_vs_Ppt",   21,-0.5,20.5,100,-500,15000);

  TH1D* h_Delta_beta = new TH1D("h_Delta_beta",  "h_Delta_beta", 200,-1,1);

  TH1D* h_dE_dx = new TH1D("h_dE_dx",  "h_dE_dx", 100,-1e-5,2.e-4);

  TH2D* h2_MCBeta_vs_hitBeta   = new TH2D("h2_MCBeta_vs_hitBeta",   "h2_MCBeta_vs_hitBeta",   100,0,3,100,0,3);
  TH2D* h2_recoBeta_vs_hitBeta = new TH2D("h2_recoBeta_vs_hitBeta", "h2_recoBeta_vs_hitBeta", 100,-0,4,100,0,4);

  TH2D* h2_DeltaR_vs_hitBeta = new TH2D("h2_DeltaR_vs_hitBeta", "h2_DeltaR_vs_hitBeta", 100,-0.01,0.05,100,-2,2);

  TH1D* h_hit_energy        = new TH1D("h_hit_energy",        "h_hit_energy", 100,-0.0001,0.0003);
  TH1D* h_hit_time          = new TH1D("h_hit_time",          "h_hit_time", 100,-2,6);

  TH1D* h_theoretical_beta = new TH1D("h_theoretical_beta", "h_theoretical_beta", 100,-0.01,0.025);


  TH1D* h_Tpt_2 = new TH1D("h_Tpt_2", "h_Tpt_2", 100,-500,5000);
  TH1D* h_qOverP_2 = new TH1D("h_qOverP_2", "h_qOverP_2", 100,-0.05,0.05);

  // double wino_mass = 3000000+165; //MeV
  double wino_mass = 3000.000+0.000165; //GeV (better cause beta sim 1 comma ca)
  double speed_light = 299.792458; //mm/ns

  int reco_counter = 0;
  int extra_counter = 0;
  int layer1_c = 0;
  int layer2_c = 0;
  int layer3_c = 0;
  int layer4_c = 0;
  for(unsigned iev=0; iev<nevents; ++iev) {
    // cout << "Event number " << iev  << endl;
    // cout << endl << "Event number: " << iev << endl;

    const fcc::MCParticleCollection* MCparticles; // create a particle collections
    bool MCparticlePresents = store.get("GenParticles", MCparticles);

    const fcc::ParticleCollection* particles; // create a particle collections
    bool particlesPresent = store.get("TrackRecoParticles", particles);

    double b_deltaR            = 1e8;
    double b_eta               = -1e8;
    double b_theta             = -1e8;
    double b_phi               = -1e8;
    double b_pt                = -1e8;
    double b_betagammasintheta = -1e8;
    double b_rho               = -1e8;
    double b_E                 = -1e8;
    double b_px                = -1e8;
    double b_py                = -1e8;
    double b_pz                = -1e8;
    double b_Tpt               = -1e8;
    double b_T_Delta_theta     = -1e8;
    double b_T_Delta_eta       = -1e8;
    double b_T_Delta_q_pt      = -1e8;
    double b_T_Delta_phi       = -1e8;
    double b_radius            = -1e8;
    double b_last_z            = -1e8;
    double b_nhits             = -1e8;
    double b_beta              = -1e8;
    double b_Hbeta             = -1e8;
    double b_dE_dx             = -1e8;
    double last_energy =1e8;
    double b_theoretical_beta = -1e8;

    double pt_smeared = -1e8;

    // cout << "MC particles" << endl;
    TLorentzVector vMC;
    if(MCparticlePresents){
      for(const auto& MCparticle : *MCparticles){
        double local_px = MCparticle.core().p4.px;
        double local_py = MCparticle.core().p4.py;
        double local_pz = MCparticle.core().p4.pz;
        vMC.SetXYZM(local_px,local_py,local_pz,wino_mass);
        h_eta->Fill(vMC.Eta());
        h_phi->Fill(vMC.Phi());
        // h_pt->Fill(vMC.Pt());
        h_px               ->Fill(vMC.Px());
        h_py               ->Fill(vMC.Py());
        h_pz               ->Fill(vMC.Pz());
        h_betagammasintheta->Fill(vMC.Beta()*vMC.Gamma()*sin(vMC.Theta()));
        // cout << vMC.Beta()*vMC.Gamma()*sin(vMC.Theta()) << "    " << vMC.Beta() << "   " << vMC.Gamma()<< endl;
        h_E                ->Fill(vMC.E());
        // cout << "rho check: " << vMC.Rho() << "   " <<  sqrt(local_px*local_px+local_py*local_py+local_pz*local_pz) << endl;


        auto pt_true = 3000.; // pT = 3 TeV
        double qoverpt_resolution = 1e-2; // GeV^-1 = 1e-2
        auto qoverpt = 1 / pt_true; // GeV^-1
        qoverpt += gRandom->Gaus(0., qoverpt_resolution); // Add gaussian noise
        pt_smeared = fabs(1 / qoverpt); // GeV // float absolute value
      }
    }

    // cout << "Reco particles" << endl;
    int particle_counter = 0;
    double last_x=0, last_y=0, last_z=0,last_t=0;
    if (particlesPresent) {
      for(const auto& particle : *particles){
          particle_counter++;

          TLorentzVector v;
          // cout << "pdgId: " << particle.core().pdgId << endl;
          double local_px = particle.core().p4.px;
          double local_py = particle.core().p4.py;
          double local_pz = particle.core().p4.pz;
          double local_mass = wino_mass;
          v.SetXYZM(local_px,local_py,local_pz,local_mass);

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
          for(auto track = particle.tracks_begin(); track != particle.tracks_end(); ++track) {
            if(track->isAvailable()) {
              h_nhits  ->Fill(track->hits().size());
              h_chi2   ->Fill(track->chi2());
              if(b_deltaR > v.DeltaR(vMC)){
                for(auto hit = track->hits_begin(); hit !=track->hits_end(); ++hit){
                    last_x = hit->x();
                    last_y = hit->y();
                    last_z = hit->z();
                    last_t = hit->core().time;
                    b_dE_dx = hit->core().energy*sin(v.Theta());
                    last_energy = hit->core().energy;
                    double last_S = sqrt(last_x*last_x+last_y*last_y+last_z*last_z);

                    double delta_S = sqrt(1/last_S*last_S*((last_x*0.005)*(last_x*0.005)+(last_y*0.005)*(last_y*0.005)+(last_z*0.005)*(last_z*0.005)));
                    b_theoretical_beta = 1/(last_t*speed_light)*sqrt(delta_S*delta_S+(last_S/last_t*0.01)*(last_S/last_t*0.01));
                    // cout <<b_dE_dx<< endl;
                }
              }

              double radius = sqrt(last_x*last_x+last_y*last_y);
              // cout << "decay radius: " << radius << endl;
              for(auto state = track->states_begin(); state !=track->states_end(); ++state){
                 h_Tphi   ->Fill(state->phi());
                 h_Ttheta ->Fill(state->theta());
                 h_qOverP ->Fill(state->qOverP());
                 h_d0     ->Fill(state->d0());
                 h_z0     ->Fill(state->z0());
                 double theta_extra = state->theta();
                 if(theta_extra<0){theta_extra+=TMath::Pi();}
                 h2_MCtheta_vs_Ttheta->Fill(vMC.Theta(),theta_extra);
                 h2_MCphi_vs_Tphi->Fill(vMC.Phi(),state->phi());
                 double cosTheta = cos(state->theta());
                 double eta_extra;
                 if(cosTheta*cosTheta < 1){eta_extra = -0.5* TMath::Log((1.0-cosTheta)/(1.0+cosTheta));}
                 else{eta_extra = -10e10;}

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

                   b_Tpt = abs(1./state->qOverP());
                   b_T_Delta_eta = make_delta_angle(eta_extra,abs(vMC.Eta()));
                   b_T_Delta_phi = make_delta_angle(state->phi(),vMC.Phi());
                   b_T_Delta_theta = make_delta_angle(theta_extra,vMC.Theta());
                   b_T_Delta_q_pt = state->qOverP()-1./vMC.Pt();
                   b_radius = radius;
                   b_last_z = last_z;

                   b_nhits = track->hits().size();
                   b_beta = v.Beta();
                   b_Hbeta = sqrt(last_x*last_x+last_y*last_y+last_z*last_z)/last_t/speed_light;

                 } // closes best if
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
      // cout << b_E << endl; // 3.00017e+06 o default
      b_h_px               ->Fill(b_px);
      b_h_py               ->Fill(b_py);
      b_h_pz               ->Fill(b_pz);
      h_Tpt->Fill(b_Tpt);
      // cout << b_Tpt << endl;
      h_Delta_phi->Fill(b_T_Delta_phi);
      h_Delta_theta->Fill(b_T_Delta_theta);
      h_Delta_q_pt->Fill(b_T_Delta_q_pt);
      h_Delta_eta->Fill(b_T_Delta_eta);
      h_radius->Fill(b_radius);
      h2_z_vs_radius->Fill(b_last_z,b_radius);

      h2_MCeta_vs_Peta->Fill(vMC.Eta(),b_eta);
      h2_MCphi_vs_Pphi->Fill(vMC.Phi(),b_phi);
      h2_MCrho_vs_Prho->Fill(vMC.Rho(),b_rho);
      h2_MCtheta_vs_Ptheta->Fill(vMC.Theta(),b_theta);
      h2_MCpt_vs_Ppt->Fill(pt_smeared,b_pt);
      h2_MCeta_vs_Ppt  ->Fill(vMC.Eta(),b_pt);
      h2_MCphi_vs_Ppt  ->Fill(vMC.Phi(),b_pt);
      h2_MCrho_vs_Ppt  ->Fill(vMC.Rho(),b_pt);
      h2_MCtheta_vs_Ppt->Fill(vMC.Theta(),b_pt);
      h2_Delta_R_vs_Ppt->Fill(b_deltaR,b_pt);
      h2_nhits_vs_Ppt  ->Fill(b_nhits,b_pt);

      h_Delta_beta->Fill(vMC.Beta()-b_Hbeta);
      h_dE_dx->Fill(b_dE_dx);

      h2_DeltaR_vs_hitBeta->Fill(b_deltaR,b_Hbeta);

      h_theoretical_beta->Fill(b_theoretical_beta);

      if(last_t!=0&&b_beta!=-1e8){
          h2_MCBeta_vs_hitBeta  ->Fill(vMC.Beta(),b_Hbeta);
          h2_recoBeta_vs_hitBeta->Fill(b_beta,b_Hbeta);
          h_hit_time->Fill(last_t);
          h_hit_energy->Fill(last_energy);
      }
    } // end of particles present if
    h2_deltaR_vs_eta->Fill(vMC.Eta(),b_deltaR);
    h2_deltaR_vs_phi->Fill(vMC.Phi(),b_deltaR);
    h_particles_per_event->Fill(particle_counter);

    if(particle_counter>=1){
      reco_counter++;
      h_eta_e->Fill(vMC.Eta());
      h_phi_e->Fill(vMC.Phi());
      h_pt_e->Fill(vMC.Pt());
    }
    // if(vMC.Pt()==3000){
    //   cout << vMC.Pt() << endl;
    // }else{
    //   cout << "ciao" << endl;
    //   cout << vMC.Pt() << endl;
    // }

    // Read TrackerHitsPosition
    const fcc::PositionedTrackHitCollection* trackhits;
    bool trackhitsPresent = store.get("TrackerHitsPosition", trackhits);

    // cout << "Trackerhits" << endl;

    if (trackhitsPresent){
      int l1 = 0;
      int l2 = 0;
      int l3 = 0;
      int l4 = 0;
      for(const auto& hit : *trackhits){
        //// Hit test:
        double r = sqrt(hit.position().x*hit.position().x+hit.position().y*hit.position().y);
        if(r<35){l1++;}
        else if(r>50&&r<70){l2++;}
        else if(r>90&&r<110){l3++;}
        else if(r>140&&r<160){l4++;}
      }
      // int cut = 1;
      // if(l1>=cut&&l2>=cut&&l3>=cut&&l4>=cut){layer4_c++;cout << "4 events nr " << iev << endl;}
      // else if(l1>=cut&&l2>=cut&&l3>=cut){layer3_c++;cout << "3 events nr " << iev << endl;}
      // else if(l1>=cut&&l2>=cut){layer2_c++;cout << "2 events nr " << iev << endl;}
      // else if(l1>=cut){layer1_c++;cout << "1 events nr " << iev << endl;}
    }

    const fcc::MCParticleCollection* simpart;
    bool SimPresent = store.get("SimParticles", simpart);

    if(SimPresent){
      // cout << "size: " << simpart->size() << endl;
      for(const auto& sim: *simpart){
        // if(abs(sim.core().pdgId)!=1000022 && abs(sim.core().pdgId)!=1000024 && \
        // abs(sim.core().pdgId)!=11  && abs(sim.core().pdgId)!=14 && \
        // abs(sim.core().pdgId)!=13  && abs(sim.core().pdgId)!=2112 && \
        // abs(sim.core().pdgId)!=211 && abs(sim.core().pdgId)!=22 && \
        // abs(sim.core().pdgId)!=12 && abs(sim.core().pdgId)!=2212){cout << sim.core().pdgId << endl;}

        if(abs(sim.core().pdgId)==211){
          double rr = sqrt(sim.core().vertex.x*sim.core().vertex.x+sim.core().vertex.y*sim.core().vertex.y);
          // cout << rr <<"  " << sim.core().vertex.z << endl;
        }
        // cout << sim.startVertex().position().x << endl;
        // for(auto vert = sim->startVertex(); vert !=sim->endVertex(); ++vert){
        //     cout << vert.position().x << endl;
        // }
          // double r = sqrt(sim.startVertex().position().x*sim.startVertex().position().x+sim.startVertex().position().y*sim.startVertex().position().y);
          // cout << sim.startVertex().position().x() << endl;
      }
    }


    // fChain->SetBranchAddress("ParticleGun_Pt", &ParticleGun_Pt, &b_ParticleGun_Pt);
    // fChain->SetBranchAddress("ParticleGun_Eta", &ParticleGun_Eta, &b_ParticleGun_Eta);
    // fChain->SetBranchAddress("ParticleGun_costheta", &ParticleGun_costheta, &b_ParticleGun_costheta);
    // fChain->SetBranchAddress("ParticleGun_Phi", &ParticleGun_Phi, &b_ParticleGun_Phi);


    ////// Tracks:
    const fcc::TrackStateCollection* states;
    bool statesPresent = store.get("TrackStates", states);

    double b_qOverP_track = 1e8;
    double b_Tpt_track = 1e8;
    double ncounter = 0;
    if(statesPresent){
      for(const auto& state: *states){
        ncounter++;
           double extra = state.qOverP() - 1./vMC.Pt();

           if(b_qOverP_track > extra){
             b_qOverP_track = extra;
             b_Tpt_track = abs(1./state.qOverP());
           }
        }
    }
    // h_ntracks->Fill(ncounter);
    // if(ncounter!=0 && ncounter!=1){cout << ncounter<< endl;}
    h_Tpt_2->Fill(b_Tpt_track);
    h_qOverP_2->Fill(b_qOverP_track);



    store.clear();
    reader.endOfEvent();
    // if(iev==100){break;}
  } // end of loop over events

  auto pt_true = 3000.; // pT = 3 TeV
  double qoverpt_resolution = 1e-2; // GeV^-1 = 1e-2
  for(int i=0;i<10000;i++){
      auto qoverpt = 1 / pt_true; // GeV^-1
      qoverpt += gRandom->Gaus(0., qoverpt_resolution); // Add gaussian noise
      auto pt_smeared = fabs(1 / qoverpt); // GeV // float absolute value
      h_pt->Fill(pt_smeared);
  }


  double events = nevents;
  cout << endl << "Layers hitten (1,2,3,4):" << layer1_c << ", "<< layer2_c << ", "<< layer3_c << ", "<< layer4_c << endl;
  cout << "reco counter: " << reco_counter << endl;
  cout << "extra counter: " << extra_counter << endl;
  cout << "events: " << events << endl;
  cout << "particle efficiency: " << reco_counter/events << endl;

  ///// Histogram salvation:
  h_eta_e->Divide(h_eta);
  h_phi_e->Divide(h_phi);
  // h_pt_e->Divide(h_pt);

  cout << "Write to .root" << endl;
  string sss = outputname+".root";
  auto f1 = TFile::Open(sss.c_str(), "RECREATE");
  h_eta                ->Write();
  h_phi                ->Write();
  h_pt                 ->Write();
  h_eta_e              ->Write();
  h_phi_e              ->Write();
  h_pt_e               ->Write();
  h2_MCeta_vs_Peta     ->Write();
  h2_MCphi_vs_Pphi     ->Write();
  h2_MCrho_vs_Prho     ->Write();
  h2_MCtheta_vs_Ptheta ->Write();
  h2_MCtheta_vs_Ttheta ->Write();
  h2_MCphi_vs_Tphi     ->Write();
  h_particles_per_event->Write();
  h2_deltaR_vs_eta     ->Write();
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
  h_Delta_phi          ->Write();
  h_Delta_theta        ->Write();
  h_Delta_q_pt         ->Write();
  h_Delta_eta          ->Write();
  h_Tpt                ->Write();
  h_radius             ->Write();
  h2_z_vs_radius       ->Write();
  h_px                 ->Write();
  h_py                 ->Write();
  h_pz                 ->Write();
  h_betagammasintheta  ->Write();
  h_E                  ->Write();
  h2_MCeta_vs_Ppt  ->Write();
  h2_MCphi_vs_Ppt  ->Write();
  h2_MCrho_vs_Ppt  ->Write();
  h2_MCtheta_vs_Ppt->Write();
  h2_Delta_R_vs_Ppt->Write();
  h2_nhits_vs_Ppt  ->Write();
  h_Delta_beta->Write();
  h_dE_dx->Write();
  h2_MCBeta_vs_hitBeta  ->Write();
  h2_recoBeta_vs_hitBeta->Write();
  h2_DeltaR_vs_hitBeta->Write();
  h_hit_time  ->Write();
  h_hit_energy->Write();
  h_theoretical_beta->Write();
  h_Tpt_2   ->Write();
  h_qOverP_2->Write();
  h2_MCpt_vs_Ppt->Write();
  f1->Close();

  cout << "test" << endl;
  rootname = outputname+"_Delta_q_pt.root";
  auto f2 = TFile::Open(rootname.c_str(), "RECREATE");
  h_Delta_q_pt->Write();
  f2->Close();

  rootname = outputname+"_Delta_beta.root";
  auto f3 = TFile::Open(rootname.c_str(), "RECREATE");
  h_Delta_beta->Write();
  f3->Close();

  cout <<"Delete" << endl;
  delete h_eta                ;
  delete h_phi                ;
  delete h_pt                 ;
  delete h_eta_e              ;
  delete h_phi_e              ;
  delete h_pt_e               ;
  delete h2_MCeta_vs_Peta     ;
  delete h2_MCphi_vs_Pphi     ;
  delete h2_MCrho_vs_Prho     ;
  delete h2_MCtheta_vs_Ptheta ;
  delete h2_MCtheta_vs_Ttheta ;
  delete h2_MCphi_vs_Tphi     ;
  delete h_particles_per_event;
  delete h2_deltaR_vs_eta     ;
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
  delete h_Delta_q_pt         ;
  delete h_Delta_phi          ;
  delete h_Delta_theta        ;
  delete h_Delta_eta          ;
  delete h_radius;
  delete h_Tpt;
  delete h2_z_vs_radius;
  delete h_px                 ;
  delete h_py                 ;
  delete h_pz                 ;
  delete h_betagammasintheta  ;
  delete h_E                  ;
  delete h2_MCeta_vs_Ppt  ;
  delete h2_MCphi_vs_Ppt  ;
  delete h2_MCrho_vs_Ppt  ;
  delete h2_MCtheta_vs_Ppt;
  delete h2_Delta_R_vs_Ppt;
  delete h2_nhits_vs_Ppt  ;
  delete h_Delta_beta;
  delete h_dE_dx;
  delete h2_MCBeta_vs_hitBeta  ;
  delete h2_recoBeta_vs_hitBeta;
  delete h2_DeltaR_vs_hitBeta;
  delete h_hit_time  ;
  delete h_hit_energy;
  delete h_theoretical_beta;
  delete h_Tpt_2   ;
  delete h_qOverP_2;
  delete h2_MCpt_vs_Ppt;

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
