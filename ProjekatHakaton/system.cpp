#include "system.h"
#include <string>

extern std::vector<Ekipa> ekipe;
extern std::vector<Dogadjaj> dogadjaji;
extern std::vector<Organizator> organizatori;
std::vector<int*> ekipeDogadjaji;

void ucitajOrganizatore()
{
	std::ifstream organizatoriFile("infoorganizatori.txt");
	char tempIme[20], tempPrezime[20], tempTitula[10];
	int tempKljuc;
	Organizator temp;
	if (organizatoriFile.is_open())
	{
		for (int i = 0; i < 5; i++)
		{
			organizatoriFile >> tempIme >> tempPrezime >> tempKljuc >> tempTitula;
			temp.setIme(tempIme);
			temp.setPrezime(tempPrezime);
			temp.setKljuc(tempKljuc);
			temp.setTitula(tempTitula);
			organizatori.push_back(temp);
		}
	}
	else
	{
		std::cout << "\nGreska!\nDatoteka nije otvorena!";
	}
}

void ucitajDogadjaj() {

	std::ifstream dogadjajiFile("infodogadjaji.txt");
	char tempLokacija[20], tempNaziv[50], tempDatum[15];
	Dogadjaj temp;
	if (dogadjajiFile.is_open())
	{
		while (dogadjajiFile >> tempNaziv)
		{
			dogadjajiFile >> tempLokacija >> tempDatum;
			temp.setNazivFajl(tempNaziv);
			temp.setDatumFajl(tempDatum);
			temp.setLokacijaFajl(tempLokacija);
			dogadjaji.push_back(temp);
		}
	}
	else
	{
		std::cout << "\nGreska!\nDatoteka nije otvorena!";
	}
}

void ucitajEkipe()
{
	char tempNaziv[20];
	int tempBrojUcesnika=0, tempBrojPobjeda=0, tempBrojUcesca=0;
	Ekipa tempE;
	Ucesnik tempU;
	std::vector<Ucesnik> tempUcesnici;
	char tempIme[30], tempPrezime[30], tempGrad[20];
	int tempGodiste;
	int tempLevel;
	std::ifstream ekipeFile("infoekipe.txt");
	if (ekipeFile.is_open())
	{
		while (ekipeFile >> tempNaziv)
		{
			tempBrojUcesnika = 0;
			tempBrojPobjeda = 0;
			tempBrojUcesca = 0;
			
			ekipeFile >> tempBrojUcesnika >> tempBrojUcesca >> tempBrojPobjeda;
			for (int j = 0; j < tempBrojUcesnika; j++)
			{
				ekipeFile >> tempIme >> tempPrezime >> tempGodiste >> tempGrad >> tempLevel;
				tempU.setGodisteN(tempGodiste);
				tempU.setGradN(tempGrad);
				tempU.setIme(tempIme);
				tempU.setObrazovanjeN(tempLevel);
				tempU.setPrezime(tempPrezime);
				tempUcesnici.push_back(tempU);
			}
			tempE.setUcesniciFajl(tempUcesnici);
			tempE.setNazivFajl(tempNaziv);
			tempE.setBrUcesnikaFajl(tempBrojUcesnika);
			tempE.setBrUcesca(tempBrojUcesca);
			tempE.setBrPobjeda(tempBrojPobjeda);
			ekipe.push_back(tempE);
		}
	}
	else
		std::cout << "\nGreska!\nDatoteka nije otvorena!";
	
	ekipeFile.close();
}

void ucitajEkipeDog()
{
	int tempIndeks = 0;
	int tempSize = 0;
	int* niz;
	std::ifstream ekipeDogFile("infoekipedogadjaji.txt");
	
	if (ekipeDogFile.is_open())
	{
		while (ekipeDogFile >> tempIndeks)
		{
			ekipeDogFile >> tempSize;
			niz = new int[tempSize];
			niz[0] = tempIndeks;
			niz[1] = tempSize;
			for (int i = 2; i < (tempSize + 2); i++)
			{
				ekipeDogFile >> tempIndeks;
				niz[i] = tempIndeks;
			}
			ekipeDogadjaji.push_back(niz);
		}
	}
	else
	{
		std::cout << "\nGreska!\nDatoteka nije otvorena!";
	}
	ekipeDogFile.close();
}

