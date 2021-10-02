#include <iostream>
using namespace std;
int unos();
int obrniBroj(int);
int sumaCifara(int);
void Provjera(int, int);
int main()
{
	int X = unos();
	int Y = unos();
	Provjera(X, Y);
}
int unos()
{
	int broj;
	do
	{
		cout << "Unesite broj u intervalu od [10, 5000]: ";
		cin >> broj;

		if ((broj < 10 || broj >5000) )
			cout << "Pogresan unos! " << endl;

	} while ((broj < 10 || broj >5000));
	return broj;
}
int obrniBroj(int broj)
{
	int novibr = 0;
	while(broj>0)
	{
		novibr = novibr * 10 + broj % 10;
		broj /= 10;
	}
	return novibr;
}
int sumaCifara(int broj)
{
	int suma = 0;
	while(broj>0)
	{
		suma += broj % 10;
		broj /= 10;
	}
	return suma;
}
void Provjera(int X, int Y)
{
	if (X > Y)
	{
		int temp = X;
		X = Y;
		Y = temp;
	}
	cout << "Brojevi koji ispunjuju dati uslov u intervalu [" << X << "," << Y << "]: ";
	for (int i = X; i <=Y; i++)
	{
		if (obrniBroj(i) % sumaCifara(i) == 0) 
			cout << i<<" ";
	}
}