// Description: Event selection for the EtapPi0_4gamma analysis

TString FND("/d/grid17/sdobbs/gluex_data/EtapPi0_4gamma/skimmed/tree_pi0eta__B4_M17_M7_FLAT_PRESKIM_*.root");
TString FNMC("/d/grid17/sdobbs/gluex_data/EtapPi0_4gamma/skimmed/tree_pi0eta__B4_M17_M7_FLAT_MC_PRESKIM*.root");
TString FNMCGen("/d/grid17/septian/EtaPPi0_4Gamma/2018S/MCThrown_flat_FSRoot.root");

TString NT("ntFSGlueX_MODECODE");

void chi2Ranking(){
   FSModeCollection::addModeInfo("100_4000000");
   FSModeTree::createChi2RankingTree(FND,NT,"","abs(RFDeltaT)<2.0");
   FSModeTree::createChi2RankingTree(FNMC,NT,"","abs(RFDeltaT)<2.0");
}

void PlotMass2GammaCombination(TString fileName, TString treeName, Int_t numberOfBin, Double_t xmin, Double_t xmax, TString cutName, TString tag, Bool_t isGamma3Cut, Bool_t isPi0Cut3, Bool_t isLMACut, Bool_t isSidebandSub);
void PlotMass3GammaCombination(TString fileName, TString treeName, Int_t numberOfBin, Double_t xmin, Double_t xmax, TString cutName, TString tag, Bool_t isGamma3Cut, Bool_t isPi0Cut3, Bool_t isSidebandSub);
void PlotMass4Gamma(TString fileName, TString treeName, Int_t numberOfBin, Double_t xmin, Double_t xmax, TString cutName, TString tag, Bool_t isGamma3Cut, Bool_t isPi0Cut3, Bool_t isPi0Select, Bool_t isEtaPrimeSelect, Bool_t isLMACut, Bool_t is2DEtaPi0Cut, Bool_t isSidebandSub, Bool_t isIncludeMC = kFALSE, TString fileNameMC = "", TString fileNameMCThrown = "", TString mcThrownCutName = "");
TString GetCutStringMass3GammaCombination(Int_t vectorIndex1,Int_t vectorIndex2,Int_t vectorIndex3);
TString GetPi0CutStringMass3Combination(Int_t vectorIndex1,Int_t vectorIndex2,Int_t vectorIndex3);
void Plot1DHistWithCuts(TString fileName, TString treeName, TString varName, TString cutName, TString tag, 
                        Int_t numberOfXBin, Double_t xmin, Double_t xmax, TString xTitle, TString yTitle, TString title,
                        Bool_t isEnableCombination, Bool_t isCanvasDivide, Int_t numberOfXPad, Int_t numberOfYPad,
                        Bool_t isGamma3Cut = kFALSE, Bool_t isPi0Cut3 = kFALSE, Bool_t isPi0Select = kFALSE, Bool_t isEtaPrimeSelect = kFALSE);
void Plot2DHistWithCuts(TString fileName, TString treeName, TString varNameX, TString varNameY, TString cutName, TString tag, 
                        Int_t numberOfXBin, Double_t xmin, Double_t xmax, TString xTitle, Int_t numberOfYBin, Double_t ymin, Double_t ymax, TString yTitle, TString title,
                        Bool_t isSidebandSub, Int_t etaPrimeSelectNumber);
TH2F* Get2DHistWithCuts(TString fileName, TString treeName, TString varNameX, TString varNameY, TString cutName, TString tag, 
                        Int_t numberOfXBin, Double_t xmin, Double_t xmax, TString xTitle, Int_t numberOfYBin, Double_t ymin, Double_t ymax, TString yTitle, TString title,
                        Bool_t isSidebandSub, Int_t etaPrimeSelectNumber);
void DefineGamma3Cuts();
void DefinePi0SelectCuts();
void DefineEtaPrimeSelectCuts();
void DefineLMACuts();
void Define2DAlternativePi0Cuts();
void Define2DAlternativeEtaCuts();

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
   FSCut::defineCut("protMom","MOMENTUM(1)>=0.3");
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

   FSCut::defineCut("allBase","CUT(unusedE,unusedTracks,zProton,protMom,e8288,chi2lt2,rank1,photFiducialA,photFiducialB,photFiducialC,photFiducialD)");
   FSCut::defineCut("allBaseChi2Rank2","CUT(unusedE,unusedTracks,zProton,protMom,e8288,chi2lt2,rank2,rf,photFiducialA,photFiducialB,photFiducialC,photFiducialD)");
   FSCut::defineCut("allBaseChi2Rank3","CUT(unusedE,unusedTracks,zProton,protMom,e8288,chi2lt2,rank3,rf,photFiducialA,photFiducialB,photFiducialC,photFiducialD)");
   FSCut::defineCut("allBaseChi2Rank4","CUT(unusedE,unusedTracks,zProton,protMom,e8288,chi2lt2,rank4,rf,photFiducialA,photFiducialB,photFiducialC,photFiducialD)");
   FSCut::defineCut("allBaseChi2Rank5","CUT(unusedE,unusedTracks,zProton,protMom,e8288,chi2lt2,rank5,rf,photFiducialA,photFiducialB,photFiducialC,photFiducialD)");
   FSCut::defineCut("allBaseChi2Rank6","CUT(unusedE,unusedTracks,zProton,protMom,e8288,chi2lt2,rank6,rf,photFiducialA,photFiducialB,photFiducialC,photFiducialD)");
   // FSCut::defineCut("TestCut","CUT(unusedE,unusedTracks,zProton,protMom,e8288,rank1,rf,photFiducialA,photFiducialB,photFiducialC,photFiducialD)")
   // FSCut::defineCut("preSkim","CUT(unusedE,unusedTracks,zProton,protMom,e8288,chi2)");
   FSCut::defineCut("numCombos1","NumCombos==1");

   // VARIABLE CUTS
   FSCut::defineCut("cet0103","OR(abs(-1*MASS2(GLUEXTARGET,-1)-0.2)<0.1)");    // 0.1 < t < 0.3
   FSCut::defineCut("cet0305","OR(abs(-1*MASS2(GLUEXTARGET,-1)-0.4)<0.1)");    // 0.3 < t < 0.5
   FSCut::defineCut("cet0507","OR(abs(-1*MASS2(GLUEXTARGET,-1)-0.6)<0.1)");    // 0.5 < t < 0.7
   FSCut::defineCut("cet0710","OR(abs(-1*MASS2(GLUEXTARGET,-1)-0.85)<0.15)");    // 0.7 < t < 1.0
   FSCut::defineCut("cet1014","OR(abs(-1*MASS2(GLUEXTARGET,-1)-1.2)<0.2)");    // 1.0 < t < 1.4
   FSCut::defineCut("cet1418","OR(abs(-1*MASS2(GLUEXTARGET,-1)-1.6)<0.2)");    // 1.4 < t < 1.8

   FSCut::defineCut("t_lt1","abs(MASS2(GLUEXTARGET,-1))<1.0");    //|t| < 1.0
   FSCut::defineCut("t_lt0.5","abs(MASS2(GLUEXTARGET,-1))<0.5");    //|t| < 0.5
   FSCut::defineCut("mct_lt0.5","abs(MCMASS2(GLUEXTARGET,-1))<0.5"); //|t| < 0.5 for MC thrown

   DefineGamma3Cuts();
   DefinePi0SelectCuts();
   DefineEtaPrimeSelectCuts();
   DefineLMACuts();
   Define2DAlternativePi0Cuts();
   Define2DAlternativeEtaCuts();

   FSControl::DEBUG=0;

   FSTree::defineMacro("MANDELSTAM_T",1,"(pow(((-EnP[I]+0.938272)),2)-pow(((-PxP[I]+0.0)),2)-pow(((-PyP[I]+0.0)),2)-pow(((-PzP[I]+0.0)),2))");

}

