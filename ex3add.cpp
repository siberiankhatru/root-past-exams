#include <TH1.h>
#include <TF1.h>
#include <TRandom.h>
#include <TMath.h>
#include <TCanvas.h>

using namespace std;

void macro()
{
	TH1F* gaus = new TH1F("gaus", "Gaussian histogram", 500, 0., 5.);
	TH1F* expo = new TH1F("expo", "Exponential histogram", 500, 0., 5.);
	int nGen1 = 1E6;
	int nGen2 = 1E5;
	gRandom->SetSeed();
	for (int i = 0; i < nGen1; i++)
	{
		double x = gRandom->Gaus(2.5, 0.25);
		gaus->Fill(x);
	}
	for (int i = 0; i < nGen2; i++)
	{
		double x = gRandom->Exp(1);
		expo->Fill(x);
	}
	TH1F* sum = new TH1F("sum", "Sum of the histograms", 500, 0., 5.);
	sum->Add(gaus, expo, 1, 1);
	TF1* fit = new TF1("fit", "[0] * TMath::Gaus(x, [1], [2]) + [3] * TMath::Exp(x * [4])", 0., 5.);
	fit->SetParameters(1, sum->GetMean(), sum->GetRMS(), 1, 1);
	sum->Fit("fit");
	TF1* fitFunc = sum->GetFunction("fit");
	for (int i = 0; i < 5; i++)
	{
		cout << "parameter " << i << ": " << fitFunc->GetParameter(i) << " +/- " << fitFunc->GetParError(i) << '\n';
	}
	cout << "reduced chi square: " << fitFunc->GetChisquare() / fitFunc->GetNDF() << '\n';
	/*
	TCanvas* c = new TCanvas("c", "Canvas");
	sum->Draw();
	*/
}