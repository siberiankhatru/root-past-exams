#include <TH1.h>
#include <TRandom.h>
#include <TMath.h>
#include <TF1.h>

using namespace std;

void macro()
{
	TH1F* h1 = new TH1F("h1", "Histogram1", 500, 0., 5.);
	TH1F* h2 = new TH1F("h2", "Histogram2", 500, 0., 5.);
	gRandom->SetSeed();
	int nGen1 = 1E6;
	int nGen2 = 1E4;
	for (int i = 0; i < nGen1; i++)
	{
		double entry = gRandom->Gaus(2.5, 0.25);
		h1->Fill(entry);
	}
	for (int i = 0; i < nGen2; i++)
	{
		double entry = gRandom->Uniform(0, 5);
		h2->Fill(entry);
	}
	TH1F* h3 = new TH1F("h3", "Histogram3", 500, 0., 5.);
	h3->Add(h1, h2, 1, 1);
	TF1* f1 = new TF1("f1", "[0] * TMath::Gaus(x, [1], [2]) + [3]");
	f1->SetParameters(1, h3->GetMean(), h3->GetRMS(), 1);
	h3->Fit("f1");
	cout << "parameter 0: " << f1->GetParameter(0) << " +/- " << f1->GetParError(0) << '\n';
	cout << "parameter 1: " << f1->GetParameter(1) << " +/- " << f1->GetParError(1) << '\n';
	cout << "parameter 2: " << f1->GetParameter(2) << " +/- " << f1->GetParError(2) << '\n';
	cout << "parameter 3: " << f1->GetParameter(3) << " +/- " << f1->GetParError(3) << '\n';
	cout << "reduced chi square: " << f1->GetChisquare() / f1->GetNDF() << '\n';
	///*
	TCanvas* c1 = new TCanvas("c1", "Generation results");
	h3->Draw("E");
	//graph not requested, just a check
	//*/
}