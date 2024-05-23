const TString dirData = "/d/grid17/septian/GlueX_Data/tree_gggg__B4_FSRootFlat/";

const TString rootFileName = "sPlot_resetGammaIndex_GlueXI_GlueX2020_FidExclusive_tlt1_2DPi0EtaAC_2DLowPhotonAC_2DOmegaAC_2DEtaPrimeAC_DeltaCut.root";
// const TString rootFileName = "sPlot_resetGammaIndex_genr8_MC_GlueX2018S_FidExclusive_tlt1_2DPi0EtaAC_2DLowPhotonAC_2DOmegaAC_2DEtaPrimeAC_DeltaCut.root";
// const TString rootFileNamePhSpMC = "sPlot_resetGammaIndex_genr8_MC_GlueX2018S_PhSp_FidExclusive_tlt1_2DPi0EtaAC_2DLowPhotonAC_2DOmegaAC_2DEtaPrimeAC_DeltaCut.root";

void drawHistsPlotTree(){
    // open data
    cout << "Opening data file " << Form("%s%s",dirData.Data(),rootFileName.Data()) << endl;
    TFile* fData = new TFile(Form("%s%s",dirData.Data(),rootFileName.Data()),"READ");
    cout << "Data file opened" << endl;
    // TFile *fMC = new TFile(Form("%s%s",dirData.Data(),rootFileNamePhSpMC.Data()),"READ");
    TTree* tree = (TTree*)fData->Get("ntFSGlueX_100_4000000");
    cout << "Tree ntFSGlueX_100_4000000 opened" << endl;

    // create histograms
    TH1D* hMassGamma23 = new TH1D("hMassGamma23","m(#gamma_{2}#gamma_{3})",40,0.85,1.05);
    TH1D* hMassGamma24 = new TH1D("hMassGamma24","m(#gamma_{2}#gamma_{4})",200,0,1.0);
    TH1D* hMassGamma25 = new TH1D("hMassGamma25","m(#gamma_{2}#gamma_{5})",200,0,1.0);
    TH1D* hMassGamma34 = new TH1D("hMassGamma34","m(#gamma_{3}#gamma_{4})",200,0,1.0);
    TH1D* hMassGamma35 = new TH1D("hMassGamma35","m(#gamma_{3}#gamma_{5})",200,0,1.0);
    TH1D* hMassGamma45 = new TH1D("hMassGamma45","m(#gamma_{4}#gamma_{5})",40,0.0,0.2);
    TH1D* hMissingMassSq = new TH1D("hMissingMass","Missing Mass Squared",50,-0.001,0.001);

    Double_t MassGamma23;
    Double_t MassGamma24;
    Double_t MassGamma25;
    Double_t MassGamma34;
    Double_t MassGamma35;
    Double_t MassGamma45;
    Double_t MissingMassSq;

    tree->SetBranchAddress("MassGamma2Gamma3",&MassGamma23);
    tree->SetBranchAddress("MassGamma2Gamma4",&MassGamma24);
    tree->SetBranchAddress("MassGamma2Gamma5",&MassGamma25);
    tree->SetBranchAddress("MassGamma3Gamma4",&MassGamma34);
    tree->SetBranchAddress("MassGamma3Gamma5",&MassGamma35);
    tree->SetBranchAddress("MassGamma4Gamma5",&MassGamma45);
    tree->SetBranchAddress("MissingMassSq",&MissingMassSq);

    cout << "Processing " << tree->GetEntries() << " entries" << endl;

    for (Int_t iEntry=0;iEntry<tree->GetEntries();iEntry++) {
        tree->GetEntry(iEntry);
        hMassGamma23->Fill(MassGamma23);
        hMassGamma24->Fill(MassGamma24);
        hMassGamma25->Fill(MassGamma25);
        hMassGamma34->Fill(MassGamma34);
        hMassGamma35->Fill(MassGamma35);
        hMassGamma45->Fill(MassGamma45);
        hMissingMassSq->Fill(MissingMassSq);
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
    hMissingMassSq->GetXaxis()->SetTitle("Missing Mass Squared (GeV^{2})");
    hMissingMassSq->Draw();
    c2->SaveAs("sPlotHistMissingMass.pdf");
}