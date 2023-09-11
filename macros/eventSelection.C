// Description: Event selection for the EtapPi0_4gamma analysis

TString FND("/d/grid17/sdobbs/gluex_data/EtapPi0_4gamma/skimmed/tree_pi0eta__B4_M17_M7_FLAT_PRESKIM_*.root");

TString FNDEtaPi0AC[6] = {"/d/grid17/septian/EtaPPi0_4Gamma/2018S/skimmedTree/skimmedTree_AllCombination_2DPi0EtaAC_0.root",
                          "/d/grid17/septian/EtaPPi0_4Gamma/2018S/skimmedTree/skimmedTree_AllCombination_2DPi0EtaAC_1.root",
                          "/d/grid17/septian/EtaPPi0_4Gamma/2018S/skimmedTree/skimmedTree_AllCombination_2DPi0EtaAC_2.root",
                          "/d/grid17/septian/EtaPPi0_4Gamma/2018S/skimmedTree/skimmedTree_AllCombination_2DPi0EtaAC_3.root",
                          "/d/grid17/septian/EtaPPi0_4Gamma/2018S/skimmedTree/skimmedTree_AllCombination_2DPi0EtaAC_4.root",
                          "/d/grid17/septian/EtaPPi0_4Gamma/2018S/skimmedTree/skimmedTree_AllCombination_2DPi0EtaAC_5.root"};

TString FNMCEtaPi0AC[6] = {"/d/grid17/septian/EtaPPi0_4Gamma/2018S/skimmedTree/skimmedTree_MC_AllCombination_2DPi0EtaAC_0.root",
                          "/d/grid17/septian/EtaPPi0_4Gamma/2018S/skimmedTree/skimmedTree_MC_AllCombination_2DPi0EtaAC_1.root",
                          "/d/grid17/septian/EtaPPi0_4Gamma/2018S/skimmedTree/skimmedTree_MC_AllCombination_2DPi0EtaAC_2.root",
                          "/d/grid17/septian/EtaPPi0_4Gamma/2018S/skimmedTree/skimmedTree_MC_AllCombination_2DPi0EtaAC_3.root",
                          "/d/grid17/septian/EtaPPi0_4Gamma/2018S/skimmedTree/skimmedTree_MC_AllCombination_2DPi0EtaAC_4.root",
                          "/d/grid17/septian/EtaPPi0_4Gamma/2018S/skimmedTree/skimmedTree_MC_AllCombination_2DPi0EtaAC_5.root"};

TString FNMCBGGENEtaPi0AC[6] = {"/d/grid17/septian/EtaPPi0_4Gamma/2018S/skimmedTree/skimmedTree_MC_BGGen_AllCombination_2DPi0EtaAC_0.root",
                          "/d/grid17/septian/EtaPPi0_4Gamma/2018S/skimmedTree/skimmedTree_MC_BGGen_AllCombination_2DPi0EtaAC_1.root",
                          "/d/grid17/septian/EtaPPi0_4Gamma/2018S/skimmedTree/skimmedTree_MC_BGGen_AllCombination_2DPi0EtaAC_2.root",
                          "/d/grid17/septian/EtaPPi0_4Gamma/2018S/skimmedTree/skimmedTree_MC_BGGen_AllCombination_2DPi0EtaAC_3.root",
                          "/d/grid17/septian/EtaPPi0_4Gamma/2018S/skimmedTree/skimmedTree_MC_BGGen_AllCombination_2DPi0EtaAC_4.root",
                          "/d/grid17/septian/EtaPPi0_4Gamma/2018S/skimmedTree/skimmedTree_MC_BGGen_AllCombination_2DPi0EtaAC_5.root"};


// TString FNMC("/d/grid17/sdobbs/gluex_data/EtapPi0_4gamma/skimmed/tree_pi0eta__B4_M17_M7_FLAT_MC_PRESKIM*.root");
// TString FNMCGen("/d/grid17/septian/EtaPPi0_4Gamma/2018S/MCThrown_flat_FSRoot.root");

//1M MC genr8 events
TString FNMC("/d/grid17/septian/EtaPPi0_4Gamma/2018S/tree_gggg__EtaPPi0_B4_genr8_FSRootFlat_1M.root");
TString FNMCGen("/d/grid17/septian/EtaPPi0_4Gamma/2018S/thrown_tree_gggg__EtaPPi0_B4_genr8_FSRootFlat_1M.root");
TString FNMCBGGEN("/d/grid17/septian/EtaPPi0_4Gamma/2018S/tree_gggg__B4_BGGen_FSRootFlat*.root");

TString NT("ntFSGlueX_MODECODE");

void chi2Ranking(){
   FSModeCollection::addModeInfo("100_4000000");
   // FSModeTree::createChi2RankingTree(FND,NT,"","abs(RFDeltaT)<2.0");
   // FSModeTree::createChi2RankingTree(FNMC,NT,"","abs(RFDeltaT)<2.0");
   FSModeTree::createChi2RankingTree(FNMCBGGEN,NT,"","abs(RFDeltaT)<2.0");
}

void PlotMass2GammaCombination(TString fileName, TString treeName, Int_t numberOfBin, Double_t xmin, Double_t xmax, TString cutName, TString tag, Bool_t isGamma3Cut, Bool_t isPi0Cut3, Bool_t isLMACut, Bool_t isSidebandSub);
void PlotMass2GammaCombinationSkimmed2DEtaPiAC(TString *fileName, TString treeName, Int_t numberOfBin, Double_t xmin, Double_t xmax, TString cutName, TString tag, Bool_t isGamma3Cut, Bool_t isPi0Cut3, Bool_t isLMACut, Bool_t isSidebandSub);
void PlotMass2GammaCombinationBGGen(TString fileName, TString treeName, Int_t numberOfBin, Double_t xmin, Double_t xmax, TString cutName, TString tag, Bool_t isGamma3Cut, Bool_t isPi0Cut3, Bool_t isLMACut, Bool_t isSidebandSub);
void PlotMass2GammaCombinationBGGenSkimmed2DEtaPiAC(TString *fileName, TString treeName, Int_t numberOfBin, Double_t xmin, Double_t xmax, TString cutName, TString tag, Bool_t isSidebandSub);
void PlotMass3GammaCombination(TString fileName, TString treeName, Int_t numberOfBin, Double_t xmin, Double_t xmax, TString cutName, TString tag, Bool_t isGamma3Cut, Bool_t isPi0Cut3, Bool_t isSidebandSub);
void PlotMass4Gamma(TString fileName, TString treeName, Int_t numberOfBin, Double_t xmin, Double_t xmax, TString cutName, TString tag,
                     Bool_t isGamma3Cut, Bool_t isPi0Cut3, Bool_t isPi0Select, Bool_t isEtaPrimeSelect, Bool_t isLMACut, Bool_t is2DEtaPi0Cut, Bool_t isDeltaCut,Bool_t isOmegaMomentumCut, Bool_t isOmegaCosThetaCOMCut,
                     Bool_t isSidebandSub, Bool_t isIncludeMC = kFALSE, TString fileNameMC = "", TString fileNameMCThrown = "", TString mcThrownCutName = "");
vector<TH1F*> GetMass4Gamma(TString fileName, TString treeName, Int_t numberOfBin, Double_t xmin, Double_t xmax, TString cutName, TString tag,
                     Bool_t isPi0Select = kFALSE, Bool_t isEtaPrimeSelect = kFALSE, Bool_t is2DEtaPi0Cut = kFALSE, Bool_t isDeltaCut = kFALSE, Bool_t isOmegaMomentumCut = kFALSE, Bool_t isOmegaCosThetaCOMCut = kFALSE,
                     Bool_t isSidebandSub = kFALSE, Bool_t isIncludeMC = kFALSE, TString fileNameMC = "", TString fileNameMCThrown = "", TString mcThrownCutName = "");
vector<TH1F*> GetMass4GammaSkimmed2DEtaPiAC(TString *fileName, TString treeName, Int_t numberOfBin, Double_t xmin, Double_t xmax, TString cutName, TString tag,
                     Bool_t isPi0Select, Bool_t isEtaPrimeSelect, Bool_t is2DLowPhotonOmegaAC, Bool_t isDeltaCut, Bool_t isOmegaMomentumCut, Bool_t isOmegaCosThetaCOMCut,
                     Bool_t isSidebandSub, Bool_t isIncludeMC, TString *fileNameMC, TString fileNameMCThrown, TString mcThrownCutName);
TString GetCutStringMass3GammaCombination(Int_t vectorIndex1,Int_t vectorIndex2,Int_t vectorIndex3);
TString GetPi0CutStringMass3Combination(Int_t vectorIndex1,Int_t vectorIndex2,Int_t vectorIndex3);
void Plot1DHistWithCuts(TString fileName, TString treeName, TString varName, TString cutName, TString tag, 
                        Int_t numberOfXBin, Double_t xmin, Double_t xmax, TString xTitle, TString yTitle, TString title,
                        Bool_t isEnableCombination, Bool_t isCanvasDivide, Int_t numberOfXPad, Int_t numberOfYPad,
                        Bool_t isGamma3Cut, Bool_t isPi0Cut3, Bool_t isPi0Select, Bool_t isEtaPrimeSelect);
TH1F* Get1DHistWithCuts(TString fileName, TString treeName, TString varName, TString cutName, TString tag, 
                        Int_t numberOfXBin, Double_t xmin, Double_t xmax, TString xTitle, TString yTitle, TString title);
void Plot2DHistWithCuts(TString fileName, TString treeName, TString varNameX, TString varNameY, TString cutName, TString tag, 
                        Int_t numberOfXBin, Double_t xmin, Double_t xmax, TString xTitle, Int_t numberOfYBin, Double_t ymin, Double_t ymax, TString yTitle, TString title,
                        Bool_t isSidebandSub, Int_t etaPrimeSelectNumber);
TH2F* Get2DHistWithCuts(TString fileName, TString treeName, TString varNameX, TString varNameY, TString cutName, TString tag, 
                        Int_t numberOfXBin, Double_t xmin, Double_t xmax, TString xTitle, Int_t numberOfYBin, Double_t ymin, Double_t ymax, TString yTitle, TString title,
                        Bool_t isSidebandSub, Int_t etaPrimeSelectNumber);
void PlotOmegaMassWithCuts(TString fileName,TString treeName,Int_t numberOfBin,Double_t xmin,Double_t xmax, TString cutName, TString tag, Bool_t isFit);
void PlotOmegaMassWithCutsSkimmed2DEtaPiAC(TString *fileName,TString treeName,Int_t numberOfBin,Double_t xmin,Double_t xmax, TString cutName, TString tag, Bool_t isFit);

void DefineGamma3Cuts();
void DefinePi0SelectCuts();
void DefineEtaPrimeSelectCuts();
void DefineLMACuts();
void Define2DAlternativePi0Cuts();
void Define2DAlternativeEtaCuts();
void Define2DAlternativeLowEnergyPhotonCuts();
void Define2DAlternativeOmegaCuts();
void DefineDeltaCuts();
void DefineOmegaMomentumCuts();
void DefineOmegaCosThetaCOMCuts();

Double_t cosTheta3G4GFrame(Double_t PxPA, Double_t PyPA, Double_t PzPA, Double_t EnPA,
                              Double_t PxPB, Double_t PyPB, Double_t PzPB, Double_t EnPB,
                              Double_t PxPC, Double_t PyPC, Double_t PzPC, Double_t EnPC,
                              Double_t PxPD, Double_t PyPD, Double_t PzPD, Double_t EnPD);

Double_t cosTheta3GCOMFrame(Double_t PxPA, Double_t PyPA, Double_t PzPA, Double_t EnPA,
                              Double_t PxPB, Double_t PyPB, Double_t PzPB, Double_t EnPB,
                              Double_t PxPC, Double_t PyPC, Double_t PzPC, Double_t EnPC,
                              Double_t PxPD, Double_t PyPD, Double_t PzPD, Double_t EnPD);

Double_t cosTheta2GCOMFrame(Double_t PxPA, Double_t PyPA, Double_t PzPA, Double_t EnPA,
                              Double_t PxPB, Double_t PyPB, Double_t PzPB, Double_t EnPB,
                              Double_t PxPC, Double_t PyPC, Double_t PzPC, Double_t EnPC);

Double_t pi0Momentum3GFrame(Double_t PxPA, Double_t PyPA, Double_t PzPA, Double_t EnPA,
                              Double_t PxPB, Double_t PyPB, Double_t PzPB, Double_t EnPB,
                              Double_t PxPC, Double_t PyPC, Double_t PzPC, Double_t EnPC);

Double_t cosTheta2G2G4GFrame(Double_t PxPA, Double_t PyPA, Double_t PzPA, Double_t EnPA,
                              Double_t PxPB, Double_t PyPB, Double_t PzPB, Double_t EnPB,
                              Double_t PxPC, Double_t PyPC, Double_t PzPC, Double_t EnPC,
                              Double_t PxPD, Double_t PyPD, Double_t PzPD, Double_t EnPD);

Double_t absMomentum2EnergyRatio(Double_t PxPA, Double_t PyPA, Double_t PzPA, Double_t EnPA);

void setup(){
   if (FSModeCollection::modeVector().size() != 0) return;
   FSModeCollection::addModeInfo("100_4000000")->addCategory("m100_4000000");
   FSModeCollection::display();
   // chi2Ranking();

   // DEFINITION OF CUTS:

   // FIXED CUTS
   // format defineCut("name","BranchName =<> value")
   // unused energy cut
   FSCut::defineCut("unusedE","EnUnusedSh<0.1");
   // unused track cuts
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
   FSCut::defineCut("allBaseBGGen","CUT(unusedE,unusedTracks,zProton,protMom,e8288,chi2lt2,rf,photFiducialA,photFiducialB,photFiducialC,photFiducialD)");
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
   FSCut::defineCut("mct_lt1","abs(MCMASS2(GLUEXTARGET,-1))<1.0"); //|t| < 1.0 for MC thrown
   FSCut::defineCut("t_lt0.5","abs(MASS2(GLUEXTARGET,-1))<0.5");    //|t| < 0.5
   FSCut::defineCut("mct_lt0.5","abs(MCMASS2(GLUEXTARGET,-1))<0.5"); //|t| < 0.5 for MC thrown
   FSCut::defineCut("pg4g5_lt1.4","MASS(1,4,5)<1.4");
   FSCut::defineCut("pg3g5_lt1.4","MASS(1,3,5)<1.4");

   //bggen selection
   // proton pi0 pi0 pi0
   FSCut::defineCut("sel_p_3pi0","MCDecayCode1==3&&MCDecayCode2==100");
   // proton gamma gamma pi0
   FSCut::defineCut("sel_p_ggpi0","MCDecayCode1==2000001&&MCDecayCode2==100");

   DefineGamma3Cuts();
   DefinePi0SelectCuts();
   DefineEtaPrimeSelectCuts();
   DefineLMACuts();
   Define2DAlternativePi0Cuts();
   Define2DAlternativeEtaCuts();
   Define2DAlternativeLowEnergyPhotonCuts();
   Define2DAlternativeOmegaCuts();
   DefineDeltaCuts();
   DefineOmegaMomentumCuts();
   DefineOmegaCosThetaCOMCuts();

   FSControl::DEBUG=0;

   FSTree::defineMacro("MANDELSTAM_T",1,"(pow(((-EnP[I]+0.938272)),2)-pow(((-PxP[I]+0.0)),2)-pow(((-PyP[I]+0.0)),2)-pow(((-PzP[I]+0.0)),2))");
   FSTree::defineMacro("cosTheta3G4GFrame", 4, "cosTheta3G4GFrame("
                                                "PxP[I],PyP[I],PzP[I],EnP[I],"
                                                "PxP[J],PyP[J],PzP[J],EnP[J],"
                                                "PxP[M],PyP[M],PzP[M],EnP[M],"
                                                "PxP[N],PyP[N],PzP[N],EnP[N])");
   FSTree::defineMacro("cosTheta3GCOMFrame", 4, "cosTheta3GCOMFrame("
                                                "PxP[I],PyP[I],PzP[I],EnP[I],"
                                                "PxP[J],PyP[J],PzP[J],EnP[J],"
                                                "PxP[M],PyP[M],PzP[M],EnP[M],"
                                                "PxP[N],PyP[N],PzP[N],EnP[N])");
   FSTree::defineMacro("cosTheta2GCOMFrame", 3, "cosTheta2GCOMFrame("
                                                "PxP[I],PyP[I],PzP[I],EnP[I],"
                                                "PxP[J],PyP[J],PzP[J],EnP[J],"
                                                "PxP[M],PyP[M],PzP[M],EnP[M])");      
   FSTree::defineMacro("pi0Momentum3GFrame", 3, "pi0Momentum3GFrame("
                                                "PxP[I],PyP[I],PzP[I],EnP[I],"
                                                "PxP[J],PyP[J],PzP[J],EnP[J],"
                                                "PxP[M],PyP[M],PzP[M],EnP[M])");
   FSTree::defineMacro("cosTheta2G2G4GFrame", 4, "cosTheta2G2G4GFrame("
                                                "PxP[I],PyP[I],PzP[I],EnP[I],"
                                                "PxP[J],PyP[J],PzP[J],EnP[J],"
                                                "PxP[M],PyP[M],PzP[M],EnP[M],"
                                                "PxP[N],PyP[N],PzP[N],EnP[N])");
   FSTree::defineMacro("absMomentum2EnergyRatio", 1, "absMomentum2EnergyRatio("
                                                "PxP[I],PyP[I],PzP[I],EnP[I])");

   FSTree::showDefinedMacros();

}


