#include <iostream>
#include <ctime>
using namespace std;
struct fudbaler {
	int* godRodjena;
	int* brojIgraca;
	int* golovi;

	fudbaler()
	{
		godRodjena = new int;
		brojIgraca = new int;
		golovi = new int;
	}
	~fudbaler()
	{
		delete godRodjena;
		godRodjena = nullptr;
		delete brojIgraca;
		brojIgraca = nullptr;
		delete golovi;
		golovi = nullptr;
	}
};
void unos(fudbaler**, int);
void ispis(fudbaler**, int);
/*Omogućiti korisniku unos svih podataka za sve igrače, te napraviti
(i testirati u main funkciji) funkciju koja će pronaći tim sa najvećim prosjekom. 
Zatim napraviti (i testirati u main funkciji)
funkciju koja će pronaći igrača sa najviše golova u timu sa najlošijim prosjekom golova. 
Radi lakšeg testiranja programa 
obavezno u funkciji unosa podataka omogućiti da se podaci generišu kao sljedeće:*/
void najveci_Prosjek(fudbaler**, int);
void igrac_s_najvise_golova(fudbaler**, int);
void Dealokacija(fudbaler**&, int);


int main() {
	int n;
	cout << "Unesite broj klubova. " << endl;
	cin >> n;
	fudbaler** niz = new fudbaler*[n];

	for (int i = 0; i < n; i++)
	{
		niz[i] = new fudbaler[n];
	}

	srand(time(NULL));
	unos(niz, n);
	ispis(niz, n);
	najveci_Prosjek(niz, n);
	igrac_s_najvise_golova(niz, n);

	Dealokacija(niz, n);
	return 0;
	cin.get();
}

void unos(fudbaler** niz, int n)
{
	cout << "Unesite podatke. " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//cout << "Godina rodjenja fudbalera. " << endl;
			*(*(niz + i) + j)->godRodjena = 1980 + rand() % ((2000 + 1) - 1980);
			//	cout << "Broj Igraca. " << endl;
				*(*(niz + i) + j)->brojIgraca = rand() % 30 + 1;
			//	cout << "Golovi igraca. " << endl;
			*(*(niz + i) + j)->golovi= rand() % 5;
		}cout << endl;
	}cout << endl;
}
void ispis(fudbaler**niz, int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Godina rodjenja igraca: " << *(*(niz + i) + j)->godRodjena << endl;
			cout << "Broj igraca: " << *(*(niz + i) + j)->brojIgraca << endl;
			cout << "Golovi igraca: " << *(*(niz + i) + j)->golovi << endl;
		}cout << endl;
	}
}
void najveci_Prosjek(fudbaler**niz, int n) {
	float* prosjek = new float[n] {};
	int index=0, brojac=0;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			brojac++;
			*(prosjek + i) += *(*(niz + i) + j)->golovi;
		}
		*(prosjek + i) /= brojac; 

	}
	float najveci_pr=0;
	for (int i = 0; i < n; i++)
	{
		if (*(prosjek+i)>najveci_pr)
		{
			najveci_pr = *(prosjek+ i);
			index = i  ;
		}
	}
	cout << "Tim sa najvecim prosjekom je na indexu broj: " << index << endl;
	cout << " Prosjek iznosi: " << najveci_pr << endl;

}
void igrac_s_najvise_golova(fudbaler**niz, int n) {
	int brojac = 0;
	float* najmanji_prosjek = new float[n] {};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			brojac++;
			*(najmanji_prosjek + i) += *(*(niz + i) + j)->golovi;
		}
		*(najmanji_prosjek + i) /= brojac;
		
	}
	int index = 0;
	for (int i = 0; i <n;  i++)
	{
		
		if(*(najmanji_prosjek + i) < *(najmanji_prosjek + index))
		{
			index = i;
		}
	}

	int najbolji_igrac = *(*(niz+index)+0)->golovi;
	int indexj = 0;
	for (int j = 0; j < n; j++)
	{
		if (*(*(niz + index) + j)->golovi > najbolji_igrac) {
			najbolji_igrac = *(*(niz + index) + j)->golovi;
			indexj = j;
		}
	}
	cout << "Igrac sa najvise golova u najlosijem timu je: " << *(*(niz + index) + indexj)->brojIgraca << "sa brojem golova: " << *(*(niz + index) + indexj)->golovi << endl;


}


void Dealokacija(fudbaler**&niz, int n) {
	for (int i = 0; i < n; i++)
	{
		delete[] *(niz + i);
		*(niz + i) = nullptr;
	}
	delete[] niz;
	niz = nullptr;
}