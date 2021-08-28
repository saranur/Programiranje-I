#include <iostream>
using namespace std;

void punjenjeNiza(int*, int, int i = 0);
void provjera(int*, int, int, int i = 0);

int main() {
	int n;
	cout << "Unesite velicinu niza. " << endl;
	cin >> n;
	int *niz = new int[n] {};
	punjenjeNiza(niz, n);
	cout << "Unesite broj za koji zelite provjeriti da je clan Fibonaccijevog niza: ";
	int izbor;
	cin >> izbor;
	cout << "Fibonacci niz: ";
	for (int i = 0; i < n; i++)
	{
		cout << *(niz + i) << " ";
	}
	cout << endl;
	provjera(niz, n, izbor);

	delete[]niz;
	niz = nullptr;
	return 0;
	cin.get();
}

void punjenjeNiza(int*niz, int n, int i) {
	if (i == n)
		return;
	if (i < n) 
	{
		if (i == 0)
			*(niz + i) = 1;
		if (i == 1)
			*(niz + i) = 1;
		if (i > 1) 
		{
			int pomocna = *(niz + i -1 ) + *(niz + i - 2);
			if (pomocna < 0)
				return;
			*(niz + i ) = pomocna;
		}
		punjenjeNiza(niz, n, i + 1);
	}
}

void provjera(int*niz, int n, int izbor, int i) {
	if (i == n) {
		cout << "Broj nije clan Fibonaccijevog niza. " << endl;
		return;
	}
	if (i < n) {
		if (*(niz + i) == izbor) {
			cout << "Broj je clan Fibonaccijevog niza. " << endl;
			return;
		}
		provjera(niz, n, izbor, i + 1);
	}
}