#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
///////////// What this .cc does:
// !!! Important !!!
// This .cc needs GetXsec_simple.txt in the same location
//
// This .cc concerns the signal samples only.
// 1) It reads GetXsec_simple.txt to extract the cross sections of the signal
// 2) It calculates the expected number of events considering a luminosity of 30ab-1
// 3) It saves them to Nr_Events_signal.txt
////////////////////////////////////////////////////////////////////////////////


void make_wino();
void make_higgsino();

void xsec_calcu_signal() {
  // make_wino();
  make_higgsino();

}

void make_wino(){
  ifstream MyReadFile("/afs/cern.ch/user/c/chugli/private/txt/GetXsec_simple.txt"); // Read from the text file

  string s;
  string delimiter = ",";
  string delimiter2 = "+";
  int counter = 0;
  double n3;
  double myarray[80][2];
  // Use a while loop together with the getline() function to read the file line by line
  while (getline (MyReadFile, s)) {
    // cout << s << endl; // Output the text from the file
    if(counter>1 && counter < 82){
      size_t found1;
      size_t found2;
      size_t found3;
      string s1;
      string s2;
      string s3;

      found1 = s.find(delimiter,0); // position of first delimiter
      found2 = s.find(delimiter,found1+1);// trova delimiter nella string s partendo da found1+1
      s1 = s.substr(0, found1); //string da 0 a position of first delimiter
      s2 = s.substr(found1+2, found2-found1-2);
      if(s2=="C1N1"){
        found3 = s.find(delimiter2);
        s3 = s.substr(found2+2,found3-found2-1);
        n3 = stod(s3);
        s3 = s.substr(found3+1,-1);
        n3 += stod(s3);
      }else{
        s3 = s.substr(found2+2,-1);
        n3 = stod(s3);
      }
      // cout << n3 << endl;
      myarray[counter-2][0]= stod(s1);
      myarray[counter-2][1]= n3;
    }else if(counter >= 82){
      break;
    }
    counter++;
  }
  MyReadFile.close(); // Close the file

  ////////
  // myarray contains the energys and cross sections of the different cases.

  //////////////////////////////////////////////////////////////////////////////
  /////////////////// Calculate number of events and write them to a results.txt:
  double myresults[80][2];
  double lumi_int = 30e6; //pb-1 => since xsec also in pb-1
  ofstream MyFile("/afs/cern.ch/user/c/chugli/private/txt/Nr_Events_signal.txt"); // Create and open a text file
  string mystring;

  MyFile << "// Wino \n// mass, process, number of events for integrated luminosity of 30ab-1 \n";

  for(int i=0; i<80;i++){
    myresults[i][0] = myarray[i][0];
    myresults[i][1] = myarray[i][1]*lumi_int;
    // cout << myresults[i][1] << endl;

    ostringstream streamObj; // use this to get scientific notation and rounding
    streamObj << myarray[i][0];
    string s1 = streamObj.str();
    ostringstream streamObj2;
    streamObj2 << myarray[i][1]*lumi_int;
    string s3 = streamObj2.str();
    string s2 = (i%2==0) ? "C1N1" : "C1C1";
    // cout << s1 << endl;
    // cout << s3 << endl;
    mystring = s1+", "+s2+", "+s3+";"+"\n";

    MyFile << mystring;
  }
  MyFile.close();
}

void make_higgsino(){
  ifstream MyReadFile("/afs/cern.ch/user/c/chugli/private/txt/GetXsec_simple_higgsino.txt"); // Read from the text file

  string s;
  string delimiter = ",";
  string delimiter2 = "+";
  string delimiter3 = ")";
  int counter = 0;
  double n3;
  double myarray[18][2];
  // Use a while loop together with the getline() function to read the file line by line
  while (getline (MyReadFile, s)) {
    // cout << s << endl; // Output the text from the file
    if(counter>1 && counter < 20){

      size_t found1 = s.find(delimiter,0);
      size_t found2 = s.find(delimiter,found1+1);
      string s1 = s.substr(0, found1);
      string s2 = s.substr(found1+2, found2-found1-2);
      // cout << s1 << endl;
      // cout << s2 << endl;
      if(s2=="C1N1"){
        size_t found3 = s.find(delimiter2);
        size_t found4 = s.find(delimiter3);
        string s3 = s.substr(found2+3,found3-found2-4);
        // cout << "A: " << s3 << endl;
        n3 = stod(s3);
        s3 = s.substr(found3+2,found4-found3-2);
        // cout << "B: " << s3 << endl;
        n3 += stod(s3);
        n3 = n3*2;
      }else{
        string s3 = s.substr(found2+2,12);
        // cout << "C: " << s3 << endl;
        n3 = stod(s3);
      }
      myarray[counter-2][0]= stod(s1);
      myarray[counter-2][1]= n3;
    }else if(counter >= 20){
      break;
    }
    counter++;
  }
  MyReadFile.close(); // Close the file

  ////////
  // myarray contains the energys and cross sections of the different cases.

  //////////////////////////////////////////////////////////////////////////////
  /////////////////// Calculate number of events and write them to a results.txt:
  double myresults[18][2];
  double lumi_int = 30e6; //pb-1 => since xsec also in pb-1
  ofstream MyFile("/afs/cern.ch/user/c/chugli/private/txt/Nr_Events_signal_higgsino.txt"); // Create and open a text file
  string mystring;

  MyFile << "// Wino \n// mass, process, number of events for integrated luminosity of 30ab-1 \n";

  for(int i=0; i<18;i++){
    myresults[i][0] = myarray[i][0];
    myresults[i][1] = myarray[i][1]*lumi_int;
    // cout << myresults[i][1] << endl;

    ostringstream streamObj; // use this to get scientific notation and rounding
    streamObj << myarray[i][0];
    string s1 = streamObj.str();
    ostringstream streamObj2;
    streamObj2 << myarray[i][1]*lumi_int;
    string s3 = streamObj2.str();
    string s2 = (i%2==0) ? "C1N1" : "C1C1";
    cout << s1 << endl;
    cout << s3 << endl;
    mystring = s1+", "+s2+", "+s3+";"+"\n";

    MyFile << mystring;
  }
  MyFile.close();
}
