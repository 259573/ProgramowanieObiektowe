#include <iostream>
#include <fstream>
#include "klasa.h"
#include "menu.h"
#include <cstdlib>
#include <string>
#include "operacje_na_plikach.h"
using namespace std;

int Arkusz::zapis_txt(string nazwa_pliku) 
{
    nazwa_pliku+=".txt";
    ofstream (plik1);
  
    plik1.open(nazwa_pliku);
    if(plik1.good()==true)
    {
    
        plik1<<wiersze<<endl;
        plik1<<kolumny<<endl; 
    
        for(int i=0; i<wiersze; i++)
        {
            for(int j=0; j<kolumny; j++)
            {
                plik1 << obiekt[i][j]->wez_wartosc()<<"\t";
            }
            plik1 << endl;
        } 
        
        plik1.close();
        return 0;
    }
    else
    {
        return 1;
    }
    
    
   
}

int Arkusz::odczyt(std::string nazwa_pliku) 
{
    
    int w=0;
    int k=0;
    int* typk;
    std::string a;
    
    nazwa_pliku+=".txt";
    
    ifstream(plik2);
    plik2.open(nazwa_pliku);
    if(plik2.good()==true)
    {
      
       
        plik2>>w;
        plik2>>k;
        typk = typ_kolumny(k);
        
        
        
        this->obiekt = aktualizacja_rozmiaru(w, k, typk);
        this->wiersze = w;
        this->kolumny = k;

        for(int i=0;i<w; i++)
        {
            for(int j=0;j<k; j++)
            {
                plik2 >> a;
                obiekt[i][j]->ustaw_wartosc(a);
            }
        }
        
        
    
        
        plik2.close();
        return 0;
    }
    else 
    {
        return 1;
    }
    
}