#include <iostream>
#include "menu.h"
#include "klasa.h"
#include <cstdlib>
#include <stdlib.h>
#include "operacje_na_plikach.h"
#include <fstream>
#include <string>
using namespace std;
int wybor;



void menu_tekst();
void wyswietl_menu(Arkusz arkusz)
{
    int w = 0; 
    int k = 0; 
    int *typk;
    int wybor2;
    int blad_dodaj_wartosc = 0;
    int blad_zmiana_wartosci = 0;
    int blad_srednia = 0;
    int blad_zapisu = 0;
    int blad_odczytu = 0;
    
    string nazwa_pliku;
    string wartosc;
    string pozwolenie;
    double wynik;
    string decyzja;
    int numer;
    do
    {
        
        switch(wybor)
        {
            case 1: 
                cout<<"Podaj ilosc wierszy:";
                cin>>w;
                cout<<endl;
                cout<<"Podaj ilosc kolumn:";
                cin>>k;
                typk = arkusz.typ_kolumny(k);
                arkusz.nowa_tablica(w, k, typk);
                system("clear");
                cout<<"Arkusz został utworzony!"<<endl;
            break;
         
            case 2: 
                system("clear");
                arkusz.wyswietl_tablice();
            break;
            
            case 3: 
                cout<<"Podaj nazwe pliku (bez rozszerzenia!), do ktorego chcesz zapisac arkusz"<<endl;
                cin>>nazwa_pliku;
                blad_zapisu = arkusz.zapis_txt(nazwa_pliku);
                if(blad_zapisu==0)
                {
                    cout<<"operacja wykonana poprawnie"<<endl;
                }
                else
                {
                    cout<<"blad. operacja nie zostala wykonana"<<endl;
                    cout<<"blad zapisu pliku"<<endl;
                }
                
            break;
            
            case 4:
                cout<<"Podaj nazwe pliku bez rozszerzenia, z ktorego chcesz odczytac arkusza"<<endl;
                cin>>nazwa_pliku;
                cout<<endl;
                cout<<"Powinienes sprawdzic przed odczytaniem, jakie wartosci zawieraja poszczegolne kolumny!"<<endl;
                blad_odczytu = arkusz.odczyt(nazwa_pliku);
                if(blad_odczytu==0)
                {
                    cout<<"operacja wykonana poprawnie"<<endl;
                }
                else
                {
                    cout<<"Blad, operacja nie zostala wykonana"<<endl;
                    cout<<"nieprawidlowa nazwa pliku"<<endl;
                }
                
                
            break;
            
            case 5:
                
                arkusz.jaka_kolumna(typk);
                cout<<"Jaka wartosc chcesz wprowadzic?"<<endl;
                cin>>wartosc;
                cout<<"Podaj numer wiersza"<<endl;
                cin>>w;
                cout<<"Podaj numer kolumny"<<endl;
                cin>>k;
                blad_zmiana_wartosci = arkusz.zmiana_wartosci(w, k, wartosc);
                if(blad_zmiana_wartosci==0)
                {
                    cout<<"Powodzenie!"<<endl;
                }
                else
                {
                    cout<<"niepowodzenie"<<endl;
                    cout<<"blad zmiany wartosci"<<endl;
                }
                
            break;
            
            case 6:
                
                cout<<"Zmniejszajac wielkosc arkusz ryzykujesz utrate danych, czy chcesz kontynuowac?"<<endl;
                cout<<"y/n"<<endl;
                cin>>pozwolenie;
                if(pozwolenie == "y")
                {
                cout<<"Podaj nowa wielkosc arkusza"<<endl;
                cout<<"Najpierw liczba wieszy:"<<endl;
                cin>>w;
                cout<<"Teraz liczba kolumn:"<<endl;
                cin>>k;
                arkusz.zmien_rozmiar(w,k,typk);
                }
                else
                {
                    cout<<"nie wykonano zadnej czynnosci"<<endl;
                }
                
                break;
            
            case 7:
                system("clear");
                break;
          
            case 8:
                cout<<"Jakie działanie wykonać?"<<endl;
                cout<<"1.Sumowanie wedlug wierszy"<<endl;
                cout<<"2.Sumowanie wedlug kolumn"<<endl;
                cout<<"3.Najwieksza wartosc w wierszu"<<endl;
                cout<<"4.Najmniejsza wartosc w kolumnie"<<endl;
                cout<<"5.Srednia wartosc wiersza/kolumny"<<endl;
                cout<<"6.Cofnij"<<endl;
                cin>>wybor2;
                switch(wybor2)
                {
                    case 1:
                    cout<<"Mozna sumowac tylko wiersze z wartosciami liczbowymi, upewnij sie, ze wlasnie taki chcesz wykorzystac!"<<endl;
                    arkusz.wyswietl_tablice();
                    cout<<endl;
                    cout<<"Kontynuowac? Jesli nie ma wiersza z samymi liczbami to przerwij proces."<<endl;
                    cout<<"y/n"<<endl;
                    cin>>pozwolenie;
                    if(pozwolenie == "y")
                    {
                        cout<<"Który wiersz chcesz zsumować?"<<endl;
                        cin>>w;
                        wynik = arkusz.sumowanie_wierszy(w);
                        cout<<"Wynik sumowania wiersza nr "<<w<<" to "<<wynik<<endl;
                    }
                    else
                    {
                        cout<<"Procedura nie zostala wykonana"<<endl;
                    }
                    
                    break;

                    case 2:
                    cout<<"Mozna sumowac tylko kolumny z wartosciami liczbowymi, upewnij sie, ze wlasnie takie chcesz wykorzystac!"<<endl;
                    arkusz.wyswietl_tablice();
                    cout<<endl;
                    cout<<"Kontynuowac? Jesli nie ma kolumny z samymi liczbami to przerwij proces."<<endl;
                    cout<<"y/n"<<endl;
                    cin>>pozwolenie;
                    if(pozwolenie == "y")
                    {
                        cout<<"Która kolumne chcesz zsumować?"<<endl;
                        cin>>k;
                        wynik = arkusz.sumowanie_kolumn(k);
                        cout<<"Wynik sumowania wiersza nr "<<k<<" to "<<wynik<<endl;
                    }
                    else
                    {
                        cout<<"Procedura nie zostala wykonana"<<endl;
                    }
                    break;

                    case 3:
                    cout<<"Najwieksza wartosc mozna wylonic tylko z liczb!"<<endl;
                    arkusz.wyswietl_tablice();
                    cout<<endl;
                    cout<<"Kontynuowac? Jesli nie ma wiersza z samymi liczbami to przerwij proces."<<endl;
                    cout<<"y/n"<<endl;
                    cin>>pozwolenie;
                    if(pozwolenie == "y")
                    {
                        cout<<"Podaj numer wiersza"<<endl;
                        cin>>w;
                        wynik = arkusz.naj_wart_wiersza(w);
                        cout<<"Najwieksza wartosc wiersza nr "<<w<<" to "<<wynik<<endl;
                    }
                    else
                    {
                        cout<<"Procedura nie zostala wykonana"<<endl;
                    }
                    
                    break;

                    case 4:
                    cout<<"Najwieksza wartosc mozna wylonic tylko z liczb!"<<endl;
                    arkusz.wyswietl_tablice();
                    cout<<endl;
                    cout<<"Kontynuowac? Jesli nie ma kolumny z samymi liczbami to przerwij proces."<<endl;
                    cout<<"y/n"<<endl;
                    cin>>pozwolenie;
                    if(pozwolenie == "y")
                    {
                        cout<<"Podaj numer kolumny"<<endl;
                        cin>>k;
                        wynik = arkusz.naj_wart_kolumny(k);
                        cout<<"Najwieksza wartosc kolumny nr "<<k<<" to "<<wynik<<endl;
                    }
                    else
                    {
                        cout<<"Procedura nie zostala wykonana"<<endl;
                    }
                    
                    break;

                    case 5:
                    cout<<"Srednia wartosc mozna policzyc tylko z liczb!"<<endl;
                    arkusz.wyswietl_tablice();
                    cout<<endl;
                    cout<<"Kontynuowac? Jesli nie ma kolumny lub wiersza z samymi liczbami to przerwij proces."<<endl;
                    cout<<"y/n"<<endl;
                    cin>>pozwolenie;
                    if(pozwolenie == "y")
                    {
                        cout<<"Chcesz policzyc srednia wartosc wiersza czy kolumny?"<<endl;
                        cout<<"w/k:";
                        cin>>decyzja;
                        cout<<endl;
                        cout<<"Podaj numer:";
                        cin>>numer;
                        cout<<endl;
                        wynik = arkusz.srednia(numer,decyzja);
                        if(decyzja == "w")
                        {
                            cout<<"Srednia wartosc wiersza nr "<<numer<<" to "<<wynik<<endl;
                        }
                        else if(decyzja == "k")
                        {
                            cout<<"Srednia wartosc kolumny nr "<<numer<<" to "<<wynik<<endl;
                        }
                    
                    }
                    else
                    {
                        cout<<"Procedura nie zostala wykonana"<<endl;
                    }
                    
                    break;
                    
                }
                break;
               
            case 9:
                system("clear");
                break;
            default:
                cout<<"Podales zla liczbe, podaj ponownie"<<endl;
            
        }
    }
    while(wybor != 9);
}