void eventSelection(){
   setup();

   //declare costheta_gj variables
   Int_t vectorIndexPermutation[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   TString COSTHETAGJ[6]; 
   for (Int_t iPermutation=0;iPermutation<6;iPermutation++) {
      COSTHETAGJ[iPermutation] = Form("FSMath::gjcostheta("
                                  "(PxP%d+PxP%d),(PyP%d+PyP%d),(PzP%d+PzP%d),(EnP%d+EnP%d),"
                                  "(PxP%d+PxP%d),(PyP%d+PyP%d),(PzP%d+PzP%d),(EnP%d+EnP%d),"
                                  "PxPB,PyPB,PzPB,EnPB)",
                                  vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1], vectorIndexPermutation[iPermutation][0], vectorIndexPermutation[iPermutation][1], vectorIndexPermutation[iPermutation][0], vectorIndexPermutation[iPermutation][1], vectorIndexPermutation[iPermutation][0], vectorIndexPermutation[iPermutation][1], 
                                  vectorIndexPermutation[5-iPermutation][0], vectorIndexPermutation[5-iPermutation][1], vectorIndexPermutation[5-iPermutation][0], vectorIndexPermutation[5-iPermutation][1],vectorIndexPermutation[5-iPermutation][0], vectorIndexPermutation[5-iPermutation][1],vectorIndexPermutation[5-iPermutation][0], vectorIndexPermutation[5-iPermutation][1]
                                  );
      // cout << COSTHETAGJ[iPermutation] << endl;
   }

   //explore Monte Carlo data
   // all Base cuts
   // PlotMass2GammaCombination(FNMC,NT,100,0.0,2.00,"allBase","MC",kFALSE,kFALSE,kFALSE,kFALSE);
   // PlotMass3GammaCombination(FNMC,NT,100,0.0,3.00,"allBase","MC",kFALSE,kFALSE,kFALSE);
   // PlotMass4Gamma(FNMC,NT,200,0.0,4.0,"allBase","MC",kFALSE,kFALSE,kFALSE,kFALSE,kFALSE,kFALSE);

   // PlotMass2GammaCombination(FNMC,NT,100,0.0,2.00,"allBase","MC",kFALSE,kFALSE,kFALSE,kFALSE);
   // PlotMass3GammaCombination(FNMC,NT,100,0.0,3.00,"allBase","MC",kFALSE,kFALSE,kFALSE);
   // PlotMass4Gamma(FNMC,NT,200,0.0,4.0,"allBase","MC",kFALSE,kFALSE,kFALSE,kFALSE,kFALSE,kFALSE);

   // all base + pi0 & eta prime alternative selection
   // PlotMass4Gamma(FNMC,NT,150,0.0,4.0,"allBase","MC",kFALSE,kFALSE,kTRUE,kTRUE,kFALSE,kFALSE);

   // all base + pi0 & eta prime alternative selection + LMA
   // PlotMass4Gamma(FNMC,NT,150,0.0,4.0,"allBase","MC_LMA",kFALSE,kFALSE,kTRUE,kTRUE,kTRUE,kFALSE);

   // FSModeHistogram::readHistogramCache();
   // PlotMass4Gamma(FND,NT,150,0.0,3.0,"allBase","LMA",kFALSE,kFALSE,kTRUE,kTRUE,kTRUE,kFALSE,kTRUE,FNMC,FNMCGen);
   // PlotMass4Gamma(FND,NT,150,0.0,3.0,"allBase","LMA_SSB",kFALSE,kFALSE,kTRUE,kTRUE,kTRUE,kTRUE,kTRUE,FNMC,FNMCGen);
   // PlotMass4Gamma(FND,NT,150,0.0,3.0,"allBase,t_lt0.5","LMA",kFALSE,kFALSE,kTRUE,kTRUE,kTRUE,kFALSE,kTRUE,FNMC,FNMCGen);
   // PlotMass4Gamma(FND,NT,150,0.0,3.0,"allBase,t_lt0.5","LMA_SSB",kFALSE,kFALSE,kTRUE,kTRUE,kTRUE,kTRUE,kTRUE,FNMC,FNMCGen);
   

   // TCanvas *c1 = new TCanvas("c1","c1",800,600);
   // TH1F* h1 = FSModeHistogram::getTH1F(FNMCGen,NT,"","MCMASS(2,5)","(200,0.0,2.0)","CUT(mcebeam)"); 
   // h1->SetXTitle("M_{#gamma_{2}#gamma_{5}} (GeV)");
   // h1->SetYTitle("Events");
   // h1->Draw("HIST");
   // c1->SaveAs("MC_thown_m25.pdf");

   // TH1F* h2 = FSModeHistogram::getTH1F(FNMCGen,NT,"","MCMASS(3,4)","(200,0.0,2.0)","CUT(mcebeam)");
   // h2->SetXTitle("M_{#gamma_{3}#gamma_{4}} (GeV)");
   // h2->SetYTitle("Events");
   // h2->Draw("HIST");
   // c1->SaveAs("MC_thown_m34.pdf");

   // Plot2DHistWithCuts(FND, NT, "MASS(2,4,5)", "MASS(2,3)", "allBase,pi0Select5,2DPiAC0,2DEtaAC0", "mass245_mass23",
   //                      150,0.0,3.0, "m_{#gamma2#gamma4#gamma5} (GeV)", 40,0.85,1.05, "m_{#gamma2#gamma3} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FND, NT, "MASS(3,4,5)", "MASS(2,3)", "allBase,pi0Select5,2DPiAC0,2DEtaAC0", "mass345_mass23",
   //                      150,0.0,3.0, "m_{#gamma3#gamma4#gamma5} (GeV)", 40,0.85,1.05, "m_{#gamma2#gamma3} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);
   
   // Plot2DHistWithCuts(FNMC, NT, "MCMASS(2,4,5)", "MCMASS(2,3)", "allBase,pi0Select5,2DPiAC0,2DEtaAC0", "mass245_mass23",
   //                      150,0.0,3.0, "m_{#gamma2#gamma4#gamma5} (GeV)", 40,0.85,1.05, "m_{#gamma2#gamma3} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMC, NT, "MCMASS(3,4,5)", "MCMASS(2,3)", "allBase,pi0Select5,2DPiAC0,2DEtaAC0", "mass345_mass23",
   //                      150,0.0,3.0, "m_{#gamma3#gamma4#gamma5} (GeV)", 40,0.85,1.05, "m_{#gamma2#gamma3} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // check 2DPiAC effect on etaPrime peak 
   // Plot2DHistWithCuts(FND, NT, "MASS(2,4)", "MASS(3,5)", "allBase,pi0Select5,etaPrimeSelect0,2DPiAC0", "mass(2,4)_vs_mass(3,5)",
   //                      50,0.0,1.0, "m_{#gamma2#gamma4}", 50, 0.0, 1.0, "m_{#gamma3#gamma5}", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);
   // Plot2DHistWithCuts(FND, NT, "MASS(2,5)", "MASS(3,4)", "allBase,pi0Select5,etaPrimeSelect0,2DPiAC0", "mass(2,5)_vs_mass(3,4)",
   //                      50,0.0,1.0, "m_{#gamma2#gamma5}", 50, 0.0, 1.0, "m_{#gamma3#gamma4}", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase","etaPrime",kFALSE,kFALSE,kFALSE,kFALSE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase","etaPrimeLMAC",kFALSE,kFALSE,kTRUE,kFALSE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase","etaPrime2DPiAC",kFALSE,kFALSE,kFALSE,kFALSE);
   // FSModeHistogram::dumpHistogramCache("histograms/2DAlternativePiEtaCuts_etaPrime");

   // Plot1DHistWithCuts(FND, NT, "MASS(2,3)", "allBase,pi0Select5,LMAC0", "",
   //                      50,0.85,1.05, "m_{#gamma2#gamma3} (GeV)", "Events", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, kFALSE, 0, 0,
   //                      kFALSE, kFALSE, kFALSE, kFALSE);

   // Plot1DHistWithCuts(FND, NT, "MASS(2,3)", "allBase,pi0Select5,2DPiAC0", "",
   //                      50,0.85,1.05, "m_{#gamma2#gamma3} (GeV)", "Events", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, kFALSE, 0, 0,
   //                      kFALSE, kFALSE, kFALSE, kFALSE);

   // Plot1DHistWithCuts(FND, NT, "MASS(2,3)", "allBase,pi0Select5,2DPiAC0,Gamma3Cut3", "",
   //                      50,0.85,1.05, "m_{#gamma2#gamma3} (GeV)", "Events", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, kFALSE, 0, 0,
   //                      kFALSE, kFALSE, kFALSE, kFALSE);
   
   // Plot1DHistWithCuts(FND, NT, "MASS(2,3)", "allBase,pi0Select5,2DPiAC0,Gamma3Cut2,Gamma3Cut3", "",
   //                      50,0.85,1.05, "m_{#gamma2#gamma3} (GeV)", "Events", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, kFALSE, 0, 0,
   //                      kFALSE, kFALSE, kFALSE, kFALSE);

      // Plot1DHistWithCuts(FND, NT, "NumCombos", "allBase", "NumCombos", 
   //                   11, -0.5, 10.5, "Number of Combos", "counts", "allBase",
   //                   kFALSE, kFALSE, 0, 0,
   //                   kFALSE, kFALSE, kFALSE, kFALSE);

   // check 2DEtaAC effect on etaPrime peak 
   // 1st combination
   // Plot2DHistWithCuts(FND, NT, "MASS(2,4)", "MASS(3,5)", "allBase,pi0Select5,etaPrimeSelect0,2DPiAC0,2DEtaAC0", "mass(2,4)_vs_mass(3,5)",
   //                      50,0.0,1.0, "m_{#gamma2#gamma4}", 50, 0.0, 1.0, "m_{#gamma3#gamma5}", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);
   // Plot2DHistWithCuts(FND, NT, "MASS(2,5)", "MASS(3,4)", "allBase,pi0Select5,etaPrimeSelect0,2DPiAC0,2DEtaAC0", "mass(2,5)_vs_mass(3,4)",
   //                      50,0.0,1.0, "m_{#gamma2#gamma5}", 50, 0.0, 1.0, "m_{#gamma3#gamma4}", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // 2nd combination
   // Plot2DHistWithCuts(FND, NT, "MASS(2,5)", "MASS(3,4)", "allBase,pi0Select4,etaPrimeSelect1,2DPiAC1,2DEtaAC1", "mass(2,5)_vs_mass(3,4)",
   //                      50,0.0,1.0, "m_{#gamma2#gamma5}", 50, 0.0, 1.0, "m_{#gamma3#gamma4}", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{4} & #pi^{0} #rightarrow #gamma_{3}#gamma_{5}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FND, NT, "MASS(2,3)", "MASS(4,5)", "allBase,pi0Select4,etaPrimeSelect1,2DPiAC1,2DEtaAC1", "mass(2,3)_vs_mass(4,5)",
   //                      50,0.0,1.0, "m_{#gamma2#gamma3}", 50, 0.0, 1.0, "m_{#gamma4#gamma5}", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{4} & #pi^{0} #rightarrow #gamma_{3}#gamma_{5}",
   //                      kFALSE, 0);


   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase","etaPrime",kFALSE,kFALSE,kFALSE,kFALSE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase","etaPrime2DPiAC",kFALSE,kFALSE,kFALSE,kFALSE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase","etaPrime2DPiEtaAC",kFALSE,kFALSE,kFALSE,kFALSE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase","etaPrimeLMAC",kFALSE,kFALSE,kTRUE,kFALSE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase","etaPrimeLMAC",kTRUE,kFALSE,kTRUE,kFALSE);

   // FSModeHistogram::dumpHistogramCache("histograms/2DAlternative3GammaOmegaCuts_etaPrime");


   // PlotMass3GammaCombination(FND,NT,150,0.,3.0,"allBase,pi0Select5","1stCombinationSSB",kFALSE,kFALSE,kTRUE);
   // PlotMass3GammaCombination(FND,NT,150,0.,3.0,"allBase,pi0Select5,2DPiAC0","1stCombinationSSB_2DPiAC0",kFALSE,kFALSE,kTRUE);
   // PlotMass3GammaCombination(FND,NT,150,0.,3.0,"allBase,pi0Select5,2DPiAC0,2DEtaAC0","1stCombinationSSB_2DPiAC0_2DEtaAC0",kFALSE,kFALSE,kTRUE);
   // PlotMass3GammaCombination(FND,NT,150,0.,3.0,"allBase,pi0Select5,LMAC0","1stCombinationSSB",kFALSE,kFALSE,kTRUE);
   // FSModeHistogram::dumpHistogramCache("histograms/3GammaMass_1stCombinationSSB_pi0Select5,2DPiAC0,2DEtaAC0");

   // FSModeHistogram::readHistogramCache();
   // PlotMass4Gamma(FND,NT,50,1.0,3.0,"allBase,t_lt0.5","2DEtaPi0AC_SSB",kFALSE,kFALSE,kTRUE,kTRUE,kFALSE,kTRUE,kTRUE,kTRUE,FNMC,FNMCGen,"CUT(mcebeam,mct_lt0.5)");
   // FSModeHistogram::dumpHistogramCache();

   // skim tree for all combination with allBase + 2DPiAC0 + 2DEtaAC0
   for (Int_t iCombination=0;iCombination<6;iCombination++) {
      FSTree::skimTree(FND,"ntFSGlueX_100_4000000",Form("/d/grid17/septian/EtaPPi0_4Gamma/2018S/skimmedTree/skimmedTree_AllCombination_2DPi0EtaAC_%d.root",iCombination),Form("CUT(allBase,etaPrimeSelect%d,pi0Select%d,2DPiAC%d,2DEtaAC%d)",iCombination,5-iCombination,iCombination,iCombination));
   }

 }

