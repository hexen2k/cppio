#pragma once
#include <iostream>

class Zespolona
{
	double re, im;
public:
	Zespolona();
	~Zespolona();
	friend std::ostream& operator<< (std::ostream&, const Zespolona&);
	Zespolona operator+(const Zespolona&);
	Zespolona operator+=(const Zespolona&);
	Zespolona operator*(const Zespolona&);
	Zespolona& operator=(const Zespolona&);
};
