#pragma once 
#include <vector>
#include "Ekipa.h"
#include "Osoba.h"

class Organizator : public Osoba {
private:
    int sigurnosniKljuc;
    char titula[10];

public:
    Organizator();
    void setKljuc(int kljuc);
    void setTitula(char* titula);
    char* getTitula();
    int getKljuc();
    void dodajEkipu(std::vector<Ekipa>& ekipe);
    void izbaciEkipu(std::vector<Ekipa>& ekipe);
    void dodajDogadjaj(std::vector<Dogadjaj>& dog);
    friend std::ostream& operator<<(std::ostream& stream, Organizator& o);
    ~Organizator();
};