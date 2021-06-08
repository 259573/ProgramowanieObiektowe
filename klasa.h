#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Komorka;


class Arkusz
{
    int w;
    int k;
    Komorka ***tablica;
    bool *czy_tekstowa;
    
public:
  
    Arkusz(){}
    
    Arkusz(int wiersze, int kolumny, bool *tekstowa);
    
    int zamiana_wartosci(int w, int k, int wartosc);
    int zwrot_wartosci(int w, int k);
    int zamiana_wartosci(int w, int k, std::string wartosc);
    std::string zwrot_wartosci_tekstowej(int w, int k);
    int zwrot_wiersza();
    int zwrot_kolumny();
    bool czy_kolumna_jest_tekstowa(int k);
    void usuwanie_tablicy(int **wskaznik);
    void wyswietlenie_tablicy();
    void zapis_funkcji(std::string nazwa);
};
void wyswietlenie_tablicy(Arkusz arkusz1);

class Komorka
{
public:
    
    virtual void ustaw_wartosc(std::string wartosc_string) = 0;
    
    virtual std::string zwrot_wartosci() = 0;
    
};
class Komorka_Liczbowa : public Komorka
{
    int wartosc = 0;

public:
    void ustaw_wartosc(int wartosc);
    void ustaw_wartosc(std::string wartosc_string);
    int zwrot_wartosci_liczbowej();
    std::string zwrot_wartosci_tekstowej();
    bool czy_komorka_jest_tekstem();
};
class Komorka_Tekstowa : public Komorka
{
    std::string wartosc_string = " ";

public:
    void ustaw_wartosc(int wartosc);
    void ustaw_wartosc(std::string wartosc_string);
    int zwrot_wartosci_liczbowej();
    std::string zwrot_wartosci_tekstowej();
    bool czy_komorka_jest_tekstem();
};