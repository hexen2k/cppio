#pragma once
#ifndef SSAK_H
#define SSAK_H


class Ssak
{
public:
	char * rasa;
	Ssak();
	virtual ~Ssak();
	void Jedz(void);
	virtual void Mow(void) = 0;
};

class Pies : public Ssak
{
public:
	char * imie;
	char * rasa;
	Pies();
	void Mow(void);
};

class Husky : public Pies
{
public:
	void Biegaj(void);
};

class Kot : public Ssak
{
public:
	char * rasa;
	Kot();
	void Mow(void);
};

#endif // !SSAK_H