void PlotMass2GammaCombination(TString fileName, TString treeName, Int_t numberOfBin, Double_t xmin, Double_t xmax, TString cutName, TString tag, Bool_t isGamma3Cut = kFALSE, Bool_t isPi0Cut3 = kFALSE, Bool_t isLMACut = kFALSE, Bool_t isSidebandSub = kFALSE){
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
      if (tag==TString("etaPrime") || tag==TString("etaPrimeSSB") || tag==TString("etaPrimeLMAC") || tag==TString("etaPrime2DPiAC") || tag==TString("etaPrime2DPiEtaAC")){
         Int_t iPermutation2 = 5-iPermutation;
         FSCut::defineCut(Form("rejectCombination%d",iPermutation2),Form("MASS(%d,%d)>0.11&&MASS(%d,%d)<0.18",vectorIndexPermutation[iPermutation2][0],vectorIndexPermutation[iPermutation2][1],vectorIndexPermutation[iPermutation2][0],vectorIndexPermutation[iPermutation2][1]));
         cutString += Form(",rejectCombination%d",iPermutation2);
      }
      if (isLMACut) {
         cutString += Form(",LMAC%d",iPermutation);
      }
      if (tag==TString("etaPrime2DPiAC")) {
         cutString += Form(",2DPiAC%d",iPermutation);
      }
      if (tag==TString("etaPrime2DPiEtaAC")) {
         cutString += Form(",2DPiAC%d",iPermutation);
         cutString += Form(",2DEtaAC%d",iPermutation);
      }
      cutString += ")";
      if (isSidebandSub && tag==TString("etaPrimeSSB")) {
         cutString += "&&";
         cutString += Form("CUTSUB(etaPrimeSelect%d)",iPermutation);
      }
      cout << cutString << endl;
      TH1F* h = FSModeHistogram::getTH1F(fileName,treeName,"",Form("MASS(%d,%d)",vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1]),binning,cutString);
      if (iPermutation==0) h1GammaGammaMass = (TH1F*)h->Clone();
      else h1GammaGammaMass->Add(h);
      h->SetTitle(Form("Mass(%d,%d) %s",vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1],cutName.Data()));
      h->SetXTitle(Form("m_{\\gamma_{%d}\\gamma_{%d}} [GeV/c^{2}]",vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1]));
      h->SetYTitle(Form("Events / %0.2f MeV/c^{2}",(xmax-xmin)/numberOfBin*1000));
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
   if (tag==TString("etaPrime") || tag==TString("etaPrimeLMAC") || tag==TString("etaPrime2DPiAC") || tag==TString("etaPrime2DPiEtaAC")){
      c->Clear();
      c->Divide(1,1);
      h1GammaGammaMass->SetTitle("Sum of combination of #gamma#gamma invariant mass");
      h1GammaGammaMass->SetXTitle("m_{\\gamma\\gamma} [GeV/c^{2}]");
      h1GammaGammaMass->SetYTitle(Form("Events / %0.2f MeV/c^{2}",(xmax-xmin)/numberOfBin*1000));
      h1GammaGammaMass->GetYaxis()->SetRangeUser(0,1.2*h1GammaGammaMass->GetMaximum());
      h1GammaGammaMass->Draw();
      c->SaveAs(Form("Mass2Combination_Total_%s_%s.pdf",cutName.Data(),tag.Data()));
   }
   delete c;
}

void PlotMass3GammaCombination(TString fileName, TString treeName, Int_t numberOfBin, Double_t xmin, Double_t xmax, TString cutName, TString tag, Bool_t isGamma3Cut = kFALSE, Bool_t isPi0Cut3 = kFALSE, Bool_t isSidebandSub = kFALSE){
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
      if (isSidebandSub) {
         cutString += "&&";
         cutString += "CUTSUB(etaPrimeSelect0)";
         // study first combination
      }
      cout << cutString << endl;
      TH1F* h = FSModeHistogram::getTH1F(fileName,treeName,"",Form("MASS(%d,%d,%d)",vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1],vectorIndexPermutation[iPermutation][2]),binning,cutString);
      h->SetTitle(Form("Mass(%d,%d,%d) %s",vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1],vectorIndexPermutation[iPermutation][2],cutName.Data()));
      h->SetXTitle(Form("m_{\\gamma_{%d}\\gamma_{%d}\\gamma_{%d}} [GeV/c^{2}]",vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1],vectorIndexPermutation[iPermutation][2]));
      h->SetYTitle(Form("Events / %0.2f MeV/c^{2}",(xmax-xmin)/numberOfBin*1000));
      h->Draw();
   }
   if (isGamma3Cut) cutName += "_Gamma3Cut";
   if (isPi0Cut3) cutName += "_pi0Cut3";
   c->SaveAs(Form("Mass3Combination_%s_%s.pdf",cutName.Data(),tag.Data()));
   delete c;
}

