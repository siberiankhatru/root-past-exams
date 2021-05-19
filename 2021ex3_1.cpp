#include <TH1.h>
#include <TF1.h>
#include <TCanvas.h>

using namespace std;

void macro()
{
	int nGen = 1E8;
	TH1F* h = new TH1F("h", "Histogram", 1000, 0., 5.);
	/*
	//this doesn't work for some stupid ass reason
	Double_t function(Double_t* x, Double_t* par) //boohoo can't define a function here
	{ //fuck off root
		Float_t xx = x[0];
		Double_t result;
		if (xx >= 0 && xx < 2)
		{
			result = (xx * xx) / par[0];
		}
		else if (xx >= 2 && xx <= 5)
		{
			result = par[1];
		}
		return result;
	}
	TF1* f = new TF1("f", function, 0., 5., 2);
	f->SetParameters(8., 0.5);
	*/
	TF1* f = new TF1("f", "(x*x)/[0] * (x>=0&&x<2) + [1] * (x>=2&&x<=5)", 0., 5.);
	f->SetParameters(8., 0.5);
	h->FillRandom("f", nGen);
	TCanvas* c = new TCanvas("c", "Canvas");
	h->Draw();
}