#include "LiczbaZespolona.h"


LiczbaZespolona::LiczbaZespolona()
{
	Im = Re = 0.0;
}


LiczbaZespolona::~LiczbaZespolona()
{
}

LiczbaZespolona::LiczbaZespolona(double value)
{
	Im = Re = value;
}

LiczbaZespolona::LiczbaZespolona(double Im, double Re)
{
	this->Im = Im;
	this->Re = Re;
}

LiczbaZespolona::LiczbaZespolona(const LiczbaZespolona & z)
{
	this->Im = z.Im;
	this->Re = z.Re;
}

void LiczbaZespolona::Add(const LiczbaZespolona & z)
{
	this->Im += z.Im;
	this->Re += z.Re;
}

void LiczbaZespolona::Sub(const LiczbaZespolona & z)
{
	this->Im -= z.Im;
	this->Re -= z.Re;
}

void LiczbaZespolona::Mul(const LiczbaZespolona & z)
{
	this->Im *= z.Im;
	this->Re *= z.Re;
}

bool LiczbaZespolona::Eq(const LiczbaZespolona & z)
{
	return this->Im == z.Im && this->Re == z.Re;
}

LiczbaZespolona & LiczbaZespolona::AddTwo(const LiczbaZespolona & z1, const LiczbaZespolona & z2)
{
	this->Im = z1.Im + z2.Im;
	this->Re = z1.Re + z2.Re;
	return *this;
}

LiczbaZespolona & LiczbaZespolona::SubTwo(const LiczbaZespolona & z1, const LiczbaZespolona & z2)
{
	this->Im = z1.Im - z2.Im;
	this->Re = z1.Re - z2.Re;
	return *this;
}

LiczbaZespolona & LiczbaZespolona::MulTwo(const LiczbaZespolona & z1, const LiczbaZespolona & z2)
{
	this->Im = z1.Im * z2.Im;
	this->Re = z1.Re * z2.Re;
	return *this;
}


LiczbaZespolona & LiczbaZespolona::operator=(const LiczbaZespolona & z)
{
	this->Im = z.Im;
	this->Re = z.Re;
	return *this;
}

bool LiczbaZespolona::operator==(const LiczbaZespolona & z)
{
	return this->Im == z.Im && this->Re == z.Re;
}

void LiczbaZespolona::setIm(double Im)
{
	this->Im = Im;
}

void LiczbaZespolona::setRe(double Re)
{
	this->Re = Re;
}

double LiczbaZespolona::getIm(void)
{
	return Im;
}

double LiczbaZespolona::getRe(void)
{
return Re;
}

std::ostream & operator<<(std::ostream & output, const LiczbaZespolona & z)
{
	return output << "z = " << z.Re << " + " << z.Im << "i";
}

std::istream & operator>>(std::istream & input, LiczbaZespolona & z)
{
	input >> z.Re >> z.Im;
	return input;
}

//this is extern function not class method
bool Equal(LiczbaZespolona & z1, LiczbaZespolona & z2)
{
	double z1Im, z1Re, z2Im, z2Re;
	z1Im = z1.getIm();
	z1Re = z1.getRe();
	z2Im = z2.getIm();
	z2Re = z2.getRe();
	return z1Im==z2Im && z1Re==z2Re;	//very error-prone way - because of the double type
}
