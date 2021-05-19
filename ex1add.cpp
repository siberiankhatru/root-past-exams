#include <TH1.h>
#include <TF1.h>
#include <TCanvas.h>

using namespace std;

void macro()
{
	TH1F* h = new TH1F("h", "Histogram", 100, 0., 10.);
	int nGen = 1E5;
	TF1* pdf = new TF1("pdf", "x", 0., 10.);
	h->FillRandom("pdf", nGen);
	/*
	TCanvas* c = new TCanvas("c", "Canvas");
	h->Draw();
	*/
}