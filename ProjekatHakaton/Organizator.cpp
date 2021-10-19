#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Ucesnik.h"
#include "Organizator.h"
#include "Ekipa.h"
#include "Dogadjaj.h"

std::vector<Organizator> organizatori;

Organizator::Organizator()
{

}

void Organizator::setKljuc(int kljuc)
{
	this->sigurnosniKljuc = kljuc;
}

void Organizator::setTitula(char* titula)
{
	strcpy_s(this->titula, titula);
}

char* Organizator::getTitula()
{
	return this->titula;
}
int Organizator::getKljuc()
{
	return this->sigurnosniKljuc;
}

void Organizator::dodajEkipu(std::vector<Ekipa>& ekipe)
{
	Ekipa temp;
	temp.postaviEkipu();
	ekipe.push_back(temp);
}

void Organizator::izbaciEkipu(std::vector<Ekipa>& ekipe)
{
	int indeks = 0;
	std::cout << "\nRB. Ekipe\tNaziv:\t\tBroj clanova\tBr ucesca\tBr pobjeda";
	std::cout << "\n---------------------------------------------------------------------------------";

	for (int i = 0; i < ekipe.size(); i++)
	{
		std::cout << "\n" << i + 1 << "\t\t";
		std::cout << ekipe[i];
	}
	std::cout << "\n";
	std::cout << "\nOdaberite ekipu za koju zelite glasati: ";
	std::cin >> indeks;
	std::cin.ignore();
	indeks--; // jer ispisuje za jedan vece
	ekipe.erase(ekipe.begin() + indeks);
	std::cout << "\nEkipa uspjesno izbacena\n";
}


void Organizator::dodajDogadjaj(std::vector<Dogadjaj>& dog)
{
	Dogadjaj temp;
	std::cin >> temp;
	dog.push_back(temp);
}

Organizator::~Organizator()
{

}

std::ostream& operator<<(std::ostream& stream, Organizator& o)
{
	stream << "\n"<<std::setw(20) <<std::left<< o.getIme() << std::left << std::setw(23) << o.getPrezime() <<std::setw(16)<< std::left << o.getTitula();
	return stream;
}
