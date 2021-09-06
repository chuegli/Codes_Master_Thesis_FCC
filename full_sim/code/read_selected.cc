#include <TChain.h>
#include <iostream>

using namespace std;

//// Merge created selected_?.root files to 1 .root file
//// Location: /afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/code/
//// Run by simply root -b -q read_selected.cc

void read_selected(){
  TChain * myChain = new TChain("t");
  cout << "Branches:" << endl;
  Double_t eta, pt, z0, d0, phi, theta, qOverP, beta_10, beta_50, nhits;
  myChain->SetBranchAddress("eta"    ,&eta    );
  myChain->SetBranchAddress("pt"     ,&pt     );
  myChain->SetBranchAddress("z0"     ,&z0     );
  myChain->SetBranchAddress("d0"     ,&d0     );
  myChain->SetBranchAddress("phi"    ,&phi    );
  myChain->SetBranchAddress("theta"  ,&theta  );
  myChain->SetBranchAddress("qOverP" ,&qOverP );
  myChain->SetBranchAddress("beta_10",&beta_10);
  myChain->SetBranchAddress("beta_50",&beta_50);
  myChain->SetBranchAddress("nhits"  ,&nhits  );
  cout << "Add:" << endl;
  // myChain->Add("/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_[1-9].root");
  // myChain->Add("/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_[1-9][1-9].root");
  // myChain->Add("/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_1[1-9][1-9].root");
  // myChain->Add("/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_2[1-9][1-9].root");
  // myChain->Add("/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_3[1-9][1-9].root");
  // myChain->Add("/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_4[1-9][1-9].root");
  myChain->Add("/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_5x5_[1-9].root");
  myChain->Add("/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_5x5_[1-9][0-9].root"); // 990
  myChain->Add("/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_5x5_1[0-9][0-9].root"); //1990
  myChain->Add("/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_5x5_2[0-9][0-9].root");
  myChain->Add("/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_5x5_3[0-9][0-9].root"); // 3990
  myChain->Add("/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_5x5_4[0-9][0-9].root");
  myChain->Add("/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_5x5_5[0-9][0-9].root"); // 5990
  myChain->Add("/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_5x5_6[0-9][0-9].root");
  myChain->Add("/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_5x5_7[0-9][0-9].root"); //7990
  myChain->Add("/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_5x5_8[0-9][0-9].root");
  myChain->Add("/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_5x5_9[0-9][0-9].root"); //9990
  cout << "Entries:" << endl;
  cout << myChain->GetEntries() << endl;
  cout << "Save:" << endl;
  // myChain->Merge("/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_tree.root");
  myChain->Merge("/afs/cern.ch/work/c/chugli/private/FCCSW_pileup_1/root_files/selected_tree_5x5.root");
  cout << "hello" << endl;
}
