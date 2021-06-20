#include <iostream>
#include "klasa.h"
#include "menu.h"
#include "operacje_na_plikach.h"
using namespace std;

void Arkusz::wyswietl_tablice()
{  
    cout<<"Obiekt "<< wiersze << 'X' << kolumny << endl;
        for(int i=0; i<wiersze; i++)
        {
            for(int j=0; j<kolumny; j++)
            {
                cout<<obiekt[i][j]->wez_wartosc()<<"\t";
            }
         cout<<endl;
        }
}