void PlotMass4Gamma(TString fileName, TString treeName, Int_t numberOfBin, Double_t xmin, Double_t xmax, TString cutName, TString tag, Bool_t isGamma3Cut = kFALSE, Bool_t isPi0Cut3 = kFALSE, Bool_t isPi0Select = kFALSE, Bool_t isEtaPrimeSelect = kFALSE, Bool_t isLMACut = kFALSE, Bool_t is2DEtaPi0Cut = kFALSE, Bool_t isSidebandSub = kFALSE, Bool_t isIncludeMC = kFALSE, TString fileNameMC = "", TString fileNameMCThrown = "", TString mcThrownCutName = ""){
   Int_t vectorIndexPermutation[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   TString binning = Form("(%d,%f,%f)",numberOfBin,xmin,xmax);
   TCanvas *c = new TCanvas("c","c",800,600);
   TH1F *h1_4GammaMass;
   TH1F *h1_4GammaMassMC;
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
      if (isLMACut) {
         cutString += Form(",LMAC%d",iPermutation);
      }
      if (is2DEtaPi0Cut) {
         cutString += Form(",2DEtaAC%d",iPermutation);
         cutString += Form(",2DPiAC%d",iPermutation);
      }
      cutString += ")";
      if (isEtaPrimeSelect && isSidebandSub) {
         cutString += "&&";
         cutString += Form("CUTSUB(etaPrimeSelect%d)",iPermutation);
      }
      cout << "Gamma index combination: " << vectorIndexPermutation[iPermutation][0] << vectorIndexPermutation[iPermutation][1] << vectorIndexPermutation[5-iPermutation][0] << vectorIndexPermutation[5-iPermutation][1] << endl;
      cout << cutString << endl;
      TH1F* h = FSModeHistogram::getTH1F(fileName,treeName,"",Form("MASS(%d,%d,%d,%d)",vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1],vectorIndexPermutation[5-iPermutation][0],vectorIndexPermutation[5-iPermutation][1]),binning,cutString);
      h->SetTitle(Form("Selection: \\eta'(\\gamma_{%d}\\gamma_{%d}) & \\pi^{0}(\\gamma_{%d}\\gamma_{%d}) %s",vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1],vectorIndexPermutation[5-iPermutation][0],vectorIndexPermutation[5-iPermutation][1],cutName.Data()));
      h->SetXTitle(Form("m_{\\gamma_{%d}\\gamma_{%d}\\gamma_{%d}\\gamma_{%d}} [GeV/c^{2}]",vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1],vectorIndexPermutation[5-iPermutation][0],vectorIndexPermutation[5-iPermutation][1]));
      h->SetYTitle(Form("Events / %0.2f MeV/c^{2}",(xmax-xmin)/numberOfBin*1000));
      h->Draw();
      if (isIncludeMC) {
         TH1F* hMC = FSModeHistogram::getTH1F(fileNameMC,treeName,"",Form("MASS(%d,%d,%d,%d)",vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1],vectorIndexPermutation[5-iPermutation][0],vectorIndexPermutation[5-iPermutation][1]),binning,cutString);
         hMC->SetLineColor(kRed);
         hMC->SetLineWidth(2);
         hMC->Draw("HIST SAME");
         if (iPermutation == 0) h1_4GammaMassMC = (TH1F*)hMC->Clone("h1_4GammaMassMC");
         else h1_4GammaMassMC->Add(hMC);   
      }
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
   h1_4GammaMass->SetYTitle(Form("Events / %0.2f MeV/c^{2}",(xmax-xmin)/numberOfBin*1000));
   h1_4GammaMass->SetMinimum(0);
   h1_4GammaMass->Draw("HIST");
   TLegend *leg = new TLegend(0.65,0.75,0.85,0.85);
   leg->SetFillColor(0);
   leg->SetBorderSize(0);
   leg->AddEntry(h1_4GammaMass,"Data","l");
   if (isIncludeMC) {
      // h1_4GammaMassMC->SetLineColor(kRed);
      // h1_4GammaMassMC->SetLineWidth(2);
      // Float_t MCScale = 0.5*h1_4GammaMass->Integral()/h1_4GammaMassMC->Integral();
      // h1_4GammaMassMC->Scale(MCScale);
      // h1_4GammaMassMC->Draw("HIST SAME");
      TH1F* h1_MCthrown = FSModeHistogram::getTH1F(fileNameMCThrown,NT,"","MCMASS(2,3,4,5)",binning,mcThrownCutName);
      TH1F* h1_acceptance = (TH1F*)h1_4GammaMassMC->Clone("h1_acceptance");
      h1_acceptance->Divide(h1_MCthrown);
      h1_acceptance->SetLineColor(kBlue);
      h1_acceptance->SetLineWidth(2);
      Float_t rightmax = 0.1;
      Float_t scale = h1_4GammaMass->GetMaximum()/rightmax;
      // gPad->GetUymax()/rightmax;
      // cout << rightmax << " " << scale << endl;
      h1_acceptance->Scale(scale);
      h1_acceptance->Draw("HIST SAME");
      auto axis_acc = new TGaxis(xmax,0.,xmax, h1_4GammaMass->GetMaximum(),0.,rightmax,210,"+L");
      axis_acc->SetLineColor(kBlue);
      axis_acc->SetLabelColor(kBlue);
      axis_acc->SetTitle("Acceptance");
      axis_acc->SetTitleColor(kBlue);
      axis_acc->SetTitleOffset(1.2);
      axis_acc->SetTitleSize(0.04);
      axis_acc->SetLabelSize(0.04);
      axis_acc->SetLabelFont(42);
      axis_acc->SetTitleFont(42);
      axis_acc->Draw();
      // leg->AddEntry(h1_4GammaMassMC,Form("MC (scale = %0.2f)",MCScale),"l");
      leg->AddEntry(h1_acceptance,"Acceptance","l");
   }
   leg->Draw();
   c->SaveAs(Form("Mass4GammaTotal_%s_%s.pdf",cutName.Data(),tag.Data()));
   delete c;
}

// TString GetCutStringMass3GammaCombination(Int_t vectorIndex1,Int_t vectorIndex2,Int_t vectorIndex3){
//    TString cutString = Form("MASS(%d,%d,%d)<2.4",vectorIndex1,vectorIndex2,vectorIndex3,vectorIndex1,vectorIndex2,vectorIndex3,vectorIndex1,vectorIndex2,vectorIndex3);
//    return cutString;
// }

// with omega 3gamma cuts
// TString GetCutStringMass3GammaCombination(Int_t vectorIndex1,Int_t vectorIndex2,Int_t vectorIndex3){
//    TString cutString = Form("MASS(%d,%d,%d)<0.7||MASS(%d,%d,%d)>0.9&&MASS(%d,%d,%d)<2.4",vectorIndex1,vectorIndex2,vectorIndex3,vectorIndex1,vectorIndex2,vectorIndex3,vectorIndex1,vectorIndex2,vectorIndex3);
//    return cutString;
// }

