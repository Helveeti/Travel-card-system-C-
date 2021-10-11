#pragma once
#include "stdafx.h"
#include "Leimattavat.h"

using namespace std;

class Yksittaislippu: public Leimattavat
{
	public:
		Yksittaislippu(Matkatyyppi matkatyyppi);
		bool matkusta(Matkatyyppi matkatyyppi);
		int palautaID() { return id; };

		friend std::ostream& operator<<(std::ostream& out, const Yksittaislippu& s);

	private:
		Matkatyyppi tyyppi;
		bool used;
		int id;
};

std::ostream& operator<<(std::ostream& out, const Yksittaislippu& s);

