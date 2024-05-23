// Description: brufit macro to run sPlot fit with 4 gamma mass invariant mass bin
// Run: brufit -b -x- -q sPlotWithMass4GammaBins.C

const TString dataDir = "/d/grid17/septian/GlueX_Data/tree_gggg__B4_FSRootFlat/";
const TString rootFile = "sPlot_resetGammaIndex_GlueXI_GlueX2020_FidExclusive_tlt1_2DPi0EtaAC_2DLowPhotonAC_2DOmegaAC_2DEtaPrimeAC_DeltaCut.root";
const TString binnedRootFileName = "TreeData.root";
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

void sPlotWithMass4GammaBins(){
    DoFit();
    // my_style();
    // DrawWithoutWeights();
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