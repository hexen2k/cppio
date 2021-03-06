#include <iostream>

template <typename T>
T minimum_z_tablicy(const T * pTstart,const T * pTend)
{
	T minimum = *pTstart;
	while (pTstart < pTend)
	{
		if (minimum > *pTstart)
		{
			minimum = *pTstart;
		}
		pTstart++;
	}
	return minimum;
}

//based on pointer
template <typename T, int count>
class Tablica
{
	T * tab;
public:
	Tablica(){ tab = new T[count]; }
	~Tablica(){ delete[] tab; }
	void set(int index, T item) { *(tab + index) = item; }
	T get(int index) { return *(tab + index); }
};

//based on table
template <typename T, int count>
class Tablica2
{
	T tab[count];
public:
	void set(int index, T item) { tab[index] = item; }
	T get(int index) { return tab[index]; }
};

int main()
{
	int tab[4];
	tab[0] = 0;
	tab[1] = 33;
	tab[2] = 147;
	tab[3] = 2;
	int m = minimum_z_tablicy(tab, tab + sizeof(tab) / sizeof(*tab));
	std::cout << m << std::endl;
	Tablica<int, 10> t;
	t.set(0, 77);
	t.set(9, 13);
	std::cout << t.get(9) << '\n';
	std::cout << sizeof(t) << '\n';
//another way
	Tablica2<int, 10> t2;
	t2.set(0, 77);
	t2.set(9, 14);
	std::cout << t2.get(9) << '\n';
	std::cout << sizeof(t2) << '\n';
	system("pause");
    return 0;
}
