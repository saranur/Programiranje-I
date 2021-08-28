/*Napisati program koji će omogućiti korisniku da unese veličinu jednodimenzionalnog dinamičkog niza integer vrijednosti.
Napisati rekurzivnu funkciju koja će taj niz popuniti faktorijelom rednog broja člana niza (1!, 2!, 3!, 4!...). 
Rekurzija se prekida kada se popuni cijeli niz ili kada se desi overflow na integer varijabli. U ovom zadatku je zabranjeno indeksirati elemente niza uglastim zagradama.

(Obavezno koristiti aritmetiku pokazivača. Obavezno sve riješiti jednom rekurzivnom funkcijom.)*/

#include <iostream>
using namespace std;
void Faktorijel(int*, int, int i = 0);
int main() {
	int n;
	cout << "Unesite broj za koji zelite izracunati Fakorijel. " << endl;
	cin >> n;
	int* niz = new int[n] {};
	Faktorijel(niz, n);
	cout << "Brojevi koji cine fakorijel broja " << n << " su: ";
	for (int i = 0; i < n; i++)
	{
		cout << *(niz + i) << " ";
	}
	cout << endl;


	delete[]niz;
	niz = nullptr;
	return 0;
	cin.get();
}
void Faktorijel(int* niz, int n, int i) {
	if (i == n)
		return;
	if (i < n) {
		if (i == 0)
			*(niz + i) = 1;
		else {
			int pomocna = *(niz + i - 1) * (i + 1);
			if (pomocna < 0)
				return;
			*(niz + i) = pomocna;
			 
			
		}
		Faktorijel(niz, n, i + 1);
	}
}

