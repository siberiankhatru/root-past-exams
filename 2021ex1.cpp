#include <TH1.h>
#include <TRandom.h>
#include <TCanvas.h>

using namespace std;

void macro()
{
	TH1F* h1 = new TH1F("h1", "Population", 4, 0., 4.);
	int n_Tot = 1E5;
	gRandom->SetSeed();
	double value;
	for (int i = 0; i < n_Tot; i++)
	{
		double probability = gRandom->Uniform(0, 1);
		if (probability < 0.125)
		{
			value = 0;
		}
		else if (probability < 0.375)
		{
			value = 1;
		}
		else if (probability < 0.875)
		{
			value = 2;
		}
		else if (probability <= 1)
		{
			value = 3;
		}
		h1->Fill(value);
	}
	/*
	TCanvas* c1 = new TCanvas("c1", "Generation results");
	h1->Draw();
	//drawing was not requested in the exam, just a check
	*/
	int entries = h1->GetEntries();
	cout << "The number of entries is:" << entries << '\n' <<'\n';
	for (int i = 1; i < 5; i++)
	{
		double content = h1->GetBinContent(i) / n_Tot;
		double error = h1->GetBinError(i) / n_Tot;
		cout << "Bin: " << i << '\n' 
			<< "Content: " << content << '\n' 
			<< "Error: " << error << '\n' << '\n';
	}
}