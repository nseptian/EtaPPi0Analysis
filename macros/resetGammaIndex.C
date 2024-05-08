TString dirName = "/d/grid17/septian/GlueX_Data/tree_gggg__B4_FSRootFlat/";
TString baseFileName = "skimmedTree_GlueXI_GlueX2020_FidExclusive_tlt1_2DPi0EtaAC_2DLowPhotonAC_2DOmegaAC_2DEtaPrimeAC_DeltaCut";
TString treeName = "ntFSGlueX_100_4000000";
TString outName = "resetGammaIndex_GlueXI_GlueX2020_FidExclusive_tlt1_2DPi0EtaAC_2DLowPhotonAC_2DOmegaAC_2DEtaPrimeAC_DeltaCut.root";
const Int_t NCombination = 6;

void resetGammaIndex(){
    Int_t vectorIndexCombination[NCombination][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};

    //create output file
    TFile* fout = new TFile(Form("%s%s",dirName.Data(),outName.Data()),"RECREATE");
    TTree* tout = new TTree(treeName.Data(),treeName.Data());

    Double_t outPxP[4];
    Double_t outPyP[4];
    Double_t outPzP[4];
    Double_t outEnP[4];

    Double_t outRPxP[4];
    Double_t outRPyP[4];
    Double_t outRPzP[4];
    Double_t outREnP[4];

    Double_t outShQualityP[4];

    Double_t outOtherBr[66];

    // Get tree from the 1st combination
    TString fileName1st = Form("%s%s_%d.root",dirName.Data(),baseFileName.Data(),0);
    TFile* f1st=new TFile(fileName1st,"READ");
    TTree* t1st = (TTree*)f1st->Get(treeName.Data());
    TObjArray* branches = t1st->GetListOfBranches();

    //create output branches

    vector<TString> branchNameToExclude;
    
    for (Int_t i=2;i<=5;i++) {
        tout->Branch(Form("PxP%d",i),&outPxP[i-2],Form("PxP%d/D",i));
        tout->Branch(Form("PyP%d",i),&outPyP[i-2],Form("PyP%d/D",i));
        tout->Branch(Form("PzP%d",i),&outPzP[i-2],Form("PzP%d/D",i));
        tout->Branch(Form("EnP%d",i),&outEnP[i-2],Form("EnP%d/D",i));
        
        tout->Branch(Form("RPxP%d",i),&outRPxP[i-2],Form("RPxP%d/D",i));
        tout->Branch(Form("RPyP%d",i),&outRPyP[i-2],Form("RPyP%d/D",i));
        tout->Branch(Form("RPzP%d",i),&outRPzP[i-2],Form("RPzP%d/D",i));
        tout->Branch(Form("REnP%d",i),&outREnP[i-2],Form("REnP%d/D",i));
        
        tout->Branch(Form("ShQualityP%d",i),&outShQualityP[i-2],Form("ShQualityP%d/D",i));

        branchNameToExclude.push_back(Form("PxP%d",i));
        branchNameToExclude.push_back(Form("PyP%d",i));
        branchNameToExclude.push_back(Form("PzP%d",i));
        branchNameToExclude.push_back(Form("EnP%d",i));

        branchNameToExclude.push_back(Form("RPxP%d",i));
        branchNameToExclude.push_back(Form("RPyP%d",i));
        branchNameToExclude.push_back(Form("RPzP%d",i));
        branchNameToExclude.push_back(Form("REnP%d",i));

        branchNameToExclude.push_back(Form("ShQualityP%d",i));
    }

    Int_t iExclude=0;
    for (Int_t iBranch=0;iBranch<branches->GetEntries();iBranch++){
        TBranch *branch = (TBranch*)branches->At(iBranch);
        TString branchName = branches->At(iBranch)->GetName();
        if (find(branchNameToExclude.begin(),branchNameToExclude.end(),branchName) != branchNameToExclude.end()) {
            iExclude++;
            continue;
        }
        else
        {
            tout->Branch(branchName.Data(),&outOtherBr[iBranch-iExclude],Form("%s/D",branchName.Data()));
        }
    }


    for (Int_t iCombination=0;iCombination<NCombination;iCombination++){
        TString fileName = Form("%s%s_%d.root",dirName.Data(),baseFileName.Data(),iCombination);
        TFile* f=new TFile(fileName,"READ");
        TTree* t = (TTree*)f->Get(treeName.Data());
        Int_t nEntries = t->GetEntries();
        t->SetBranchStatus("*",1);

        Double_t PxP[4],PyP[4],PzP[4],EnP[4];
        Double_t RPxP[4],RPyP[4],RPzP[4],REnP[4];
        Double_t ShQualityP[4];
        Double_t OtherBr[66];

        for (Int_t i=2;i<=5;i++){
            t->SetBranchAddress(Form("PxP%d",i),&PxP[i]);
            t->SetBranchAddress(Form("PyP%d",i),&PyP[i]);
            t->SetBranchAddress(Form("PzP%d",i),&PzP[i]);
            t->SetBranchAddress(Form("EnP%d",i),&EnP[i]);

            t->SetBranchAddress(Form("RPxP%d",i),&RPxP[i]);
            t->SetBranchAddress(Form("RPyP%d",i),&RPyP[i]);
            t->SetBranchAddress(Form("RPzP%d",i),&RPzP[i]);
            t->SetBranchAddress(Form("REnP%d",i),&REnP[i]);

            t->SetBranchAddress(Form("ShQualityP%d",i),&ShQualityP);
        }

        iExclude=0;

        for (Int_t iBranch=0;iBranch<branches->GetEntries();iBranch++){
            TBranch *branch = (TBranch*)branches->At(iBranch);
            TString branchName = branches->At(iBranch)->GetName();
            if (find(branchNameToExclude.begin(),branchNameToExclude.end(),branchName) != branchNameToExclude.end()) {
                iExclude++;
                continue;
            }
            else
            {
                t->SetBranchAddress(branchName.Data(),&OtherBr[iBranch-iExclude]);
            }
        }
        
        Int_t gammaIndex[4] = {vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[5-iCombination][0],vectorIndexCombination[5-iCombination][1]};
        
        //print file info
        cout << "File: " << fileName << endl;
        cout << "Number of entries: " << nEntries << endl;
        cout << "Gamma index combination: " << vectorIndexCombination[iCombination][0] << " " << vectorIndexCombination[iCombination][1] << " " << vectorIndexCombination[5-iCombination][0] << " " << vectorIndexCombination[5-iCombination][1] << endl;
        
        //loop over entries and fill output branches
        for (Int_t iEntry=0;iEntry<t->GetEntries();iEntry++){
            t->GetEntry(iEntry);
            // gamma index reset
            for (Int_t i=2;i<6;i++) {
                outPxP[i] = PxP[gammaIndex[i-2]];
                outPyP[i] = PyP[gammaIndex[i-2]];
                outPzP[i] = PzP[gammaIndex[i-2]];
                outEnP[i] = EnP[gammaIndex[i-2]];

                outRPxP[i] = RPxP[gammaIndex[i-2]];
                outRPyP[i] = RPyP[gammaIndex[i-2]];
                outRPzP[i] = RPzP[gammaIndex[i-2]];
                outREnP[i] = REnP[gammaIndex[i-2]];

                outShQualityP[i] = ShQualityP[gammaIndex[i-2]];
            }
            std::copy(std::begin(OtherBr), std::end(OtherBr), std::begin(outOtherBr));
            // cout << "Entry: " << iEntry << endl;
            tout->Fill();
        }
        f->Close();
        delete f;
    }
    tout->Print();
    fout->cd();
    tout->Write();
    fout->Close();
}