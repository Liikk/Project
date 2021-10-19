#include "Dogadjaj.h"
#include "system.h"
#include <vector>
#include <iostream>
#include <iomanip>

std::vector<Dogadjaj> dogadjaji;

Dogadjaj::Dogadjaj()
{
}

void Dogadjaj::setNazivDogadjaja()
{
	char tempNaziv[30];
	bool jeZauzet = true;
	do
	{
		std::cout << "\nUnesite naziv dogadjaja: ";
		std::cin.getline(tempNaziv, 30);
		for (int i = 0; i < dogadjaji.size(); i++)
		{
			if (dogadjaji[i].getNazivDogadjaja() == tempNaziv)
			{
				std::cout << "\nTaj naziv je zauzet molimo unesite drugi!";
			}
			else
			{
				jeZauzet = false;
				strcpy_s(this->nazivDogadjaja, tempNaziv);
			}
		}
	} while (jeZauzet);
}

void Dogadjaj::setLokacija()
{
	char tempNaziv[20];
	std::cout << "\nUnesite lokaciju dogadjaja: ";
	std::cin.getline(tempNaziv, 20);
	strcpy_s(this->lokacija, tempNaziv);
}

void Dogadjaj::setDatum()
{
	char tempDatum[15];
	std::cout << "\nUnesite datum dogadjaja u formatu 'dd.mm.gggg.': ";
	std::cin.getline(tempDatum, 15); //treba ubacit provjeru jel unesen ispravan datum
	strcpy_s(this->datum, tempDatum);
}

void Dogadjaj::setNazivFajl(char* naziv)
{
	strcpy_s(this->nazivDogadjaja, naziv);
}

void Dogadjaj::setLokacijaFajl(char* lokacija)
{
	strcpy_s(this->lokacija, lokacija);
}

void Dogadjaj::setDatumFajl(char* datum)
{
	strcpy_s(this->datum, datum);
}

char* Dogadjaj::getNazivDogadjaja()
{
	return this->nazivDogadjaja;
}

char* Dogadjaj::getLokacija()
{
	return this->lokacija;
}

char* Dogadjaj::getDatum()
{
	return this->datum;
}

Dogadjaj::~Dogadjaj()
{
}

std::ostream& operator<<(std::ostream& stream, Dogadjaj& d)
{
	stream << std::left << std::setw(30) << d.getNazivDogadjaja() << std::left << std::setw(24) << d.getLokacija() << "\t" << std::left << std::setw(15) << d.getDatum();
	return stream;
}

std::istream& operator>>(std::istream& stream, Dogadjaj& d)
{
	d.setNazivDogadjaja();
	d.setDatum();
	d.setLokacija();
	return stream;
}
