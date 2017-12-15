#pragma once

enum barwa_e
{
	niezdefiniowany,
	bialy,
	czarny,
	szary,
	zielony,
	czerwony,
	mieszany
};

class Pies
{
public:
	char * imie;
	enum barwa_e barwa;
	int energia;
	Pies();
	Pies(char *);
	Pies(int energia_poczatkowa);
	Pies(int energia_poczatkowa, char * imie);
	Pies(enum barwa_e nowaBarwa, int energia_poczatkowa);
	Pies(const Pies &pies);
	~Pies();
	void setImie(char *);
	void setBarwa(enum barwa_e);
	void Spaceruj(void);
	//void Spaceruj(int minuty);
	//void Spaceruj(double godziny);
	void Spaceruj(int minuty, double godziny = 7);
	void Jedz(void);
	int IleEnergii(void);
};

