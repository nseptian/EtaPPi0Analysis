TString FND("/d/grid17/sdobbs/gluex_data/EtapPi0_4gamma/skimmed/tree_pi0eta__B4_M17_M7_FLAT_PRESKIM_*.root");
TString FNMC("/d/grid17/sdobbs/gluex_data/EtapPi0_4gamma/skimmed/tree_pi0eta__B4_M17_M7_FLAT_MC_PRESKIM.root");
//TString FNMCGen("/w/halld-scshelf2101/malte/PipPim_FSRoot/flatten/SKIM.RFSIG.100_110.MCGEN.root");

TString NT("ntFSGlueX_MODECODE");
TString rootHistFile("histograms.root");

void chi2Ranking(){
   FSModeCollection::addModeInfo("100_4000000");
//   FSModeTree::createChi2RankingTree(FND,NT,"","abs(RFDeltaT)<2.0");
   FSModeTree::createChi2RankingTree(FNMC,NT,"","abs(RFDeltaT)<2.0");
}

void PlotMass2GammaCombination(TString fileName, TString treeName, Int_t numberOfBin, Double_t xmin, Double_t xmax, TString cutName, TString tag, Bool_t isGamma3Cut, Bool_t isPi0Cut3);
void PlotMass3GammaCombination(TString fileName, TString treeName, Int_t numberOfBin, Double_t xmin, Double_t xmax, TString cutName, TString tag, Bool_t isGamma3Cut, Bool_t isPi0Cut3);
void PlotMass4Gamma(TString fileName, TString treeName, Int_t numberOfBin, Double_t xmin, Double_t xmax, TString cutName, TString tag, Bool_t isGamma3Cut, Bool_t isPi0Cut3, Bool_t isPi0Select, Bool_t isEtaPrimeSelect);
TString GetCutStringMass3GammaCombination(Int_t vectorIndex1,Int_t vectorIndex2,Int_t vectorIndex3);
TString GetPi0CutStringMass3Combination(Int_t vectorIndex1,Int_t vectorIndex2,Int_t vectorIndex3);
void Plot1DHistWithCuts(TString fileName, TString treeName, TString varName, TString cutName, TString tag, 
                        Int_t numberOfXBin, Double_t xmin, Double_t xmax, TString xTitle, TString yTitle, TString title,
                        Bool_t isEnableCombination, Bool_t isCanvasDivide, Int_t numberOfXPad, Int_t numberOfYPad,
                        Bool_t isGamma3Cut = kFALSE, Bool_t isPi0Cut3 = kFALSE, Bool_t isPi0Select = kFALSE, Bool_t isEtaPrimeSelect = kFALSE);
void DefineGamma3Cuts();
void DefinePi0SelectCuts();
void DefineEtaPrimeSelectCuts();

