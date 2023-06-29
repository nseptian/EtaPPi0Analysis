TString dirName = "/d/grid17/septian/EtaPPi0_4Gamma/2018S/skimmedTree/";
TString baseFileName = "skimmedTree_AllCombination_2DPi0EtaAC";
TString treeName = "ntFSGlueX_100_4000000";
TString outName = "resetGammaIndexFlatTree_GlueX_100_4000000.root";
Int_t NCombination = 6;

void resetGammaIndex(){
    Int_t vectorIndexCombination[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};

    //create output file
    TFile* fout = new TFile(outName,"RECREATE");
    TTree* tout = new TTree(treeName.Data(),treeName.Data());

    Double_t outPxP[6];
    Double_t outPyP[6];
    Double_t outPzP[6];
    Double_t outEnP[6];

    //create output branches
    tout->Branch("PxPB",&outPxP[0],"PxPB/D");
    tout->Branch("PyPB",&outPyP[0],"PyPB/D");
    tout->Branch("PzPB",&outPzP[0],"PzPB/D");
    tout->Branch("EnPB",&outEnP[0],"EnPB/D");
    
    for (Int_t i=1;i<6;i++) {
        tout->Branch(Form("PxP%d",i),&outPxP[i],Form("PxP%d/D",i));
        tout->Branch(Form("PyP%d",i),&outPyP[i],Form("PyP%d/D",i));
        tout->Branch(Form("PzP%d",i),&outPzP[i],Form("PzP%d/D",i));
        tout->Branch(Form("EnP%d",i),&outEnP[i],Form("EnP%d/D",i));
    }

    for (Int_t iCombination=0;iCombination<NCombination;iCombination++){
        TString fileName = Form("%s%s_%d.root",dirName.Data(),baseFileName.Data(),iCombination);
        TFile* f=new TFile(fileName,"READ");
        TTree* t = (TTree*)f->Get(treeName.Data());
        Int_t nEntries = t->GetEntries();
        //print file info
        cout << "File: " << fileName << endl;
        cout << "Number of entries: " << nEntries << endl;
        cout << "Gamma index combination: " << vectorIndexCombination[iCombination][0] << " " << vectorIndexCombination[iCombination][1] << " " << vectorIndexCombination[5-iCombination][0] << " " << vectorIndexCombination[5-iCombination][1] << endl;
        t->SetBranchStatus("*",0);
        t->SetBranchStatus("PxPB",1);
        t->SetBranchStatus("PyPB",1);
        t->SetBranchStatus("PzPB",1);
        t->SetBranchStatus("EnPB",1);
        for (Int_t i=1;i<6;i++){
            t->SetBranchStatus(Form("PxP%d",i),1);
            t->SetBranchStatus(Form("PyP%d",i),1);
            t->SetBranchStatus(Form("PzP%d",i),1);
            t->SetBranchStatus(Form("EnP%d",i),1);
        }

        Double_t PxP[6],PyP[6],PzP[6],EnP[6];

        //SetBranchAddress for all active branches
        t->SetBranchAddress("PxPB",&PxP[0]);
        t->SetBranchAddress("PyPB",&PyP[0]);
        t->SetBranchAddress("PzPB",&PzP[0]);
        t->SetBranchAddress("EnPB",&EnP[0]);
        for (Int_t i=1;i<6;i++){
            t->SetBranchAddress(Form("PxP%d",i),&PxP[i]);
            t->SetBranchAddress(Form("PyP%d",i),&PyP[i]);
            t->SetBranchAddress(Form("PzP%d",i),&PzP[i]);
            t->SetBranchAddress(Form("EnP%d",i),&EnP[i]);
        }
        
        Int_t gammaIndex[4] = {vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[5-iCombination][0],vectorIndexCombination[5-iCombination][1]};

        //loop over entries
        for (Int_t iEntry=0;iEntry<nEntries;iEntry++){
            t->GetEntry(iEntry);
            //fill output branches
            for (Int_t i=0;i<6;i++) {
                if (i<=1) {
                    //recoil proton and beam
                    outPxP[i] = PxP[i];
                    outPyP[i] = PyP[i];
                    outPzP[i] = PzP[i];
                    outEnP[i] = EnP[i];
                }
                else {
                    //gamma index reset
                    outPxP[i] = PxP[gammaIndex[i-2]];
                    outPyP[i] = PyP[gammaIndex[i-2]];
                    outPzP[i] = PzP[gammaIndex[i-2]];
                    outEnP[i] = EnP[gammaIndex[i-2]];
                }
            }
            tout->Fill();
        }
        f->Close();
    }
    tout->Print();
    fout->cd();
    tout->Write();
    fout->Close();
}