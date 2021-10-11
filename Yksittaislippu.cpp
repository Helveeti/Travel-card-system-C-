#include "Yksittaislippu.h"

Yksittaislippu::Yksittaislippu(Matkatyyppi matkatyyppi)
{
	tyyppi = matkatyyppi;
	used = false;
	id = rand() % 100 + 1;
}

bool Yksittaislippu::matkusta(Matkatyyppi matkatyyppi)
{
	if (tyyppi == matkatyyppi && !used) {
		used = true;
		//cout << "Matkan tyyppi täsmää.";
		return true;
	}
	else if (!used){
		//cout << "Matkan tyyppi ei täsnää.";
		return false;
	}

	return false;
}

std::ostream& operator<<(std::ostream& out, const Yksittaislippu& s)
{
	string lippu;

	if (s.tyyppi) lippu = "SEUTU";
	else lippu = "HELSINKI";

	out << "Lipun tyyppi:\t" << lippu;
	return out;
}