void setup(){
   if (FSModeCollection::modeVector().size() != 0) return;
   FSHistogram::readHistogramCache();
   FSModeCollection::addModeInfo("100_4000000")->addCategory("m100_4000000");
   FSModeCollection::display();

   // DEFINITION OF CUTS:

   // FIXED CUTS
   // format defineCut("name","BranchName =<> value")
   // unused energy cut
   FSCut::defineCut("unusedE","EnUnusedSh<0.1");
   // unused track cut
   FSCut::defineCut("unusedTracks","NumUnusedTracks<1");
   // z vertex cut (liquid hydrogen target)
   FSCut::defineCut("zProton","ProdVz>51&&ProdVz<78");
   // Proton momentum > 0.3GeV/c
   FSCut::defineCut("protMom","MOMENTUM([p+])>=0.3");
   FSCut::defineCut("e8288","(EnPB>8.2&&EnPB<8.8)");
   FSCut::defineCut("mcebeam","(MCEnPB>8.2&&MCEnPB<8.8)");
   // FSCut::defineCut("chi2","Chi2DOF<5.0","Chi2DOF>10.0&&Chi2DOF<15.0");
   FSCut::defineCut("chi2lt2","Chi2DOF<2.0");
   FSCut::defineCut("rank1","Chi2Rank==1");
   FSCut::defineCut("rank2","Chi2Rank==2");
   FSCut::defineCut("rank3","Chi2Rank==3");
   FSCut::defineCut("rank4","Chi2Rank==4");
   FSCut::defineCut("rank5","Chi2Rank==5");
   FSCut::defineCut("rank6","Chi2Rank==6");
   FSCut::defineCut("rf","OR(abs(RFDeltaT)<2.0)", "abs(RFDeltaT)>2.0",0.125);
   FSCut::defineCut("photFiducialA","(acos(COSINE(2))*180/3.141>2.5 && acos(COSINE(2))*180/3.141<10.3) || (acos(COSINE(2))*180/3.141>11.9)");
   FSCut::defineCut("photFiducialB","(acos(COSINE(3))*180/3.141>2.5 && acos(COSINE(3))*180/3.141<10.3) || (acos(COSINE(3))*180/3.141>11.9)");
   FSCut::defineCut("photFiducialC","(acos(COSINE(4))*180/3.141>2.5 && acos(COSINE(4))*180/3.141<10.3) || (acos(COSINE(4))*180/3.141>11.9)");
   FSCut::defineCut("photFiducialD","(acos(COSINE(5))*180/3.141>2.5 && acos(COSINE(5))*180/3.141<10.3) || (acos(COSINE(5))*180/3.141>11.9)");

   FSCut::defineCut("pi01","MASS(2,3)>0.08&&MASS(2,3)<0.18");
   FSCut::defineCut("pi02","MASS(2,4)>0.08&&MASS(2,4)<0.18");
   FSCut::defineCut("pi03","MASS(2,5)>0.08&&MASS(2,5)<0.18");
   FSCut::defineCut("pi04","MASS(3,4)>0.08&&MASS(3,4)<0.18");
   FSCut::defineCut("pi05","MASS(3,5)>0.08&&MASS(3,5)<0.18");
   FSCut::defineCut("pi06","MASS(4,5)>0.08&&MASS(4,5)<0.18");
   
   FSCut::defineCut("etap1","MASS(4,5)>0.92&&MASS(4,5)<0.99","(abs(MASS(4,5)-0.958-0.0755)<0.0175 || abs(MASS(4,5)-0.958+0.0695)<0.0175)", 1.0);
   FSCut::defineCut("etap2","MASS(3,5)>0.92&&MASS(3,5)<0.99","(abs(MASS(3,5)-0.958-0.0755)<0.0175 || abs(MASS(3,5)-0.958+0.0695)<0.0175)", 1.0);
   FSCut::defineCut("etap3","MASS(3,4)>0.92&&MASS(3,4)<0.99","(abs(MASS(3,4)-0.958-0.0755)<0.0175 || abs(MASS(3,4)-0.958+0.0695)<0.0175)", 1.0);
   FSCut::defineCut("etap4","MASS(2,5)>0.92&&MASS(2,5)<0.99","(abs(MASS(2,5)-0.958-0.0755)<0.0175 || abs(MASS(2,5)-0.958+0.0695)<0.0175)", 1.0);
   FSCut::defineCut("etap5","MASS(2,4)>0.92&&MASS(2,4)<0.99","(abs(MASS(2,4)-0.958-0.0755)<0.0175 || abs(MASS(2,4)-0.958+0.0695)<0.0175)", 1.0);
   FSCut::defineCut("etap6","MASS(2,3)>0.92&&MASS(2,3)<0.99","(abs(MASS(2,3)-0.958-0.0755)<0.0175 || abs(MASS(2,3)-0.958+0.0695)<0.0175)", 1.0);
   FSTree::addFriendTree("Chi2Rank");

   FSCut::defineCut("allBase","CUT(unusedE,unusedTracks,zProton,protMom,e8288,chi2lt2,rank1,rf,photFiducialA,photFiducialB,photFiducialC,photFiducialD)");
   FSCut::defineCut("allBaseChi2Rank2","CUT(unusedE,unusedTracks,zProton,protMom,e8288,chi2lt2,rank2,rf,photFiducialA,photFiducialB,photFiducialC,photFiducialD)");
   FSCut::defineCut("allBaseChi2Rank3","CUT(unusedE,unusedTracks,zProton,protMom,e8288,chi2lt2,rank3,rf,photFiducialA,photFiducialB,photFiducialC,photFiducialD)");
   FSCut::defineCut("allBaseChi2Rank4","CUT(unusedE,unusedTracks,zProton,protMom,e8288,chi2lt2,rank4,rf,photFiducialA,photFiducialB,photFiducialC,photFiducialD)");
   FSCut::defineCut("allBaseChi2Rank5","CUT(unusedE,unusedTracks,zProton,protMom,e8288,chi2lt2,rank5,rf,photFiducialA,photFiducialB,photFiducialC,photFiducialD)");
   FSCut::defineCut("allBaseChi2Rank6","CUT(unusedE,unusedTracks,zProton,protMom,e8288,chi2lt2,rank6,rf,photFiducialA,photFiducialB,photFiducialC,photFiducialD)");
   // FSCut::defineCut("TestCut","CUT(unusedE,unusedTracks,zProton,protMom,e8288,rank1,rf,photFiducialA,photFiducialB,photFiducialC,photFiducialD)")
   // FSCut::defineCut("preSkim","CUT(unusedE,unusedTracks,zProton,protMom,e8288,chi2)");

   // VARIABLE CUTS
   FSCut::defineCut("cet0103","OR(abs(-1*MASS2(GLUEXTARGET,-[p+],-[pi+])-0.2)<0.1)");    // 0.1 < t < 0.3
   FSCut::defineCut("cet0102","OR(abs(-1*MASS2(GLUEXTARGET,-[p+],-[pi+])-0.15)<0.05)");    // 0.1 < t < 0.3
   FSCut::defineCut("mccet0102","OR(abs(-1*MCMASS2(GLUEXTARGET,-1,-2)-0.15)<0.05)");    // 0.1 < t < 0.3
   FSCut::defineCut("cet0203","OR(abs(-1*MASS2(GLUEXTARGET,-[p+],-[pi+])-0.25)<0.05)");    // 0.1 < t < 0.3
   FSCut::defineCut("cet0304","OR(abs(-1*MASS2(GLUEXTARGET,-[p+],-[pi+])-0.35)<0.05)");    // 0.1 < t < 0.3
   FSCut::defineCut("cet0405","OR(abs(-1*MASS2(GLUEXTARGET,-[p+],-[pi+])-0.45)<0.05)");    // 0.1 < t < 0.3
   FSCut::defineCut("cet05075","OR(abs(-1*MASS2(GLUEXTARGET,-[p+],-[pi+])-0.625)<0.125)");    // 0.1 < t < 0.3
   FSCut::defineCut("cet0751","OR(abs(-1*MASS2(GLUEXTARGET,-[p+],-[pi+])-0.875)<0.125)");    // 0.1 < t < 0.3
   FSCut::defineCut("cet051","OR(abs(-1*MASS2(GLUEXTARGET,-[p+],-[pi+])-0.75)<0.25)");    // 0.5 < t < 1.0
   FSCut::defineCut("cet0306","OR(abs(-1*MASS2(GLUEXTARGET,-[p+],-[pi+])-0.45)<0.15)");    // 0.3 < t < 0.6

   FSCut::defineCut("pol0","Run==51767 || Run==51766 || Run==51731 || Run==51730 || Run==51687 || Run==51686 || Run==51685 || Run==51683 || Run==51638 || Run==51629 || Run==51628 || Run==51619 || Run==51597 || Run==51596 || Run==51587 || Run==51586 || Run==51577 || Run==51576 || Run==51568 || Run==51567 || Run==51560 || Run==51559 || Run==51539 || Run==51537 || Run==51515 || Run==51514 || Run==51507 || Run==51506 || Run==51497 || Run==51450 || Run==51449 || Run==51442 || Run==51434 || Run==51402 || Run==51394 || Run==51384 || Run==51365 || Run==51332 || Run==51331 || Run==51329 || Run==51321 || Run==51313 || Run==51312 || Run==51302 || Run==51296 || Run==51289 || Run==51283 || Run==51266 || Run==51265 || Run==51254 || Run==51237 || Run==51236 || Run==51225 || Run==51209 || Run==51205 || Run==51204 || Run==51198 || Run==51179 || Run==51174 || Run==51166 || Run==51160 || Run==51154 || Run==51142 || Run==51119 || Run==51100 || Run==51095 || Run==51073 || Run==51072 || Run==51071 || Run==51065 || Run==51064 || Run==51063 || Run==51062 || Run==51054 || Run==51047 || Run==51046 || Run==51038 || Run==51031 || Run==51030 || Run==50987 || Run==50986 || Run==50979 || Run==50961 || Run==50950 || Run==50948 || Run==50947 || Run==50946 || Run==50939 || Run==50937 || Run==50931 || Run==50930 || Run==50904 || Run==5 || Run==50839 || Run==50838 || Run==50836 || Run==50813 || Run==50807 || Run==50806 || Run==50786 || Run==50785 || Run==50771 || Run==50754 || Run==50753 || Run==50752 || Run==50740 || Run==50726 || Run==50715 || Run==50712 || Run==50707 || Run==50702 || Run==50701 || Run==50698 || Run==50697");

   FSCut::defineCut("pol90","Run==51768 || Run==51733 || Run==51732 || Run==51724 || Run==51723 || Run==51722 || Run==51631 || Run==51630 || Run==51599 || Run==51598 || Run==51590 || Run==51589 || Run==51579 || Run==51578 || Run==51570 || Run==51569 || Run==51562 || Run==51561 || Run==51542 || Run==51540 || Run==51517 || Run==51516 || Run==51508 || Run==51498 || Run==51453 || Run==51451 || Run==51443 || Run==51435 || Run==51408 || Run==51395 || Run==51387 || Run==51386 || Run==51367 || Run==51366 || Run==51333 || Run==51323 || Run==51322 || Run==51315 || Run==51314 || Run==51304 || Run==51303 || Run==51290 || Run==51285 || Run==51284 || Run==51268 || Run==51267 || Run==51256 || Run==51248 || Run==51226 || Run==51212 || Run==51210 || Run==51199 || Run==51192 || Run==51175 || Run==51167 || Run==51161 || Run==51155 || Run==51145 || Run==51143 || Run==51114 || Run==51101 || Run==51096 || Run==51074 || Run==51066 || Run==51055 || Run==51049 || Run==51048 || Run==51039 || Run==51033 || Run==51032 || Run==51018 || Run==51017 || Run==50981 || Run==50951 || Run==50940 || Run==50933 || Run==50932 || Run==50911 || Run==50909 || Run==50908 || Run==50907 || Run==50905 || Run==50840 || Run==50814 || Run==50808 || Run==50787 || Run==50772 || Run==50755 || Run==50742 || Run==50741 || Run==50727 || Run==50716 || Run==50699");


   FSCut::defineCut("pol45","Run==51748 || Run==51735 || Run==51734 || Run==51726 || Run==51725 || Run==51634 || Run==51633 || Run==51632 || Run==51601 || Run==51600 || Run==51592 || Run==51591 || Run==51581 || Run==51580 || Run==51572 || Run==51571 || Run==51564 || Run==51563 || Run==51544 || Run==51543 || Run==51519 || Run==51518 || Run==51510 || Run==51502 || Run==51500 || Run==51499 || Run==51454 || Run==51444 || Run==51436 || Run==51409 || Run==51397 || Run==51396 || Run==51389 || Run==51388 || Run==51369 || Run==51368 || Run==51336 || Run==51335 || Run==51326 || Run==51325 || Run==51324 || Run==51316 || Run==51306 || Run==51305 || Run==51291 || Run==51286 || Run==51271 || Run==51270 || Run==51269 || Run==51261 || Run==51260 || Run==51250 || Run==51249 || Run==51228 || Run==51227 || Run==51213 || Run==51200 || Run==51193 || Run==51176 || Run==51170 || Run==51169 || Run==51162 || Run==51156 || Run==51150 || Run==51115 || Run==51097 || Run==51076 || Run==51075 || Run==51067 || Run==51056 || Run==51051 || Run==51050 || Run==51040 || Run==51035 || Run==51028 || Run==51027 || Run==50984 || Run==50983 || Run==50958 || Run==50956 || Run==50944 || Run==50935 || Run==50928 || Run==50919 || Run==50917 || Run==50847 || Run==50817 || Run==50816 || Run==50811 || Run==50810 || Run==50802 || Run==50801 || Run==50775 || Run==50774 || Run==50759 || Run==50758 || Run==50750 || Run==50746 || Run==50738 || Run==50737 || Run==50733 || Run==50706 || Run==50705");

   FSCut::defineCut("pol135","Run==51764 || Run==51763 || Run==51762 || Run==51749 || Run==51728 || Run==51727 || Run==51636 || Run==51635 || Run==51603 || Run==51602 || Run==51594 || Run==51593 || Run==51583 || Run==51582 || Run==51574 || Run==51573 || Run==51565 || Run==51545 || Run==51521 || Run==51520 || Run==51512 || Run==51511 || Run==51504 || Run==51503 || Run==51455 || Run==51445 || Run==51437 || Run==51410 || Run==51398 || Run==51390 || Run==51363 || Run==51362 || Run==51337 || Run==51327 || Run==51318 || Run==51317 || Run==51310 || Run==51309 || Run==51293 || Run==51292 || Run==51287 || Run==51273 || Run==51272 || Run==51263 || Run==51262 || Run==51252 || Run==51251 || Run==51234 || Run==51233 || Run==51214 || Run==51202 || Run==51201 || Run==51194 || Run==51177 || Run==51171 || Run==51164 || Run==51163 || Run==51157 || Run==51152 || Run==51151 || Run==51117 || Run==51116 || Run==51098 || Run==51077 || Run==51068 || Run==51059 || Run==51058 || Run==51057 || Run==51052 || Run==51041 || Run==51034 || Run==51020 || Run==51019 || Run==50982 || Run==50955 || Run==50952 || Run==50943 || Run==50942 || Run==50941 || Run==50934 || Run==50927 || Run==50915 || Run==50914 || Run==50841 || Run==50815 || Run==50809 || Run==50799 || Run==50798 || Run==50797 || Run==50773 || Run==50757 || Run==50756 || Run==50745 || Run==50744 || Run==50743 || Run==50729 || Run==50728 || Run==50704 || Run==50703");

   DefineGamma3Cuts();
   DefinePi0SelectCuts();
   DefineEtaPrimeSelectCuts();
}