void saveInfo() {
	std::ofstream finalniFile("infoekipe.txt");
	for (int i = 0; i < ekipe.size(); i++)
	{
		finalniFile << ekipe[i].getNaziv() << " " << ekipe[i].getBrUcesnika() << " " << ekipe[i].getBrUcesca() << " " << ekipe[i].getBrPobjeda() << " ";

		for (int j = 0; j < ekipe[i].getBrUcesnika(); j++)
		{
			finalniFile << " " << ekipe[i].getUcesnici()[j].getIme() << " " << ekipe[i].getUcesnici()[j].getPrezime() << " " << ekipe[i].getUcesnici()[j].getGodiste() << " " << ekipe[i].getUcesnici()[j].getGrad();
			if (ekipe[i].getUcesnici()[j].getObrazovanje() == srednjaSkola)
			{
				finalniFile << " 0";
			}
			else
			{
				finalniFile << " 1";
			}
		}
		finalniFile << "\n";
	}
	finalniFile.close();
}

void saveInfoDog() {
	std::ofstream finalniFile("infodogadjaji.txt");
	for (int i = 0; i < dogadjaji.size(); i++)
	{
		finalniFile << dogadjaji[i].getNazivDogadjaja() << " " << dogadjaji[i].getLokacija() << " " << dogadjaji[i].getDatum() << "\n";
	}
	finalniFile.close();
}

void saveInfoEkipeDog()
{
	std::ofstream finalniFile("infoekipedogadjaji.txt");
	int* niz;
	int velicina = 0;
	for (int i = 0; i < ekipeDogadjaji.size(); i++)
	{
		niz = ekipeDogadjaji[i];
		velicina = niz[1] + 2;
		for (int j = 0; j < velicina; j++)
		{
			finalniFile << niz[j] << " ";
		}
		finalniFile << "\n";
	}
	finalniFile.close();
}

void vidiEkipe() {
	std::cout << "\nRB. Ekipe\tNaziv\t\t\tBr clanova\tBr ucesca\tBr pobjeda";
	std::cout << "\n---------------------------------------------------------------------------------";

	for (int i = 0; i < ekipe.size(); i++)
	{
		std::cout << "\n" << std::left << std::setw(15) << i + 1;
		std::cout << ekipe[i];
	}
	std::cout << "\n";
}

void vidiUcesnikeEkipe() {
	int n;
	bool jeNeispravno = true;
	vidiEkipe();
	do
	{
		std::cout << "\nUnesite broj ekipe cije clanove zelite vidjeti: ";
		std::cin >> n;
		std::cin.ignore();
		if (n<0 || n>ekipe.size())
		{
			std::cout << "\nMolimo unesite broj u rasponu 1 - " << ekipe.size() << " ";
		}
		else
		{
			jeNeispravno = false;
			n--; // posto indeksi idu od 0 do size-1
			std::cout << "\nEkipa '" << ekipe[n].getNaziv() << "' ima sljedece ucesnike: ";
			std::cout << "\nIme\t\t    Prezime\t\t    Godiste\tObrazovanje";
			std::cout << "\n---------------------------------------------------------------------------------";
			for (int i = 0; i < ekipe[n].getBrUcesnika(); i++)
			{
				std::cout << "\n" << ekipe[n].getUcesnici()[i];
			}
			std::cout << "\n";
		}
	} while (jeNeispravno);
}

void vidiDogadjaje() {
	std::cout << "\n   Naziv\t\t\t  Lokacija\t\t\tDatum";
	std::cout << "\n---------------------------------------------------------------------------------";
	for (int i = 0; i < dogadjaji.size(); i++)
	{
		std::cout << "\n" << i + 1 << ". " << dogadjaji[i];
	}
	std::cout << "\n";
}

void vidiOrganizatore() {
	std::cout << "\nIme\t\t     Prezime\t\t    Titula";
	std::cout << "\n-----------------------------------------------------------------------";
	for (int i = 0; i < organizatori.size(); i++)
	{
		std::cout << organizatori[i];
	}
	std::cout << "\n";
}

void opcijeOrganizator(int i)
{
	int izbor = 0;
	do
	{
		system("PAUSE");
		system("cls");
		std::cout << "\nOdaberite jednu od opcija:\n\t1- Vidi ekipe\n\t2- Izbaci ekipu\n\t3- Dodaj ekipu\n\t4- Dodaj dogadjaj\n\t5- Vidi dogadjaje\n\t6- Izlaz\n\t";
		std::cin >> izbor;
		std::cin.ignore();
		switch (izbor)
		{
		case 1:
			vidiEkipe();
			break;
		case 2:
			organizatori[i].izbaciEkipu(ekipe);
			saveInfo();
			break;
		case 3:
			organizatori[i].dodajEkipu(ekipe);
			saveInfo();
			break;
		case 4:
			organizatori[i].dodajDogadjaj(dogadjaji);
			saveInfoDog();
			break;
		case 5:
			vidiDogadjaje();
			break;
		case 6:
			std::cout << "\nDovidjenja!";
			break;
		default:
			break;
		}
	} while (izbor != 6);
}