void eventSelection(){
   setup();

   //declare costheta_gj variables
   Int_t vectorIndexCombination[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   TString COSTHETAGJ[6]; 
   for (Int_t iCombination=0;iCombination<6;iCombination++) {
      COSTHETAGJ[iCombination] = Form("FSMath::gjcostheta("
                                  "(PxP%d+PxP%d),(PyP%d+PyP%d),(PzP%d+PzP%d),(EnP%d+EnP%d),"
                                  "(PxP%d+PxP%d),(PyP%d+PyP%d),(PzP%d+PzP%d),(EnP%d+EnP%d),"
                                  "PxPB,PyPB,PzPB,EnPB)",
                                  vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1], vectorIndexCombination[iCombination][0], vectorIndexCombination[iCombination][1], vectorIndexCombination[iCombination][0], vectorIndexCombination[iCombination][1], vectorIndexCombination[iCombination][0], vectorIndexCombination[iCombination][1], 
                                  vectorIndexCombination[5-iCombination][0], vectorIndexCombination[5-iCombination][1], vectorIndexCombination[5-iCombination][0], vectorIndexCombination[5-iCombination][1],vectorIndexCombination[5-iCombination][0], vectorIndexCombination[5-iCombination][1],vectorIndexCombination[5-iCombination][0], vectorIndexCombination[5-iCombination][1]
                                  );
      // cout << COSTHETAGJ[iCombination] << endl;
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
   // FSModeHistogram::dumpHistogramCache("histograms/3GammaMass_1stCombinationSSB_pi0Select5,2DPiAC0,2DEtaAC0_D");

   // FSModeHistogram::readHistogramCache();
   // PlotMass4Gamma(FND,NT,50,1.0,3.0,"allBase,t_lt0.5","2DEtaPi0AC",kFALSE,kFALSE,kTRUE,kTRUE,kFALSE,kTRUE,kFALSE,kTRUE,FNMC,FNMCGen,"CUT(mcebeam,mct_lt0.5)");
   // PlotMass4Gamma(FND,NT,50,1.0,3.0,"allBase,t_lt0.5","2DEtaPi0AC_SSB",kFALSE,kFALSE,kTRUE,kTRUE,kFALSE,kTRUE,kTRUE,kTRUE,FNMC,FNMCGen,"CUT(mcebeam,mct_lt0.5)");
   // FSModeHistogram::dumpHistogramCache();

   // skim tree for all combination with allBase + 2DPiAC0 + 2DEtaAC0
   // for (Int_t iCombination=0;iCombination<6;iCombination++) {
   //    FSTree::skimTree(FND,"ntFSGlueX_100_4000000",Form("/d/grid17/septian/EtaPPi0_4Gamma/2018S/skimmedTree/skimmedTree_AllCombination_2DPi0EtaAC_%d.root",iCombination),Form("CUT(allBase,pi0Select%d,2DPiAC%d,2DEtaAC%d)",5-iCombination,iCombination,iCombination));
      // FSTree::skimTree(FNMCBGGEN,"ntFSGlueX_100_4000000",Form("/d/grid17/septian/EtaPPi0_4Gamma/2018S/skimmedTree/skimmedTree_MC_BGGen_AllCombination_2DPi0EtaAC_%d.root",iCombination),Form("CUT(allBase,pi0Select%d,2DPiAC%d,2DEtaAC%d)",5-iCombination,iCombination,iCombination));
   // }

   //check energy from gamma2 and gamma3
   // Plot2DHistWithCuts(FND, NT, "MASS(2,4,5)", "EnP2", "allBase,pi0Select5,2DPiAC0,2DEtaAC0", "mass245_En2",
   //                      150,0.0,3.0, "m_{#gamma2#gamma4#gamma5} (GeV)", 100,0.0,8.00, "E_{#gamma2} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FND, NT, "MASS(3,4,5)", "EnP3", "allBase,pi0Select5,2DPiAC0,2DEtaAC0", "mass345_En3",
   //                      150,0.0,3.0, "m_{#gamma3#gamma4#gamma5} (GeV)", 100,0.0,8.00, "E_{#gamma3} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMC, NT, "MASS(2,4,5)", "EnP2", "allBase,pi0Select5,2DPiAC0,2DEtaAC0", "mass245_En2_MC",
   //                      150,0.0,3.0, "m_{#gamma2#gamma4#gamma5} (GeV)", 100,0.0,8.00, "E_{#gamma2} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMC, NT, "MASS(3,4,5)", "EnP3", "allBase,pi0Select5,2DPiAC0,2DEtaAC0", "mass345_En3_MC",
   //                      150,0.0,3.0, "m_{#gamma3#gamma4#gamma5} (GeV)", 100,0.0,8.00, "E_{#gamma3} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // check baryon contributions from proton + extra photon
   // Plot2DHistWithCuts(FND, NT, "MASS(2,4,5)", "MASS(1,3)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0", "mass245_mass13",
   //                      150,0.0,3.0, "m_{#gamma2#gamma4#gamma5} (GeV)", 60,0.9,4.00, "m_{p#gamma3} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & #eta' #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FND, NT, "MASS(3,4,5)", "MASS(1,2)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0", "mass345_mass12",
   //                      150,0.0,3.0, "m_{#gamma3#gamma4#gamma5} (GeV)", 60,0.9,4.00, "m_{p#gamma2} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & #eta' #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMC, NT, "MASS(2,4,5)", "MASS(1,3)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0", "mass245_mass13_MC",
   //                      150,0.0,3.0, "m_{#gamma2#gamma4#gamma5} (GeV)", 60,0.9,4.00, "m_{p#gamma3} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & #eta' #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMC, NT, "MASS(3,4,5)", "MASS(1,2)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0", "mass345_mass12_MC",
   //                      150,0.0,3.0, "m_{#gamma3#gamma4#gamma5} (GeV)", 60,0.9,4.00, "p_{p#gamma2} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & #eta' #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);


   // plot projection Y
   // gStyle->SetOptStat(0);

   // TH2F* h2_omegaBaryon_0 = Get2DHistWithCuts(FND, NT, "MASS(2,4,5)", "MASS(1,3)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0", "mass245_mass13",
   //                      150,0.0,3.0, "m_{#gamma2#gamma4#gamma5} (GeV)", 60,0.9,4.00, "m_{p#gamma3} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & #eta' #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // TH2F* h2_omegaBaryon_1 = Get2DHistWithCuts(FND, NT, "MASS(3,4,5)", "MASS(1,2)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0", "mass345_mass12",
   //                      150,0.0,3.0, "m_{#gamma3#gamma4#gamma5} (GeV)", 60,0.9,4.00, "p_{p#gamma2} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & #eta' #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // TH1D* h1_omegaBaryon_0 = h2_omegaBaryon_0->ProjectionY("h1_omegaBaryon_0", 0, -1);
   // h1_omegaBaryon_0->GetYaxis()->SetTitle("counts");
   // h1_omegaBaryon_0->SetLineColor(kBlack);
   // TH1D* h1_omegaBaryon_1 = h2_omegaBaryon_1->ProjectionY("h1_omegaBaryon_1", 0, -1);
   // h1_omegaBaryon_1->GetYaxis()->SetTitle("counts");
   // h1_omegaBaryon_1->SetLineColor(kBlack);

   // TCanvas* c1 = new TCanvas("c1", "c1", 800, 600);
   // c1->cd();
   // h1_omegaBaryon_0->Draw("hist");
   // c1->SaveAs("h1_omegaBaryon_0.pdf");
   // h1_omegaBaryon_1->Draw("hist");
   // c1->SaveAs("h1_omegaBaryon_1.pdf");
   // Plot2DHistWithCuts(FNMC, NT, "MASS(2,4,5)", "MASS(1,2)", "allBase,pi0Select5,2DPiAC0,2DEtaAC0", "mass245_mass12_MC",
   //                      150,0.0,3.0, "m_{#gamma2#gamma4#gamma5} (GeV)", 30,0.9,4.00, "m_{p#gamma2} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMC, NT, "MASS(3,4,5)", "MASS(1,3)", "allBase,pi0Select5,2DPiAC0,2DEtaAC0", "mass345_mass13_MC",
   //                      150,0.0,3.0, "m_{#gamma3#gamma4#gamma5} (GeV)", 30,0.9,4.00, "p_{p#gamma3} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // Check Delta+ baryon contribution
   // Plot1DHistWithCuts(FND, NT, "MASS(1,4,5)", "allBase,pi0Select5,2DPiAC0,2DEtaAC0", "mass145",
                        // 90,1.0,4.0, "m_{p#gamma4#gamma5} (GeV)", "Events", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
                        // kFALSE, kFALSE, 0, 0,
                        // kFALSE, kFALSE, kFALSE, kFALSE);

   // Plot1DHistWithCuts(FNMC, NT, "MASS(1,4,5)", "allBase,pi0Select5,2DPiAC0,2DEtaAC0", "mass145_MC",
   //                      90,1.0,4.0, "m_{p#gamma4#gamma5} (GeV)", "Events", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, kFALSE, 0, 0,
   //                      kFALSE, kFALSE, kFALSE, kFALSE);

   // Plot2DHistWithCuts(FND, NT, "MASS(1,4,5)", "MASS(2,3)", "allBase,pi0Select5,2DPiAC0,2DEtaAC0", "mass145_mass23",
   //                      60,1.0,4.0, "m_{p#gamma4#gamma5} (GeV)", 60,0.0,3.00, "m_{#gamma2#gamma3} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMC, NT, "MASS(1,4,5)", "MASS(2,3)", "allBase,pi0Select5,2DPiAC0,2DEtaAC0", "mass145_mass23_MC",
   //                   60,1.0,4.0, "m_{p#gamma4#gamma5} (GeV)", 60,0.0,3.00, "m_{#gamma2#gamma3} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                   kFALSE, 0);

   // Plot1DHistWithCuts(FND, NT, "MASS(1,4,5)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0", "mass145_etaPrimeSelect",
   //                      90,1.0,3.5, "m_{p#gamma4#gamma5} (GeV)", "Events", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, kFALSE, 0, 0,
   //                      kFALSE, kFALSE, kFALSE, kFALSE);

   // Plot1DHistWithCuts(FNMC, NT, "MASS(1,4,5)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0", "mass145_etaPrimeSelect_MC",
   //                      90,1.0,3.5, "m_{p#gamma4#gamma5} (GeV)", "Events", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, kFALSE, 0, 0,
   //                      kFALSE, kFALSE, kFALSE, kFALSE);

   // Plot2DHistWithCuts(FND, NT, "MASS(1,4,5)", "MASS(2,3)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0", "mass145_mass23_etaPrimeSelect",
   //                   60,1.0,3.5, "m_{p#gamma4#gamma5} (GeV)", 60,0.9,1.0, "m_{#gamma2#gamma3} (GeV)", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                   kFALSE, 0);

   // Plot2DHistWithCuts(FNMC, NT, "MASS(1,4,5)", "MASS(2,3)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0", "mass145_mass23_etaPrimeSelect_MC",
   //                   60,1.0,3.5, "m_{p#gamma4#gamma5} (GeV)", 60,0.9,1.0, "m_{#gamma2#gamma3} (GeV)", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                   kFALSE, 0);

   // Plot1DHistWithCuts(FND, NT, "MASS(1,4,5)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,t_lt0.5", "mass145_etaPrimeSelect_tlt0.5",
   //                      90,1.0,3.5, "m_{p#gamma4#gamma5} (GeV)", "Events", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & |t| < 0.5 GeV^{2}",
   //                      kFALSE, kFALSE, 0, 0,
   //                      kFALSE, kFALSE, kFALSE, kFALSE);

   // Plot1DHistWithCuts(FNMC, NT, "MASS(1,4,5)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,t_lt0.5", "mass145_etaPrimeSelect_tlt0.5_MC",
   //                      90,1.0,3.5, "m_{p#gamma4#gamma5} (GeV)", "Events", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & |t| < 0.5 GeV^{2}",
   //                      kFALSE, kFALSE, 0, 0,
   //                      kFALSE, kFALSE, kFALSE, kFALSE);

   // Plot2DHistWithCuts(FND, NT, "MASS(1,4,5)", "MASS(2,3)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,t_lt0.5", "mass145_mass23_etaPrimeSelect_tlt0.5",
   //                   60,1.0,3.5, "m_{p#gamma4#gamma5} (GeV)", 60,0.9,1.0, "m_{#gamma2#gamma3} (GeV)", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & |t| < 0.5 GeV^{2}",
   //                   kFALSE, 0);

   // Plot2DHistWithCuts(FNMC, NT, "MASS(1,4,5)", "MASS(2,3)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,t_lt0.5", "mass145_mass23_etaPrimeSelect_tlt0.5_MC",
   //                   60,1.0,3.5, "m_{p#gamma4#gamma5} (GeV)", 60,0.9,1.0, "m_{#gamma2#gamma3} (GeV)", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & |t| < 0.5 GeV^{2}",
   //                   kFALSE, 0);

   // Plot1DHistWithCuts(FND, NT, "MASS(1,4,5)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5,t_lt0.5", "mass145_etaPrimeSelect_deltaCut_tlt0.5",
   //                      90,1.0,3.5, "m_{p#gamma4#gamma5} (GeV)", "Events", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & |t| < 0.5 GeV^{2}",
   //                      kFALSE, kFALSE, 0, 0,
   //                      kFALSE, kFALSE, kFALSE, kFALSE);

   // Plot1DHistWithCuts(FNMC, NT, "MASS(1,4,5)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5,t_lt0.5", "mass145_etaPrimeSelect_deltaCut_tlt0.5_MC",
   //                      90,1.0,3.5, "m_{p#gamma4#gamma5} (GeV)", "Events", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & |t| < 0.5 GeV^{2}",
   //                      kFALSE, kFALSE, 0, 0,
   //                      kFALSE, kFALSE, kFALSE, kFALSE);

   
   // Plot1DHistWithCuts(FND, NT, "MASS(1,2,3,4,5)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,t_lt0.5,pg4g5_lt1.4", "mass12345_etaPrimeSelect_tlt0.5",
   //                      50,4.0,4.2, "m_{p#gamma2#gamma3#gamma4#gamma5} (GeV)", "Events", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & |t| < 0.5 GeV^{2}",
   //                      kFALSE, kFALSE, 0, 0,
   //                      kFALSE, kFALSE, kFALSE, kFALSE);

   // Plot1DHistWithCuts(FND, NT, "MASS(1,2,3,4,5)", "allBase,etaPrimeSelect1,pi0Select4,2DPiAC1,2DEtaAC1,t_lt0.5,pg3g5_lt1.4", "mass12345_etaPrimeSelect_tlt0.5",
   //                      50,4.0,4.2, "m_{p#gamma2#gamma3#gamma4#gamma5} (GeV)", "Events", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & |t| < 0.5 GeV^{2}",
   //                      kFALSE, kFALSE, 0, 0,
   //                      kFALSE, kFALSE, kFALSE, kFALSE);

   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase","etaPrime2DPiEtaAC",kFALSE,kFALSE,kFALSE,kFALSE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase","etaPrime2DPiEtaACDeltaCut",kFALSE,kFALSE,kFALSE,kFALSE);
   // FSModeHistogram::dumpHistogramCache("histograms/2DPiEtaACDeltaCut_etaPrime");

   // check omega momentum
   // Plot2DHistWithCuts(FND, NT, "MASS(2,4,5)", "MOMENTUM(2,4,5)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5", "mass245_momentum245",
   //                      150,0.0,3.0, "m_{#gamma2#gamma4#gamma5} (GeV)", 100,0.0,10.00, "p_{#gamma2#gamma4#gamma5} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & #eta' #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FND, NT, "MASS(3,4,5)", "MOMENTUM(3,4,5)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5", "mass345_momentum345",
   //                      150,0.0,3.0, "m_{#gamma3#gamma4#gamma5} (GeV)", 100,0.0,10.00, "p_{#gamma3#gamma4#gamma5} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & #eta' #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMC, NT, "MASS(2,4,5)", "MOMENTUM(2,4,5)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5", "mass245_momentum245_MC",
   //                      150,0.0,3.0, "m_{#gamma2#gamma4#gamma5} (GeV)", 100,0.0,10.00, "p_{#gamma2#gamma4#gamma5} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & #eta' #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMC, NT, "MASS(3,4,5)", "MOMENTUM(3,4,5)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5", "mass345_momentum345_MC",
   //                      150,0.0,3.0, "m_{#gamma3#gamma4#gamma5} (GeV)", 100,0.0,10.00, "p_{#gamma3#gamma4#gamma5} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & #eta' #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // momentum with 2D 3gamma mass and momentum cut
   // Plot2DHistWithCuts(FND, NT, "MASS(2,4,5)", "MOMENTUM(2,4,5)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5,OmegaMomentumCut0", "mass245_momentum245",
   //                      150,0.0,3.0, "m_{#gamma2#gamma4#gamma5} (GeV)", 100,0.0,10.00, "p_{#gamma2#gamma4#gamma5} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & #eta' #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FND, NT, "MASS(3,4,5)", "MOMENTUM(3,4,5)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5,OmegaMomentumCut0", "mass345_momentum345",
   //                      150,0.0,3.0, "m_{#gamma3#gamma4#gamma5} (GeV)", 100,0.0,10.00, "p_{#gamma3#gamma4#gamma5} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & #eta' #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMC, NT, "MASS(2,4,5)", "MOMENTUM(2,4,5)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5,OmegaMomentumCut0", "mass245_momentum245_MC",
   //                      150,0.0,3.0, "m_{#gamma2#gamma4#gamma5} (GeV)", 100,0.0,10.00, "p_{#gamma2#gamma4#gamma5} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & #eta' #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMC, NT, "MASS(3,4,5)", "MOMENTUM(3,4,5)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5,OmegaMomentumCut0", "mass345_momentum345_MC",
   //                      150,0.0,3.0, "m_{#gamma3#gamma4#gamma5} (GeV)", 100,0.0,10.00, "p_{#gamma3#gamma4#gamma5} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & #eta' #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FND, NT, "MASS(2,4,5)", "cosTheta3G4GFrame(4;5;2;3)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5,t_lt0.5", "mass245_costheta3G4G",
   //                      150,0.0,3.0, "m_{#gamma2#gamma4#gamma5} (GeV)", 100,-1.0,1.0, "cos(#theta_{#gamma452,4#gamma})", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & |t| < 0.5",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMC, NT, "MASS(2,4,5)", "cosTheta3G4GFrame(4;5;2;3)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5,t_lt0.5", "mass245_costheta3G4G_MC",
   //                      150,0.0,3.0, "m_{#gamma2#gamma4#gamma5} (GeV)", 100,-1.0,1.0, "cos(#theta_{#gamma452,4#gamma})", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & |t| < 0.5",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FND, NT, "MASS(3,4,5)", "cosTheta3G4GFrame(4;5;3;2)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5,t_lt0.5", "mass345_costheta3G4G",
   //                      150,0.0,3.0, "m_{#gamma2#gamma4#gamma5} (GeV)", 100,-1.0,1.0, "cos(#theta_{#gamma453,4#gamma})", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & |t| < 0.5",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMC, NT, "MASS(3,4,5)", "cosTheta3G4GFrame(4;5;3;2)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5,t_lt0.5", "mass345_costheta3G4G_MC",
   //                      150,0.0,3.0, "m_{#gamma2#gamma4#gamma5} (GeV)", 100,-1.0,1.0, "cos(#theta_{#gamma453,4#gamma})", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & |t| < 0.5",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FND, NT, "MASS(2,4,5)", "cosTheta3GCOMFrame(4;5;2;GLUEXCMS)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5,OmegaCosThetaCOMCut0,t_lt0.5", "mass245_costheta3GCOM",
   //                      150,0.0,3.0, "m_{#gamma2#gamma4#gamma5} (GeV)", 100,-1.0,1.0, "cos(#theta_{#gamma452,COM})", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & |t| < 0.5",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMC, NT, "MASS(2,4,5)", "cosTheta3GCOMFrame(4;5;2;GLUEXCMS)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5,OmegaCosThetaCOMCut0,t_lt0.5", "mass245_costheta3GCOM_MC",
   //                      150,0.0,3.0, "m_{#gamma2#gamma4#gamma5} (GeV)", 100,-1.0,1.0, "cos(#theta_{#gamma452,COM})", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & |t| < 0.5",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FND, NT, "MASS(3,4,5)", "cosTheta3GCOMFrame(4;5;3;GLUEXCMS)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5,OmegaCosThetaCOMCut0,t_lt0.5", "mass345_costheta3GCOM",
   //                      150,0.0,3.0, "m_{#gamma2#gamma4#gamma5} (GeV)", 100,-1.0,1.0, "cos(#theta_{#gamma453,COM})", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & |t| < 0.5",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMC, NT, "MASS(3,4,5)", "cosTheta3GCOMFrame(4;5;3;GLUEXCMS)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5,OmegaCosThetaCOMCut0,t_lt0.5", "mass345_costheta3GCOM_MC",
   //                      150,0.0,3.0, "m_{#gamma2#gamma4#gamma5} (GeV)", 100,-1.0,1.0, "cos(#theta_{#gamma453,COM})", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & |t| < 0.5",
   //                      kFALSE, 0);


   // Plot2DHistWithCuts(FND, NT, "MASS(2,4,5)", "pi0Momentum3GFrame(4;5;2)", "allBase,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5,Gamma3Cut2", "mass245_Pi0Momentum3GFrame",
   //                      150,0.0,3.0, "m_{#gamma2#gamma4#gamma5} (GeV)", 100,0.0,1.0, "p_{#pi^{0}}^{3#gamma}", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMC, NT, "MASS(2,4,5)", "pi0Momentum3GFrame(4;5;2)", "allBase,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5,Gamma3Cut2", "mass245_Pi0Momentum3GFrame_MC",
   //                      150,0.0,3.0, "m_{#gamma2#gamma4#gamma5} (GeV)", 100,0.0,1.0, "p_{#pi^{0}}^{3#gamma}", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // PlotMass3GammaCombination(FND,NT,150,0.,3.0,"allBase,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5","gamma3momentumCut0",kTRUE,kFALSE,kFALSEpi0Momentum3GFrame), 3, ";

   // check omega momentum vs B(pgamma)
   // Plot2DHistWithCuts(FND, NT, "MASS(3,1)", "MOMENTUM(2,4,5)", "allBase,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5", "BaryonMass_momentum245",
   //                      100,0.0,4.0, "m_{#gamma3p} (GeV)", 100,0.0,10.00, "p_{#gamma2#gamma4#gamma5} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FND, NT, "MASS(2,1)", "MOMENTUM(3,4,5)", "allBase,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5", "BaryonMass_momentum345",
   //                      100,0.0,4.0, "m_{#gamma2p} (GeV)", 100,0.0,10.00, "p_{#gamma3#gamma4#gamma5} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMC, NT, "MASS(3,1)", "MOMENTUM(2,4,5)", "allBase,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5", "BaryonMass_momentum245_MC",
   //                      100,0.0,4.0, "m_{#gamma3p} (GeV)", 100,0.0,10.00, "p_{#gamma2#gamma4#gamma5} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMC, NT, "MASS(2,1)", "MOMENTUM(3,4,5)", "allBase,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5", "BaryonMass_momentum345_MC",
   //                      100,0.0,4.0, "m_{#gamma2p} (GeV)", 100,0.0,10.00, "p_{#gamma3#gamma4#gamma5} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);
   
   // Plot2DHistWithCuts(FND, NT, "MASS(3,1)", "MOMENTUM(2,4,5)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5", "BaryonMass_momentum245",
   //                      100,0.0,4.0, "m_{#gamma3p} (GeV)", 100,0.0,10.00, "p_{#gamma2#gamma4#gamma5} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & #eta' #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FND, NT, "MASS(2,1)", "MOMENTUM(3,4,5)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5", "BaryonMass_momentum345",
   //                      100,0.0,4.0, "m_{#gamma2p} (GeV)", 100,0.0,10.00, "p_{#gamma3#gamma4#gamma5} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & #eta' #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMC, NT, "MASS(3,1)", "MOMENTUM(2,4,5)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5", "BaryonMass_momentum245_MC",
   //                      100,0.0,4.0, "m_{#gamma3p} (GeV)", 100,0.0,10.00, "p_{#gamma2#gamma4#gamma5} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & #eta' #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMC, NT, "MASS(2,1)", "MOMENTUM(3,4,5)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5", "BaryonMass_momentum345_MC",
   //                      100,0.0,4.0, "m_{#gamma2p} (GeV)", 100,0.0,10.00, "p_{#gamma3#gamma4#gamma5} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & #eta' #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);


   // Plot2DHistWithCuts(FND, NT, "MASS(2,3)", "cosTheta2G2G4GFrame(2;3;4;5)", "allBase,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5", "mass23_costheta2GPi04GFrame",
   //                      100,0.9,1.0, "m_{#gamma2#gamma3} (GeV)", 100,-1.0,-0.9999, "cos(#theta_{#pi^{0}2#gamma})", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMC, NT, "MASS(2,3)", "cosTheta2G2G4GFrame(2;3;4;5)", "allBase,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5", "mass23_costheta2GPi04GFrame_MC",
   //                      100,0.9,1.0, "m_{#gamma2#gamma3} (GeV)", 100,-1.0,-0.9999, "cos(#theta_{#pi^{0}2#gamma})", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   
   // Plot2DHistWithCuts(FND, NT, "MASS(2,1)", "MOMENTUM(2,4,5)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5", "BaryonMass_momentum245",
   //                      100,0.0,4.0, "m_{#gamma2p} (GeV)", 100,0.0,10.00, "p_{#gamma2#gamma4#gamma5} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);
   // Plot2DHistWithCuts(FND, NT, "MASS(3,1)", "MOMENTUM(3,4,5)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5", "BaryonMass_momentum345",
   //                      100,0.0,4.0, "m_{#gamma3p} (GeV)", 100,0.0,10.00, "p_{#gamma3#gamma4#gamma5} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);
   // Plot2DHistWithCuts(FNMC, NT, "MASS(2,1)", "MOMENTUM(2,4,5)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5", "BaryonMass_momentum245_MC",
   //                      100,0.0,4.0, "m_{#gamma2p} (GeV)", 100,0.0,10.00, "p_{#gamma2#gamma4#gamma5} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);
   // Plot2DHistWithCuts(FNMC, NT, "MASS(3,1)", "MOMENTUM(3,4,5)", "allBase,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5", "BaryonMass_momentum345_MC",
   //                      100,0.0,4.0, "m_{#gamma3p} (GeV)", 100,0.0,10.00, "p_{#gamma3#gamma4#gamma5} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);
   // TH2F* h2_mass245_mass12 = Get2DHistWithCuts(FND, NT, "MASS(2,1)", "MOMENTUM(2,4,5)", "allBase,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5", "BaryonMass_momentum245",
   //                      100,0.0,4.0, "m_{#gamma2p} (GeV)", 100,0.0,10.00, "p_{#gamma2#gamma4#gamma5} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // Double_t grad = (8.5-6)/(1.8-1);
   // Double_t y_intersect = 1.0;
   
   // TF1* f_mass245_mass12_cut_line = new TF1("f_mass245_mass12_cut_line","[0]*x+[1]",0.0,4.0);
   // f_mass245_mass12_cut_line->SetParameter(0,grad);
   // f_mass245_mass12_cut_line->SetParameter(1,y_intersect);

   // TCanvas* c_mass245_mass12 = new TCanvas("c_mass245_mass12","c_mass245_mass12",800,600);
   // h2_mass245_mass12->Draw("colz");
   // f_mass245_mass12_cut_line->Draw("SAME");
   // c_mass245_mass12->SaveAs("plots/mass245_mass12.pdf");   

   
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase","etaPrime2DPiEtaAC",kFALSE,kFALSE,kFALSE,kFALSE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase","etaPrime2DPiEtaACDeltaCut",kFALSE,kFALSE,kFALSE,kFALSE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase","etaPrime2DPiEtaACDeltaCutOmegaMomentumCut",kFALSE,kFALSE,kFALSE,kFALSE);
   // FSModeHistogram::dumpHistogramCache("histograms/2DPiEtaACDeltaCutOmegaMomentumCut_etaPrime");

   // FSModeHistogram::readHistogramCache();
   // PlotMass4Gamma(FND,NT,50,1.0,3.0,"allBase,t_lt0.5","2DEtaPi0ACDeltaCutOmegaMomentumCut",kFALSE,kFALSE,kTRUE,kTRUE,kFALSE,kTRUE,kTRUE,kTRUE,kFALSE,kTRUE,FNMC,FNMCGen,"CUT(mcebeam,mct_lt0.5)");
   // PlotMass4Gamma(FND,NT,50,1.0,3.0,"allBase,t_lt0.5","2DEtaPi0ACDeltaCutOmegaMomentumCut_SSB",kFALSE,kFALSE,kTRUE,kTRUE,kFALSE,kTRUE,kTRUE,kTRUE,kTRUE,kTRUE,FNMC,FNMCGen,"CUT(mcebeam,mct_lt0.5)");
   // FSModeHistogram::dumpHistogramCache();

   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase","etaPrime2DPiEtaAC",kFALSE,kFALSE,kFALSE,kFALSE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase","etaPrime2DPiEtaACDeltaCut",kFALSE,kFALSE,kFALSE,kFALSE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase","etaPrime2DPiEtaACDeltaCutOmegaCosThetaCOMCut",kFALSE,kFALSE,kFALSE,kFALSE);
   // FSModeHistogram::dumpHistogramCache("histograms/2DPiEtaACDeltaCutOmegaCosThetaCOMCut_etaPrime");
   
   // FSModeHistogram::readHistogramCache();
   // PlotOmegaMassWithCuts(FND,NT,50,0.6,0.9,"allBase","NoOmegaCut",kTRUE);
   // PlotOmegaMassWithCuts(FND,NT,50,0.6,0.9,"allBase","OmegaMomentumCut",kTRUE);
   // PlotOmegaMassWithCuts(FND,NT,50,0.6,0.9,"allBase","OmegaCosThetaCOMCut",kTRUE);
   // FSModeHistogram::dumpHistogramCache();

   //explore BGGen
   
   // PlotMass2GammaCombination(FNMCBGGEN,NT,40,0.85,1.05,"allBaseBGGen","",kFALSE,kFALSE,kFALSE,kFALSE);
   // PlotMass2GammaCombination(FNMCBGGEN,NT,40,0.85,1.05,"allBaseBGGen","etaPrime2DPiEtaAC",kFALSE,kFALSE,kFALSE,kFALSE);
   // PlotMass2GammaCombination(FNMCBGGEN,NT,40,0.85,1.05,"allBaseBGGen","etaPrime2DPiEtaACDeltaCut",kFALSE,kFALSE,kFALSE,kFALSE);
   // PlotMass2GammaCombination(FNMCBGGEN,NT,40,0.85,1.05,"allBaseBGGen","etaPrime2DPiEtaACDeltaCutOmegaCosThetaCOMCut",kFALSE,kFALSE,kFALSE,kFALSE);

   // TCanvas *c = new TCanvas("c","c",800,600);
   // for (Int_t i=0;i<6;i++) {
   //    Int_t vectorIndexCombination[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   //    FSModeHistogram::drawMCComponents(FNMCBGGEN,NT,"m100_4000000",Form("MASS(%d,%d)",vectorIndexCombination[i][0],vectorIndexCombination[i][1]),"(40,0.85,1.05)",Form("CUT(allBaseBGGen,etaPrimeSelect%d,pi0Select%d,2DPiAC%d,2DEtaAC%d)",i,5-i,i,i),1.0,c,true);
   //    c->SaveAs(Form("massEtaPrimeSelect_2DPiAC_2DEtaAC_%d.pdf",i));
   // }
   // for (Int_t i=0;i<6;i++) {
   //    Int_t vectorIndexCombination[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   //    FSModeHistogram::drawMCComponents(FNMCBGGEN,NT,"m100_4000000",Form("MASS(%d,%d)",vectorIndexCombination[i][0],vectorIndexCombination[i][1]),"(40,0.85,1.05)",Form("CUT(allBaseBGGen,etaPrimeSelect%d,pi0Select%d,2DPiAC%d,2DEtaAC%d,DeltaCut%d)",i,5-i,i,i,5-i),1.0,c,true);
   //    c->SaveAs(Form("massEtaPrimeSelect_2DPiAC_2DEtaAC_DeltaCut_%d.pdf",i));
   // }
   // for (Int_t i=0;i<6;i++) {
   //    Int_t vectorIndexCombination[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   //    FSModeHistogram::drawMCComponents(FNMCBGGEN,NT,"m100_4000000",Form("MASS(%d,%d)",vectorIndexCombination[i][0],vectorIndexCombination[i][1]),"(40,0.85,1.05)",Form("CUT(allBaseBGGen,etaPrimeSelect%d,pi0Select%d,2DPiAC%d,2DEtaAC%d,DeltaCut%d,OmegaCosThetaCOMCut%d)",i,5-i,i,i,5-i,i),1.0,c,true);
   //    c->SaveAs(Form("massEtaPrimeSelect_2DPiAC_2DEtaAC_DeltaCut_OmegaCut_%d.pdf",i));
   // }

   // vector<TString> vMCCompBGGen = FSModeHistogram::getMCComponents(FNMCBGGEN,NT,"m100_4000000","MASS(2,3)","(40,0.85,1.05)","CUT(allBaseBGGen,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0)",1.0);
   // for (Int_t i=0;i<vMCCompBGGen.size();i++) {
   //    cout << FSModeHistogram::getMCComponentCut(vMCCompBGGen[i]) << endl;
   // }

   // auto vMCCompBGGen = FSModeHistogram::getMCComponentsAndSizes(FNMCBGGEN,NT,"m100_4000000","MASS(2,3)","(40,0.85,1.05)","CUT(allBaseBGGen,etaPrimeSelect0,pi0Select5,2DPiAC0,2DEtaAC0)",1.0);
   // for (auto it = vMCCompBGGen.begin(); it != vMCCompBGGen.end(); it++) {
   //    cout << it->first << " " << it->second << endl;
   // }

   // FSModeHistogram::readHistogramCache();
   // PlotMass2GammaCombinationBGGen(FNMCBGGEN,NT,40,0.85,1.05,"allBaseBGGen","",kFALSE,kFALSE,kFALSE,kFALSE);
   // PlotMass2GammaCombinationBGGen(FNMCBGGEN,NT,40,0.85,1.05,"allBaseBGGen","etaPrime2DPiEtaAC",kFALSE,kFALSE,kFALSE,kFALSE);
   // PlotMass2GammaCombinationBGGen(FNMCBGGEN,NT,40,0.85,1.05,"allBaseBGGen","etaPrime2DPiEtaACDeltaCut",kFALSE,kFALSE,kFALSE,kFALSE);
   // PlotMass2GammaCombinationBGGen(FNMCBGGEN,NT,40,0.85,1.05,"allBaseBGGen","etaPrime2DPiEtaACDeltaCutOmegaCosThetaCOMCut",kFALSE,kFALSE,kFALSE,kFALSE);
   // FSModeHistogram::dumpHistogramCache();

   // FSModeHistogram::readHistogramCache();
   // PlotMass4Gamma(FND,NT,50,1.0,3.0,"allBase,t_lt0.5","2DEtaPi0AC",
   //                kFALSE,kFALSE,kTRUE,kTRUE,kFALSE,kTRUE,kFALSE,kFALSE,kFALSE,
   //                kFALSE,kTRUE,FNMC,FNMCGen,"CUT(mcebeam,mct_lt0.5)");
   // PlotMass4Gamma(FND,NT,50,1.0,3.0,"allBase,t_lt0.5","2DEtaPi0AC_SSB",
   //                kFALSE,kFALSE,kTRUE,kTRUE,kFALSE,kTRUE,kFALSE,kFALSE,kFALSE,
   //                kTRUE,kTRUE,FNMC,FNMCGen,"CUT(mcebeam,mct_lt0.5)");
   // PlotMass4Gamma(FND,NT,50,1.0,3.0,"allBase,t_lt0.5","2DEtaPi0ACDeltaCut",
   //                kFALSE,kFALSE,kTRUE,kTRUE,kFALSE,kTRUE,kTRUE,kFALSE,kFALSE,
   //                kFALSE,kTRUE,FNMC,FNMCGen,"CUT(mcebeam,mct_lt0.5)");
   // PlotMass4Gamma(FND,NT,50,1.0,3.0,"allBase,t_lt0.5","2DEtaPi0ACDeltaCut_SSB",
   //                kFALSE,kFALSE,kTRUE,kTRUE,kFALSE,kTRUE,kTRUE,kFALSE,kFALSE,
   //                kTRUE,kTRUE,FNMC,FNMCGen,"CUT(mcebeam,mct_lt0.5)");
   // PlotMass4Gamma(FND,NT,50,1.0,3.0,"allBase,t_lt0.5","2DEtaPi0ACDeltaCutOmegaCosThetaCOMCut",
   //                kFALSE,kFALSE,kTRUE,kTRUE,kFALSE,kTRUE,kTRUE,kFALSE,kTRUE,
   //                kFALSE,kTRUE,FNMC,FNMCGen,"CUT(mcebeam,mct_lt0.5)");
   // PlotMass4Gamma(FND,NT,50,1.0,3.0,"allBase,t_lt0.5","2DEtaPi0ACDeltaCutOmegaCosThetaCOMCut_SSB",
   //                kFALSE,kFALSE,kTRUE,kTRUE,kFALSE,kTRUE,kTRUE,kFALSE,kTRUE,
   //                kTRUE,kTRUE,FNMC,FNMCGen,"CUT(mcebeam,mct_lt0.5)");
   // FSModeHistogram::dumpHistogramCache();

   // Plot2DHistWithCuts(FNMCBGGEN, NT, "MASS(2,3)", "absMomentum2EnergyRatio(2,3)", "allBaseBGGen,pi0Select5,2DPiAC0,2DEtaAC0,sel_p_3pi0", "mass23_absMomentum2EnergyRatio23_BGGen",
   //                      100,0.9,1.0, "m_{#gamma2#gamma3} (GeV)", 50,0.,1.0, "#frac{|#vec{p}_{23}|}{E_{23}}", "Selection: #pi^{0} #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMCBGGEN, NT, "MASS(2,3)", "absMomentum2EnergyRatio(2,3)", "allBaseBGGen,pi0Select5,2DPiAC0,2DEtaAC0,sel_p_ggpi0", "mass23_absMomentum2EnergyRatio23_BGGen",
   //                      100,0.9,1.0, "m_{#gamma2#gamma3} (GeV)", 50,0.,1.0, "#frac{|#vec{p}_{23}|}{E_{23}}", "Selection: #pi^{0} #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // Plot1DHistWithCuts(FNMCBGGEN, NT, "MASS(2,3)", "allBaseBGGen,pi0Select5,2DPiAC0,2DEtaAC0,sel_p_3pi0", "",
   //                      50,0.85,1.05, "m_{#gamma2#gamma3} (GeV)", "Events", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, kFALSE, 0, 0,
   //                      kFALSE, kFALSE, kFALSE, kFALSE);
   // Plot1DHistWithCuts(FNMCBGGEN, NT, "MASS(2,3)", "allBaseBGGen,pi0Select5,2DPiAC0,2DEtaAC0,sel_p_ggpi0", "",
   //                      50,0.85,1.05, "m_{#gamma2#gamma3} (GeV)", "Events", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, kFALSE, 0, 0,
   //                      kFALSE, kFALSE, kFALSE, kFALSE);
   // Plot2DHistWithCuts(FNMC, NT, "MASS(2,3)", "absMomentum2EnergyRatio(4,5)", "allBase,pi0Select5,2DPiAC0,2DEtaAC0,DeltaCut5,OmegaCosThetaCOMCut0", "mass23_absMomentum2EnergyRatio45_BGGen",
   //                      100,0.9,1.0, "m_{#gamma2#gamma3} (GeV)", 20,0.,1.0, "|#vec{p}_{45}| (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMCBGGEN, NT, "MASS(2,3)", "MOMENTUM(2)", "allBaseBGGen,pi0Select5,2DPiAC0,2DEtaAC0,sel_p_3pi0", "",
   //                      100,0.9,1.0, "m_{#gamma2#gamma3} (GeV)", 50,0.,10.0, "|#vec{p}_{2}|", "Selection: #pi^{0} #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMCBGGEN, NT, "MASS(2,3)", "MOMENTUM(2)", "allBaseBGGen,pi0Select5,2DPiAC0,2DEtaAC0,sel_p_ggpi0", "",
   //                      100,0.9,1.0, "m_{#gamma2#gamma3} (GeV)", 50,0.,10.0, "|#vec{p}_{2}|", "Selection: #pi^{0} #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);
   
   // Plot2DHistWithCuts(FNMCBGGEN, NT, "MASS(2,3)", "MOMENTUM(3)", "allBaseBGGen,pi0Select5,2DPiAC0,2DEtaAC0,sel_p_3pi0", "",
   //                      100,0.9,1.0, "m_{#gamma2#gamma3} (GeV)", 50,0.,10.0, "|#vec{p}_{3}|", "Selection: #pi^{0} #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMCBGGEN, NT, "MASS(2,3)", "MOMENTUM(3)", "allBaseBGGen,pi0Select5,2DPiAC0,2DEtaAC0,sel_p_ggpi0", "",
   //                      100,0.9,1.0, "m_{#gamma2#gamma3} (GeV)", 50,0.,10.0, "|#vec{p}_{3}|", "Selection: #pi^{0} #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMCBGGEN, NT, "MASS(2,3)", "cosTheta2GCOMFrame(2;3;2,3,4,5)", "allBaseBGGen,pi0Select5,2DPiAC0,2DEtaAC0,sel_p_3pi0", "",
   //                      100,0.9,1.0, "m_{#gamma2#gamma3} (GeV)", 50,-1.0,1.0, "cos(#theta)", "Selection: #pi^{0} #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMCBGGEN, NT, "MASS(2,3)", "cosTheta2GCOMFrame(2;3;B)", "allBaseBGGen,pi0Select5,2DPiAC0,2DEtaAC0,sel_p_ggpi0", "",
   //                      100,0.9,1.0, "m_{#gamma2#gamma3} (GeV)", 50,-1.0,1.0, "cos(#theta)", "Selection: #pi^{0} #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMCBGGEN, NT, "MASS(2,3)", "ENERGY(2)", "allBaseBGGen,pi0Select5,2DPiAC0,2DEtaAC0,sel_p_3pi0", "",
   //                      100,0.9,1.0, "m_{#gamma2#gamma3} (GeV)", 50,0.,10.0, "E_{2}", "Selection: #pi^{0} #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMCBGGEN, NT, "MASS(2,3)", "ENERGY(2)", "allBaseBGGen,pi0Select5,2DPiAC0,2DEtaAC0,sel_p_ggpi0", "",
   //                      100,0.9,1.0, "m_{#gamma2#gamma3} (GeV)", 50,0.,10.0, "E_{2}", "Selection: #pi^{0} #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);
   
   // Plot2DHistWithCuts(FNMCBGGEN, NT, "MASS(2,3)", "ENERGY(3)", "allBaseBGGen,pi0Select5,2DPiAC0,2DEtaAC0,sel_p_3pi0", "",
   //                      100,0.9,1.0, "m_{#gamma2#gamma3} (GeV)", 50,0.,10.0, "E_{3}", "Selection: #pi^{0} #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMCBGGEN, NT, "MASS(2,3)", "ENERGY(3)", "allBaseBGGen,pi0Select5,2DPiAC0,2DEtaAC0,sel_p_ggpi0", "",
   //                      100,0.9,1.0, "m_{#gamma2#gamma3} (GeV)", 50,0.,10.0, "E_{3}", "Selection: #pi^{0} #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   //make plots for presentation in working group meeting
   // FSModeHistogram::readHistogramCache("histograms/e8288");
   // PlotMass2GammaCombination(FND,NT,150,0.0,1.5,"e8288","",kFALSE,kFALSE,kFALSE,kFALSE);
   // FSModeHistogram::dumpHistogramCache("histograms/e8288");

   // FSModeHistogram::readHistogramCache("histograms/Mass2GammCombination_allBase");
   // PlotMass2GammaCombination(FND,NT,150,0.0,1.5,"allBase","",kFALSE,kFALSE,kFALSE,kFALSE);
   // FSModeHistogram::dumpHistogramCache("histograms/Mass2GammCombination_allBase");

   // FSModeHistogram::readHistogramCache("histograms/Mass2GammCombination_allBase_pi0");
   // PlotMass2GammaCombination(FND,NT,100,0.08,0.18,"allBase","",kFALSE,kFALSE,kFALSE,kFALSE);
   // FSModeHistogram::dumpHistogramCache("histograms/Mass2GammCombination_allBase_pi0");

   // FSModeHistogram::readHistogramCache("histograms/Mass2GammCombination_allBase_etaPrime");
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase","etaPrime",kFALSE,kFALSE,kFALSE,kFALSE);
   // FSModeHistogram::dumpHistogramCache("histograms/Mass2GammCombination_allBase_etaPrime");

   // Plot2DHistWithCuts(FND, NT, "MASS(2,4)", "MASS(3,5)", "allBase,pi0Select5", "mass(2,4)_vs_mass(3,5)",
   //                      50,0.0,1.0, "m_{#gamma2#gamma4} [GeV/c^{2}]", 50, 0.0, 1.0, "m_{#gamma3#gamma5} [GeV/c^{2}]", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FND, NT, "MASS(2,5)", "MASS(3,4)", "allBase,pi0Select5", "mass(2,5)_vs_mass(3,4)",
   //                      50,0.0,1.0, "m_{#gamma2#gamma5} [GeV/c^{2}]", 50, 0.0, 1.0, "m_{#gamma3#gamma4} [GeV/c^{2}]", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FND, NT, "MASS(2,4)", "MASS(3,5)", "allBase,pi0Select5,2DPiAC0,2DEtaAC0", "mass(2,4)_vs_mass(3,5)",
   //                      50,0.0,1.0, "m_{#gamma2#gamma4} [GeV/c^{2}]", 50, 0.0, 1.0, "m_{#gamma3#gamma5} [GeV/c^{2}]", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FND, NT, "MASS(2,5)", "MASS(3,4)", "allBase,pi0Select5,2DPiAC0,2DEtaAC0,2DLowPhotonAC0", "mass(2,5)_vs_mass(3,4)",
   //                      50,0.0,1.0, "m_{#gamma2#gamma5} [GeV/c^{2}]", 50, 0.0, 1.0, "m_{#gamma3#gamma4} [GeV/c^{2}]", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FND, NT, "MASS(2,4)", "MASS(3,5)", "allBase,pi0Select5,2DPiAC0,2DEtaAC0,2DLowPhotonAC0", "mass(2,4)_vs_mass(3,5)",
   //                      50,0.0,1.0, "m_{#gamma2#gamma4} [GeV/c^{2}]", 50, 0.0, 1.0, "m_{#gamma3#gamma5} [GeV/c^{2}]", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // reached the limit of TTreeFormula

   // Plot2DHistWithCuts(FNDEtaPi0AC[0], NT, "MASS(2,5)", "MASS(3,4)", "2DLowPhotonAC0,2DOmegaAC0", "mass(2,5)_vs_mass(3,4)",
   //                      50,0.0,1.0, "m_{#gamma2#gamma5} [GeV/c^{2}]", 50, 0.0, 1.0, "m_{#gamma3#gamma4} [GeV/c^{2}]", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNDEtaPi0AC[0], NT, "MASS(2,4)", "MASS(3,5)", "2DLowPhotonAC0,2DOmegaAC0", "mass(2,4)_vs_mass(3,5)",
   //                      50,0.0,1.0, "m_{#gamma2#gamma4} [GeV/c^{2}]", 50, 0.0, 1.0, "m_{#gamma3#gamma5} [GeV/c^{2}]", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FND, NT, "MASS(2,5)", "MASS(3,4)", "allBase,pi0Select5,2DPiAC0,2DEtaAC0", "mass(2,5)_vs_mass(3,4)",
   //                      50,0.0,1.0, "m_{#gamma2#gamma5} [GeV/c^{2}]", 50, 0.0, 1.0, "m_{#gamma3#gamma4} [GeV/c^{2}]", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);


   // Plot2DHistWithCuts(FND, NT, "MASS(2,4)", "MASS(3,5)", "allBase,pi0Select5,etaPrimeSelect0", "mass(2,4)_vs_mass(3,5)",
   //                      50,0.0,1.0, "m_{#gamma2#gamma4} [GeV/c^{2}]", 50, 0.0, 1.0, "m_{#gamma3#gamma5} [GeV/c^{2}]", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FND, NT, "MASS(2,5)", "MASS(3,4)", "allBase,pi0Select5,etaPrimeSelect0", "mass(2,5)_vs_mass(3,4)",
   //                      50,0.0,1.0, "m_{#gamma2#gamma5} [GeV/c^{2}]", 50, 0.0, 1.0, "m_{#gamma3#gamma4} [GeV/c^{2}]", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMC, NT, "MASS(2,4)", "MASS(3,5)", "allBase,pi0Select5,etaPrimeSelect0", "mass(2,4)_vs_mass(3,5) MC",
   //                      50,0.0,1.0, "m_{#gamma2#gamma4} [GeV/c^{2}]", 50, 0.0, 1.0, "m_{#gamma3#gamma5} [GeV/c^{2}]", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMC, NT, "MASS(2,5)", "MASS(3,4)", "allBase,pi0Select5,etaPrimeSelect0", "mass(2,5)_vs_mass(3,4) MC",
   //                      50,0.0,1.0, "m_{#gamma2#gamma5} [GeV/c^{2}]", 50, 0.0, 1.0, "m_{#gamma3#gamma4} [GeV/c^{2}]", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FND, NT, "MASS(2,4)", "MASS(3,5)", "allBase,pi0Select5,etaPrimeSelect0", "mass(2,4)_vs_mass(3,5)",
   //                      50,0.0,1.0, "m_{#gamma2#gamma4} [GeV/c^{2}]", 50, 0.0, 1.0, "m_{#gamma3#gamma5} [GeV/c^{2}]", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FND, NT, "MASS(2,5)", "MASS(3,4)", "allBase,pi0Select5,etaPrimeSelect0", "mass(2,5)_vs_mass(3,4)",
   //                      50,0.0,1.0, "m_{#gamma2#gamma5} [GeV/c^{2}]", 50, 0.0, 1.0, "m_{#gamma3#gamma4} [GeV/c^{2}]", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

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
   
   // FSModeHistogram::readHistogramCache("histograms/Mass2GammCombination_allBase_2DPiEtaAC_etaPrime");
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase","etaPrime",kFALSE,kFALSE,kFALSE,kFALSE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase","etaPrime2DPiAC",kFALSE,kFALSE,kFALSE,kFALSE);
   // PlotMass2GammaCombination(FND,NT,40,0.85,1.05,"allBase","etaPrime2DPiEtaAC",kFALSE,kFALSE,kFALSE,kFALSE);
   // FSModeHistogram::dumpHistogramCache("histograms/Mass2GammCombination_allBase_2DPiEtaAC_etaPrime");

   // FSModeHistogram::readHistogramCache("histograms/Mass2GammCombination_allBase_2DPiEtaAC_2DLowPhotonAC_2DOmegaAC_etaPrime");
   // PlotMass2GammaCombinationSkimmed2DEtaPiAC(FNDEtaPi0AC,NT,40,0.85,1.05,"","etaPrime",kFALSE,kFALSE,kFALSE,kFALSE);
   // PlotMass2GammaCombinationSkimmed2DEtaPiAC(FNDEtaPi0AC,NT,40,0.85,1.05,"","etaPrime2DLowPhotonAC",kFALSE,kFALSE,kFALSE,kFALSE);
   // PlotMass2GammaCombinationSkimmed2DEtaPiAC(FNDEtaPi0AC,NT,40,0.85,1.05,"","etaPrime2DLowPhotonAC2DOmegaAC",kFALSE,kFALSE,kFALSE,kFALSE);
   // FSModeHistogram::dumpHistogramCache("histograms/Mass2GammCombination_allBase_2DPiEtaAC_2DLowPhotonAC_2DOmegaAC_etaPrime");

   // Plot1DHistWithCuts(FNDEtaPi0AC[0], NT, "MASS(1,4,5)", "2DLowPhotonAC0,2DOmegaAC0", "mass145",
   //                   90,1.0,4.0, "m_{p#gamma4#gamma5} (GeV)", "Events", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                   kFALSE, kFALSE, 0, 0,
   //                   kFALSE, kFALSE, kFALSE, kFALSE);

   // PlotMass2GammaCombinationSkimmed2DEtaPiAC(FNMCEtaPi0AC,NT,40,0.85,1.05,"","etaPrime2DLowPhotonAC2DOmegaAC",kFALSE,kFALSE,kFALSE,kFALSE);
   // FSModeHistogram::dumpHistogramCache("histograms/Mass2GammCombination_allBase_2DPiEtaAC_2DLowPhotonAC_2DOmegaAC_etaPrime_MC");

   // TCanvas *c = new TCanvas("c","c",1200,600);
   // TH1F *h_data = Get1DHistWithCuts(FNDEtaPi0AC[0], NT, "MASS(1,4,5)", "2DLowPhotonAC0,2DOmegaAC0,etaPrimeSelect0", "mass145_etaPrimeSelect",
   //                      90,1.0,3.5, "m_{p#gamma4#gamma5} (GeV)", "Events", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}");

   // h_data->Draw("HIST");
   // TH1F *h_MC = Get1DHistWithCuts(FNMCEtaPi0AC[0], NT, "MASS(1,4,5)", "2DLowPhotonAC0,2DOmegaAC0,etaPrimeSelect0", "mass145_etaPrimeSelect_MC",
   //                      90,1.0,3.5, "m_{p#gamma4#gamma5} (GeV)", "Events", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}");
   // // rescale MC
   // h_MC->Scale(0.7*h_data->Integral()/h_MC->Integral());
   // h_MC->SetLineColor(kRed);
   // h_MC->Draw("HIST SAME");

   // // add legend
   // TLegend *leg = new TLegend(0.4,0.2,0.6,0.3);
   // leg->AddEntry(h_data,"Data","l");
   // leg->AddEntry(h_MC,"Scaled MC","l");
   // leg->Draw();

   // // draw box for delta cut from 1.0 GeV to 1.4 GeV
   // TBox *box = new TBox(1.0,0.0,1.4,h_data->GetMaximum());
   // box->SetFillColor(kRed);
   // box->SetFillStyle(3002);
   // box->Draw();

   // // draw line for delta mass
   // TLine *line = new TLine(1.232,0.0,1.232,h_data->GetMaximum());
   // line->SetLineColor(kBlue);
   // line->SetLineStyle(2);
   // line->Draw();
   // c->SaveAs("mass145_etaPrimeSelect0.pdf");
   

   // Plot2DHistWithCuts(FNDEtaPi0AC[0], NT, "MASS(1,4,5)", "MASS(2,3)", "2DLowPhotonAC0,2DOmegaAC0,etaPrimeSelect0", "mass145_mass23_etaPrimeSelect",
   //                   60,1.0,3.5, "m_{p#gamma4#gamma5} (GeV)", 60,0.9,1.0, "m_{#gamma2#gamma3} (GeV)", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                   kFALSE, 0);

   // Plot2DHistWithCuts(FNMCEtaPi0AC[0], NT, "MASS(1,4,5)", "MASS(2,3)", "2DLowPhotonAC0,2DOmegaAC0,etaPrimeSelect0", "mass145_mass23_etaPrimeSelect_MC",
   //                   60,1.0,3.5, "m_{p#gamma4#gamma5} (GeV)", 60,0.9,1.0, "m_{#gamma2#gamma3} (GeV)", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                   kFALSE, 0);

   // PlotMass3GammaCombination(FNDEtaPi0AC[0],NT,150,0.,3.0,"2DLowPhotonAC0,2DOmegaAC0,etaPrimeSelect0,DeltaCut0","1stCombination",kFALSE,kFALSE,kFALSE);
   // FSModeHistogram::dumpHistogramCache("histograms/Mass3GammCombination_allBase_2DPiEtaAC_2DLowPhotonAC_2DOmegaAC_etaPrime");

   // Plot2DHistWithCuts(FNDEtaPi0AC[0], NT, "MASS(2,4,5)", "MASS(1,3)", "2DLowPhotonAC0,2DOmegaAC0,etaPrimeSelect0,DeltaCut0", "mass245_mass13",
   //                      150,0.0,3.0, "m_{#gamma2#gamma4#gamma5} (GeV)", 155,0.9,4.00, "m_{p#gamma3} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & #eta' #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNDEtaPi0AC[0], NT, "MASS(3,4,5)", "MASS(1,2)", "2DLowPhotonAC0,2DOmegaAC0,etaPrimeSelect0,DeltaCut0", "mass345_mass12",
   //                      150,0.0,3.0, "m_{#gamma3#gamma4#gamma5} (GeV)", 155,0.9,4.00, "m_{p#gamma2} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & #eta' #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // TH2F* h2_omegaBaryon_0 = Get2DHistWithCuts(FNDEtaPi0AC[0], NT, "MASS(2,4,5)", "MASS(1,3)", "2DLowPhotonAC0,2DOmegaAC0,etaPrimeSelect0,DeltaCut0", "mass245_mass13",
   //                      150,0.0,3.0, "m_{#gamma2#gamma4#gamma5} (GeV)", 155,0.9,4.00, "m_{p#gamma3} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & #eta' #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // TH2F* h2_omegaBaryon_1 = Get2DHistWithCuts(FNDEtaPi0AC[0], NT, "MASS(3,4,5)", "MASS(1,2)", "2DLowPhotonAC0,2DOmegaAC0,etaPrimeSelect0,DeltaCut0", "mass345_mass12",
   //                      150,0.0,3.0, "m_{#gamma3#gamma4#gamma5} (GeV)", 155,0.9,4.00, "m_{p#gamma2} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & #eta' #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // TH2F* h2_omegaBaryon_MC_0 = Get2DHistWithCuts(FNMCEtaPi0AC[0], NT, "MASS(2,4,5)", "MASS(1,3)", "2DLowPhotonAC0,2DOmegaAC0,etaPrimeSelect0,DeltaCut0", "mass245_mass13",
   //                      150,0.0,3.0, "m_{#gamma2#gamma4#gamma5} (GeV)", 155,0.9,4.00, "m_{p#gamma3} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & #eta' #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // TH2F* h2_omegaBaryon_MC_1 = Get2DHistWithCuts(FNMCEtaPi0AC[0], NT, "MASS(3,4,5)", "MASS(1,2)", "2DLowPhotonAC0,2DOmegaAC0,etaPrimeSelect0,DeltaCut0", "mass345_mass12",
   //                      150,0.0,3.0, "m_{#gamma3#gamma4#gamma5} (GeV)", 155,0.9,4.00, "m_{p#gamma2} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & #eta' #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // TH1D* h1_omegaBaryon_0 = h2_omegaBaryon_0->ProjectionY("h1_omegaBaryon_0", 0, -1);
   // h1_omegaBaryon_0->GetYaxis()->SetTitle("counts");
   // h1_omegaBaryon_0->SetLineColor(kBlack);
   // TH1D* h1_omegaBaryon_MC_0 = h2_omegaBaryon_MC_0->ProjectionY("h1_omegaBaryon_MC_0", 0, -1);
   // h1_omegaBaryon_MC_0->GetYaxis()->SetTitle("counts");
   // h1_omegaBaryon_MC_0->SetLineColor(kRed);
   // // scale MC
   // h1_omegaBaryon_MC_0->Scale(0.7*h1_omegaBaryon_0->Integral()/h1_omegaBaryon_MC_0->Integral());

   // TH1D* h1_omegaBaryon_1 = h2_omegaBaryon_1->ProjectionY("h1_omegaBaryon_1", 0, -1);
   // h1_omegaBaryon_1->GetYaxis()->SetTitle("counts");
   // h1_omegaBaryon_1->SetLineColor(kBlack);

   // TH1D* h1_omegaBaryon_MC_1 = h2_omegaBaryon_MC_1->ProjectionY("h1_omegaBaryon_MC_1", 0, -1);
   // h1_omegaBaryon_MC_1->GetYaxis()->SetTitle("counts");
   // h1_omegaBaryon_MC_1->SetLineColor(kRed);
   // // scale MC
   // h1_omegaBaryon_MC_1->Scale(0.7*h1_omegaBaryon_1->Integral()/h1_omegaBaryon_MC_1->Integral());


   // gStyle->SetOptStat(0);
   // TCanvas* c1 = new TCanvas("c1", "c1", 800, 800);
   // c1->cd();
   // h1_omegaBaryon_0->Draw("hist");
   // h1_omegaBaryon_MC_0->Draw("hist same");
   // // draw legend
   // TLegend *leg0 = new TLegend(0.4,0.2,0.6,0.3);
   // leg0->AddEntry(h1_omegaBaryon_0,"Data","l");
   // leg0->AddEntry(h1_omegaBaryon_MC_0,"Scaled MC","l");
   // leg0->Draw();
   // c1->SaveAs("h1_omegaBaryon_0.pdf");
   
   
   // h1_omegaBaryon_1->Draw("hist");
   // h1_omegaBaryon_MC_1->Draw("hist same");
   // // draw legend
   // TLegend *leg1 = new TLegend(0.4,0.2,0.6,0.3);
   // leg1->AddEntry(h1_omegaBaryon_1,"Data","l");
   // leg1->AddEntry(h1_omegaBaryon_MC_1,"Scaled MC","l");
   // leg1->Draw();
   // c1->SaveAs("h1_omegaBaryon_1.pdf");
   // Plot2DHistWithCuts(FNMCEtaPi0AC[0], NT, "MASS(2,4,5)", "MASS(1,2)", "2DLowPhotonAC0,2DOmegaAC0,etaPrimeSelect0,DeltaCut0", "mass245_mass12_MC",
   //                      150,0.0,3.0, "m_{#gamma2#gamma4#gamma5} (GeV)", 155,0.9,4.00, "m_{p#gamma2} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & #eta' #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMCEtaPi0AC[0], NT, "MASS(3,4,5)", "MASS(1,3)", "2DLowPhotonAC0,2DOmegaAC0,etaPrimeSelect0,DeltaCut0", "mass345_mass13_MC",
   //                      150,0.0,3.0, "m_{#gamma3#gamma4#gamma5} (GeV)", 155,0.9,4.00, "m_{p#gamma3} (GeV)", "Selection: #pi^{0} #rightarrow #gamma_{4}#gamma_{5} & #eta' #rightarrow #gamma_{2}#gamma_{3}",
   //                      kFALSE, 0);

   // PlotOmegaMassWithCutsSkimmed2DEtaPiAC(FNDEtaPi0AC,NT,50,0.6,0.9,"","NoOmegaCut",kTRUE);
   // Plot2DHistWithCuts(FNDEtaPi0AC[0], NT, "MASS(2,4,5)", "cosTheta3GCOMFrame(4;5;2;GLUEXCMS)", "2DLowPhotonAC0,2DOmegaAC0,etaPrimeSelect0,DeltaCut0", "mass245_costheta3GCOM",
   //                      150,0.0,3.0, "m_{#gamma_{2}#gamma_{4}#gamma_{5}} (GeV)", 100,-1.0,1.0, "cos(#theta_{#gamma_{452},CMS})", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMCEtaPi0AC[0], NT, "MASS(2,4,5)", "cosTheta3GCOMFrame(4;5;2;GLUEXCMS)", "2DLowPhotonAC0,2DOmegaAC0,etaPrimeSelect0,DeltaCut0", "mass245_costheta3GCOM_MC",
   //                      150,0.0,3.0, "m_{#gamma_{2}#gamma_{4}#gamma_{5}} (GeV)", 100,-1.0,1.0, "cos(#theta_{#gamma_{452},CMS})", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNDEtaPi0AC[0], NT, "MASS(3,4,5)", "cosTheta3GCOMFrame(4;5;3;GLUEXCMS)", "2DLowPhotonAC0,2DOmegaAC0,etaPrimeSelect0,DeltaCut0", "mass345_costheta3GCOM",
   //                      150,0.0,3.0, "m_{#gamma_{3}#gamma_{4}#gamma_{5}} (GeV)", 100,-1.0,1.0, "cos(#theta_{#gamma_{453},CMS})", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNMCEtaPi0AC[0], NT, "MASS(3,4,5)", "cosTheta3GCOMFrame(4;5;3;GLUEXCMS)", "2DLowPhotonAC0,2DOmegaAC0,etaPrimeSelect0,DeltaCut0", "mass345_costheta3GCOM_MC",
   //                      150,0.0,3.0, "m_{#gamma_{3}#gamma_{4}#gamma_{5}} (GeV)", 100,-1.0,1.0, "cos(#theta_{#gamma_{453},CMS})", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // Plot2DHistWithCuts(FNDEtaPi0AC[0], NT, "MASS(2,4,5)", "cosTheta3GCOMFrame(4;5;2;GLUEXCMS)", "2DLowPhotonAC0,2DOmegaAC0,etaPrimeSelect0,DeltaCut0,OmegaCosThetaCOMCut0", "mass245_costheta3GCOM",
   //                      150,0.0,3.0, "m_{#gamma_{2}#gamma_{4}#gamma_{5}} (GeV)", 100,-1.0,1.0, "cos(#theta_{#gamma_{452},CMS})", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);
   // Plot2DHistWithCuts(FNDEtaPi0AC[0], NT, "MASS(3,4,5)", "cosTheta3GCOMFrame(4;5;3;GLUEXCMS)", "2DLowPhotonAC0,2DOmegaAC0,etaPrimeSelect0,DeltaCut0,OmegaCosThetaCOMCut0", "mass345_costheta3GCOM",
   //                      150,0.0,3.0, "m_{#gamma_{3}#gamma_{4}#gamma_{5}} (GeV)", 100,-1.0,1.0, "cos(#theta_{#gamma_{453},CMS})", "Selection: #eta' #rightarrow #gamma_{2}#gamma_{3} & #pi^{0} #rightarrow #gamma_{4}#gamma_{5}",
   //                      kFALSE, 0);

   // PlotOmegaMassWithCuts(FND,NT,50,0.6,0.9,"allBase","OmegaMomentumCut",kTRUE);
   // PlotOmegaMassWithCutsSkimmed2DEtaPiAC(FNDEtaPi0AC,NT,50,0.6,0.9,"","OmegaCosThetaCOMCut",kTRUE);

   // PlotMass2GammaCombinationSkimmed2DEtaPiAC(FNDEtaPi0AC,NT,40,0.85,1.05,"","etaPrime2DLowPhotonAC2DOmegaAC",kFALSE,kFALSE,kFALSE,kFALSE);
   // PlotMass2GammaCombinationSkimmed2DEtaPiAC(FNDEtaPi0AC,NT,40,0.85,1.05,"","etaPrime2DLowPhotonAC2DOmegaACDeltaCut",kFALSE,kFALSE,kFALSE,kFALSE);
   // PlotMass2GammaCombinationSkimmed2DEtaPiAC(FNDEtaPi0AC,NT,40,0.85,1.05,"","etaPrime2DLowPhotonAC2DOmegaACDeltaCutOmegaCosThetaCOMCut",kFALSE,kFALSE,kFALSE,kFALSE);
   // FSModeHistogram::dumpHistogramCache("histograms/Mass2GammCombination_allBase_2DPiEtaAC_2DLowPhotonAC_2DOmegaAC_DeltaCut_OmegaCosThetaCOMCut_etaPrime");
   
   // PlotMass2GammaCombinationBGGen(FNMCBGGEN,NT,40,0.85,1.05,"allBase","etaPrime",kFALSE,kFALSE,kFALSE,kFALSE);
   // PlotMass2GammaCombinationBGGen(FNMCBGGEN,NT,40,0.85,1.05,"allBase","etaPrime2DPiEtaAC",kFALSE,kFALSE,kFALSE,kFALSE);
   // PlotMass2GammaCombinationBGGenSkimmed2DEtaPiAC(FNMCBGGENEtaPi0AC,NT,40,0.85,1.05,"","etaPrime2DLowPhotonAC2DOmegaAC",kFALSE);
   // PlotMass2GammaCombinationBGGenSkimmed2DEtaPiAC(FNMCBGGENEtaPi0AC,NT,40,0.85,1.05,"","etaPrime2DLowPhotonAC2DOmegaACDeltaCut",kFALSE);
   // PlotMass2GammaCombinationBGGenSkimmed2DEtaPiAC(FNMCBGGENEtaPi0AC,NT,40,0.85,1.05,"","etaPrime2DLowPhotonAC2DOmegaACDeltaCutOmegaCosThetaCOMCut",kFALSE);
   // PlotMass2GammaCombinationBGGenSkimmed2DEtaPiAC(FNMCBGGENEtaPi0AC,NT,40,0.85,1.05,"","etaPrime2DLowPhotonAC2DOmegaACDeltaCutOmegaCosThetaCOMCut",kFALSE);

   // FSModeHistogram::readHistogramCache();
   // PlotMass4Gamma(FND,NT,50,1.0,3.0,"allBase","2DEtaPi0AC",
   //                kFALSE,kFALSE,kTRUE,kTRUE,kFALSE,kTRUE,kFALSE,kFALSE,kFALSE,
   //                kFALSE,kTRUE,FNMC,FNMCGen,"CUT(mcebeam)");
   // vector<TH1F*> v_h1_4GammaMass_2DEtaPi0AC = GetMass4Gamma(FND,NT,50,1.0,3.0,"allBase","2DEtaPi0AC",
   //                   kTRUE,kTRUE,kTRUE,kFALSE,kFALSE,kFALSE,
   //                   kFALSE,kTRUE,FNMC,FNMCGen,"CUT(mcebeam)");

 
   // FSModeHistogram::readHistogramCache();
   // vector<TH1F*> v_h1_4GammaMass_LowPhotonOmegaAC = GetMass4GammaSkimmed2DEtaPiAC(FNDEtaPi0AC,NT,50,1.0,3.0,"","2DEtaPi0LowPhotonOmegaAC",
   //                   kTRUE,kTRUE,kTRUE,kFALSE,kFALSE,kFALSE,
   //                   kFALSE,kTRUE,FNMCEtaPi0AC,FNMCGen,"CUT(mcebeam)");

   // vector<TH1F*> v_h1_4GammaMass_DeltaCut = GetMass4GammaSkimmed2DEtaPiAC(FNDEtaPi0AC,NT,50,1.0,3.0,"","2DEtaPi0LowPhotonOmegaACDeltaCut",
   //                   kTRUE,kTRUE,kTRUE,kTRUE,kFALSE,kFALSE,
   //                   kFALSE,kTRUE,FNMCEtaPi0AC,FNMCGen,"CUT(mcebeam)");

   // vector<TH1F*> v_h1_4GammaMass_OmegaCosThetaCMSCut = GetMass4GammaSkimmed2DEtaPiAC(FNDEtaPi0AC,NT,50,1.0,3.0,"","2DEtaPi0LowPhotonOmegaACDeltaCutOmegaCosThetaCMSCut",
   //                   kTRUE,kTRUE,kTRUE,kTRUE,kFALSE,kTRUE,
   //                   kFALSE,kTRUE,FNMCEtaPi0AC,FNMCGen,"CUT(mcebeam)");

   // TCanvas *c = new TCanvas("c","c",1200,600);
   // c->Divide(2,1);
   // c->cd(1);
   // v_h1_4GammaMass_LowPhotonOmegaAC[0]->SetLineColor(kBlack);
   // v_h1_4GammaMass_DeltaCut[0]->SetLineColor(kRed);
   // v_h1_4GammaMass_OmegaCosThetaCMSCut[0]->SetLineColor(kBlue);
   // v_h1_4GammaMass_LowPhotonOmegaAC[0]->SetMarkerColor(kBlack);
   // v_h1_4GammaMass_DeltaCut[0]->SetMarkerColor(kRed);
   // v_h1_4GammaMass_OmegaCosThetaCMSCut[0]->SetMarkerColor(kBlue);
   // v_h1_4GammaMass_LowPhotonOmegaAC[0]->Draw();
   // v_h1_4GammaMass_DeltaCut[0]->Draw("SAME");
   // v_h1_4GammaMass_OmegaCosThetaCMSCut[0]->Draw("SAME");
   // TLegend *leg0 = new TLegend(0.4,0.2,0.6,0.3);
   // leg0->AddEntry(v_h1_4GammaMass_LowPhotonOmegaAC[0],"X #rightarrow 2#gamma bkg rejection","l");
   // leg0->AddEntry(v_h1_4GammaMass_DeltaCut[0],"+ #Delta cut","l");
   // leg0->AddEntry(v_h1_4GammaMass_OmegaCosThetaCMSCut[0],"+ #omega cos#theta_{CMS} cut","l");
   // leg0->Draw();
   // c->cd(2);
   // v_h1_4GammaMass_LowPhotonOmegaAC[1]->SetLineColor(kBlack);
   // v_h1_4GammaMass_DeltaCut[1]->SetLineColor(kRed);
   // v_h1_4GammaMass_OmegaCosThetaCMSCut[1]->SetLineColor(kBlue);
   // v_h1_4GammaMass_LowPhotonOmegaAC[1]->SetTitle("");
   // v_h1_4GammaMass_LowPhotonOmegaAC[1]->GetXaxis()->SetTitle("m_{4#gamma} [GeV/c^{2}]");
   // v_h1_4GammaMass_LowPhotonOmegaAC[1]->GetYaxis()->SetTitle("Acceptance");
   // v_h1_4GammaMass_LowPhotonOmegaAC[1]->Draw("HIST");
   // v_h1_4GammaMass_DeltaCut[1]->Draw("HIST SAME");
   // v_h1_4GammaMass_OmegaCosThetaCMSCut[1]->Draw("HIST SAME");
   // TLegend *leg1 = new TLegend(0.4,0.2,0.6,0.3);
   // leg1->AddEntry(v_h1_4GammaMass_LowPhotonOmegaAC[1],"X #rightarrow 2#gamma bkg rejection","l");
   // leg1->AddEntry(v_h1_4GammaMass_DeltaCut[1],"+ #Delta cut","l");
   // leg1->AddEntry(v_h1_4GammaMass_OmegaCosThetaCMSCut[1],"+ #omega cos#theta_{CMS} cut","l");
   // leg1->Draw();
   // // FSModeHistogram::dumpHistogramCache();
   // c->SaveAs("mass4Gamma_allCut.pdf");

   // TCanvas *c = new TCanvas("c","c",800,800);
   // TH1F* h_mandelstam_t[6];
   // TH1F* h_mandelstam_t_MC[6];
   // for (Int_t iCombination=0;iCombination<6;iCombination++) {
   //    h_mandelstam_t[iCombination] = Get1DHistWithCuts(FNDEtaPi0AC[iCombination],NT,"MANDELSTAM_T(1)",Form("2DLowPhotonAC%d,2DOmegaAC%d,etaPrimeSelect%d,DeltaCut%d,OmegaCosThetaCOMCut%d",iCombination,iCombination,iCombination,iCombination,iCombination),"", 
   //                                  101,-10.05,0.05,"t [GeV^{2}]","counts","");
   //    h_mandelstam_t_MC[iCombination] = Get1DHistWithCuts(FNMCEtaPi0AC[iCombination],NT,"MANDELSTAM_T(1)",Form("2DLowPhotonAC%d,2DOmegaAC%d,etaPrimeSelect%d,DeltaCut%d,OmegaCosThetaCOMCut%d",iCombination,iCombination,iCombination,iCombination,iCombination),"", 
   //                                  101,-10.05,0.05,"t [GeV^{2}]","counts","");
   // }
   // // sum up all combinations
   // TH1F* h_mandelstam_t_sum = (TH1F*)h_mandelstam_t[0]->Clone("h_mandelstam_t_sum");
   // TH1F* h_mandelstam_t_sum_MC = (TH1F*)h_mandelstam_t_MC[0]->Clone("h_mandelstam_t_sum_MC");
   // for (Int_t iCombination=1;iCombination<6;iCombination++) {
   //    h_mandelstam_t_sum->Add(h_mandelstam_t[iCombination]);
   //    h_mandelstam_t_sum_MC->Add(h_mandelstam_t_MC[iCombination]);
   // }
   // h_mandelstam_t_sum->Draw("HIST");
   // // scale MC
   // h_mandelstam_t_sum_MC->Scale(0.6*h_mandelstam_t_sum->Integral()/h_mandelstam_t_sum_MC->Integral());
   // h_mandelstam_t_sum_MC->SetLineColor(kRed);
   // h_mandelstam_t_sum_MC->Draw("HIST SAME");
   // // draw legend
   // TLegend *leg = new TLegend(0.4,0.2,0.6,0.3);
   // leg->AddEntry(h_mandelstam_t_sum,"Data","l");
   // leg->AddEntry(h_mandelstam_t_sum_MC,"Scaled MC","l");
   // leg->Draw();
   // // draw box from -1.0 to 0.0
   // TBox *box = new TBox(-1.0,0.0,0.0,1.05*h_mandelstam_t_sum->GetMaximum());
   // box->SetFillColor(kGreen);
   // box->SetFillStyle(3002);
   // box->Draw();
   // c->SaveAs("mandelstam_t.pdf");

   // PlotMass2GammaCombinationSkimmed2DEtaPiAC(FNDEtaPi0AC,NT,40,0.85,1.05,"","etaPrime2DLowPhotonAC2DOmegaACDeltaCutOmegaCosThetaCOMCut",kFALSE,kFALSE,kFALSE,kFALSE);
   // PlotMass2GammaCombinationSkimmed2DEtaPiAC(FNDEtaPi0AC,NT,40,0.85,1.05,"t_lt1","etaPrime2DLowPhotonAC2DOmegaACDeltaCutOmegaCosThetaCOMCut",kFALSE,kFALSE,kFALSE,kFALSE);
   // FSModeHistogram::dumpHistogramCache("histograms/Mass2GammCombination_allBase_2DPiEtaAC_2DLowPhotonAC_2DOmegaAC_DeltaCut_OmegaCosThetaCOMCut_tlt1_etaPrime");

   // vector<TH1F*> v_h1_4GammaMass_OmegaCosThetaCMSCut = GetMass4GammaSkimmed2DEtaPiAC(FNDEtaPi0AC,NT,50,1.0,3.0,"","2DEtaPi0LowPhotonOmegaACDeltaCutOmegaCosThetaCMSCut",
   //                   kTRUE,kTRUE,kTRUE,kTRUE,kFALSE,kTRUE,
   //                   kFALSE,kTRUE,FNMCEtaPi0AC,FNMCGen,"CUT(mcebeam)");

   // vector<TH1F*> v_h1_4GammaMass_OmegaCosThetaCMSCut_tlt1 = GetMass4GammaSkimmed2DEtaPiAC(FNDEtaPi0AC,NT,50,1.0,3.0,"t_lt1","2DEtaPi0LowPhotonOmegaACDeltaCutOmegaCosThetaCMSCut",
   //                   kTRUE,kTRUE,kTRUE,kTRUE,kFALSE,kTRUE,
   //                   kFALSE,kTRUE,FNMCEtaPi0AC,FNMCGen,"CUT(mcebeam,mct_lt1)");

   // TCanvas *c = new TCanvas("c","c",1200,600);
   // c->Divide(2,1);
   // c->cd(1);
   // v_h1_4GammaMass_OmegaCosThetaCMSCut[0]->SetLineColor(kBlack);
   // v_h1_4GammaMass_OmegaCosThetaCMSCut_tlt1[0]->SetLineColor(kRed);
   // v_h1_4GammaMass_OmegaCosThetaCMSCut[0]->SetMarkerColor(kBlack);
   // v_h1_4GammaMass_OmegaCosThetaCMSCut_tlt1[0]->SetMarkerColor(kRed);
   // v_h1_4GammaMass_OmegaCosThetaCMSCut[0]->Draw("");
   // v_h1_4GammaMass_OmegaCosThetaCMSCut_tlt1[0]->Draw("SAME");
   // TLegend *leg0 = new TLegend(0.4,0.2,0.6,0.3);
   // leg0->AddEntry(v_h1_4GammaMass_OmegaCosThetaCMSCut[0],"All previous cuts","l");
   // leg0->AddEntry(v_h1_4GammaMass_OmegaCosThetaCMSCut_tlt1[0],"+ |t| < 1 GeV^{2}","l");
   // leg0->Draw();
   // c->cd(2);
   // v_h1_4GammaMass_OmegaCosThetaCMSCut[1]->SetLineColor(kBlack);
   // v_h1_4GammaMass_OmegaCosThetaCMSCut_tlt1[1]->SetLineColor(kRed);
   // v_h1_4GammaMass_OmegaCosThetaCMSCut[1]->SetTitle("");
   // v_h1_4GammaMass_OmegaCosThetaCMSCut[1]->GetXaxis()->SetTitle("m_{4#gamma} [GeV/c^{2}]");
   // v_h1_4GammaMass_OmegaCosThetaCMSCut[1]->GetYaxis()->SetTitle("Acceptance");
   // v_h1_4GammaMass_OmegaCosThetaCMSCut[1]->Draw("HIST");
   // v_h1_4GammaMass_OmegaCosThetaCMSCut_tlt1[1]->Draw("HIST SAME");
   // TLegend *leg1 = new TLegend(0.4,0.2,0.6,0.3);
   // leg1->AddEntry(v_h1_4GammaMass_OmegaCosThetaCMSCut[1],"All previous cuts","l");
   // leg1->AddEntry(v_h1_4GammaMass_OmegaCosThetaCMSCut_tlt1[1],"+ |t| < 1 GeV^{2}","l");
   // leg1->Draw();
   // // FSModeHistogram::dumpHistogramCache();
   // c->SaveAs("mass4Gamma_allCut_tlt1.pdf");

   vector<TH1F*> v_h1_4GammaMass_OmegaCosThetaCMSCut_tlt1 = GetMass4GammaSkimmed2DEtaPiAC(FNDEtaPi0AC,NT,50,1.0,3.0,"t_lt1","2DEtaPi0LowPhotonOmegaACDeltaCutOmegaCosThetaCMSCut",
                     kTRUE,kTRUE,kTRUE,kTRUE,kFALSE,kTRUE,
                     kTRUE,kFALSE,FNMCEtaPi0AC,FNMCGen,"CUT(mcebeam,mct_lt1)");

   FSModeHistogram::dumpHistogramCache("histograms/Mass4Gamma_allBase_2DPiEtaAC_2DLowPhotonAC_2DOmegaAC_DeltaCut_OmegaCosThetaCOMCut_tlt1_etaPrime");

 }


