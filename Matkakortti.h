#pragma once
#include "stdafx.h"
#include "Leimattavat.h"
using namespace std;

class Omistaja
{
public:
	int i;
	shared_ptr<string> omistajanNimi;
	shared_ptr<float> saldo;

	Omistaja() { omistajanNimi.reset(new string); saldo.reset(new float); };
	~Omistaja() { omistajanNimi.reset(); saldo.reset(); };
};

class Lompakko : virtual public Omistaja
{
public:
	int j;

	Lompakko() { *saldo = 0.0; }

	void lataa(float raha) { *saldo += raha; };
	float palautaSaldo() { return *saldo; };
};

class HenkiloKortti : virtual public Omistaja
{
public:
	int k;

	void alusta(string& omistaja) { *omistajanNimi = omistaja; };
	string& palautaNimi() { return *omistajanNimi; };
};

class Matkakortti : public Lompakko, public HenkiloKortti, public Leimattavat
{
public:
	Matkakortti();
	bool matkusta(Matkatyyppi tyyppi);
	int palautaID() { return id; };

	int summa() { return i + j + k; }

	friend std::ostream& operator<<(std::ostream& out, const Matkakortti& s);

private:
	int id;
};

std::ostream& operator<<(std::ostream& out, const Matkakortti& s);