void organizatorLogIn() {
	char ime[15];
	int sifra = 0;
	int brPokusaja = 3;
	bool neispravno = true;
	do
	{
		std::cin.ignore();
		std::cout << "\nMolimo unesite svoje ime: ";
		std::cin.getline(ime, 15);
		std::cout << "\nMolimo unesite svoju sifru: ";
		std::cin >> sifra;
		std::cin.ignore();
		brPokusaja--;
		for (int i = 0; i < organizatori.size(); i++)
		{
			if (_strcmpi(organizatori[i].getIme(), ime)==0 && organizatori[i].getKljuc() == sifra)
			{
				std::cout << "\nDobrodosli!\n";
				neispravno = false;
				opcijeOrganizator(i);
			}
		}
		if(neispravno)
			std::cout << "\nMolimo pokusajte ponovo, Vas unos je neispravan!\nPreostalo: " << brPokusaja << " pokusaja!";

	} while (neispravno && brPokusaja > 0);
}

void printDog()
{
	vidiDogadjaje();
	int i = 0;
	std::cout << "\nUnesite redni broj dogadjaja koji zelite sacuvati: ";
	std::cin >> i;
	i--;
	std::cin.ignore();
	try
	{
		if (i<0 || i>dogadjaji.size())
			throw "\nDogadjaj s tim indeksom ne postoji!\n";
		else
		{
			Osoba p;
			p.setIme();
			p.setPrezime();
			std::ofstream kartaFile("karta.txt");
			kartaFile << "\nNaziv\t\t\t  Lokacija\t\t\tDatum\n---------------------------------------------------------------------------------\n";
			kartaFile << std::left << std::setw(30) << dogadjaji[i].getNazivDogadjaja() << std::left << std::setw(24) << dogadjaji[i].getLokacija() << "\t" << std::left << std::setw(15) << dogadjaji[i].getDatum();;
			kartaFile << "\n\nOvaj dokument je pristupnica za navedeni dogadjaj za osobu: " << p.getIme() << " " << p.getPrezime() << "\n---------------------------------------------------------------------------------\n";
			kartaFile.close();
		}
	}
	catch (const char* poruka)
	{
		std::cout << poruka;
	}
}

void vidiEkipeDog()
{
	int* niz;
	int brojac = 2;
	std::cout << "\n   Naziv\t\t\t  Lokacija\t\t\tDatum";
	std::cout << "\n---------------------------------------------------------------------------------\n";
	for (int j = 0; j < ekipeDogadjaji.size(); j++)
	{
		brojac = 2;
		niz = ekipeDogadjaji[j];
		std::cout << "\nEkipa '" << ekipe[niz[0]].getNaziv() << "' su bile/ce biti ucesnici " << niz[1] << " dogadjaja: ";
		std::cout << "\n---------------------------------------------------------------------------------\n";
		for (int i = 0; i < dogadjaji.size(); i++)
		{
			if (niz[brojac] == i)
			{
				std::cout << "\n" << i + 1 << ". " << dogadjaji[i];
				brojac++;
			}
		}
		std::cout << "\n";
	}
}

void posmatracView() {
	int odluka = 0;
	do
	{
		system("PAUSE");
		system("cls");
		std::cout << "\nHvala Vam na Vasoj zainteresovanosti za takmicenja!\nMolimo odaberite jednu od opcija:\n\t1- Pregledaj sva takmicenja\n\t2- Pregledaj sve ekipe\n\t3- Pregledaj organizatore\n\t4- Vidi ucesnike odredjene ekipe\n\t5- Isprintaj informacije o dogadjaju\n\t6- Vidi koje ekipe su na kojim dogadjajima\n\t7- Izlaz\n\tUnos: ";
		std::cin >> odluka;
		std::cin.ignore();
		switch (odluka)
		{
		case 1:
			vidiDogadjaje();
			break;
		case 2:
			vidiEkipe();
			break;
		case 3:
			vidiOrganizatore();
			break;
		case 4:
			vidiUcesnikeEkipe();
			break;
		case 5:
			printDog();
			break;
		case 6:
			if (ekipeDogadjaji.size() == 0)
				std::cout << "\nJos uvijek nijedna ekipa nije povezana niti sa jednim dogadjajem";
			else
				vidiEkipeDog();
			break;
		case 7:
			std::cout << "\nHvala i prijatno!\n";
			break;
		default:
			break;
		}
	} while (odluka != 7);
}

