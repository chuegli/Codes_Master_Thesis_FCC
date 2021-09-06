#include <TFile.h>
#include <TTree.h>
#include <TTreeReader.h>
#include <TTreeReaderArray.h>
#include <TLorentzVector.h>
#include <TVector2.h>
#include <TH1D.h>
#include <TLegend.h>
#include <TPaveStats.h>
#include <TChain.h>
#include <TString.h>
#include <TPaveLabel.h>
#include <TMultiGraph.h>
#include <TGraph.h>
#include <TColor.h>
#include <TSystemDirectory.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TPad.h>
#include <TH2D.h>
#include <TGraph2D.h>

#include <math.h>
#include <typeinfo>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
///////////// What this .cc does:
// !!! Important !!!
// if not already done you need to run first signal_kin.cc and BG_kin.cc
//
// This .cc concerns both signals and BGs samples.
//
// 1) It first extracts the histograms for the predicted number of BG events and
// predicted number of signal events
// 2) It calculates a histogram with the significance (sig = signal/sqrt(BG))
// 3) It plots everything in plots_kin.pdf
//
// 2D plots of significance, signal and BG are produced

// root -q -b plots_kin_sel.cc+
////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// "/afs/cern.ch/user/c/chugli/private/txt/arrays_1.txt" = vecchio con histo fill only in loop events
// "/afs/cern.ch/user/c/chugli/private/txt/arrays_2.txt" = new correct one with histo fill in loop events, loop gen particles, if wino fill
///////////////////////////////////////////////////////////////////////////////

void histo_styling(TH1D* h, int j);
void make_arrays_wino();

void plots_kin_sel(){
  make_arrays_wino();
  cout << "************************ Finished !!!! :))))) **********************" << endl;
}

