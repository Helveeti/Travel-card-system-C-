#include "Leimaustapahtuma.h"

Leimaustapahtuma::Leimaustapahtuma(Leimattavat& leimattavat, Matkatyyppi matkatyyppi, string aikaLeima)
{
	kortti.reset(&leimattavat);
	leima = aikaLeima;

	if (matkatyyppi) {
		tyyppi = "SEUTU";
	}
	else {
		tyyppi = "HELSINKI";
	}
}

Leimaustapahtuma::Leimaustapahtuma(const Leimaustapahtuma& kopio)
{
	kortti = kopio.kortti;
	leima = kopio.leima;
	tyyppi = kopio.tyyppi;
}

Leimaustapahtuma::~Leimaustapahtuma()
{
	//cout << "Leimaustapahtuman osoittimet poistetaan...";
	kortti.reset();
}

string Leimaustapahtuma::leimaus()
{
	string id = to_string(kortti->palautaID());
	return id + "\t | " + leima + "\t" + tyyppi;
}