void ekipeTakmicenja(int x)
{
	int broj = 0, indeks = 0, brojac = 2;
	int* niz;

	vidiDogadjaje();

	std::cout << "\nMolimo unesite na koliko takmicenja je Vasa ekipa ucestvovala/ce ucestvovati: ";
	std::cin >> broj;
	std::cin.ignore();
	if (broj<0 || broj>dogadjaji.size())
		std::cout << "\nTaj broj nije validan!\n";
	else
	{
		niz = new int[(broj + 2)];
		niz[0] = x;
		niz[1] = broj;
		std::cout << "\nNa koja od navedenih takmicenja ste mislili: ";
		for (int i = 0; i < broj; i++)
		{
			do
			{
				std::cout << "\nUnesite indeks takmicenja: ";
				std::cin >> indeks;
				std::cin.ignore();
				if (indeks<1 || indeks>dogadjaji.size())
					std::cout << "\nMolimo za ispravan unos!";
				else
				{
					niz[brojac] = (indeks - 1);
					brojac++;
				}
			} while (indeks<1 || indeks>dogadjaji.size());
		}
		ekipeDogadjaji.push_back(niz);
	}
}

void opcijeEkipa(int i) {
	int odluka;
	do
	{
		system("PAUSE");
		system("cls");
		std::cout << "\nDobrodosao clanu ekipe: '" << ekipe[i].getNaziv() << "'\nIzaberi jednu od opcija:\n\t1- Pregled clanova\n\t2- Pregled broja pobjeda\n\t3- Pregled broja ucesca\n\t4- Odaberi takmicenja\n\t5- Izlaz\n\tIzbor: ";
		std::cin >> odluka;
		std::cin.ignore();
		switch (odluka)
		{
		case 1:
			std::cout << "\nIme\t\t    Prezime\t\t    Godiste\tObrazovanje";
			std::cout << "\n---------------------------------------------------------------------------------";
			for (int j = 0; j < ekipe[i].getBrUcesnika(); j++)
			{
				std::cout << "\n" << ekipe[i].getUcesnici()[j];
			}
			std::cout << "\n";
			break;
		case 2:
			std::cout << "\nBroj pobjeda Vaseg tima iznosi: " << ekipe[i].getBrPobjeda();
			if(ekipe[i].getBrPobjeda() < 5)
				std::cout<< "\nNa dobrom ste putu, samo tako nastavite!\n";
			else if(ekipe[i].getBrPobjeda()==0)
				std::cout << "\nBitno je ucestvovati!\n";
			else
				std::cout << "\nCestitamo\n";
			break;
		case 3:
			std::cout << "\nBroj ucesca Vaseg tima iznosi: " << ekipe[i].getBrUcesca();
			if(ekipe[i].getBrUcesca()==0)
				std::cout << "\nOcekujemo Vase ucesce na sljedecemo takmicenju!\n";
			else
				std::cout << "\nSamo tako nastavite!\n";
			break;
		case 4:
			ekipeTakmicenja(i);
			saveInfoEkipeDog();
			break;
		case 5:
			std::cout << "\nHvala Vam i dovidjenja\n";
			break;
		default:
			std::cout << "\nMolimo unesite ispravan broj!\n";
			break;
		}
	} while (odluka != 5);
}

void vidiSvojuEkipu() {
	int brPokusaja = 3;
	bool pronadjen = false;
	char tempNaziv[20];
	int indeks = 0;
	do
	{
		std::cout << "\nUnesi naziv svoje ekipe: ";
		std::cin.getline(tempNaziv, 20);
		brPokusaja--;
		for (int i = 0; i < ekipe.size(); i++)
		{
			if (strcmp(ekipe[i].getNaziv(), tempNaziv) == 0)
			{
				pronadjen = true;
				indeks = i;
				break;
			}
		}
		if (pronadjen == true)
		{
			opcijeEkipa(indeks);
		}
		else
			std::cout << "\nEkipa s tim nazivom ne postoji!\nPreostalo " << brPokusaja << " pokusaja!\n";

	} while (brPokusaja > 0 && pronadjen == false);
}

void ucesnikLogIn() {
	int odluka;
	bool jeLiNeispravno = true;
	do
	{
		std::cout << "\nDa li se zelite prijaviti ili ste vec ucesnik:\n\t0- Prijava ekipe\n\t1- Vec sam clan ekipe\n\tIzbor: ";
		std::cin >> odluka;
		std::cin.ignore();
		if (odluka < 0 || odluka>1)
		{
			std::cout << "\nMolimo unesite ispravan broj: ";
		}
		else
		{
			jeLiNeispravno = false;
			if (odluka == 0)
			{
				Ekipa temp;
				temp.postaviEkipu();
				ekipe.push_back(temp);
				saveInfo();
			}
			else
			{
				vidiSvojuEkipu();
			}
		}
	} while (jeLiNeispravno);

}