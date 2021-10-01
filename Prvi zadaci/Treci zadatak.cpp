#include <iostream>
using namespace std;
int noviBroj(int, int&);
int main()
{
	int broj = 0, rezultat = 0;
	do
	{
		cout << "Unesite cifru:  ";
		cin >> broj;
		if (broj > 9)
			cout << "Cifra nije validna. " << endl;
		if (broj > 0 && broj <= 9)
			noviBroj(broj, rezultat);
		

	} while (broj > 0);
	cout << "Novi broj je: "<< rezultat;

	return 0;
	system("pause>0");
}
int noviBroj(int broj, int& rezultat){
	return rezultat = rezultat* 10 + broj;
}


