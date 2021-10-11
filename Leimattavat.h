#pragma once

const float HELSINKIHINTA = 2.80;
const float SEUTUHINTA = 3.40;

enum Matkatyyppi { HELSINKI, SEUTU };

class Leimattavat {
	public:
		virtual bool matkusta(Matkatyyppi matkatyyppi)=0;
		virtual int palautaID()=0;
};
