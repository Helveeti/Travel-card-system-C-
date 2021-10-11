#include "Matkakortti.h"

Matkakortti::Matkakortti()
{
	id = rand() % 900 + 100;
}

bool Matkakortti::matkusta(Matkatyyppi tyyppi)
{
	if (!tyyppi && HELSINKIHINTA < *saldo) {
		*saldo -= HELSINKIHINTA;
		return true;
	}
	else if (tyyppi && SEUTUHINTA < *saldo) {
		*saldo -= SEUTUHINTA;
		return true;
	}

	return false;
}

std::ostream& operator<<(std::ostream& out, const Matkakortti& s)
{
	out << "\nKortin id: " << s.id << "\n\t\tOmistajan nimi: " << *s.omistajanNimi << "\tKortin saldo: " << *s.saldo;
	return out;
}