void eventSelection(){
   setup();
   // TCanvas* c1 = new TCanvas("c1","c1",800,600);
   // TFile* fHistOutput = new TFile(rootHistFile.Data(),"RECREATE");
   
   // TH1F* h1D  = FSModeHistogram::getTH1F(FND,NT,"","Chi2DOF","(100,0.0,25.0)","CUT(e8288)");
   // TH1F* h1MC = FSModeHistogram::getTH1F(FNMC,NT,"","Chi2DOF","(100,0.0,25.0)","CUT(e8288)");
   // h1D->SetTitle("#gamma p #rightarrow 4#gamma p (cut on e8288)");
   // h1D->SetXTitle("#chi^{2}/dof");
   // h1D->SetYTitle("Events / Bin");
   // h1MC->SetLineColor(kBlue); h1MC->SetMarkerColor(kBlue);
   // h1D->Draw("");
   // h1MC->Draw("hist,same");
   // c1->Print("chi2DOF.pdf");
   // FSModeHistogram::dumpHistogramCache();
   // h1D->Write();
   // h1MC->Write();

   // PlotMass2GammaCombination(FND,NT,150,0.0,1.5,"allBase","all",kTRUE,kTRUE);
   // PlotMass2GammaCombination(FND,NT,20,0.92,0.99,"CUT(allBase)","etaPrime");
   // PlotMass3GammaCombination(FND,NT,130,0.,1.3,"CUT(e8288)","all");
   // PlotMass3GammaCombination(FND,NT,130,0.,1.3,"allBase","all");
   // PlotMass3GammaCombination(FND,NT,130,0.,1.3,"allBase","all",kTRUE);
   // PlotMass2GammaCombination(FND,NT,200,0.0,1.0,"allBase","all",kTRUE);
   // PlotMass2GammaCombination(FND,NT,100,0.0,1.0,"allBase","all",kTRUE,kTRUE);
   // PlotMass3GammaCombination(FND,NT,130,0.0,1.3,"allBase","all",kTRUE,kTRUE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase","etaPrime",kTRUE,kTRUE);
   // PlotMass2GammaCombination(FND,NT,30,0.0,0.3,"allBase","pi0",kTRUE,kTRUE);
   // PlotMass3GammaCombination(FND,NT,20,1.0,1.2,"allBase","check1012",kTRUE,kTRUE);
   // PlotMass4Gamma(FND,NT,200,0.0,2.0,"allBase","all",kTRUE,kTRUE,kFALSE,kFALSE);
   // PlotMass4Gamma(FND,NT,200,0.0,2.0,"allBase","all",kTRUE,kTRUE,kTRUE,kFALSE);
   PlotMass4Gamma(FND,NT,100,1.0,2.0,"allBase","SSB",kTRUE,kTRUE,kTRUE,kTRUE);

   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase","etaPrime_noPi0Select",kTRUE,kTRUE);

   // PlotMass4Gamma(FND,NT,100,1.0,2.0,"allBase","left_etaP_sideband_0885_0905",kTRUE,kTRUE,kTRUE,kTRUE);

   // Plot1DHistWithCuts(FND, NT, "Chi2DOF", "allBase", "Chi2DOF_test", 
   //                   20, 0.0, 5.0, "#chi^{2}/dof", "counts", "allBase",
   //                   kFALSE, kFALSE, 0, 0,
   //                   kFALSE, kFALSE, kFALSE, kFALSE);

   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBaseChi2Rank2","etaPrime",kTRUE,kTRUE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBaseChi2Rank3","etaPrime",kTRUE,kTRUE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBaseChi2Rank4","etaPrime",kTRUE,kTRUE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBaseChi2Rank5","etaPrime",kTRUE,kTRUE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBaseChi2Rank6","etaPrime",kTRUE,kTRUE);

   // fHistOutput->Write();
   // fHistOutput->Close();
}

