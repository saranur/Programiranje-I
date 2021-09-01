#include <iostream>
#include <time.h>
using namespace std;
int bacanjeKockica();
int main() {
	srand(time(NULL));
	cout << "Ukopno bacanja potrebnih da se dobiju isti brojevi za sve tri kockice dva puta uzastopno je: " << bacanjeKockica() << endl;

	return 0;
	cin.get();
}

int bacanjeKockica() {
	int brojBacanja = 0;
	int brojPonavljanja = 0;
	do
	{
		int kocka1 = rand() % 6 + 1;
		int kocka2= rand() % 6 + 1;
		int kocka3= rand() % 6 + 1;
		
		if (kocka1 == kocka2 && kocka2 == kocka3) {
			brojPonavljanja++;
		}
		else brojPonavljanja = 0;

		brojBacanja++;

	} while (brojPonavljanja < 2);

		return brojBacanja;
}
