#include <TH1.h>
#include <TRandom.h>

using namespace std;

void macro()
{
	TH1F* h = new TH1F("h", "Histogram", 4, 0., 4.);
	int nGen = 1E6;
	int value;
	gRandom->SetSeed();
	for (int i = 0; i < nGen; i++)
	{
		double probability = gRandom->Uniform(0., 1.);
		if (probability < 0.6)
		{
			value = 0;
		}
		else if (probability < 0.9)
		{
			value = 1;
		}
		else if (probability < 0.99)
		{
			value = 2;
		}
		else
		{
			value = 3
		}
		h->Fill(value);
	}
	for (int i = 0; i < 5; i++)
	{
		cout << "bin " << i << ": " << h->GetBinContent(i) << " +/- " << h->GetBinError(i) << '\n';
	}
}