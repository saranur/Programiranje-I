#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void popunjavanjeNiza(int*, int, int i = 0);
int main() {
	int n;
	cout << "Unesite velicinu niza. " << endl;
	cin >> n;
	int* niz = new int[n] {};
	srand(time(NULL));
	popunjavanjeNiza(niz, n);
	for (int i = 0; i < n; i++)
	{
		cout << *(niz + i) << " ";
	}


	delete[]niz;
	niz = nullptr;
	return 0;
	cin.get();
}
void popunjavanjeNiza(int*niz, int n, int i) {
	if (i == n)
		return;

		*(niz + i) = rand() % 100 + 1;
		if (i > 1) {

			if (*(niz + i) == *(niz + i + 1) == *(niz + i + 2)) {
				return;
			}
		}
		

    popunjavanjeNiza(niz, n, i + 1);

}