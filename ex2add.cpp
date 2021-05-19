#include <TH1.h>
#include <TF1.h>
#include <TRandom.h>
#include <TCanvas.h>

using namespace std;

void macro()
{
	TH1F* pop = new TH1F("pop", "Population", 100, 0., 10.);
	TH1F* acc = new TH1F("acc", "Accepted entries", 100, 0., 10.);
	int nGen = 1E5;
	gRandom->SetSeed();
	TF1* eff = new TF1("eff", "x / 10", 0., 10.);
	for (int i = 0; i < nGen; i++)
	{
		double x = gRandom->Gaus(5., 1.);
		pop->Fill(x);
		double y = gRandom->Uniform(0., 1.);
		if (y < eff->Eval(x))
		{
			acc->Fill(x);
		}
	}
	TH1F* effHisto = new TH1F("effHisto", "Efficiency histogram", 100, 0., 10.);
	effHisto->Divide(acc, pop, 1, 1, "B");
	TCanvas* c = new TCanvas("c", "Canvas");
	c->Divide(3, 1);
	c->cd(1);
	pop->Draw();
	c->cd(2);
	acc->Draw();
	c->cd(3);
	effHisto->Draw();
}