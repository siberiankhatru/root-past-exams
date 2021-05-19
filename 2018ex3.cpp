#include <TH1.h>
#include <TRandom.h>
#include <TF1.h>
#include <TMath.h>
#include <TCanvas.h>

using namespace std;

void macro()
{
	TH1F* h1 = new TH1F("h1", "Histogram", 100, 0., 10.);
	int nGen = 1E7;
	TF1* f1 = new TF1("f1", "TMath::Sqrt(x) + (x * x)", 0., 10.);
	h1->FillRandom("f1", nGen);
	TCanvas* c = new TCanvas("c", "Canvas");
	h1->Draw();
}