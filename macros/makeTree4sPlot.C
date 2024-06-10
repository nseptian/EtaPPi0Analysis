const TString dirData = "/d/grid17/septian/GlueX_Data/tree_gggg__B4_FSRootFlat/";
const TString baseFileName = "resetGammaIndex_GlueXI_GlueX2020_FidExclusive_tlt1_2DPi0EtaAC_2DLowPhotonAC_2DOmegaAC_2DEtaPrimeAC_DeltaCut";
// const TString baseFileName = "skimmedTree_GlueXI_GlueX2020_FidExclusive_tlt1_2DPi0EtaAC_2DLowPhotonAC_2DOmegaAC_2DEtaPrimeAC_DeltaCut_0.root";
// TString baseFileName = "resetGammaIndex_genr8_MC_GlueX2018S_FidExclusive_tlt1_2DPi0EtaAC_2DLowPhotonAC_2DOmegaAC_2DEtaPrimeAC_DeltaCut";
// TString baseFileName = "skimmedTree_genr8_MC_GlueX2018S_FidExclusive_tlt1_2DPi0EtaAC_2DLowPhotonAC_2DOmegaAC_2DEtaPrimeAC_DeltaCut_1";
const TString treeName = "ntFSGlueX_100_4000000";
const TString outName = Form("sPlot_%s.root",baseFileName.Data());

