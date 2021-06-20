#include <iostream>
#include "klasa.h"
#include "menu.h"
#include "operacje_na_plikach.h"
using namespace std;

void Arkusz::nowa_tablica(int w, int k, int* typk)
{
    this->wiersze = w;
    this->kolumny = k;
    this->obiekt = tworzenie_tablicy(w, k, typk);
}
Komorka*** Arkusz::tworzenie_tablicy(int w, int k, int* typk)     
{  
    
    Komorka ***arkusz = new Komorka**[w];

    for(int i=0; i<w;i++)
    {
       arkusz[i]=new Komorka*[k];
       
       for(int j=0; j<k; j++)
       {
            if(typk[j]==0)
            {
                arkusz[i][j] = new Komorka_String;

            }
           
            if(typk[j]==1)
            {
                arkusz[i][j] = new Komorka_Liczb;
            }
           

       }
    
    }

    
    return arkusz;
}



void Komorka_String::ustaw_wartosc(std::string pole)
{
    this->komorka_string = pole;
}

void Komorka_Liczb::ustaw_wartosc(std::string pole)
{
    this->komorka_int = stod(pole);
}

std::string Komorka_String::wez_wartosc()
{
    return komorka_string;
}

std::string Komorka_Liczb::wez_wartosc()
{
    return to_string(komorka_int);
}

bool Komorka_Liczb::wez_kolumne()
{
    return false;
}

bool Komorka_String::wez_kolumne()
{
    return true;
}



int Arkusz::zmiana_wartosci(int w, int k, std::string wartosc)
{
   if((wiersze<w || kolumny<k))
    {
        return 1;
    }
    else
    {
        if(obiekt[w-1][k-1]->wez_kolumne()==false)
        {
            this->obiekt[w-1][k-1]->ustaw_wartosc(wartosc);
        }

        if(obiekt[w-1][k-1]->wez_kolumne()==true)
        {
            this->obiekt[w-1][k-1]->ustaw_wartosc(wartosc);
        }
        return 0;
    }
  
}

Komorka*** Arkusz::aktualizacja_rozmiaru(int w, int k, int* typ)
{
    Komorka*** kopia = tworzenie_tablicy(w, k, typ);
    
    
    if((wiersze<=w || kolumny<=k))
    {
        kopiowanie(obiekt, kopia, wiersze, kolumny);
    }
    else
    {
        kopiowanie(obiekt, kopia, w, k);
    }
    
    return kopia; 
    
}

void Arkusz::zmien_rozmiar(int w,int k, int* typ)
{
    this->obiekt = aktualizacja_rozmiaru(w,k,typ);
    this->wiersze = w;
    this->kolumny = k;
}

void Arkusz::kopiowanie(Komorka ***obiekt_wej, Komorka*** obiekt_wyj, int w, int k)
{
    
    
    
    for(int i = 0; i<w; i++)
    {
        for(int j = 0; j<k; j++)
        {
            if(obiekt_wej[i][j]->wez_kolumne()==false)
            {
                obiekt_wyj[i][j]->ustaw_wartosc(obiekt_wej[i][j]->wez_wartosc());
            }

            if(obiekt_wej[i][j]->wez_kolumne()==true)
            {
                obiekt_wej[i][j]->ustaw_wartosc(obiekt_wej[i][j]->wez_wartosc());
            }
        }
    }
}

double Arkusz::sumowanie_wierszy(int w)
{
    double a = 0;
    double b = 0;
    
    for(int j=0;j<kolumny; j++)
    {
        a = stod(obiekt[w-1][j]->wez_wartosc());
        b = b + a;
    }
    
  
    return b;
}

double Arkusz::sumowanie_kolumn(int k)
{
    double a = 0;
    double b = 0;
    
    for(int i=0;i<wiersze; i++)
    {
        a = stod(obiekt[i][k-1]->wez_wartosc());
        b = b + a;
    }
    
  
    return b;
}
double Arkusz::naj_wart_wiersza(int w)
{
    double a = 0;
    a = stod(obiekt[w-1][0]->wez_wartosc());
    for(int j=0;j<kolumny-1; j++)
    {
        if(stod(obiekt[w-1][j]->wez_wartosc())<stod(obiekt[w-1][j+1]->wez_wartosc()))
        {
            a = stod(obiekt[w-1][j+1]->wez_wartosc());
        }
        
    }
    
  
    return a; 
}
double Arkusz::naj_wart_kolumny(int k)
{
    double a = 0;
    a = stod(obiekt[0][k-1]->wez_wartosc());
    for(int i=0;i<wiersze-1; i++)
    {
        if(stod(obiekt[i][k-1]->wez_wartosc())<stod(obiekt[i+1][k-1]->wez_wartosc()))
        {
            a = stod(obiekt[i+1][k-1]->wez_wartosc());
        }
        
    }
    
  
    return a; 
}
double Arkusz::srednia(int num, std::string decyzja)
{
    double a = 0;
    double b = 0;
    if(decyzja == "w")
    {
        for(int j=0;j<kolumny; j++)
        {
            a = stod(obiekt[num-1][j]->wez_wartosc());
            b = b + a;
        }
        b = b/kolumny;
        return b;
    }
    else if(decyzja == "k")
    {
        for(int i=0;i<wiersze; i++)
        {   
            a = stod(obiekt[i][num-1]->wez_wartosc());
            b = b + a;
        }
        b = b/wiersze;
        return b;
    }
    return a;
}

