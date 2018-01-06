#include "zadanie1.h"
#include "Pracownik.h"

void zadanie1(void)
{
	char selected_option = 0;
	int employee_number = 0;
	double total_cost;
	Pracownik * employee[100];

	while (selected_option != 'Q')
	{
		std::cout << "U - nowy urzednik, R - nowy robotnik, W - wyswietl, K - oblicz i wyswietl pensje, Q - koniec programu" << std::endl;
		std::cin >> selected_option;
		switch (selected_option)
		{
		case 'U':
			employee[employee_number] = new Urzednik;
			employee[employee_number]->Wprowadz();
			employee_number++;
			break;
		case 'R':
			employee[employee_number] = new Robotnik;
			employee[employee_number]->Wprowadz();
			employee_number++;
			break;
		case 'W':
			for (int i = 0; i < employee_number; i++)
			{
				employee[i]->Pokaz();
				std::cout << std::endl;
			}
			break;
		case 'K':
			total_cost = 0;
			for (int i = 0; i < employee_number; i++)
			{
				total_cost += employee[i]->KosztMiesieczny();
			}
			std::cout << "Miesieczna kwota na wyplaty dla wszystkich pracownikow: " << total_cost << " zl\n";
			break;
		default:
			break;
		}

	}
}
