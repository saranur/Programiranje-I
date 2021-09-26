#include <iostream>
#include <iomanip>
using namespace std;
double GS(int);
int main()
{
	int N;
	cout << "Unesite neki broj N. " << endl;
	cin >> N;

	cout<<"Geometrijska sredina svih neparnih brojeva u inervalu [1, "<<N<<"] a koji nisu djeljivi sa 5 iznosi: "<<setprecision(3)<< GS(N);

	return 0;
	cin.get();
}

double GS(int N)
{
	long double suma = 1.0;
	int brojac = 0;
	for (int i=1; i<=N; i+=2 )
	{
		if(i%5!=0)
		{
			suma *= i;
			brojac++;
		}
	}
	return pow(suma, 1 /double(brojac));
}