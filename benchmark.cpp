#include <TH1.h>
#include <TRandom.h>
#include <TBenchmark.h>

using namespace std;

void benchmark()
{
	TH1F* h1 = new TH1F("h1", "Histogram1", 1000, -5., 5.);
	int nGen = 1E5;
	gBenchmark->Start("Explicit generation");
	gRandom->SetSeed();
	for (int i = 0; i < nGen; i++)
	{
		double x = gRandom->Gaus(0., 1.);
		h1->Fill(x);
	}
	gBenchmark->Show("Explicit generation");
	TH1F* h2 = new TH1F("h2", "Histogram2", 1000, -5, 5);
	gBenchmark->Start("FillRandom");
	h2->FillRandom("gaus", nGen);
	gBenchmark->Show("FillRandom");
}