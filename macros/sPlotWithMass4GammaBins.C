// Description: brufit macro to run sPlot fit with 4 gamma mass invariant mass bin
// Run: brufit -b -x- -q sPlotWithMass4GammaBins.C

const TString dataDir = "/d/grid17/septian/GlueX_Data/tree_gggg__B4_FSRootFlat/";
const TString rootFile = "sPlot_resetGammaIndex_GlueXI_GlueX2020_FidExclusive_tlt1_2DPi0EtaAC_2DLowPhotonAC_2DOmegaAC_2DEtaPrimeAC_DeltaCut.root";
const TString binnedRootFileName = "TreeData.root";
const TString binnedResultsFileName = "ResultsHSMinuit2.root";
const TString outDir = "sPlotWithMass4GammaBin/";
const Int_t NMass4GammaBins = 17;
const Double_t Mass4GammaLowLim = 1.3;
const Double_t Mass4GammaUpLim = 3.0;

sPlot RF;

void DoFit();
void DrawWithWeights(TString weightFileName);
void DrawWithoutWeights(TString inFileName, TString weightFileName, Int_t iVar=0);
void my_style();
TH1F* GetUnweightedEtaPrimeMassHistogram(TString inFileName, Int_t iBin);
TPad* GetsPlotFitPad(TString inFileName, TString binVarName, TString sPlotVarName, Int_t iBin);
void DrawsPlotFit();

void sPlotWithMass4GammaBins(){
    // my_style();
    // DoFit();
    // DrawWithoutWeights();
    // DrawsPlotFit();
    DrawWithWeights(Form("%s%s",dataDir.Data(),rootFile.Data()));
}

void DoFit(){
    RF.SetUp().SetOutDir(outDir);
    RF.SetUp().LoadVariable("MassGamma2Gamma3[0.86,1.06]");
    RF.SetUp().SetIDBranchName("UID");
    RF.SetUp().FactoryPDF("Gaussian::Signal(MassGamma2Gamma3,mean[0.958,0.950,0.964],sigma[0.014,0.001,0.2])");
    RF.SetUp().LoadSpeciesPDF("Signal",1);
    RF.SetUp().FactoryPDF("Chebychev::BG(MassGamma2Gamma3,{a0[-0.1,-1,1],a1[0.1,-1,1],a2[0.1,-1,1]})");
    RF.SetUp().LoadSpeciesPDF("BG",1);
    RF.Bins().LoadBinVar("Mass4Gamma",20,1.0,3.0);
    RF.LoadData("ntFSGlueX_100_4000000",Form("%s%s",dataDir.Data(),rootFile.Data()));
    Here::Go(&RF);
    RF.DeleteWeightedTree();
}

void DrawWithoutWeights(){
    // vector<TString> binDir;
    TH1F* h_etaPrimeMass[NMass4GammaBins];
    for (Int_t iBin=0;iBin<NMass4GammaBins;iBin++){
        Double_t centerBin = Mass4GammaLowLim + (Mass4GammaUpLim - Mass4GammaLowLim)/NMass4GammaBins*(iBin+0.5);
        // binDir.push_back(Form("%sMass4Gamma%1.2f_",outDir.Data(),centerBin));
        TString binDir = Form("%sMass4Gamma%1.2f_",outDir.Data(),centerBin);
        // cout << "Results directory bin-" << iBin+1 << ": " << binDir[iBin] << endl;
        TString inFileName = Form("%s/%s",binDir.Data(),binnedRootFileName.Data());
        h_etaPrimeMass[iBin] = GetUnweightedEtaPrimeMassHistogram(inFileName,iBin);
    }
    TCanvas *c = new TCanvas("c","c",1600,800);
    c->Divide(5,4,0.001,0.001);
    for (Int_t iBin=0;iBin<NMass4GammaBins;iBin++){
        c->cd(iBin+1);
        h_etaPrimeMass[iBin]->GetXaxis()->SetTitle("m_{#eta'} [GeV]");
        h_etaPrimeMass[iBin]->GetYaxis()->SetTitle(Form("Events/%1.2f MeV",(Mass4GammaUpLim-Mass4GammaLowLim)/NMass4GammaBins*1000));
        h_etaPrimeMass[iBin]->SetTitle(Form("m_{4#gamma} = [%1.2f,%1.2f] GeV",Mass4GammaLowLim + (Mass4GammaUpLim - Mass4GammaLowLim)/NMass4GammaBins*iBin,Mass4GammaLowLim + (Mass4GammaUpLim - Mass4GammaLowLim)/NMass4GammaBins*(iBin+1)));
        h_etaPrimeMass[iBin]->SetLineColor(kBlack);
        h_etaPrimeMass[iBin]->Draw();
    }
    c->SaveAs(Form("%sEtaPrimeMass.pdf",outDir.Data())); 
}

