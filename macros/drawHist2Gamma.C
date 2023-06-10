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
TString fileName = "histograms/GammaGammaMass_etaPrime.root";
TString outputTag = "etaPrimeHist";
void drawHist2Gamma(){
	gSystem->Exec("mkdir -p plots");

	gluex_style();
	gROOT->ForceStyle();	

	string drawOptions="HIST";

	TFile* f=new TFile(fileName,"READ");
	const Int_t NHist = 18;
	TString hname;
	TH1F *h1[NHist];
	TH1F *h1_total[3];
	TCanvas *c1 = new TCanvas("c1","c1",800,600);
	c1->Divide(3,2);
	Color_t markerColor=1;
	Int_t totalCounter=0;
	for (Int_t i=0;i<NHist;i++) {
		if (i<9) hname=Form("FSRootHist:00000%d",i+1);
		else hname=Form("FSRootHist:0000%d",i+1);
		f->GetObject(hname.Data(),h1[i]);
		if (((i+1)%6)==1) {
			c1->cd(1);
			h1[i]->SetMarkerColor(markerColor);
			h1[i]->SetLineColor(markerColor);
			h1[i]->Draw("SAME");
			h1_total[totalCounter] = new TH1F(*h1[i]);
			// cout << i+1 << endl;
		}
		if (((i+1)%6)==2) {
			c1->cd(2);
			h1[i]->SetMarkerColor(markerColor);
			h1[i]->SetLineColor(markerColor);
			h1[i]->Draw("SAME");
			h1_total[totalCounter]->Add(h1[i]);
		}
		if (((i+1)%6)==3) {
			c1->cd(3);
			h1[i]->SetMarkerColor(markerColor);
			h1[i]->SetLineColor(markerColor);
			h1[i]->Draw("SAME");
			h1_total[totalCounter]->Add(h1[i]);
		}
		if (((i+1)%6)==4) {
			c1->cd(4);
			h1[i]->SetMarkerColor(markerColor);
			h1[i]->SetLineColor(markerColor);
			h1[i]->Draw("SAME");
			h1_total[totalCounter]->Add(h1[i]);
		}
		if (((i+1)%6)==5) {
			c1->cd(5);
			h1[i]->SetMarkerColor(markerColor);
			h1[i]->SetLineColor(markerColor);
			h1[i]->Draw("SAME");
			h1_total[totalCounter]->Add(h1[i]);
		}
		if (((i+1)%6)==0) {
			c1->cd(6);
			h1[i]->SetMarkerColor(markerColor);
			h1[i]->SetLineColor(markerColor);
			h1[i]->Draw("SAME");
			h1_total[totalCounter]->Add(h1[i]);
			markerColor++;
			totalCounter++;
		}
	}
	c1->SaveAs(Form("plots/%s.pdf",outputTag.Data()));
	c1->Clear();
	c1->Divide(1,1);
	c1->cd(1);
	h1_total[0]->GetYaxis()->SetRangeUser(0,1.1*h1_total[0]->GetMaximum());
	h1_total[0]->GetXaxis()->SetTitle("m_{#gamma#gamma} (GeV)");
	h1_total[0]->SetTitle("Sum of all combinations of #eta' #rightarrow #gamma #gamma");
	for (Color_t iColor=0;iColor<3;iColor++) {
		h1_total[iColor]->SetMarkerColor(iColor+1);
		h1_total[iColor]->SetLineColor(iColor+1);
		h1_total[iColor]->Draw("SAME");
	}
	c1->SaveAs(Form("plots/%s_total.pdf",outputTag.Data()));
	// TH2F* h2;
	// TBox* box=new TBox();
	// TCanvas* c=new TCanvas("","",800,600);
}