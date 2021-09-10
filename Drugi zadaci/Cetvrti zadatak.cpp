#include <iostream>
using namespace std;
bool prost(int);
void Goldbach(int);
void ispis(int, int);
int main() {
	int n1, n2;
	do
	{
	cout << "Unesite dva broja. (n2 > n1)  " << endl;
	cin >> n1 >> n2;
	} while (n1<=0|| n2<=0);
	ispis(n1, n2);

	return 0;
	cin.get();
}
bool prost(int broj) 
{
	if (broj <= 1) //0 i 1 nisu prosti brojevi
		return false;
	for (int i = 2; i < broj; i++)
	{
		if (broj % i == 0) 
			return false;
	}
	return true;
}
void Goldbach(int broj) {
	for (int i = broj/2, j=broj/2; i <= broj; i++, j--) //ukoliko je broj 20, 20/2= 10 pa ce i biti 10 i j ce biti 10, i cemo povecati a j smanjivati
	{													//time cemo ispitati svaku cifru u broju 20.
		if (prost(i) && prost(j))
		{
			cout << broj << " = " << i << " + " << j << endl;
			break;
		}
	}
}

void ispis(int n1, int n2) {

	if (n1 > n2) {  
		int temp = n1;
		n1 = n2;
		n2 = temp;
	}
	cout << "Parni brojevi predstavljeni kao suma prostih brojeva u intervalu od " << n1 << " do " << n2 << " je: " << endl;
	if (n1 % 2 != 0)
		n1++;
	for (int i = n1; i <= n2; i +=2)
	{
		Goldbach(i);
	}
		
}