TString GetCutStringMass3GammaCombination(Int_t vectorIndex1,Int_t vectorIndex2,Int_t vectorIndex3){
   TString cutString = Form("MASS(%d,%d,%d)>0.9",vectorIndex1,vectorIndex2,vectorIndex3);
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
void Plot2DHistWithCuts(TString fileName, TString treeName, TString varNameX, TString varNameY, TString cutName, TString tag, 
                        Int_t numberOfXBin, Double_t xmin, Double_t xmax, TString xTitle, Int_t numberOfYBin, Double_t ymin, Double_t ymax, TString yTitle, TString title,
                        Bool_t isSidebandSub, Int_t etaPrimeSelectNumber){
   
   TString binning = Form("(%d,%f,%f,%d,%f,%f)",numberOfXBin,xmin,xmax,numberOfYBin,ymin,ymax);
   TCanvas* c = new TCanvas("c","c",800,600);   
   TString cutString = "CUT(";
   cutString += cutName;
   cutString += ")";
   if (isSidebandSub) cutString += Form("&&CUTSUB(etaPrimeSelect%d)",etaPrimeSelectNumber);
   cout << cutString << endl;
   TH2F *h = FSModeHistogram::getTH2F(fileName,treeName,"",varNameY+":"+varNameX,binning,cutString);
   h->SetTitle(title.Data());
   h->SetXTitle(xTitle.Data());
   h->SetYTitle(yTitle.Data());
   h->Sumw2();
   h->SetMinimum(0.000);
   h->Draw("COLZ");
   c->SaveAs(Form("%s_%s_%s_%s.pdf",varNameX.Data(),varNameY.Data(),cutName.Data(),tag.Data()));
   delete c;
}

TH2F* Get2DHistWithCuts(TString fileName, TString treeName, TString varNameX, TString varNameY, TString cutName, TString tag, 
                        Int_t numberOfXBin, Double_t xmin, Double_t xmax, TString xTitle, Int_t numberOfYBin, Double_t ymin, Double_t ymax, TString yTitle, TString title,
                        Bool_t isSidebandSub, Int_t etaPrimeSelectNumber){
   
   TString binning = Form("(%d,%f,%f,%d,%f,%f)",numberOfXBin,xmin,xmax,numberOfYBin,ymin,ymax);   
   TString cutString = "CUT(";
   cutString += cutName;
   cutString += ")";
   if (isSidebandSub) cutString += Form("&&CUTSUB(etaPrimeSelect%d)",etaPrimeSelectNumber);
   else cutString += Form("&&CUT(etaPrimeSelect%d)",etaPrimeSelectNumber);
   cout << cutString << endl;
   // cout << binning << endl;
   TH2F *h = FSModeHistogram::getTH2F(fileName,treeName,"",varNameY+":"+varNameX,binning,cutString);
   h->SetTitle(title.Data());
   h->SetXTitle(xTitle.Data());
   h->SetYTitle(yTitle.Data());
   TH2F* hClone = new TH2F(*h);
   return hClone;
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
   Bool_t isSidebandSub = kTRUE;
   Int_t vectorIndexPermutation[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   //use values from the fit
   Double_t etaPrimeMass = 0.95778;
   Double_t etaSigma = 0.012;
   Double_t signalRegion[2] = {etaPrimeMass-(2*etaSigma),etaPrimeMass+(2*etaSigma)};
   Double_t leftSidebandRegion[2] = {etaPrimeMass-(6*etaSigma),etaPrimeMass-(4*etaSigma)};
   Double_t rightSidebandRegion[2] = {etaPrimeMass+(4*etaSigma),etaPrimeMass+(6*etaSigma)};
   Double_t weightSideband = (signalRegion[1]-signalRegion[0])/((rightSidebandRegion[1]-rightSidebandRegion[0])+(leftSidebandRegion[1]-leftSidebandRegion[0]));
   for (Int_t iPermutation = 0;iPermutation < 6; iPermutation++) {
      TString SelectMassString = Form("MASS(%d,%d)>%f&&MASS(%d,%d)<%f",vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1],signalRegion[0],vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1],signalRegion[1]);
      if (!isSidebandSub) FSCut::defineCut(Form("etaPrimeSelect%d",iPermutation),SelectMassString.Data());
      else {
         TString SelectMassSBString = Form("(MASS(%d,%d)>%f&&MASS(%d,%d)<%f)",vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1],leftSidebandRegion[0],vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1],leftSidebandRegion[1]);
         SelectMassSBString += "||";
         SelectMassSBString += Form("(MASS(%d,%d)>%f&&MASS(%d,%d)<%f)",vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1],rightSidebandRegion[0],vectorIndexPermutation[iPermutation][0],vectorIndexPermutation[iPermutation][1],rightSidebandRegion[1]);
         // cout << SelectMassString << ", " << SelectMassSBString << endl;
         FSCut::defineCut(Form("etaPrimeSelect%d",iPermutation),SelectMassString.Data(),SelectMassSBString.Data(),weightSideband);
      }
   }
}

