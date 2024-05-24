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
void DrawWithoutWeights();
void my_style();
TH1F* GetUnweightedEtaPrimeMassHistogram(TString inFileName, Int_t iBin);
TPad* GetsPlotFitPad(TString inFileName, TString binVarName, TString sPlotVarName, Int_t iBin);
void DrawsPlotFit();

void sPlotWithMass4GammaBins(){
    // DoFit();
    // my_style();
    // DrawWithoutWeights();
    // DrawsPlotFit();
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