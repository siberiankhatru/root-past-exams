#include <TH1.h>
#include <TF1.h>
#include <TCanvas.h>

using namespace std;

void macro()
{
	TH1F* h1 = new TH1F("h1", "Generation", 1000, 0., 5.);
	TF1* f1 = new TF1("f1", "(x*x)/8 * (x>=0 && x<2) + 0.5 * (x>=2 && x<=5)", 0., 5.);
	int n_Tot = 1E8;
	h1->FillRandom("f1", n_Tot);
	/*
	TCanvas* c1 = new TCanvas("c1", "canvas");
	h1->Draw();
	//drawing was not requested in the exam, just a check
	*/
}