void DefineLMACuts(){
   Int_t vectorIndexPermutation[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   for (Int_t iPermutation = 0;iPermutation < 6; iPermutation++) {
      Int_t iCut1 = iPermutation+1;
      Int_t iCutt1 = iPermutation+2;
      if (iPermutation <= 2){
         if (iCut1 > 2) iCut1 -= 3;
         if (iCutt1 > 2) iCutt1 -= 3;
      }
      else {
         if (iCut1 > 5) iCut1 -= 3;
         if (iCutt1 > 5) iCutt1 -= 3;
      }
      Int_t iCut2 = 5-iCut1;
      Int_t iCutt2 = 5-iCutt1;

      // cout << iCut1 << ", " << iCut2 << " " << iCutt1 << ", " << iCutt2 << endl;
      // cout << "LMAC" << iPermutation << " = " << vectorIndexPermutation[iPermutation][0] << "," << vectorIndexPermutation[iPermutation][1] << ":" << vectorIndexPermutation[5-iPermutation][0] << "," << vectorIndexPermutation[5-iPermutation][1] << " cuts on " << vectorIndexPermutation[iCut1][0] << "," << vectorIndexPermutation[iCut1][1] << ":" << vectorIndexPermutation[iCut2][0] << "," << vectorIndexPermutation[iCut2][1] << "  &  " << vectorIndexPermutation[iCutt1][0] << "," << vectorIndexPermutation[iCutt1][1] << ":" << vectorIndexPermutation[iCutt2][0] << "," << vectorIndexPermutation[iCutt2][1] << endl;
      // TString CutString =  Form("(MASS(%d,%d)<0.15&&MASS(%d,%d)<0.15)",vectorIndexPermutation[iCut1][0],vectorIndexPermutation[iCut1][1],vectorIndexPermutation[iCut2][0],vectorIndexPermutation[iCut2][1]);
      TString CutString =  Form("(MASS(%d,%d)>0.16&&MASS(%d,%d)>0.16)&&(MASS(%d,%d)>0.16&&MASS(%d,%d)>0.16)",vectorIndexPermutation[iCut1][0],vectorIndexPermutation[iCut1][1],vectorIndexPermutation[iCut2][0],vectorIndexPermutation[iCut2][1],vectorIndexPermutation[iCutt1][0],vectorIndexPermutation[iCutt1][1],vectorIndexPermutation[iCutt2][0],vectorIndexPermutation[iCutt2][1]);
      FSCut::defineCut(Form("LMAC%d",iPermutation),CutString.Data());
   }
}

void Define2DAlternativePi0Cuts(){
   Int_t vectorIndexPermutation[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   for (Int_t iPermutation = 0;iPermutation < 6; iPermutation++) {
      Int_t iCut1 = iPermutation+1;
      Int_t iCutt1 = iPermutation+2;
      if (iPermutation <= 2){
         if (iCut1 > 2) iCut1 -= 3;
         if (iCutt1 > 2) iCutt1 -= 3;
      }
      else {
         if (iCut1 > 5) iCut1 -= 3;
         if (iCutt1 > 5) iCutt1 -= 3;
      }
      Int_t iCut2 = 5-iCut1;
      Int_t iCutt2 = 5-iCutt1;

      // cout << iCut1 << ", " << iCut2 << " " << iCutt1 << ", " << iCutt2 << endl;
      cout << "2DPiAC" << iPermutation << " = " << vectorIndexPermutation[iPermutation][0] << "," << vectorIndexPermutation[iPermutation][1] << ":" << vectorIndexPermutation[5-iPermutation][0] << "," << vectorIndexPermutation[5-iPermutation][1] << " cuts on " << vectorIndexPermutation[iCut1][0] << "," << vectorIndexPermutation[iCut1][1] << ":" << vectorIndexPermutation[iCut2][0] << "," << vectorIndexPermutation[iCut2][1] << "  &  " << vectorIndexPermutation[iCutt1][0] << "," << vectorIndexPermutation[iCutt1][1] << ":" << vectorIndexPermutation[iCutt2][0] << "," << vectorIndexPermutation[iCutt2][1] << endl;
      TString CutString =  Form("!((MASS(%d,%d)<0.16&&MASS(%d,%d)<0.16)&&(MASS(%d,%d)>0.11&&MASS(%d,%d)>0.11))",vectorIndexPermutation[iCut1][0],vectorIndexPermutation[iCut1][1],vectorIndexPermutation[iCut2][0],vectorIndexPermutation[iCut2][1],vectorIndexPermutation[iCut1][0],vectorIndexPermutation[iCut1][1],vectorIndexPermutation[iCut2][0],vectorIndexPermutation[iCut2][1]);
      CutString +=  Form("&&!((MASS(%d,%d)<0.16&&MASS(%d,%d)<0.16)&&(MASS(%d,%d)>0.11&&MASS(%d,%d)>0.11))",vectorIndexPermutation[iCutt1][0],vectorIndexPermutation[iCutt1][1],vectorIndexPermutation[iCutt2][0],vectorIndexPermutation[iCutt2][1],vectorIndexPermutation[iCutt1][0],vectorIndexPermutation[iCutt1][1],vectorIndexPermutation[iCutt2][0],vectorIndexPermutation[iCutt2][1]);
      // TString CutString =  Form("!((MASS(%d,%d)<0.16&&MASS(%d,%d)<0.16)&&(MASS(%d,%d)<0.16&&MASS(%d,%d)<0.16)&&(MASS(%d,%d)>0.11&&MASS(%d,%d)>0.11)&&(MASS(%d,%d)>0.11&&MASS(%d,%d)>0.11))",vectorIndexPermutation[iCut1][0],vectorIndexPermutation[iCut1][1],vectorIndexPermutation[iCut2][0],vectorIndexPermutation[iCut2][1],vectorIndexPermutation[iCutt1][0],vectorIndexPermutation[iCutt1][1],vectorIndexPermutation[iCutt2][0],vectorIndexPermutation[iCutt2][1],vectorIndexPermutation[iCut1][0],vectorIndexPermutation[iCut1][1],vectorIndexPermutation[iCut2][0],vectorIndexPermutation[iCut2][1],vectorIndexPermutation[iCutt1][0],vectorIndexPermutation[iCutt1][1],vectorIndexPermutation[iCutt2][0],vectorIndexPermutation[iCutt2][1]);
      // cout << CutString << endl;
      FSCut::defineCut(Form("2DPiAC%d",iPermutation),CutString.Data());
   }
}

void Define2DAlternativeEtaCuts(){
   Double_t etaMass = 0.547853;
   Double_t etaSigma = 0.0078;
   Double_t etaSignalRegion[2] = {etaMass-5*etaSigma,etaMass+5*etaSigma};
   Int_t vectorIndexPermutation[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   for (Int_t iPermutation = 0;iPermutation < 6; iPermutation++) {
      Int_t iCut1 = iPermutation+1;
      Int_t iCutt1 = iPermutation+2;
      if (iPermutation <= 2){
         if (iCut1 > 2) iCut1 -= 3;
         if (iCutt1 > 2) iCutt1 -= 3;
      }
      else {
         if (iCut1 > 5) iCut1 -= 3;
         if (iCutt1 > 5) iCutt1 -= 3;
      }
      Int_t iCut2 = 5-iCut1;
      Int_t iCutt2 = 5-iCutt1;

      // cout << iCut1 << ", " << iCut2 << " " << iCutt1 << ", " << iCutt2 << endl;
      cout << "2DEtaAC" << iPermutation << " = " << vectorIndexPermutation[iPermutation][0] << "," << vectorIndexPermutation[iPermutation][1] << ":" << vectorIndexPermutation[5-iPermutation][0] << "," << vectorIndexPermutation[5-iPermutation][1] << " cuts on " << vectorIndexPermutation[iCut1][0] << "," << vectorIndexPermutation[iCut1][1] << ":" << vectorIndexPermutation[iCut2][0] << "," << vectorIndexPermutation[iCut2][1] << "  &  " << vectorIndexPermutation[iCutt1][0] << "," << vectorIndexPermutation[iCutt1][1] << ":" << vectorIndexPermutation[iCutt2][0] << "," << vectorIndexPermutation[iCutt2][1] << endl;
      TString CutString =  Form("!((MASS(%d,%d)<0.16&&MASS(%d,%d)<%f)&&(MASS(%d,%d)>0.11&&MASS(%d,%d)>%f))",vectorIndexPermutation[iCut1][0],vectorIndexPermutation[iCut1][1],vectorIndexPermutation[iCut2][0],vectorIndexPermutation[iCut2][1],etaSignalRegion[1],vectorIndexPermutation[iCut1][0],vectorIndexPermutation[iCut1][1],vectorIndexPermutation[iCut2][0],vectorIndexPermutation[iCut2][1],etaSignalRegion[0]);
      CutString += Form("&&!((MASS(%d,%d)<%f&&MASS(%d,%d)<0.16)&&(MASS(%d,%d)>%f&&MASS(%d,%d)>0.11))",vectorIndexPermutation[iCut1][0],vectorIndexPermutation[iCut1][1],etaSignalRegion[1],vectorIndexPermutation[iCut2][0],vectorIndexPermutation[iCut2][1],vectorIndexPermutation[iCut1][0],vectorIndexPermutation[iCut1][1],etaSignalRegion[0],vectorIndexPermutation[iCut2][0],vectorIndexPermutation[iCut2][1]);
      CutString += Form("&&!((MASS(%d,%d)<0.16&&MASS(%d,%d)<%f)&&(MASS(%d,%d)>0.11&&MASS(%d,%d)>%f))",vectorIndexPermutation[iCutt1][0],vectorIndexPermutation[iCutt1][1],vectorIndexPermutation[iCutt2][0],vectorIndexPermutation[iCutt2][1],etaSignalRegion[1],vectorIndexPermutation[iCutt1][0],vectorIndexPermutation[iCutt1][1],vectorIndexPermutation[iCutt2][0],vectorIndexPermutation[iCutt2][1],etaSignalRegion[0]);
      CutString += Form("&&!((MASS(%d,%d)<%f&&MASS(%d,%d)<0.16)&&(MASS(%d,%d)>%f&&MASS(%d,%d)>0.11))",vectorIndexPermutation[iCutt1][0],vectorIndexPermutation[iCutt1][1],etaSignalRegion[1],vectorIndexPermutation[iCutt2][0],vectorIndexPermutation[iCutt2][1],vectorIndexPermutation[iCutt1][0],vectorIndexPermutation[iCutt1][1],etaSignalRegion[0],vectorIndexPermutation[iCutt2][0],vectorIndexPermutation[iCutt2][1]);
      // cout << CutString << endl;
      FSCut::defineCut(Form("2DEtaAC%d",iPermutation),CutString.Data());
   }
}

// Explore data

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

   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase","etaPrime_noPi0Select",kTRUE,kTRUE);

   // PlotMass4Gamma(FND,NT,100,1.0,2.0,"allBase","left_etaP_sideband_0885_0905",kTRUE,kTRUE,kTRUE,kTRUE);

   // Plot1DHistWithCuts(FND, NT, "NumCombos", "allBase", "NumCombos", 
   //                   11, -0.5, 10.5, "Number of Combos", "counts", "allBase",
   //                   kFALSE, kFALSE, 0, 0,
   //                   kFALSE, kFALSE, kFALSE, kFALSE);

   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBaseChi2Rank2","etaPrime",kTRUE,kTRUE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBaseChi2Rank3","etaPrime",kTRUE,kTRUE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBaseChi2Rank4","etaPrime",kTRUE,kTRUE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBaseChi2Rank5","etaPrime",kTRUE,kTRUE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBaseChi2Rank6","etaPrime",kTRUE,kTRUE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase","etaPrimeSSB",kTRUE,kTRUE);
   // PlotMass4Gamma(FND,NT,100,1.0,2.0,"allBase","SSB",kTRUE,kTRUE,kTRUE,kTRUE);
   // PlotMass4Gamma(FND,NT,100,1.0,2.0,"allBase","",kFALSE,kFALSE,kTRUE,kTRUE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase,numCombos1","etaPrime",kFALSE,kFALSE);


   // PlotMass4Gamma(FND,NT,100,1.0,2.0,"allBase","SSB",kFALSE,kFALSE,kTRUE,kTRUE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase","etaPrime",kFALSE,kFALSE);

   // study t-dependence

   // Plot1DHistWithCuts(FND, NT, "MASS2(GLUEXTARGET,-1)", "allBase,cet0103", "cet0103", 
   //                   100, -5.0, 0.0, "t (GeV^{2})", "counts", "0.1<|t|<0.3 GeV^{2}",
   //                   kFALSE, kFALSE, 0, 0,
   //                   kFALSE, kFALSE, kFALSE, kFALSE);
   // PlotMass4Gamma(FND,NT,100,1.0,2.0,"allBase,cet0103","cet0103",kFALSE,kFALSE,kTRUE,kTRUE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase,cet0103","etaPrime",kFALSE,kFALSE);

   // Plot1DHistWithCuts(FND, NT, "MASS2(GLUEXTARGET,-1)", "allBase,cet0305", "cet0305", 
   //                   100, -5.0, 0.0, "t (GeV^{2})", "counts", "0.3<|t|< 0.5 GeV^{2}",
   //                   kFALSE, kFALSE, 0, 0,
   //                   kFALSE, kFALSE, kFALSE, kFALSE);
   // PlotMass4Gamma(FND,NT,100,1.0,2.0,"allBase,cet0305","cet0305",kFALSE,kFALSE,kTRUE,kTRUE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase,cet0305","etaPrime",kFALSE,kFALSE);

   // Plot1DHistWithCuts(FND, NT, "MASS2(GLUEXTARGET,-1)", "allBase,cet0507", "cet0507", 
   //                   100, -5.0, 0.0, "t (GeV^{2})", "counts", "0.5<|t|<0.7 GeV^{2}",
   //                   kFALSE, kFALSE, 0, 0,
   //                   kFALSE, kFALSE, kFALSE, kFALSE);
   // PlotMass4Gamma(FND,NT,100,1.0,2.0,"allBase,cet0507","cet0507",kFALSE,kFALSE,kTRUE,kTRUE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase,cet0507","etaPrime",kFALSE,kFALSE);

   // Plot1DHistWithCuts(FND, NT, "MASS2(GLUEXTARGET,-1)", "allBase,cet0710", "cet0710", 
   //                   100, -5.0, 0.0, "t (GeV^{2})", "counts", "0.7<|t|<1.0 GeV^{2}",
   //                   kFALSE, kFALSE, 0, 0,
   //                   kFALSE, kFALSE, kFALSE, kFALSE);
   // PlotMass4Gamma(FND,NT,100,1.0,2.0,"allBase,cet0710","cet0710",kFALSE,kFALSE,kTRUE,kTRUE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase,cet0710","etaPrime",kFALSE,kFALSE);

   // Plot1DHistWithCuts(FND, NT, "MASS2(GLUEXTARGET,-1)", "allBase,cet1014", "cet1014", 
   //                   100, -5.0, 0.0, "t (GeV^{2})", "counts", "1.0<|t|<1.4 GeV^{2}",
   //                   kFALSE, kFALSE, 0, 0,
   //                   kFALSE, kFALSE, kFALSE, kFALSE);
   // PlotMass4Gamma(FND,NT,100,1.0,2.0,"allBase,cet1014","cet1014",kFALSE,kFALSE,kTRUE,kTRUE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase,cet1014","etaPrime",kFALSE,kFALSE);

   // Plot1DHistWithCuts(FND, NT, "MASS2(GLUEXTARGET,-1)", "allBase,cet1418", "cet1418", 
   //                   100, -5.0, 0.0, "t (GeV^{2})", "counts", "1.4<|t|<1.8 GeV^{2}",
   //                   kFALSE, kFALSE, 0, 0,
   //                   kFALSE, kFALSE, kFALSE, kFALSE);
   // PlotMass4Gamma(FND,NT,100,1.0,2.0,"allBase,cet1418","cet1418",kFALSE,kFALSE,kTRUE,kTRUE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase,cet1418","etaPrime",kFALSE,kFALSE);

   // FSTree::testMacro("MANDELSTAM_T");
   // Plot1DHistWithCuts(FND, NT, "MANDELSTAM_T(1)", "allBase", "t_testMacro", 
   //                   100, -10.0, 0.0, "t (GeV^{2})", "counts", "t_testMacro",
   //                   kFALSE, kFALSE, 0, 0,
   //                   kFALSE, kFALSE, kFALSE, kFALSE);

   // make histogram for each 3 gamma combination cuts
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase","etaPrime",kFALSE,kFALSE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase","etaPrime",kTRUE,kFALSE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase","etaPrime",kTRUE,kTRUE);
   // FSModeHistogram::dumpHistogramCache("GammaGammaMass_etaPrime");

   // PlotMass4Gamma(FND,NT,150,0.0,3.0,"allBase","all_SSB",kFALSE,kFALSE,kTRUE,kTRUE);
   // PlotMass4Gamma(FND,NT,150,0.0,3.0,"allBase","all_SSB",kTRUE,kFALSE,kTRUE,kTRUE);
   // PlotMass4Gamma(FND,NT,150,0.0,3.0,"allBase","all_SSB",kTRUE,kTRUE,kTRUE,kTRUE);
   // FSModeHistogram::dumpHistogramCache("4GammaMassEtaPrimePi0_differentGamma3Cuts_SSB");

   //2D plot test
   // Plot2DHistWithCuts(FND, NT, "MASS(2,3)", "MASS(4,5)", "allBase", "m23m45",
   //                      100, 0.0, 2.0, "mass(2,3)", 100, 0.0, 2.0, "mass(4,5)", "mass(2,3) vs mass(4,5)",
   //                      kFALSE, kFALSE, 0, 0);

   // explore MC
   // PlotMass2GammaCombination(FNMC,NT,100,0.0,2.00,"e8288","MC",kFALSE,kFALSE);
   // PlotMass3GammaCombination(FNMC,NT,100,0.0,2.00,"e8288","MC",kFALSE,kFALSE);
   // PlotMass4Gamma(FNMC,NT,150,0.0,3.0,"e8288","MC",kFALSE,kFALSE,kTRUE,kTRUE);

   // PlotMass2GammaCombination(FNMC,NT,100,0.0,2.00,"allBase","MC",kFALSE,kFALSE);
   // PlotMass3GammaCombination(FNMC,NT,100,0.0,2.00,"allBase","MC",kFALSE,kFALSE);
   // PlotMass4Gamma(FNMC,NT,150,0.0,3.0,"allBase","MC",kFALSE,kFALSE,kTRUE,kTRUE);

   // explore eta prime invariant mass as a function of other variables
   // Plot2DHistWithCuts(FND, NT, "MASS(2,3)", "PolarizationAngle", "allBase,pi0Select5", "mass(2,3)_vs_PolarizationAngle",
   //                      40,0.85,1.05, "m_{#gamma2#gamma3}", 181, -0.5, 180.5, "Polarization angle (degree)", "",
   //                      kFALSE, kFALSE, 0, 0);

   // Plot2DHistWithCuts(FND, NT, "MASS(2,3)", "COSINE(2,3)", "allBase,pi0Select5", "mass(2,3)_vs_cos(#theta_{2,3})",
   //                      40,0.85,1.05, "m_{#gamma2#gamma3}", 50, 0.98, 1., "cos(#theta_{23})", "",
   //                      kFALSE, kFALSE, 0, 0);

   // Plot2DHistWithCuts(FND, NT, "MASS(2,3)", "COSINE(2,4)", "allBase,pi0Select5", "mass(2,3)_vs_cos(#theta_{2,4})",
   //                      40,0.85,1.05, "m_{#gamma2#gamma3}", 50, 0.98, 1., "cos(#theta_{24})", "",
   //                      kFALSE, kFALSE, 0, 0);

   // Plot2DHistWithCuts(FND, NT, "MASS(2,3)", "COSINE(2,5)", "allBase,pi0Select5", "mass(2,3)_vs_cos(#theta_{2,5})",
   //                      40,0.85,1.05, "m_{#gamma2#gamma3}", 50, 0.98, 1., "cos(#theta_{25})", "",
   //                      kFALSE, kFALSE, 0, 0);

   // Plot2DHistWithCuts(FND, NT, "MASS(2,3)", "Chi2DOF", "allBase,pi0Select5", "mass(2,3)_vs_chi2dof",
   //                      40,0.85,1.05, "m_{#gamma2#gamma3}", 100, 0., 2., "Chi2DOF", "",
   //                      kFALSE, kFALSE, 0, 0);

   // Low mass alternative check 

   // Plot2DHistWithCuts(FND, NT, "MASS(2,4)", "MASS(3,5)", "allBase,pi0Select5,etaPrimeSelect0", "mass(2,4)_vs_mass(3,5)",
   //                      50,0.0,1.0, "m_{#gamma2#gamma4}", 50, 0.0, 1.0, "m_{#gamma3#gamma5}", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, kFALSE, 0, 0);

   // Plot2DHistWithCuts(FND, NT, "MASS(2,5)", "MASS(3,4)", "allBase,pi0Select5,etaPrimeSelect0", "mass(2,5)_vs_mass(3,4)",
   //                      50,0.0,1.0, "m_{#gamma2#gamma5}", 50, 0.0, 1.0, "m_{#gamma3#gamma4}", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, kFALSE, 0, 0);

   // Plot2DHistWithCuts(FNMC, NT, "MASS(2,4)", "MASS(3,5)", "allBase,pi0Select5,etaPrimeSelect0", "mass(2,4)_vs_mass(3,5) MC",
   //                      50,0.0,1.0, "m_{#gamma2#gamma4}", 50, 0.0, 1.0, "m_{#gamma3#gamma5}", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, kFALSE, 0, 0);

   // Plot2DHistWithCuts(FNMC, NT, "MASS(2,5)", "MASS(3,4)", "allBase,pi0Select5,etaPrimeSelect0", "mass(2,5)_vs_mass(3,4) MC",
   //                      50,0.0,1.0, "m_{#gamma2#gamma5}", 50, 0.0, 1.0, "m_{#gamma3#gamma4}", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, kFALSE, 0, 0);

   // Plot2DHistWithCuts(FND, NT, "MASS(2,3)", "MASS(2,3,5)", "allBase,pi0Select5,etaPrimeSelect0", "mass(2,3)_vs_mass(2,3,5)",
   //                      50,0.92,1.0, "m_{#gamma2#gamma3}", 50, 0.0, 1.0, "m_{#gamma2#gamma3#gamma5}", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, kFALSE, 0, 0);

   // Plot2DHistWithCuts(FND, NT, "MASS(2,3)", "MASS(2,4,5)", "allBase,pi0Select5,etaPrimeSelect0", "mass(2,3)_vs_mass(2,4,5)",
   //                      50,0.92,1.0, "m_{#gamma2#gamma3}", 50, 0.0, 1.0, "m_{#gamma2#gamma4#gamma5}", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, kFALSE, 0, 0);

   // Plot2DHistWithCuts(FND, NT, "MASS(2,3)", "MASS(3,4,5)", "allBase,pi0Select5,etaPrimeSelect0", "mass(2,3)_vs_mass(3,4,5)",
   //                      50,0.92,1.0, "m_{#gamma2#gamma3}", 50, 0.0, 1.0, "m_{#gamma3#gamma4#gamma5}", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, kFALSE, 0, 0);

   // check LMAC effect on etaPrime peak 
   // Plot2DHistWithCuts(FND, NT, "MASS(2,4)", "MASS(3,5)", "allBase,pi0Select5,etaPrimeSelect0,LMAC0", "mass(2,4)_vs_mass(3,5)",
   //                      50,0.0,1.0, "m_{#gamma2#gamma4}", 50, 0.0, 1.0, "m_{#gamma3#gamma5}", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, kFALSE, 0, 0);
   // Plot2DHistWithCuts(FND, NT, "MASS(2,5)", "MASS(3,4)", "allBase,pi0Select5,etaPrimeSelect0,LMAC0", "mass(2,5)_vs_mass(3,4)",
   //                      50,0.0,1.0, "m_{#gamma2#gamma5}", 50, 0.0, 1.0, "m_{#gamma3#gamma4}", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, kFALSE, 0, 0);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase","etaPrime",kFALSE,kFALSE,kFALSE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase","etaPrimeLMAC",kFALSE,kFALSE,kTRUE);
   // FSModeHistogram::dumpHistogramCache("histograms/2DAlternativeCuts_etaPrime");

   // PlotMass4Gamma(FND,NT,150,0.0,3.0,"allBase,t_lt0.5","all_SSB",kFALSE,kFALSE,kTRUE,kTRUE,kFALSE);
   // PlotMass4Gamma(FND,NT,150,0.0,3.0,"allBase,t_lt0.5","all_SSB_LMAC",kFALSE,kFALSE,kTRUE,kTRUE,kTRUE);
   // FSModeHistogram::dumpHistogramCache("histograms/4GammaMass_all_SSB_LMAC_t_lt0.5");

   // PlotMass4Gamma(FND,NT,150,0.0,3.0,"allBase,t_lt0.5","all_SNewSBNew",kFALSE,kFALSE,kTRUE,kTRUE,kFALSE);
   // PlotMass4Gamma(FND,NT,150,0.0,3.0,"allBase,t_lt0.5","all_SNewSBNew_LMAC",kFALSE,kFALSE,kTRUE,kTRUE,kTRUE);
   // FSModeHistogram::dumpHistogramCache("histograms/4GammaMass_all_SNewSBNew_LMAC_t_lt0.5");

   // PlotMass4Gamma(FND,NT,150,0.0,3.0,"allBase,t_lt0.5","all_SNewSBNewNew",kFALSE,kFALSE,kTRUE,kTRUE,kFALSE);
   // PlotMass4Gamma(FND,NT,150,0.0,3.0,"allBase,t_lt0.5","all_SNewSBNewNew_LMAC",kFALSE,kFALSE,kTRUE,kTRUE,kTRUE);
   // FSModeHistogram::dumpHistogramCache("histograms/4GammaMass_all_SNewSBNewNew_LMAC_t_lt0.5");

   // PlotMass4Gamma(FND,NT,150,0.0,3.0,"allBase","all_SNewSBNew",kFALSE,kFALSE,kTRUE,kTRUE,kFALSE);
   // PlotMass4Gamma(FND,NT,150,0.0,3.0,"allBase","all_SNewSBNew_LMAC",kFALSE,kFALSE,kTRUE,kTRUE,kTRUE);
   // FSModeHistogram::dumpHistogramCache("histograms/4GammaMass_all_SNewSBNew_LMAC");

   // PlotMass4Gamma(FND,NT,150,0.0,3.0,"allBase","all_SNewSBNewNew",kFALSE,kFALSE,kTRUE,kTRUE,kFALSE);
   // PlotMass4Gamma(FND,NT,150,0.0,3.0,"allBase","all_SNewSBNewNew_LMAC",kFALSE,kFALSE,kTRUE,kTRUE,kTRUE);
   // FSModeHistogram::dumpHistogramCache("histograms/4GammaMass_all_SNewSBNewNew_LMAC");

   // PlotMass4Gamma(FND,NT,150,0.0,3.0,"allBase,t_lt0.5","t_lt0.5_LMAC",kFALSE,kFALSE,kTRUE,kTRUE,kTRUE);
   // PlotMass4Gamma(FND,NT,150,0.0,3.0,"allBase","all_LMAC",kFALSE,kFALSE,kTRUE,kTRUE,kTRUE);

   // 3 gamma mass 2D alternative cuts effect
   // Plot1DHistWithCuts(FND, NT, "MASS(2,4,5)", "allBase,etaPrimeSelect0,pi0Select5", "mass(2,4,5)", 
   //                   100, 0., 1.0, "m_{#gamma2#gamma4#gamma5}", "counts", "allBase",
   //                   kFALSE, kFALSE, 0, 0,
   //                   kFALSE, kFALSE, kFALSE, kFALSE);
   // Plot1DHistWithCuts(FND, NT, "MASS(2,4,5)", "allBase,etaPrimeSelect0,pi0Select5,LMAC0", "mass(2,4,5)_LMAC0", 
   //                   100, 0., 1.0, "m_{#gamma2#gamma4#gamma5}", "counts", "allBase",
   //                   kFALSE, kFALSE, 0, 0,
   //                   kFALSE, kFALSE, kFALSE, kFALSE);
   
   // Plot1DHistWithCuts(FND, NT, "MASS(3,4,5)", "allBase,etaPrimeSelect0,pi0Select5", "mass(3,4,5)", 
   //                   100, 0., 1.0, "m_{#gamma2#gamma4#gamma5}", "counts", "allBase",
   //                   kFALSE, kFALSE, 0, 0,
   //                   kFALSE, kFALSE, kFALSE, kFALSE);
   // Plot1DHistWithCuts(FND, NT, "MASS(3,4,5)", "allBase,etaPrimeSelect0,pi0Select5,LMAC0", "mass(3,4,5)_LMAC0", 
   //                   100, 0., 1.0, "m_{#gamma3#gamma4#gamma5}", "counts", "allBase",
   //                   kFALSE, kFALSE, 0, 0,
   //                   kFALSE, kFALSE, kFALSE, kFALSE);

   // PlotMass3GammaCombination(FND,NT,150,0.,3.0,"allBase,pi0Select5","1stCombinationSSBNew",kFALSE,kFALSE);
   // PlotMass3GammaCombination(FND,NT,150,0.,3.0,"allBase,pi0Select5,LMAC0","1stCombinationSNewSBNewNew_LMAC0",kFALSE,kFALSE);
   // FSModeHistogram::dumpHistogramCache("histograms/3GammaMass_1stCombinationSBLNew_LMAC0");

   // test cos(theta)GJ distribution from 1st combination
   // Plot2DHistWithCuts(FND, NT, "MASS(EtaPrime0,Pi05)", COSTHETAGJ[0], "allBase,pi0Select5,LMAC0", "mass(2,3)_vs_GJCOSTHETA",
   //                      150,0.0,3.0, "m_{#gamma2#gamma3#gamma4#gamma5}", 50, -1.0, 1.0, "cos#theta_{GJ}", "",
   //                      kTRUE, 0);

   // Plot mass vs cos theta GJ all combinations
   // TH2F *h2, *h2_total;
   // TCanvas *c1 = new TCanvas("c1","c1",800,600);
   // for (Int_t i=0;i<6;i++) {
   //    h2 = Get2DHistWithCuts(FND, NT, Form("MASS(2,3,4,5)"), COSTHETAGJ[i], Form("allBase,t_lt0.5,pi0Select%d,LMAC%d",5-i,i), "m_{#eta'#pi^{0}} vs cos#theta_{GJ}",
   //                      150,0.0,3.0, "m_{#eta'#pi^{0}} GeV", 50, -1.0, 1.0, "cos#theta_{GJ}", Form("Selection: \\eta'(\\gamma_{%d}\\gamma_{%d}) & \\pi^{0}(\\gamma_{%d}\\gamma_{%d})",vectorIndexPermutation[i][0],vectorIndexPermutation[i][1],vectorIndexPermutation[5-i][0],vectorIndexPermutation[5-i][1]),
   //                      kFALSE, i);
   //    if (i==0) {
   //       h2_total = (TH2F*)h2->Clone("h2_total");
   //    } else {
   //       h2_total->Add(h2);
   //    }
   //    h2->SetMinimum(0.0);
   //    h2->Draw("colz");
   //    c1->Print(Form("plots/mass_vs_cosThetaGJ_tlt0.5_%d.pdf",i));
   // }
   // c1->Clear();
   // h2_total->SetMinimum(0.0);
   // h2_total->SetTitle("Sum of all combinations");
   // h2_total->Draw("colz");
   // c1->Print("plots/mass_vs_cosThetaGJ_tlt0.5_total.pdf");

   // FSModeHistogram::dumpHistogramCache("histograms/mass_vs_cosThetaGJ_total");