void PlotMass2GammaCombination(TString fileName, TString treeName, Int_t numberOfBin, Double_t xmin, Double_t xmax, TString cutName, TString tag, Bool_t isGamma3Cut = kFALSE, Bool_t isPi0Cut3 = kFALSE){
   Int_t vectorIndexPermutation[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   TString binning = Form("(%d,%f,%f)",numberOfBin,xmin,xmax);
   TH1F *h1GammaGammaMass;
   TCanvas *c = new TCanvas("c","c",800,600);
   c->Divide(3,2);
   if (isGamma3Cut) {
      Int_t vectorIndexPermutation3[4][3] = {{2,3,4},{2,3,5},{2,4,5},{3,4,5}};
      for (Int_t iPermutation3 = 0;iPermutation3 < 4; iPermutation3++){
         FSCut::defineCut(Form("Gamma3Cut%d",iPermutation3),GetCutStringMass3GammaCombination(vectorIndexPermutation3[iPermutation3][0],vectorIndexPermutation3[iPermutation3][1],vectorIndexPermutation3[iPermutation3][2]).Data());
      }
   }
   if (isPi0Cut3) {
      Int_t vectorIndexPermutation3[4][3] = {{2,3,4},{2,3,5},{2,4,5},{3,4,5}};
      for (Int_t iPermutation3 = 0;iPermutation3 < 4; iPermutation3++){
         FSCut::defineCut(Form("pi0Cut%d",iPermutation3),GetPi0CutStringMass3Combination(vectorIndexPermutation3[iPermutation3][0],vectorIndexPermutation3[iPermutation3][1],vectorIndexPermutation3[iPermutation3][2]).Data());
      }
   }
   for (Int_t iPermutation = 0; iPermutation < 6; iPermutation++){
      c->cd(iPermutation+1);
      TString cutString = "CUT(";
      cutString += cutName;
      if (isGamma3Cut) {
         for (Int_t iPermutation3 = 0;iPermutation3 < 4; iPermutation3++){
            cutString += Form(",Gamma3Cut%d",iPermutation3);
         }
      }
      if (isPi0Cut3) {
         for (Int_t iPermutation3 = 0;iPermutation3 < 4; iPermutation3++){
            cutString += Form(",pi0Cut%d",iPermutation3);
         }
      }
      //reject alternative combination
      if (tag==TString("etaPrime")){
         Int_t iPermutation2 = 5-iPermutation;
         FSCut::defineCut(Form("rejectCombination%d",iPermutation2),Form("MASS(%d,%d)>0.11&&MASS(%d,%d)<0.18",vectorIndexPermutation[iPermutation2][0],vectorIndexPermutation[iPermutation2][1],vectorIndexPermutation[iPermutation2][0],vectorIndexPermutation[iPermutation2][1]));
         cutString += Form(",rejectCombination%d",iPermutation2);
      }
      cutString += ")";
      cout << cutString << endl;
      TH1F* h = FSModeHistogram::getTH1F(fileName,treeName,"",Form("MASS(%d,%d)",vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1]),binning,cutString);
      if (iPermutation==0) h1GammaGammaMass = (TH1F*)h->Clone();
      else h1GammaGammaMass->Add(h);
      h->SetTitle(Form("Mass(%d,%d) %s",vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1],cutName.Data()));
      h->SetXTitle(Form("m_{\\gamma_{%d}\\gamma_{%d}} [GeV/c^{2}]",vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1]));
      h->SetYTitle(Form("Events / %f MeV/c^{2}",(xmax-xmin)/numberOfBin*1000));
      h->Draw();
   }
   if (isGamma3Cut) {
      for (Int_t iPermutation3 = 0;iPermutation3 < 4; iPermutation3++){
         cutName += Form(",Gamma3Cut%d",iPermutation3);
      }
   }
   if (isPi0Cut3) {
      for (Int_t iPermutation3 = 0;iPermutation3 < 4; iPermutation3++){
         cutName += Form(",pi0Cut%d",iPermutation3);
      }
   }
   c->SaveAs(Form("Mass2Combination_%s_%s.pdf",cutName.Data(),tag.Data()));
   if (tag==TString("etaPrime")){
      c->Clear();
      c->Divide(1,1);
      h1GammaGammaMass->SetTitle("Sum of combination of #gamma#gamma invariant mass");
      h1GammaGammaMass->SetXTitle("m_{\\gamma\\gamma} [GeV/c^{2}]");
      h1GammaGammaMass->Draw();
      c->SaveAs(Form("Mass2Combination_Total_%s_%s.pdf",cutName.Data(),tag.Data()));
   }
   delete c;
}

