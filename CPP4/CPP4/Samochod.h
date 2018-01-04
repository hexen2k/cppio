#pragma once
#include <string>

class Samochod
{
private:
	std::string marka;
	double pojemnosc_baku;
	double predkosc_max;
	double zuzycie_paliwa;
public:
	Samochod(const char * marka_, double pojemnosc_baku_, double predkosc_max_, double zuzycie_paliwa_) : marka(marka_), pojemnosc_baku(pojemnosc_baku_), predkosc_max(predkosc_max_), zuzycie_paliwa(zuzycie_paliwa_) {}
	~Samochod();
	void Jedz(double jakSzybko, double jakDaleko);
};

class Kabriolet : public Samochod
{
private:
	bool dach_otwarty;
public:
	Kabriolet(const char * marka_, double pojemnosc_baku_, double predkosc_max_, double zuzycie_paliwa_) : Samochod(marka_, pojemnosc_baku_, predkosc_max_, zuzycie_paliwa_), dach_otwarty(false) {}
	void otworz_dach(void) { dach_otwarty = true; }
	void zamknij_dach(void) { dach_otwarty = false; }
	void Jedz(double jakSzybko, double jakDaleko);
};
