#include <iostream>
using namespace std;
/*Napisati program koji će omogućiti korisniku da unese veličinu n jednodimenzionalnog dinamičkog niza integer vrijednosti (n > 2).
Napisati rekurzivnu funkciju koja će taj niz puniti serijom brojeva tako da je svaki sljedeći broj jednak umnošku dva prethodna broja,
a prva dva elementa su 1 i 3 (1, 3, 3, 9, 27, ...).

Zatim napraviti drugu rekurzivnu funkciju koja će izračunati zbir svih elemenata tog niza (voditi računa o tipu podatka zbog veličine broja).

(Obavezno koristiti aritmetiku pokazivača)*/
void punjenjeNiza(int*, int, int i = 0);
void ispisivanjeNiza(int*, int, int i = 0);
long long int suma(int*, int, int i=0);
int main() {
	int n;
	do
	{
		cout << "Unesite broj n > 2. " << endl;
		cin >> n;
	} while (n<2);
	int* niz = new int[n] {0};
	punjenjeNiza(niz, n);
	ispisivanjeNiza(niz, n);
	cout << endl;
	cout << "Suma svih elemenata je: " << suma(niz, n) << endl;
	delete[]niz;
	niz = nullptr;
	return 0;
	cin.get();

}
void punjenjeNiza(int*niz, int n, int i) {
	if (i == n)
		return;
	if (i < n) {
		if (i == 0)
			*(niz + i) = 1;
		if (i == 1)
			*(niz + i) = 3;
		if (i > 1)
		{
			int pomocna = *(niz + i - 1) * *(niz + i - 2);
			if (pomocna < 0) //ako se desi overflow
				return;
			*(niz + i) = pomocna;
		}
	punjenjeNiza(niz, n, i+1);
	}
}
void ispisivanjeNiza(int*niz, int n, int i){
	if (i == n)
		return;
	
	cout << *(niz + i) << " ";

	ispisivanjeNiza(niz, n, i +1);
}
long long int suma(int*niz, int n, int i) {
	if (i == n)
		return 0;
	return *(niz + i) + suma(niz, n, i + 1);
	
}
