#pragma once
#include <iostream>

class Osoba
{
private:
	char * nazwisko;
	int wiek;
	char * ParentName[2];	//tablica imion rodzicow
public:
	Osoba();
	~Osoba();
	Osoba(const Osoba & os);
	Osoba(const char * nazwisko_, int wiek_, const char * parent1 = "", const char * parent2 = "");
	Osoba & operator=(const Osoba & os);
	Osoba operator+(const Osoba & os) const;
	Osoba & operator+=(const Osoba & os);
	const char * GetNazwisko(void) const { return nazwisko; }
	const int GetWiek(void) const { return wiek; }
	const char * GetParentName1(void) const { return ParentName[0]; }
	const char * GetParentName2(void) const { return ParentName[1]; }
	friend std::istream & operator>>(std::istream & in, Osoba & os);
	friend std::ostream & operator<<(std::ostream & out, Osoba & os);
	virtual void PrzedstawSie(void) const;
};

class Student : public Osoba
{
private:
	int numer_legitymacji;
	double sredniaOcen[5];
public:
	Student(const char * nazwisko_, int wiek_, int numer_legitymacji_, const char * parent1 = "", const char * parent2 = "") : Osoba(nazwisko_,wiek_,parent1,parent2), numer_legitymacji(numer_legitymacji_) {}
	int GetNumerLegitymacji(void) const { return numer_legitymacji; }
	void SetNumerLegitymacji(int nr) { numer_legitymacji = nr; }
	double GetSredniaOcen(int nr) const { return sredniaOcen[nr]; }
	void SetSredniaOcen(int nr, double val) { sredniaOcen[nr] = val; }
	void PrzedstawSie(void) const;
	void WprowadzSrednieOcen(void);
};

