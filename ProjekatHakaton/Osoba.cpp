#include "Osoba.h"
#include <iostream>

void Osoba::setIme()
{
	std::cout << "\nUnesite ime: ";
	std::cin.getline(this->ime, 30);
}

void Osoba::setIme(char* imeN)
{
	strcpy_s(this->ime, imeN);
}

void Osoba::setPrezime()
{
	std::cout << "\nUnesite prezime: ";
	std::cin.getline(this->prezime, 30);
}

void Osoba::setPrezime(char* prezimeN)
{
	strcpy_s(this->prezime, prezimeN);
}

char* Osoba::getIme()
{
	return this->ime;
}

char* Osoba::getPrezime()
{
	return this->prezime;
}

Osoba::~Osoba()
{
}
