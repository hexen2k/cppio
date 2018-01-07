#pragma once
#ifndef OKRAG_H
#define OKRAG_H

const double PI = 3.141592;

class Okrag
{
private:
	double X;
	double R;
public:
	Okrag(double x=0, double r=0) : X(x), R(r) {}
	virtual ~Okrag();
	void SetX(double x) { X = x; }
	void SetR(double r) { R = r; }
	double GetX(void) const { return X; }
	double GetR(void) const { return R; }
	double Obwod(void) const { return 2 * PI * R; }
	bool Przeciecie(const Okrag & okr) const;
	virtual void Wypisz(void) const;
	virtual bool StyczneWewnetrznie(const Okrag & okr) const;
	bool StyczneZewnetrznie(const Okrag & okr) const;
};

class Kolo : public Okrag
{
public:
	Kolo(double x=0, double r=0) : Okrag(x,r) {}
	double Pole(void) const { return PI * GetR() * GetR(); }
	bool StyczneWewnetrznie(const Kolo & kol) const;
	void Wypisz(void) const;
};

class Kula : public Kolo
{
public:
	Kula(double x=0, double r=0) : Kolo(x,r) {}
	double Pole(void) const { return 4.0 * PI*GetR()*GetR(); }
	double Objetosc(void) const { return 4.0 / 3 * PI*GetR()*GetR()*GetR(); }
	void Wypisz(void) const;
};

#endif // !OKRAG_H