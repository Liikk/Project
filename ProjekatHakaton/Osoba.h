#pragma once
class Osoba
{
public:
	char ime[20];
	char prezime[20];
	virtual void setIme();
	virtual void setIme(char* imeN);
	virtual void setPrezime();
	virtual void setPrezime(char* prezimeN);
	virtual char* getIme();
	virtual char* getPrezime();
	virtual ~Osoba();
};