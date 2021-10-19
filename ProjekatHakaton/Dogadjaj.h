#pragma once
#include <fstream>

class Dogadjaj {
public:
	Dogadjaj();
	void setNazivDogadjaja();
	void setLokacija();
	void setDatum();
	void setNazivFajl(char* naziv);
	void setLokacijaFajl(char* lokacija);
	void setDatumFajl(char* datum);
	char* getNazivDogadjaja();
	char* getLokacija();
	char* getDatum();
	friend std::ostream& operator<<(std::ostream& stream, Dogadjaj& d);
	friend std::istream& operator>>(std::istream& stream, Dogadjaj& d);
	~Dogadjaj();
private:
	char nazivDogadjaja[30];
	char lokacija[20];
	char datum[15];
};