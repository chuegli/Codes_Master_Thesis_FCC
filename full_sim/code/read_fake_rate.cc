

double getMean(double arr[], int size);
double getRMS(double arr[], int size);


void read_fake_rate(){

  TH1D* h_TL = new TH1D("h_TL", "h_TL", 100,-1,20);
  TH1D* h_TT = new TH1D("h_TT", "h_TT", 100,-1,20);
  TH1D* h_LT = new TH1D("h_LT", "h_LT", 100,-0,1000);
  TH1D* h_LL = new TH1D("h_LL", "h_LL", 100,-0,10000);

  ////////////////////// Read the file:
  ifstream MyReadFile("/afs/cern.ch/user/c/chugli/private/full_sim/FCCSW_pileup_1/Mio/txt_files/Fake_rate_estimation_final_5.txt"); // Read from the text file
  string s;
  string delimiter = ",";
  int counter = 0;
  int n = 2012;
  double f_TL[n],f_TT[n],f_LT[n],f_LL[n];
  // Use a while loop together with the getline() function to read the file line by line
  while (getline (MyReadFile, s)) {
    if(counter>1){
      size_t found1;
      size_t found2;
      size_t found3;
      size_t found4;
      string s1;
      string s2;
      string s3;
      string s4;
      found1 = s.find(delimiter,0); // position of first delimiter
      found2 = s.find(delimiter,found1+1);// trova delimiter nella string s partendo da found1+1
      found3 = s.find(delimiter,found2+1);
      found4 = s.find(delimiter,found3+1);
      s1 = s.substr(0, found1); //string da 0 a position of first delimiter
      s2 = s.substr(found1+2, found2-found1-2);
      s3 = s.substr(found2+2, found3-found2-2);
      s4 = s.substr(found3+2, found4-found3-2);
      // cout << s1 << "  " << s2 << "  " << s3 << "  " << s4 << endl;
      f_TL[counter-1] = stod(s1);
      f_TT[counter-1] = stod(s2);
      f_LT[counter-1] = stod(s3);
      f_LL[counter-1] = stod(s4);
      h_TL->Fill(stod(s1));
      h_TT->Fill(stod(s2));
      h_LT->Fill(stod(s3));
      h_LL->Fill(stod(s4));
    }
    counter ++;
  } // end line reader
  MyReadFile.close(); // Close the file
  cout << "Counter: " << counter << endl;


  //////////////////////// Plot:
  TCanvas *canvas = new TCanvas("canvas","");
  canvas->SetGrid();

  gPad->SetMargin(0.17,0.15,0.12,0.1);//l,r,b,t
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  string ss1 = "fake_rate_plots.pdf[";
  string ss2 = "fake_rate_plots.pdf";
  string ss3 = "fake_rate_plots.pdf]";

  TF1 *f_poisson = new TF1("f_poisson","[0]*[1]^x*exp(-[1])/TMath::Factorial(x)");
  f_poisson->SetParNames("N","lambda");
  f_poisson->SetParameters(1000,1);

  TF1 *f_gauss = new TF1("f_gauss","[0]*1/([1]*sqrt(2*TMath::Pi()))*exp(-0.5*((x-[2])/[1])^2)");
  f_gauss->SetParNames("N","sigma","mean");

  h_TL->Draw("hist h");
  h_TL->Fit("f_poisson");
  double mean_TL = f_poisson->GetParameter(1);
  double rms_TL  = f_poisson->GetParError(1);
  cout << "Fit TL: " << f_poisson->GetParameter(1) << " +/- " << f_poisson->GetParError(1) << endl;
  cout << "Fit TL chi2/ndf: " << f_poisson->GetChisquare()/f_poisson->GetNDF() << endl;
  h_TL->SetTitle("TL (Tight time)");
  h_TL->GetYaxis()->SetLabelSize(0.05);
  h_TL->GetXaxis()->SetLabelSize(0.05);
  h_TL->GetYaxis()->SetTitleSize(0.05);
  h_TL->GetXaxis()->SetTitleSize(0.05);
  canvas->SaveAs(ss1.c_str());
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  h_TT->Draw("hist h");
  h_TT->SetTitle("TT");
  h_TT->Fit("f_poisson");
  double mean_TT = f_poisson->GetParameter(1);
  double rms_TT  = f_poisson->GetParError(1);
  cout << "Fit TT: " << f_poisson->GetParameter(1) << " +/- " << f_poisson->GetParError(1) << endl;
  cout << "Fit TT chi2/ndf: " << f_poisson->GetChisquare()/f_poisson->GetNDF() << endl;
  h_TT->GetYaxis()->SetLabelSize(0.05);
  h_TT->GetXaxis()->SetLabelSize(0.05);
  h_TT->GetYaxis()->SetTitleSize(0.05);
  h_TT->GetXaxis()->SetTitleSize(0.05);
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  h_LT->Draw("hist h");
  h_LT->SetTitle("LT");
  f_gauss->SetParameters(1000,getMean(f_LT,n),getRMS(f_LT,n));
  h_LT->Fit("f_gauss");
  double mean_LT = f_gauss->GetParameter(2);
  double rms_LT  = f_gauss->GetParError(2);
  cout << "Fit LT: " << f_gauss->GetParameter(2) << " +/- " << f_gauss->GetParError(2) << endl;
  cout << "Fit LT chi2/ndf: " << f_gauss->GetChisquare()/f_gauss->GetNDF() << endl;
  h_LT->GetYaxis()->SetLabelSize(0.05);
  h_LT->GetXaxis()->SetLabelSize(0.05);
  h_LT->GetYaxis()->SetTitleSize(0.05);
  h_LT->GetXaxis()->SetTitleSize(0.05);
  canvas->SaveAs(ss2.c_str());
  canvas->Clear();

  h_LL->Draw("hist h");
  h_LL->SetTitle("LL");
  f_gauss->SetParameters(1000,getMean(f_LL,n),getRMS(f_LL,n));
  h_LL->Fit("f_gauss");
  double mean_LL = f_gauss->GetParameter(2);
  double rms_LL  = f_gauss->GetParError(2);
  cout << "Fit LL: " << f_gauss->GetParameter(2) << " +/- " << f_gauss->GetParError(2) << endl;
  cout << "Fit LL chi2/ndf: " << f_gauss->GetChisquare()/f_gauss->GetNDF() << endl;
  h_LL->GetYaxis()->SetLabelSize(0.05);
  h_LL->GetXaxis()->SetLabelSize(0.05);
  h_LL->GetYaxis()->SetTitleSize(0.05);
  h_LL->GetXaxis()->SetTitleSize(0.05);
  canvas->SaveAs(ss2.c_str());
  canvas->SaveAs(ss3.c_str());

  /////////////////////////////// fake rate calculation:
  ///// Tight calculation:
  double tight = mean_LT*mean_TL/mean_LL;
  double tight_err = sqrt( (rms_TL*mean_LT/mean_LL)*(rms_TL*mean_LT/mean_LL) + (rms_LT*mean_TL/mean_LL)*(rms_LT*mean_TL/mean_LL) + (mean_TL*mean_LT*rms_LL/(mean_LL*mean_LL))*(mean_TL*mean_LT*rms_LL/(mean_LL*mean_LL)) );
  cout << "Tight calculation: " << tight << " +/- " << tight_err << endl;
  cout << "Tight array: " << mean_TT << " +/- " << rms_TT << endl;

  ///// Fake rate calculation:
  // tight_err = 0.001;
  double A = 151.0;
  double B = 9990.0;
  double f_LK = A/B;
  double f_LK_e = sqrt((sqrt(A)/B)*(sqrt(A)/B) + (sqrt(B)*A/(B*B))*(sqrt(B)*A/(B*B)));
  // cout << "f_KL_e: " << f_LK_e << endl; // 0.00152206


  double fake_rate = f_LK*tight/mean_LL;
  double fake_rate_err = sqrt( (f_LK_e*tight/mean_LL)*(f_LK_e*tight/mean_LL) + (tight_err*f_LK/mean_LL)*(tight_err*f_LK/mean_LL) + (rms_LL*f_LK*tight/(mean_LL*mean_LL))*(rms_LL*f_LK*tight/(mean_LL*mean_LL)) );

  cout << "A: " << (f_LK_e*tight/mean_LL)*(f_LK_e*tight/mean_LL) << endl;
  cout << "B: " << (tight_err*f_LK/mean_LL)*(tight_err*f_LK/mean_LL) << endl;
  cout << "C: " << (rms_LL*f_LK*tight/(mean_LL*mean_LL))*(rms_LL*f_LK*tight/(mean_LL*mean_LL)) << endl;

  double fake_rate_test = f_LK*mean_TT/mean_LL;
  double fake_rate_err_test = sqrt( (f_LK_e*mean_TT/mean_LL)*(f_LK_e*mean_TT/mean_LL) + (rms_TT*f_LK/mean_LL)*(rms_TT*f_LK/mean_LL) + (rms_LL*f_LK*rms_TT/(mean_LL*mean_LL))*(rms_LL*f_LK*rms_TT/(mean_LL*mean_LL)) );

  cout << "Fake rate calculation: " << fake_rate      << " +/- " << fake_rate_err      << endl;
  cout << "Fake rate test: "        << fake_rate_test << " +/- " << fake_rate_err_test << endl;

}

double getMean(double arr[], int size){
    double sum = 0;
    double counter = 0;
    for(int i = 0; i<size;i++){
        counter ++;
        sum+=arr[i];
    }
    return sum/counter;
}

double getRMS(double arr[], int size){
    double sum = 0;
    double counter = 0;
    for(int i = 0; i<size;i++){
        counter ++;
        sum+=(arr[i]-getMean(arr,size))*(arr[i]-getMean(arr,size));
    }
    return sqrt(sum/counter);
}







//
