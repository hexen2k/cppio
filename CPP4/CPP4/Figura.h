#pragma once
#include <string>

class Figura
{
public:
	Figura();
	~Figura();
	std::string nazwa(void);
	double pole(void);
	void wypisz(void);
	
};

class Kolo : public Figura
{
	double r;
public:
	void ustawPromien(double r_) { r = r_; }
	double promien(void) { return r; }
};