void PlotMass3GammaCombination(TString fileName, TString treeName, Int_t numberOfBin, Double_t xmin, Double_t xmax, TString cutName, TString tag, Bool_t isGamma3Cut = kFALSE, Bool_t isPi0Cut3 = kFALSE){
   Int_t vectorIndexPermutation[4][3] = {{2,3,4},{2,3,5},{2,4,5},{3,4,5}};
   TString binning = Form("(%d,%f,%f)",numberOfBin,xmin,xmax);
   TCanvas *c = new TCanvas("c","c",800,600);
   c->Divide(2,2);
   for (Int_t iPermutation = 0; iPermutation < 4; iPermutation++){
      c->cd(iPermutation+1);
      TString cutString = "CUT(";
      cutString += cutName;
      if (isGamma3Cut) {
         FSCut::defineCut("Gamma3Cut",GetCutStringMass3GammaCombination(vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1],vectorIndexPermutation[iPermutation][2]).Data());
         cutString += ",Gamma3Cut";
      }
      if (isPi0Cut3) {
         FSCut::defineCut("pi0Cut3",GetPi0CutStringMass3Combination(vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1],vectorIndexPermutation[iPermutation][2]).Data());
         cutString += ",pi0Cut3";
      }
      cutString += ")";
      cout << cutString << endl;
      TH1F* h = FSModeHistogram::getTH1F(fileName,treeName,"",Form("MASS(%d,%d,%d)",vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1],vectorIndexPermutation[iPermutation][2]),binning,cutString);
      h->SetTitle(Form("Mass(%d,%d,%d) %s",vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1],vectorIndexPermutation[iPermutation][2],cutName.Data()));
      h->SetXTitle(Form("m_{\\gamma_{%d}\\gamma_{%d}\\gamma_{%d}} [GeV/c^{2}]",vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1],vectorIndexPermutation[iPermutation][2]));
      h->SetYTitle(Form("Events / %f MeV/c^{2}",(xmax-xmin)/numberOfBin*1000));
      h->Draw();
   }
   if (isGamma3Cut) cutName += "_Gamma3Cut";
   if (isPi0Cut3) cutName += "_pi0Cut3";
   c->SaveAs(Form("Mass3Combination_%s_%s.pdf",cutName.Data(),tag.Data()));
   delete c;
}

