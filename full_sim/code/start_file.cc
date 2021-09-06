#include <iostream>
#include <fstream>
#include <sstream>

void start_file(){
  ofstream MyFile;
  string myname = "/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/txt_files/Fake_rate_estimation.txt";
  MyFile.open(myname.c_str()); // Create and open a text file
  MyFile << "// tight time, tight both, tight other, lose both\n";
  MyFile.close();
}
