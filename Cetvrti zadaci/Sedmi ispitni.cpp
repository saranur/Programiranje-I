#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;
//Struktura
struct figura {
	int ID;
	char *nazivFigure;
	float *visinaFigure;
	figura()
	{
		ID = 0;
		nazivFigure = new char[10];
		visinaFigure = new float;
	}
	~figura()
	{
		delete[] nazivFigure;
		nazivFigure = nullptr;
		delete visinaFigure;
		visinaFigure = nullptr;
	}
};
//Deklaracija funkcija
void unos(figura**, int, int);
void ispis(figura**, int, int);
float* prosjek(figura**, int, int);
void Dealokacija(figura**&, int);

//Main funkcija
int main() {
	srand((time(0)));
	int red, kolona;
	cout << "Unesite broj redova sahovske table. " << endl;
	cin >> red;
	cout << "Unesite broj kolona sahovske table. " << endl;
	cin >> kolona;
	figura** niz = new figura * [red];
	for (int i = 0; i < red; i++)
	{
		*(niz + i) = new figura[kolona];
	}
	unos(niz, red, kolona);
	ispis(niz, red, kolona);
	cout << "Memorijska lokacija prosjeka svih figura na crnim poljima ispod sporedne dijagonale: " << prosjek(niz, red, kolona) << endl;
	cout << "Prosjek svih figura na crnim poljima ispod sporedne dijagonale: " << *prosjek(niz, red, kolona) << endl;

	Dealokacija(niz, red);
	return 0;
	cin.get();
}

//Definicija funkcija
void unos(figura**niz, int red, int kolona) {
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cin.ignore();
			cout << "Unesite naziv figure: ";
			cin.getline((*(niz + i) + j)->nazivFigure, 10);
			(*(niz + i) + j)->ID = rand() % 10000 + 100;
		    *(*(niz + i) + j)->visinaFigure = (float(rand()%10+1));
			/* //Rucni unos:
			cout << "Unesite ID figure: ";
			cin >> (*(niz + i) + j)->ID;
			cout << "Unesite visinu figure: ";
			cin >> *(*(niz + i) + j)->visinaFigure;
			*/
		}
		cout << endl;
	}
}
void ispis(figura** niz, int red, int kolona) {
		cout << endl;
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cout << "Naziv figure:" << (*(niz + i) + j)->nazivFigure << "\t";
			cout << "ID figure: " << (*(niz + i) + j)->ID << "\t";
			cout << "Visina figure: " << *(*(niz + i) + j)->visinaFigure << endl;
		}
		cout << "\n";
	}
}
float* prosjek(figura**niz, int red, int kolona) {
	float prosjekCrnih = 0.0f;
	int brojac=0;
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if ((i + j) >= red - 1 && (i + j) % 2 == 0) {
				prosjekCrnih += *(*(niz + i) + j)->visinaFigure;
				brojac++;
			}
		}
	}
	if(brojac!=0)
	return new  float(prosjekCrnih /= brojac);
}
void Dealokacija(figura**&niz, int red) {
	for (int i = 0; i < red; i++)
	{
		delete[]* (niz + i);
		*(niz + i) = NULL;
	}
	delete[] niz;
	niz = nullptr;
}