void PlotMass4Gamma(TString fileName, TString treeName, Int_t numberOfBin, Double_t xmin, Double_t xmax, TString cutName, TString tag, Bool_t isGamma3Cut = kFALSE, Bool_t isPi0Cut3 = kFALSE, Bool_t isPi0Select = kFALSE, Bool_t isEtaPrimeSelect = kFALSE){
   Int_t vectorIndexPermutation[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   TString binning = Form("(%d,%f,%f)",numberOfBin,xmin,xmax);
   TCanvas *c = new TCanvas("c","c",800,600);
   TH1F *h1_4GammaMass;
   c->Divide(3,2);
   Bool_t isSidebandSub=kTRUE;
   if (isGamma3Cut) {
      Int_t vectorIndexPermutation3[4][3] = {{2,3,4},{2,3,5},{2,4,5},{3,4,5}};
      for (Int_t iPermutation3 = 0;iPermutation3 < 4; iPermutation3++){
         FSCut::defineCut(Form("Gamma3Cut%d",iPermutation3),GetCutStringMass3GammaCombination(vectorIndexPermutation3[iPermutation3][0],vectorIndexPermutation3[iPermutation3][1],vectorIndexPermutation3[iPermutation3][2]).Data());
      }
   }
   if (isPi0Cut3) {
      Int_t vectorIndexPermutation3[4][3] = {{2,3,4},{2,3,5},{2,4,5},{3,4,5}};
      for (Int_t iPermutation3 = 0;iPermutation3 < 4; iPermutation3++){
         FSCut::defineCut(Form("pi0Cut%d",iPermutation3),GetPi0CutStringMass3Combination(vectorIndexPermutation3[iPermutation3][0],vectorIndexPermutation3[iPermutation3][1],vectorIndexPermutation3[iPermutation3][2]).Data());
      }
   }
   for (Int_t iPermutation = 0;iPermutation < 6; iPermutation++){
      c->cd(iPermutation+1);
      TString cutString = "CUT(";
      cutString += cutName;
      if (isGamma3Cut) {
         for (Int_t iPermutation3 = 0;iPermutation3 < 4; iPermutation3++){
            cutString += Form(",Gamma3Cut%d",iPermutation3);
         }
      }
      if (isPi0Cut3) {
         for (Int_t iPermutation3 = 0;iPermutation3 < 4; iPermutation3++){
            cutString += Form(",pi0Cut%d",iPermutation3);
         }
      }
      if (isPi0Select) {
         Int_t iPermutation2 = 5-iPermutation;
         // FSCut::defineCut(Form("pi0Select%d",iPermutation2),Form("MASS(%d,%d)>0.11&&MASS(%d,%d)<0.16",vectorIndexPermutation[iPermutation2][0],vectorIndexPermutation[iPermutation2][1],vectorIndexPermutation[iPermutation2][0],vectorIndexPermutation[iPermutation2][1]));
         cutString += Form(",pi0Select%d",iPermutation2);
      }
      if (isEtaPrimeSelect && !isSidebandSub) {
         // FSCut::defineCut(Form("etaPrimeSelect%d",iPermutation),Form("MASS(%d,%d)>0.93&&MASS(%d,%d)<0.99",vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1],vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1]));
         cutString += Form(",etaPrimeSelect%d",iPermutation);
      }
      cutString += ")";
      if (isEtaPrimeSelect && isSidebandSub) {
         cutString += "&&";
         cutString += Form("CUTSB(etaPrimeSelect%d)",iPermutation);
      }
      cout << "Gamma index combination: " << vectorIndexPermutation[iPermutation][0] << vectorIndexPermutation[iPermutation][1] << vectorIndexPermutation[5-iPermutation][0] << vectorIndexPermutation[5-iPermutation][1] << endl;
      cout << cutString << endl;
      TH1F* h = FSModeHistogram::getTH1F(fileName,treeName,"",Form("MASS(%d,%d,%d,%d)",vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1],vectorIndexPermutation[5-iPermutation][0],vectorIndexPermutation[5-iPermutation][1]),binning,cutString);
      h->SetTitle(Form("Selection: \\eta'(\\gamma_{%d}\\gamma_{%d}) & \\pi^{0}(\\gamma_{%d}\\gamma_{%d}) %s",vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1],vectorIndexPermutation[5-iPermutation][0],vectorIndexPermutation[5-iPermutation][1],cutName.Data()));
      h->SetXTitle(Form("m_{\\gamma_{%d}\\gamma_{%d}\\gamma_{%d}\\gamma_{%d}} [GeV/c^{2}]",vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1],vectorIndexPermutation[5-iPermutation][0],vectorIndexPermutation[5-iPermutation][1]));
      h->SetYTitle(Form("Events / %f MeV/c^{2}",(xmax-xmin)/numberOfBin*1000));
      h->Draw();
      if (iPermutation == 0) h1_4GammaMass = (TH1F*)h->Clone("h1_4GammaMass");
      else h1_4GammaMass->Add(h);
   }
   if (isGamma3Cut) cutName += "_Gamma3Cut";
   if (isPi0Cut3) cutName += "_pi0Cut3";
   if (isPi0Select) cutName += "_pi0Select";
   if (isEtaPrimeSelect) cutName += "_etaPrimeSelect";
   c->SaveAs(Form("Mass4Gamma_%s_%s.pdf",cutName.Data(),tag.Data()));
   c->Clear();
   c->Divide(1,1);
   c->cd(1);
   h1_4GammaMass->SetTitle("Total 4#gamma invariant mass");
   h1_4GammaMass->SetXTitle("m_{4#gamma} [GeV/c^{2}]");
   h1_4GammaMass->SetYTitle(Form("Events / %f MeV/c^{2}",(xmax-xmin)/numberOfBin*1000));
   h1_4GammaMass->Draw();
   c->SaveAs(Form("Mass4GammaTotal_%s_%s.pdf",cutName.Data(),tag.Data()));
   delete c;
}

