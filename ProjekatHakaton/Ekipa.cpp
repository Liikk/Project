#include "Ekipa.h"
#include "system.h"
#include <iostream>
#include <cstring>
#include <memory>
#include <vector>
#include <iomanip>

std::vector<Ekipa> ekipe;

Ekipa::Ekipa()
{
	strcpy_s(this->naziv, "Naziv");
	this->brUcesnika = 0;
	this->brojUcesca = 0;
	this->brojPobjeda = 0;
}

void Ekipa::setUcesniciFajl(std::vector<Ucesnik>& ucesnici)
{
	this->ucesnici = ucesnici;
}

void Ekipa::setNazivFajl(char* naziv)
{
	strcpy_s(this->naziv, naziv);
}

void Ekipa::setBrUcesnikaFajl(int n)
{
	this->brUcesnika = n;
}

void Ekipa::setBrPobjeda(int n)
{
	this->brojPobjeda = n;
}

void Ekipa::setBrUcesca(int n)
{
	this->brojUcesca = n;
}

void Ekipa::setNaziv()
{
	char tempNaziv[20];
	// bool jeZauzet = true;
	/*do
	{*/
		std::cout << "\nUnesite naziv Vase ekipe: ";
		std::cin.getline(tempNaziv, 20);
		strcpy_s(this->naziv, tempNaziv);
		/*for (int i = 0; i < ekipe.size(); i++)
		{
			if (ekipe[i].getNaziv() == tempNaziv)
			{
				std::cout << "\nTaj naziv je zauzet molimo unesite drugi!";
			}
			else
			{
				jeZauzet = false;
				strcpy_s(this->naziv, tempNaziv); 
			}
		}*/
	//} while (jeZauzet);
}

void Ekipa::setUcesnici()
{
	std::cout << "\nMolimo postavite Vase clanove tima(ukljucujuci i Vas): ";
	std::shared_ptr<Ucesnik> temp = std::make_shared<Ucesnik>();
	for (int i = 0; i < this->getBrUcesnika(); i++)
	{
		temp->postaviUcesnik();
		this->ucesnici.push_back(*temp);
	}
}

void Ekipa::setBrPobjeda()
{
	bool jeNeispravno = true;
	int temp;
	do
	{
		std::cout << "\nMolimo unesite broj dosadasnjih pobjeda Vaseg tima: ";
		std::cin >> temp;
		std::cin.ignore();
		if (temp < 0)
		{
			std::cout << "\nNemoguce je imati negativan broj pobjeda molimo unesite ispravan broj!";
		}
		else
		{
			jeNeispravno = false;
			this->brojPobjeda = temp;
		}
	} while (jeNeispravno);
}

void Ekipa::setBrUcesca()
{
	bool jeNeispravno = true;
	int temp;
	do
	{
		std::cout << "\nMolimo unesite broj dosadasnjih ucesca Vaseg tima: ";
		std::cin >> temp;
		std::cin.ignore();
		if (temp < 0)
		{
			std::cout << "\nMolimo unesite 0 ili pozitivan broj!";
		}
		else
		{
			jeNeispravno = false;
			this->brojUcesca = temp;
		}
	} while (jeNeispravno);
}

char* Ekipa::getNaziv()
{
	return this->naziv;
}

std::vector<Ucesnik> Ekipa::getUcesnici()
{
	return this->ucesnici;
}

int Ekipa::getBrPobjeda()
{
	return this->brojPobjeda;
}

int Ekipa::getBrUcesca()
{
	return this->brojUcesca;
}

void Ekipa::setBrUcesnika()
{
	int temp = 0;
	bool jeNeispravno = true;
	do
	{
		std::cout << "\nMolimo unesite broj clanova Vase ekipe: ";
		std::cin >> temp;
		std::cin.ignore();
		if (temp > 6 || temp <= 0)
		{
			std::cout << "\nMolimo unesite ispravan broj clanova 1-6!";
		}
		else
		{
			this->brUcesnika = temp;
			jeNeispravno = false;
		}
	} while (jeNeispravno);
}

int Ekipa::getBrUcesnika()
{
	return this->brUcesnika;
}

void Ekipa::pobjedili()
{
	this->brojPobjeda++;
}

void Ekipa::postaviEkipu()
{
	this->setNaziv();
	this->setBrUcesnika();
	this->setUcesnici();
	this->setBrUcesca();
	this->setBrPobjeda();
}

Ekipa::~Ekipa()
{
}

std::ostream& operator<<(std::ostream& stream, Ekipa& e)
{
	stream << std::setw(26) << e.getNaziv() << std::setw(16) << e.getBrUcesnika() << std::setw(16) << e.getBrUcesca() << std::setw(16) << e.getBrPobjeda();
	return stream;
}
