// run: brufit -b -x -q sPlotEtaPrimeRangeVar.C

// make 5 different fits with different ranges of eta prime mass

const Int_t NFits = 5;
sPlot RF[NFits];
Double_t etaPMassRangeLowLim[NFits] = {0.85, 0.86, 0.87, 0.88, 0.89};
Double_t etaPMassRangeUpLim[NFits] = {1.05, 1.06, 1.07, 1.08, 1.09};

const TString dataDir = "/d/grid17/septian/GlueX_Data/tree_gggg__B4_FSRootFlat/";
const TString rootFile = "sPlot_resetGammaIndex_GlueXI_GlueX2020_FidExclusive_tlt1_2DPi0EtaAC_2DLowPhotonAC_2DOmegaAC_2DEtaPrimeAC_DeltaCut.root";
const TString outDir = "sPlotEtaPrimeRangeVar/";
const TString baseResultDir = "var";

void DoFit();
void DrawWithWeights(TString inFileName, TString weightFileName, Int_t iVar=0);
void my_style();

void sPlotEtaPrimeRangeVar(){
    // DoFit();
    TString inFileName = Form("%s%s",dataDir.Data(),rootFile.Data());
    for (Int_t iVar=2;iVar<NFits;iVar++) {
        TString weightFileName = Form("%s%s_%d/Weights.root",outDir.Data(),baseResultDir.Data(),iVar);
        DrawWithWeights(inFileName,weightFileName,iVar);
    }
}

void DoFit(){
    for (Int_t i = 0; i < NFits; i++){
        RF[i].SetUp().SetOutDir(Form("%s%s_%d/",outDir.Data(),baseResultDir.Data(),i));
        RF[i].SetUp().LoadVariable(Form("MassGamma2Gamma3[%f,%f]",etaPMassRangeLowLim[i],etaPMassRangeUpLim[i]));
        RF[i].SetUp().SetIDBranchName("UID");
        RF[i].SetUp().FactoryPDF(Form("Gaussian::Signal(MassGamma2Gamma3,mean[0.958,0.950,0.964],sigma[0.014,0.001,0.2])"));
        RF[i].SetUp().LoadSpeciesPDF("Signal",1);
        RF[i].SetUp().FactoryPDF("Chebychev::BG(MassGamma2Gamma3,{a0[-0.1,-1,1],a1[0.1,-1,1],a2[0.1,-1,1]})");
        RF[i].SetUp().LoadSpeciesPDF("BG",1);
        RF[i].LoadData("ntFSGlueX_100_4000000",Form("%s%s",dataDir.Data(),rootFile.Data()));
        Here::Go(&RF[i]);
        RF[i].DeleteWeightedTree();
    }
}