TString GetCutStringMass3GammaCombination(Int_t vectorIndex1,Int_t vectorIndex2,Int_t vectorIndex3){
   TString cutString = Form("MASS(%d,%d,%d)<0.7||MASS(%d,%d,%d)>0.9&&MASS(%d,%d,%d)<2.4",vectorIndex1,vectorIndex2,vectorIndex3,vectorIndex1,vectorIndex2,vectorIndex3,vectorIndex1,vectorIndex2,vectorIndex3);
   return cutString;
}

TString GetPi0CutStringMass3Combination(Int_t vectorIndex1,Int_t vectorIndex2,Int_t vectorIndex3){
   TString cutString = Form("MASS(%d,%d,%d)<0.11 || MASS(%d,%d,%d)>0.18",vectorIndex1,vectorIndex2,vectorIndex3,vectorIndex1,vectorIndex2,vectorIndex3);
   return cutString;
}

//plot custom 1D histogram with cuts
void Plot1DHistWithCuts(TString fileName, TString treeName, TString varName, TString cutName, TString tag, 
                        Int_t numberOfXBin, Double_t xmin, Double_t xmax, TString xTitle, TString yTitle, TString title,
                        Bool_t isEnableCombination, Bool_t isCanvasDivide, Int_t numberOfXPad, Int_t numberOfYPad,
                        Bool_t isGamma3Cut = kFALSE, Bool_t isPi0Cut3 = kFALSE, Bool_t isPi0Select = kFALSE, Bool_t isEtaPrimeSelect = kFALSE){
      
   TString binning = Form("(%d,%f,%f)",numberOfXBin,xmin,xmax);
   TCanvas* c = new TCanvas("c","c",800,600);
   if (isCanvasDivide) c->Divide(numberOfXPad,numberOfYPad);
   if (isEnableCombination){
      Int_t vectorIndexPermutation[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
      for (Int_t iPermutation=0;iPermutation<6;iPermutation++){
         //build cut string
         TString cutString = "CUT(";
         cutString += cutName;
         if (isGamma3Cut) {
            for (Int_t iPermutation3 = 0;iPermutation3 < 4; iPermutation3++){
               cutString += Form(",Gamma3Cut%d",iPermutation3);
            }
         }
         if (isPi0Select) {
            Int_t iPermutation2 = 5-iPermutation;
            cutString += Form(",pi0Select%d",iPermutation2);
         }
         if (isEtaPrimeSelect) {
            cutString += Form(",etaPrimeSelect%d",iPermutation);
         }
         cutString += ")";
         cout << cutString << endl;
         //plot histogram
         TH1F* h = FSModeHistogram::getTH1F(fileName,treeName,"",Form("%s(%d,%d,%d,%d)",varName.Data(),vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1],vectorIndexPermutation[5-iPermutation][0],vectorIndexPermutation[5-iPermutation][1]),binning,cutString);
         if (isCanvasDivide) c->cd(iPermutation+1);
         h->SetTitle(Form("%s(%d,%d,%d,%d)",title.Data(),vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1],vectorIndexPermutation[5-iPermutation][0],vectorIndexPermutation[5-iPermutation][1]));
         h->SetXTitle(xTitle.Data());
         h->SetYTitle(yTitle.Data());
         h->Sumw2();
         h->Draw();
      }
   }
   else{
      TString cutString = "CUT(";
      cutString += cutName;
      for (Int_t iPermutation=0;iPermutation<6;iPermutation++){
         if (isGamma3Cut) {
            for (Int_t iPermutation3 = 0;iPermutation3 < 4; iPermutation3++){
               cutString += Form(",Gamma3Cut%d",iPermutation3);
            }
         }
         if (isPi0Select) {
            Int_t iPermutation2 = 5-iPermutation;
            cutString += Form(",pi0Select%d",iPermutation2);
         }
         if (isEtaPrimeSelect) {
            cutString += Form(",etaPrimeSelect%d",iPermutation);
         }
      }
      cutString += ")";
      cout << cutString << endl;
      // cout << binning << endl;
      TH1F* h = FSModeHistogram::getTH1F(fileName,treeName,"",varName,binning,cutString);
      h->SetTitle(title.Data());
      h->SetXTitle(xTitle.Data());
      h->SetYTitle(yTitle.Data());
      h->Sumw2();
      h->Draw();
   }
   if (isEnableCombination) c->SaveAs(Form("%s_%s_%s_combinationTrue.pdf",varName.Data(),cutName.Data(),tag.Data()));
   else c->SaveAs(Form("%s_%s_%s_combinationFalse.pdf",varName.Data(),cutName.Data(),tag.Data()));
   delete c;
}

