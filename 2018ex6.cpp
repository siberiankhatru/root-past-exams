#include <TH1.h>
#include <TF1.h>
#include <TCanvas.h>

using namespace std;

void macro()
{
	TH1F* h = new TH1F("h", "Histogram", 100, 0., 10.);
	TF1* pdf = new TF1("pdf", "TMath::Sin(x) + x * x");
	int nGen = 1E5;
	h->FillRandom("pdf", nGen);
	/*
	TCanvas* c = new TCanvas("c", "Canvas");
	h->Draw();
	*/
}