void DrawsPlotFit(){
    TPad *pad_sPlot[NMass4GammaBins];
    for (Int_t iBin=0;iBin<NMass4GammaBins;iBin++){
        Double_t centerBin = Mass4GammaLowLim + (Mass4GammaUpLim - Mass4GammaLowLim)/NMass4GammaBins*(iBin+0.5);
        TString binDir = Form("%sMass4Gamma%1.2f_",outDir.Data(),centerBin);
        TString inFileName = Form("%s/%s",binDir.Data(),binnedResultsFileName.Data());
        // pad_sPlot[iBin] = GetsPlotFitPad(Form("%sMass4Gamma1.45_/%s",outDir.Data(),binnedResultsFileName.Data()),"Mass4Gamma1.45","MassGamma2Gamma3");
        pad_sPlot[iBin] = (TPad*)GetsPlotFitPad(inFileName,Form("Mass4Gamma%1.2f",centerBin),"MassGamma2Gamma3",iBin)->Clone();
    }
    TCanvas *c = new TCanvas("c","c",1600,800);
    c->Divide(5,4,0.001,0.001);
    for (Int_t iBin=0;iBin<NMass4GammaBins;iBin++){
        c->cd(iBin+1);
        pad_sPlot[iBin]->Draw();
        pad_sPlot[iBin]->SetPad(0.01,0.01,0.99,0.99);
    }
    c->SaveAs(Form("%ssPlotWithMass4GammaBins_EtaPrimeMassFit.pdf",outDir.Data()));
}

TH1F* GetUnweightedEtaPrimeMassHistogram(TString inFileName, Int_t iBin){
    TChain chain("ntFSGlueX_100_4000000");
    chain.Add(inFileName);
    TH1F* h_etaPrimeMass = new TH1F(Form("h_etaPrimeMass_%d",iBin),Form("h_etaPrimeMass_%d",iBin),100,0.86,1.06);
    Double_t MassGamma2Gamma3;
    chain.SetBranchAddress("MassGamma2Gamma3",&MassGamma2Gamma3);
    for (Int_t iEntry=0;iEntry<chain.GetEntries();iEntry++){
        chain.GetEntry(iEntry);
        h_etaPrimeMass->Fill(MassGamma2Gamma3);
    }
    return h_etaPrimeMass;
}

TPad* GetsPlotFitPad(TString inFileName, TString binVarName, TString sPlotVarName, Int_t iBin){
    TFile *f = new TFile(inFileName);
    TCanvas *c = (TCanvas*)f->Get(Form("%s__%s",binVarName.Data(),sPlotVarName.Data()));
    // TList *list = c->GetListOfPrimitives();
    // TIter next(list);
    // TObject *obj;
    // while ((obj = next())) {
    //     cout << "Name: " << obj->GetName() << ", Class: " << obj->ClassName() << endl;
    // }

    // create pad on the heap
    TPad *pad = (TPad*)c->GetListOfPrimitives()->At(0);
    // TList *listPad = pad->GetListOfPrimitives();
    // TIter nextPad(listPad);
    // TObject *objPad;
    // while ((objPad = nextPad())) {
    //     cout << "Name: " << objPad->GetName() << ", Class: " << objPad->ClassName() << endl;
    // }

    TH1D *h1_Mass2Gamma = (TH1D*)pad->GetListOfPrimitives()->At(1);
    h1_Mass2Gamma->GetXaxis()->SetTitle("m_{#eta'} [GeV]");
    h1_Mass2Gamma->SetTitle(Form("m_{4#gamma} = [%1.2f,%1.2f] GeV",Mass4GammaLowLim + (Mass4GammaUpLim - Mass4GammaLowLim)/NMass4GammaBins*iBin,Mass4GammaLowLim + (Mass4GammaUpLim - Mass4GammaLowLim)/NMass4GammaBins*(iBin+1)));
    h1_Mass2Gamma->SetTitleSize(0.07,"X");
    h1_Mass2Gamma->SetTitleSize(0.07,"Y");
    h1_Mass2Gamma->SetTitleOffset(1.0,"X");
    h1_Mass2Gamma->SetTitleOffset(1.0,"Y");
    h1_Mass2Gamma->SetLabelSize(0.05,"X");
    h1_Mass2Gamma->SetLabelSize(0.05,"Y");
    h1_Mass2Gamma->SetLabelOffset(0.02,"X");

    // remove Parambox
    TObject *objParamBox = pad->GetListOfPrimitives()->At(6);
    pad->GetListOfPrimitives()->Remove(objParamBox);
    // save pad in pdf
    // pad->SaveAs(Form("%s.pdf",inFileName.Data()));

    return pad;
}

