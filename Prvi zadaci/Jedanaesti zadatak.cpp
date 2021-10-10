/*Napisati program koji korisniku omogućava unos realnog broja x,
 cijelog broja m i odabir funkcije za proračun datog izraza.
 Korisnik bira funkciju unosom sljedećih karaktera 's' (sin), 'c' (cos), 'q' (sqrt), 'p' (pow).
 U slučaju da korisnik unese karakter koji ne odgovara niti jednoj od predefinisanih vrijednosti ispisati odgovarajuću poruku i ponoviti odabir.
Funkciji pow postavite broj 2 za drugi parametar.
Za odabranu funkciju izraz je:


Broj faktora u izrazu odgovara unesenom broju m. U rješenju obavezno iskoristiti switch iskaz.*/
#include <iostream>
using namespace std;
float rezultatIzraza(int, float);
int main()
{
	float x;
	int m;
	cout << "Unesite neki realan broj. " << endl;
	cin >> x;
	cout << "Unesite cijeli broj." << endl;
	cin >> m;
	cout << "Rezultat odabranog izraza je: " << rezultatIzraza(x, m);
	

	return 0;
	system("pause>0");
}
float rezultatIzraza(int m, float x)
{	
	float izraz = 0.0f;
	char izbor;
	do
	{
		cout << "Odaberite funkciju:  's' (sin), 'c' (cos), 'q' (sqrt), 'p' (pow)." << endl;
		cin >> izbor;
		if (izbor != 's' && izbor != 'c' && izbor != 'p' && izbor != 'q')
			cout << "Neispravan unos! ";
	} while (izbor != 's' && izbor != 'c' && izbor != 'p' && izbor != 'q');


	switch (izbor)
	{
	case 's': {
		for (int i = 1; i <= m; i++)
		{
			izraz += i / (sin(x / i) + x);

		}
		return izraz;
	}break;
	case 'c': {
		for (int i = 1; i <= m; i++)
		{
			izraz += i / (sin(x / i) + x);

		}
		return izraz;
	}break;
	case 'p': {
		for (int i = 1; i <= m; i++)
		{
			izraz += i / (pow((x / i) , 2));

		}
		return izraz;
	}break;
	case 'q': {
		for (int i = 1; i <= m; i++)
		{
			izraz += i / (sqrt(x / i) + x);

		}
		return izraz;
	}break;

	default: cout << "Neispravan unos! 's' (sin), 'c' (cos), 'q' (sqrt), 'p' (pow)." << endl;
		break;
	}
}