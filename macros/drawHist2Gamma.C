TString fileName = "histograms/2DAlternative3GammaCuts_etaPrime.cache.root";
TString outputTag = "etaPrimeHist_2DAlternative3GammaCuts";

const Int_t NCombinations = 6;
const Int_t NCuts = 2;
const Int_t NHist = NCombinations*NCuts;
const Bool_t isFitHist = kTRUE;
const Int_t iHistToFit = 1;

void gluex_style();
void drawHist2Gamma(){
	gSystem->Exec("mkdir -p plots");

	gluex_style();
	gROOT->ForceStyle();	

	string drawOptions="HIST";

	TFile* f=new TFile(fileName,"READ");
	TString hname;
	TH1F *h1[NHist];
	TH1F *h1_total[NCuts];
	TCanvas *c1 = new TCanvas("c1","c1",800,600);
	c1->Divide(3,2);
	Color_t markerColor=1;
	Int_t totalCounter=0;
	for (Int_t i=0;i<NHist;i++) {
		if (i<9) hname=Form("FSRootHist:00000%d",i+1);
		else hname=Form("FSRootHist:0000%d",i+1);
		f->GetObject(hname.Data(),h1[i]);
		for (Int_t iCombination=0;iCombination<NCombinations;iCombination++){
			if (((i+1)%6)==iCombination) {

				if ((iCombination)==1) h1_total[totalCounter] = new TH1F(*h1[i]);
				else h1_total[totalCounter]->Add(h1[i]);
				
				if ((iCombination)==0) c1->cd(6);
				else c1->cd(iCombination);
				
				h1[i]->SetMarkerColor(markerColor);
				h1[i]->SetLineColor(markerColor);
				h1[i]->Draw("SAME");
				// cout << i+1 << endl;
				// cout << iCombination << endl;
				if(iCombination==0){
					markerColor++;
					totalCounter++;
				}
			}
		}
	}
	c1->SaveAs(Form("plots/%s.pdf",outputTag.Data()));
	c1->Clear();
	c1->Divide(1,1);
	c1->cd(1);
	h1_total[0]->GetYaxis()->SetRangeUser(0,1.1*h1_total[0]->GetMaximum());
	h1_total[0]->GetXaxis()->SetTitle("m_{#gamma#gamma} (GeV)");
	h1_total[0]->SetTitle("Sum of all combinations of #eta' #rightarrow #gamma #gamma");
	for (Color_t iColor=0;iColor<NCuts;iColor++) {
		h1_total[iColor]->SetMarkerColor(iColor+1);
		h1_total[iColor]->SetLineColor(iColor+1);
		h1_total[iColor]->Draw("SAME");
	}
	TLegend *leg = new TLegend(0.2,0.73,0.45,0.9);
	leg->AddEntry(h1_total[0],"all Base + 2D alternative cuts","lep");
	leg->AddEntry(h1_total[1],"+ 3#gamma cuts","lep");
	// leg->AddEntry(h1_total[2],"+ 2D #pi^{0} #eta alternative cuts","lep");
	// leg->AddEntry(h1_total[3],"+ 2D alternative cuts","lep");
	leg->Draw();
	c1->SaveAs(Form("plots/%s_total.pdf",outputTag.Data()));
	
	//Fit h1_total with gaussian with mean at eta prime mass and polynomial background
	h1_total[iHistToFit]->SetMinimum(0);
	h1_total[iHistToFit]->SetMaximum(1.1*h1_total[iHistToFit]->GetMaximum());
	h1_total[iHistToFit]->GetXaxis()->SetTitle("m_{#gamma#gamma} (GeV)");
	h1_total[iHistToFit]->SetTitle("Sum of all combinations of #eta' #rightarrow #gamma #gamma");
	h1_total[iHistToFit]->SetMarkerColor(1);
	h1_total[iHistToFit]->SetLineColor(1);
	c1->Clear();
	h1_total[iHistToFit]->Draw();
	TF1 *f1 = new TF1("f1","gaus(0)+pol2(3)",0.85,1.05);
	f1->SetParameter(0,1);
	f1->SetParameter(1,0.957);
	f1->SetParameter(2,0.01);
	f1->SetParameter(3,200);
	f1->SetParameter(4,-10);
	f1->SetParameter(5,0);
	h1_total[iHistToFit]->Fit("f1","R");
	f1->SetLineColor(4);
	f1->SetLineStyle(2);
	f1->Draw("SAME");
	//draw the gaussian function from the fit separately from the background
	TF1 *f2 = new TF1("f2","gaus(0)",0.85,1.05);
	f2->SetParameter(0,f1->GetParameter(0));
	f2->SetParameter(1,f1->GetParameter(1));
	f2->SetParameter(2,f1->GetParameter(2));
	f2->SetLineColor(2);
	f2->SetLineStyle(2);
	f2->Draw("SAME");
	//draw the background from the fit separately from the gaussian function
	TF1 *f3 = new TF1("f3","pol2(0)",0.85,1.05);
	f3->SetParameter(0,f1->GetParameter(3));
	f3->SetParameter(1,f1->GetParameter(4));
	f3->SetParameter(2,f1->GetParameter(5));
	f3->SetLineColor(3);
	f3->SetLineStyle(2);
	f3->Draw("SAME");
	cout << "Chi2/NDF = " << f1->GetChisquare()/f1->GetNDF() << endl;
	cout << "Prob = " << f1->GetProb() << endl;
	cout << "Mean = " << f1->GetParameter(1) << endl;
	cout << "Sigma = " << f1->GetParameter(2) << endl;
	cout << "Mean error = " << f1->GetParError(1) << endl;
	cout << "Sigma error = " << f1->GetParError(2) << endl;
	// cout << "Mean pull = " << (f1->GetParameter(1)-0.957)/f1->GetParError(1) << endl;
	// cout << "Sigma pull = " << (f1->GetParameter(2)-0.01)/f1->GetParError(2) << endl;
	// cout << "Mean pull = " << (f1->GetParameter(1)-0.957)/f1->GetParError(1) << endl;
	
	// Calculate the integration of the gaussian function within 3 Sigma region from the fit
	double gausIntegral = f2->Integral(f1->GetParameter(1)-(3*f1->GetParameter(2)),f1->GetParameter(1)+(3*f1->GetParameter(2)));
	// Calculate the integration of the background within 3 Sigma region from the fit
	double backgroundIntegral = f3->Integral(f1->GetParameter(1)-(3*f1->GetParameter(2)),f1->GetParameter(1)+(3*f1->GetParameter(2)));

	// Calculate the signal and background yield per bin width
	double signalYield = gausIntegral/(h1_total[0]->GetBinWidth(1));
	double backgroundYield = backgroundIntegral/(h1_total[0]->GetBinWidth(1));

	// Draw signal yield, background yield, signal to background ratio
	TLatex *tex = new TLatex();
	tex->SetNDC();
	tex->SetTextFont(42);
	tex->SetTextSize(0.04);
	tex->SetTextColor(1);
	tex->SetTextAlign(12);
	tex->DrawLatex(0.25,0.6,Form("S (3#sigma) = %.0f",signalYield));
	tex->DrawLatex(0.25,0.55,Form("B (3#sigma) = %.0f",backgroundYield));
	tex->DrawLatex(0.25,0.5,Form("S/B = %.2f",signalYield/backgroundYield));
	// Draw mean and sigma of the gaussian function
	tex->DrawLatex(0.25,0.7,Form("#mu = %.3f #pm %.3f",f1->GetParameter(1),f1->GetParError(1)));
	tex->DrawLatex(0.25,0.65,Form("#sigma = %.3f #pm %.3f",f1->GetParameter(2),f1->GetParError(2)));

	// tex->DrawLatex(0.2,0.65,Form("S/#sqrt{S+B} = %.2f",gausIntegral/sqrt(gausIntegral+backgroundIntegral)));
	// tex->DrawLatex(0.2,0.6,Form("S/#sqrt{B} = %.2f",gausIntegral/sqrt(backgroundIntegral)));
	
	c1->SaveAs(Form("plots/%s_total_fit_allBase.pdf",outputTag.Data()));

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
