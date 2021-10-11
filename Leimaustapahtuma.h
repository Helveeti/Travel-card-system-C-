#pragma once

#include "stdafx.h"
#include "Leimattavat.h"

using namespace std;

class Leimaustapahtuma
{
	public:
		Leimaustapahtuma(Leimattavat &leimattavat, Matkatyyppi tyyppi, string aikaLeima);
		Leimaustapahtuma(const Leimaustapahtuma& kopio);
		~Leimaustapahtuma();
		string leimaus();

	private:
		shared_ptr<Leimattavat> kortti;
		string leima, tyyppi;
};

