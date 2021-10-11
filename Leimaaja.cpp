#include "Leimaaja.h"

Leimaaja::Leimaaja()
{
	sekunnit = 0;
	aikaLeima = {0};
	index = 0;

	Paneeli* paneeli = new Paneeli;
}

Leimaaja::~Leimaaja()
{
	cout << "Leimaajan tiedot poistetaan...";

	delete paneeli;
}

bool Leimaaja::leimaa(Leimattavat &kortti, Matkatyyppi matkatyyppi)
{
	Leimattavat* ptr = &kortti;

	if (!ptr->matkusta(matkatyyppi))
	{
		paneeli->valo(false);
		return false;
	}
	else
	{
		time(&sekunnit);
		localtime_s(&aikaLeima, &sekunnit);

		string aika = to_string(aikaLeima.tm_hour) + ":" + to_string(aikaLeima.tm_min) + ":" + to_string(aikaLeima.tm_sec);
		Leimaustapahtuma leimaus(*ptr, matkatyyppi, aika);
		lista.push(leimaus);

		paneeli->valo(true);
		return true;
	}
}

std::ostream& operator<<(std::ostream& out, const Leimaaja& s)
{
	queue<Leimaustapahtuma> copy = s.lista;
	int size = 0;

	if (copy.size() >= 5) size = 5;
	else size = (int) copy.size();

	for (int i = 1; i <= size; i++) {
		out << "\t" << i << ". " << copy.front().leimaus() << "\n";
		copy.pop();
	}

	return out;
}

bool Leimaaja::operator<<(Leimattavat& kortti)
{
	return leimaa(kortti, HELSINKI);
}

bool Leimaaja::operator>>(Leimattavat& kortti)
{
	return leimaa(kortti, SEUTU);
}
