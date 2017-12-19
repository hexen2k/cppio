#pragma once
#ifndef LICZBAZESPOLONA_H
#define LICZBAZESPOLONA_H

#include <iostream>

class LiczbaZespolona
{
private:
	double Im, Re;
public:
	LiczbaZespolona();
	LiczbaZespolona(double value);
	LiczbaZespolona(double Im, double Re);
	LiczbaZespolona(const LiczbaZespolona& z);
	~LiczbaZespolona();
	void Add(const LiczbaZespolona & z1);
	void Sub(const LiczbaZespolona & z1);
	void Mul(const LiczbaZespolona & z1);
	bool Eq(const LiczbaZespolona & z1);
	LiczbaZespolona & AddTwo(const LiczbaZespolona & z1, const LiczbaZespolona & z2);
	LiczbaZespolona & SubTwo(const LiczbaZespolona & z1, const LiczbaZespolona & z2);
	LiczbaZespolona & MulTwo(const LiczbaZespolona & z1, const LiczbaZespolona & z2);
	LiczbaZespolona & LiczbaZespolona::operator=(const LiczbaZespolona & z);
	bool LiczbaZespolona::operator==(const LiczbaZespolona & z);
	void setIm(double Im);
	void setRe(double Re);
	double getIm(void);
	double getRe(void);
	friend std::ostream & operator<<(std::ostream & output, const LiczbaZespolona & z);
	friend std::istream & operator>>(std::istream & input, LiczbaZespolona & z);
};

	bool Equal(LiczbaZespolona & z1, LiczbaZespolona & z2);
#endif // !LICZBAZESPOLONA_H
