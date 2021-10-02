#include <iostream>
using namespace std;
int sumaFaktorijela(int broj);
void ispisiBrojeve();
int main()
{
	ispisiBrojeve();

	return 0;
	cin.get();
}

int sumaFaktorijela(int broj) {
	int suma=0;

	while (broj>0)
	{
		int cifra = broj % 10; 
		int faktorijel = 1;
		for (int i = 1; i <= cifra; i++)
		{
		faktorijel *= i;
		}

		suma += faktorijel;
		broj /= 10;
	}
	return suma;
}

void ispisiBrojeve() {
	for (int i = 100; i < 1000; i++) 
	{
		if (i == sumaFaktorijela(i))
			cout <<"Cifre broja "<< i<<" su jednaki sumi faktorijela tih cifri. " << endl;
	}
}

