#include <TH1.h>
#include <TRandom.h>
#include <TMath.h>
#include <TF1.h>

using namespace std;

void macro()
{
	TH1F* gaus = new TH1F("gaus", "Gaussian generation", 500, 0., 5.);
	TH1F* expo = new TH1F("expo", "Exponential generation", 500, 0., 5.);
	int nGenGaus = 1E6;
	gRandom->SetSeed();
	for (int i = 0; i < nGenGaus; i++)
	{
		double x = gRandom->Gaus(2., 0.5);
		gaus->Fill(x);
	}
	int nGenExp = 1E5;
	for (int i = 0; i < nGenExp; i++)
	{
		double x = gRandom->Exp(1);
		expo->Fill(x);
	}
	TH1F* sum = new TH1F("sum", "Sum histogram", 500, 0., 5.);
	sum->Add(gaus, expo, 1, 1);
	TF1* fit = new TF1("fit", "[0] * TMath::Gaus(x, [1], [2]) + [3] * TMath::Exp([4] * x)", 0., 5.);
	fit->SetParameters(1, sum->GetMean(), sum->GetRMS(), 1, 1);
	sum->Fit("fit");
	TF1* fitFunc = sum->GetFunction("fit");
	for (int i = 0; i < 5; i++)
	{
		cout << "parameter " << i << ": " << fitFunc->GetParameter(i) << " +/- " << fitFunc->GetParError(i) << '\n';
	}
	double rX2 = fitFunc->GetChisquare() / fitFunc->GetNDF();
	cout << "reduced chi square: " << rX2 << '\n'; //why is the chi square fucking 90
}