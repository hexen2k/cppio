#include "Zespolona.h"


Zespolona::Zespolona()
{
	re = 1.2;
	im = 3.4;
}


Zespolona::~Zespolona()
{
}

std::ostream& operator<< (std::ostream &output, const Zespolona &s)
{
	return output << "z = " << s.re << " + " << s.im << " i ";
}


Zespolona Zespolona::operator+(const Zespolona& z)
{
	Zespolona zz;
	zz.re += z.re;
	zz.im += z.im;
	return zz;
}

Zespolona Zespolona::operator+=(const Zespolona& z)
{
	this->re += z.re;
	this->im += z.im;
	return *this;
}

Zespolona Zespolona::operator*(const Zespolona& z)
{
	Zespolona zz = *this;
	zz.re *= z.re;
	zz.im *= z.im;
	return zz;
}

Zespolona& Zespolona::operator=(const Zespolona& z)
{
	this->im = z.im;
	this->re = z.re;
	return *this;
}
