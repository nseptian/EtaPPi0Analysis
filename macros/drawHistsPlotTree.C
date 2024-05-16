const TString dirData = "/d/grid17/septian/GlueX_Data/tree_gggg__B4_FSRootFlat/";

const TString rootFileName = "sPlot_resetGammaIndex_GlueXI_GlueX2020_FidExclusive_tlt1_2DPi0EtaAC_2DLowPhotonAC_2DOmegaAC_2DEtaPrimeAC_DeltaCut.root";

void drawHistsPlotTree(){
    // open data
    cout << "Opening data file " << Form("%s%s",dirData.Data(),rootFileName.Data()) << endl;
    TFile* fData = new TFile(Form("%s%s",dirData.Data(),rootFileName.Data()),"READ");
    cout << "Data file opened" << endl;
    TTree* tree = (TTree*)fData->Get("ntFSGlueX_100_4000000");
    cout << "Tree ntFSGlueX_100_4000000 opened" << endl;

    // create histograms
    TH1D* hMassGamma23 = new TH1D("hMassGamma23","Mass #gamma_{2}#gamma_{3}",40,0.85,1.05);
    TH1D* hMassGamma24 = new TH1D("hMassGamma24","Mass #gamma_{2}#gamma_{4}",200,0,1.0);
    TH1D* hMassGamma25 = new TH1D("hMassGamma25","Mass #gamma_{2}#gamma_{5}",200,0,1.0);
    TH1D* hMassGamma34 = new TH1D("hMassGamma34","Mass #gamma_{3}#gamma_{4}",200,0,1.0);
    TH1D* hMassGamma35 = new TH1D("hMassGamma35","Mass #gamma_{3}#gamma_{5}",200,0,1.0);
    TH1D* hMassGamma45 = new TH1D("hMassGamma45","Mass #gamma_{4}#gamma_{5}",40,0.0,0.2);
    TH1D* hMissingMass = new TH1D("hMissingMass","Missing Mass",100,0,2);

    Double_t massGamma23;
    Double_t massGamma24;
    Double_t massGamma25;
    Double_t massGamma34;
    Double_t massGamma35;
    Double_t massGamma45;
    Double_t missingMass;

    tree->SetBranchAddress("massGamma2Gamma3",&massGamma23);
    tree->SetBranchAddress("massGamma2Gamma4",&massGamma24);
    tree->SetBranchAddress("massGamma2Gamma5",&massGamma25);
    tree->SetBranchAddress("massGamma3Gamma4",&massGamma34);
    tree->SetBranchAddress("massGamma3Gamma5",&massGamma35);
    tree->SetBranchAddress("massGamma4Gamma5",&massGamma45);
    tree->SetBranchAddress("missingMass",&missingMass);

    cout << "Processing " << tree->GetEntries() << " entries" << endl;

    for (Int_t iEntry=0;iEntry<tree->GetEntries();iEntry++) {
        tree->GetEntry(iEntry);
        hMassGamma23->Fill(massGamma23);
        hMassGamma24->Fill(massGamma24);
        hMassGamma25->Fill(massGamma25);
        hMassGamma34->Fill(massGamma34);
        hMassGamma35->Fill(massGamma35);
        hMassGamma45->Fill(massGamma45);
        hMissingMass->Fill(missingMass);
    }

    TCanvas* c1 = new TCanvas("c1","c1",800,600);
    c1->Divide(3,2);
    c1->cd(1);
    hMassGamma23->SetMinimum(0);
    hMassGamma23->Draw();
    c1->cd(2);
    hMassGamma24->Draw();
    c1->cd(3);
    hMassGamma25->Draw();
    c1->cd(4);
    hMassGamma34->Draw();
    c1->cd(5);
    hMassGamma35->Draw();
    c1->cd(6);
    hMassGamma45->Draw();
    c1->SaveAs("sPlotHistMassCombinations.pdf");

    TCanvas* c2 = new TCanvas("c2","c2",800,600);
    hMissingMass->GetXaxis()->SetRangeUser(-0.1,0.1);
    hMissingMass->GetXaxis()->SetTitle("Missing Mass Squared (GeV^{2})");
    hMissingMass->Draw();
    c2->SaveAs("sPlotHistMissingMass.pdf");
}