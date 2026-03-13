#include "TH1F.h"
#include "TF1.h"
#include "TFile.h"
#include "TMath.h"
#include <iostream>

void write_hist() {
    TF1 *myFunc = new TF1("myFunc", "[0]*exp(-[1]*x) + [2]*TMath::Gaus(x, [3], [4])", 0, 10);
    myFunc->SetParameters(5555, 6.66, 777, 8.88, 0.99);

    TH1F *h1 = new TH1F("h_signal", "C++ task;Energy [GeV];Events", 100, 0, 10);
    h1->FillRandom("myFunc", 50000);

    TFile *file = new TFile("my_secret_data.root", "RECREATE");
    h1->Write();  
    file->Close(); 
}
