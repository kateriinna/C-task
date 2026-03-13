#include "TFile.h"
#include "TH1F.h"
#include "TCanvas.h"
#include <iostream>

void read_vlada() {
    TFile *file = new TFile("vlada_ABCDE.root", "READ");
    
    if (!file || file->IsZombie()) {
        std::cerr << "Error: could not open file!" << std::endl;
        return;
    }

    TH1F *h1_read = (TH1F*)file->Get("vlada_hist");

    if (!h1_read) {
        std::cerr << "Error: histogram not found!" << std::endl;
        file->Close();
        return;
    }

    TCanvas *c1 = new TCanvas("c1", "Vlada's Histogram Canvas", 800, 600);
    
    h1_read->SetLineColor(kRed + 1);
    h1_read->SetFillColor(kYellow - 9);
    h1_read->SetLineWidth(2);
    
    h1_read->Draw();
    h1_read->SetDirectory(0); 
    
    c1->SaveAs("vlada_graph.png");
    
    file->Close();
}
