#include "TFile.h"
#include "TH1F.h"
#include "TCanvas.h"
#include <iostream>

void read_hist() {
    TFile *file = new TFile("my_secret_data.root", "READ");
    
    if (!file || file->IsZombie()) {
        std::cerr << "Error: could not open file!" << std::endl;
        return;
    }

    TH1F *h1_read = (TH1F*)file->Get("h_signal");

    TCanvas *c1 = new TCanvas("c1", "C-task", 800, 600);
    
    h1_read->SetLineColor(kBlue + 1);
    h1_read->SetFillColor(kCyan - 9);
    h1_read->SetLineWidth(2);
    
    h1_read->Draw();
    h1_read->SetDirectory(0); 
    
    c1->SaveAs("my_graph.png");
    
    file->Close();
}