void makeTree4sPlot(){
    // open data
    cout << "Opening data file " << Form("%s%s",dirData.Data(),baseFileName.Data()) << endl;
    TFile* fData = new TFile(Form("%s%s.root",dirData.Data(),baseFileName.Data()),"READ");
    cout << "Data file opened" << endl;
    TTree* tree = (TTree*)fData->Get(treeName.Data());
    cout << "Tree " << treeName << " opened" << endl;

    // create output file
    cout << "Creating output file " << Form("%s%s",dirData.Data(),outName.Data()) << endl;
    TFile* fOut = new TFile(Form("%s%s",dirData.Data(),outName.Data()),"RECREATE");

    TTree* outTree = new TTree(treeName.Data(),treeName.Data());

    Int_t vectorIndexCombination[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
    Double_t Mass2Gamma[6];
    Double_t Mass4Gamma;
    Double_t MissingMassSq;
    Double_t MassPi0Gamma1;
    Double_t MassPi0Gamma2;
    Double_t EtaPrimeCOSThetaGJ;
    const Int_t NBranches = tree->GetListOfBranches()->GetEntries();
    cout << "Number of branches: " << NBranches << endl;

    Double_t vars[NBranches];

    for (Int_t iBranch=0;iBranch<NBranches;iBranch++){
        outTree->Branch(tree->GetListOfBranches()->At(iBranch)->GetName(),&vars[iBranch],tree->GetListOfBranches()->At(iBranch)->GetName());
    }

    for (Int_t iMass=0;iMass<6;iMass++){
        outTree->Branch(Form("MassGamma%dGamma%d",vectorIndexCombination[iMass][0],vectorIndexCombination[iMass][1]),&Mass2Gamma[iMass],Form("massGamma%dGamma%d/D",vectorIndexCombination[iMass][0],vectorIndexCombination[iMass][1]));
    }
    outTree->Branch("MissingMassSq",&MissingMassSq,"MissingMassSq/D");
    outTree->Branch("Mass4Gamma",&Mass4Gamma,"Mass4Gamma/D");
    outTree->Branch("MassPi0Gamma1",&MassPi0Gamma1,"MassPi0Gamma1/D");
    outTree->Branch("MassPi0Gamma2",&MassPi0Gamma2,"MassPi0Gamma2/D");
    outTree->Branch("EtaPrimeCOSThetaGJ",&EtaPrimeCOSThetaGJ,"EtaPrimeCOSThetaGJ/D");
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
        TLorentzVector P4_Gamma[4];
        TLorentzVector P4_RecoilProton;
        TLorentzVector P4_TargetProton = TLorentzVector(0,0,0,0.938272);
        TLorentzVector P4_Beam;

        for (Int_t iBranches=0;iBranches<NBranches;iBranches++){
            vars[iBranches] = tree->GetLeaf(tree->GetListOfBranches()->At(iBranches)->GetName())->GetValue();
        }
        
        P4_RecoilProton.SetPxPyPzE(tree->GetLeaf("PxP1")->GetValue(),
                                  tree->GetLeaf("PyP1")->GetValue(),
                                  tree->GetLeaf("PzP1")->GetValue(),
                                  tree->GetLeaf("EnP1")->GetValue());

        P4_Beam.SetPxPyPzE(tree->GetLeaf("PxPB")->GetValue(),
                          tree->GetLeaf("PyPB")->GetValue(),
                          tree->GetLeaf("PzPB")->GetValue(),
                          tree->GetLeaf("EnPB")->GetValue());
        

        for (Int_t iGammaIndex=2;iGammaIndex<=5;iGammaIndex++){            
            P4_Gamma[iGammaIndex-2].SetPxPyPzE(tree->GetLeaf(Form("PxP%d",iGammaIndex))->GetValue(),
                                              tree->GetLeaf(Form("PyP%d",iGammaIndex))->GetValue(),
                                              tree->GetLeaf(Form("PzP%d",iGammaIndex))->GetValue(),
                                              tree->GetLeaf(Form("EnP%d",iGammaIndex))->GetValue());
            // cout << "Gamma " << iGammaIndex << " : " << p_gamma[iGammaIndex-2].Px() << " " << p_gamma[iGammaIndex-2].Py() << " " << p_gamma[iGammaIndex-2].Pz() << " " << p_gamma[iGammaIndex-2].E() << endl;
        }

        for (Int_t iMass=0;iMass<6;iMass++){
            Mass2Gamma[iMass] = (P4_Gamma[vectorIndexCombination[iMass][0]-2] + P4_Gamma[vectorIndexCombination[iMass][1]-2]).M();
            // if (iMass==5 && (mass[iMass]>0.11 && mass[iMass]<0.12)) cout << vectorIndexCombination[iMass][0] << " " << vectorIndexCombination[iMass][1] << " " << mass[iMass] << endl;
        }

        TLorentzVector P4_4Gamma = P4_Gamma[0] + P4_Gamma[1] + P4_Gamma[2] + P4_Gamma[3];
        Mass4Gamma = P4_4Gamma.M();
        MissingMassSq = (P4_Beam + P4_TargetProton - P4_RecoilProton - P4_4Gamma).M2();
        MassPi0Gamma1 = (P4_Gamma[0] + P4_Gamma[2] + P4_Gamma[3]).M();
        MassPi0Gamma2 = (P4_Gamma[1] + P4_Gamma[2] + P4_Gamma[3]).M();
        outTree->Fill();

        // calculate EtaPrimeCOSThetaGJ
        TLorentzVector P4_EtaPrime = P4_Gamma[0] + P4_Gamma[1];
        TLorentzVector P4_PiZero = P4_Gamma[2] + P4_Gamma[3];
        
        // boost to CM frame
        TLorentzVector P4_EtaPrime_CM = P4_EtaPrime;
        TLorentzVector P4_PiZero_CM = P4_PiZero;
        TLorentzVector P4_Beam_CM = P4_Beam;
        
        TLorentzVector P4_CM = P4_Beam + P4_TargetProton;
        TVector3 betaCM = P4_CM.BoostVector();

        P4_EtaPrime_CM.Boost(-betaCM);
        P4_PiZero_CM.Boost(-betaCM);
        P4_Beam_CM.Boost(-betaCM);

        // boost to GJ frame
        TLorentzVector P4_EtaPrime_GJ = P4_EtaPrime_CM;
        TLorentzVector P4_PiZero_GJ = P4_PiZero_CM;
        TLorentzVector P4_Beam_GJ = P4_Beam_CM;

        TLorentzVector P4_GJ = P4_EtaPrime_CM + P4_PiZero_CM;
        TVector3 betaGJ = P4_GJ.BoostVector();

        P4_EtaPrime_GJ.Boost(-betaGJ);
        P4_PiZero_GJ.Boost(-betaGJ);
        P4_Beam_GJ.Boost(-betaGJ);

        // calculate GJ z-axis
        TVector3 zGJ = P4_Beam_GJ.Vect().Unit();

        // calculate EtaPrimeCOSThetaGJ
        EtaPrimeCOSThetaGJ = TMath::Cos(P4_EtaPrime_GJ.Vect().Angle(zGJ));

        // cout << "Entry " << iEntry << " done" << endl;
    }

    fOut->Write();
    fOut->Close();
    fData->Close();

}