void DrawWithWeights(TString inFileName, TString weightFileName, Int_t iVar=0){
    my_style(); 
    Weights* wts = new Weights("Weights");

    cout << "Loading weights from " << weightFileName << endl;
    wts->LoadSaved(weightFileName,"HSsWeights");

    TChain chain("ntFSGlueX_100_4000000");

    cout << "Adding file " << inFileName << " to the chain" << endl;
    chain.Add(inFileName);

    Double_t UID;
    Double_t Mass2Gamma[6];
    Double_t Mass4Gamma;
    Double_t MassPi0Gamma1;
    Double_t MassPi0Gamma2;
    TLorentzVector P4_Gamma_Measured[4];
    TLorentzVector P4_Gamma_KinFit[4];
    TLorentzVector P4_RecoilProton;
    TLorentzVector P4_TargetProton = TLorentzVector(0,0,0,0.938272);

    chain.SetBranchAddress("UID",&UID);
    chain.SetBranchAddress("MassGamma2Gamma3",&Mass2Gamma[0]);
    chain.SetBranchAddress("MassGamma2Gamma4",&Mass2Gamma[1]);
    chain.SetBranchAddress("MassGamma2Gamma5",&Mass2Gamma[2]);
    chain.SetBranchAddress("MassGamma3Gamma4",&Mass2Gamma[3]);
    chain.SetBranchAddress("MassGamma3Gamma5",&Mass2Gamma[4]);
    chain.SetBranchAddress("MassGamma4Gamma5",&Mass2Gamma[5]);
    chain.SetBranchAddress("Mass4Gamma",&Mass4Gamma);
    chain.SetBranchAddress("MassPi0Gamma1",&MassPi0Gamma1);
    chain.SetBranchAddress("MassPi0Gamma2",&MassPi0Gamma2);

    TH1F *h1_MassGamma2Gamma3 = new TH1F("h1_MassGamma2Gamma3","m(#gamma_{2}#gamma_{3})",40,0.85,1.05);
    TH1F *h1_MassGamma2Gamma4 = new TH1F("h1_MassGamma2Gamma4","m(#gamma_{2}#gamma_{4})",200,0,1.0);
    TH1F *h1_MassGamma2Gamma5 = new TH1F("h1_MassGamma2Gamma5","m(#gamma_{2}#gamma_{5})",200,0,1.0);
    TH1F *h1_MassGamma3Gamma4 = new TH1F("h1_MassGamma3Gamma4","m(#gamma_{3}#gamma_{4})",200,0,1.0);
    TH1F *h1_MassGamma3Gamma5 = new TH1F("h1_MassGamma3Gamma5","m(#gamma_{3}#gamma_{5})",200,0,1.0);
    TH1F *h1_MassGamma4Gamma5 = new TH1F("h1_MassGamma4Gamma5","m(#gamma_{4}#gamma_{5})",40,0.0,0.2);
    TH1F *h1_Mass4Gamma_Signal = new TH1F("h1_Mass4Gamma_Signal","m_{4#gamma}",50,1.0,3.0);
    TH1F *h1_Mass4Gamma_BG = new TH1F("h1_Mass4Gamma_BG","m_{4#gamma}",50,1.0,3.0);
    TH1F *h1_MassPi0Gamma1 = new TH1F("h1_MassPi0Gamma1","m(#pi^{0}#gamma_{2})",100,0.0,3.0);
    TH1F *h1_MassPi0Gamma2 = new TH1F("h1_MassPi0Gamma2","m(#pi^{0}#gamma_{3})",100,0.0,3.0);

    cout << "Processing " << chain.GetEntries() << " entries" << endl;
    cout << "Filling histograms..." << endl;

    for (Int_t iEntry=0;iEntry<chain.GetEntries();iEntry++){
        chain.GetEntry(iEntry);
        if(wts->GetEntryBinarySearch(UID)){
            Double_t sigweight = wts->GetWeight("Signal");
            Double_t bkgweight = wts->GetWeight("BG");
            
            // cout << UID << " " << weight << endl;
            h1_MassGamma2Gamma3->Fill(Mass2Gamma[0],sigweight);
            h1_MassGamma2Gamma4->Fill(Mass2Gamma[1],sigweight);
            h1_MassGamma2Gamma5->Fill(Mass2Gamma[2],sigweight);
            h1_MassGamma3Gamma4->Fill(Mass2Gamma[3],sigweight);
            h1_MassGamma3Gamma5->Fill(Mass2Gamma[4],sigweight);
            h1_MassGamma4Gamma5->Fill(Mass2Gamma[5],sigweight);
            h1_Mass4Gamma_Signal->Fill(Mass4Gamma,sigweight);
            h1_Mass4Gamma_BG->Fill(Mass4Gamma,bkgweight);
            h1_MassPi0Gamma1->Fill(MassPi0Gamma1,sigweight);
            h1_MassPi0Gamma2->Fill(MassPi0Gamma2,sigweight);
        }
    }

    TCanvas *c_Mass2Gamma = new TCanvas("c_Mass2Gamma","c_Mass2Gamma",1600,800);
    c_Mass2Gamma->Divide(3,2);
    c_Mass2Gamma->cd(1);
    h1_MassGamma2Gamma3->GetXaxis()->SetTitle("m(#gamma_{2}#gamma_{3}) [GeV]");
    h1_MassGamma2Gamma3->GetYaxis()->SetTitle(Form("Events/%.3f GeV",h1_MassGamma2Gamma3->GetBinWidth(1)));
    h1_MassGamma2Gamma3->Draw();
    c_Mass2Gamma->cd(2);
    h1_MassGamma2Gamma4->GetXaxis()->SetTitle("m(#gamma_{2}#gamma_{4}) [GeV]");
    h1_MassGamma2Gamma4->GetYaxis()->SetTitle(Form("Events/%.3f GeV",h1_MassGamma2Gamma4->GetBinWidth(1)));
    h1_MassGamma2Gamma4->Draw();
    c_Mass2Gamma->cd(3);
    h1_MassGamma2Gamma5->GetXaxis()->SetTitle("m(#gamma_{2}#gamma_{5}) [GeV]");
    h1_MassGamma2Gamma5->GetYaxis()->SetTitle(Form("Events/%.3f GeV",h1_MassGamma2Gamma5->GetBinWidth(1)));
    h1_MassGamma2Gamma5->Draw();
    c_Mass2Gamma->cd(4);
    h1_MassGamma3Gamma4->GetXaxis()->SetTitle("m(#gamma_{3}#gamma_{4}) [GeV]");
    h1_MassGamma3Gamma4->GetYaxis()->SetTitle(Form("Events/%.3f GeV",h1_MassGamma3Gamma4->GetBinWidth(1)));
    h1_MassGamma3Gamma4->Draw();
    c_Mass2Gamma->cd(5);
    h1_MassGamma3Gamma5->GetXaxis()->SetTitle("m(#gamma_{3}#gamma_{5}) [GeV]");
    h1_MassGamma3Gamma5->GetYaxis()->SetTitle(Form("Events/%.3f GeV",h1_MassGamma3Gamma5->GetBinWidth(1)));
    h1_MassGamma3Gamma5->Draw();
    c_Mass2Gamma->cd(6);
    h1_MassGamma4Gamma5->GetXaxis()->SetTitle("m(#gamma_{4}#gamma_{5}) [GeV]");
    h1_MassGamma4Gamma5->GetYaxis()->SetTitle(Form("Events/%.3f GeV",h1_MassGamma4Gamma5->GetBinWidth(1)));
    h1_MassGamma4Gamma5->Draw();
    c_Mass2Gamma->SaveAs(Form("%s%s_%d/Mass2Gamma_SG_hist.pdf",outDir.Data(),baseResultDir.Data(),iVar));

    TCanvas *c_Mass4Gamma = new TCanvas("c_Mass4Gamma","c_Mass4Gamma",1000,800);
    c_Mass4Gamma->Divide(1,2);
    c_Mass4Gamma->cd(1);
    h1_Mass4Gamma_Signal->GetXaxis()->SetTitle("m_{4#gamma} [GeV])");
    h1_Mass4Gamma_Signal->GetYaxis()->SetTitle(Form("Events/%.3f GeV",h1_Mass4Gamma_Signal->GetBinWidth(1)));
    h1_Mass4Gamma_Signal->SetTitle("sWeighted m_{4#gamma} Signal");
    h1_Mass4Gamma_Signal->Draw();
    c_Mass4Gamma->cd(2);
    h1_Mass4Gamma_BG->GetXaxis()->SetTitle("m_{4#gamma} [GeV])");
    h1_Mass4Gamma_BG->GetYaxis()->SetTitle(Form("Events/%.3f GeV",h1_Mass4Gamma_BG->GetBinWidth(1)));
    h1_Mass4Gamma_BG->SetTitle("sWeighted m_{4#gamma} Background");
    h1_Mass4Gamma_BG->Draw();
    c_Mass4Gamma->SaveAs(Form("%s%s_%d/Mass4Gamma_SG_BG_hist.pdf",outDir.Data(),baseResultDir.Data(),iVar));

    // delete all objects on the heap
    delete h1_MassGamma2Gamma3;
    delete h1_MassGamma2Gamma4;
    delete h1_MassGamma2Gamma5;
    delete h1_MassGamma3Gamma4;
    delete h1_MassGamma3Gamma5;
    delete h1_MassGamma4Gamma5;
    delete h1_Mass4Gamma_Signal;
    delete h1_Mass4Gamma_BG;
    delete h1_MassPi0Gamma1;
    delete h1_MassPi0Gamma2;
    delete c_Mass2Gamma;
    delete c_Mass4Gamma;
    delete wts;
}

// Make a TStyle for the plots to look like a paper quality plots
void my_style(){
    gStyle->SetOptStat(0);
    gStyle->SetLabelSize(0.05,"X");
    gStyle->SetLabelSize(0.05,"Y");
    gStyle->SetTitleSize(0.05,"X");
    gStyle->SetTitleSize(0.05,"Y");
    gStyle->SetTitleOffset(1.0,"X");
    gStyle->SetTitleOffset(1.0,"Y");
    gStyle->SetPadLeftMargin(0.15);
    gStyle->SetPadRightMargin(0.05);
    gStyle->SetPadTopMargin(0.1);
    gStyle->SetPadBottomMargin(0.15);
    gStyle->SetHistLineWidth(2);
}