#include "Ucesnik.h"
#include <iostream>
#include <cstring>
#include <iomanip>

Ucesnik::Ucesnik()
{
	strcpy_s(this->ime, "");
	strcpy_s(this->prezime, "");
}



void Ucesnik::setObrazovanje()
{
	//upotreba novog operatora ~Amir,  mislim da ovo treba staviti na 0 i 1 jer enum ide od 0 a ne od 1 ~Lejla
	int unos;
	do
	{
		std::cout << "\nUnesite Vase trenutno obrazovanje:\n\t0-Srednja skola\n\t1-Fakultet\n";
		std::cin >> unos;
		std::cin.ignore();
		if (unos < 0 || unos > 1)
		{
			std::cout << "\nMolimo unesite ili 0 ili 1!";
		}
		else
		{
			this->level = levelObrazovanja(unos);
		}
	} while (this->level < 0 || this->level > 1);
}

void Ucesnik::setObrazovanjeN(int obrazovanjeN)
{
	if (obrazovanjeN == 0)
		this->level = srednjaSkola;
	else
		this->level = fakultet;
}

void Ucesnik::setGrad()
{
	std::cout << "\nUnesite grad iz kojeg dolazite: ";
	std::cin.getline(this->grad, 20);
}

void Ucesnik::setGradN(char* gradN)
{
	strcpy_s(this->grad, gradN);
}

void Ucesnik::setGodiste()
{
	std::cout << "\nUnesite Vase godiste: ";
	std::cin >> this->godiste;
	std::cin.ignore();
}

void Ucesnik::setGodisteN(int godisteN)
{
	this->godiste = godisteN;
}

levelObrazovanja Ucesnik::getObrazovanje()
{
	return this->level;
}

char* Ucesnik::getGrad()
{
	return this->grad;
}

int Ucesnik::getGodiste()
{
	return this->godiste;
}

void Ucesnik::postaviUcesnik()
{
	this->setIme();
	this->setPrezime();
	this->setObrazovanje();
	this->setGrad();
	this->setGodiste();
}

std::ostream& operator<<(std::ostream& stream, Ucesnik& u)
{
	stream << std::left << std::setw(20) << u.getIme() << std::left << std::setw(24) << u.getPrezime() << std::left << std::setw(12) << u.getGodiste() ;
	if (u.getObrazovanje() == srednjaSkola)
	{
		stream << std::left << "Srednja Skola";
	}
	else
	{
		stream << std::left << "Fakultet";
	}
	return stream;
}

std::istream& operator>>(std::istream& is, levelObrazovanja& level)
{
	int obj;
	if (is >> obj)
		level = static_cast<levelObrazovanja>(obj);
	return is;
}

Ucesnik::~Ucesnik()
{
}
