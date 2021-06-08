
#include <iostream>
#include <fstream>
#include "klasa.h"
#include <string>
#include "tablica.h"
using namespace std;





int Arkusz::zamiana_wartosci(int x, int y, int wartosc)
{
  if (w < x || k < y)
  {
    return 1;
  }
  else if (x < 0 || y < 0)
  {
    return 1;
  }
  else
  {
    
    tablica[x][y]->ustaw_wartosc(wartosc);
  }
  return 0;
}

int Arkusz::zamiana_wartosci(int x, int y, std::string wartosc)
{
  if (w < x || k < y)
  {
    return 1;
  }
  else if (x < 0 || y < 0)
  {
    return 1;
  }
  else
  {
    tablica[x][y]->ustaw_wartosc(wartosc);
  }
  return 0;
}


void Arkusz::usuwanie_tablicy(int **wskaznik)
{
    for ( int i = 0; i < w; i++)
    {
        delete [] wskaznik[i];
    }

delete [] wskaznik;
wskaznik = NULL;
}



void Komorka_Liczbowa::ustaw_wartosc(int wartosc)
{
  this->wartosc = wartosc;
}


int Komorka_Liczbowa::zwrot_wartosci_liczbowej()
{
  return wartosc;
}
string Komorka_Liczbowa::zwrot_wartosci_tekstowej()
{
  return std::to_string(wartosc);
}
bool Komorka_Liczbowa::czy_komorka_jest_tekstem()
{
  return false;
}

bool Arkusz::czy_kolumna_jest_tekstowa(int k)
{
  return czy_tekstowa[k];
}

void Komorka_Tekstowa::ustaw_wartosc(int wartosc)
{
  this->wartosc_string = to_string(wartosc);
}
void Komorka_Tekstowa::ustaw_wartosc(string wartosc_string)
{
  this->wartosc_string = wartosc_string;
}
int Komorka_Tekstowa::zwrot_wartosci_liczbowej()
{
  return 0;
}
string Komorka_Tekstowa::zwrot_wartosci_tekstowej()
{
  return wartosc_string;
}
bool Komorka_Tekstowa::czy_komorka_jest_tekstem()
{
  return true;
}
