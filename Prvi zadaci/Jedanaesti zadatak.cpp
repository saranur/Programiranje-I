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