void make_arrays_wino(){
  ////////// Definition part:
  cout << "********************* Start BG part *********************" << endl;

  string BGtype[5] = {"W+jets","Z+jets","ttbar","topsingle","multijets"};

  int mylength[5] = {7,7,10,1,9};
  int mycolor[5] = {68,65,8,9,94};

  string a[] = {"0_150", "150_300", "300_500", "500_1000", "1000_2000", "2000_5000", "5000_100000"};
  string c[] = {"0_600", "600_1200", "1200_2100", "2100_3400", "3400_5300", "5300_8100", "8100_15000",
  "15000_25000", "25000_35000", "35000_100000"};
  string d[] = {""};
  string e[] = {"0_500", "500_1000", "1000_2000", "2000_4000", "4000_7200", "7200_15000",
  "15000_25000", "25000_35000", "35000_100000"};
  string *myfolders[5] = {a,a,c,d,e};

  map<TString, TH2D*> map_s2D;
  map<int, map<TString, TH2D*>> h_map_2D;

  map<TString, TH1D*> map_s1D;
  map<int, map<TString, TH1D*>> h_map_1D;

  for(int i=0; i<5;i++){
      const char* BGchar = BGtype[i].c_str();
      cout << "********************* Start BG " << BGtype[i] << "  " << i << " *********************" << endl;

      map_s1D["h_eta"       ] = new TH1D("h_eta",       "; Leading jet #eta [ ];        Entries", 100, -6, 6);
      map_s1D["h_phi"       ] = new TH1D("h_phi",       "; Leading jet #phi [ ];        Entries", 100, -4, 4);
      map_s1D["h_theta"     ] = new TH1D("h_theta",     "; Leading jet #theta [ ];      Entries", 100, -1, 4);
      map_s1D["h_beta"      ] = new TH1D("h_beta",      "; Leading jet #beta [ ];       Entries", 100, 0.8, 1.1);
      map_s1D["h_gamma"     ] = new TH1D("h_gamma",     "; Leading jet #gamma [ ];      Entries", 100, 0, 5000);
      map_s1D["h_betagamma" ] = new TH1D("h_betagamma", "; Leading jet #beta#gamma [ ]; Entries", 100, 0, 5000);
      map_s1D["h_met"       ] = new TH1D("h_met",       "; met p_T [GeV];               Entries", 100, 0, 5000);
      map_s1D["h_met_phi"   ] = new TH1D("h_met_phi",   "; met #phi [ ];                Entries", 100, -4, 4);
      map_s1D["h_delta_phi" ] = new TH1D("h_delta_phi", "; #Delta #phi [ ];             Entries", 100, -1, 4);
      map_s1D["h_delta_pt"  ] = new TH1D("h_delta_pt",  "; #Delta p_T [GeV];            Entries", 100, 0, 7000);

      map_s1D["c1h_eta"      ]   = new TH1D("c1h_eta",       "; Leading jet #eta [ ];        Cut MET entries", 100, -4, 4);
      map_s1D["c1h_phi"      ]   = new TH1D("c1h_phi",       "; Leading jet #phi [ ];        Cut MET entries", 100, -4, 4);
      map_s1D["c1h_theta"    ]   = new TH1D("c1h_theta",     "; Leading jet #theta [ ];      Cut MET entries", 100, -1, 4);
      map_s1D["c1h_beta"     ]   = new TH1D("c1h_beta",      "; Leading jet #beta [ ];       Cut MET entries", 100, 0.9, 1.1);
      map_s1D["c1h_gamma"    ]   = new TH1D("c1h_gamma",     "; Leading jet #gamma [ ];      Cut MET entries", 100, 0, 800);
      map_s1D["c1h_betagamma"]   = new TH1D("c1h_betagamma", "; Leading jet #beta#gamma [ ]; Cut MET entries", 100, 0, 800);
      map_s1D["c1h_met"      ]   = new TH1D("c1h_met",       "; met p_T [GeV];               Cut MET entries", 100, 3000, 10000);
      map_s1D["c1h_met_phi"  ]   = new TH1D("c1h_met_phi",   "; met #phi [ ];                Cut MET entries", 100, -4, 4);
      map_s1D["c1h_delta_phi"]   = new TH1D("c1h_delta_phi", "; #Delta #phi [ ];             Cut MET entries", 100, -1, 4);
      map_s1D["c1h_delta_pt" ]   = new TH1D("c1h_delta_pt",  "; #Delta p_T [GeV];            Cut MET entries", 100, 0, 10000);

      map_s1D["c2h_eta"      ]   = new TH1D("c2h_eta",       "; Leading jet #eta [ ];        Cut LJet entries", 100, -4, 4);
      map_s1D["c2h_phi"      ]   = new TH1D("c2h_phi",       "; Leading jet #phi [ ];        Cut LJet entries", 100, -4, 4);
      map_s1D["c2h_theta"    ]   = new TH1D("c2h_theta",     "; Leading jet #theta [ ];      Cut LJet entries", 100, -1, 4);
      map_s1D["c2h_beta"     ]   = new TH1D("c2h_beta",      "; Leading jet #beta [ ];       Cut LJet entries", 100, 0.9, 1.1);
      map_s1D["c2h_gamma"    ]   = new TH1D("c2h_gamma",     "; Leading jet #gamma [ ];      Cut LJet entries", 100, 0, 1500);
      map_s1D["c2h_betagamma"]   = new TH1D("c2h_betagamma", "; Leading jet #beta#gamma [ ]; Cut LJet entries", 100, 0, 1500);
      map_s1D["c2h_met"      ]   = new TH1D("c2h_met",       "; met p_T [GeV];               Cut LJet entries", 100, 0, 10000);
      map_s1D["c2h_met_phi"  ]   = new TH1D("c2h_met_phi",   "; met #phi [ ];                Cut LJet entries", 100, -4, 4);
      map_s1D["c2h_delta_phi"]   = new TH1D("c2h_delta_phi", "; #Delta #phi [ ];             Cut LJet entries", 100, -1, 4);
      map_s1D["c2h_delta_pt" ]   = new TH1D("c2h_delta_pt",  "; #Delta p_T [GeV];            Cut LJet entries", 100, 0, 10000);

      map_s2D["Jh_eta"      ]  = new TH2D("Jh_eta",       "; Leading jet #eta [ ];        Leading jet p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
      map_s2D["Jh_phi"      ]  = new TH2D("Jh_phi",       "; Leading jet #phi [ ];        Leading jet p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
      map_s2D["Jh_theta"    ]  = new TH2D("Jh_theta",     "; Leading jet #theta [ ];      Leading jet p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
      map_s2D["Jh_beta"     ]  = new TH2D("Jh_beta",      "; Leading jet #beta [ ];       Leading jet p_T [GeV]; Entries", 100, -1.2, 1.2,  100,0,5000);
      map_s2D["Jh_gamma"    ]  = new TH2D("Jh_gamma",     "; Leading jet #gamma [ ];      Leading jet p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);
      map_s2D["Jh_betagamma"]  = new TH2D("Jh_betagamma", "; Leading jet #beta#gamma [ ]; Leading jet p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);
      map_s2D["Jh_met"      ]  = new TH2D("Jh_met",       "; met p_T [GeV];               Leading jet p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);
      map_s2D["Jh_met_phi"  ]  = new TH2D("Jh_met_phi",   "; met #phi [ ];                Leading jet p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
      map_s2D["Jh_delta_phi"]  = new TH2D("Jh_delta_phi", "; #Delta #phi [ ];             Leading jet p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
      map_s2D["Jh_delta_pt" ]  = new TH2D("Jh_delta_pt",  "; #Delta p_T [GeV];            Leading jet p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);
      map_s2D["Mh_eta"      ]  = new TH2D("Mh_eta",       "; Leading jet #eta [ ];        MET p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
      map_s2D["Mh_phi"      ]  = new TH2D("Mh_phi",       "; Leading jet #phi [ ];        MET p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
      map_s2D["Mh_theta"    ]  = new TH2D("Mh_theta",     "; Leading jet #theta [ ];      MET p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
      map_s2D["Mh_beta"     ]  = new TH2D("Mh_beta",      "; Leading jet #beta [ ];       MET p_T [GeV]; Entries", 100, -1.2, 1.2,  100,0,5000);
      map_s2D["Mh_gamma"    ]  = new TH2D("Mh_gamma",     "; Leading jet #gamma [ ];      MET p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);
      map_s2D["Mh_betagamma"]  = new TH2D("Mh_betagamma", "; Leading jet #beta#gamma [ ]; MET p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);
      map_s2D["Mh_met"      ]  = new TH2D("Mh_met",       "; met p_T [GeV];               MET p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);
      map_s2D["Mh_met_phi"  ]  = new TH2D("Mh_met_phi",   "; met #phi [ ];                MET p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
      map_s2D["Mh_delta_phi"]  = new TH2D("Mh_delta_phi", "; #Delta #phi [ ];             MET p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
      map_s2D["Mh_delta_pt" ]  = new TH2D("Mh_delta_pt",  "; #Delta p_T [GeV];            MET p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);


      for(int j=0; j<mylength[i]; j++){
          string filename = "/afs/cern.ch/work/c/chugli/private/fast_sim/histo_kin_sel_" +BGtype[i]+"_"+myfolders[i][j]+".root";
          const char* dirname = filename.c_str();
          TFile *f = new TFile(dirname);

          TH1D* c_h_eta        = (TH1D*)f->Get("h_eta"      );
          TH1D* c_h_phi        = (TH1D*)f->Get("h_phi"      );
          TH1D* c_h_theta      = (TH1D*)f->Get("h_theta"    );
          TH1D* c_h_beta       = (TH1D*)f->Get("h_beta"     );
          TH1D* c_h_gamma      = (TH1D*)f->Get("h_gamma"    );
          TH1D* c_h_betagamma  = (TH1D*)f->Get("h_betagamma");
          TH1D* c_h_met        = (TH1D*)f->Get("h_met"      );
          TH1D* c_h_met_phi    = (TH1D*)f->Get("h_met_phi"  );
          TH1D* c_h_delta_phi  = (TH1D*)f->Get("h_delta_phi");
          TH1D* c_h_delta_pt   = (TH1D*)f->Get("h_delta_pt" );
          TH1D* c_c1h_eta        = (TH1D*)f->Get("c1h_eta"      );
          TH1D* c_c1h_phi        = (TH1D*)f->Get("c1h_phi"      );
          TH1D* c_c1h_theta      = (TH1D*)f->Get("c1h_theta"    );
          TH1D* c_c1h_beta       = (TH1D*)f->Get("c1h_beta"     );
          TH1D* c_c1h_gamma      = (TH1D*)f->Get("c1h_gamma"    );
          TH1D* c_c1h_betagamma  = (TH1D*)f->Get("c1h_betagamma");
          TH1D* c_c1h_met        = (TH1D*)f->Get("c1h_met"      );
          TH1D* c_c1h_met_phi    = (TH1D*)f->Get("c1h_met_phi"  );
          TH1D* c_c1h_delta_phi  = (TH1D*)f->Get("c1h_delta_phi");
          TH1D* c_c1h_delta_pt   = (TH1D*)f->Get("c1h_delta_pt" );
          TH1D* c_c2h_eta       = (TH1D*)f->Get("c2h_eta"      );
          TH1D* c_c2h_phi       = (TH1D*)f->Get("c2h_phi"      );
          TH1D* c_c2h_theta     = (TH1D*)f->Get("c2h_theta"    );
          TH1D* c_c2h_beta      = (TH1D*)f->Get("c2h_beta"     );
          TH1D* c_c2h_gamma     = (TH1D*)f->Get("c2h_gamma"    );
          TH1D* c_c2h_betagamma = (TH1D*)f->Get("c2h_betagamma");
          TH1D* c_c2h_met       = (TH1D*)f->Get("c2h_met"      );
          TH1D* c_c2h_met_phi   = (TH1D*)f->Get("c2h_met_phi"  );
          TH1D* c_c2h_delta_phi = (TH1D*)f->Get("c2h_delta_phi");
          TH1D* c_c2h_delta_pt  = (TH1D*)f->Get("c2h_delta_pt" );
          TH2D* c_Jh_eta       = (TH2D*)f->Get("Jh_eta"      );
          TH2D* c_Jh_phi       = (TH2D*)f->Get("Jh_phi"      );
          TH2D* c_Jh_theta     = (TH2D*)f->Get("Jh_theta"    );
          TH2D* c_Jh_beta      = (TH2D*)f->Get("Jh_beta"     );
          TH2D* c_Jh_gamma     = (TH2D*)f->Get("Jh_gamma"    );
          TH2D* c_Jh_betagamma = (TH2D*)f->Get("Jh_betagamma");
          TH2D* c_Jh_met       = (TH2D*)f->Get("Jh_met"      );
          TH2D* c_Jh_met_phi   = (TH2D*)f->Get("Jh_met_phi"  );
          TH2D* c_Jh_delta_phi = (TH2D*)f->Get("Jh_delta_phi");
          TH2D* c_Jh_delta_pt  = (TH2D*)f->Get("Jh_delta_pt" );
          TH2D* c_Mh_eta         = (TH2D*)f->Get("Mh_eta"      );
          TH2D* c_Mh_phi         = (TH2D*)f->Get("Mh_phi"      );
          TH2D* c_Mh_theta       = (TH2D*)f->Get("Mh_theta"    );
          TH2D* c_Mh_beta        = (TH2D*)f->Get("Mh_beta"     );
          TH2D* c_Mh_gamma       = (TH2D*)f->Get("Mh_gamma"    );
          TH2D* c_Mh_betagamma   = (TH2D*)f->Get("Mh_betagamma");
          TH2D* c_Mh_met         = (TH2D*)f->Get("Mh_met"      );
          TH2D* c_Mh_met_phi     = (TH2D*)f->Get("Mh_met_phi"  );
          TH2D* c_Mh_delta_phi   = (TH2D*)f->Get("Mh_delta_phi");
          TH2D* c_Mh_delta_pt    = (TH2D*)f->Get("Mh_delta_pt" );

          histo_styling(map_s1D["h_eta"        ],mycolor[i]);
          histo_styling(map_s1D["h_phi"        ],mycolor[i]);
          histo_styling(map_s1D["h_theta"      ],mycolor[i]);
          histo_styling(map_s1D["h_beta"       ],mycolor[i]);
          histo_styling(map_s1D["h_gamma"      ],mycolor[i]);
          histo_styling(map_s1D["h_betagamma"  ],mycolor[i]);
          histo_styling(map_s1D["h_met"        ],mycolor[i]);
          histo_styling(map_s1D["h_met_phi"    ],mycolor[i]);
          histo_styling(map_s1D["h_delta_phi"  ],mycolor[i]);
          histo_styling(map_s1D["h_delta_pt"   ],mycolor[i]);
          histo_styling(map_s1D["c1h_eta"      ],mycolor[i]);
          histo_styling(map_s1D["c1h_phi"      ],mycolor[i]);
          histo_styling(map_s1D["c1h_theta"    ],mycolor[i]);
          histo_styling(map_s1D["c1h_beta"     ],mycolor[i]);
          histo_styling(map_s1D["c1h_gamma"    ],mycolor[i]);
          histo_styling(map_s1D["c1h_betagamma"],mycolor[i]);
          histo_styling(map_s1D["c1h_met"      ],mycolor[i]);
          histo_styling(map_s1D["c1h_met_phi"  ],mycolor[i]);
          histo_styling(map_s1D["c1h_delta_phi"],mycolor[i]);
          histo_styling(map_s1D["c1h_delta_pt" ],mycolor[i]);
          histo_styling(map_s1D["c2h_eta"      ],mycolor[i]);
          histo_styling(map_s1D["c2h_phi"      ],mycolor[i]);
          histo_styling(map_s1D["c2h_theta"    ],mycolor[i]);
          histo_styling(map_s1D["c2h_beta"     ],mycolor[i]);
          histo_styling(map_s1D["c2h_gamma"    ],mycolor[i]);
          histo_styling(map_s1D["c2h_betagamma"],mycolor[i]);
          histo_styling(map_s1D["c2h_met"      ],mycolor[i]);
          histo_styling(map_s1D["c2h_met_phi"  ],mycolor[i]);
          histo_styling(map_s1D["c2h_delta_phi"],mycolor[i]);
          histo_styling(map_s1D["c2h_delta_pt" ],mycolor[i]);

          map_s1D["h_eta"        ]  ->Add(c_h_eta      );
          map_s1D["h_phi"        ]  ->Add(c_h_phi      );
          map_s1D["h_theta"      ]  ->Add(c_h_theta    );
          map_s1D["h_beta"       ]  ->Add(c_h_beta     );
          map_s1D["h_gamma"      ]  ->Add(c_h_gamma    );
          map_s1D["h_betagamma"  ]  ->Add(c_h_betagamma);
          map_s1D["h_met"        ]  ->Add(c_h_met      );
          map_s1D["h_met_phi"    ]  ->Add(c_h_met_phi  );
          map_s1D["h_delta_phi"  ]  ->Add(c_h_delta_phi);
          map_s1D["h_delta_pt"   ]  ->Add(c_h_delta_pt );
          map_s1D["c1h_eta"      ]  ->Add(c_c1h_eta      );
          map_s1D["c1h_phi"      ]  ->Add(c_c1h_phi      );
          map_s1D["c1h_theta"    ]  ->Add(c_c1h_theta    );
          map_s1D["c1h_beta"     ]  ->Add(c_c1h_beta     );
          map_s1D["c1h_gamma"    ]  ->Add(c_c1h_gamma    );
          map_s1D["c1h_betagamma"]  ->Add(c_c1h_betagamma);
          map_s1D["c1h_met"      ]  ->Add(c_c1h_met      );
          map_s1D["c1h_met_phi"  ]  ->Add(c_c1h_met_phi  );
          map_s1D["c1h_delta_phi"]  ->Add(c_c1h_delta_phi);
          map_s1D["c1h_delta_pt" ]  ->Add(c_c1h_delta_pt );
          map_s1D["c2h_eta"      ]  ->Add(c_c2h_eta      );
          map_s1D["c2h_phi"      ]  ->Add(c_c2h_phi      );
          map_s1D["c2h_theta"    ]  ->Add(c_c2h_theta    );
          map_s1D["c2h_beta"     ]  ->Add(c_c2h_beta     );
          map_s1D["c2h_gamma"    ]  ->Add(c_c2h_gamma    );
          map_s1D["c2h_betagamma"]  ->Add(c_c2h_betagamma);
          map_s1D["c2h_met"      ]  ->Add(c_c2h_met      );
          map_s1D["c2h_met_phi"  ]  ->Add(c_c2h_met_phi  );
          map_s1D["c2h_delta_phi"]  ->Add(c_c2h_delta_phi);
          map_s1D["c2h_delta_pt" ]  ->Add(c_c2h_delta_pt );
          map_s2D["Jh_eta"      ]  ->Add(c_Jh_eta      );
          map_s2D["Jh_phi"      ]  ->Add(c_Jh_phi      );
          map_s2D["Jh_theta"    ]  ->Add(c_Jh_theta    );
          map_s2D["Jh_beta"     ]  ->Add(c_Jh_beta     );
          map_s2D["Jh_gamma"    ]  ->Add(c_Jh_gamma    );
          map_s2D["Jh_betagamma"]  ->Add(c_Jh_betagamma);
          map_s2D["Jh_met"      ]  ->Add(c_Jh_met      );
          map_s2D["Jh_met_phi"  ]  ->Add(c_Jh_met_phi  );
          map_s2D["Jh_delta_phi"]  ->Add(c_Jh_delta_phi);
          map_s2D["Jh_delta_pt" ]  ->Add(c_Jh_delta_pt );
          map_s2D["Mh_eta"      ]  ->Add(c_Mh_eta      );
          map_s2D["Mh_phi"      ]  ->Add(c_Mh_phi      );
          map_s2D["Mh_theta"    ]  ->Add(c_Mh_theta    );
          map_s2D["Mh_beta"     ]  ->Add(c_Mh_beta     );
          map_s2D["Mh_gamma"    ]  ->Add(c_Mh_gamma    );
          map_s2D["Mh_betagamma"]  ->Add(c_Mh_betagamma);
          map_s2D["Mh_met"      ]  ->Add(c_Mh_met      );
          map_s2D["Mh_met_phi"  ]  ->Add(c_Mh_met_phi  );
          map_s2D["Mh_delta_phi"]  ->Add(c_Mh_delta_phi);
          map_s2D["Mh_delta_pt" ]  ->Add(c_Mh_delta_pt );
      } // end of j
      h_map_1D[i] = map_s1D;
      h_map_2D[i] = map_s2D;
  } //end of i


  /////////////////////////////////////////////////////////////////////////////
  /////////////////// Signal part:
  cout << "********************* Start signal part *********************" << endl;
  string f_type1  = "C1N1";
  string f_type2  = "C1C1";
  string f_middle[2] = {"1000","3000"};
  int mycolor_s[2] = {2,6};
  int index = 5;

  for(int i = 0; i < 2; i++){
      string ftype;
      ///// C1C1:
      ftype=f_type1;
      cout << "signal type, mass, index: " << ftype << ", " << f_middle[i] << ", " << index << endl;
      string filename = "/afs/cern.ch/work/c/chugli/private/fast_sim/histo_kin_sel_" +ftype+"_"+f_middle[i]+".root";
      const char* dirname = filename.c_str();
      TFile *f = new TFile(dirname);

      map_s1D["h_eta"       ] = new TH1D("h_eta",       "; Leading jet #eta [ ];        Entries", 100, -6, 6);
      map_s1D["h_phi"       ] = new TH1D("h_phi",       "; Leading jet #phi [ ];        Entries", 100, -4, 4);
      map_s1D["h_theta"     ] = new TH1D("h_theta",     "; Leading jet #theta [ ];      Entries", 100, -1, 4);
      map_s1D["h_beta"      ] = new TH1D("h_beta",      "; Leading jet #beta [ ];       Entries", 100, 0.8, 1.1);
      map_s1D["h_gamma"     ] = new TH1D("h_gamma",     "; Leading jet #gamma [ ];      Entries", 100, 0, 5000);
      map_s1D["h_betagamma" ] = new TH1D("h_betagamma", "; Leading jet #beta#gamma [ ]; Entries", 100, 0, 5000);
      map_s1D["h_met"       ] = new TH1D("h_met",       "; met p_T [GeV];               Entries", 100, 0, 5000);
      map_s1D["h_met_phi"   ] = new TH1D("h_met_phi",   "; met #phi [ ];                Entries", 100, -4, 4);
      map_s1D["h_delta_phi" ] = new TH1D("h_delta_phi", "; #Delta #phi [ ];             Entries", 100, -1, 4);
      map_s1D["h_delta_pt"  ] = new TH1D("h_delta_pt",  "; #Delta p_T [GeV];            Entries", 100, 0, 7000);

      map_s1D["c1h_eta"      ]   = new TH1D("c1h_eta",       "; Leading jet #eta [ ];        Cut MET entries", 100, -4, 4);
      map_s1D["c1h_phi"      ]   = new TH1D("c1h_phi",       "; Leading jet #phi [ ];        Cut MET entries", 100, -4, 4);
      map_s1D["c1h_theta"    ]   = new TH1D("c1h_theta",     "; Leading jet #theta [ ];      Cut MET entries", 100, -1, 4);
      map_s1D["c1h_beta"     ]   = new TH1D("c1h_beta",      "; Leading jet #beta [ ];       Cut MET entries", 100, 0.9, 1.1);
      map_s1D["c1h_gamma"    ]   = new TH1D("c1h_gamma",     "; Leading jet #gamma [ ];      Cut MET entries", 100, 0, 800);
      map_s1D["c1h_betagamma"]   = new TH1D("c1h_betagamma", "; Leading jet #beta#gamma [ ]; Cut MET entries", 100, 0, 800);
      map_s1D["c1h_met"      ]   = new TH1D("c1h_met",       "; met p_T [GeV];               Cut MET entries", 100, 3000, 10000);
      map_s1D["c1h_met_phi"  ]   = new TH1D("c1h_met_phi",   "; met #phi [ ];                Cut MET entries", 100, -4, 4);
      map_s1D["c1h_delta_phi"]   = new TH1D("c1h_delta_phi", "; #Delta #phi [ ];             Cut MET entries", 100, -1, 4);
      map_s1D["c1h_delta_pt" ]   = new TH1D("c1h_delta_pt",  "; #Delta p_T [GeV];            Cut MET entries", 100, 0, 10000);

      map_s1D["c2h_eta"      ]   = new TH1D("c2h_eta",       "; Leading jet #eta [ ];        Cut LJet entries", 100, -4, 4);
      map_s1D["c2h_phi"      ]   = new TH1D("c2h_phi",       "; Leading jet #phi [ ];        Cut LJet entries", 100, -4, 4);
      map_s1D["c2h_theta"    ]   = new TH1D("c2h_theta",     "; Leading jet #theta [ ];      Cut LJet entries", 100, -1, 4);
      map_s1D["c2h_beta"     ]   = new TH1D("c2h_beta",      "; Leading jet #beta [ ];       Cut LJet entries", 100, 0.9, 1.1);
      map_s1D["c2h_gamma"    ]   = new TH1D("c2h_gamma",     "; Leading jet #gamma [ ];      Cut LJet entries", 100, 0, 1500);
      map_s1D["c2h_betagamma"]   = new TH1D("c2h_betagamma", "; Leading jet #beta#gamma [ ]; Cut LJet entries", 100, 0, 1500);
      map_s1D["c2h_met"      ]   = new TH1D("c2h_met",       "; met p_T [GeV];               Cut LJet entries", 100, 0, 10000);
      map_s1D["c2h_met_phi"  ]   = new TH1D("c2h_met_phi",   "; met #phi [ ];                Cut LJet entries", 100, -4, 4);
      map_s1D["c2h_delta_phi"]   = new TH1D("c2h_delta_phi", "; #Delta #phi [ ];             Cut LJet entries", 100, -1, 4);
      map_s1D["c2h_delta_pt" ]   = new TH1D("c2h_delta_pt",  "; #Delta p_T [GeV];            Cut LJet entries", 100, 0, 10000);

      map_s2D["Jh_eta"      ]  = new TH2D("Jh_eta",       "; Leading jet #eta [ ];        Leading jet p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
      map_s2D["Jh_phi"      ]  = new TH2D("Jh_phi",       "; Leading jet #phi [ ];        Leading jet p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
      map_s2D["Jh_theta"    ]  = new TH2D("Jh_theta",     "; Leading jet #theta [ ];      Leading jet p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
      map_s2D["Jh_beta"     ]  = new TH2D("Jh_beta",      "; Leading jet #beta [ ];       Leading jet p_T [GeV]; Entries", 100, -1.2, 1.2,  100,0,5000);
      map_s2D["Jh_gamma"    ]  = new TH2D("Jh_gamma",     "; Leading jet #gamma [ ];      Leading jet p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);
      map_s2D["Jh_betagamma"]  = new TH2D("Jh_betagamma", "; Leading jet #beta#gamma [ ]; Leading jet p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);
      map_s2D["Jh_met"      ]  = new TH2D("Jh_met",       "; met p_T [GeV];               Leading jet p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);
      map_s2D["Jh_met_phi"  ]  = new TH2D("Jh_met_phi",   "; met #phi [ ];                Leading jet p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
      map_s2D["Jh_delta_phi"]  = new TH2D("Jh_delta_phi", "; #Delta #phi [ ];             Leading jet p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
      map_s2D["Jh_delta_pt" ]  = new TH2D("Jh_delta_pt",  "; #Delta p_T [GeV];            Leading jet p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);
      map_s2D["Mh_eta"      ]  = new TH2D("Mh_eta",       "; Leading jet #eta [ ];        MET p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
      map_s2D["Mh_phi"      ]  = new TH2D("Mh_phi",       "; Leading jet #phi [ ];        MET p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
      map_s2D["Mh_theta"    ]  = new TH2D("Mh_theta",     "; Leading jet #theta [ ];      MET p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
      map_s2D["Mh_beta"     ]  = new TH2D("Mh_beta",      "; Leading jet #beta [ ];       MET p_T [GeV]; Entries", 100, -1.2, 1.2,  100,0,5000);
      map_s2D["Mh_gamma"    ]  = new TH2D("Mh_gamma",     "; Leading jet #gamma [ ];      MET p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);
      map_s2D["Mh_betagamma"]  = new TH2D("Mh_betagamma", "; Leading jet #beta#gamma [ ]; MET p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);
      map_s2D["Mh_met"      ]  = new TH2D("Mh_met",       "; met p_T [GeV];               MET p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);
      map_s2D["Mh_met_phi"  ]  = new TH2D("Mh_met_phi",   "; met #phi [ ];                MET p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
      map_s2D["Mh_delta_phi"]  = new TH2D("Mh_delta_phi", "; #Delta #phi [ ];             MET p_T [GeV]; Entries", 100, -4, 4,      100,0,5000);
      map_s2D["Mh_delta_pt" ]  = new TH2D("Mh_delta_pt",  "; #Delta p_T [GeV];            MET p_T [GeV]; Entries", 100, 0, 5000,    100,0,5000);


      TH1D* c_h_eta        = (TH1D*)f->Get("h_eta"      );
      TH1D* c_h_phi        = (TH1D*)f->Get("h_phi"      );
      TH1D* c_h_theta      = (TH1D*)f->Get("h_theta"    );
      TH1D* c_h_beta       = (TH1D*)f->Get("h_beta"     );
      TH1D* c_h_gamma      = (TH1D*)f->Get("h_gamma"    );
      TH1D* c_h_betagamma  = (TH1D*)f->Get("h_betagamma");
      TH1D* c_h_met        = (TH1D*)f->Get("h_met"      );
      TH1D* c_h_met_phi    = (TH1D*)f->Get("h_met_phi"  );
      TH1D* c_h_delta_phi  = (TH1D*)f->Get("h_delta_phi");
      TH1D* c_h_delta_pt   = (TH1D*)f->Get("h_delta_pt" );
      TH1D* c_c1h_eta        = (TH1D*)f->Get("c1h_eta"      );
      TH1D* c_c1h_phi        = (TH1D*)f->Get("c1h_phi"      );
      TH1D* c_c1h_theta      = (TH1D*)f->Get("c1h_theta"    );
      TH1D* c_c1h_beta       = (TH1D*)f->Get("c1h_beta"     );
      TH1D* c_c1h_gamma      = (TH1D*)f->Get("c1h_gamma"    );
      TH1D* c_c1h_betagamma  = (TH1D*)f->Get("c1h_betagamma");
      TH1D* c_c1h_met        = (TH1D*)f->Get("c1h_met"      );
      TH1D* c_c1h_met_phi    = (TH1D*)f->Get("c1h_met_phi"  );
      TH1D* c_c1h_delta_phi  = (TH1D*)f->Get("c1h_delta_phi");
      TH1D* c_c1h_delta_pt   = (TH1D*)f->Get("c1h_delta_pt" );
      TH1D* c_c2h_eta       = (TH1D*)f->Get("c2h_eta"      );
      TH1D* c_c2h_phi       = (TH1D*)f->Get("c2h_phi"      );
      TH1D* c_c2h_theta     = (TH1D*)f->Get("c2h_theta"    );
      TH1D* c_c2h_beta      = (TH1D*)f->Get("c2h_beta"     );
      TH1D* c_c2h_gamma     = (TH1D*)f->Get("c2h_gamma"    );
      TH1D* c_c2h_betagamma = (TH1D*)f->Get("c2h_betagamma");
      TH1D* c_c2h_met       = (TH1D*)f->Get("c2h_met"      );
      TH1D* c_c2h_met_phi   = (TH1D*)f->Get("c2h_met_phi"  );
      TH1D* c_c2h_delta_phi = (TH1D*)f->Get("c2h_delta_phi");
      TH1D* c_c2h_delta_pt  = (TH1D*)f->Get("c2h_delta_pt" );
      TH2D* c_Jh_eta       = (TH2D*)f->Get("Jh_eta"      );
      TH2D* c_Jh_phi       = (TH2D*)f->Get("Jh_phi"      );
      TH2D* c_Jh_theta     = (TH2D*)f->Get("Jh_theta"    );
      TH2D* c_Jh_beta      = (TH2D*)f->Get("Jh_beta"     );
      TH2D* c_Jh_gamma     = (TH2D*)f->Get("Jh_gamma"    );
      TH2D* c_Jh_betagamma = (TH2D*)f->Get("Jh_betagamma");
      TH2D* c_Jh_met       = (TH2D*)f->Get("Jh_met"      );
      TH2D* c_Jh_met_phi   = (TH2D*)f->Get("Jh_met_phi"  );
      TH2D* c_Jh_delta_phi = (TH2D*)f->Get("Jh_delta_phi");
      TH2D* c_Jh_delta_pt  = (TH2D*)f->Get("Jh_delta_pt" );
      TH2D* c_Mh_eta         = (TH2D*)f->Get("Mh_eta"      );
      TH2D* c_Mh_phi         = (TH2D*)f->Get("Mh_phi"      );
      TH2D* c_Mh_theta       = (TH2D*)f->Get("Mh_theta"    );
      TH2D* c_Mh_beta        = (TH2D*)f->Get("Mh_beta"     );
      TH2D* c_Mh_gamma       = (TH2D*)f->Get("Mh_gamma"    );
      TH2D* c_Mh_betagamma   = (TH2D*)f->Get("Mh_betagamma");
      TH2D* c_Mh_met         = (TH2D*)f->Get("Mh_met"      );
      TH2D* c_Mh_met_phi     = (TH2D*)f->Get("Mh_met_phi"  );
      TH2D* c_Mh_delta_phi   = (TH2D*)f->Get("Mh_delta_phi");
      TH2D* c_Mh_delta_pt    = (TH2D*)f->Get("Mh_delta_pt" );

      histo_styling(map_s1D["h_eta"        ],mycolor_s[i]);
      histo_styling(map_s1D["h_phi"        ],mycolor_s[i]);
      histo_styling(map_s1D["h_theta"      ],mycolor_s[i]);
      histo_styling(map_s1D["h_beta"       ],mycolor_s[i]);
      histo_styling(map_s1D["h_gamma"      ],mycolor_s[i]);
      histo_styling(map_s1D["h_betagamma"  ],mycolor_s[i]);
      histo_styling(map_s1D["h_met"        ],mycolor_s[i]);
      histo_styling(map_s1D["h_met_phi"    ],mycolor_s[i]);
      histo_styling(map_s1D["h_delta_phi"  ],mycolor_s[i]);
      histo_styling(map_s1D["h_delta_pt"   ],mycolor_s[i]);
      histo_styling(map_s1D["c1h_eta"      ],mycolor_s[i]);
      histo_styling(map_s1D["c1h_phi"      ],mycolor_s[i]);
      histo_styling(map_s1D["c1h_theta"    ],mycolor_s[i]);
      histo_styling(map_s1D["c1h_beta"     ],mycolor_s[i]);
      histo_styling(map_s1D["c1h_gamma"    ],mycolor_s[i]);
      histo_styling(map_s1D["c1h_betagamma"],mycolor_s[i]);
      histo_styling(map_s1D["c1h_met"      ],mycolor_s[i]);
      histo_styling(map_s1D["c1h_met_phi"  ],mycolor_s[i]);
      histo_styling(map_s1D["c1h_delta_phi"],mycolor_s[i]);
      histo_styling(map_s1D["c1h_delta_pt" ],mycolor_s[i]);
      histo_styling(map_s1D["c2h_eta"      ],mycolor_s[i]);
      histo_styling(map_s1D["c2h_phi"      ],mycolor_s[i]);
      histo_styling(map_s1D["c2h_theta"    ],mycolor_s[i]);
      histo_styling(map_s1D["c2h_beta"     ],mycolor_s[i]);
      histo_styling(map_s1D["c2h_gamma"    ],mycolor_s[i]);
      histo_styling(map_s1D["c2h_betagamma"],mycolor_s[i]);
      histo_styling(map_s1D["c2h_met"      ],mycolor_s[i]);
      histo_styling(map_s1D["c2h_met_phi"  ],mycolor_s[i]);
      histo_styling(map_s1D["c2h_delta_phi"],mycolor_s[i]);
      histo_styling(map_s1D["c2h_delta_pt" ],mycolor_s[i]);

      map_s1D["h_eta"        ]  ->Add(c_h_eta      );
      map_s1D["h_phi"        ]  ->Add(c_h_phi      );
      map_s1D["h_theta"      ]  ->Add(c_h_theta    );
      map_s1D["h_beta"       ]  ->Add(c_h_beta     );
      map_s1D["h_gamma"      ]  ->Add(c_h_gamma    );
      map_s1D["h_betagamma"  ]  ->Add(c_h_betagamma);
      map_s1D["h_met"        ]  ->Add(c_h_met      );
      map_s1D["h_met_phi"    ]  ->Add(c_h_met_phi  );
      map_s1D["h_delta_phi"  ]  ->Add(c_h_delta_phi);
      map_s1D["h_delta_pt"   ]  ->Add(c_h_delta_pt );
      map_s1D["c1h_eta"      ]  ->Add(c_c1h_eta      );
      map_s1D["c1h_phi"      ]  ->Add(c_c1h_phi      );
      map_s1D["c1h_theta"    ]  ->Add(c_c1h_theta    );
      map_s1D["c1h_beta"     ]  ->Add(c_c1h_beta     );
      map_s1D["c1h_gamma"    ]  ->Add(c_c1h_gamma    );
      map_s1D["c1h_betagamma"]  ->Add(c_c1h_betagamma);
      map_s1D["c1h_met"      ]  ->Add(c_c1h_met      );
      map_s1D["c1h_met_phi"  ]  ->Add(c_c1h_met_phi  );
      map_s1D["c1h_delta_phi"]  ->Add(c_c1h_delta_phi);
      map_s1D["c1h_delta_pt" ]  ->Add(c_c1h_delta_pt );
      map_s1D["c2h_eta"      ]  ->Add(c_c2h_eta      );
      map_s1D["c2h_phi"      ]  ->Add(c_c2h_phi      );
      map_s1D["c2h_theta"    ]  ->Add(c_c2h_theta    );
      map_s1D["c2h_beta"     ]  ->Add(c_c2h_beta     );
      map_s1D["c2h_gamma"    ]  ->Add(c_c2h_gamma    );
      map_s1D["c2h_betagamma"]  ->Add(c_c2h_betagamma);
      map_s1D["c2h_met"      ]  ->Add(c_c2h_met      );
      map_s1D["c2h_met_phi"  ]  ->Add(c_c2h_met_phi  );
      map_s1D["c2h_delta_phi"]  ->Add(c_c2h_delta_phi);
      map_s1D["c2h_delta_pt" ]  ->Add(c_c2h_delta_pt );
      map_s2D["Jh_eta"      ]  ->Add(c_Jh_eta      );
      map_s2D["Jh_phi"      ]  ->Add(c_Jh_phi      );
      map_s2D["Jh_theta"    ]  ->Add(c_Jh_theta    );
      map_s2D["Jh_beta"     ]  ->Add(c_Jh_beta     );
      map_s2D["Jh_gamma"    ]  ->Add(c_Jh_gamma    );
      map_s2D["Jh_betagamma"]  ->Add(c_Jh_betagamma);
      map_s2D["Jh_met"      ]  ->Add(c_Jh_met      );
      map_s2D["Jh_met_phi"  ]  ->Add(c_Jh_met_phi  );
      map_s2D["Jh_delta_phi"]  ->Add(c_Jh_delta_phi);
      map_s2D["Jh_delta_pt" ]  ->Add(c_Jh_delta_pt );
      map_s2D["Mh_eta"      ]  ->Add(c_Mh_eta      );
      map_s2D["Mh_phi"      ]  ->Add(c_Mh_phi      );
      map_s2D["Mh_theta"    ]  ->Add(c_Mh_theta    );
      map_s2D["Mh_beta"     ]  ->Add(c_Mh_beta     );
      map_s2D["Mh_gamma"    ]  ->Add(c_Mh_gamma    );
      map_s2D["Mh_betagamma"]  ->Add(c_Mh_betagamma);
      map_s2D["Mh_met"      ]  ->Add(c_Mh_met      );
      map_s2D["Mh_met_phi"  ]  ->Add(c_Mh_met_phi  );
      map_s2D["Mh_delta_phi"]  ->Add(c_Mh_delta_phi);
      map_s2D["Mh_delta_pt" ]  ->Add(c_Mh_delta_pt );

      ///// C1C1:
      ftype=f_type2;
      cout << "signal type, mass, index: " << ftype << ", " << f_middle[i] << ", " << index << endl;
      filename = "/afs/cern.ch/work/c/chugli/private/fast_sim/histo_kin_sel_" +ftype+"_"+f_middle[i]+".root";
      dirname = filename.c_str();
      TFile *f2 = new TFile(dirname);

      TH1D* c2_h_eta        = (TH1D*)f2->Get("h_eta"      );
      TH1D* c2_h_phi        = (TH1D*)f2->Get("h_phi"      );
      TH1D* c2_h_theta      = (TH1D*)f2->Get("h_theta"    );
      TH1D* c2_h_beta       = (TH1D*)f2->Get("h_beta"     );
      TH1D* c2_h_gamma      = (TH1D*)f2->Get("h_gamma"    );
      TH1D* c2_h_betagamma  = (TH1D*)f2->Get("h_betagamma");
      TH1D* c2_h_met        = (TH1D*)f2->Get("h_met"      );
      TH1D* c2_h_met_phi    = (TH1D*)f2->Get("h_met_phi"  );
      TH1D* c2_h_delta_phi  = (TH1D*)f2->Get("h_delta_phi");
      TH1D* c2_h_delta_pt   = (TH1D*)f2->Get("h_delta_pt" );
      TH1D* c2_c1h_eta        = (TH1D*)f2->Get("c1h_eta"      );
      TH1D* c2_c1h_phi        = (TH1D*)f2->Get("c1h_phi"      );
      TH1D* c2_c1h_theta      = (TH1D*)f2->Get("c1h_theta"    );
      TH1D* c2_c1h_beta       = (TH1D*)f2->Get("c1h_beta"     );
      TH1D* c2_c1h_gamma      = (TH1D*)f2->Get("c1h_gamma"    );
      TH1D* c2_c1h_betagamma  = (TH1D*)f2->Get("c1h_betagamma");
      TH1D* c2_c1h_met        = (TH1D*)f2->Get("c1h_met"      );
      TH1D* c2_c1h_met_phi    = (TH1D*)f2->Get("c1h_met_phi"  );
      TH1D* c2_c1h_delta_phi  = (TH1D*)f2->Get("c1h_delta_phi");
      TH1D* c2_c1h_delta_pt   = (TH1D*)f2->Get("c1h_delta_pt" );
      TH1D* c2_c2h_eta       = (TH1D*)f2->Get("c2h_eta"      );
      TH1D* c2_c2h_phi       = (TH1D*)f2->Get("c2h_phi"      );
      TH1D* c2_c2h_theta     = (TH1D*)f2->Get("c2h_theta"    );
      TH1D* c2_c2h_beta      = (TH1D*)f2->Get("c2h_beta"     );
      TH1D* c2_c2h_gamma     = (TH1D*)f2->Get("c2h_gamma"    );
      TH1D* c2_c2h_betagamma = (TH1D*)f2->Get("c2h_betagamma");
      TH1D* c2_c2h_met       = (TH1D*)f2->Get("c2h_met"      );
      TH1D* c2_c2h_met_phi   = (TH1D*)f2->Get("c2h_met_phi"  );
      TH1D* c2_c2h_delta_phi = (TH1D*)f2->Get("c2h_delta_phi");
      TH1D* c2_c2h_delta_pt  = (TH1D*)f2->Get("c2h_delta_pt" );
      TH2D* c2_Jh_eta       = (TH2D*)f2->Get("Jh_eta"      );
      TH2D* c2_Jh_phi       = (TH2D*)f2->Get("Jh_phi"      );
      TH2D* c2_Jh_theta     = (TH2D*)f2->Get("Jh_theta"    );
      TH2D* c2_Jh_beta      = (TH2D*)f2->Get("Jh_beta"     );
      TH2D* c2_Jh_gamma     = (TH2D*)f2->Get("Jh_gamma"    );
      TH2D* c2_Jh_betagamma = (TH2D*)f2->Get("Jh_betagamma");
      TH2D* c2_Jh_met       = (TH2D*)f2->Get("Jh_met"      );
      TH2D* c2_Jh_met_phi   = (TH2D*)f2->Get("Jh_met_phi"  );
      TH2D* c2_Jh_delta_phi = (TH2D*)f2->Get("Jh_delta_phi");
      TH2D* c2_Jh_delta_pt  = (TH2D*)f2->Get("Jh_delta_pt" );
      TH2D* c2_Mh_eta         = (TH2D*)f2->Get("Mh_eta"      );
      TH2D* c2_Mh_phi         = (TH2D*)f2->Get("Mh_phi"      );
      TH2D* c2_Mh_theta       = (TH2D*)f2->Get("Mh_theta"    );
      TH2D* c2_Mh_beta        = (TH2D*)f2->Get("Mh_beta"     );
      TH2D* c2_Mh_gamma       = (TH2D*)f2->Get("Mh_gamma"    );
      TH2D* c2_Mh_betagamma   = (TH2D*)f2->Get("Mh_betagamma");
      TH2D* c2_Mh_met         = (TH2D*)f2->Get("Mh_met"      );
      TH2D* c2_Mh_met_phi     = (TH2D*)f2->Get("Mh_met_phi"  );
      TH2D* c2_Mh_delta_phi   = (TH2D*)f2->Get("Mh_delta_phi");
      TH2D* c2_Mh_delta_pt    = (TH2D*)f2->Get("Mh_delta_pt" );

      histo_styling(map_s1D["h_eta"        ],mycolor_s[i]);
      histo_styling(map_s1D["h_phi"        ],mycolor_s[i]);
      histo_styling(map_s1D["h_theta"      ],mycolor_s[i]);
      histo_styling(map_s1D["h_beta"       ],mycolor_s[i]);
      histo_styling(map_s1D["h_gamma"      ],mycolor_s[i]);
      histo_styling(map_s1D["h_betagamma"  ],mycolor_s[i]);
      histo_styling(map_s1D["h_met"        ],mycolor_s[i]);
      histo_styling(map_s1D["h_met_phi"    ],mycolor_s[i]);
      histo_styling(map_s1D["h_delta_phi"  ],mycolor_s[i]);
      histo_styling(map_s1D["h_delta_pt"   ],mycolor_s[i]);
      histo_styling(map_s1D["c1h_eta"      ],mycolor_s[i]);
      histo_styling(map_s1D["c1h_phi"      ],mycolor_s[i]);
      histo_styling(map_s1D["c1h_theta"    ],mycolor_s[i]);
      histo_styling(map_s1D["c1h_beta"     ],mycolor_s[i]);
      histo_styling(map_s1D["c1h_gamma"    ],mycolor_s[i]);
      histo_styling(map_s1D["c1h_betagamma"],mycolor_s[i]);
      histo_styling(map_s1D["c1h_met"      ],mycolor_s[i]);
      histo_styling(map_s1D["c1h_met_phi"  ],mycolor_s[i]);
      histo_styling(map_s1D["c1h_delta_phi"],mycolor_s[i]);
      histo_styling(map_s1D["c1h_delta_pt" ],mycolor_s[i]);
      histo_styling(map_s1D["c2h_eta"      ],mycolor_s[i]);
      histo_styling(map_s1D["c2h_phi"      ],mycolor_s[i]);
      histo_styling(map_s1D["c2h_theta"    ],mycolor_s[i]);
      histo_styling(map_s1D["c2h_beta"     ],mycolor_s[i]);
      histo_styling(map_s1D["c2h_gamma"    ],mycolor_s[i]);
      histo_styling(map_s1D["c2h_betagamma"],mycolor_s[i]);
      histo_styling(map_s1D["c2h_met"      ],mycolor_s[i]);
      histo_styling(map_s1D["c2h_met_phi"  ],mycolor_s[i]);
      histo_styling(map_s1D["c2h_delta_phi"],mycolor_s[i]);
      histo_styling(map_s1D["c2h_delta_pt" ],mycolor_s[i]);

      map_s1D["h_eta"        ]  ->Add(c2_h_eta      );
      map_s1D["h_phi"        ]  ->Add(c2_h_phi      );
      map_s1D["h_theta"      ]  ->Add(c2_h_theta    );
      map_s1D["h_beta"       ]  ->Add(c2_h_beta     );
      map_s1D["h_gamma"      ]  ->Add(c2_h_gamma    );
      map_s1D["h_betagamma"  ]  ->Add(c2_h_betagamma);
      map_s1D["h_met"        ]  ->Add(c2_h_met      );
      map_s1D["h_met_phi"    ]  ->Add(c2_h_met_phi  );
      map_s1D["h_delta_phi"  ]  ->Add(c2_h_delta_phi);
      map_s1D["h_delta_pt"   ]  ->Add(c2_h_delta_pt );
      map_s1D["c1h_eta"      ]  ->Add(c2_c1h_eta      );
      map_s1D["c1h_phi"      ]  ->Add(c2_c1h_phi      );
      map_s1D["c1h_theta"    ]  ->Add(c2_c1h_theta    );
      map_s1D["c1h_beta"     ]  ->Add(c2_c1h_beta     );
      map_s1D["c1h_gamma"    ]  ->Add(c2_c1h_gamma    );
      map_s1D["c1h_betagamma"]  ->Add(c2_c1h_betagamma);
      map_s1D["c1h_met"      ]  ->Add(c2_c1h_met      );
      map_s1D["c1h_met_phi"  ]  ->Add(c2_c1h_met_phi  );
      map_s1D["c1h_delta_phi"]  ->Add(c2_c1h_delta_phi);
      map_s1D["c1h_delta_pt" ]  ->Add(c2_c1h_delta_pt );
      map_s1D["c2h_eta"      ]  ->Add(c2_c2h_eta      );
      map_s1D["c2h_phi"      ]  ->Add(c2_c2h_phi      );
      map_s1D["c2h_theta"    ]  ->Add(c2_c2h_theta    );
      map_s1D["c2h_beta"     ]  ->Add(c2_c2h_beta     );
      map_s1D["c2h_gamma"    ]  ->Add(c2_c2h_gamma    );
      map_s1D["c2h_betagamma"]  ->Add(c2_c2h_betagamma);
      map_s1D["c2h_met"      ]  ->Add(c2_c2h_met      );
      map_s1D["c2h_met_phi"  ]  ->Add(c2_c2h_met_phi  );
      map_s1D["c2h_delta_phi"]  ->Add(c2_c2h_delta_phi);
      map_s1D["c2h_delta_pt" ]  ->Add(c2_c2h_delta_pt );
      map_s2D["Jh_eta"      ]  ->Add(c2_Jh_eta      );
      map_s2D["Jh_phi"      ]  ->Add(c2_Jh_phi      );
      map_s2D["Jh_theta"    ]  ->Add(c2_Jh_theta    );
      map_s2D["Jh_beta"     ]  ->Add(c2_Jh_beta     );
      map_s2D["Jh_gamma"    ]  ->Add(c2_Jh_gamma    );
      map_s2D["Jh_betagamma"]  ->Add(c2_Jh_betagamma);
      map_s2D["Jh_met"      ]  ->Add(c2_Jh_met      );
      map_s2D["Jh_met_phi"  ]  ->Add(c2_Jh_met_phi  );
      map_s2D["Jh_delta_phi"]  ->Add(c2_Jh_delta_phi);
      map_s2D["Jh_delta_pt" ]  ->Add(c2_Jh_delta_pt );
      map_s2D["Mh_eta"      ]  ->Add(c2_Mh_eta      );
      map_s2D["Mh_phi"      ]  ->Add(c2_Mh_phi      );
      map_s2D["Mh_theta"    ]  ->Add(c2_Mh_theta    );
      map_s2D["Mh_beta"     ]  ->Add(c2_Mh_beta     );
      map_s2D["Mh_gamma"    ]  ->Add(c2_Mh_gamma    );
      map_s2D["Mh_betagamma"]  ->Add(c2_Mh_betagamma);
      map_s2D["Mh_met"      ]  ->Add(c2_Mh_met      );
      map_s2D["Mh_met_phi"  ]  ->Add(c2_Mh_met_phi  );
      map_s2D["Mh_delta_phi"]  ->Add(c2_Mh_delta_phi);
      map_s2D["Mh_delta_pt" ]  ->Add(c2_Mh_delta_pt );

      h_map_1D[index] = map_s1D;
      h_map_2D[index] = map_s2D;
      index++;
  } // end of i

  ////////// Plotting part:
  cout << "********************* Start plotting *********************" << endl;
  TCanvas *canvas = new TCanvas("c","");
  canvas->SetGrid();
  canvas->SetLogy();
  gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
  gStyle->SetOptStat(0);

  string ss1 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/dyn/plot_selection_1D.pdf[";
  string ss2 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/dyn/plot_selection_1D.pdf";
  string ss3 = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/dyn/plot_selection_1D.pdf]";

  string ss1_2D = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/dyn/plot_selection_2D.pdf[";
  string ss2_2D = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/dyn/plot_selection_2D.pdf";
  string ss3_2D = "/afs/cern.ch/user/c/chugli/private/fast_sim/plots/dyn/plot_selection_2D.pdf]";

  h_map_1D[4]["h_eta"]->Draw("h");
  h_map_1D[4]["h_eta"]->SetMinimum(1);
  h_map_1D[1]["h_eta"]->Draw("same h");
  h_map_1D[2]["h_eta"]->Draw("same h");
  h_map_1D[3]["h_eta"]->Draw("same h");
  h_map_1D[0]["h_eta"]->Draw("same h");
  h_map_1D[5]["h_eta"]->Draw("same h");
  h_map_1D[6]["h_eta"]->Draw("same h");
  auto legend = new TLegend(0.75,0.65,0.95,0.95); // x1,y1,x2,y2
  legend->AddEntry(h_map_1D[0]["h_eta"],"W+jets","lep");
  legend->AddEntry(h_map_1D[1]["h_eta"],"Z+jets","lep");
  legend->AddEntry(h_map_1D[2]["h_eta"],"ttbar","lep");
  legend->AddEntry(h_map_1D[3]["h_eta"],"topsingle","lep");
  legend->AddEntry(h_map_1D[4]["h_eta"],"multijets","lep");
  legend->AddEntry(h_map_1D[5]["h_eta"],"Higgsino","lep");
  legend->AddEntry(h_map_1D[6]["h_eta"],"Wino","lep");
  legend->Draw();
  canvas->SaveAs(ss1.c_str());
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  h_map_1D[4]["h_phi"]->Draw("h");
  h_map_1D[4]["h_phi"]->SetMinimum(1);
  h_map_1D[1]["h_phi"]->Draw("same h");
  h_map_1D[2]["h_phi"]->Draw("same h");
  h_map_1D[3]["h_phi"]->Draw("same h");
  h_map_1D[0]["h_phi"]->Draw("same h");
  h_map_1D[5]["h_phi"]->Draw("same h");
  h_map_1D[6]["h_phi"]->Draw("same h");
  legend->Clear();
  legend->AddEntry(h_map_1D[0]["h_phi"],"W+jets","lep");
  legend->AddEntry(h_map_1D[1]["h_phi"],"Z+jets","lep");
  legend->AddEntry(h_map_1D[2]["h_phi"],"ttbar","lep");
  legend->AddEntry(h_map_1D[3]["h_phi"],"topsingle","lep");
  legend->AddEntry(h_map_1D[4]["h_phi"],"multijets","lep");
  legend->AddEntry(h_map_1D[5]["h_phi"],"Higgsino","lep");
  legend->AddEntry(h_map_1D[6]["h_phi"],"Wino","lep");
  legend->Draw();
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  h_map_1D[4]["h_theta"]->Draw("h");
  h_map_1D[4]["h_theta"]->SetMinimum(1);
  h_map_1D[1]["h_theta"]->Draw("same h");
  h_map_1D[2]["h_theta"]->Draw("same h");
  h_map_1D[3]["h_theta"]->Draw("same h");
  h_map_1D[0]["h_theta"]->Draw("same h");
  h_map_1D[5]["h_theta"]->Draw("same h");
  h_map_1D[6]["h_theta"]->Draw("same h");
  legend->Clear();
  legend->AddEntry(h_map_1D[0]["h_theta"],"W+jets","lep");
  legend->AddEntry(h_map_1D[1]["h_theta"],"Z+jets","lep");
  legend->AddEntry(h_map_1D[2]["h_theta"],"ttbar","lep");
  legend->AddEntry(h_map_1D[3]["h_theta"],"topsingle","lep");
  legend->AddEntry(h_map_1D[4]["h_theta"],"multijets","lep");
  legend->AddEntry(h_map_1D[5]["h_theta"],"Higgsino","lep");
  legend->AddEntry(h_map_1D[6]["h_theta"],"Wino","lep");
  legend->Draw();
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  h_map_1D[4]["h_beta"]->Draw("h");
  h_map_1D[4]["h_beta"]->SetMinimum(1);
  h_map_1D[1]["h_beta"]->Draw("same h");
  h_map_1D[2]["h_beta"]->Draw("same h");
  h_map_1D[3]["h_beta"]->Draw("same h");
  h_map_1D[0]["h_beta"]->Draw("same h");
  h_map_1D[5]["h_beta"]->Draw("same h");
  h_map_1D[6]["h_beta"]->Draw("same h");
  legend->Clear();
  legend->AddEntry(h_map_1D[0]["h_beta"],"W+jets","lep");
  legend->AddEntry(h_map_1D[1]["h_beta"],"Z+jets","lep");
  legend->AddEntry(h_map_1D[2]["h_beta"],"ttbar","lep");
  legend->AddEntry(h_map_1D[3]["h_beta"],"topsingle","lep");
  legend->AddEntry(h_map_1D[4]["h_beta"],"multijets","lep");
  legend->AddEntry(h_map_1D[5]["h_beta"],"Higgsino","lep");
  legend->AddEntry(h_map_1D[6]["h_beta"],"Wino","lep");
  legend->Draw();
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  h_map_1D[4]["h_gamma"]->Draw("h");
  h_map_1D[4]["h_gamma"]->SetMinimum(1);
  h_map_1D[1]["h_gamma"]->Draw("same h");
  h_map_1D[2]["h_gamma"]->Draw("same h");
  h_map_1D[3]["h_gamma"]->Draw("same h");
  h_map_1D[0]["h_gamma"]->Draw("same h");
  h_map_1D[5]["h_gamma"]->Draw("same h");
  h_map_1D[6]["h_gamma"]->Draw("same h");
  legend->Clear();
  legend->AddEntry(h_map_1D[0]["h_gamma"],"W+jets","lep");
  legend->AddEntry(h_map_1D[1]["h_gamma"],"Z+jets","lep");
  legend->AddEntry(h_map_1D[2]["h_gamma"],"ttbar","lep");
  legend->AddEntry(h_map_1D[3]["h_gamma"],"topsingle","lep");
  legend->AddEntry(h_map_1D[4]["h_gamma"],"multijets","lep");
  legend->AddEntry(h_map_1D[5]["h_gamma"],"Higgsino","lep");
  legend->AddEntry(h_map_1D[6]["h_gamma"],"Wino","lep");
  legend->Draw();
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  h_map_1D[4]["h_betagamma"]->Draw("h");
  h_map_1D[4]["h_betagamma"]->SetMinimum(1);
  h_map_1D[1]["h_betagamma"]->Draw("same h");
  h_map_1D[2]["h_betagamma"]->Draw("same h");
  h_map_1D[3]["h_betagamma"]->Draw("same h");
  h_map_1D[0]["h_betagamma"]->Draw("same h");
  h_map_1D[5]["h_betagamma"]->Draw("same h");
  h_map_1D[6]["h_betagamma"]->Draw("same h");
  legend->Clear();
  legend->AddEntry(h_map_1D[0]["h_betagamma"],"W+jets","lep");
  legend->AddEntry(h_map_1D[1]["h_betagamma"],"Z+jets","lep");
  legend->AddEntry(h_map_1D[2]["h_betagamma"],"ttbar","lep");
  legend->AddEntry(h_map_1D[3]["h_betagamma"],"topsingle","lep");
  legend->AddEntry(h_map_1D[4]["h_betagamma"],"multijets","lep");
  legend->AddEntry(h_map_1D[5]["h_betagamma"],"Higgsino","lep");
  legend->AddEntry(h_map_1D[6]["h_betagamma"],"Wino","lep");
  legend->Draw();
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  h_map_1D[4]["h_met"]->Draw("h");
  h_map_1D[4]["h_met"]->SetMinimum(1);
  h_map_1D[1]["h_met"]->Draw("same h");
  h_map_1D[2]["h_met"]->Draw("same h");
  h_map_1D[3]["h_met"]->Draw("same h");
  h_map_1D[0]["h_met"]->Draw("same h");
  h_map_1D[5]["h_met"]->Draw("same h");
  h_map_1D[6]["h_met"]->Draw("same h");
  legend->Clear();
  legend->AddEntry(h_map_1D[0]["h_met"],"W+jets","lep");
  legend->AddEntry(h_map_1D[1]["h_met"],"Z+jets","lep");
  legend->AddEntry(h_map_1D[2]["h_met"],"ttbar","lep");
  legend->AddEntry(h_map_1D[3]["h_met"],"topsingle","lep");
  legend->AddEntry(h_map_1D[4]["h_met"],"multijets","lep");
  legend->AddEntry(h_map_1D[5]["h_met"],"Higgsino","lep");
  legend->AddEntry(h_map_1D[6]["h_met"],"Wino","lep");
  legend->Draw();
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  h_map_1D[4]["h_met_phi"]->Draw("h");
  h_map_1D[4]["h_met_phi"]->SetMinimum(1);
  h_map_1D[1]["h_met_phi"]->Draw("same h");
  h_map_1D[2]["h_met_phi"]->Draw("same h");
  h_map_1D[3]["h_met_phi"]->Draw("same h");
  h_map_1D[0]["h_met_phi"]->Draw("same h");
  h_map_1D[5]["h_met_phi"]->Draw("same h");
  h_map_1D[6]["h_met_phi"]->Draw("same h");
  legend->Clear();
  legend->AddEntry(h_map_1D[0]["h_met_phi"],"W+jets","lep");
  legend->AddEntry(h_map_1D[1]["h_met_phi"],"Z+jets","lep");
  legend->AddEntry(h_map_1D[2]["h_met_phi"],"ttbar","lep");
  legend->AddEntry(h_map_1D[3]["h_met_phi"],"topsingle","lep");
  legend->AddEntry(h_map_1D[4]["h_met_phi"],"multijets","lep");
  legend->AddEntry(h_map_1D[5]["h_met_phi"],"Higgsino","lep");
  legend->AddEntry(h_map_1D[6]["h_met_phi"],"Wino","lep");
  legend->Draw();
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  h_map_1D[4]["h_delta_phi"]->Draw("h");
  h_map_1D[4]["h_delta_phi"]->SetMinimum(1);
  h_map_1D[1]["h_delta_phi"]->Draw("same h");
  h_map_1D[2]["h_delta_phi"]->Draw("same h");
  h_map_1D[3]["h_delta_phi"]->Draw("same h");
  h_map_1D[0]["h_delta_phi"]->Draw("same h");
  h_map_1D[5]["h_delta_phi"]->Draw("same h");
  h_map_1D[6]["h_delta_phi"]->Draw("same h");
  legend->Clear();
  legend->AddEntry(h_map_1D[0]["h_delta_phi"],"W+jets","lep");
  legend->AddEntry(h_map_1D[1]["h_delta_phi"],"Z+jets","lep");
  legend->AddEntry(h_map_1D[2]["h_delta_phi"],"ttbar","lep");
  legend->AddEntry(h_map_1D[3]["h_delta_phi"],"topsingle","lep");
  legend->AddEntry(h_map_1D[4]["h_delta_phi"],"multijets","lep");
  legend->AddEntry(h_map_1D[5]["h_delta_phi"],"Higgsino","lep");
  legend->AddEntry(h_map_1D[6]["h_delta_phi"],"Wino","lep");
  legend->Draw();
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  h_map_1D[4]["h_delta_pt"]->Draw("h");
  h_map_1D[4]["h_delta_pt"]->SetMinimum(1);
  h_map_1D[1]["h_delta_pt"]->Draw("same h");
  h_map_1D[2]["h_delta_pt"]->Draw("same h");
  h_map_1D[3]["h_delta_pt"]->Draw("same h");
  h_map_1D[0]["h_delta_pt"]->Draw("same h");
  h_map_1D[5]["h_delta_pt"]->Draw("same h");
  h_map_1D[6]["h_delta_pt"]->Draw("same h");
  legend->Clear();
  legend->AddEntry(h_map_1D[0]["h_delta_pt"],"W+jets","lep");
  legend->AddEntry(h_map_1D[1]["h_delta_pt"],"Z+jets","lep");
  legend->AddEntry(h_map_1D[2]["h_delta_pt"],"ttbar","lep");
  legend->AddEntry(h_map_1D[3]["h_delta_pt"],"topsingle","lep");
  legend->AddEntry(h_map_1D[4]["h_delta_pt"],"multijets","lep");
  legend->AddEntry(h_map_1D[5]["h_delta_pt"],"Higgsino","lep");
  legend->AddEntry(h_map_1D[6]["h_delta_pt"],"Wino","lep");
  legend->Draw();
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  ///////////////////////////////////
  h_map_1D[4]["c1h_eta"]->Draw("h");
  h_map_1D[4]["c1h_eta"]->SetMinimum(1);
  h_map_1D[1]["c1h_eta"]->Draw("same h");
  h_map_1D[2]["c1h_eta"]->Draw("same h");
  h_map_1D[3]["c1h_eta"]->Draw("same h");
  h_map_1D[0]["c1h_eta"]->Draw("same h");
  h_map_1D[5]["c1h_eta"]->Draw("same h");
  h_map_1D[6]["c1h_eta"]->Draw("same h");
  legend->Clear();
  legend->AddEntry(h_map_1D[0]["h_eta"],"W+jets","lep");
  legend->AddEntry(h_map_1D[1]["h_eta"],"Z+jets","lep");
  legend->AddEntry(h_map_1D[2]["h_eta"],"ttbar","lep");
  legend->AddEntry(h_map_1D[3]["h_eta"],"topsingle","lep");
  legend->AddEntry(h_map_1D[4]["h_eta"],"multijets","lep");
  legend->AddEntry(h_map_1D[5]["h_eta"],"Higgsino","lep");
  legend->AddEntry(h_map_1D[6]["h_eta"],"Wino","lep");
  legend->Draw();
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  h_map_1D[4]["c1h_phi"]->Draw("h");
  h_map_1D[4]["c1h_phi"]->SetMinimum(1);
  h_map_1D[1]["c1h_phi"]->Draw("same h");
  h_map_1D[2]["c1h_phi"]->Draw("same h");
  h_map_1D[3]["c1h_phi"]->Draw("same h");
  h_map_1D[0]["c1h_phi"]->Draw("same h");
  h_map_1D[5]["c1h_phi"]->Draw("same h");
  h_map_1D[6]["c1h_phi"]->Draw("same h");
  legend->Clear();
  legend->AddEntry(h_map_1D[0]["h_phi"],"W+jets","lep");
  legend->AddEntry(h_map_1D[1]["h_phi"],"Z+jets","lep");
  legend->AddEntry(h_map_1D[2]["h_phi"],"ttbar","lep");
  legend->AddEntry(h_map_1D[3]["h_phi"],"topsingle","lep");
  legend->AddEntry(h_map_1D[4]["h_phi"],"multijets","lep");
  legend->AddEntry(h_map_1D[5]["h_phi"],"Higgsino","lep");
  legend->AddEntry(h_map_1D[6]["h_phi"],"Wino","lep");
  legend->Draw();
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  h_map_1D[4]["c1h_theta"]->Draw("h");
  h_map_1D[4]["c1h_theta"]->SetMinimum(1);
  h_map_1D[1]["c1h_theta"]->Draw("same h");
  h_map_1D[2]["c1h_theta"]->Draw("same h");
  h_map_1D[3]["c1h_theta"]->Draw("same h");
  h_map_1D[0]["c1h_theta"]->Draw("same h");
  h_map_1D[5]["c1h_theta"]->Draw("same h");
  h_map_1D[6]["c1h_theta"]->Draw("same h");
  legend->Clear();
  legend->AddEntry(h_map_1D[0]["h_theta"],"W+jets","lep");
  legend->AddEntry(h_map_1D[1]["h_theta"],"Z+jets","lep");
  legend->AddEntry(h_map_1D[2]["h_theta"],"ttbar","lep");
  legend->AddEntry(h_map_1D[3]["h_theta"],"topsingle","lep");
  legend->AddEntry(h_map_1D[4]["h_theta"],"multijets","lep");
  legend->AddEntry(h_map_1D[5]["h_theta"],"Higgsino","lep");
  legend->AddEntry(h_map_1D[6]["h_theta"],"Wino","lep");
  legend->Draw();
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  h_map_1D[4]["c1h_beta"]->Draw("h");
  h_map_1D[4]["c1h_beta"]->SetMinimum(1);
  h_map_1D[1]["c1h_beta"]->Draw("same h");
  h_map_1D[2]["c1h_beta"]->Draw("same h");
  h_map_1D[3]["c1h_beta"]->Draw("same h");
  h_map_1D[0]["c1h_beta"]->Draw("same h");
  h_map_1D[5]["c1h_beta"]->Draw("same h");
  h_map_1D[6]["c1h_beta"]->Draw("same h");
  legend->Clear();
  legend->AddEntry(h_map_1D[0]["h_beta"],"W+jets","lep");
  legend->AddEntry(h_map_1D[1]["h_beta"],"Z+jets","lep");
  legend->AddEntry(h_map_1D[2]["h_beta"],"ttbar","lep");
  legend->AddEntry(h_map_1D[3]["h_beta"],"topsingle","lep");
  legend->AddEntry(h_map_1D[4]["h_beta"],"multijets","lep");
  legend->AddEntry(h_map_1D[5]["h_beta"],"Higgsino","lep");
  legend->AddEntry(h_map_1D[6]["h_beta"],"Wino","lep");
  legend->Draw();
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  h_map_1D[4]["c1h_gamma"]->Draw("h");
  h_map_1D[4]["c1h_gamma"]->SetMinimum(1);
  h_map_1D[1]["c1h_gamma"]->Draw("same h");
  h_map_1D[2]["c1h_gamma"]->Draw("same h");
  h_map_1D[3]["c1h_gamma"]->Draw("same h");
  h_map_1D[0]["c1h_gamma"]->Draw("same h");
  h_map_1D[5]["c1h_gamma"]->Draw("same h");
  h_map_1D[6]["c1h_gamma"]->Draw("same h");
  legend->Clear();
  legend->AddEntry(h_map_1D[0]["h_gamma"],"W+jets","lep");
  legend->AddEntry(h_map_1D[1]["h_gamma"],"Z+jets","lep");
  legend->AddEntry(h_map_1D[2]["h_gamma"],"ttbar","lep");
  legend->AddEntry(h_map_1D[3]["h_gamma"],"topsingle","lep");
  legend->AddEntry(h_map_1D[4]["h_gamma"],"multijets","lep");
  legend->AddEntry(h_map_1D[5]["h_gamma"],"Higgsino","lep");
  legend->AddEntry(h_map_1D[6]["h_gamma"],"Wino","lep");
  legend->Draw();
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  h_map_1D[4]["c1h_betagamma"]->Draw("h");
  h_map_1D[4]["c1h_betagamma"]->SetMinimum(1);
  h_map_1D[1]["c1h_betagamma"]->Draw("same h");
  h_map_1D[2]["c1h_betagamma"]->Draw("same h");
  h_map_1D[3]["c1h_betagamma"]->Draw("same h");
  h_map_1D[0]["c1h_betagamma"]->Draw("same h");
  h_map_1D[5]["c1h_betagamma"]->Draw("same h");
  h_map_1D[6]["c1h_betagamma"]->Draw("same h");
  legend->Clear();
  legend->AddEntry(h_map_1D[0]["h_betagamma"],"W+jets","lep");
  legend->AddEntry(h_map_1D[1]["h_betagamma"],"Z+jets","lep");
  legend->AddEntry(h_map_1D[2]["h_betagamma"],"ttbar","lep");
  legend->AddEntry(h_map_1D[3]["h_betagamma"],"topsingle","lep");
  legend->AddEntry(h_map_1D[4]["h_betagamma"],"multijets","lep");
  legend->AddEntry(h_map_1D[5]["h_betagamma"],"Higgsino","lep");
  legend->AddEntry(h_map_1D[6]["h_betagamma"],"Wino","lep");
  legend->Draw();
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  h_map_1D[4]["c1h_met"]->Draw("h");
  h_map_1D[4]["c1h_met"]->SetMinimum(1);
  h_map_1D[1]["c1h_met"]->Draw("same h");
  h_map_1D[2]["c1h_met"]->Draw("same h");
  h_map_1D[3]["c1h_met"]->Draw("same h");
  h_map_1D[0]["c1h_met"]->Draw("same h");
  h_map_1D[5]["c1h_met"]->Draw("same h");
  h_map_1D[6]["c1h_met"]->Draw("same h");
  legend->Clear();
  legend->AddEntry(h_map_1D[0]["h_met"],"W+jets","lep");
  legend->AddEntry(h_map_1D[1]["h_met"],"Z+jets","lep");
  legend->AddEntry(h_map_1D[2]["h_met"],"ttbar","lep");
  legend->AddEntry(h_map_1D[3]["h_met"],"topsingle","lep");
  legend->AddEntry(h_map_1D[4]["h_met"],"multijets","lep");
  legend->AddEntry(h_map_1D[5]["h_met"],"Higgsino","lep");
  legend->AddEntry(h_map_1D[6]["h_met"],"Wino","lep");
  legend->Draw();
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  h_map_1D[4]["c1h_met_phi"]->Draw("h");
  h_map_1D[4]["c1h_met_phi"]->SetMinimum(1);
  h_map_1D[1]["c1h_met_phi"]->Draw("same h");
  h_map_1D[2]["c1h_met_phi"]->Draw("same h");
  h_map_1D[3]["c1h_met_phi"]->Draw("same h");
  h_map_1D[0]["c1h_met_phi"]->Draw("same h");
  h_map_1D[5]["c1h_met_phi"]->Draw("same h");
  h_map_1D[6]["c1h_met_phi"]->Draw("same h");
  legend->Clear();
  legend->AddEntry(h_map_1D[0]["h_met_phi"],"W+jets","lep");
  legend->AddEntry(h_map_1D[1]["h_met_phi"],"Z+jets","lep");
  legend->AddEntry(h_map_1D[2]["h_met_phi"],"ttbar","lep");
  legend->AddEntry(h_map_1D[3]["h_met_phi"],"topsingle","lep");
  legend->AddEntry(h_map_1D[4]["h_met_phi"],"multijets","lep");
  legend->AddEntry(h_map_1D[5]["h_met_phi"],"Higgsino","lep");
  legend->AddEntry(h_map_1D[6]["h_met_phi"],"Wino","lep");
  legend->Draw();
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  h_map_1D[4]["c1h_delta_phi"]->Draw("h");
  h_map_1D[4]["c1h_delta_phi"]->SetMinimum(1);
  h_map_1D[1]["c1h_delta_phi"]->Draw("same h");
  h_map_1D[2]["c1h_delta_phi"]->Draw("same h");
  h_map_1D[3]["c1h_delta_phi"]->Draw("same h");
  h_map_1D[0]["c1h_delta_phi"]->Draw("same h");
  h_map_1D[5]["c1h_delta_phi"]->Draw("same h");
  h_map_1D[6]["c1h_delta_phi"]->Draw("same h");
  legend->Clear();
  legend->AddEntry(h_map_1D[0]["h_delta_phi"],"W+jets","lep");
  legend->AddEntry(h_map_1D[1]["h_delta_phi"],"Z+jets","lep");
  legend->AddEntry(h_map_1D[2]["h_delta_phi"],"ttbar","lep");
  legend->AddEntry(h_map_1D[3]["h_delta_phi"],"topsingle","lep");
  legend->AddEntry(h_map_1D[4]["h_delta_phi"],"multijets","lep");
  legend->AddEntry(h_map_1D[5]["h_delta_phi"],"Higgsino","lep");
  legend->AddEntry(h_map_1D[6]["h_delta_phi"],"Wino","lep");
  legend->Draw();
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  h_map_1D[4]["c1h_delta_pt"]->Draw("h");
  h_map_1D[4]["c1h_delta_pt"]->SetMinimum(1);
  h_map_1D[1]["c1h_delta_pt"]->Draw("same h");
  h_map_1D[2]["c1h_delta_pt"]->Draw("same h");
  h_map_1D[3]["c1h_delta_pt"]->Draw("same h");
  h_map_1D[0]["c1h_delta_pt"]->Draw("same h");
  h_map_1D[5]["c1h_delta_pt"]->Draw("same h");
  h_map_1D[6]["c1h_delta_pt"]->Draw("same h");
  legend->Clear();
  legend->AddEntry(h_map_1D[0]["h_delta_pt"],"W+jets","lep");
  legend->AddEntry(h_map_1D[1]["h_delta_pt"],"Z+jets","lep");
  legend->AddEntry(h_map_1D[2]["h_delta_pt"],"ttbar","lep");
  legend->AddEntry(h_map_1D[3]["h_delta_pt"],"topsingle","lep");
  legend->AddEntry(h_map_1D[4]["h_delta_pt"],"multijets","lep");
  legend->AddEntry(h_map_1D[5]["h_delta_pt"],"Higgsino","lep");
  legend->AddEntry(h_map_1D[6]["h_delta_pt"],"Wino","lep");
  legend->Draw();
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  ///////////////////////////////////
  h_map_1D[4]["c2h_eta"]->Draw("h");
  h_map_1D[4]["c2h_eta"]->SetMinimum(1);
  h_map_1D[1]["c2h_eta"]->Draw("same h");
  h_map_1D[2]["c2h_eta"]->Draw("same h");
  h_map_1D[3]["c2h_eta"]->Draw("same h");
  h_map_1D[0]["c2h_eta"]->Draw("same h");
  h_map_1D[5]["c2h_eta"]->Draw("same h");
  h_map_1D[6]["c2h_eta"]->Draw("same h");
  legend->Clear();
  legend->AddEntry(h_map_1D[0]["c2h_eta"],"W+jets","lep");
  legend->AddEntry(h_map_1D[1]["c2h_eta"],"Z+jets","lep");
  legend->AddEntry(h_map_1D[2]["c2h_eta"],"ttbar","lep");
  legend->AddEntry(h_map_1D[3]["c2h_eta"],"topsingle","lep");
  legend->AddEntry(h_map_1D[4]["c2h_eta"],"multijets","lep");
  legend->AddEntry(h_map_1D[5]["c2h_eta"],"Higgsino","lep");
  legend->AddEntry(h_map_1D[6]["c2h_eta"],"Wino","lep");
  legend->Draw();
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  h_map_1D[4]["c2h_phi"]->Draw("h");
  h_map_1D[4]["c2h_phi"]->SetMinimum(1);
  h_map_1D[1]["c2h_phi"]->Draw("same h");
  h_map_1D[2]["c2h_phi"]->Draw("same h");
  h_map_1D[3]["c2h_phi"]->Draw("same h");
  h_map_1D[0]["c2h_phi"]->Draw("same h");
  h_map_1D[5]["c2h_phi"]->Draw("same h");
  h_map_1D[6]["c2h_phi"]->Draw("same h");
  legend->Clear();
  legend->AddEntry(h_map_1D[0]["c2h_phi"],"W+jets","lep");
  legend->AddEntry(h_map_1D[1]["c2h_phi"],"Z+jets","lep");
  legend->AddEntry(h_map_1D[2]["c2h_phi"],"ttbar","lep");
  legend->AddEntry(h_map_1D[3]["c2h_phi"],"topsingle","lep");
  legend->AddEntry(h_map_1D[4]["c2h_phi"],"multijets","lep");
  legend->AddEntry(h_map_1D[5]["c2h_phi"],"Higgsino","lep");
  legend->AddEntry(h_map_1D[6]["c2h_phi"],"Wino","lep");
  legend->Draw();
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  h_map_1D[4]["c2h_theta"]->Draw("h");
  h_map_1D[4]["c2h_theta"]->SetMinimum(1);
  h_map_1D[1]["c2h_theta"]->Draw("same h");
  h_map_1D[2]["c2h_theta"]->Draw("same h");
  h_map_1D[3]["c2h_theta"]->Draw("same h");
  h_map_1D[0]["c2h_theta"]->Draw("same h");
  h_map_1D[5]["c2h_theta"]->Draw("same h");
  h_map_1D[6]["c2h_theta"]->Draw("same h");
  legend->Clear();
  legend->AddEntry(h_map_1D[0]["c2h_theta"],"W+jets","lep");
  legend->AddEntry(h_map_1D[1]["c2h_theta"],"Z+jets","lep");
  legend->AddEntry(h_map_1D[2]["c2h_theta"],"ttbar","lep");
  legend->AddEntry(h_map_1D[3]["c2h_theta"],"topsingle","lep");
  legend->AddEntry(h_map_1D[4]["c2h_theta"],"multijets","lep");
  legend->AddEntry(h_map_1D[5]["c2h_theta"],"Higgsino","lep");
  legend->AddEntry(h_map_1D[6]["c2h_theta"],"Wino","lep");
  legend->Draw();
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  h_map_1D[4]["c2h_beta"]->Draw("h");
  h_map_1D[4]["c2h_beta"]->SetMinimum(1);
  h_map_1D[1]["c2h_beta"]->Draw("same h");
  h_map_1D[2]["c2h_beta"]->Draw("same h");
  h_map_1D[3]["c2h_beta"]->Draw("same h");
  h_map_1D[0]["c2h_beta"]->Draw("same h");
  h_map_1D[5]["c2h_beta"]->Draw("same h");
  h_map_1D[6]["c2h_beta"]->Draw("same h");
  legend->Clear();
  legend->AddEntry(h_map_1D[0]["c2h_beta"],"W+jets","lep");
  legend->AddEntry(h_map_1D[1]["c2h_beta"],"Z+jets","lep");
  legend->AddEntry(h_map_1D[2]["c2h_beta"],"ttbar","lep");
  legend->AddEntry(h_map_1D[3]["c2h_beta"],"topsingle","lep");
  legend->AddEntry(h_map_1D[4]["c2h_beta"],"multijets","lep");
  legend->AddEntry(h_map_1D[5]["c2h_beta"],"Higgsino","lep");
  legend->AddEntry(h_map_1D[6]["c2h_beta"],"Wino","lep");
  legend->Draw();
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  h_map_1D[4]["c2h_gamma"]->Draw("h");
  h_map_1D[4]["c2h_gamma"]->SetMinimum(1);
  h_map_1D[1]["c2h_gamma"]->Draw("same h");
  h_map_1D[2]["c2h_gamma"]->Draw("same h");
  h_map_1D[3]["c2h_gamma"]->Draw("same h");
  h_map_1D[0]["c2h_gamma"]->Draw("same h");
  h_map_1D[5]["c2h_gamma"]->Draw("same h");
  h_map_1D[6]["c2h_gamma"]->Draw("same h");
  legend->Clear();
  legend->AddEntry(h_map_1D[0]["c2h_gamma"],"W+jets","lep");
  legend->AddEntry(h_map_1D[1]["c2h_gamma"],"Z+jets","lep");
  legend->AddEntry(h_map_1D[2]["c2h_gamma"],"ttbar","lep");
  legend->AddEntry(h_map_1D[3]["c2h_gamma"],"topsingle","lep");
  legend->AddEntry(h_map_1D[4]["c2h_gamma"],"multijets","lep");
  legend->AddEntry(h_map_1D[5]["c2h_gamma"],"Higgsino","lep");
  legend->AddEntry(h_map_1D[6]["c2h_gamma"],"Wino","lep");
  legend->Draw();
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  h_map_1D[4]["c2h_betagamma"]->Draw("h");
  h_map_1D[4]["c2h_betagamma"]->SetMinimum(1);
  h_map_1D[1]["c2h_betagamma"]->Draw("same h");
  h_map_1D[2]["c2h_betagamma"]->Draw("same h");
  h_map_1D[3]["c2h_betagamma"]->Draw("same h");
  h_map_1D[0]["c2h_betagamma"]->Draw("same h");
  h_map_1D[5]["c2h_betagamma"]->Draw("same h");
  h_map_1D[6]["c2h_betagamma"]->Draw("same h");
  legend->Clear();
  legend->AddEntry(h_map_1D[0]["c2h_betagamma"],"W+jets","lep");
  legend->AddEntry(h_map_1D[1]["c2h_betagamma"],"Z+jets","lep");
  legend->AddEntry(h_map_1D[2]["c2h_betagamma"],"ttbar","lep");
  legend->AddEntry(h_map_1D[3]["c2h_betagamma"],"topsingle","lep");
  legend->AddEntry(h_map_1D[4]["c2h_betagamma"],"multijets","lep");
  legend->AddEntry(h_map_1D[5]["c2h_betagamma"],"Higgsino","lep");
  legend->AddEntry(h_map_1D[6]["c2h_betagamma"],"Wino","lep");
  legend->Draw();
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  h_map_1D[4]["c2h_met"]->Draw("h");
  h_map_1D[4]["c2h_met"]->SetMinimum(1);
  h_map_1D[1]["c2h_met"]->Draw("same h");
  h_map_1D[2]["c2h_met"]->Draw("same h");
  h_map_1D[3]["c2h_met"]->Draw("same h");
  h_map_1D[0]["c2h_met"]->Draw("same h");
  h_map_1D[5]["c2h_met"]->Draw("same h");
  h_map_1D[6]["c2h_met"]->Draw("same h");
  legend->Clear();
  legend->AddEntry(h_map_1D[0]["c2h_met"],"W+jets","lep");
  legend->AddEntry(h_map_1D[1]["c2h_met"],"Z+jets","lep");
  legend->AddEntry(h_map_1D[2]["c2h_met"],"ttbar","lep");
  legend->AddEntry(h_map_1D[3]["c2h_met"],"topsingle","lep");
  legend->AddEntry(h_map_1D[4]["c2h_met"],"multijets","lep");
  legend->AddEntry(h_map_1D[5]["c2h_met"],"Higgsino","lep");
  legend->AddEntry(h_map_1D[6]["c2h_met"],"Wino","lep");
  legend->Draw();
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  h_map_1D[4]["c2h_met_phi"]->Draw("h");
  h_map_1D[4]["c2h_met_phi"]->SetMinimum(1);
  h_map_1D[1]["c2h_met_phi"]->Draw("same h");
  h_map_1D[2]["c2h_met_phi"]->Draw("same h");
  h_map_1D[3]["c2h_met_phi"]->Draw("same h");
  h_map_1D[0]["c2h_met_phi"]->Draw("same h");
  h_map_1D[5]["c2h_met_phi"]->Draw("same h");
  h_map_1D[6]["c2h_met_phi"]->Draw("same h");
  legend->Clear();
  legend->AddEntry(h_map_1D[0]["c2h_met_phi"],"W+jets","lep");
  legend->AddEntry(h_map_1D[1]["c2h_met_phi"],"Z+jets","lep");
  legend->AddEntry(h_map_1D[2]["c2h_met_phi"],"ttbar","lep");
  legend->AddEntry(h_map_1D[3]["c2h_met_phi"],"topsingle","lep");
  legend->AddEntry(h_map_1D[4]["c2h_met_phi"],"multijets","lep");
  legend->AddEntry(h_map_1D[5]["c2h_met_phi"],"Higgsino","lep");
  legend->AddEntry(h_map_1D[6]["c2h_met_phi"],"Wino","lep");
  legend->Draw();
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  h_map_1D[4]["c2h_delta_phi"]->Draw("h");
  h_map_1D[4]["c2h_delta_phi"]->SetMinimum(1);
  h_map_1D[1]["c2h_delta_phi"]->Draw("same h");
  h_map_1D[2]["c2h_delta_phi"]->Draw("same h");
  h_map_1D[3]["c2h_delta_phi"]->Draw("same h");
  h_map_1D[0]["c2h_delta_phi"]->Draw("same h");
  h_map_1D[5]["c2h_delta_phi"]->Draw("same h");
  h_map_1D[6]["c2h_delta_phi"]->Draw("same h");
  legend->Clear();
  legend->AddEntry(h_map_1D[0]["c2h_delta_phi"],"W+jets","lep");
  legend->AddEntry(h_map_1D[1]["c2h_delta_phi"],"Z+jets","lep");
  legend->AddEntry(h_map_1D[2]["c2h_delta_phi"],"ttbar","lep");
  legend->AddEntry(h_map_1D[3]["c2h_delta_phi"],"topsingle","lep");
  legend->AddEntry(h_map_1D[4]["c2h_delta_phi"],"multijets","lep");
  legend->AddEntry(h_map_1D[5]["c2h_delta_phi"],"Higgsino","lep");
  legend->AddEntry(h_map_1D[6]["c2h_delta_phi"],"Wino","lep");
  legend->Draw();
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  h_map_1D[4]["c2h_delta_pt"]->Draw("h");
  h_map_1D[4]["c2h_delta_pt"]->SetMinimum(1);
  h_map_1D[1]["c2h_delta_pt"]->Draw("same h");
  h_map_1D[2]["c2h_delta_pt"]->Draw("same h");
  h_map_1D[3]["c2h_delta_pt"]->Draw("same h");
  h_map_1D[0]["c2h_delta_pt"]->Draw("same h");
  h_map_1D[5]["c2h_delta_pt"]->Draw("same h");
  h_map_1D[6]["c2h_delta_pt"]->Draw("same h");
  canvas->SaveAs(ss2.c_str());
  canvas->SaveAs(ss3.c_str());
  canvas->Clear();


  /////////////////////////////////////////////////////
  /////////////////////////////////////////////////////
  h_map_2D[4]["Jh_eta"]->Draw("colz");
  canvas->SaveAs(ss1_2D.c_str());
  canvas->SaveAs(ss2_2D.c_str());
  canvas->Clear();

  h_map_2D[4]["Jh_phi"]->Draw("colz");
  canvas->SaveAs(ss2_2D.c_str());
  canvas->Clear();

  h_map_2D[4]["Jh_theta"]->Draw("colz");
  canvas->SaveAs(ss2_2D.c_str());
  canvas->Clear();

  h_map_2D[4]["Jh_beta"]->Draw("colz");
  canvas->SaveAs(ss2_2D.c_str());
  canvas->Clear();

  h_map_2D[4]["Jh_gamma"]->Draw("colz");
  canvas->SaveAs(ss2_2D.c_str());
  canvas->Clear();

  h_map_2D[4]["Jh_betagamma"]->Draw("colz");
  canvas->SaveAs(ss2_2D.c_str());
  canvas->Clear();

  h_map_2D[4]["Jh_met"]->Draw("colz");
  canvas->SaveAs(ss2_2D.c_str());
  canvas->Clear();

  h_map_2D[4]["Jh_met_phi"]->Draw("colz");
  canvas->SaveAs(ss2_2D.c_str());
  canvas->Clear();

  h_map_2D[4]["Jh_delta_phi"]->Draw("colz");
  canvas->SaveAs(ss2_2D.c_str());
  canvas->Clear();

  h_map_2D[4]["Jh_delta_pt"]->Draw("colz");
  canvas->SaveAs(ss2_2D.c_str());
  canvas->Clear();

  /////////////////////////////////////////////////////
  h_map_2D[4]["Mh_eta"]->Draw("colz");
  canvas->SaveAs(ss2_2D.c_str());
  canvas->Clear();

  h_map_2D[4]["Mh_phi"]->Draw("colz");
  canvas->SaveAs(ss2_2D.c_str());
  canvas->Clear();

  h_map_2D[4]["Mh_theta"]->Draw("colz");
  canvas->SaveAs(ss2_2D.c_str());
  canvas->Clear();

  h_map_2D[4]["Mh_beta"]->Draw("colz");
  canvas->SaveAs(ss2_2D.c_str());
  canvas->Clear();

  h_map_2D[4]["Mh_gamma"]->Draw("colz");
  canvas->SaveAs(ss2_2D.c_str());
  canvas->Clear();

  h_map_2D[4]["Mh_betagamma"]->Draw("colz");
  canvas->SaveAs(ss2_2D.c_str());
  canvas->Clear();

  h_map_2D[4]["Mh_met"]->Draw("colz");
  canvas->SaveAs(ss2_2D.c_str());
  canvas->Clear();

  h_map_2D[4]["Mh_met_phi"]->Draw("colz");
  canvas->SaveAs(ss2_2D.c_str());
  canvas->Clear();

  h_map_2D[4]["Mh_delta_phi"]->Draw("colz");
  canvas->SaveAs(ss2_2D.c_str());
  canvas->Clear();

  h_map_2D[4]["Mh_delta_pt"]->Draw("colz");
  canvas->SaveAs(ss2_2D.c_str());
  canvas->SaveAs(ss3_2D.c_str());


}

void histo_styling(TH1D* h, int j){
    h->SetLineColor(j);
    h->SetMarkerColor(j);
    h->SetMarkerSize(0);
    h->SetLineStyle(2);
    h->SetLineWidth(2);
    h->GetYaxis()->SetLabelSize(0.05);
    h->GetXaxis()->SetLabelSize(0.05);
    h->GetYaxis()->SetTitleSize(0.05);
    h->GetXaxis()->SetTitleSize(0.05);
    h->GetXaxis()->SetNdivisions(5,10,1);
  // h->SetLabelSize(1,"xy");
  // h->SetMarkerColor(j);
  // h->SetMarkerStyle(8);
  // h->SetMarkerSize(0);
  // h->SetTitle(tit);
  // h->GetXaxis()->SetTitle(tit_x);
  // h->GetYaxis()->SetTitle(tit_y);
}
