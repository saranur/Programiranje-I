#include <iostream>
using namespace std;
double suma(int);
int main()
{
	int broj;
	do
	{
	cout << "Unesite neki prirodni broj: ";
	cin >> broj;
	if (broj < 0)
		cout << "Pogresan unos! " << endl;
	} while (broj < 0);

	cout << "Rezultat je: "<<suma(broj);

	return 0;
	cin.get();
}
double suma(int broj)
{
	double rez=0;
	for (int i=1; i <=broj; i++)
	{
		/*  Za provjeru: 
		double temp = 1;
		temp/=((i * 2) + 1);
		cout << "temp: " << temp << endl;
		cout << "temp^2: " << pow(temp, 2) << endl;
		 */
		rez +=1/ pow(i * 2 + 1, 2);
	}
	return rez;
}