/*Napisati program koji omogućava unos pozitivnog broja n te pronalazi njegove parne cifre i formira novi broj u kojem su parne cifre
zamijenjene cifrom '5'.
Dodatno program treba ispisati razliku unesenog i broja koji se dobije nakon zamjene.*/
#include <iostream>
using namespace std;
int zamjenaBroja(int);
int main() {
	int n, noviBr;
	do
	{
		cout << "Unesite prirodni broj n. " << endl;
		cin >> n;
	} while (n<0);
	noviBr = zamjenaBroja(n);
	cout << "Novi broj u kojem su parne cifre zamjenjenje peticom: " << noviBr << endl;
	cout << "Razlika izmedju " << n << " i " << noviBr << " je: " << abs(n - noviBr);
	return 0;
	cin.get();
}
int zamjenaBroja(int n) {
	int cifra = 0;
	int noviBroj = 0;
	int brojac = 0;
	while (n > 0) {
		//neka je npr. n=123456
		cifra = n % 10; //zadnju cifru (6)
		if (cifra % 2 == 0) {  
			cifra = 5;		//cifra je 6(parna, zamijeni je na 5)
			noviBroj += cifra * pow(10, brojac) ;   //novi broj je inicijaliziran na 0, cifra je 6, brojac je trenutno 0.
			// pa ce to biti noviBroj= 0+6*10^0 a to je 6
			n /= 10; //skini zadnju cifru tj 6. Ovo radimo da mozemo ispitati za svaku cifru tog broja. 
		}
		else {
			noviBroj += cifra * pow(10, brojac);  //u slucaju da broj nije paran, radi isto samo cifra ostaje kakve jeste.

			n /= 10; //opet skida u nakon svakog izvrsenja
		}
			brojac++; //brojac povecamo nakon izvrsenja tako da bi mogli svaki broj vratiti na prvobitnu poziciju. tj ako unesemo 1234 nek ispise 1535

	}
	return noviBroj;
}