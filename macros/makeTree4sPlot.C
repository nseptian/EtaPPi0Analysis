const TString dirData = "/d/grid17/septian/GlueX_Data/tree_gggg__B4_FSRootFlat/";
const TString baseFileName = "resetGammaIndex_GlueXI_GlueX2020_FidExclusive_tlt1_2DPi0EtaAC_2DLowPhotonAC_2DOmegaAC_2DEtaPrimeAC_DeltaCut.root";
// const TString baseFileName = "skimmedTree_GlueXI_GlueX2020_FidExclusive_tlt1_2DPi0EtaAC_2DLowPhotonAC_2DOmegaAC_2DEtaPrimeAC_DeltaCut_0.root";
const TString treeName = "ntFSGlueX_100_4000000";
const TString outName = "sPlot_resetGammaIndex_GlueXI_GlueX2020_FidExclusive_tlt1_2DPi0EtaAC_2DLowPhotonAC_2DOmegaAC_2DEtaPrimeAC_DeltaCut.root";

void makeTree4sPlot(){
    // open data
    cout << "Opening data file " << Form("%s%s",dirData.Data(),baseFileName.Data()) << endl;
    TFile* fData = new TFile(Form("%s%s",dirData.Data(),baseFileName.Data()),"READ");
    cout << "Data file opened" << endl;
    TTree* tree = (TTree*)fData->Get(treeName.Data());
    cout << "Tree " << treeName << " opened" << endl;

    // create output file
    cout << "Creating output file " << Form("%s%s",dirData.Data(),outName.Data()) << endl;
    TFile* fOut = new TFile(Form("%s%s",dirData.Data(),outName.Data()),"RECREATE");

    TTree* outTree = new TTree(treeName.Data(),treeName.Data());

    Int_t vectorIndexCombination[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
    Double_t mass[6];
    Double_t missingMass;
    const Int_t NBranches = tree->GetListOfBranches()->GetEntries();
    cout << "Number of branches: " << NBranches << endl;

    Double_t vars[NBranches];

    for (Int_t iBranch=0;iBranch<NBranches;iBranch++){
        outTree->Branch(tree->GetListOfBranches()->At(iBranch)->GetName(),&vars[iBranch],tree->GetListOfBranches()->At(iBranch)->GetName());
    }

    for (Int_t iMass=0;iMass<6;iMass++){
        outTree->Branch(Form("massGamma%dGamma%d",vectorIndexCombination[iMass][0],vectorIndexCombination[iMass][1]),&mass[iMass],Form("massGamma%dGamma%d/D",vectorIndexCombination[iMass][0],vectorIndexCombination[iMass][1]));
    }
    outTree->Branch("missingMass",&missingMass,"missingMass/D");

    // for (Int_t iGammaIndex=2;iGammaIndex<=5;iGammaIndex++) {
    //     outTree->SetBranchStatus("*",0);
    //     outTree->SetBranchStatus(Form("PxP%d",iGammaIndex),1);
    //     outTree->SetBranchStatus(Form("PyP%d",iGammaIndex),1);
    //     outTree->SetBranchStatus(Form("PzP%d",iGammaIndex),1);
    //     outTree->SetBranchStatus(Form("EnP%d",iGammaIndex),1);
    // }
    
    cout << "Processing " << tree->GetEntries() << " entries" << endl;
    for (Int_t iEntry=0;iEntry<tree->GetEntries();iEntry++) {
        tree->GetEntry(iEntry);
        TLorentzVector p_gamma[4];
        TLorentzVector p_recoilProton;
        TLorentzVector p_targetProton = TLorentzVector(0,0,0,0.938272);
        TLorentzVector p_beam;

        for (Int_t iBranches=0;iBranches<NBranches;iBranches++){
            vars[iBranches] = tree->GetLeaf(tree->GetListOfBranches()->At(iBranches)->GetName())->GetValue();
        }
        
        p_recoilProton.SetPxPyPzE(tree->GetLeaf("PxP1")->GetValue(),
                                  tree->GetLeaf("PyP1")->GetValue(),
                                  tree->GetLeaf("PzP1")->GetValue(),
                                  tree->GetLeaf("EnP1")->GetValue());

        p_beam.SetPxPyPzE(tree->GetLeaf("PxPB")->GetValue(),
                          tree->GetLeaf("PyPB")->GetValue(),
                          tree->GetLeaf("PzPB")->GetValue(),
                          tree->GetLeaf("EnPB")->GetValue());
        

        for (Int_t iGammaIndex=2;iGammaIndex<=5;iGammaIndex++){            
            p_gamma[iGammaIndex-2].SetPxPyPzE(tree->GetLeaf(Form("PxP%d",iGammaIndex))->GetValue(),
                                              tree->GetLeaf(Form("PyP%d",iGammaIndex))->GetValue(),
                                              tree->GetLeaf(Form("PzP%d",iGammaIndex))->GetValue(),
                                              tree->GetLeaf(Form("EnP%d",iGammaIndex))->GetValue());
            // cout << "Gamma " << iGammaIndex << " : " << p_gamma[iGammaIndex-2].Px() << " " << p_gamma[iGammaIndex-2].Py() << " " << p_gamma[iGammaIndex-2].Pz() << " " << p_gamma[iGammaIndex-2].E() << endl;
        }

        for (Int_t iMass=0;iMass<6;iMass++){
            mass[iMass] = (p_gamma[vectorIndexCombination[iMass][0]-2] + p_gamma[vectorIndexCombination[iMass][1]-2]).M();
            // if (iMass==5 && (mass[iMass]>0.11 && mass[iMass]<0.12)) cout << vectorIndexCombination[iMass][0] << " " << vectorIndexCombination[iMass][1] << " " << mass[iMass] << endl;
        }

        // calculate missing mass squared
        TLorentzVector p_sumGamma = p_gamma[0] + p_gamma[1] + p_gamma[2] + p_gamma[3];
        missingMass = (p_beam + p_targetProton - p_recoilProton - p_sumGamma).M2();

        outTree->Fill();
        cout << "Entry " << iEntry << " done" << endl;
    }

    fOut->Write();
    fOut->Close();
    fData->Close();

}