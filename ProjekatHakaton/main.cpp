#include <iostream>
#include <fstream>
#include "system.h"

int main() {
	int izbor;
	ucitajOrganizatore();
	ucitajEkipe();
	ucitajDogadjaj();
	ucitajEkipeDog();

	do {
		system("PAUSE");
		system("CLS");
		std::cout << "\n\tOdaberi vrtu racuna:\n\t0.) Izlaz\n\t1.) Organizator\n\t2.) Posmatrac\n\t3.) Ucesnik\n\tIzbor: ";
		std::cin >> izbor;
		switch (izbor) {
		case 0:
			return 0;
			break;
		case 1:
			organizatorLogIn();
			break;
		case 2:
			posmatracView();
			break;
		case 3:
			ucesnikLogIn(); // samo se ekipa cijela moze prijaviti ne mogu pojedinci, isto i kod logina vazi jedan je naziv ekipe i jedna sifra za ekipu
			break;
		default:
			std::cout << "\nMolimo unesite validnu opciju! ";
		}
	} while (izbor != 0);

	return 0;
}