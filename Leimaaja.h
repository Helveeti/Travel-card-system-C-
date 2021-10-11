#pragma once
#include "stdafx.h"
#include "Paneeli.h"
#include "Leimaustapahtuma.h"

using namespace std;

class Leimaaja
{
	public:
		Leimaaja();
		~Leimaaja();
		bool leimaa(Leimattavat &kortti, Matkatyyppi matkatyyppi);

		bool operator<<(Leimattavat& kortti);
		bool operator>>(Leimattavat& kortti);

		friend std::ostream& operator<<(std::ostream& out, const Leimaaja& s);

	private:
		Paneeli* paneeli;
		struct tm aikaLeima;
		time_t sekunnit;

		queue<Leimaustapahtuma> lista;
		int index;
};

std::ostream& operator<<(std::ostream& out, const Leimaaja& s);