//plot custom 2D histogram with cuts
void Plot2DHistWithCuts(TString fileName, TString treeName, TString varName, TString cutName, TString tag, 
                        Int_t numberOfXBin, Double_t xmin, Double_t xmax, TString xTitle, Int_t numberOfYBin, Double_t ymin, Double_t ymax, TString yTitle, TString title,
                        Bool_t isEnableCombination, Bool_t isCanvasDivide, Int_t numberOfXPad, Int_t numberOfYPad,
                        Bool_t isGamma3Cut = kFALSE, Bool_t isPi0Cut3 = kFALSE, Bool_t isPi0Select = kFALSE, Bool_t isEtaPrimeSelect = kFALSE){

}

void DefineGamma3Cuts(){
   Int_t vectorIndexPermutation3[4][3] = {{2,3,4},{2,3,5},{2,4,5},{3,4,5}};
   for (Int_t iPermutation3 = 0;iPermutation3 < 4; iPermutation3++){
      FSCut::defineCut(Form("Gamma3Cut%d",iPermutation3),GetCutStringMass3GammaCombination(vectorIndexPermutation3[iPermutation3][0],vectorIndexPermutation3[iPermutation3][1],vectorIndexPermutation3[iPermutation3][2]).Data());
   }
}

void DefinePi0SelectCuts(){
   Int_t vectorIndexPermutation[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   for (Int_t iPermutation2 = 5;iPermutation2 >= 0; iPermutation2--){
      FSCut::defineCut(Form("pi0Select%d",iPermutation2),Form("MASS(%d,%d)>0.11&&MASS(%d,%d)<0.16",vectorIndexPermutation[iPermutation2][0],vectorIndexPermutation[iPermutation2][1],vectorIndexPermutation[iPermutation2][0],vectorIndexPermutation[iPermutation2][1]));
   }
}

void DefineEtaPrimeSelectCuts(){
   Int_t vectorIndexPermutation[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   Bool_t isSidebandSub = kTRUE;
   for (Int_t iPermutation = 0;iPermutation < 6; iPermutation++) {
      TString SelectMassString = Form("MASS(%d,%d)>0.93&&MASS(%d,%d)<0.99",vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1],vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1]);
      if (!isSidebandSub) FSCut::defineCut(Form("etaPrimeSelect%d",iPermutation),SelectMassString.Data());
      else {
         TString SelectMassSBString = Form("(MASS(%d,%d)>0.885&&MASS(%d,%d)<0.905)",vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1],vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1]);
         SelectMassSBString += "||";
         SelectMassSBString += Form("(MASS(%d,%d)>1.02&&MASS(%d,%d)<1.04)",vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1],vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1]);
         cout << SelectMassString << ", " << SelectMassSBString << endl;
         FSCut::defineCut(Form("etaPrimeSelect%d",iPermutation),SelectMassString.Data(),SelectMassSBString.Data(),0.75);
      }
   }
}