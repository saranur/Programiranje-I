#include <iostream>
using namespace std;
 float const PI = 3.14159265;
float sumaSin(float);
float sumaCos(float);
int main()
{
	float x;
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
	cout<<" Suma za "<<izbor<< " je: "<<sumaSin(x);
	else
		cout << " Suma za " << izbor << " je: " << sumaCos(x);

	return 0;
	cin.get();
}
 
float sumaSin(float x){
	float suma = 1;
	for (int i=1; i<=x; i++)
	{
		suma += i / ( (sin(x / i) + x)); //Rezultat ce biti u radijanima jer je to default
	}
	return suma;
}

float sumaCos(float x) {
	float suma = 1;
	for (int i = 1; i <= x; i++)
	{
		suma += i / ((cos(x / i) + x)); //Rezultat ce biti u radijanima jer je to default
	}
	return suma;
}

//Ukoliko zelite da suma bude ispisana u stepenima onda odkomentirajte:
/*
float sumaSin(float broj) {
	double suma=1.0f;
	for (int i = 1; i <= broj; i++)
	{
		suma += i / (sin(PI / 180 *( broj / i)) + broj);
	}
	return suma;
	}

float sumaCos(float broj) {
	double suma = 1.0f;
	
	for (int i = 1; i <= broj; i++)
	{
		suma += i / (cos(PI / 180 * (broj / i)) + broj);
	}
	return suma;
}
*/