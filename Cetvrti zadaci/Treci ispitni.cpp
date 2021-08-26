#include <iostream>
#include <ctime>
using namespace std;
struct vozilo {
    char* markaVozila;
    char* nazivVozila;
    char* tipVozila; // omogućiti unos samo 'A', 'B','C'
    float* potrosnja_goriva_po_km;
    vozilo()
    {
        markaVozila = new char[20];
        nazivVozila = new char[20];
        tipVozila = new char;
        potrosnja_goriva_po_km = new float;
    }
    ~vozilo()
    {
        delete[] markaVozila;
        markaVozila = nullptr;
        delete[] nazivVozila;
        nazivVozila = nullptr;
        delete tipVozila;
        tipVozila = nullptr;
    }
};

void unos(vozilo**, int, int);
void ispis(vozilo**, int, int);
void firma_najveca_potrosnja(vozilo**, int, int);
void potrosnja_vozila_C(vozilo**, int, int);
void Dealokacija(vozilo**&, int);

int main() {
    int red, kolona;
    cout << "Unesite broj firmi. " << endl;
    cin >> red;
    cout << "Unesite broj automobila. " << endl;
    cin >> kolona;
    vozilo** niz = new vozilo * [red];
    for (int i = 0; i < red; i++)
    {
        *(niz + i) = new vozilo [kolona];
    }
    //srand(time(NULL));
    unos(niz, red, kolona);
    ispis(niz, red, kolona);
    firma_najveca_potrosnja(niz, red, kolona);
    potrosnja_vozila_C(niz, red, kolona);
    Dealokacija(niz, red);
    return 0;
    cin.get();
}

void unos(vozilo**niz, int red, int kolona) {
    cout << "Unesite podatke. " << endl;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            cin.ignore();
            cout << "Unesite marku vozila: " << endl;
            cin.getline((*(niz + i) + j)->markaVozila, 20); //obavezno dodati velicinu niza!
            cout << "Unesite naziv vozila: " << endl;
            cin.getline((*(niz + i) + j)->nazivVozila, 20); //za nizove karaktera ne trebaju dva pokazivaca zbog prirode pokazivaca!
            do
            {
                cout << "Unesite tip vozila: 'A', 'B', 'C' : " << endl;
                cin>> *(*(niz + i) + j)->tipVozila;

            } while (*(*(niz+i)+j)->tipVozila!='A' && *(*(niz + i) + j)->tipVozila != 'B'&& *(*(niz + i) + j)->tipVozila != 'C');
            cout << "Unesite potrsnju po kilometru: " << endl;
            cin >> *(*(niz + i) + j)->potrosnja_goriva_po_km;
            // *(*(niz + i) + j)->potrosnja_goriva_po_km= rand() % 10 + 5;
        }
    }
}
void ispis(vozilo**niz, int red, int kolona) {
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            cout << "Marka vozila je: " << (*(niz + i) + j)->markaVozila << endl;
            cout << "Naziv vozila je: " << (*(niz + i) + j)->nazivVozila << endl;
            cout << "Tip vozila je: " << *(*(niz + i) + j)->tipVozila << endl;
            cout << "Potrosnja po km: " << *(*(niz + i) + j)->potrosnja_goriva_po_km << endl;
        }cout << endl;
        
    }
}
void firma_najveca_potrosnja(vozilo**niz, int red, int kolona) {
    float* potrosnja = new float[red] {};
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            *(potrosnja+i) += *(*(niz + i) + j)->potrosnja_goriva_po_km; 
        }
    }
    
    int index = 0;
    for (int i = 0; i < red; i++)
    {
        if (*(potrosnja + i) > * (potrosnja + index))
            index = i;
    }
    cout << "Firma sa najvecom potrosnjom se nalazi na indexu: " << index << " i ima sljedece podatke: " << endl;
    for (int j = 0; j < kolona; j++)
    {
        cout << "Marka vozila je: " << (*(niz + index) + j)->markaVozila << endl;
        cout << "Naziv vozila je: " << (*(niz + index) + j)->nazivVozila << endl;
        cout << "Tip vozila je: " << *(*(niz + index) + j)->tipVozila << endl;
        cout << "Potrosnja po km: " << *(*(niz + index) + j)->potrosnja_goriva_po_km << endl;
    }cout << endl;
    delete[]potrosnja;
    potrosnja = nullptr;
}
void potrosnja_vozila_C(vozilo**niz, int red, int kolona) {
    float prosjekC = 0.0f;
    int brojac = 0;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            if (*(*(niz + i) + j)->tipVozila == 'C') {
                prosjekC += *(*(niz + i) + j)->potrosnja_goriva_po_km;
                brojac++;
               
            }
        }
    }
    if (brojac == 0) {

        cout << "Nema vozila tipa C. " << endl;
    }
    else
       prosjekC/= brojac;
    cout << "Prosjek potrosnje po km za sva vozila tipa C je: " << prosjekC;
   
}
void Dealokacija(vozilo**& niz, int red) {
    for (int i = 0; i < red; i++)
    {
        delete[]* (niz + i); 
    }
    delete[]niz;
    niz = nullptr;
}