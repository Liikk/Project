#pragma once 
#include "Ucesnik.h"
#include "Dogadjaj.h"
#include <vector>

class Ekipa {
public:
	Ekipa();
	void setUcesniciFajl(std::vector<Ucesnik>& ucesnici);
	void setNazivFajl(char* naziv);
	void setBrUcesnikaFajl(int n);
	void setBrPobjeda(int n);
	void setBrUcesca(int n);
	void setNaziv();
	void setUcesnici();
	void setBrPobjeda();
	void setBrUcesca();
	char* getNaziv();
	std::vector<Ucesnik> getUcesnici();
	int getBrPobjeda();
	int getBrUcesca();
	void setBrUcesnika();
	int getBrUcesnika();
	void pobjedili();
	void postaviEkipu();
	friend std::ostream& operator<<(std::ostream& stream, Ekipa& e);
	~Ekipa();
private:
	char naziv[20];
	std::vector<Ucesnik> ucesnici;
	int brUcesnika;
	int brojPobjeda;
	int brojUcesca;
};

