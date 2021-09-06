

void smearing(){
    auto h = new TH1D("h", "", 100, 0, 4000); // GeV
    auto pt_true = 3000.; // pT = 3 TeV
    double qoverpt_resolution = 10e-3; // GeV^-1
    for(int i=0;i<10000;i++){
        auto qoverpt = 1 / pt_true; // GeV^-1
        qoverpt += gRandom->Gaus(0., qoverpt_resolution); // Add gaussian noise
        auto pt_smeared = fabs(1 / qoverpt); // GeV // float absolute value
        h->Fill(pt_smeared);
    }
    h->Draw();
}
