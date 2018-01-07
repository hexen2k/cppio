#include <iostream>
#include "Osoba.h"



Osoba::Osoba()
{
	nazwisko = new char[1];
	nazwisko[0] = '\0';
	wiek = 0;
	ParentName[0] = new char[1];
	ParentName[0][0] = '\0';
	ParentName[1] = new char[1];
	ParentName[1][0] = '\0';
}


Osoba::~Osoba()
{
	delete[] nazwisko;
	delete[] ParentName[0];
	delete[] ParentName[1];
}

Osoba::Osoba(const Osoba & os)
{
	nazwisko = new char[strlen(os.nazwisko) + 1];
	strcpy(nazwisko, os.nazwisko);
	wiek = os.wiek;
	ParentName[0] = new char[strlen(os.ParentName[0]) + 1];
	strcpy(ParentName[0], os.ParentName[0]);
	ParentName[1] = new char[strlen(os.ParentName[1]) + 1];
	strcpy(ParentName[1], os.ParentName[1]);
}

Osoba::Osoba(const char * nazwisko_, int wiek_, const char * parent1, const char * parent2)
{
	nazwisko = new char[strlen(nazwisko_) + 1];
	strcpy(nazwisko, nazwisko_);
	wiek = wiek_;
	ParentName[0] = new char[strlen(parent1) + 1];
	strcpy(ParentName[0], parent1);
	ParentName[1] = new char[strlen(parent2) + 1];
	strcpy(ParentName[1], parent2);
}

Osoba & Osoba::operator=(const Osoba & os)
{
	nazwisko = new char[strlen(os.nazwisko) + 1];
	strcpy(nazwisko, os.nazwisko);
	wiek = os.wiek;
	ParentName[0] = new char[strlen(os.ParentName[0]) + 1];
	strcpy(ParentName[0], os.ParentName[0]);
	ParentName[1] = new char[strlen(os.ParentName[1]) + 1];
	strcpy(ParentName[1], os.ParentName[1]);
	return (*this);
}

Osoba Osoba::operator+(const Osoba & os) const
{
	Osoba tmp;
	int stringLength = strlen(nazwisko) + strlen(os.nazwisko) + 2;
	delete[] tmp.nazwisko;
	tmp.nazwisko = new char[stringLength];
	strcpy(tmp.nazwisko, nazwisko);
	tmp.nazwisko[strlen(nazwisko) + 1] = '-';
	strcat(tmp.nazwisko, os.nazwisko);
	tmp.nazwisko[stringLength] = '\0';
	tmp.wiek = wiek;
	delete[] tmp.ParentName[0];
	tmp.ParentName[0] = new char[strlen(os.ParentName[0]) + 1];
	delete[] tmp.ParentName[1];
	tmp.ParentName[1] = new char[strlen(os.ParentName[1]) + 1];
	return tmp;
}

Osoba & Osoba::operator+=(const Osoba & os)
{
	int stringLength = strlen(nazwisko) + strlen(os.nazwisko) + 2;
	char *pstr = new char[stringLength];
	strcpy(pstr, nazwisko);
	pstr[strlen(nazwisko) + 1] = '-';
	strcat(pstr, os.nazwisko);
	delete[] nazwisko;
	nazwisko = new char[stringLength];
	strcpy(nazwisko, pstr);
	delete[] pstr;
	return *this;
}

std::istream & operator>>(std::istream & in, Osoba & os)
{
	char buf[300];
	in.getline(buf,sizeof(buf));
	delete[] os.nazwisko;
	os.nazwisko = new char[strlen(buf) + 1];
	in >> os.wiek;
	in.getline(buf,sizeof(buf));
	delete[] os.ParentName[0];
	os.ParentName[0] = new char[strlen(buf) + 1];
	in.getline(buf,sizeof(buf));
	delete[] os.ParentName[1];
	os.ParentName[1] = new char[strlen(buf) + 1];
	return in;
}

std::ostream & operator<<(std::ostream & out, Osoba & os)
{
	out << os.nazwisko << " wiek: " << os.wiek << os.ParentName[0] << " " << os.ParentName[1];
	return out;
}

void Osoba::PrzedstawSie(void) const
{
	std::cout << "Nazywam sie " << nazwisko << " i mam " << wiek << " lat.";
}

void Student::PrzedstawSie(void) const
{
	std::cout << "Jestem studentem o nazwisku " << GetNazwisko() << " w wieku " << GetWiek() << " lat, o numerze legitymacji: " << numer_legitymacji;
}

void Student::WprowadzSrednieOcen(void)
{
	double srednia;
	for (int i = 0; i < 5; ++i)
	{
		std::cout << "Podaj srednia z " << i + 1 << " roku studiow: ";
		std::cin >> srednia;
		SetSredniaOcen(i, srednia);
	}
}
