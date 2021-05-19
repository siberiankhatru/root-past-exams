#include <TH1.h>
#include <TRandom.h>
#include <TMath.h>
#include <TCanvas.h>

using namespace std;

void macro()
{
	TH1F* gaus = new TH1F("gaus", "Gaussian histogram", 1000, 0., 10.);
	TH1F* acc = new TH1F("acc", "Accepted entries", 1000, 0., 10.);
	int nGen = 1E7;
	gRandom->SetSeed();
	TF1* eff = new TF1("eff", "[0] * x * TMath::Exp([1]*x)", 0., 10.);
	eff->SetParameters(0.1, -1.);
	for (int i = 0; i < nGen; i++)
	{
		double entry = gRandom->Gaus(5., 1.);
		gaus->Fill(entry);
		double y = gRandom->Uniform(0., 1.);
		if (y < eff->Eval(entry))
		{
			acc->Fill(entry);
		}
	}
	TH1F* effHisto = new TH1F("effHisto", "Efficiency histogram", 1000, 0., 10.);
	effHisto->Divide(acc, gaus, 1, 1, "B");
	TCanvas* c = new TCanvas("c", "Canvas");
	/*
	c->Divide(2, 2);
	c->cd(1);
	gaus->Draw();
	c->cd(2);
	acc->Draw();
	c->cd(3);
	eff->Draw();
	c->cd(4);
	*/
	effHisto->Draw("E"); //weird graph?? guess it's correct tho
}