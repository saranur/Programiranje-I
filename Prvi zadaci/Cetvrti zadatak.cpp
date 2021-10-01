#include <iostream>
using namespace std;
int prebroj(int);
int prvaCifra(int);
int srednjaCifra(int);
int zadnjaCifra(int);
int obrni(int);
int main()
{
	int broj;
	cout << "Unesite broj: " << endl;
	cin >> broj;
	cout << "Broj ima: "<< prebroj(broj) << " cifara." << endl;
	cout << "Prva cifra broja je: " << prvaCifra(broj) << endl;
	cout << "Srednja cifra broja je: " << srednjaCifra(broj) << endl;
	cout << "Zadnja cifra broja je: " << zadnjaCifra(broj) << endl;
	cout << "Obrnuti broj je: " << obrni(broj);
	return 0;
	system("pause>0");
}

int prebroj(int br)
{
	int brojac = 0;
	while(br>0)
	{
		br /= 10;
		brojac++;
	}
	return brojac;
}
int obrni(int br)
{
	int obrnuti = 0;
	while(br>0)
	{
		obrnuti = obrnuti * 10 + br % 10;
		br /=10; 
	}
	return obrnuti;
}
int prvaCifra(int br)
{
	while (br >= 10) {
		br /= 10;
	}
	return br;
	/*  Drugi nacin
	int temp = prebroj(br); //Prebroji cifre, ako je br= 12345, temp ce biti 5
	br/=pow(10, (temp-1));  //kada br podijelimo sa 10^4, to je 12345/1000, otkidamo 4 cifre
	return br; //vracamo tu jednu cifru koja je ostala, tj prvi broj
	*/
	//Drugi nacin
}
int srednjaCifra(int br)
{
	if (br % 2 == 0)
		cout << "Broj je paran! "; //Moze, a i ne mora
	int temp = prebroj(br) / 2; ////Ne znamo koliko broj ima cifri, ako broj ima npr 5 cifri, podijelimo sa dva, s obzirom da je integer, dobicemo rjesenje 2
	br/= pow(10,temp);  //10^2= 100, npr 12345/=100 ce biti 123, otkinuce dvije cifre jer koristimo integere
	return br%10;  //Modulo uzima samo zadnji broj dakle ako smo imali 123, modulo ce vratiti broj 3. 
}
int zadnjaCifra(int br)
{
	return br % 10; //samo uzmemo zadnji broj
}