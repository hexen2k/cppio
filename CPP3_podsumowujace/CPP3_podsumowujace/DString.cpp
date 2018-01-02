#include "DString.h"


DString::DString()
{
	sp = new char[1];
	sp[0] = '\0';
}

DString::DString(const char* s)
{
	int i = 0;
	char * ptmp = (char*)s;
	while (*ptmp++)
	{
		i++;
	}
	sp = new char[i+1];
	for (;i >= 0; i--)
	{
		sp[i] = s[i];
	}
}

DString & DString::operator=(const DString& b)
{
	if (this == &b)
		return *this;
	copy(b);
	return *this;
}

DString::DString(const DString& b)
{
	sp = new char[1];
	sp[0] = '\0';
	copy(b);
}

void DString::copy(const DString& b)
{
	int i = 0;
	char * ptmp = b.sp;
	while (*ptmp++)
	{
		i++;
	}

	delete[] sp;
	sp = new char[i+1];

	for (;i >= 0; i--)
	{
		sp[i] = b.sp[i];
	}
}

int DString::getLen()
{
	int i = 0;
	char * ptmp = sp;
	while (*ptmp++)
	{
		i++;
	}
	return i;
}

DString::~DString()
{
	delete[] sp;
}

ostream& operator<<(ostream& output, DString& obj)
{
	output << obj.sp;
	return output;
}

istream& operator>>(istream& input, DString& obj)
{
	char buf[200];
	input.ignore();	//flush input buffer
	input.getline(buf, sizeof(buf));
	DString tmp(buf);
	obj.copy(tmp);
	return input;
}

DString DString::operator+(const DString& obj) const
{
	int i = 0;
	i += strlen(sp);
	i += strlen(obj.sp);
	char * pstr = new char[i + 1];
	strcpy(pstr, sp);
	strcat(pstr, obj.sp);
	DString tmp(pstr);
	delete[] pstr;
	return tmp;
}

DString DString::operator+(char * str) const
{
	int i = 0;
	i += strlen(sp);
	i += strlen(str);
	char * pstr = new char[i + 1];
	strcpy(pstr, sp);
	strcat(pstr, str);
	DString tmp(pstr);
	delete[] pstr;
	return tmp;
}

DString& DString::operator+=(const DString& obj)
{
	int i = 0;
	i += strlen(sp);
	i += strlen(obj.sp);
	char * pstr = new char[i + 1];
	strcpy(pstr, sp);
	strcat(pstr, obj.sp);
	const DString tmp(pstr);
	copy(tmp);
	delete[] pstr;
	return *this;
}

int DString::operator==(const DString& other)
{
	return	((strcmp(sp, other.sp)) ? 0 : 1);
}

int DString::operator!=(const char*other)
{
	return ((strcmp(sp, other)) ? 1 : 0);
}

char& DString::operator[] (int i)
{
	if(i <= this->getLen())
		return sp[i];
	throw "ERR:PRZEKROCZENIE ZAKRESU OPERATOREM[]";
}

char* DString::asChars()
{
	return sp;
}

int DString::asInt()
{

	for (int i = 0; i < this->getLen(); i++)
	{
		if (!isdigit(sp[i]))
			throw "ERR:KONWERSJA LICZBY NIE POWIODLA SIE";
	}
	return atoi(sp);
}

int DString::empty()
{
	DString tmp;
	this->copy(tmp);
	return 0;
}

int DString::IsEmpty()
{
	return ((this->getLen()) ? 0 : 1);
}

DString::operator const char*()
{
	return sp;
}

DString DString::IsString(char* str)
{
	DString tmp(str);
	if (!strstr(sp, str))
		tmp.empty();
	return tmp;
}

DString DString::GetString(int from, int cnt)
{
	DString tmp;
	if (from + cnt < this->getLen())
	{
		char * pbuf = new char[cnt + 1];
		pbuf[cnt] = '\0';
		tmp = tmp + strncpy(pbuf, &sp[from], cnt);
		delete[] pbuf;
	}
	return tmp;
}

DString DString::TrimRight(int cnt)
{
	int len = this->getLen() - cnt;
	DString tmp;
	if (cnt < this->getLen())
	{
		char * pbuf = new char[len + 1];
		pbuf[len] = '\0';
		tmp = tmp + strncpy(pbuf, sp, len);
		delete[] pbuf;
	}
	return tmp;
}

DString DString::TrimLeft(int cnt)
{
	int len = this->getLen() - cnt;
	DString tmp;
	if (cnt < this->getLen())
	{
		char * pbuf = new char[len + 1];
		pbuf[len] = '\0';
		tmp = tmp + strncpy(pbuf, &sp[cnt], len);
		delete[] pbuf;
	}
	return tmp;
}
