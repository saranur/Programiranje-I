#include <iostream>
#include <iomanip>
using namespace std;
double suma(int);
int main()
{
	int broj;
	do
	{
		cout << "Unesite neki prirodni broj. " << endl;
		cin >> broj;
		if (broj < 0)
			cout << "Pogresan unos!" << endl;
	} while (broj<0);

	cout << "Suma cosinusa za sve brojeve do " << broj << " iznosi: " << suma(broj);
	return 0;
	cin.get();
}

double suma(int broj)
{
	long double S = 0;
	for (int i = 1; i <=broj; i++)
	{
		 //Za provjeru
		double cosx = cos(pow(broj, i));
		cout << cosx << endl;
		
		S += cos(pow(broj, i));

	}
	return S;
}