void PlotMass2GammaCombination(TString fileName, TString treeName, Int_t numberOfBin, Double_t xmin, Double_t xmax, TString cutName, TString tag, Bool_t isGamma3Cut = kFALSE, Bool_t isPi0Cut3 = kFALSE, Bool_t isLMACut = kFALSE, Bool_t isSidebandSub = kFALSE){
   Int_t vectorIndexCombination[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   TString binning = Form("(%d,%f,%f)",numberOfBin,xmin,xmax);
   TH1F *h1GammaGammaMass;
   TCanvas *c = new TCanvas("c","c",800,600);
   c->Divide(3,2);
   if (isGamma3Cut) {
      Int_t vectorIndexCombination3[4][3] = {{2,3,4},{2,3,5},{2,4,5},{3,4,5}};
      for (Int_t iCombination3 = 0;iCombination3 < 4; iCombination3++){
         FSCut::defineCut(Form("Gamma3Cut%d",iCombination3),GetCutStringMass3GammaCombination(vectorIndexCombination3[iCombination3][0],vectorIndexCombination3[iCombination3][1],vectorIndexCombination3[iCombination3][2]).Data());
      }
   }
   if (isPi0Cut3) {
      Int_t vectorIndexCombination3[4][3] = {{2,3,4},{2,3,5},{2,4,5},{3,4,5}};
      for (Int_t iCombination3 = 0;iCombination3 < 4; iCombination3++){
         FSCut::defineCut(Form("pi0Cut%d",iCombination3),GetPi0CutStringMass3Combination(vectorIndexCombination3[iCombination3][0],vectorIndexCombination3[iCombination3][1],vectorIndexCombination3[iCombination3][2]).Data());
      }
   }
   for (Int_t iCombination = 0; iCombination < 6; iCombination++){
      c->cd(iCombination+1);
      TString cutString = "CUT(";
      cutString += cutName;
      if (isGamma3Cut) {
         for (Int_t iCombination3 = 0;iCombination3 < 4; iCombination3++){
            cutString += Form(",Gamma3Cut%d",iCombination3);
         }
      }
      if (isPi0Cut3) {
         for (Int_t iCombination3 = 0;iCombination3 < 4; iCombination3++){
            cutString += Form(",pi0Cut%d",iCombination3);
         }
      }
      //select pi0 from alternative 2-gamma
      if (tag==TString("etaPrime") || tag==TString("etaPrimeSSB") || tag==TString("etaPrimeLMAC") || tag==TString("etaPrime2DPiAC") || tag==TString("etaPrime2DPiEtaAC") || tag==TString("etaPrime2DPiEtaACDeltaCut") || tag==TString("etaPrime2DPiEtaACDeltaCutOmegaMomentumCut") || tag==TString("etaPrime2DPiEtaACDeltaCutOmegaCosThetaCOMCut")) {
         Int_t iCombination2 = 5-iCombination;
         FSCut::defineCut(Form("rejectCombination%d",iCombination2),Form("MASS(%d,%d)>0.11&&MASS(%d,%d)<0.17",vectorIndexCombination[iCombination2][0],vectorIndexCombination[iCombination2][1],vectorIndexCombination[iCombination2][0],vectorIndexCombination[iCombination2][1]));
         cutString += Form(",rejectCombination%d",iCombination2);
      }
      if (isLMACut) {
         cutString += Form(",LMAC%d",iCombination);
      }
      if (tag==TString("etaPrime2DPiAC")) {
         cutString += Form(",2DPiAC%d",iCombination);
      }
      if (tag==TString("etaPrime2DPiEtaAC")) {
         cutString += Form(",2DPiAC%d",iCombination);
         cutString += Form(",2DEtaAC%d",iCombination);
      }
      if (tag==TString("etaPrime2DLowPhotonAC")) {
         cutString += Form(",2DLowPhotonAC%d",iCombination);
      }
      if (tag==TString("etaPrime2DLowPhotonAC2DOmegaAC")) {
         cutString += Form(",2DOmegaAC%d",iCombination);
      }
      if (tag==TString("etaPrime2DPiEtaACDeltaCut")) {
         cutString += Form(",2DPiAC%d",iCombination);
         cutString += Form(",2DEtaAC%d",iCombination);
         cutString += Form(",DeltaCut%d",5-iCombination);
      }
      if (tag==TString("etaPrime2DPiEtaACDeltaCutOmegaMomentumCut")){
         cutString += Form(",2DPiAC%d",iCombination);
         cutString += Form(",2DEtaAC%d",iCombination);
         cutString += Form(",DeltaCut%d",5-iCombination);
         cutString += Form(",OmegaMomentumCut%d",iCombination);
      }
      if (tag==TString("etaPrime2DPiEtaACDeltaCutOmegaCosThetaCOMCut")){
         cutString += Form(",2DPiAC%d",iCombination);
         cutString += Form(",2DEtaAC%d",iCombination);
         cutString += Form(",DeltaCut%d",5-iCombination);
         cutString += Form(",OmegaCosThetaCOMCut%d",iCombination);
      }
      cutString += ")";
      if (isSidebandSub && tag==TString("etaPrimeSSB")) {
         cutString += "&&";
         cutString += Form("CUTSUB(etaPrimeSelect%d)",iCombination);
      }
      cout << cutString << endl;
      TH1F* h = FSModeHistogram::getTH1F(fileName,treeName,"",Form("MASS(%d,%d)",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1]),binning,cutString);
      if (iCombination==0) h1GammaGammaMass = (TH1F*)h->Clone();
      else h1GammaGammaMass->Add(h);
      h->SetTitle(Form("#gamma_{%d}#gamma_{%d} invariant mass",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1]));
      h->SetXTitle(Form("m_{\\gamma_{%d}\\gamma_{%d}} [GeV/c^{2}]",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1]));
      h->SetYTitle(Form("Events / %0.2f MeV/c^{2}",(xmax-xmin)/numberOfBin*1000));
      //enlarge axis and label size
      h->GetXaxis()->SetTitleSize(0.05);
      h->GetXaxis()->SetLabelSize(0.05);
      h->GetXaxis()->SetTitleOffset(1.3);
      h->GetYaxis()->SetTitleSize(0.05);
      h->GetYaxis()->SetLabelSize(0.05);
      h->GetYaxis()->SetRangeUser(0,1.2*h->GetMaximum());
      h->GetYaxis()->SetTitleOffset(1.3);
      h->Draw();
   }
   if (isGamma3Cut) {
      for (Int_t iCombination3 = 0;iCombination3 < 4; iCombination3++){
         cutName += Form(",Gamma3Cut%d",iCombination3);
      }
   }
   if (isPi0Cut3) {
      for (Int_t iCombination3 = 0;iCombination3 < 4; iCombination3++){
         cutName += Form(",pi0Cut%d",iCombination3);
      }
   }
   c->SaveAs(Form("Mass2Combination_%s_%s.pdf",cutName.Data(),tag.Data()));
   if (tag==TString("etaPrime") || tag==TString("etaPrimeLMAC") || tag==TString("etaPrime2DPiAC") || tag==TString("etaPrime2DPiEtaAC") || tag==TString("etaPrime2DPiEtaACDeltaCut") || tag==TString("etaPrime2DPiEtaACDeltaCutOmegaMomentumCut") || tag==TString("etaPrime2DPiEtaACDeltaCutOmegaCosThetaCOMCut")){
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

void PlotMass2GammaCombinationSkimmed2DEtaPiAC(TString *fileName, TString treeName, Int_t numberOfBin, Double_t xmin, Double_t xmax, TString cutName, TString tag, Bool_t isGamma3Cut = kFALSE, Bool_t isPi0Cut3 = kFALSE, Bool_t isLMACut = kFALSE, Bool_t isSidebandSub = kFALSE){
   Int_t vectorIndexCombination[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   TString binning = Form("(%d,%f,%f)",numberOfBin,xmin,xmax);
   TH1F *h1GammaGammaMass;
   TCanvas *c = new TCanvas("c","c",800,600);
   c->Divide(3,2);
   if (isGamma3Cut) {
      Int_t vectorIndexCombination3[4][3] = {{2,3,4},{2,3,5},{2,4,5},{3,4,5}};
      for (Int_t iCombination3 = 0;iCombination3 < 4; iCombination3++){
         FSCut::defineCut(Form("Gamma3Cut%d",iCombination3),GetCutStringMass3GammaCombination(vectorIndexCombination3[iCombination3][0],vectorIndexCombination3[iCombination3][1],vectorIndexCombination3[iCombination3][2]).Data());
      }
   }
   if (isPi0Cut3) {
      Int_t vectorIndexCombination3[4][3] = {{2,3,4},{2,3,5},{2,4,5},{3,4,5}};
      for (Int_t iCombination3 = 0;iCombination3 < 4; iCombination3++){
         FSCut::defineCut(Form("pi0Cut%d",iCombination3),GetPi0CutStringMass3Combination(vectorIndexCombination3[iCombination3][0],vectorIndexCombination3[iCombination3][1],vectorIndexCombination3[iCombination3][2]).Data());
      }
   }
   for (Int_t iCombination = 0; iCombination < 6; iCombination++){
      c->cd(iCombination+1);
      TString cutString = "CUT(";
      cutString += cutName;
      if (isGamma3Cut) {
         for (Int_t iCombination3 = 0;iCombination3 < 4; iCombination3++){
            cutString += Form(",Gamma3Cut%d",iCombination3);
         }
      }
      if (isPi0Cut3) {
         for (Int_t iCombination3 = 0;iCombination3 < 4; iCombination3++){
            cutString += Form(",pi0Cut%d",iCombination3);
         }
      }
      //select pi0 from alternative 2-gamma
      if (tag==TString("etaPrime") || tag==TString("etaPrimeSSB") || tag==TString("etaPrimeLMAC") || tag==TString("etaPrime2DLowPhotonAC") || tag==TString("etaPrime2DLowPhotonAC2DOmegaAC") || tag==TString("etaPrime2DLowPhotonAC2DOmegaACDeltaCut") || tag==TString("etaPrime2DLowPhotonAC2DOmegaACDeltaCutOmegaCosThetaCOMCut")) {
         Int_t iCombination2 = 5-iCombination;
         FSCut::defineCut(Form("rejectCombination%d",iCombination2),Form("MASS(%d,%d)>0.11&&MASS(%d,%d)<0.17",vectorIndexCombination[iCombination2][0],vectorIndexCombination[iCombination2][1],vectorIndexCombination[iCombination2][0],vectorIndexCombination[iCombination2][1]));
         cutString += Form(",rejectCombination%d",iCombination2);
      }
      if (isLMACut) {
         cutString += Form(",LMAC%d",iCombination);
      }
      if (tag==TString("etaPrime2DLowPhotonAC")) {
         cutString += Form(",2DLowPhotonAC%d",iCombination);
      }
      if (tag==TString("etaPrime2DLowPhotonAC2DOmegaAC")) {
         cutString += Form(",2DLowPhotonAC%d",iCombination);
         cutString += Form(",2DOmegaAC%d",iCombination);
      }
      if (tag==TString("etaPrime2DLowPhotonAC2DOmegaACDeltaCut")) {
         cutString += Form(",2DLowPhotonAC%d",iCombination);
         cutString += Form(",2DOmegaAC%d",iCombination);
         cutString += Form(",DeltaCut%d",5-iCombination);
      }
      if (tag==TString("etaPrime2DLowPhotonAC2DOmegaACDeltaCutOmegaCosThetaCOMCut")) {
         cutString += Form(",2DLowPhotonAC%d",iCombination);
         cutString += Form(",2DOmegaAC%d",iCombination);
         cutString += Form(",DeltaCut%d",5-iCombination);
         cutString += Form(",OmegaCosThetaCOMCut%d",iCombination);
      }
      cutString += ")";
      if (isSidebandSub) {
         cutString += "&&";
         cutString += Form("CUTSUB(etaPrimeSelect%d)",iCombination);
      }
      cout << cutString << endl;
      TH1F* h = FSModeHistogram::getTH1F(fileName[iCombination],treeName,"",Form("MASS(%d,%d)",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1]),binning,cutString);
      if (iCombination==0) h1GammaGammaMass = (TH1F*)h->Clone();
      else h1GammaGammaMass->Add(h);
      h->SetTitle(Form("#gamma_{%d}#gamma_{%d} invariant mass",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1]));
      h->SetXTitle(Form("m_{\\gamma_{%d}\\gamma_{%d}} [GeV/c^{2}]",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1]));
      h->SetYTitle(Form("Events / %0.2f MeV/c^{2}",(xmax-xmin)/numberOfBin*1000));
      //enlarge axis and label size
      h->GetXaxis()->SetTitleSize(0.05);
      h->GetXaxis()->SetLabelSize(0.05);
      h->GetXaxis()->SetTitleOffset(1.3);
      h->GetYaxis()->SetTitleSize(0.05);
      h->GetYaxis()->SetLabelSize(0.05);
      h->GetYaxis()->SetRangeUser(0,1.2*h->GetMaximum());
      h->GetYaxis()->SetTitleOffset(1.3);
      h->Draw();
   }
   if (isGamma3Cut) {
      for (Int_t iCombination3 = 0;iCombination3 < 4; iCombination3++){
         cutName += Form(",Gamma3Cut%d",iCombination3);
      }
   }
   if (isPi0Cut3) {
      for (Int_t iCombination3 = 0;iCombination3 < 4; iCombination3++){
         cutName += Form(",pi0Cut%d",iCombination3);
      }
   }
   c->SaveAs(Form("Mass2Combination_%s_%s.pdf",cutName.Data(),tag.Data()));
   if (tag==TString("etaPrime") || tag==TString("etaPrimeLMAC") || tag==TString("etaPrime2DLowPhotonAC") || tag==TString("etaPrime2DLowPhotonAC2DOmegaAC") || tag==TString("etaPrime2DLowPhotonAC2DOmegaACDeltaCut") || tag==TString("etaPrime2DLowPhotonAC2DOmegaACDeltaCutOmegaCosThetaCOMCut")){
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

void PlotMass2GammaCombinationBGGen(TString fileName, TString treeName, Int_t numberOfBin, Double_t xmin, Double_t xmax, TString cutName, TString tag, Bool_t isGamma3Cut = kFALSE, Bool_t isPi0Cut3 = kFALSE, Bool_t isLMACut = kFALSE, Bool_t isSidebandSub = kFALSE){
   Int_t vectorIndexCombination[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   TString binning = Form("(%d,%f,%f)",numberOfBin,xmin,xmax);
   TH1F *h1GammaGammaMass;
   TCanvas *c = new TCanvas("c","c",800,600);
   c->Divide(3,2);
   if (isGamma3Cut) {
      Int_t vectorIndexCombination3[4][3] = {{2,3,4},{2,3,5},{2,4,5},{3,4,5}};
      for (Int_t iCombination3 = 0;iCombination3 < 4; iCombination3++){
         FSCut::defineCut(Form("Gamma3Cut%d",iCombination3),GetCutStringMass3GammaCombination(vectorIndexCombination3[iCombination3][0],vectorIndexCombination3[iCombination3][1],vectorIndexCombination3[iCombination3][2]).Data());
      }
   }
   if (isPi0Cut3) {
      Int_t vectorIndexCombination3[4][3] = {{2,3,4},{2,3,5},{2,4,5},{3,4,5}};
      for (Int_t iCombination3 = 0;iCombination3 < 4; iCombination3++){
         FSCut::defineCut(Form("pi0Cut%d",iCombination3),GetPi0CutStringMass3Combination(vectorIndexCombination3[iCombination3][0],vectorIndexCombination3[iCombination3][1],vectorIndexCombination3[iCombination3][2]).Data());
      }
   }

   vector<pair<TString,float>> v_MCComponentSize[6];
   vector<TH1F*> v_hMCComponent[6];
   vector<pair<TString,float>> v_MCComponentSizeTotalCombination;
   vector<TH1F*> v_hMCComponentTotalCombination;

   for (Int_t iCombination = 0; iCombination < 6; iCombination++){
      c->cd(iCombination+1);
      TString cutString = "CUT(";
      cutString += cutName;
      if (isGamma3Cut) {
         for (Int_t iCombination3 = 0;iCombination3 < 4; iCombination3++){
            cutString += Form(",Gamma3Cut%d",iCombination3);
         }
      }
      if (isPi0Cut3) {
         for (Int_t iCombination3 = 0;iCombination3 < 4; iCombination3++){
            cutString += Form(",pi0Cut%d",iCombination3);
         }
      }
      //select pi0 from alternative 2-gamma
      if (tag==TString("etaPrime") || tag==TString("etaPrimeSSB") || tag==TString("etaPrimeLMAC") || tag==TString("etaPrime2DPiAC") || tag==TString("etaPrime2DPiEtaAC") || tag==TString("etaPrime2DPiEtaACDeltaCut") || tag==TString("etaPrime2DPiEtaACDeltaCutOmegaMomentumCut") || tag==TString("etaPrime2DPiEtaACDeltaCutOmegaCosThetaCOMCut")) {
         Int_t iCombination2 = 5-iCombination;
         FSCut::defineCut(Form("rejectCombination%d",iCombination2),Form("MASS(%d,%d)>0.11&&MASS(%d,%d)<0.17",vectorIndexCombination[iCombination2][0],vectorIndexCombination[iCombination2][1],vectorIndexCombination[iCombination2][0],vectorIndexCombination[iCombination2][1]));
         cutString += Form(",rejectCombination%d",iCombination2);
      }
      if (isLMACut) {
         cutString += Form(",LMAC%d",iCombination);
      }
      if (tag==TString("etaPrime2DPiAC")) {
         cutString += Form(",2DPiAC%d",iCombination);
      }
      if (tag==TString("etaPrime2DPiEtaAC")) {
         cutString += Form(",2DPiAC%d",iCombination);
         cutString += Form(",2DEtaAC%d",iCombination);
      }
      if (tag==TString("etaPrime2DPiEtaACDeltaCut")) {
         cutString += Form(",2DPiAC%d",iCombination);
         cutString += Form(",2DEtaAC%d",iCombination);
         cutString += Form(",DeltaCut%d",5-iCombination);
      }
      if (tag==TString("etaPrime2DPiEtaACDeltaCutOmegaMomentumCut")){
         cutString += Form(",2DPiAC%d",iCombination);
         cutString += Form(",2DEtaAC%d",iCombination);
         cutString += Form(",DeltaCut%d",5-iCombination);
         cutString += Form(",OmegaMomentumCut%d",iCombination);
      }
      if (tag==TString("etaPrime2DPiEtaACDeltaCutOmegaCosThetaCOMCut")){
         cutString += Form(",2DPiAC%d",iCombination);
         cutString += Form(",2DEtaAC%d",iCombination);
         cutString += Form(",DeltaCut%d",5-iCombination);
         cutString += Form(",OmegaCosThetaCOMCut%d",iCombination);
      }
      cutString += ")";
      if (isSidebandSub && tag==TString("etaPrimeSSB")) {
         cutString += "&&";
         cutString += Form("CUTSUB(etaPrimeSelect%d)",iCombination);
      }
      //get stacked histograms with MC components and draw it on c
      TH1F *h = FSModeHistogram::drawMCComponents(fileName,treeName,"",Form("MASS(%d,%d)",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1]),binning,cutString,1.0,c,true);
      
      //get MC components and sizes and save it on a vector
      v_MCComponentSize[iCombination] = FSModeHistogram::getMCComponentsAndSizes(fileName,treeName,"",Form("MASS(%d,%d)",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1]),binning,cutString);
      // cout << iCombination << " " << v_MCComponentSize[iCombination].size() << endl;

      //get MC components histogram and save it on a vector
      v_hMCComponent[iCombination] = FSModeHistogram::getMCComponentsTH1F(fileName,treeName,"",Form("MASS(%d,%d)",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1]),binning,cutString);

      if (iCombination==0) h1GammaGammaMass = (TH1F*)h->Clone();
      else h1GammaGammaMass->Add(h);
      h->SetTitle("");
      h->SetXTitle(Form("m_{\\gamma_{%d}\\gamma_{%d}} [GeV/c^{2}]",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1]));
      h->SetYTitle(Form("Events / %0.2f MeV/c^{2}",(xmax-xmin)/numberOfBin*1000));
      // enlarge axis and label size
      h->GetXaxis()->SetTitleSize(0.05);
      h->GetXaxis()->SetTitleOffset(1.3);
      h->GetYaxis()->SetTitleSize(0.05);
      h->GetYaxis()->SetRangeUser(0,1.2*h->GetMaximum());
      h->GetYaxis()->SetTitleOffset(1.3);

      // draw iCombination number for pi0
		TLatex *tex = new TLatex();
		tex->SetNDC();
		tex->SetTextFont(42);
		tex->SetTextSize(0.06);
		tex->SetTextColor(1);
		tex->SetTextAlign(12);
		tex->DrawLatex(0.18,0.85,Form("Selection: #pi^{0} #rightarrow #gamma_{%d}#gamma_{%d}",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1]));
   }
   
   if (isGamma3Cut) {
      for (Int_t iCombination3 = 0;iCombination3 < 4; iCombination3++){
         cutName += Form(",Gamma3Cut%d",iCombination3);
      }
   }
   if (isPi0Cut3) {
      for (Int_t iCombination3 = 0;iCombination3 < 4; iCombination3++){
         cutName += Form(",pi0Cut%d",iCombination3);
      }
   }
   c->SaveAs(Form("Mass2Combination_BGGen_%s_%s.pdf",cutName.Data(),tag.Data()));

   //sum up MC components and sizes based on the component code
   vector<TString> vStringMCComponentCode;
   vector<TH1F*> vTH1FMCComponentCode;
   vector<float> vNEventMCComponentCode;
   vector<int> vIndexMCComponentCode;

   cout << "===================Summing up MC components from all combination===================" << endl;
   for (Int_t iCombination=0;iCombination<6;iCombination++){
      cout << "Combination = " << iCombination+1 << endl;
      for (Int_t iMCComp=0;iMCComp<v_MCComponentSize[iCombination].size();iMCComp++) {
         // cout << iCombination << " " << v_MCComponentSize[iCombination][iMCComp].first << " " << v_MCComponentSize[iCombination][iMCComp].second << endl;
         if (iCombination==0) {
            cout << "Push back:" << " MCCode(" << v_MCComponentSize[iCombination][iMCComp].first << ") " << "NEvent(" << v_MCComponentSize[iCombination][iMCComp].second*(v_hMCComponent[iCombination][iMCComp]->Integral()) << ")" << endl;
            vStringMCComponentCode.push_back(v_MCComponentSize[iCombination][iMCComp].first);
            vNEventMCComponentCode.push_back(v_MCComponentSize[iCombination][iMCComp].second*(v_hMCComponent[iCombination][iMCComp]->Integral()));
            vTH1FMCComponentCode.push_back(v_hMCComponent[iCombination][iMCComp]);
         }
         else{
            //check if the component code is already in the vector
            const int nMCCompCode = vStringMCComponentCode.size();
            cout << "Checking if the component code is already in the vector..." << endl;
            for (Int_t iMCCompCode=0;iMCCompCode<nMCCompCode;iMCCompCode++) {
               cout << iMCCompCode << " Comparing:" << vStringMCComponentCode[iMCCompCode] << ":" << v_MCComponentSize[iCombination][iMCComp].first << endl;
               if (vStringMCComponentCode[iMCCompCode]==v_MCComponentSize[iCombination][iMCComp].first) {
                  cout << "Found, adding:" << " MCCode(" << v_MCComponentSize[iCombination][iMCComp].first << ") " << "NEvent(" << v_MCComponentSize[iCombination][iMCComp].second*(v_hMCComponent[iCombination][iMCComp]->Integral()) << ")" << endl;
                  vNEventMCComponentCode[iMCCompCode] += v_MCComponentSize[iCombination][iMCComp].second*(v_hMCComponent[iCombination][iMCComp]->Integral());
                  vTH1FMCComponentCode[iMCCompCode]->Add(v_hMCComponent[iCombination][iMCComp]);
                  break;
               }
               if (iMCCompCode==nMCCompCode-1) {
                  cout << "Not found, push back:" << " MCCode(" << v_MCComponentSize[iCombination][iMCComp].first << ") " << "NEvent(" << v_MCComponentSize[iCombination][iMCComp].second*(v_hMCComponent[iCombination][iMCComp]->Integral()) << ")" << endl;
                  vStringMCComponentCode.push_back(v_MCComponentSize[iCombination][iMCComp].first);
                  vNEventMCComponentCode.push_back(v_MCComponentSize[iCombination][iMCComp].second*(v_hMCComponent[iCombination][iMCComp]->Integral()));
                  vTH1FMCComponentCode.push_back(v_hMCComponent[iCombination][iMCComp]);
               }
            }
         }
      }
   }

   //Print out the MC components and sizes after sum up
   cout << endl << "===================MC components after summing up===================" << endl;
   for (Int_t iMCCompCode=0;iMCCompCode<vStringMCComponentCode.size();iMCCompCode++) {
      cout << iMCCompCode << " " << vStringMCComponentCode[iMCCompCode] << " " << FSModeHistogram::formatMCComponent(vStringMCComponentCode[iMCCompCode],vNEventMCComponentCode[iMCCompCode]/vTH1FMCComponentCode[iMCCompCode]->Integral()) << endl;
   }
   
   //draw th1f inside vector and save it on a pdf file
   for (Int_t i=0;i<vTH1FMCComponentCode.size();i++){
      c->Clear();
      c->Divide(1,1);
      vTH1FMCComponentCode[i]->SetTitle(Form("Total combination invariant mass (%s)",cutName.Data()));
      vTH1FMCComponentCode[i]->SetXTitle("m_{\\gamma\\gamma} [GeV/c^{2}]");
      vTH1FMCComponentCode[i]->SetYTitle(Form("Events / %0.2f MeV/c^{2}",(xmax-xmin)/numberOfBin*1000));
      vTH1FMCComponentCode[i]->Draw();
      c->SaveAs(Form("Mass2Combination_BGGen_Total_%s_%s_%s.pdf",cutName.Data(),tag.Data(),vStringMCComponentCode[i].Data()));
   }

   // draw stacked histograms with MC components
   c->Clear();
   THStack *hs = new THStack("hs","hs");
   TLegend *legend = new TLegend(0.7,0.5,1.0,1.0);
   cout << endl << "Stacking histograms..." << endl;
   for (Int_t iMCCompCode=vStringMCComponentCode.size()-1;iMCCompCode>=0;iMCCompCode--) {
      TH1F *hdraw = vTH1FMCComponentCode[iMCCompCode];
      if (iMCCompCode!=0) hdraw->SetFillColor(iMCCompCode+1);
      hdraw->SetLineColor(iMCCompCode+1);
      hs->Add(hdraw,"hist");
      cout << iMCCompCode << " " << FSModeHistogram::formatMCComponent(vStringMCComponentCode[iMCCompCode],vNEventMCComponentCode[iMCCompCode]/vTH1FMCComponentCode[iMCCompCode]->Integral()) << endl;
      TString legendString(FSModeHistogram::formatMCComponent(vStringMCComponentCode[iMCCompCode],vNEventMCComponentCode[iMCCompCode]/vTH1FMCComponentCode[iMCCompCode]->Integral()));
      legendString = FSModeString::rootSymbols(legendString);
      legend->AddEntry(hdraw,legendString.Data(),"f");
   }
   c->Clear();
   c->Divide(1,1);
   c->SetWindowSize(800,800);
   h1GammaGammaMass->SetTitle("Sum of all combination");
   h1GammaGammaMass->SetXTitle("m_{\\gamma\\gamma} [GeV/c^{2}]");
   h1GammaGammaMass->SetYTitle(Form("Events / %0.2f MeV/c^{2}",(xmax-xmin)/numberOfBin*1000));
   h1GammaGammaMass->GetYaxis()->SetRangeUser(0,1.2*h1GammaGammaMass->GetMaximum());
   h1GammaGammaMass->Draw();
   if ((vTH1FMCComponentCode.size()!=0) && (tag==TString("etaPrime") || tag==TString("etaPrimeLMAC") || tag==TString("etaPrime2DPiAC") || tag==TString("etaPrime2DPiEtaAC") || tag==TString("etaPrime2DPiEtaACDeltaCut") || tag==TString("etaPrime2DPiEtaACDeltaCutOmegaMomentumCut") || tag==TString("etaPrime2DPiEtaACDeltaCutOmegaCosThetaCOMCut"))){
      hs->Draw("same");
      legend->Draw("same");
      h1GammaGammaMass->Draw("same");
      c->RedrawAxis();
      c->SaveAs(Form("Mass2Combination_Total_BGGen_%s_%s.pdf",cutName.Data(),tag.Data()));
   }
   
   delete c;
}

