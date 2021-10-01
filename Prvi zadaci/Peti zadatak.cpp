#include <iostream>
using namespace std;
int obrni(int);
int main()
{
	int A, B=0;
	do
	{
		cout << "Unesite broj (A > 100000): " << endl;
		cin >> A;
		if (A < 100000)
			cout << "POgresan unos! " << endl;
	} while (A<100000);

	B= obrni(A);
	cout << "Obrnuti broj od unesenog sa uklonjenim parnim ciframa: " << B << endl;
	cout << "Razlika unesenog broja A i novog broja je: " << abs(A - B) << endl;
	return 0;
	cin.get();
}
int obrni(int br)
{
	int obrnut = 0;
	int temp = 0;
	while(br>0)
	{
		temp= br % 10;
		if(temp%2!=0)
		{
			obrnut = obrnut * 10 + temp;
		}
		br /= 10;
	}
	return obrnut;
}