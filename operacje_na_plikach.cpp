#include <iostream>
#include <fstream>
#include "operacje_na_plikach.h"
#include "klasa.h"
using namespace std;

int zapis(Arkusz nowyarkusz)
{
    ofstream plik("arkusz.csv");
    if (plik.good())
    {
        plik << nowyarkusz.zwrot_wiersza() << " " << nowyarkusz.zwrot_kolumny() << endl;
        for (int i = 0; i < nowyarkusz.zwrot_kolumny(); i++)
        {
            plik << ((nowyarkusz.czy_kolumna_jest_tekstowa(i)) ? "1" : "0") << "\t";
        }
        plik << endl;
        for (int w = 0; w < nowyarkusz.zwrot_wiersza(); w++)
        {
            for (int k = 0; k < nowyarkusz.zwrot_kolumny(); k++)
            {
                plik << nowyarkusz.zwrot_wartosci_tekstowej(w, k) << " ";
            }
            plik << endl;
        }
        return 0;
    }
    return 1;
}
int odczyt(Arkusz *arkusz)
{
    ifstream plik("arkusz.csv");
    if (plik.good())
    {
        int wiersze, kolumny;
        plik >> wiersze;
        plik >> kolumny;
        if (wiersze < 1 || kolumny < 1)
        {
            return 2;
        }
        bool *tekstowa = new bool[kolumny];
        for (int i = 0; i < kolumny; i++)
        {
            int typ = 0;
            plik >> typ;
            if (typ)
            {
                tekstowa[i] = true;
            }
            else
            {
                tekstowa[i] = false;
            }
        }
        Arkusz nowyarkusz(wiersze, kolumny, tekstowa);
        string tekst;
        int temp = 0;
        plik.ignore(10, '\n');
        for (int w = 0; w < wiersze; w++)
        {
            for (int k = 0; k < kolumny; k++)
            {
                if (tekstowa)
                {
                    plik >> tekst;
                    nowyarkusz.zamiana_wartosci(w, k, tekst);
                }
                else
                {
                    plik >> temp;
                    nowyarkusz.zamiana_wartosci(w, k, temp);
                }
            }
        }
        *arkusz = nowyarkusz;
        return 0;
    }
    return 1;
}