void PlotMass2GammaCombinationBGGenSkimmed2DEtaPiAC(TString *fileName, TString treeName, Int_t numberOfBin, Double_t xmin, Double_t xmax, TString cutName, TString tag, Bool_t isSidebandSub = kFALSE){
   Int_t vectorIndexCombination[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   TString binning = Form("(%d,%f,%f)",numberOfBin,xmin,xmax);
   TH1F *h1GammaGammaMass;
   TCanvas *c = new TCanvas("c","c",800,800);
   c->Divide(3,2);

   vector<pair<TString,float>> v_MCComponentSize[6];
   vector<TH1F*> v_hMCComponent[6];
   vector<pair<TString,float>> v_MCComponentSizeTotalCombination;
   vector<TH1F*> v_hMCComponentTotalCombination;

   for (Int_t iCombination = 0; iCombination < 6; iCombination++){
      c->cd(iCombination+1);
      TString cutString = "CUT(";
      cutString += cutName;

      //select pi0 from alternative 2-gamma
      if (tag==TString("etaPrime") || tag==TString("etaPrimeSSB") || tag==TString("etaPrimeLMAC") || tag==TString("etaPrime2DLowPhotonAC") || tag==TString("etaPrime2DLowPhotonAC2DOmegaAC") || tag==TString("etaPrime2DLowPhotonAC2DOmegaACDeltaCut") || tag==TString("etaPrime2DLowPhotonAC2DOmegaACDeltaCutOmegaCosThetaCOMCut")) {
         Int_t iCombination2 = 5-iCombination;
         FSCut::defineCut(Form("rejectCombination%d",iCombination2),Form("MASS(%d,%d)>0.11&&MASS(%d,%d)<0.17",vectorIndexCombination[iCombination2][0],vectorIndexCombination[iCombination2][1],vectorIndexCombination[iCombination2][0],vectorIndexCombination[iCombination2][1]));
         cutString += Form(",rejectCombination%d",iCombination2);
      }
      if (tag==TString("etaPrime2DLowPhotonAC")) {
         cutString += Form(",2DLowPhotonAC%d",iCombination);
      }
      if (tag==TString("etaPrime2DLowPhotonAC2DOmegaAC")) {
         cutString += Form(",2DLowPhotonAC%d",iCombination);
         cutString += Form(",2DOmegaAC%d",iCombination);
      }
      if (tag==TString("etaPrime2DLowPhotonAC2DOmegaACDeltaCut")) {
         cutString += Form(",2DLowPhotonAC%d",iCombination);
         cutString += Form(",2DOmegaAC%d",iCombination);
         cutString += Form(",DeltaCut%d",5-iCombination);
      }
      if (tag==TString("etaPrime2DLowPhotonAC2DOmegaACDeltaCutOmegaCosThetaCOMCut")) {
         cutString += Form(",2DLowPhotonAC%d",iCombination);
         cutString += Form(",2DOmegaAC%d",iCombination);
         cutString += Form(",DeltaCut%d",5-iCombination);
         cutString += Form(",OmegaCosThetaCOMCut%d",iCombination);
      }
      cutString += ")";
      if (isSidebandSub) {
         cutString += "&&";
         cutString += Form("CUTSUB(etaPrimeSelect%d)",iCombination);
      }
      //get stacked histograms with MC components and draw it on c
      TH1F *h = FSModeHistogram::drawMCComponents(fileName[iCombination],treeName,"",Form("MASS(%d,%d)",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1]),binning,cutString,1.0,c,true);
      
      //get MC components and sizes and save it on a vector
      v_MCComponentSize[iCombination] = FSModeHistogram::getMCComponentsAndSizes(fileName[iCombination],treeName,"",Form("MASS(%d,%d)",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1]),binning,cutString);
      // cout << iCombination << " " << v_MCComponentSize[iCombination].size() << endl;

      //get MC components histogram and save it on a vector
      v_hMCComponent[iCombination] = FSModeHistogram::getMCComponentsTH1F(fileName[iCombination],treeName,"",Form("MASS(%d,%d)",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1]),binning,cutString);

      if (iCombination==0) h1GammaGammaMass = (TH1F*)h->Clone();
      else h1GammaGammaMass->Add(h);
      h->SetTitle(Form("Mass(%d,%d) %s",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],cutName.Data()));
      h->SetXTitle(Form("m_{\\gamma_{%d}\\gamma_{%d}} [GeV/c^{2}]",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1]));
      h->SetYTitle(Form("Events / %0.2f MeV/c^{2}",(xmax-xmin)/numberOfBin*1000));
   }
   c->SaveAs(Form("Mass2Combination_BGGen_%s_%s.pdf",cutName.Data(),tag.Data()));

   //sum up MC components and sizes based on the component code
   vector<TString> vStringMCComponentCode;
   vector<TH1F*> vTH1FMCComponentCode;
   vector<float> vNEventMCComponentCode;
   vector<int> vIndexMCComponentCode;

   cout << "===================Summing up MC components from all combination===================" << endl;
   for (Int_t iCombination=0;iCombination<6;iCombination++){
      cout << "Combination = " << iCombination+1 << endl;
      for (Int_t iMCComp=0;iMCComp<v_MCComponentSize[iCombination].size();iMCComp++) {
         // cout << iCombination << " " << v_MCComponentSize[iCombination][iMCComp].first << " " << v_MCComponentSize[iCombination][iMCComp].second << endl;
         // check if v_MCComponentSize[iCombination][iMCComp].second exists
         
         if (v_MCComponentSize[iCombination][iMCComp].second<=0.001) continue;
         if (iCombination==0) {
            cout << "Push back:" << " MCCode(" << v_MCComponentSize[iCombination][iMCComp].first << ") " << "NEvent(" << v_MCComponentSize[iCombination][iMCComp].second*(v_hMCComponent[iCombination][iMCComp]->Integral()) << ")" << endl;
            vStringMCComponentCode.push_back(v_MCComponentSize[iCombination][iMCComp].first);
            vNEventMCComponentCode.push_back(v_MCComponentSize[iCombination][iMCComp].second*(v_hMCComponent[iCombination][iMCComp]->Integral()));
            vTH1FMCComponentCode.push_back(v_hMCComponent[iCombination][iMCComp]);
         }
         else{
            //check if the component code is already in the vector
            const int nMCCompCode = vStringMCComponentCode.size();
            cout << "Checking if the component code is already in the vector..." << endl;
            for (Int_t iMCCompCode=0;iMCCompCode<nMCCompCode;iMCCompCode++) {
               cout << iMCCompCode << " Comparing:" << vStringMCComponentCode[iMCCompCode] << ":" << v_MCComponentSize[iCombination][iMCComp].first << endl;
               if (vStringMCComponentCode[iMCCompCode]==v_MCComponentSize[iCombination][iMCComp].first) {
                  cout << "Found, adding:" << " MCCode(" << v_MCComponentSize[iCombination][iMCComp].first << ") " << "NEvent(" << v_MCComponentSize[iCombination][iMCComp].second*(v_hMCComponent[iCombination][iMCComp]->Integral()) << ")" << endl;
                  vNEventMCComponentCode[iMCCompCode] += v_MCComponentSize[iCombination][iMCComp].second*(v_hMCComponent[iCombination][iMCComp]->Integral());
                  vTH1FMCComponentCode[iMCCompCode]->Add(v_hMCComponent[iCombination][iMCComp]);
                  break;
               }
               if (iMCCompCode==nMCCompCode-1) {
                  cout << "Not found, push back:" << " MCCode(" << v_MCComponentSize[iCombination][iMCComp].first << ") " << "NEvent(" << v_MCComponentSize[iCombination][iMCComp].second*(v_hMCComponent[iCombination][iMCComp]->Integral()) << ")" << endl;
                  vStringMCComponentCode.push_back(v_MCComponentSize[iCombination][iMCComp].first);
                  vNEventMCComponentCode.push_back(v_MCComponentSize[iCombination][iMCComp].second*(v_hMCComponent[iCombination][iMCComp]->Integral()));
                  vTH1FMCComponentCode.push_back(v_hMCComponent[iCombination][iMCComp]);
               }
            }
         }
      }
   }

   //Print out the MC components and sizes after sum up
   cout << endl << "===================MC components after summing up===================" << endl;
   for (Int_t iMCCompCode=0;iMCCompCode<vStringMCComponentCode.size();iMCCompCode++) {
      cout << iMCCompCode << " " << vStringMCComponentCode[iMCCompCode] << " " << FSModeHistogram::formatMCComponent(vStringMCComponentCode[iMCCompCode],vNEventMCComponentCode[iMCCompCode]/vTH1FMCComponentCode[iMCCompCode]->Integral()) << endl;
   }
   
   //draw th1f inside vector and save it on a pdf file
   for (Int_t i=0;i<vTH1FMCComponentCode.size();i++){
      c->Clear();
      c->Divide(1,1);
      vTH1FMCComponentCode[i]->SetTitle(Form("Total combination invariant mass (%s)",cutName.Data()));
      vTH1FMCComponentCode[i]->SetXTitle("m_{\\gamma\\gamma} [GeV/c^{2}]");
      vTH1FMCComponentCode[i]->SetYTitle(Form("Events / %0.2f MeV/c^{2}",(xmax-xmin)/numberOfBin*1000));
      vTH1FMCComponentCode[i]->Draw();
      c->SaveAs(Form("Mass2Combination_BGGen_Total_%s_%s_%s.pdf",cutName.Data(),tag.Data(),vStringMCComponentCode[i].Data()));
   }

   // draw stacked histograms with MC components
   c->Clear();
   THStack *hs = new THStack("hs","hs");
   TLegend *legend = new TLegend(0.7,0.5,1.0,1.0);
   cout << endl << "Stacking histograms..." << endl;
   for (Int_t iMCCompCode=vStringMCComponentCode.size()-1;iMCCompCode>=0;iMCCompCode--) {
      TH1F *hdraw = vTH1FMCComponentCode[iMCCompCode];
      if (iMCCompCode!=0) hdraw->SetFillColor(iMCCompCode+1);
      hdraw->SetLineColor(iMCCompCode+1);
      hs->Add(hdraw,"hist");
      cout << iMCCompCode << " " << FSModeHistogram::formatMCComponent(vStringMCComponentCode[iMCCompCode],vNEventMCComponentCode[iMCCompCode]/vTH1FMCComponentCode[iMCCompCode]->Integral()) << endl;
      TString legendString(FSModeHistogram::formatMCComponent(vStringMCComponentCode[iMCCompCode],vNEventMCComponentCode[iMCCompCode]/vTH1FMCComponentCode[iMCCompCode]->Integral()));
      legendString = FSModeString::rootSymbols(legendString);
      legend->AddEntry(hdraw,legendString.Data(),"f");
   }
   c->Clear();
   c->Divide(1,1);
   h1GammaGammaMass->SetTitle("");
   h1GammaGammaMass->SetXTitle("m_{\\gamma\\gamma} [GeV/c^{2}]");
   h1GammaGammaMass->SetYTitle(Form("Events / %0.2f MeV/c^{2}",(xmax-xmin)/numberOfBin*1000));
   h1GammaGammaMass->GetYaxis()->SetRangeUser(1.2*h1GammaGammaMass->GetMinimum(),1.2*h1GammaGammaMass->GetMaximum());
   h1GammaGammaMass->Draw();
   if ((vTH1FMCComponentCode.size()!=0) && (tag==TString("etaPrime") || tag==TString("etaPrimeSSB") || tag==TString("etaPrimeLMAC") || tag==TString("etaPrime2DLowPhotonAC") || tag==TString("etaPrime2DLowPhotonAC2DOmegaAC") || tag==TString("etaPrime2DLowPhotonAC2DOmegaACDeltaCut") || tag==TString("etaPrime2DLowPhotonAC2DOmegaACDeltaCutOmegaCosThetaCOMCut"))){
      hs->Draw("same");
      legend->Draw("same");
      h1GammaGammaMass->Draw("same");
      c->RedrawAxis();
      // draw box for signal region
		Double_t etaPrimeMass = 0.956;
   	Double_t etaSigma = 0.013;
   	Double_t signalRegion[2] = {etaPrimeMass-(3*etaSigma),etaPrimeMass+(3*etaSigma)};
   	Double_t leftSidebandRegion[2] = {etaPrimeMass-(7*etaSigma),etaPrimeMass-(4*etaSigma)};
   	Double_t rightSidebandRegion[2] = {etaPrimeMass+(4*etaSigma),etaPrimeMass+(7*etaSigma)};
		TBox *box = new TBox(signalRegion[0],0,signalRegion[1],h1GammaGammaMass->GetMaximum());
		box->SetFillColor(4);
		box->SetFillStyle(3002);
		box->Draw();

		// draw box for sidebands region
		TBox *boxLSB = new TBox(leftSidebandRegion[0],0,leftSidebandRegion[1],h1GammaGammaMass->GetMaximum());
		boxLSB->SetFillColor(2);
		boxLSB->SetFillStyle(3002);
		boxLSB->Draw();

		TBox *boxRSB = new TBox(rightSidebandRegion[0],0,rightSidebandRegion[1],h1GammaGammaMass->GetMaximum());
		boxRSB->SetFillColor(2);
		boxRSB->SetFillStyle(3002);
		boxRSB->Draw();
      c->SaveAs(Form("Mass2Combination_Total_BGGen_%s_%s.pdf",cutName.Data(),tag.Data()));
   }
   
   delete c;
}

