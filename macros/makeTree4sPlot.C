const TString dirData = "/d/grid17/septian/GlueX_Data/tree_gggg__B4_FSRootFlat/";
const TString baseFileName = "resetGammaIndex_GlueXI_GlueX2020_FidExclusive_tlt1_2DPi0EtaAC_2DLowPhotonAC_2DOmegaAC_2DEtaPrimeAC_DeltaCut.root";
const TString treeName = "ntFSGlueX_100_4000000";
const TString outName = "sPlot_resetGammaIndex_GlueXI_GlueX2020_FidExclusive_tlt1_2DPi0EtaAC_2DLowPhotonAC_2DOmegaAC_2DEtaPrimeAC_DeltaCut.root";

void makeTree4sPlot(){
    // open data
    TFile* fData = new TFile(Form("%s%s",dirData.Data(),baseFileName.Data()),"READ");
    TTree* tree = (TTree*)fData->Get(treeName.Data());

    // create output file
    TFile* fOut = new TFile(Form("%s%s",dirData.Data(),outName.Data()),"RECREATE");

    TTree* outTree = tree->CloneTree();

    Int_t vectorIndexCombination[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
    Double_t mass[6];

    for (Int_t iMass=0;iMass<6;iMass++){
        outTree->Branch(Form("massGamma%dGamma%d",vectorIndexCombination[iMass][0],vectorIndexCombination[iMass][1]),&mass[iMass],Form("massGamma%dGamma%d/D",vectorIndexCombination[iMass][0],vectorIndexCombination[iMass][1]));
    }

    for (Int_t iGammaIndex=2;iGammaIndex<=5;iGammaIndex++) {
        outTree->SetBranchStatus("*",0);
        outTree->SetBranchStatus(Form("PxP%d",iGammaIndex),1);
        outTree->SetBranchStatus(Form("PyP%d",iGammaIndex),1);
        outTree->SetBranchStatus(Form("PzP%d",iGammaIndex),1);
        outTree->SetBranchStatus(Form("EnP%d",iGammaIndex),1);
    }

    TLorentzVector p_gamma[4];

    for (Int_t iEntry=0;iEntry<outTree->GetEntries();iEntry++) {
        outTree->GetEntry(iEntry);
        
        for (Int_t iGammaIndex=2;iGammaIndex<=5;iGammaIndex++){            
            p_gamma[iGammaIndex-2].SetPxPyPzE(outTree->GetLeaf(Form("PxP%d",iGammaIndex))->GetValue(),
                                              outTree->GetLeaf(Form("PyP%d",iGammaIndex))->GetValue(),
                                              outTree->GetLeaf(Form("PzP%d",iGammaIndex))->GetValue(),
                                              outTree->GetLeaf(Form("EnP%d",iGammaIndex))->GetValue());
        }

        for (Int_t iMass=0;iMass<6;iMass++){
            mass[iMass] = (p_gamma[vectorIndexCombination[iMass][0]-2] + p_gamma[vectorIndexCombination[iMass][1]-2]).M();
        }

        outTree->Fill();
    }

    fOut->Write();
    fOut->Close();
    fData->Close();

}