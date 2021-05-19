#include <TH1.h>
#include <TRandom.h>
#include <TMath.h>
#include <TF1.h>

using namespace std;

void macro()
{
	TH1F* h1 = new TH1F("h1", "Histogram 1", 100, 0., 5.);
	TH1F* h2 = new TH1F("h2", "Histogram 2", 100, 0., 5.);
	TH1F* h3 = new TH1F("h3", "Histogram 3", 100, 0., 5.);
	gRandom->SetSeed();
	int nGen1 = 1E4;
	int nGen2 = 1E6;
	int nGen3 = 1E5;
	for (int i = 0; i < nGen1; i++) 
	{
		double entry = gRandom->Exp(0.5);
		h1->Fill (entry);
	}
	for (int i = 0; i < nGen2; i++)
	{
		double entry = gRandom->Gaus(2.5, 0.25);
		h2->Fill(entry);
	}
	for (int i = 0; i < nGen3; i++)
	{
		double entry = gRandom->Uniform(0., 5.);
		h3->Fill(entry);
	}
	TH1F* h4 = new TH1F("h4", "Sum", 100, 0., 5.);
	h4->Add(h1, h2, 1, 1);
	h4->Add(h4, h3, 1, 1);
	TF1* f1 = new TF1("f1", "[0] * TMath::Exp(x * [1]) + [2] * TMath::Gaus(x, [3], [4]) + [5]");
	f1->SetParameters(1, 1, 1, h4->GetMean(), h4->GetRMS(), 1);
	h4->Fit("f1");
	TF1* fitFunc = h4->GetFunction("f1");
	cout << "gaussian mean: " << fitFunc->GetParameter(3) << " +/- " << fitFunc->GetParError(3) << '\n';
	cout << "gaussian standard deviation: " << fitFunc->GetParameter(4) << " +/- " << fitFunc->GetParError(4) << '\n';
	double rX2 = fitFunc->GetChisquare() / fitFunc->GetNDF();
	cout << "reduced chi square: " << rX2 << '\n';
	//weird fit parameters?? chi square is ridiculously high?? rms is negative?? what the fuck??
	///*
	TCanvas* c1 = new TCanvas("c1", "Generation results");
	h4->Draw();
	//graph not requested, just a check
	//*/
}