void PlotMass3GammaCombination(TString fileName, TString treeName, Int_t numberOfBin, Double_t xmin, Double_t xmax, TString cutName, TString tag, Bool_t isGamma3Cut = kFALSE, Bool_t isPi0Cut3 = kFALSE, Bool_t isSidebandSub = kFALSE){
   Int_t vectorIndexCombination[4][3] = {{2,3,4},{2,3,5},{2,4,5},{3,4,5}};
   TString binning = Form("(%d,%f,%f)",numberOfBin,xmin,xmax);
   TCanvas *c = new TCanvas("c","c",800,600);
   c->Divide(2,2);
   for (Int_t iCombination = 0; iCombination < 4; iCombination++){
      c->cd(iCombination+1);
      TString cutString = "CUT(";
      cutString += cutName;
      if (isGamma3Cut) {
         FSCut::defineCut("Gamma3Cut",GetCutStringMass3GammaCombination(vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[iCombination][2]).Data());
         cutString += ",Gamma3Cut";
      }
      if (isPi0Cut3) {
         FSCut::defineCut("pi0Cut3",GetPi0CutStringMass3Combination(vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[iCombination][2]).Data());
         cutString += ",pi0Cut3";
      }
      cutString += ")";
      if (isSidebandSub) {
         cutString += "&&";
         cutString += "CUTSUB(etaPrimeSelect0)";
         // study first combination
      }
      cout << cutString << endl;
      TH1F* h = FSModeHistogram::getTH1F(fileName,treeName,"",Form("MASS(%d,%d,%d)",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[iCombination][2]),binning,cutString);
      h->SetTitle(Form("Mass(%d,%d,%d) %s",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[iCombination][2],cutName.Data()));
      h->SetXTitle(Form("m_{\\gamma_{%d}\\gamma_{%d}\\gamma_{%d}} [GeV/c^{2}]",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[iCombination][2]));
      h->SetYTitle(Form("Events / %0.2f MeV/c^{2}",(xmax-xmin)/numberOfBin*1000));
      h->Draw();
   }
   if (isGamma3Cut) cutName += "_Gamma3Cut";
   if (isPi0Cut3) cutName += "_pi0Cut3";
   c->SaveAs(Form("Mass3Combination_%s_%s.pdf",cutName.Data(),tag.Data()));
   delete c;
}

