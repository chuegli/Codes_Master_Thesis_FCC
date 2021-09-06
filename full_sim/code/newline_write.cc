#include <iostream>
#include <fstream>
#include <sstream>

void newline_write(){
  ofstream MyFile;
  string myname = "/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/txt_files/Fake_rate_estimation.txt";
  MyFile.open(myname.c_str(), ios_base::app); // Create and open a text file
  MyFile << ";\n";
  MyFile.close();
}
