#pragma once
#ifndef DSTRING_H
#define DSTRING_H

#include <iostream>
using namespace std;

class DString
{
protected:
	char* sp;
	void copy(const DString& b); // kopiowanie tekstu
public:
	DString();
	DString(const DString& b);
	DString(const char* s);
	~DString();
	operator const char*(); // operator rzutowanie Dstring na const char*
	DString& operator=(const DString& b); // operator przypisania typu a= b
	friend ostream& operator<<(ostream&, DString&); //operacja typu cout<< a
	friend istream& operator>>(istream&, DString&); // operacja typu cin >> a
	DString operator+(const DString&) const; //operator dodawania a+b
	DString operator+(char*) const; //operator dodawanie typu a+"tekst"
	DString& operator+=(const DString&); // dodawanie typu a = a+b
	int operator==(const DString&other); // operator porownania czy oba teksty sa takie same
	int operator!=(const char*other); // operator porownania czy oba teksty sa rozne
	char& operator[] (int i); // zwraca wybrany zanak z tesktu ->a[3] - czwarty znak w tekscie
	char* asChars(); // metoda zwracajaca dostep do tablicy znakow
	int asInt(); // konwersja z tesktu na int np: "123" da 123 ale "123ala"  nie powinna zwrocic 123 tylko informacje ze nie da sie przeprowadzic konwersji
	int empty(); //czyszczenie tekstu
	int IsEmpty(); // sprawdzanie czy tekst jest pusty
	int getLen(); // dlugosc tekstu
	DString IsString(char*); // szukanie podciagu w teksie w razie znalezienia zwraca jako nowy obiekt
	DString GetString(int, int); // zwraca nowy obiekt zawierajacy wyciety tekst 1 argument - od ktorego znaku, 2 argument ile znakow
	DString TrimRight(int); // obciecie z prawej strony ilosci znakow podanych jako argument
	DString TrimLeft(int); //obciecie z lewej strony ilosc znakow podanych jako argument
};

#endif // !DSTRING_H