void PlotMass4Gamma(TString fileName, TString treeName, Int_t numberOfBin, Double_t xmin, Double_t xmax, TString cutName, TString tag,
                     Bool_t isGamma3Cut = kFALSE, Bool_t isPi0Cut3 = kFALSE, Bool_t isPi0Select = kFALSE, Bool_t isEtaPrimeSelect = kFALSE, Bool_t isLMACut = kFALSE, Bool_t is2DEtaPi0Cut = kFALSE, Bool_t isDeltaCut = kFALSE, Bool_t isOmegaMomentumCut = kFALSE, Bool_t isOmegaCosThetaCOMCut = kFALSE,
                     Bool_t isSidebandSub = kFALSE, Bool_t isIncludeMC = kFALSE, TString fileNameMC = "", TString fileNameMCThrown = "", TString mcThrownCutName = "")
{
   Int_t vectorIndexCombination[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   TString binning = Form("(%d,%f,%f)",numberOfBin,xmin,xmax);
   TString binningGJCosTheta = Form("(%d,%f,%f,%d,%f,%f)",numberOfBin,xmin,xmax,50,-1.0,1.0);
   TCanvas *c = new TCanvas("c","c",800,600);
   TH1F *h1_4GammaMass;
   TH1F *h1_4GammaMassMC;
   TH2F *h2MC_m_CosThetaGJTotal;
   
   c->Divide(3,2);
   if (isGamma3Cut) {
      Int_t vectorIndexCombination3[4][3] = {{2,3,4},{2,3,5},{2,4,5},{3,4,5}};
      for (Int_t iCombination3 = 0;iCombination3 < 4; iCombination3++){
         FSCut::defineCut(Form("Gamma3Cut%d",iCombination3),GetCutStringMass3GammaCombination(vectorIndexCombination3[iCombination3][0],vectorIndexCombination3[iCombination3][1],vectorIndexCombination3[iCombination3][2]).Data());
      }
   }
   if (isPi0Cut3) {
      Int_t vectorIndexCombination3[4][3] = {{2,3,4},{2,3,5},{2,4,5},{3,4,5}};
      for (Int_t iCombination3 = 0;iCombination3 < 4; iCombination3++){
         FSCut::defineCut(Form("pi0Cut%d",iCombination3),GetPi0CutStringMass3Combination(vectorIndexCombination3[iCombination3][0],vectorIndexCombination3[iCombination3][1],vectorIndexCombination3[iCombination3][2]).Data());
      }
   }
   for (Int_t iCombination = 0;iCombination < 6; iCombination++){
      c->cd(iCombination+1);
      TString cutString = "CUT(";
      cutString += cutName;
      if (isGamma3Cut) {
         for (Int_t iCombination3 = 0;iCombination3 < 4; iCombination3++){
            cutString += Form(",Gamma3Cut%d",iCombination3);
         }
      }
      if (isPi0Cut3) {
         for (Int_t iCombination3 = 0;iCombination3 < 4; iCombination3++){
            cutString += Form(",pi0Cut%d",iCombination3);
         }
      }
      if (isPi0Select) {
         Int_t iCombination2 = 5-iCombination;
         // FSCut::defineCut(Form("pi0Select%d",iCombination2),Form("MASS(%d,%d)>0.11&&MASS(%d,%d)<0.16",vectorIndexCombination[iCombination2][0],vectorIndexCombination[iCombination2][1],vectorIndexCombination[iCombination2][0],vectorIndexCombination[iCombination2][1]));
         cutString += Form(",pi0Select%d",iCombination2);
      }
      if (isEtaPrimeSelect && !isSidebandSub) {
         // FSCut::defineCut(Form("etaPrimeSelect%d",iCombination),Form("MASS(%d,%d)>0.93&&MASS(%d,%d)<0.99",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1]));
         cutString += Form(",etaPrimeSelect%d",iCombination);
      }
      if (isLMACut) {
         cutString += Form(",LMAC%d",iCombination);
      }
      if (is2DEtaPi0Cut) {
         cutString += Form(",2DEtaAC%d",iCombination);
         cutString += Form(",2DPiAC%d",iCombination);
      }
      if (isDeltaCut) {
         cutString += Form(",DeltaCut%d",5-iCombination);
      }
      if (isOmegaMomentumCut) {
         cutString += Form(",OmegaMomentumCut%d",iCombination);
      }
      if (isOmegaCosThetaCOMCut) {
         cutString += Form(",OmegaCosThetaCOMCut%d",iCombination);
      }
      cutString += ")";
      if (isEtaPrimeSelect && isSidebandSub) {
         cutString += "&&";
         cutString += Form("CUTSUB(etaPrimeSelect%d)",iCombination);
      }
      cout << "Gamma index combination: " << vectorIndexCombination[iCombination][0] << vectorIndexCombination[iCombination][1] << vectorIndexCombination[5-iCombination][0] << vectorIndexCombination[5-iCombination][1] << endl;
      cout << cutString << endl;
      TH1F* h = FSModeHistogram::getTH1F(fileName,treeName,"",Form("MASS(%d,%d,%d,%d)",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[5-iCombination][0],vectorIndexCombination[5-iCombination][1]),binning,cutString);
      // h->SetTitle(Form("Selection: \\eta' #rightarrow \\gamma_{%d}\\gamma_{%d} & \\pi^{0} #rightarrow \\gamma_{%d}\\gamma_{%d}",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[5-iCombination][0],vectorIndexCombination[5-iCombination][1]));
      h->SetTitle("");
      h->SetXTitle(Form("m_{\\gamma_{%d}\\gamma_{%d}\\gamma_{%d}\\gamma_{%d}} [GeV/c^{2}]",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[5-iCombination][0],vectorIndexCombination[5-iCombination][1]));
      h->SetYTitle(Form("Events / %0.2f MeV/c^{2}",(xmax-xmin)/numberOfBin*1000));
      h->Draw();
      TLatex *tex = new TLatex();
		tex->SetNDC();
		tex->SetTextFont(42);
		tex->SetTextSize(0.04);
		tex->SetTextColor(1);
		tex->SetTextAlign(12);
		tex->DrawLatex(0.3,0.85,Form("Selection: #eta' #rightarrow #gamma_{%d}#gamma_{%d} & #pi^{0} #rightarrow #gamma_{%d}#gamma_{%d}",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[5-iCombination][0],vectorIndexCombination[5-iCombination][1]));
      if (isIncludeMC) {
         TH1F* hMC = FSModeHistogram::getTH1F(fileNameMC,treeName,"",Form("MASS(%d,%d,%d,%d)",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[5-iCombination][0],vectorIndexCombination[5-iCombination][1]),binning,cutString);
         TH2F* h2MC_m_CosThetaGJ = FSModeHistogram::getTH2F(fileNameMC,treeName,"",Form("GJCOSTHETA(%d,%d;%d,%d;B):MASS(%d,%d,%d,%d)",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[5-iCombination][0],vectorIndexCombination[5-iCombination][1],vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[5-iCombination][0],vectorIndexCombination[5-iCombination][1]),binningGJCosTheta,cutString);
         // hMC->SetLineColor(kRed);
         // hMC->SetLineWidth(2);
         // hMC->Draw("HIST SAME");
         if (iCombination == 0) {
            h1_4GammaMassMC = (TH1F*)hMC->Clone("h1_4GammaMassMC");
            h2MC_m_CosThetaGJTotal = (TH2F*)h2MC_m_CosThetaGJ->Clone("h2MC_m_CosThetaGJTotal");
         }
         else {
            h1_4GammaMassMC->Add(hMC);
            h2MC_m_CosThetaGJTotal->Add(h2MC_m_CosThetaGJ);
         }   
      }
      if (iCombination == 0) h1_4GammaMass = (TH1F*)h->Clone("h1_4GammaMass");
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
   c->SetWindowSize(400,800);
   h1_4GammaMass->SetTitle("Total 4#gamma invariant mass");
   h1_4GammaMass->SetXTitle("m_{4#gamma} [GeV/c^{2}]");
   h1_4GammaMass->SetYTitle(Form("Events / %0.2f MeV/c^{2}",(xmax-xmin)/numberOfBin*1000));
   h1_4GammaMass->SetMinimum(0);
   h1_4GammaMass->Draw();
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
      Float_t rightmax = 0.3;
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
      axis_acc->SetLabelSize(0.03);
      axis_acc->SetLabelFont(42);
      axis_acc->SetTitleFont(42);
      axis_acc->Draw();
      // leg->AddEntry(h1_4GammaMassMC,Form("MC (scale = %0.2f)",MCScale),"l");
      leg->AddEntry(h1_acceptance,"Acceptance","l");
   }
   leg->Draw();
   c->SaveAs(Form("Mass4GammaTotal_%s_%s.pdf",cutName.Data(),tag.Data()));
   if (isIncludeMC) {
      TH2F* h2_m_CosThetaGJMCThrown = FSModeHistogram::getTH2F(fileNameMCThrown,NT,"","MCGJCOSTHETA(2,5;3,4;B):MCMASS(2,3,4,5)",binningGJCosTheta,mcThrownCutName);
      TH2F* h2_m_CosThetaGJAcceptance = (TH2F*)h2MC_m_CosThetaGJTotal->Clone("h2_m_CosThetaGJMCAcceptance");
      h2_m_CosThetaGJAcceptance->Divide(h2_m_CosThetaGJMCThrown);
      h2_m_CosThetaGJAcceptance->SetTitle("Acceptance");
      h2_m_CosThetaGJAcceptance->SetXTitle("m_{4#gamma} [GeV/c^{2}]");
      h2_m_CosThetaGJAcceptance->SetYTitle("cos#theta_{GJ}");
      h2_m_CosThetaGJAcceptance->Draw("COLZ");
      c->SaveAs(Form("Mass4Gamma_CosThetaGJ_Acceptance_%s_%s.pdf",cutName.Data(),tag.Data()));
   }
   delete c;
}

vector<TH1F*> GetMass4Gamma(TString fileName, TString treeName, Int_t numberOfBin, Double_t xmin, Double_t xmax, TString cutName, TString tag,
                     Bool_t isPi0Select = kFALSE, Bool_t isEtaPrimeSelect = kFALSE, Bool_t is2DEtaPi0Cut = kFALSE, Bool_t isDeltaCut = kFALSE, Bool_t isOmegaMomentumCut = kFALSE, Bool_t isOmegaCosThetaCOMCut = kFALSE,
                     Bool_t isSidebandSub = kFALSE, Bool_t isIncludeMC = kFALSE, TString fileNameMC = "", TString fileNameMCThrown = "", TString mcThrownCutName = "")
{
   Int_t vectorIndexCombination[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   TString binning = Form("(%d,%f,%f)",numberOfBin,xmin,xmax);
   TString binningGJCosTheta = Form("(%d,%f,%f,%d,%f,%f)",numberOfBin,xmin,xmax,50,-1.0,1.0);
   TCanvas *c = new TCanvas("c","c",800,600);
   TCanvas *c2 = new TCanvas("c2","c2",800,800);
   TH1F *h1_4GammaMass;
   TH1F *h1_4GammaMassMC;
   TH2F *h2MC_m_CosThetaGJTotal;

   vector<TH1F*> v_h1_4GammaMass;
   
   c->Divide(3,2);
   for (Int_t iCombination = 0;iCombination < 6; iCombination++){
      c->cd(iCombination+1);
      TString cutString = "CUT(";
      cutString += cutName;
      if (isPi0Select) {
         Int_t iCombination2 = 5-iCombination;
         // FSCut::defineCut(Form("pi0Select%d",iCombination2),Form("MASS(%d,%d)>0.11&&MASS(%d,%d)<0.16",vectorIndexCombination[iCombination2][0],vectorIndexCombination[iCombination2][1],vectorIndexCombination[iCombination2][0],vectorIndexCombination[iCombination2][1]));
         cutString += Form(",pi0Select%d",iCombination2);
      }
      if (isEtaPrimeSelect && !isSidebandSub) {
         // FSCut::defineCut(Form("etaPrimeSelect%d",iCombination),Form("MASS(%d,%d)>0.93&&MASS(%d,%d)<0.99",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1]));
         cutString += Form(",etaPrimeSelect%d",iCombination);
      }
      if (is2DEtaPi0Cut) {
         cutString += Form(",2DEtaAC%d",iCombination);
         cutString += Form(",2DPiAC%d",iCombination);
      }
      if (isDeltaCut) {
         cutString += Form(",DeltaCut%d",5-iCombination);
      }
      if (isOmegaMomentumCut) {
         cutString += Form(",OmegaMomentumCut%d",iCombination);
      }
      if (isOmegaCosThetaCOMCut) {
         cutString += Form(",OmegaCosThetaCOMCut%d",iCombination);
      }
      cutString += ")";
      if (isEtaPrimeSelect && isSidebandSub) {
         cutString += "&&";
         cutString += Form("CUTSUB(etaPrimeSelect%d)",iCombination);
      }
      cout << "Gamma index combination: " << vectorIndexCombination[iCombination][0] << vectorIndexCombination[iCombination][1] << vectorIndexCombination[5-iCombination][0] << vectorIndexCombination[5-iCombination][1] << endl;
      cout << cutString << endl;
      TH1F* h = FSModeHistogram::getTH1F(fileName,treeName,"",Form("MASS(%d,%d,%d,%d)",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[5-iCombination][0],vectorIndexCombination[5-iCombination][1]),binning,cutString);
      // h->SetTitle(Form("Selection: \\eta' #rightarrow \\gamma_{%d}\\gamma_{%d} & \\pi^{0} #rightarrow \\gamma_{%d}\\gamma_{%d}",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[5-iCombination][0],vectorIndexCombination[5-iCombination][1]));
      h->SetTitle("");
      h->SetXTitle(Form("m_{\\gamma_{%d}\\gamma_{%d}\\gamma_{%d}\\gamma_{%d}} [GeV/c^{2}]",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[5-iCombination][0],vectorIndexCombination[5-iCombination][1]));
      h->SetYTitle(Form("Events / %0.2f MeV/c^{2}",(xmax-xmin)/numberOfBin*1000));
      h->Draw();
      TLatex *tex = new TLatex();
		tex->SetNDC();
		tex->SetTextFont(42);
		tex->SetTextSize(0.04);
		tex->SetTextColor(1);
		tex->SetTextAlign(12);
		tex->DrawLatex(0.3,0.85,Form("Selection: #eta' #rightarrow #gamma_{%d}#gamma_{%d} & #pi^{0} #rightarrow #gamma_{%d}#gamma_{%d}",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[5-iCombination][0],vectorIndexCombination[5-iCombination][1]));
      if (isIncludeMC) {
         TH1F* hMC = FSModeHistogram::getTH1F(fileNameMC,treeName,"",Form("MASS(%d,%d,%d,%d)",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[5-iCombination][0],vectorIndexCombination[5-iCombination][1]),binning,cutString);
         TH2F* h2MC_m_CosThetaGJ = FSModeHistogram::getTH2F(fileNameMC,treeName,"",Form("GJCOSTHETA(%d,%d;%d,%d;B):MASS(%d,%d,%d,%d)",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[5-iCombination][0],vectorIndexCombination[5-iCombination][1],vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[5-iCombination][0],vectorIndexCombination[5-iCombination][1]),binningGJCosTheta,cutString);
         // hMC->SetLineColor(kRed);
         // hMC->SetLineWidth(2);
         // hMC->Draw("HIST SAME");
         if (iCombination == 0) {
            h1_4GammaMassMC = (TH1F*)hMC->Clone("h1_4GammaMassMC");
            h2MC_m_CosThetaGJTotal = (TH2F*)h2MC_m_CosThetaGJ->Clone("h2MC_m_CosThetaGJTotal");
         }
         else {
            h1_4GammaMassMC->Add(hMC);
            h2MC_m_CosThetaGJTotal->Add(h2MC_m_CosThetaGJ);
         }   
      }
      if (iCombination == 0) h1_4GammaMass = new TH1F(*h);
      else h1_4GammaMass->Add(h);
   }
   if (isPi0Select) cutName += "_pi0Select";
   if (isEtaPrimeSelect) cutName += "_etaPrimeSelect";
   c->SaveAs(Form("Mass4Gamma_%s_%s.pdf",cutName.Data(),tag.Data()));
   c->Clear();
   c->Divide(1,1);
   c->cd(1);
   c->SetWindowSize(400,800);
   h1_4GammaMass->SetTitle("Total 4#gamma invariant mass");
   h1_4GammaMass->SetXTitle("m_{4#gamma} [GeV/c^{2}]");
   h1_4GammaMass->SetYTitle(Form("Events / %0.2f MeV/c^{2}",(xmax-xmin)/numberOfBin*1000));
   h1_4GammaMass->SetMinimum(0);
   h1_4GammaMass->Draw();
   v_h1_4GammaMass.push_back(h1_4GammaMass);
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
      TH1F* h1_acceptance = new TH1F(*h1_4GammaMassMC);
      h1_acceptance->Divide(h1_MCthrown);
      h1_acceptance->SetLineColor(kBlue);
      h1_acceptance->SetLineWidth(2);
      v_h1_4GammaMass.push_back(h1_acceptance);
      Float_t rightmax = 0.3;
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
      axis_acc->SetLabelSize(0.03);
      axis_acc->SetLabelFont(42);
      axis_acc->SetTitleFont(42);
      axis_acc->Draw();
      // leg->AddEntry(h1_4GammaMassMC,Form("MC (scale = %0.2f)",MCScale),"l");
      leg->AddEntry(h1_acceptance,"Acceptance","l");
   }
   leg->Draw();
   c->SaveAs(Form("Mass4GammaTotal_%s_%s.pdf",cutName.Data(),tag.Data()));
   if (isIncludeMC) {
      TH2F* h2_m_CosThetaGJMCThrown = FSModeHistogram::getTH2F(fileNameMCThrown,NT,"","MCGJCOSTHETA(2,5;3,4;B):MCMASS(2,3,4,5)",binningGJCosTheta,mcThrownCutName);
      TH2F* h2_m_CosThetaGJAcceptance = (TH2F*)h2MC_m_CosThetaGJTotal->Clone("h2_m_CosThetaGJMCAcceptance");
      h2_m_CosThetaGJAcceptance->Divide(h2_m_CosThetaGJMCThrown);
      h2_m_CosThetaGJAcceptance->SetTitle("Acceptance");
      h2_m_CosThetaGJAcceptance->SetXTitle("m_{4#gamma} [GeV/c^{2}]");
      h2_m_CosThetaGJAcceptance->SetYTitle("cos#theta_{GJ}");
      h2_m_CosThetaGJAcceptance->Draw("COLZ");
      c->SaveAs(Form("Mass4Gamma_CosThetaGJ_Acceptance_%s_%s.pdf",cutName.Data(),tag.Data()));
   }
   delete c;
   return v_h1_4GammaMass;
}

vector<TH1F*> GetMass4GammaSkimmed2DEtaPiAC(TString *fileName, TString treeName, Int_t numberOfBin, Double_t xmin, Double_t xmax, TString cutName, TString tag,
                     Bool_t isPi0Select, Bool_t isEtaPrimeSelect, Bool_t is2DLowPhotonOmegaAC, Bool_t isDeltaCut, Bool_t isOmegaMomentumCut, Bool_t isOmegaCosThetaCOMCut,
                     Bool_t isSidebandSub, Bool_t isIncludeMC, TString *fileNameMC, TString fileNameMCThrown, TString mcThrownCutName)
{
   Int_t vectorIndexCombination[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   TString binning = Form("(%d,%f,%f)",numberOfBin,xmin,xmax);
   TString binningGJCosTheta = Form("(%d,%f,%f,%d,%f,%f)",numberOfBin,xmin,xmax,50,-1.0,1.0);
   TCanvas *c = new TCanvas("c","c",800,600);
   TCanvas *c2 = new TCanvas("c2","c2",800,600);
   TH1F *h1_4GammaMass;
   TH1F *h1_4GammaMassMC;
   TH2F *h2_m_CosThetaGJTotal;
   TH2F *h2MC_m_CosThetaGJTotal;

   vector<TH1F*> v_h1_4GammaMass;
   
   c->Divide(3,2);
   c2->Divide(3,2);
   for (Int_t iCombination = 0;iCombination < 6; iCombination++){
      c->cd(iCombination+1);
      TString cutString = "CUT(";
      cutString += cutName;
      if (isPi0Select) {
         Int_t iCombination2 = 5-iCombination;
         // FSCut::defineCut(Form("pi0Select%d",iCombination2),Form("MASS(%d,%d)>0.11&&MASS(%d,%d)<0.16",vectorIndexCombination[iCombination2][0],vectorIndexCombination[iCombination2][1],vectorIndexCombination[iCombination2][0],vectorIndexCombination[iCombination2][1]));
         cutString += Form(",pi0Select%d",iCombination2);
      }
      if (isEtaPrimeSelect && !isSidebandSub) {
         // FSCut::defineCut(Form("etaPrimeSelect%d",iCombination),Form("MASS(%d,%d)>0.93&&MASS(%d,%d)<0.99",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1]));
         cutString += Form(",etaPrimeSelect%d",iCombination);
      }
      if (is2DLowPhotonOmegaAC) {
         cutString += Form(",2DLowPhotonAC%d",iCombination);
         cutString += Form(",2DOmegaAC%d",iCombination);
      }
      if (isDeltaCut) {
         cutString += Form(",DeltaCut%d",5-iCombination);
      }
      if (isOmegaMomentumCut) {
         cutString += Form(",OmegaMomentumCut%d",iCombination);
      }
      if (isOmegaCosThetaCOMCut) {
         cutString += Form(",OmegaCosThetaCOMCut%d",iCombination);
      }
      cutString += ")";
      if (isEtaPrimeSelect && isSidebandSub) {
         cutString += "&&";
         cutString += Form("CUTSUB(etaPrimeSelect%d)",iCombination);
      }
      cout << "Gamma index combination: " << vectorIndexCombination[iCombination][0] << vectorIndexCombination[iCombination][1] << vectorIndexCombination[5-iCombination][0] << vectorIndexCombination[5-iCombination][1] << endl;
      cout << cutString << endl;
      TH1F* h = FSModeHistogram::getTH1F(fileName[iCombination],treeName,"",Form("MASS(%d,%d,%d,%d)",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[5-iCombination][0],vectorIndexCombination[5-iCombination][1]),binning,cutString);
      // h->SetTitle(Form("Selection: \\eta' #rightarrow \\gamma_{%d}\\gamma_{%d} & \\pi^{0} #rightarrow \\gamma_{%d}\\gamma_{%d}",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[5-iCombination][0],vectorIndexCombination[5-iCombination][1]));
      h->SetTitle("");
      h->SetXTitle(Form("m_{\\gamma_{%d}\\gamma_{%d}\\gamma_{%d}\\gamma_{%d}} [GeV/c^{2}]",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[5-iCombination][0],vectorIndexCombination[5-iCombination][1]));
      h->SetYTitle(Form("Events / %0.2f MeV/c^{2}",(xmax-xmin)/numberOfBin*1000));
      h->Draw();
      TLatex *tex = new TLatex();
		tex->SetNDC();
		tex->SetTextFont(42);
		tex->SetTextSize(0.04);
		tex->SetTextColor(1);
		tex->SetTextAlign(12);
		tex->DrawLatex(0.3,0.85,Form("Selection: #eta' #rightarrow #gamma_{%d}#gamma_{%d} & #pi^{0} #rightarrow #gamma_{%d}#gamma_{%d}",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[5-iCombination][0],vectorIndexCombination[5-iCombination][1]));
      TH2F *h2;
      if (!isSidebandSub){
         h2 = FSModeHistogram::getTH2F(fileName[iCombination],treeName,"",Form("GJCOSTHETA(%d,%d;%d,%d;B):MASS(%d,%d,%d,%d)",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[5-iCombination][0],vectorIndexCombination[5-iCombination][1],vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[5-iCombination][0],vectorIndexCombination[5-iCombination][1]),binningGJCosTheta,cutString);
         h2->SetTitle("");
         h2->SetXTitle(Form("m_{\\gamma_{%d}\\gamma_{%d}\\gamma_{%d}\\gamma_{%d}} [GeV/c^{2}]",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[5-iCombination][0],vectorIndexCombination[5-iCombination][1]));
         h2->SetYTitle("cos#theta_{GJ}");
         c2->cd(iCombination+1);
         h2->Draw("COLZ");
         h2->SetTitle(Form("Selection: #eta' #rightarrow #gamma_{%d}#gamma_{%d} & #pi^{0} #rightarrow #gamma_{%d}#gamma_{%d}",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[5-iCombination][0],vectorIndexCombination[5-iCombination][1]));
      }
      if (isIncludeMC && !isSidebandSub) {
         TH1F* hMC = FSModeHistogram::getTH1F(fileNameMC[iCombination],treeName,"",Form("MASS(%d,%d,%d,%d)",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[5-iCombination][0],vectorIndexCombination[5-iCombination][1]),binning,cutString);
         TH2F* h2MC_m_CosThetaGJ = FSModeHistogram::getTH2F(fileNameMC[iCombination],treeName,"",Form("GJCOSTHETA(%d,%d;%d,%d;B):MASS(%d,%d,%d,%d)",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[5-iCombination][0],vectorIndexCombination[5-iCombination][1],vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[5-iCombination][0],vectorIndexCombination[5-iCombination][1]),binningGJCosTheta,cutString);
         // hMC->SetLineColor(kRed);
         // hMC->SetLineWidth(2);
         // hMC->Draw("HIST SAME");
         if (iCombination == 0) {
            h1_4GammaMassMC = (TH1F*)hMC->Clone("h1_4GammaMassMC");
            h2MC_m_CosThetaGJTotal = (TH2F*)h2MC_m_CosThetaGJ->Clone("h2MC_m_CosThetaGJTotal");
         }
         else {
            h1_4GammaMassMC->Add(hMC);
            h2MC_m_CosThetaGJTotal->Add(h2MC_m_CosThetaGJ);
         }   
      }
      if (iCombination == 0) {
         h1_4GammaMass = new TH1F(*h);
         if (!isSidebandSub) h2_m_CosThetaGJTotal = new TH2F(*h2);
      }
      else {
         h1_4GammaMass->Add(h);
         if (!isSidebandSub) h2_m_CosThetaGJTotal->Add(h2);
      }
   }
   if (isPi0Select) cutName += "_pi0Select";
   if (isEtaPrimeSelect) cutName += "_etaPrimeSelect";
   c->SaveAs(Form("Mass4Gamma_%s_%s.pdf",cutName.Data(),tag.Data()));
   c->Clear();
   c->Divide(1,1);
   c->cd(1);
   c->SetWindowSize(400,800);
   h1_4GammaMass->SetTitle("Total 4#gamma invariant mass");
   h1_4GammaMass->SetXTitle("m_{4#gamma} [GeV/c^{2}]");
   h1_4GammaMass->SetYTitle(Form("Events / %0.2f MeV/c^{2}",(xmax-xmin)/numberOfBin*1000));
   h1_4GammaMass->SetMinimum(0);
   h1_4GammaMass->Draw();
   v_h1_4GammaMass.push_back(h1_4GammaMass);
   if (!isSidebandSub) {
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
         TH1F* h1_acceptance = new TH1F(*h1_4GammaMassMC);
         h1_acceptance->Divide(h1_MCthrown);
         TH1F* h1_acceptance_unscaled = new TH1F(*h1_acceptance); 
         v_h1_4GammaMass.push_back(h1_acceptance_unscaled);
         h1_acceptance->SetLineColor(kBlue);
         h1_acceptance->SetLineWidth(2);
         Float_t rightmax = 0.3;
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
         axis_acc->SetLabelSize(0.03);
         axis_acc->SetLabelFont(42);
         axis_acc->SetTitleFont(42);
         axis_acc->Draw();
         // leg->AddEntry(h1_4GammaMassMC,Form("MC (scale = %0.2f)",MCScale),"l");
         leg->AddEntry(h1_acceptance,"Acceptance","l");
      }
      leg->Draw();
   }
   c->SaveAs(Form("Mass4GammaTotal_%s_%s.pdf",cutName.Data(),tag.Data()));
   if (!isSidebandSub) {
      if (isIncludeMC) {
         TH2F* h2_m_CosThetaGJMCThrown = FSModeHistogram::getTH2F(fileNameMCThrown,NT,"","MCGJCOSTHETA(2,5;3,4;B):MCMASS(2,3,4,5)",binningGJCosTheta,mcThrownCutName);
         TH2F* h2_m_CosThetaGJAcceptance = (TH2F*)h2MC_m_CosThetaGJTotal->Clone("h2_m_CosThetaGJMCAcceptance");
         h2_m_CosThetaGJAcceptance->Divide(h2_m_CosThetaGJMCThrown);
         h2_m_CosThetaGJAcceptance->SetTitle("Acceptance");
         h2_m_CosThetaGJAcceptance->SetXTitle("m_{4#gamma} [GeV/c^{2}]");
         h2_m_CosThetaGJAcceptance->SetYTitle("cos#theta_{GJ}");
         c->SetWindowSize(400,800);
         h2_m_CosThetaGJAcceptance->Draw("COLZ");
         c->SaveAs(Form("Mass4Gamma_CosThetaGJ_Acceptance_%s_%s.pdf",cutName.Data(),tag.Data()));
      }
      c2->SaveAs(Form("Mass4Gamma_CosThetaGJ_%s_%s.pdf",cutName.Data(),tag.Data()));
      c2->Clear();
      c2->Divide(1,1);
      c2->cd(1);
      c2->SetWindowSize(400,800);
      h2_m_CosThetaGJTotal->SetTitle("Total cos#theta_{GJ} vs. 4#gamma invariant mass");
      h2_m_CosThetaGJTotal->SetXTitle("m_{4#gamma} [GeV/c^{2}]");
      h2_m_CosThetaGJTotal->SetYTitle("cos#theta_{GJ}");
      h2_m_CosThetaGJTotal->Draw("COLZ");
      c2->SaveAs(Form("Mass4Gamma_CosThetaGJ_Total_%s_%s.pdf",cutName.Data(),tag.Data()));
   }
   delete c;
   delete c2;
   return v_h1_4GammaMass;
}

// TString GetCutStringMass3GammaCombination(Int_t vectorIndex1,Int_t vectorIndex2,Int_t vectorIndex3){
//    TString cutString = Form("MASS(%d,%d,%d)<2.4",vectorIndex1,vectorIndex2,vectorIndex3,vectorIndex1,vectorIndex2,vectorIndex3,vectorIndex1,vectorIndex2,vectorIndex3);
//    return cutString;
// }

// with omega 3gamma cuts
TString GetCutStringMass3GammaCombination(Int_t vectorIndex1,Int_t vectorIndex2,Int_t vectorIndex3){
   Double_t omegaMass = 0.78265;
   Double_t omegaMassWindow = 0.05;
   Double_t omegaMomentum = 7.6;
   Double_t omegaMomentumWindow = 0.8;
   TString cutString = Form("!((MASS(%d,%d,%d)>%f&&MASS(%d,%d,%d)<%f)&&(MOMENTUM(%d,%d,%d)>%f&&MOMENTUM(%d,%d,%d)<%f))",vectorIndex1,vectorIndex2,vectorIndex3,omegaMass-omegaMassWindow,vectorIndex1,vectorIndex2,vectorIndex3,omegaMass+omegaMassWindow,vectorIndex1,vectorIndex2,vectorIndex3,omegaMomentum-omegaMomentumWindow,vectorIndex1,vectorIndex2,vectorIndex3,omegaMomentum+omegaMomentumWindow);
   return cutString;
}

// TString GetCutStringMass3GammaCombination(Int_t vectorIndex1,Int_t vectorIndex2,Int_t vectorIndex3){
//    TString cutString = Form("MASS(%d,%d,%d)>0.9",vectorIndex1,vectorIndex2,vectorIndex3);
//    return cutString;
// }

TString GetPi0CutStringMass3Combination(Int_t vectorIndex1,Int_t vectorIndex2,Int_t vectorIndex3){
   TString cutString = Form("MASS(%d,%d,%d)<0.11 || MASS(%d,%d,%d)>0.17",vectorIndex1,vectorIndex2,vectorIndex3,vectorIndex1,vectorIndex2,vectorIndex3);
   return cutString;
}

//plot custom 1D histogram with cuts
void Plot1DHistWithCuts(TString fileName, TString treeName, TString varName, TString cutName, TString tag, 
                        Int_t numberOfXBin, Double_t xmin, Double_t xmax, TString xTitle, TString yTitle, TString title,
                        Bool_t isEnableCombination, Bool_t isCanvasDivide, Int_t numberOfXPad, Int_t numberOfYPad,
                        Bool_t isGamma3Cut = kFALSE, Bool_t isPi0Cut3 = kFALSE, Bool_t isPi0Select = kFALSE, Bool_t isEtaPrimeSelect = kFALSE){
      
   TString binning = Form("(%d,%f,%f)",numberOfXBin,xmin,xmax);
   TCanvas* c = new TCanvas("c","c",800,800);
   if (isCanvasDivide) c->Divide(numberOfXPad,numberOfYPad);
   if (isEnableCombination){
      Int_t vectorIndexCombination[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
      for (Int_t iCombination=0;iCombination<6;iCombination++){
         //build cut string
         TString cutString = "CUT(";
         cutString += cutName;
         if (isGamma3Cut) {
            for (Int_t iCombination3 = 0;iCombination3 < 4; iCombination3++){
               cutString += Form(",Gamma3Cut%d",iCombination3);
            }
         }
         if (isPi0Select) {
            Int_t iCombination2 = 5-iCombination;
            cutString += Form(",pi0Select%d",iCombination2);
         }
         if (isEtaPrimeSelect) {
            cutString += Form(",etaPrimeSelect%d",iCombination);
         }
         cutString += ")";
         cout << cutString << endl;
         //plot histogram
         TH1F* h = FSModeHistogram::getTH1F(fileName,treeName,"",Form("%s(%d,%d,%d,%d)",varName.Data(),vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[5-iCombination][0],vectorIndexCombination[5-iCombination][1]),binning,cutString);
         if (isCanvasDivide) c->cd(iCombination+1);
         h->SetTitle(Form("%s(%d,%d,%d,%d)",title.Data(),vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[5-iCombination][0],vectorIndexCombination[5-iCombination][1]));
         h->SetXTitle(xTitle.Data());
         h->SetYTitle(yTitle.Data());
         h->Sumw2();
         h->Draw();
      }
   }
   else{
      TString cutString = "CUT(";
      cutString += cutName;
      for (Int_t iCombination=0;iCombination<6;iCombination++){
         if (isGamma3Cut) {
            for (Int_t iCombination3 = 0;iCombination3 < 4; iCombination3++){
               cutString += Form(",Gamma3Cut%d",iCombination3);
            }
         }
         if (isPi0Select) {
            Int_t iCombination2 = 5-iCombination;
            cutString += Form(",pi0Select%d",iCombination2);
         }
         if (isEtaPrimeSelect) {
            cutString += Form(",etaPrimeSelect%d",iCombination);
         }
      }
      cutString += ")";
      cout << cutString << endl;
      // cout << binning << endl;
      TH1F* h = FSModeHistogram::getTH1F(fileName,treeName,"",varName,binning,cutString);
      h->SetTitle(title.Data());
      h->SetXTitle(xTitle.Data());
      h->SetYTitle(yTitle.Data());
      // h->Sumw2();
      h->Draw("HIST");
   }
   if (isEnableCombination) c->SaveAs(Form("%s_%s_%s_combinationTrue.pdf",varName.Data(),cutName.Data(),tag.Data()));
   else c->SaveAs(Form("%s_%s_%s_combinationFalse.pdf",varName.Data(),cutName.Data(),tag.Data()));
   delete c;
}

TH1F* Get1DHistWithCuts(TString fileName, TString treeName, TString varName, TString cutName, TString tag, 
                        Int_t numberOfXBin, Double_t xmin, Double_t xmax, TString xTitle, TString yTitle, TString title){
      
   TString binning = Form("(%d,%f,%f)",numberOfXBin,xmin,xmax);
   TString cutString = "CUT(";
   cutString += cutName; 
   cutString += ")";
   cout << cutString << endl;
   // cout << binning << endl;
   TH1F* h = FSModeHistogram::getTH1F(fileName,treeName,"",varName,binning,cutString);
   h->SetTitle(title.Data());
   h->SetXTitle(xTitle.Data());
   h->SetYTitle(yTitle.Data());
   // h->Sumw2();

   return h;
}

//plot custom 2D histogram with cuts
void Plot2DHistWithCuts(TString fileName, TString treeName, TString varNameX, TString varNameY, TString cutName, TString tag, 
                        Int_t numberOfXBin, Double_t xmin, Double_t xmax, TString xTitle, Int_t numberOfYBin, Double_t ymin, Double_t ymax, TString yTitle, TString title,
                        Bool_t isSidebandSub, Int_t etaPrimeSelectNumber){
   
   TString binning = Form("(%d,%f,%f,%d,%f,%f)",numberOfXBin,xmin,xmax,numberOfYBin,ymin,ymax);
   TCanvas* c = new TCanvas("c","c",800,800);   
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
   Int_t vectorIndexCombination3[4][3] = {{2,3,4},{2,3,5},{2,4,5},{3,4,5}};
   for (Int_t iCombination3 = 0;iCombination3 < 4; iCombination3++){
      FSCut::defineCut(Form("Gamma3Cut%d",iCombination3),GetCutStringMass3GammaCombination(vectorIndexCombination3[iCombination3][0],vectorIndexCombination3[iCombination3][1],vectorIndexCombination3[iCombination3][2]).Data());
   }
}

void DefinePi0SelectCuts(){
   Int_t vectorIndexCombination[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   for (Int_t iCombination2 = 5;iCombination2 >= 0; iCombination2--){
      FSCut::defineCut(Form("pi0Select%d",iCombination2),Form("MASS(%d,%d)>0.11&&MASS(%d,%d)<0.16",vectorIndexCombination[iCombination2][0],vectorIndexCombination[iCombination2][1],vectorIndexCombination[iCombination2][0],vectorIndexCombination[iCombination2][1]));
   }
}

void DefineEtaPrimeSelectCuts(){
   Bool_t isSidebandSub = kTRUE;
   Int_t vectorIndexCombination[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   //use values from the fit
   Double_t etaPrimeMass = 0.956;
   Double_t etaSigma = 0.013;
   Double_t signalRegion[2] = {etaPrimeMass-(3*etaSigma),etaPrimeMass+(3*etaSigma)};
   Double_t leftSidebandRegion[2] = {etaPrimeMass-(7*etaSigma),etaPrimeMass-(4*etaSigma)};
   Double_t rightSidebandRegion[2] = {etaPrimeMass+(4*etaSigma),etaPrimeMass+(7*etaSigma)};
   Double_t weightSideband = (signalRegion[1]-signalRegion[0])/((rightSidebandRegion[1]-rightSidebandRegion[0])+(leftSidebandRegion[1]-leftSidebandRegion[0]));
   for (Int_t iCombination = 0;iCombination < 6; iCombination++) {
      TString SelectMassString = Form("MASS(%d,%d)>%f&&MASS(%d,%d)<%f",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],signalRegion[0],vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],signalRegion[1]);
      if (!isSidebandSub) FSCut::defineCut(Form("etaPrimeSelect%d",iCombination),SelectMassString.Data());
      else {
         TString SelectMassSBString = Form("(MASS(%d,%d)>%f&&MASS(%d,%d)<%f)",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],leftSidebandRegion[0],vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],leftSidebandRegion[1]);
         SelectMassSBString += "||";
         SelectMassSBString += Form("(MASS(%d,%d)>%f&&MASS(%d,%d)<%f)",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],rightSidebandRegion[0],vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],rightSidebandRegion[1]);
         // cout << SelectMassString << ", " << SelectMassSBString << endl;
         FSCut::defineCut(Form("etaPrimeSelect%d",iCombination),SelectMassString.Data(),SelectMassSBString.Data(),weightSideband);
      }
   }
}

