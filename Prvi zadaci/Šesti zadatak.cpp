#include <iostream>
using namespace std;
long long int Faktorijel(int);
long long int Suma(int);
void sumaFaktorijela(int);
int main()
{
	int N;
	cout << "Unesite neki prirorodni broj. " << endl;
	cin >> N;
	sumaFaktorijela(N);
	cout << endl;
	//Odkomentiraj za koristenje druge dvije funkcije
	//cout << "Suma neparnih brojeva u intervalu od [1, "<<N<<"] iznosi: " <<Suma(N)<< endl;
	return 0;
	cin.get();

}
//Mozete koristiti samo ovu funkciju za racunanje faktorijela i sume neparnih brojeva 
void sumaFaktorijela(int brojN)  
{
	 long long int Faktorijel = 1;
	 long long int suma = 0;
	for(int i=1; i<=brojN; i++)
	{
		Faktorijel *= i;  
		cout << " Faktorijel " << i << "! iznosi: " << Faktorijel << endl; //nije neophodna linija, radi lakse citljivosti
		if (i % 2 != 0)
			suma += Faktorijel;
	}
	cout << "Suma neparnih brojeva u intervalu od [1, " << brojN << "] iznosi: "<< suma;
}
//Mozete napraviti dvije funkcije radi ponovnog koristenja zasebnih funckija, korisno u zadacima kada nam treba ista funkcija vise puta
//Samo pozvati obje funkcije u main funkciji. 
long long int Faktorijel(int brojN)
{
	long long int faktorijel = 1;
	for (int i = 1; i <=brojN; i++)
	{
		faktorijel *= i;
	}
	return faktorijel;
}
long long int Suma(int brojN)
{
	long long int suma = 0;
	for (int i = 1; i <=brojN; i+=2) //kada stavimo i+2 dobicemo samo neparne brojeve
	{
		suma += Faktorijel(i);
	}
	return suma;
}
