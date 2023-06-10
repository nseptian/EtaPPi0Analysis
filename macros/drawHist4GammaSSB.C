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
TString fileName = "4GammaMassEtaPrimePi0_differentGamma3Cuts_SSB.cache.root";
TString outputTag = "4GammaEtaPrimePi0SSBHist";
void drawHist4GammaSSB(){
	gSystem->Exec("mkdir -p plots");

	// gluex_style();
	// gROOT->ForceStyle();	

	// string drawOptions="HIST";

	TFile* f=new TFile(fileName,"READ");
	const Int_t NHist = 54;
	TString hname;
	TH1F *h1[NHist];
	TH1F *h1_total[3][3];
	// TH1F *h1_total[3];
	// Color_t markerColor=1;
	// Int_t totalCounter=0;
	Int_t vectorIndexPermutation[6][2] = {{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
	for (Int_t i=NHist-1;i>=0;i--) {
		if (i<9) hname=Form("FSRootHist:00000%d",i+1);
		else hname=Form("FSRootHist:0000%d",i+1);
		if ((((i+1)%3)==1)) {
			h1[i] = new TH1F(*h1[i+1]);
			h1[i]->Add(h1[i+2]);
		}
		else f->GetObject(hname.Data(),h1[i]);
		// cout << i+1 << endl;
	}
	
	TCanvas *c[3];
	for (Int_t iCanvas=0;iCanvas<3;iCanvas++){
		c[iCanvas] = new TCanvas(Form("c%d",iCanvas+1),Form("c%d",iCanvas+1),800,600);
		c[iCanvas]->Divide(3,2);
	}

	Int_t iPlot=0;
	Color_t markerColor=1;
	for (Int_t iHist=0;iHist<NHist;iHist++){	
		if (iHist%3==0){
			if ((iPlot)%6==0) iPlot=0;
			iPlot++;
		}
		for (Int_t iComposite=0;iComposite<3;iComposite++) {
			if ((iHist+1)%3==iComposite) {
				c[iComposite]->cd(iPlot);
				h1[iHist]->SetMarkerColor(markerColor);
				h1[iHist]->SetLineColor(markerColor);
				h1[iHist]->SetTitle(Form("Selection: #eta' #rightarrow #gamma_{%d}#gamma_{%d} & #pi^{0} #rightarrow #gamma_{%d}#gamma_{%d}",vectorIndexPermutation[iPlot-1][0],vectorIndexPermutation[iPlot-1][1],vectorIndexPermutation[5-(iPlot-1)][0],vectorIndexPermutation[5-(iPlot-1)][1]));
				h1[iHist]->GetXaxis()->SetTitle(Form("m_{#gamma_{%d}#gamma_{%d}#gamma_{%d}#gamma_{%d}} [GeV]",vectorIndexPermutation[iPlot-1][0],vectorIndexPermutation[iPlot-1][1],vectorIndexPermutation[5-(iPlot-1)][0],vectorIndexPermutation[5-(iPlot-1)][1]));
				h1[iHist]->GetYaxis()->SetTitle(Form("Events / %d MeV",(Int_t)(h1[iHist]->GetBinWidth(1)*1000)));
				h1[iHist]->Draw("SAME");
				if (iPlot==1) h1_total[iComposite][markerColor-1] = new TH1F(*h1[iHist]);
				else h1_total[iComposite][markerColor-1]->Add(h1[iHist]);
				cout << iHist+1 << " " << iComposite+1 << " " << iPlot << " " << markerColor << endl;
			}
		}
		// h1_total[markerColor-1]->SetMarkerColor(markerColor);
		// h1_total[markerColor-1]->SetLineColor(markerColor);
		// h1_total[markerColor-1]->SetTitle("");
		// c_total[markerColor-1]->cd();
		// h1_total[markerColor-1]->Draw("SAME");
		if ((iHist+1)%18==0) markerColor++;
	}
	for (Int_t iCanvas=0;iCanvas<3;iCanvas++){
		c[iCanvas]->SaveAs(Form("plots/%s_%d.pdf",outputTag.Data(),iCanvas+1));
	}
	
	TCanvas *c_total[3];
	for (Int_t iCanvas=0;iCanvas<3;iCanvas++){
		c_total[iCanvas] = new TCanvas(Form("c_total%d",iCanvas+1),Form("c_total%d",iCanvas+1),800,600);
	}

	for (Int_t iComposite=0;iComposite<3;iComposite++){
		h1_total[iComposite][0]->GetXaxis()->SetTitle("m_{4#gamma} [GeV]");
		switch(iComposite){
			case 0:
				h1_total[iComposite][0]->SetTitle(Form("Sum of all combinations, weighted sidebands"));
				break;
			case 1:
				h1_total[iComposite][0]->SetTitle(Form("Sum of all combinations, signal + weighted sidebands"));
				break;
			case 2:
				h1_total[iComposite][0]->SetTitle(Form("Sum of all combinations, signal"));
				break;
		}
		for (Int_t iMarkerColor=0;iMarkerColor<3;iMarkerColor++){
			// h1_total[iComposite][iMarkerColor]->SetMarkerColor(iMarkerColor+1);
			// h1_total[iComposite][iMarkerColor]->SetLineColor(iMarkerColor+1);
			// h1_total[iComposite][iMarkerColor]->SetTitle("");
			c_total[iComposite]->cd();
			h1_total[iComposite][iMarkerColor]->Draw("SAME");
		}
		c_total[iComposite]->SaveAs(Form("plots/%s_total_%d.pdf",outputTag.Data(),iComposite+1));
	}

	// c1->SaveAs(Form("plots/%s.pdf",outputTag.Data()));
	// c1->Clear();
	// c1->Divide(1,1);
	// c1->cd(1);
	// h1_total[0]->GetYaxis()->SetRangeUser(0,1.1*h1_total[0]->GetMaximum());
	// h1_total[0]->GetXaxis()->SetTitle("m_{#gamma#gamma} (GeV)");
	// h1_total[0]->SetTitle("Sum of all combinations of #eta' #pi^{0} #rightarrow 4#gamma");
	// for (Color_t iColor=0;iColor<3;iColor++) {
	// 	h1_total[iColor]->SetMarkerColor(iColor+1);
	// 	h1_total[iColor]->SetLineColor(iColor+1);
	// 	h1_total[iColor]->Draw("SAME");
	// }
	// c1->SaveAs(Form("plots/%s_total.pdf",outputTag.Data()));
	// TH2F* h2;
	// TBox* box=new TBox();
	// TCanvas* c=new TCanvas("","",800,600);
}