void DefineLMACuts(){
   Int_t vectorIndexCombination[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   for (Int_t iCombination = 0;iCombination < 6; iCombination++) {
      Int_t iCut1 = iCombination+1;
      Int_t iCutt1 = iCombination+2;
      if (iCombination <= 2){
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
      // cout << "LMAC" << iCombination << " = " << vectorIndexCombination[iCombination][0] << "," << vectorIndexCombination[iCombination][1] << ":" << vectorIndexCombination[5-iCombination][0] << "," << vectorIndexCombination[5-iCombination][1] << " cuts on " << vectorIndexCombination[iCut1][0] << "," << vectorIndexCombination[iCut1][1] << ":" << vectorIndexCombination[iCut2][0] << "," << vectorIndexCombination[iCut2][1] << "  &  " << vectorIndexCombination[iCutt1][0] << "," << vectorIndexCombination[iCutt1][1] << ":" << vectorIndexCombination[iCutt2][0] << "," << vectorIndexCombination[iCutt2][1] << endl;
      // TString CutString =  Form("(MASS(%d,%d)<0.15&&MASS(%d,%d)<0.15)",vectorIndexCombination[iCut1][0],vectorIndexCombination[iCut1][1],vectorIndexCombination[iCut2][0],vectorIndexCombination[iCut2][1]);
      TString CutString =  Form("(MASS(%d,%d)>0.17&&MASS(%d,%d)>0.17)&&(MASS(%d,%d)>0.17&&MASS(%d,%d)>0.17)",vectorIndexCombination[iCut1][0],vectorIndexCombination[iCut1][1],vectorIndexCombination[iCut2][0],vectorIndexCombination[iCut2][1],vectorIndexCombination[iCutt1][0],vectorIndexCombination[iCutt1][1],vectorIndexCombination[iCutt2][0],vectorIndexCombination[iCutt2][1]);
      FSCut::defineCut(Form("LMAC%d",iCombination),CutString.Data());
   }
}

void Define2DAlternativePi0Cuts(){
   Int_t vectorIndexCombination[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   for (Int_t iCombination = 0;iCombination < 6; iCombination++) {
      Int_t iCut1 = iCombination+1;
      Int_t iCutt1 = iCombination+2;
      if (iCombination <= 2){
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
      cout << "2DPiAC" << iCombination << " = " << vectorIndexCombination[iCombination][0] << "," << vectorIndexCombination[iCombination][1] << ":" << vectorIndexCombination[5-iCombination][0] << "," << vectorIndexCombination[5-iCombination][1] << " cuts on " << vectorIndexCombination[iCut1][0] << "," << vectorIndexCombination[iCut1][1] << ":" << vectorIndexCombination[iCut2][0] << "," << vectorIndexCombination[iCut2][1] << "  &  " << vectorIndexCombination[iCutt1][0] << "," << vectorIndexCombination[iCutt1][1] << ":" << vectorIndexCombination[iCutt2][0] << "," << vectorIndexCombination[iCutt2][1] << endl;
      TString CutString =  Form("!((MASS(%d,%d)<0.17&&MASS(%d,%d)<0.17)&&(MASS(%d,%d)>0.11&&MASS(%d,%d)>0.11))",vectorIndexCombination[iCut1][0],vectorIndexCombination[iCut1][1],vectorIndexCombination[iCut2][0],vectorIndexCombination[iCut2][1],vectorIndexCombination[iCut1][0],vectorIndexCombination[iCut1][1],vectorIndexCombination[iCut2][0],vectorIndexCombination[iCut2][1]);
      CutString +=  Form("&&!((MASS(%d,%d)<0.17&&MASS(%d,%d)<0.17)&&(MASS(%d,%d)>0.11&&MASS(%d,%d)>0.11))",vectorIndexCombination[iCutt1][0],vectorIndexCombination[iCutt1][1],vectorIndexCombination[iCutt2][0],vectorIndexCombination[iCutt2][1],vectorIndexCombination[iCutt1][0],vectorIndexCombination[iCutt1][1],vectorIndexCombination[iCutt2][0],vectorIndexCombination[iCutt2][1]);
      // TString CutString =  Form("!((MASS(%d,%d)<0.17&&MASS(%d,%d)<0.17)&&(MASS(%d,%d)<0.17&&MASS(%d,%d)<0.17)&&(MASS(%d,%d)>0.11&&MASS(%d,%d)>0.11)&&(MASS(%d,%d)>0.11&&MASS(%d,%d)>0.11))",vectorIndexCombination[iCut1][0],vectorIndexCombination[iCut1][1],vectorIndexCombination[iCut2][0],vectorIndexCombination[iCut2][1],vectorIndexCombination[iCutt1][0],vectorIndexCombination[iCutt1][1],vectorIndexCombination[iCutt2][0],vectorIndexCombination[iCutt2][1],vectorIndexCombination[iCut1][0],vectorIndexCombination[iCut1][1],vectorIndexCombination[iCut2][0],vectorIndexCombination[iCut2][1],vectorIndexCombination[iCutt1][0],vectorIndexCombination[iCutt1][1],vectorIndexCombination[iCutt2][0],vectorIndexCombination[iCutt2][1]);
      // cout << CutString << endl;
      FSCut::defineCut(Form("2DPiAC%d",iCombination),CutString.Data());
   }
}

void Define2DAlternativeEtaCuts(){
   Double_t etaMass = 0.547853;
   Double_t etaSigma = 0.0078;
   Double_t etaSignalRegion[2] = {etaMass-5*etaSigma,etaMass+5*etaSigma};
   Int_t vectorIndexCombination[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   for (Int_t iCombination = 0;iCombination < 6; iCombination++) {
      Int_t iCut1 = iCombination+1;
      Int_t iCutt1 = iCombination+2;
      if (iCombination <= 2){
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
      cout << "2DEtaAC" << iCombination << " = " << vectorIndexCombination[iCombination][0] << "," << vectorIndexCombination[iCombination][1] << ":" << vectorIndexCombination[5-iCombination][0] << "," << vectorIndexCombination[5-iCombination][1] << " cuts on " << vectorIndexCombination[iCut1][0] << "," << vectorIndexCombination[iCut1][1] << ":" << vectorIndexCombination[iCut2][0] << "," << vectorIndexCombination[iCut2][1] << "  &  " << vectorIndexCombination[iCutt1][0] << "," << vectorIndexCombination[iCutt1][1] << ":" << vectorIndexCombination[iCutt2][0] << "," << vectorIndexCombination[iCutt2][1] << endl;
      TString CutString =  Form("!((MASS(%d,%d)<0.17&&MASS(%d,%d)<%f)&&(MASS(%d,%d)>0.11&&MASS(%d,%d)>%f))",vectorIndexCombination[iCut1][0],vectorIndexCombination[iCut1][1],vectorIndexCombination[iCut2][0],vectorIndexCombination[iCut2][1],etaSignalRegion[1],vectorIndexCombination[iCut1][0],vectorIndexCombination[iCut1][1],vectorIndexCombination[iCut2][0],vectorIndexCombination[iCut2][1],etaSignalRegion[0]);
      CutString += Form("&&!((MASS(%d,%d)<%f&&MASS(%d,%d)<0.17)&&(MASS(%d,%d)>%f&&MASS(%d,%d)>0.11))",vectorIndexCombination[iCut1][0],vectorIndexCombination[iCut1][1],etaSignalRegion[1],vectorIndexCombination[iCut2][0],vectorIndexCombination[iCut2][1],vectorIndexCombination[iCut1][0],vectorIndexCombination[iCut1][1],etaSignalRegion[0],vectorIndexCombination[iCut2][0],vectorIndexCombination[iCut2][1]);
      CutString += Form("&&!((MASS(%d,%d)<0.17&&MASS(%d,%d)<%f)&&(MASS(%d,%d)>0.11&&MASS(%d,%d)>%f))",vectorIndexCombination[iCutt1][0],vectorIndexCombination[iCutt1][1],vectorIndexCombination[iCutt2][0],vectorIndexCombination[iCutt2][1],etaSignalRegion[1],vectorIndexCombination[iCutt1][0],vectorIndexCombination[iCutt1][1],vectorIndexCombination[iCutt2][0],vectorIndexCombination[iCutt2][1],etaSignalRegion[0]);
      CutString += Form("&&!((MASS(%d,%d)<%f&&MASS(%d,%d)<0.17)&&(MASS(%d,%d)>%f&&MASS(%d,%d)>0.11))",vectorIndexCombination[iCutt1][0],vectorIndexCombination[iCutt1][1],etaSignalRegion[1],vectorIndexCombination[iCutt2][0],vectorIndexCombination[iCutt2][1],vectorIndexCombination[iCutt1][0],vectorIndexCombination[iCutt1][1],etaSignalRegion[0],vectorIndexCombination[iCutt2][0],vectorIndexCombination[iCutt2][1]);
      // cout << CutString << endl;
      FSCut::defineCut(Form("2DEtaAC%d",iCombination),CutString.Data());
   }
}

void Define2DAlternativeLowEnergyPhotonCuts(){
   Double_t LowPhotonMass = 0.02;
   Double_t LowPhotonSigma = 0.02;
   Double_t LowPhotonSignalRegion[2] = {LowPhotonMass-LowPhotonSigma,LowPhotonMass+LowPhotonSigma};
   Int_t vectorIndexCombination[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   for (Int_t iCombination = 0;iCombination < 6; iCombination++) {
      Int_t iCut1 = iCombination+1;
      Int_t iCutt1 = iCombination+2;
      if (iCombination <= 2){
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
      cout << "2DLowPhotonAC" << iCombination << " = " << vectorIndexCombination[iCombination][0] << "," << vectorIndexCombination[iCombination][1] << ":" << vectorIndexCombination[5-iCombination][0] << "," << vectorIndexCombination[5-iCombination][1] << " cuts on " << vectorIndexCombination[iCut1][0] << "," << vectorIndexCombination[iCut1][1] << ":" << vectorIndexCombination[iCut2][0] << "," << vectorIndexCombination[iCut2][1] << "  &  " << vectorIndexCombination[iCutt1][0] << "," << vectorIndexCombination[iCutt1][1] << ":" << vectorIndexCombination[iCutt2][0] << "," << vectorIndexCombination[iCutt2][1] << endl;
      TString CutString =  Form("!((MASS(%d,%d)<0.17&&MASS(%d,%d)<%f)&&(MASS(%d,%d)>0.11&&MASS(%d,%d)>%f))",vectorIndexCombination[iCut1][0],vectorIndexCombination[iCut1][1],vectorIndexCombination[iCut2][0],vectorIndexCombination[iCut2][1],LowPhotonSignalRegion[1],vectorIndexCombination[iCut1][0],vectorIndexCombination[iCut1][1],vectorIndexCombination[iCut2][0],vectorIndexCombination[iCut2][1],LowPhotonSignalRegion[0]);
      CutString += Form("&&!((MASS(%d,%d)<%f&&MASS(%d,%d)<0.17)&&(MASS(%d,%d)>%f&&MASS(%d,%d)>0.11))",vectorIndexCombination[iCut1][0],vectorIndexCombination[iCut1][1],LowPhotonSignalRegion[1],vectorIndexCombination[iCut2][0],vectorIndexCombination[iCut2][1],vectorIndexCombination[iCut1][0],vectorIndexCombination[iCut1][1],LowPhotonSignalRegion[0],vectorIndexCombination[iCut2][0],vectorIndexCombination[iCut2][1]);
      CutString += Form("&&!((MASS(%d,%d)<0.17&&MASS(%d,%d)<%f)&&(MASS(%d,%d)>0.11&&MASS(%d,%d)>%f))",vectorIndexCombination[iCutt1][0],vectorIndexCombination[iCutt1][1],vectorIndexCombination[iCutt2][0],vectorIndexCombination[iCutt2][1],LowPhotonSignalRegion[1],vectorIndexCombination[iCutt1][0],vectorIndexCombination[iCutt1][1],vectorIndexCombination[iCutt2][0],vectorIndexCombination[iCutt2][1],LowPhotonSignalRegion[0]);
      CutString += Form("&&!((MASS(%d,%d)<%f&&MASS(%d,%d)<0.17)&&(MASS(%d,%d)>%f&&MASS(%d,%d)>0.11))",vectorIndexCombination[iCutt1][0],vectorIndexCombination[iCutt1][1],LowPhotonSignalRegion[1],vectorIndexCombination[iCutt2][0],vectorIndexCombination[iCutt2][1],vectorIndexCombination[iCutt1][0],vectorIndexCombination[iCutt1][1],LowPhotonSignalRegion[0],vectorIndexCombination[iCutt2][0],vectorIndexCombination[iCutt2][1]);
      // cout << CutString << endl;
      FSCut::defineCut(Form("2DLowPhotonAC%d",iCombination),CutString.Data());
   }
}

void Define2DAlternativeOmegaCuts(){
   Double_t OmegaMass = 0.78265;
   Double_t OmegaSigma = 0.05;
   Double_t OmegaSignalRegion[2] = {OmegaMass-OmegaSigma,OmegaMass+OmegaSigma};
   Int_t vectorIndexCombination[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   for (Int_t iCombination = 0;iCombination < 6; iCombination++) {
      Int_t iCut1 = iCombination+1;
      Int_t iCutt1 = iCombination+2;
      if (iCombination <= 2){
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
      cout << "2DOmegaAC" << iCombination << " = " << vectorIndexCombination[iCombination][0] << "," << vectorIndexCombination[iCombination][1] << ":" << vectorIndexCombination[5-iCombination][0] << "," << vectorIndexCombination[5-iCombination][1] << " cuts on " << vectorIndexCombination[iCut1][0] << "," << vectorIndexCombination[iCut1][1] << ":" << vectorIndexCombination[iCut2][0] << "," << vectorIndexCombination[iCut2][1] << "  &  " << vectorIndexCombination[iCutt1][0] << "," << vectorIndexCombination[iCutt1][1] << ":" << vectorIndexCombination[iCutt2][0] << "," << vectorIndexCombination[iCutt2][1] << endl;
      TString CutString =  Form("!((MASS(%d,%d)<0.17&&MASS(%d,%d)<%f)&&(MASS(%d,%d)>0.11&&MASS(%d,%d)>%f))",vectorIndexCombination[iCut1][0],vectorIndexCombination[iCut1][1],vectorIndexCombination[iCut2][0],vectorIndexCombination[iCut2][1],OmegaSignalRegion[1],vectorIndexCombination[iCut1][0],vectorIndexCombination[iCut1][1],vectorIndexCombination[iCut2][0],vectorIndexCombination[iCut2][1],OmegaSignalRegion[0]);
      CutString += Form("&&!((MASS(%d,%d)<%f&&MASS(%d,%d)<0.17)&&(MASS(%d,%d)>%f&&MASS(%d,%d)>0.11))",vectorIndexCombination[iCut1][0],vectorIndexCombination[iCut1][1],OmegaSignalRegion[1],vectorIndexCombination[iCut2][0],vectorIndexCombination[iCut2][1],vectorIndexCombination[iCut1][0],vectorIndexCombination[iCut1][1],OmegaSignalRegion[0],vectorIndexCombination[iCut2][0],vectorIndexCombination[iCut2][1]);
      CutString += Form("&&!((MASS(%d,%d)<0.17&&MASS(%d,%d)<%f)&&(MASS(%d,%d)>0.11&&MASS(%d,%d)>%f))",vectorIndexCombination[iCutt1][0],vectorIndexCombination[iCutt1][1],vectorIndexCombination[iCutt2][0],vectorIndexCombination[iCutt2][1],OmegaSignalRegion[1],vectorIndexCombination[iCutt1][0],vectorIndexCombination[iCutt1][1],vectorIndexCombination[iCutt2][0],vectorIndexCombination[iCutt2][1],OmegaSignalRegion[0]);
      CutString += Form("&&!((MASS(%d,%d)<%f&&MASS(%d,%d)<0.17)&&(MASS(%d,%d)>%f&&MASS(%d,%d)>0.11))",vectorIndexCombination[iCutt1][0],vectorIndexCombination[iCutt1][1],OmegaSignalRegion[1],vectorIndexCombination[iCutt2][0],vectorIndexCombination[iCutt2][1],vectorIndexCombination[iCutt1][0],vectorIndexCombination[iCutt1][1],OmegaSignalRegion[0],vectorIndexCombination[iCutt2][0],vectorIndexCombination[iCutt2][1]);
      // cout << CutString << endl;
      FSCut::defineCut(Form("2DOmegaAC%d",iCombination),CutString.Data());
   }
}

void DefineDeltaCuts(){
   Double_t DeltaUpLim = 1.4;
   Int_t vectorIndexCombination[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   for (Int_t iCombination=0;iCombination<6;iCombination++){
      TString CutString = Form("MASS(1,%d,%d)>%f",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],DeltaUpLim);
      FSCut::defineCut(Form("DeltaCut%d",iCombination),CutString.Data());
   }
}

void DefineOmegaMomentumCuts(){
   Double_t omegaMomentum = 7.6;
   Double_t omegaMomentumWindow = 0.8;
   Double_t omegaMass = 0.78265;
   Double_t omegaMassWindow = 0.05;
   Int_t vectorIndexCombination[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   for (Int_t iCombination=0;iCombination<6;iCombination++){
      Int_t Pi0Index = 5-iCombination;
      TString CutString;
      for (Int_t iExtraPhoton=0;iExtraPhoton<2;iExtraPhoton++){
         CutString += Form("!(MASS(%d,%d,%d)>%f&&MASS(%d,%d,%d)<%f",vectorIndexCombination[Pi0Index][0],vectorIndexCombination[Pi0Index][1],vectorIndexCombination[iCombination][iExtraPhoton],omegaMass-omegaMassWindow,vectorIndexCombination[Pi0Index][0],vectorIndexCombination[Pi0Index][1],vectorIndexCombination[iCombination][iExtraPhoton],omegaMass+omegaMassWindow); 
         CutString += Form("&&MOMENTUM(%d,%d,%d)>%f&&MOMENTUM(%d,%d,%d)<%f)",vectorIndexCombination[Pi0Index][0],vectorIndexCombination[Pi0Index][1],vectorIndexCombination[iCombination][iExtraPhoton],omegaMomentum-omegaMomentumWindow,vectorIndexCombination[Pi0Index][0],vectorIndexCombination[Pi0Index][1],vectorIndexCombination[iCombination][iExtraPhoton],omegaMomentum+omegaMomentumWindow);
         if (!iExtraPhoton) CutString += "&&";
      }
      cout << "CutString omega momentum " << iCombination << " = " << CutString << endl;
      FSCut::defineCut(Form("OmegaMomentumCut%d",iCombination),CutString.Data());
   }
}

void DefineOmegaCosThetaCOMCuts(){
   Double_t omegaCosThetaCOM = 0.95;
   Double_t omegaCosThetaCOMWindow = 0.05;
   Double_t omegaMass = 0.78265;
   Double_t omegaMassWindow = 0.05;
   Int_t vectorIndexCombination[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   for (Int_t iCombination=0;iCombination<6;iCombination++){
      Int_t Pi0Index = 5-iCombination;
      TString CutString;
      for (Int_t iExtraPhoton=0;iExtraPhoton<2;iExtraPhoton++){
         CutString += Form("!(MASS(%d,%d,%d)>%f&&MASS(%d,%d,%d)<%f",vectorIndexCombination[Pi0Index][0],vectorIndexCombination[Pi0Index][1],vectorIndexCombination[iCombination][iExtraPhoton],omegaMass-omegaMassWindow,vectorIndexCombination[Pi0Index][0],vectorIndexCombination[Pi0Index][1],vectorIndexCombination[iCombination][iExtraPhoton],omegaMass+omegaMassWindow); 
         CutString += Form("&&cosTheta3GCOMFrame(%d;%d;%d;GLUEXCMS)>%f&&cosTheta3GCOMFrame(%d;%d;%d;GLUEXCMS)<%f)",vectorIndexCombination[Pi0Index][0],vectorIndexCombination[Pi0Index][1],vectorIndexCombination[iCombination][iExtraPhoton],omegaCosThetaCOM-omegaCosThetaCOMWindow,vectorIndexCombination[Pi0Index][0],vectorIndexCombination[Pi0Index][1],vectorIndexCombination[iCombination][iExtraPhoton],omegaCosThetaCOM+omegaCosThetaCOMWindow);
         if (!iExtraPhoton) CutString += "&&";
      }
      cout << "CutString omega CosThetaCOM " << iCombination << " = " << CutString << endl;
      FSCut::defineCut(Form("OmegaCosThetaCOMCut%d",iCombination),CutString.Data());
   }
}

void PlotOmegaMassWithCuts(TString fileName,TString treeName,Int_t numberOfBin,Double_t xmin,Double_t xmax, TString cutName, TString tag, Bool_t isFit){
   const Int_t NCombination = 6;
   const Int_t NOmegaCombination = 2;
   const Int_t NHist = NCombination*NOmegaCombination;
   Double_t binWidth = (xmax-xmin)/numberOfBin;
   TH1F *h[NHist];
   TH1F *h_total;
   TString binning = Form("(%d,%f,%f)",numberOfBin,xmin,xmax);
   TCanvas *c = new TCanvas("c","c",1200,800);
   c->Divide(4,3);
   Int_t vectorIndexCombination[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   Int_t iHist = 0;
   for (Int_t iCombination=0;iCombination<6;iCombination++) {
      Int_t Pi0Index = 5-iCombination;
      for (Int_t iExtraPhoton=0;iExtraPhoton<2;iExtraPhoton++){
         TString cutString = "CUT(";
         cutString += cutName;
         cutString += Form(",pi0Select%d",5-iCombination);
         cutString += Form(",etaPrimeSelect%d",iCombination);
         cutString += Form(",2DPiAC%d",iCombination);
         cutString += Form(",2DEtaAC%d",iCombination);
         cutString += Form(",DeltaCut%d",5-iCombination);
         if (tag == TString("OmegaMomentumCut")) cutString += Form(",%s%d",tag.Data(),iCombination);
         else if (tag == TString("OmegaCosThetaCOMCut")) cutString += Form(",%s%d",tag.Data(),iCombination);
         cutString += ")";
         cout << iHist+1 << ". " << Form("MASS(%d,%d,%d)",vectorIndexCombination[Pi0Index][0],vectorIndexCombination[Pi0Index][1],vectorIndexCombination[iCombination][iExtraPhoton]) << endl;
         cout << "   CutString = " << cutString << endl;
         h[iHist] = FSModeHistogram::getTH1F(fileName,treeName,"",Form("MASS(%d,%d,%d)",vectorIndexCombination[Pi0Index][0],vectorIndexCombination[Pi0Index][1],vectorIndexCombination[iCombination][iExtraPhoton]),binning,cutString);
         h[iHist]->SetTitle(Form("#eta' #rightarrow #gamma_{%d}#gamma_{%d} && #pi^{0} #rightarrow #gamma_{%d}#gamma_{%d}",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[Pi0Index][0],vectorIndexCombination[Pi0Index][1]));
         h[iHist]->GetXaxis()->SetTitle(Form("m_{#gamma_{%d}#gamma_{%d}#gamma_{%d}} (GeV/c^{2})",vectorIndexCombination[Pi0Index][0],vectorIndexCombination[Pi0Index][1],vectorIndexCombination[iCombination][iExtraPhoton]));
         h[iHist]->GetYaxis()->SetTitle(Form("Counts/%.0f MeV/c^{2}",(xmax-xmin)*1000./numberOfBin));
         //make plots look nicer
         h[iHist]->SetLineColor(kBlack);
         h[iHist]->SetLineWidth(2);
         h[iHist]->SetMarkerStyle(20);
         h[iHist]->SetMarkerSize(0.5);
         h[iHist]->SetMarkerColor(kBlack);
         h[iHist]->GetXaxis()->SetRangeUser(xmin,xmax);
         h[iHist]->GetXaxis()->SetNdivisions(505);
         h[iHist]->GetYaxis()->SetNdivisions(505);
         h[iHist]->GetXaxis()->SetTitleSize(0.05);
         h[iHist]->GetYaxis()->SetTitleSize(0.05);
         h[iHist]->GetXaxis()->SetTitleOffset(1.0);
         h[iHist]->GetYaxis()->SetTitleOffset(1.0);
         h[iHist]->GetXaxis()->SetLabelSize(0.05);
         h[iHist]->GetYaxis()->SetLabelSize(0.05);
         h[iHist]->GetXaxis()->SetLabelOffset(0.01);
         h[iHist]->GetYaxis()->SetLabelOffset(0.01);
         h[iHist]->GetXaxis()->SetLabelFont(42);
         h[iHist]->GetYaxis()->SetLabelFont(42);
         h[iHist]->GetXaxis()->SetTitleFont(42);
         h[iHist]->GetYaxis()->SetTitleFont(42);
         h[iHist]->GetXaxis()->SetTickLength(0.03);
         h[iHist]->GetYaxis()->SetTickLength(0.03);
         c->cd(iHist+1);
         h[iHist]->Draw();
         if (isFit){
            //fit the histogram with gaussian function and linear function
            TF1 *f = new TF1("f","gaus(0)+pol1(3)",xmin,xmax);
            Double_t omegaMass = 0.78265;
            f->SetParameters(100,omegaMass,0.01,0,0);
            h[iHist]->Fit("f","R");
            Double_t mean = f->GetParameter(1);
            Double_t sigma = TMath::Abs(f->GetParameter(2));
            Double_t meanError = f->GetParError(1);
            Double_t sigmaError = f->GetParError(2);
            Double_t chi2 = f->GetChisquare();
            Double_t ndf = f->GetNDF();
            Double_t chi2ndf = chi2/ndf;
            cout << "   Mean = " << mean << " +- " << meanError << endl;
            cout << "   Sigma = " << sigma << " +- " << sigmaError << endl;
            cout << "   Chi2 = " << chi2 << endl;
            cout << "   NDF = " << ndf << endl;
            cout << "   Chi2/NDF = " << chi2ndf << endl;
            //draw the fit function
            TF1 *fFit = new TF1("fFit","gaus(0)+pol1(3)",xmin,xmax);
            fFit->SetParameters(f->GetParameters());
            fFit->SetLineColor(kRed);
            fFit->Draw("same");

            //draw gaussian function and linear function separately
            TF1 *fGaus = new TF1("fGaus","gaus(0)",xmin,xmax);
            fGaus->SetParameters(f->GetParameter(0),f->GetParameter(1),f->GetParameter(2));
            fGaus->SetLineStyle(2);
            fGaus->SetLineWidth(1);
            fGaus->SetLineColor(kGreen);
            fGaus->Draw("same");

            TF1 *fLinear = new TF1("fLinear","pol1(0)",xmin,xmax);
            fLinear->SetParameters(f->GetParameter(3),f->GetParameter(4));
            fLinear->SetLineStyle(2);
            fLinear->SetLineWidth(1);
            fLinear->SetLineColor(kBlue);
            fLinear->Draw("same");

            // calculate omega yield and write it on histogram
            Double_t omegaYield = fGaus->Integral(mean-5*sigma,mean+5*sigma)/h[iHist]->GetBinWidth(1);
            cout << "   Omega Yield = " << omegaYield << endl;
            TLatex *latex = new TLatex();
            latex->SetTextSize(0.04);
            latex->DrawLatexNDC(0.2,0.8,Form("#mu = %.4f",mean));

         }
         if (iHist==0) h_total = (TH1F*)h[iHist]->Clone("h_total");
         else h_total->Add(h[iHist]);
         iHist++;
      }
   }
   c->SaveAs(Form("OmegaMass_%s.pdf",tag.Data()));
   c->Clear();
   c->Divide(1,1);
   c->cd(1);
   h_total->GetXaxis()->SetTitle("m_{#gamma #gamma #gamma} (GeV/c^{2})");
   h_total->GetYaxis()->SetTitle(Form("Counts/%.0f MeV/c^{2}",(xmax-xmin)*1000./numberOfBin));
   // fit h_total and write the yield on histogram
   if (isFit){
      TF1 *f = new TF1("f","gaus(0)+pol1(3)",xmin,xmax);
      Double_t omegaMass = 0.78265;
      f->SetParameters(100,omegaMass,0.01,0,0);
      h_total->Fit("f","R");
      Double_t mean = f->GetParameter(1);
      Double_t sigma = TMath::Abs(f->GetParameter(2));
      Double_t meanError = f->GetParError(1);
      Double_t sigmaError = f->GetParError(2);
      Double_t chi2 = f->GetChisquare();
      Double_t ndf = f->GetNDF();
      Double_t chi2ndf = chi2/ndf;
      cout << "   Mean = " << mean << " +- " << meanError << endl;
      cout << "   Sigma = " << sigma << " +- " << sigmaError << endl;
      cout << "   Chi2 = " << chi2 << endl;
      cout << "   NDF = " << ndf << endl;
      cout << "   Chi2/NDF = " << chi2ndf << endl;
      //draw the fit function
      TF1 *fFit = new TF1("fFit","gaus(0)+pol1(3)",xmin,xmax);
      fFit->SetParameters(f->GetParameters());
      fFit->SetLineColor(kRed);
      fFit->Draw("same");

      //draw gaussian function and linear function separately
      TF1 *fGaus = new TF1("fGaus","gaus(0)",xmin,xmax);
      fGaus->SetParameters(f->GetParameter(0),f->GetParameter(1),f->GetParameter(2));
      fGaus->SetLineStyle(2);
      fGaus->SetLineWidth(1);
      fGaus->SetLineColor(kGreen);
      fGaus->Draw("same");

      TF1 *fLinear = new TF1("fLinear","pol1(0)",xmin,xmax);
      fLinear->SetParameters(f->GetParameter(3),f->GetParameter(4));
      fLinear->SetLineStyle(2);
      fLinear->SetLineWidth(1);
      fLinear->SetLineColor(kBlue);
      fLinear->Draw("same");

      // calculate omega yield and write it on histogram
      Double_t omegaYield = fGaus->Integral(mean-5*sigma,mean+5*sigma)/h_total->GetBinWidth(1);
      cout << "   Omega Yield = " << omegaYield << endl;
      TLatex *latex = new TLatex();
      latex->SetTextSize(0.04);
      latex->DrawLatexNDC(0.2,0.8,Form("S = %.0f",omegaYield));

   }
   h_total->Draw();
   c->SaveAs(Form("OmegaMass_%s_total.pdf",tag.Data()));
}

void PlotOmegaMassWithCutsSkimmed2DEtaPiAC(TString *fileName,TString treeName,Int_t numberOfBin,Double_t xmin,Double_t xmax, TString cutName, TString tag, Bool_t isFit){
   const Int_t NCombination = 6;
   const Int_t NOmegaCombination = 2;
   const Int_t NHist = NCombination*NOmegaCombination;
   Double_t binWidth = (xmax-xmin)/numberOfBin;
   TH1F *h[NHist];
   TH1F *h_total;
   TString binning = Form("(%d,%f,%f)",numberOfBin,xmin,xmax);
   TCanvas *c = new TCanvas("c","c",1200,800);
   c->Divide(4,3);
   Int_t vectorIndexCombination[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
   Int_t iHist = 0;
   for (Int_t iCombination=0;iCombination<6;iCombination++) {
      Int_t Pi0Index = 5-iCombination;
      for (Int_t iExtraPhoton=0;iExtraPhoton<2;iExtraPhoton++){
         TString cutString = "CUT(";
         cutString += cutName;
         cutString += Form(",pi0Select%d",5-iCombination);
         cutString += Form(",etaPrimeSelect%d",iCombination);
         cutString += Form(",2DLowPhotonAC%d",iCombination);
         cutString += Form(",2DOmegaAC%d",iCombination);
         cutString += Form(",DeltaCut%d",5-iCombination);
         if (tag == TString("OmegaMomentumCut")) cutString += Form(",%s%d",tag.Data(),iCombination);
         else if (tag == TString("OmegaCosThetaCOMCut")) cutString += Form(",%s%d",tag.Data(),iCombination);
         cutString += ")";
         cout << iHist+1 << ". " << Form("MASS(%d,%d,%d)",vectorIndexCombination[Pi0Index][0],vectorIndexCombination[Pi0Index][1],vectorIndexCombination[iCombination][iExtraPhoton]) << endl;
         cout << "   CutString = " << cutString << endl;
         h[iHist] = FSModeHistogram::getTH1F(fileName[iCombination],treeName,"",Form("MASS(%d,%d,%d)",vectorIndexCombination[Pi0Index][0],vectorIndexCombination[Pi0Index][1],vectorIndexCombination[iCombination][iExtraPhoton]),binning,cutString);
         h[iHist]->SetTitle(Form("#eta' #rightarrow #gamma_{%d}#gamma_{%d} && #pi^{0} #rightarrow #gamma_{%d}#gamma_{%d}",vectorIndexCombination[iCombination][0],vectorIndexCombination[iCombination][1],vectorIndexCombination[Pi0Index][0],vectorIndexCombination[Pi0Index][1]));
         h[iHist]->GetXaxis()->SetTitle(Form("m_{#gamma_{%d}#gamma_{%d}#gamma_{%d}} (GeV/c^{2})",vectorIndexCombination[Pi0Index][0],vectorIndexCombination[Pi0Index][1],vectorIndexCombination[iCombination][iExtraPhoton]));
         h[iHist]->GetYaxis()->SetTitle(Form("Counts/%.0f MeV/c^{2}",(xmax-xmin)*1000./numberOfBin));
         //make plots look nicer
         h[iHist]->SetLineColor(kBlack);
         h[iHist]->SetLineWidth(2);
         h[iHist]->SetMarkerStyle(20);
         h[iHist]->SetMarkerSize(0.5);
         h[iHist]->SetMarkerColor(kBlack);
         h[iHist]->GetXaxis()->SetRangeUser(xmin,xmax);
         h[iHist]->GetXaxis()->SetNdivisions(505);
         h[iHist]->GetYaxis()->SetNdivisions(505);
         h[iHist]->GetXaxis()->SetTitleSize(0.05);
         h[iHist]->GetYaxis()->SetTitleSize(0.05);
         h[iHist]->GetXaxis()->SetTitleOffset(1.0);
         h[iHist]->GetYaxis()->SetTitleOffset(1.0);
         h[iHist]->GetXaxis()->SetLabelSize(0.05);
         h[iHist]->GetYaxis()->SetLabelSize(0.05);
         h[iHist]->GetXaxis()->SetLabelOffset(0.01);
         h[iHist]->GetYaxis()->SetLabelOffset(0.01);
         h[iHist]->GetXaxis()->SetLabelFont(42);
         h[iHist]->GetYaxis()->SetLabelFont(42);
         h[iHist]->GetXaxis()->SetTitleFont(42);
         h[iHist]->GetYaxis()->SetTitleFont(42);
         h[iHist]->GetXaxis()->SetTickLength(0.03);
         h[iHist]->GetYaxis()->SetTickLength(0.03);
         c->cd(iHist+1);
         h[iHist]->Draw();
         if (isFit){
            //fit the histogram with gaussian function and linear function
            TF1 *f = new TF1("f","gaus(0)+pol1(3)",xmin,xmax);
            Double_t omegaMass = 0.78265;
            f->SetParameters(100,omegaMass,0.01,0,0);
            h[iHist]->Fit("f","R");
            Double_t mean = f->GetParameter(1);
            Double_t sigma = TMath::Abs(f->GetParameter(2));
            Double_t meanError = f->GetParError(1);
            Double_t sigmaError = f->GetParError(2);
            Double_t chi2 = f->GetChisquare();
            Double_t ndf = f->GetNDF();
            Double_t chi2ndf = chi2/ndf;
            cout << "   Mean = " << mean << " +- " << meanError << endl;
            cout << "   Sigma = " << sigma << " +- " << sigmaError << endl;
            cout << "   Chi2 = " << chi2 << endl;
            cout << "   NDF = " << ndf << endl;
            cout << "   Chi2/NDF = " << chi2ndf << endl;
            //draw the fit function
            TF1 *fFit = new TF1("fFit","gaus(0)+pol1(3)",xmin,xmax);
            fFit->SetParameters(f->GetParameters());
            fFit->SetLineColor(kRed);
            fFit->Draw("same");

            //draw gaussian function and linear function separately
            TF1 *fGaus = new TF1("fGaus","gaus(0)",xmin,xmax);
            fGaus->SetParameters(f->GetParameter(0),f->GetParameter(1),f->GetParameter(2));
            fGaus->SetLineStyle(2);
            fGaus->SetLineWidth(1);
            fGaus->SetLineColor(kGreen);
            fGaus->Draw("same");

            TF1 *fLinear = new TF1("fLinear","pol1(0)",xmin,xmax);
            fLinear->SetParameters(f->GetParameter(3),f->GetParameter(4));
            fLinear->SetLineStyle(2);
            fLinear->SetLineWidth(1);
            fLinear->SetLineColor(kBlue);
            fLinear->Draw("same");

            // calculate omega yield and write it on histogram
            Double_t omegaYield = fGaus->Integral(mean-5*sigma,mean+5*sigma)/h[iHist]->GetBinWidth(1);
            cout << "   Omega Yield = " << omegaYield << endl;
            TLatex *latex = new TLatex();
            latex->SetTextSize(0.04);
            latex->DrawLatexNDC(0.2,0.8,Form("#mu = %.4f",mean));
         }
         if (iHist==0) h_total = (TH1F*)h[iHist]->Clone("h_total");
         else h_total->Add(h[iHist]);
         iHist++;
      }
   }
   c->SaveAs(Form("OmegaMass_%s.pdf",tag.Data()));
   c->Clear();
   c->Divide(1,1);
   c->cd(1);
   c->SetWindowSize(300,800);
   h_total->SetTitle("m_{#gamma#gamma#gamma} all combination sum");
   h_total->GetXaxis()->SetTitle("m_{#gamma#gamma#gamma} (GeV/c^{2})");
   h_total->GetYaxis()->SetTitle(Form("Counts/%.0f MeV/c^{2}",(xmax-xmin)*1000./numberOfBin));
   h_total->GetYaxis()->SetTitleOffset(1.5);
   h_total->Draw();

   // fit h_total and write the yield on histogram
   if (isFit){
      TF1 *f = new TF1("f","gaus(0)+pol1(3)",xmin,xmax);
      Double_t omegaMass = 0.78265;
      f->SetParameters(100,omegaMass,0.01,0,0);
      h_total->Fit("f","R");
      Double_t mean = f->GetParameter(1);
      Double_t sigma = TMath::Abs(f->GetParameter(2));
      Double_t meanError = f->GetParError(1);
      Double_t sigmaError = f->GetParError(2);
      Double_t chi2 = f->GetChisquare();
      Double_t ndf = f->GetNDF();
      Double_t chi2ndf = chi2/ndf;
      cout << "   Mean = " << mean << " +- " << meanError << endl;
      cout << "   Sigma = " << sigma << " +- " << sigmaError << endl;
      cout << "   Chi2 = " << chi2 << endl;
      cout << "   NDF = " << ndf << endl;
      cout << "   Chi2/NDF = " << chi2ndf << endl;
      //draw the fit function
      TF1 *fFit = new TF1("fFit","gaus(0)+pol1(3)",xmin,xmax);
      fFit->SetParameters(f->GetParameters());
      fFit->SetLineColor(kRed);
      fFit->Draw("same");

      //draw gaussian function and linear function separately
      TF1 *fGaus = new TF1("fGaus","gaus(0)",xmin,xmax);
      fGaus->SetParameters(f->GetParameter(0),f->GetParameter(1),f->GetParameter(2));
      fGaus->SetLineStyle(2);
      fGaus->SetLineWidth(1);
      fGaus->SetLineColor(kGreen);
      fGaus->Draw("same");

      TF1 *fLinear = new TF1("fLinear","pol1(0)",xmin,xmax);
      fLinear->SetParameters(f->GetParameter(3),f->GetParameter(4));
      fLinear->SetLineStyle(2);
      fLinear->SetLineWidth(1);
      fLinear->SetLineColor(kBlue);
      fLinear->Draw("same");

      // Draw signal yield and mean
      Double_t omegaYield = fGaus->Integral(mean-5*sigma,mean+5*sigma)/h_total->GetBinWidth(1);
      cout << "   Omega Yield = " << omegaYield << endl;
      TLatex *latex_total = new TLatex();
      latex_total->SetTextSize(0.04);
      latex_total->DrawLatexNDC(0.2,0.8,Form("S = %.0f",omegaYield));
      latex_total->DrawLatexNDC(0.2,0.75,Form("#mu = %.4f",mean));

   }
   c->SaveAs(Form("OmegaMass_%s_total.pdf",tag.Data()));
}

Double_t cosTheta3G4GFrame(Double_t PxPA, Double_t PyPA, Double_t PzPA, Double_t EnPA,
                              Double_t PxPB, Double_t PyPB, Double_t PzPB, Double_t EnPB,
                              Double_t PxPC, Double_t PyPC, Double_t PzPC, Double_t EnPC,
                              Double_t PxPD, Double_t PyPD, Double_t PzPD, Double_t EnPD){
      
   TLorentzVector PA(PxPA,PyPA,PzPA,EnPA);
   TLorentzVector PB(PxPB,PyPB,PzPB,EnPB);
   TLorentzVector PC(PxPC,PyPC,PzPC,EnPC);
   TLorentzVector PD(PxPD,PyPD,PzPD,EnPD);
   TLorentzVector p4_ABC = PA + PB + PC;
   TLorentzVector p4_ABCD = p4_ABC + PD;
   
   // get the boost vector
   TVector3 boost = p4_ABCD.BoostVector();
   // boost the 4-vectors
   PA.Boost(-boost);
   PB.Boost(-boost);
   PC.Boost(-boost);
   PD.Boost(-boost);
   
   TVector3 p3_AB = PA.Vect() + PB.Vect();
   TVector3 p3_ABC = p3_AB + PC.Vect();
   TVector3 p3_ABCD = p3_ABC + PD.Vect();
   //get the angle between p3_AB and p3_ABC
   Double_t cosTheta = p3_ABCD.Dot(p3_ABC)/(p3_ABCD.Mag()*p3_ABC.Mag());
   return cosTheta;

}

Double_t cosTheta3GCOMFrame(Double_t PxPA, Double_t PyPA, Double_t PzPA, Double_t EnPA,
                              Double_t PxPB, Double_t PyPB, Double_t PzPB, Double_t EnPB,
                              Double_t PxPC, Double_t PyPC, Double_t PzPC, Double_t EnPC,
                              Double_t PxPD, Double_t PyPD, Double_t PzPD, Double_t EnPD){
   
   //gamma A,B,C are from omega, gamma D is total four momenta to get COM frame
   TLorentzVector PA(PxPA,PyPA,PzPA,EnPA);
   TLorentzVector PB(PxPB,PyPB,PzPB,EnPB);
   TLorentzVector PC(PxPC,PyPC,PzPC,EnPC);
   TLorentzVector PD(PxPD,PyPD,PzPD,EnPD);
   
   // get the boost vector
   TVector3 boost = PD.BoostVector();
   // boost the 4-vectors
   PA.Boost(-boost);
   PB.Boost(-boost);
   PC.Boost(-boost);
   
   TVector3 p3_ABC = PA.Vect() + PB.Vect() + PC.Vect();
   
   Double_t cosTheta = p3_ABC.CosTheta();
   // cout << cosTheta << endl;
   return cosTheta;

}

Double_t cosTheta2GCOMFrame(Double_t PxPA, Double_t PyPA, Double_t PzPA, Double_t EnPA,
                              Double_t PxPB, Double_t PyPB, Double_t PzPB, Double_t EnPB,
                              Double_t PxPC, Double_t PyPC, Double_t PzPC, Double_t EnPC){
   
   //gamma A,B are from eta prime, gamma C is total four momenta to get COM frame
   TLorentzVector PA(PxPA,PyPA,PzPA,EnPA);
   TLorentzVector PB(PxPB,PyPB,PzPB,EnPB);
   TLorentzVector PC(PxPC,PyPC,PzPC,EnPC);
   
   // get the boost vector
   TVector3 boost = PC.BoostVector();
   // boost the 4-vectors
   PA.Boost(-boost);
   PB.Boost(-boost);
   
   TVector3 p3_AB = PA.Vect() + PB.Vect();
   
   Double_t cosTheta = p3_AB.CosTheta();
   return cosTheta;

}

Double_t pi0Momentum3GFrame(Double_t PxPA, Double_t PyPA, Double_t PzPA, Double_t EnPA,
                              Double_t PxPB, Double_t PyPB, Double_t PzPB, Double_t EnPB,
                              Double_t PxPC, Double_t PyPC, Double_t PzPC, Double_t EnPC){
   
   TLorentzVector PA(PxPA,PyPA,PzPA,EnPA);
   TLorentzVector PB(PxPB,PyPB,PzPB,EnPB);
   TLorentzVector PC(PxPC,PyPC,PzPC,EnPC);

   TLorentzVector p4_ABC = PA + PB + PC;

   // get the boost vector
   TVector3 boost = p4_ABC.BoostVector();
   // boost the 4-vectors
   PA.Boost(-boost);
   PB.Boost(-boost);
   PC.Boost(-boost);

   TVector3 p3_AB = PA.Vect() + PB.Vect();
   Double_t pi0Momentum = p3_AB.Mag();
   return pi0Momentum;

}

Double_t cosTheta2G2G4GFrame(Double_t PxPA, Double_t PyPA, Double_t PzPA, Double_t EnPA,
                     Double_t PxPB, Double_t PyPB, Double_t PzPB, Double_t EnPB,
                     Double_t PxPC, Double_t PyPC, Double_t PzPC, Double_t EnPC,
                     Double_t PxPD, Double_t PyPD, Double_t PzPD, Double_t EnPD){
   
   TLorentzVector PA(PxPA,PyPA,PzPA,EnPA);
   TLorentzVector PB(PxPB,PyPB,PzPB,EnPB);
   TLorentzVector PC(PxPC,PyPC,PzPC,EnPC);
   TLorentzVector PD(PxPD,PyPD,PzPD,EnPD);

   TLorentzVector p4_ABCD = PA + PB + PC + PD;

   // get the boost vector

   TVector3 boost = p4_ABCD.BoostVector();
   // boost the 4-vectors
   PA.Boost(-boost);
   PB.Boost(-boost);
   PC.Boost(-boost);
   PD.Boost(-boost);

   TLorentzVector boosted_p4_AB = PA + PB;
   TLorentzVector boosted_p4_CD = PC + PD;

   //angle between p3_AB and p3_CD
   Double_t cosTheta = boosted_p4_AB.Vect().Dot(boosted_p4_CD.Vect())/(boosted_p4_AB.Vect().Mag()*boosted_p4_CD.Vect().Mag());
   return cosTheta;
}

Double_t absMomentum2EnergyRatio(Double_t PxPA, Double_t PyPA, Double_t PzPA, Double_t EnPA){
   TLorentzVector PA(PxPA,PyPA,PzPA,EnPA);
   Double_t absMomentum = PA.Vect().Mag();
   Double_t energy = PA.E();
   Double_t ratio = absMomentum/energy;
   return ratio;
}

// Double_t cosTheta3G4GFrame(Double_t PxPA, Double_t PyPA, Double_t PzPA, Double_t EnPA,
//                               Double_t PxPB, Double_t PyPB, Double_t PzPB, Double_t EnPB,
//                               Double_t PxPC, Double_t PyPC, Double_t PzPC, Double_t EnPC,
//                               Double_t PxPD, Double_t PyPD, Double_t PzPD, Double_t EnPD){
      
//    TLorentzVector PA(PxPA,PyPA,PzPA,EnPA);
//    TLorentzVector PB(PxPB,PyPB,PzPB,EnPB);
//    TLorentzVector PC(PxPC,PyPC,PzPC,EnPC);
//    TLorentzVector PD(PxPD,PyPD,PzPD,EnPD);
//    TLorentzVector p4_ABC = PA + PB + PC;
//    TLorentzVector p4_ABCD = p4_ABC + PD;
   
//    // get the boost vector
//    TVector3 boost = p4_ABCD.BoostVector();
//    // boost the 4-vectors
//    PA.Boost(-boost);
//    PB.Boost(-boost);
//    PC.Boost(-boost);
//    PD.Boost(-boost);
   
//    TVector3 p3_AB = PA.Vect() + PB.Vect();
//    TVector3 p3_ABC = p3_AB + PC.Vect();
//    TVector3 p3_ABCD = p3_ABC + PD.Vect();
//    //get the angle between p3_AB and p3_ABC
//    Double_t cosTheta = p3_ABCD.Dot(p3_ABC)/(p3_ABCD.Mag()*p3_ABC.Mag());
//    return cosTheta;

// }

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
   //                      150,0.0,3.0, "m_{#eta'#pi^{0}} GeV", 50, -1.0, 1.0, "cos#theta_{GJ}", Form("Selection: \\eta'(\\gamma_{%d}\\gamma_{%d}) & \\pi^{0}(\\gamma_{%d}\\gamma_{%d})",vectorIndexCombination[i][0],vectorIndexCombination[i][1],vectorIndexCombination[5-i][0],vectorIndexCombination[5-i][1]),
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