void DrawWithWeights(TString inFileName){
    my_style();

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
    TH1F *h1_MassPi0Gamma1_Signal = new TH1F("h1_MassPi0Gamma1_Signal","m(#pi^{0}#gamma_{2})",100,0.0,3.0);
    TH1F *h1_MassPi0Gamma2_Signal = new TH1F("h1_MassPi0Gamma2_Signal","m(#pi^{0}#gamma_{3})",100,0.0,3.0);
    TH1F *h1_MassPi0Gamma1_BG = new TH1F("h1_MassPi0Gamma1_BG","m(#pi^{0}#gamma_{2})",100,0.0,3.0);
    TH1F *h1_MassPi0Gamma2_BG = new TH1F("h1_MassPi0Gamma2_BG","m(#pi^{0}#gamma_{3})",100,0.0,3.0);

    cout << "Processing " << chain.GetEntries() << " entries" << endl;
    cout << "Filling histograms..." << endl;

    Weights *wts[NMass4GammaBins];

    for (Int_t iBin=0;iBin<NMass4GammaBins;iBin++){
        Double_t centerBin = Mass4GammaLowLim + (Mass4GammaUpLim - Mass4GammaLowLim)/NMass4GammaBins*(iBin+0.5);
        TString weightFileName = Form("%sWeightsMass4Gamma%1.2f_.root",outDir.Data(),centerBin);
        wts[iBin] = new Weights("Weights");
        cout << "Loading weights from " << weightFileName << endl;
        wts[iBin]->LoadSaved(weightFileName,"HSsWeights");
        for (Int_t iEntry=0;iEntry<chain.GetEntries();iEntry++){
            chain.GetEntry(iEntry);
            if(wts[iBin]->GetEntryBinarySearch(UID)){
                Double_t sigweight = wts[iBin]->GetWeight("Signal");
                Double_t bkgweight = wts[iBin]->GetWeight("BG");

                // cout << UID << " " << weight << endl;
                h1_MassGamma2Gamma3->Fill(Mass2Gamma[0],sigweight);
                h1_MassGamma2Gamma4->Fill(Mass2Gamma[1],sigweight);
                h1_MassGamma2Gamma5->Fill(Mass2Gamma[2],sigweight);
                h1_MassGamma3Gamma4->Fill(Mass2Gamma[3],sigweight);
                h1_MassGamma3Gamma5->Fill(Mass2Gamma[4],sigweight);
                h1_MassGamma4Gamma5->Fill(Mass2Gamma[5],sigweight);
                h1_Mass4Gamma_Signal->Fill(Mass4Gamma,sigweight);
                h1_Mass4Gamma_BG->Fill(Mass4Gamma,bkgweight);
                h1_MassPi0Gamma1_Signal->Fill(MassPi0Gamma1,sigweight);
                h1_MassPi0Gamma2_Signal->Fill(MassPi0Gamma2,sigweight);
                h1_MassPi0Gamma1_BG->Fill(MassPi0Gamma1,bkgweight);
                h1_MassPi0Gamma2_BG->Fill(MassPi0Gamma2,bkgweight);
            }
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
    c_Mass2Gamma->SaveAs(Form("%sMass2Gamma_SG_hist.pdf",outDir.Data()));

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
    c_Mass4Gamma->SaveAs(Form("%sMass4Gamma_SG_BG_hist.pdf",outDir.Data()));

    TCanvas *c_MassPi0Gamma1 = new TCanvas("c_MassPi0Gamma1","c_MassPi0Gamma1",1000,800);
    c_MassPi0Gamma1->Divide(1,2);
    c_MassPi0Gamma1->cd(1);
    h1_MassPi0Gamma1_Signal->GetXaxis()->SetTitle("m(#pi^{0}#gamma_{2}) [GeV])");
    h1_MassPi0Gamma1_Signal->GetYaxis()->SetTitle(Form("Events/%.3f GeV",h1_MassPi0Gamma1_Signal->GetBinWidth(1)));
    h1_MassPi0Gamma1_Signal->SetTitle("sWeighted m(#pi^{0}#gamma_{2}) Signal");
    h1_MassPi0Gamma1_Signal->Draw();
    c_MassPi0Gamma1->cd(2);
    h1_MassPi0Gamma1_BG->GetXaxis()->SetTitle("m(#pi^{0}#gamma_{2}) [GeV])");
    h1_MassPi0Gamma1_BG->GetYaxis()->SetTitle(Form("Events/%.3f GeV",h1_MassPi0Gamma1_BG->GetBinWidth(1)));
    h1_MassPi0Gamma1_BG->SetTitle("sWeighted m(#pi^{0}#gamma_{2}) Background");
    h1_MassPi0Gamma1_BG->Draw();
    c_MassPi0Gamma1->SaveAs(Form("%sMassPi0Gamma1_SG_BG_hist.pdf",outDir.Data()));

    TCanvas *c_MassPi0Gamma2 = new TCanvas("c_MassPi0Gamma2","c_MassPi0Gamma2",1000,800);
    c_MassPi0Gamma2->Divide(1,2);
    c_MassPi0Gamma2->cd(1);
    h1_MassPi0Gamma2_Signal->GetXaxis()->SetTitle("m(#pi^{0}#gamma_{3}) [GeV])");
    h1_MassPi0Gamma2_Signal->GetYaxis()->SetTitle(Form("Events/%.3f GeV",h1_MassPi0Gamma2_Signal->GetBinWidth(1)));
    h1_MassPi0Gamma2_Signal->SetTitle("sWeighted m(#pi^{0}#gamma_{3}) Signal");
    h1_MassPi0Gamma2_Signal->Draw();
    c_MassPi0Gamma2->cd(2);
    h1_MassPi0Gamma2_BG->GetXaxis()->SetTitle("m(#pi^{0}#gamma_{3}) [GeV])");
    h1_MassPi0Gamma2_BG->GetYaxis()->SetTitle(Form("Events/%.3f GeV",h1_MassPi0Gamma2_BG->GetBinWidth(1)));
    h1_MassPi0Gamma2_BG->SetTitle("sWeighted m(#pi^{0}#gamma_{3}) Background");
    h1_MassPi0Gamma2_BG->Draw();
    c_MassPi0Gamma2->SaveAs(Form("%sMassPi0Gamma2_SG_BG_hist.pdf",outDir.Data()));

    // delete all objects on the heap
    delete h1_MassGamma2Gamma3;
    delete h1_MassGamma2Gamma4;
    delete h1_MassGamma2Gamma5;
    delete h1_MassGamma3Gamma4;
    delete h1_MassGamma3Gamma5;
    delete h1_MassGamma4Gamma5;
    delete h1_Mass4Gamma_Signal;
    delete h1_Mass4Gamma_BG;
    delete h1_MassPi0Gamma1_Signal;
    delete h1_MassPi0Gamma2_Signal;
    delete h1_MassPi0Gamma1_BG;
    delete h1_MassPi0Gamma2_BG;
    delete c_Mass2Gamma;
    delete c_Mass4Gamma;
    delete c_MassPi0Gamma1;
    delete c_MassPi0Gamma2;
    // delete wts[NMass4GammaBins];    
}

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