int* Arkusz::typ_kolumny(int k)
{
    int *tk = new int[k];
    cout<<"1-liczba"<<endl;
    cout<<"0-string"<<endl;
    for(int i=0; i<k; i++)
    {
        cout<<"kolumna:"<<i+1<<endl;
        cin>>tk[i];
    }
    return tk;
}

void Arkusz::jaka_kolumna(int* typ)
{
    
    for(int i=0; i<kolumny; i++)
    {
        if(typ[i]==1)
        {
            cout<<"kolumna nr: "<<i+1<<"to kolumna liczbowa"<<endl;
        }

        if(typ[i]==0)
        {
            cout<<"kolumna nr: "<<i+1<<"to kolumna tekstowa"<<endl;
        }
    }
}
void menu_tekst()
{   cout<<"Poprawiony Projekt \t Mateusz Piniarski 259573"<<endl;
        cout<<"Jakie działanie wykonać?"<<endl;
        cout<<"1-stworz nowa tablice"<<endl;
        cout<<"2-wyswietl tablice"<<endl;
        cout<<"3-zapisz na dysk"<<endl;
        cout<<"4-odczytaj z dysku"<<endl;
        cout<<"5-zmien wartosc w arkuszu"<<endl;
        cout<<"6-zmien rozmiar tablicy"<<endl;
        cout<<"7-wyczysc ekran"<<endl;
        cout<<"8-Matematyka"<<endl;
        cout<<"9-wyjdz"<<endl;
        cin>>wybor;
}
