TString fileName = "histograms/3GammaMass_1stCombinationSSB_pi0Select5,2DPiAC0,2DEtaAC0.cache.root";
TString outputTag = "3GammaMass_1stCombinationSSB_pi0Select5,2DPiAC0,2DEtaAC0";

const Int_t NCombinations = 4;
const Int_t NCuts = 1;
const Int_t NComposites = 3;
const Int_t NHist = NCombinations*NCuts*NComposites;

void gluex_style();
void drawHist3GammaSSB(){
	gSystem->Exec("mkdir -p plots");

	// gluex_style();
	// gROOT->ForceStyle();	

	// string drawOptions="HIST";

	TFile* f=new TFile(fileName,"READ");
	TString hname;
	TH1F *h1[NHist];

	Int_t vectorIndexCombination3[4][3] = {{2,3,4},{2,3,5},{2,4,5},{3,4,5}};
	for (Int_t i=NHist-1;i>=0;i--) {
		if (i<9) hname=Form("FSRootHist:00000%d",i+1);
		else hname=Form("FSRootHist:0000%d",i+1);
		if ((((i+1)%NComposites)==1)) {
			h1[i] = new TH1F(*h1[i+1]);
			h1[i]->Add(h1[i+2]);
		}
		else f->GetObject(hname.Data(),h1[i]);
		// cout << i+1 << endl;
	}
	
	TCanvas *c[NComposites];
	for (Int_t iCanvas=0;iCanvas<NComposites;iCanvas++){
		c[iCanvas] = new TCanvas(Form("c%d",iCanvas+1),Form("c%d",iCanvas+1),800,600);
		c[iCanvas]->Divide(2,2);
	}

	Int_t iPlot=0;
	Color_t markerColor=1;
	for (Int_t iHist=0;iHist<NHist;iHist++){	
		if (iHist%NComposites==0){
			if ((iPlot)%NCombinations==0) iPlot=0;
			iPlot++;
		}
		for (Int_t iComposite=0;iComposite<NComposites;iComposite++) {
			if ((iHist+1)%NComposites==iComposite) {
				c[iComposite]->cd(iPlot);
				h1[iHist]->SetMarkerColor(markerColor);
				h1[iHist]->SetLineColor(markerColor);
				h1[iHist]->SetTitle("Selection: #eta' #rightarrow #gamma_{1}#gamma_{2} & #pi^{0} #rightarrow #gamma_{3}#gamma_{4}");
				h1[iHist]->GetXaxis()->SetTitle(Form("m_{#gamma_{%d}#gamma_{%d}#gamma_{%d}} [GeV]",vectorIndexCombination3[iPlot-1][0],vectorIndexCombination3[iPlot-1][1],vectorIndexCombination3[iPlot-1][2]));
				h1[iHist]->GetYaxis()->SetTitle(Form("Events / %d MeV",(Int_t)(h1[iHist]->GetBinWidth(1)*1000)));
				h1[iHist]->Draw("SAME");
				cout << iHist+1 << " " << iComposite+1 << " " << iPlot << " " << markerColor << endl;
			}
		}
		// h1_total[markerColor-1]->SetMarkerColor(markerColor);
		// h1_total[markerColor-1]->SetLineColor(markerColor);
		// h1_total[markerColor-1]->SetTitle("");
		// c_total[markerColor-1]->cd();
		// h1_total[markerColor-1]->Draw("SAME");
		if ((iHist+1)%(NComposites*NCombinations)==0) markerColor++;
	}
	for (Int_t iCanvas=0;iCanvas<NComposites;iCanvas++){
		c[iCanvas]->SaveAs(Form("plots/%s_%d.pdf",outputTag.Data(),iCanvas+1));
	}
}

void gluex_style() {
	///////// 
	// Make the plots prettier with bigger fonts
	// Original code is https://halldweb.jlab.org/wiki-private/index.php/Guidance_for_Presentations 
	// 	slightly modified
	/////////
	auto gluex_style = new TStyle("GlueX","Default GlueX Style");

        gluex_style->SetCanvasBorderMode(0);
        gluex_style->SetPadBorderMode(0);
        gluex_style->SetPadColor(0);
        gluex_style->SetCanvasColor(0);
        gluex_style->SetStatColor(0);

	// some default window sizes
	gluex_style->SetCanvasDefW(800);
	gluex_style->SetCanvasDefH(600);

	// let's change the default margins
	gluex_style->SetPadBottomMargin(0.2);
	gluex_style->SetPadLeftMargin(0.2);
	gluex_style->SetPadTopMargin(0.08);
	gluex_style->SetPadRightMargin(0.15);

	// axis labels and settings
    gluex_style->SetStripDecimals(0);
 	gluex_style->SetLabelSize(0.045,"xyz"); // size of axis value font
 	gluex_style->SetTitleSize(0.06,"xyz"); // size of axis title font
 	gluex_style->SetTitleFont(42,"xyz"); // font option
 	gluex_style->SetLabelFont(42,"xyz"); 
 	gluex_style->SetTitleOffset(1.5,"y"); 
 	gluex_style->SetLabelOffset(0.01,"xyz");   // stop collisions of "0"s at the origin
 	
	// histogram settings
	gluex_style->SetOptStat(0);     // no stats box by default
	gluex_style->SetOptTitle(1);    // no title by default
	gluex_style->SetHistLineWidth(2); 
	gluex_style->SetNdivisions(508,"xyz"); // some ticks were very bunched, lets reduce the number of divisions to label 
	// gluex_style->SetOptFit(0111);

	gluex_style->SetHistFillColor(920);   // grey
	gluex_style->SetPalette(kViridis); // kViridis is perceptually uniform and colorblind friendly
	gluex_style->cd();
}