
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>

using namespace std;
//Struktura
struct vremenska_prognoza{
    char* padavine; //dozvoliti unos rijeci npr. "kisa" ili "snijeg"
    float* temperatura;
    float* vlaznost_vazduha;

    vremenska_prognoza()
    {
        padavine = new char;
        temperatura = new float;
        vlaznost_vazduha = new float;
    }
    ~vremenska_prognoza()
    {
        delete padavine;
        padavine = nullptr;
        delete temperatura;
        temperatura = nullptr;
        delete vlaznost_vazduha;
        vlaznost_vazduha = nullptr;
    }
};
//Deklarisanje funckija
void unos(vremenska_prognoza**, int, int);
void ispis(vremenska_prognoza**, int, int);
void unos1D(vremenska_prognoza*, int);
void najtacnijiMeteorolog(vremenska_prognoza**, vremenska_prognoza*, int, int);
void Dealokacija(vremenska_prognoza**&, int);
//main funkcija
int main() {
    int red, kolona;
    
    cout << "Unesite broj meteorologa. " << endl;
    cin >> red;
    cout << "Unesite broj dana. " << endl;
    cin >> kolona;
    vremenska_prognoza** niz = new vremenska_prognoza * [red];
    for (int i = 0; i < red; i++)
    {
        *(niz + i) = new vremenska_prognoza[kolona];
    }

    vremenska_prognoza* niz1D= new vremenska_prognoza[kolona];
    unos1D(niz1D, kolona);
    //srand(time(NULL));
    unos(niz, red, kolona);
    ispis(niz, red, kolona);
    najtacnijiMeteorolog(niz, niz1D, red, kolona);
    Dealokacija(niz, red);
    delete[]niz1D;
    niz1D = nullptr;
    return 0;
    cin.get();
}
//Definicije funkcija
void unos(vremenska_prognoza**niz, int red, int kolona) {
    cout << "Unesite podatke. " << endl;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            cin.ignore();
            do
            {
                cout << "Unesite vrstu padavine. Unesite S za snijeg i K za kisu. " << endl;
                cin >> *(*(niz + i) + j)->padavine; 
            } while ((*(*(niz + i) + j)->padavine != 's') && (*(*(niz + i) + j)->padavine != 'k'));
            cout << "Unesite temperaturu. " << endl;
            cin >> *(*(niz + i) + j)->temperatura;
            cout << "Unesite vlaznost_vazduha. " << endl;
            cin >> *(*(niz + i) + j)->vlaznost_vazduha;
           // *(*(niz + i) + j)->temperatura = rand() % 50 + 2;
            //*(*(niz + i) + j)->vlaznost_vazduha = rand() % 100 + 2;
        }
    }
}
void ispis(vremenska_prognoza**niz, int red, int kolona) {
    cout << endl << endl;
    for (int i = 0; i < red; i++)
    {
        
        for (int j = 0; j < kolona; j++)
        {
            cout << "Vrsta padavine: " << (*(*(niz + i) + j)->padavine) << endl;
            cout << "Temperatura :" << (*(*(niz + i) + j)->temperatura) << endl;
            cout << "Vlaznost vazduha :" << (*(*(niz + i) + j)->vlaznost_vazduha) << endl;
        }cout << endl;
        cout << "\n";
    }
}
void unos1D(vremenska_prognoza*niz1D, int kolona) {
    cout << "Unesite podatke. " << endl;
    for (int i = 0; i < kolona; i++)
    {
            cout << "Unesite vrstu padavine. Unesite s za snijeg i k za kisa. " << endl;
            cin >> *(niz1D + i)->padavine;
            cout << "Unesite temperaturu. " << endl;
            cin >> *(niz1D + i)->temperatura;
            cout << "Unesite vlaznost vazduha. " << endl;
            cin >> *(niz1D + i)->vlaznost_vazduha;
    }
}
void najtacnijiMeteorolog(vremenska_prognoza**niz, vremenska_prognoza*niz1D, int red, int kolona) {
    float* nizmet = new float[kolona]  {0}; //niz na pohranu svih razlika
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            *(nizmet+i) = abs(*(*(niz + i) + j)->temperatura - *(niz1D + i)->temperatura);
            cout << "Razlika je: " << *(nizmet+i)<< endl;
        }
    }
    int pomocna = 0;
    for (int i = 0; i < kolona; i++)
    {
        if (*(nizmet + i) < *(nizmet + pomocna)) {
            pomocna = i;
        }
    }
    cout << "Najtacniji meteorolog je na indexu: " << pomocna  << endl;

    delete[] nizmet;
    nizmet = nullptr; 
}
void Dealokacija(vremenska_prognoza**&niz, int red) {

    for (int i = 0; i < red; i++)
    {
        delete[] * (niz + i);
    }
    delete[] niz;
    niz = nullptr;
}

