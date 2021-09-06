// Data model
#include "datamodel/TrackCollection.h"
#include "datamodel/ParticleCollection.h"
#include "datamodel/TrackStateCollection.h"
#include "datamodel/MCParticleCollection.h"
#include "datamodel/PositionedTrackHitCollection.h"
#include "datamodel/GenVertexCollection.h"

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
  auto store = podio::EventStore();
  reader.openFile(rootname.c_str());
  store.setReader(&reader);
  unsigned nevents= reader.getEntries();

  //////
  // e1: there is at least 1 reconstructed particle
  // e2: delta R cut at 0.001
  // e3: delta R cut at 0.0001

  TH1D* h_vertex_r_e1 = new TH1D("h_vertex_r_e1", "h_vertex_r_e1", 100,-0.02,0.2);
  TH1D* h_vertex_r_e2 = new TH1D("h_vertex_r_e2", "h_vertex_r_e2", 100,-0.02,0.2);
  TH1D* h_vertex_r_e3 = new TH1D("h_vertex_r_e3", "h_vertex_r_e3", 100,-0.02,0.2);
  TH1D* h_vertex_r    = new TH1D("h_vertex_r",    "h_vertex_r",    100,-0.02,0.2);

  TH1D* h_vertex_z_e1 = new TH1D("h_vertex_z_e1", "h_vertex_z_e1", 100,-1,1);
  TH1D* h_vertex_z_e2 = new TH1D("h_vertex_z_e2", "h_vertex_z_e2", 100,-1,1);
  TH1D* h_vertex_z_e3 = new TH1D("h_vertex_z_e3", "h_vertex_z_e3", 100,-1,1);
  TH1D* h_vertex_z    = new TH1D("h_vertex_z",    "h_vertex_z",    100,-1,1);

  double wino_mass = 3000.000+0.000165; //GeV (better cause beta sim 1 comma ca)

  for(unsigned iev=0; iev<nevents; ++iev) {

    const fcc::MCParticleCollection* MCparticles; // create a particle collections
    bool MCparticlePresents = store.get("GenParticles", MCparticles);

    const fcc::ParticleCollection* particles; // create a particle collections
    bool particlesPresent = store.get("TrackRecoParticles", particles);

    double b_deltaR            = 10000;

    TLorentzVector vMC;
    if(MCparticlePresents){
      for(const auto& MCparticle : *MCparticles){
        double local_px = MCparticle.core().p4.px;
        double local_py = MCparticle.core().p4.py;
        double local_pz = MCparticle.core().p4.pz;
        double local_mass = wino_mass;
        vMC.SetXYZM(local_px,local_py,local_pz,local_mass);
      }
    }

    int particle_counter = 0;
    if (particlesPresent) {
      for(const auto& particle : *particles){
          particle_counter++;

          TLorentzVector v;
          double local_px = particle.core().p4.px;
          double local_py = particle.core().p4.py;
          double local_pz = particle.core().p4.pz;
          double local_mass = wino_mass;
          v.SetXYZM(local_px,local_py,local_pz,local_mass);

          if(b_deltaR > v.DeltaR(vMC)){
            b_deltaR            = v.DeltaR(vMC);
          }
      }
    } // end of particles present if


    /////// Vertex r,z:
    const fcc::GenVertexCollection* vertices;
    bool verticesPresent = store.get("GenVertices", vertices);

    if (verticesPresent){
      for(const auto& vertex : *vertices){
        double r = sqrt(vertex.position().x*vertex.position().x+vertex.position().y*vertex.position().y);
        h_vertex_r->Fill(r);
        h_vertex_z->Fill(vertex.position().z);
        // cout << r << "   " << vertex.position().z << endl; => is all = 0 :(
        if(particle_counter>=1){
          h_vertex_r_e1->Fill(r);
          h_vertex_z_e1->Fill(vertex.position().z);
        }
        if(b_deltaR<0.001){
          h_vertex_r_e2->Fill(r);
          h_vertex_z_e2->Fill(vertex.position().z);
        }
        if(b_deltaR<0.0001){
          h_vertex_r_e3->Fill(r);
          h_vertex_z_e3->Fill(vertex.position().z);
        }
      }
    }


    store.clear();
    reader.endOfEvent();
  } // end of loop over events
  double events = nevents;

  ///// Histogram salvation:
  h_vertex_r_e1->Divide(h_vertex_r);
  h_vertex_r_e2->Divide(h_vertex_r);
  h_vertex_r_e3->Divide(h_vertex_r);
  h_vertex_z_e1->Divide(h_vertex_z);
  h_vertex_z_e2->Divide(h_vertex_z);
  h_vertex_z_e3->Divide(h_vertex_z);


  cout << "Write to .root" << endl;
  auto f1 = TFile::Open(outputname.c_str(), "RECREATE");
  h_vertex_r_e1->Write();
  h_vertex_r_e2->Write();
  h_vertex_r_e3->Write();
  h_vertex_z_e1->Write();
  h_vertex_z_e2->Write();
  h_vertex_z_e3->Write();
  f1->Close();

  cout <<"Delete" << endl;
  delete h_vertex_r_e1;
  delete h_vertex_r_e2;
  delete h_vertex_r_e3;
  delete h_vertex_z_e1;
  delete h_vertex_z_e2;
  delete h_vertex_z_e3;


 cout << "***************** Finished *********************" << endl;
}
