#pragma once
#include <iostream>
#include "Osoba.h"
enum levelObrazovanja { srednjaSkola, fakultet };

class Ucesnik : public Osoba {
public:
	Ucesnik();
	
	void setObrazovanje();
	void setObrazovanjeN(int obrazovanjeN);
	void setGrad();
	void setGradN(char* gradN);
	void setGodiste();
	void setGodisteN(int godisteN);

	levelObrazovanja getObrazovanje();
	char* getGrad();
	int getGodiste();
	void postaviUcesnik();
	friend std::ostream& operator<<(std::ostream& stream, Ucesnik& u);
	friend std::istream& operator>>(std::istream& is, levelObrazovanja& level);
	~Ucesnik();

private:
	/*char ime[30];
	char prezime[30];*/
	char grad[20];
	int godiste;
	levelObrazovanja level;
};

