#pragma once
#include <iostream>
#include <string>

class Pracownik
{
protected:
	std::string Nazwisko;
	double Pensja;
public:
	Pracownik();
	~Pracownik();
	virtual double KosztMiesieczny(void) = 0;
	virtual void Wprowadz(void) = 0;
	virtual void Pokaz(void) = 0;
};

class Urzednik : public Pracownik
{
private:
	double Premia;
public:
	double KosztMiesieczny(void);
	void Wprowadz(void);
	void Pokaz(void);
};

class Robotnik : public Pracownik
{
private:
	double Premia;
public:
	double KosztMiesieczny(void);
	void Wprowadz(void);
	void Pokaz(void);
};
