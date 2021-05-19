#include <TH1.h>
#include <TF1.h>
#include <TRandom.h>
#include <TCanvas.h>

using namespace std;

void macro()
{
	TH1F* h1 = new TH1F("h1", "Histogram1", 1000, 0., 5.);
	TH1F* h2 = new TH1F("h2", "Histogram2", 1000, 0., 5.);
	gRandom->SetSeed();
	int nGen = 1E7;
	TF1* f1 = new TF1("f1", "x/[0]", 0., 5.);
	f1->SetParameter(0, 5.);
	for (int i = 0; i < nGen; i++)
	{
		double entry = gRandom->Exp(1);
		h1->Fill(entry);
		double y = gRandom->Uniform(0, 1);
		if (y < f1->Eval(entry))
		{
			h2->Fill(entry);
		}
	}
	TH1F* h3 = new TH1F("h3", "Histogram3", 1000, 0., 5.);
	h3->Divide(h2, h1, 1, 1, "B");
	TCanvas* c1 = new TCanvas("c1", "Canvas");
	/*
	c1->Divide(2, 2);
	c1->cd(1);
	h1->Draw();
	c1->cd(2);
	h2->Draw();
	c1->cd(3);
	f1->Draw();
	c1->cd(4);
	*/
	h3->Draw("E");
}