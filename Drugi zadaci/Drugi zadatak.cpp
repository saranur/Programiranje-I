
#include <iostream>
using namespace std;
int obrniA(int);
int main() {
	int A, B;
	do
	{
		cout << "Unesite broj A. " << endl;
		cin >> A;
	} while (A<=100000);
	B=obrniA(A);
	cout << "Obrnuti broj bez parnih brojeva je: " << B << endl;
	cout << "Razlika izmedju broja A i B je: " << abs(A - B) << endl;
	return 0;
	cin.get();
}
int obrniA(int A) { 
	int B = 0;
	int ostatak = 0;
	while (A > 0) {

	while (A > 0) {
		ostatak= A % 10;
		if (ostatak % 2 == 0){
			A /= 10;
		}
		else {
			B = B * 10 + ostatak;
			A /= 10;
		}
	}
	}
	return B;

}