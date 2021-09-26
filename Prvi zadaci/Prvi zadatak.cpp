#include <iostream>
#include <cmath>
using namespace std;
float sumaSin(int, char);
float sumaCos(int, char);
int main()
{
	int x;
	cout << "Unesite neki broj x. " << endl;
	cin >> x;
	char izbor;
	do
	{
		cout << "Unesite 'c' za cosinus i 's' za sinus. " << endl;
		cin >> izbor;
		if(izbor != 's' && izbor != 'c')
		cout << "Netacan unos! " << endl;
	}
	while (izbor!='s' && izbor!='c');
	if(izbor=='s')
	cout<<" Suma za "<<izbor<< " je: "<<sumaSin(x, izbor);
	else
		cout << " Suma za " << izbor << " je: " << sumaCos(x, izbor);

	return 0;
	cin.get();
}

float sumaSin(int x, char izbor){
	float suma = 1;
	for (int i=1; i<=x; i++)
	{
		suma += i / ( (sin(x / i) + x)); //Rezultat ce biti u radijanima jer je to default
	}
	return suma;
}

float sumaCos(int x, char izbor) {
	float suma = 1;
	for (int i = 1; i <= x; i++)
	{
		suma += i / ((cos(x / i) + x)); //Rezultat ce biti u radijanima jer je to default
	}
	return suma;
}

