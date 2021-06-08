
#include <iostream>
#include <fstream>
#include <string>
#include "menu.h"
#include "klasa.h"
#include "tablica_wysw.h"
#include "operacje_na_plikach.h"
#include "tablica.h"
using namespace std;



void menu()
{
    cout << "Poprawiony Projekt\tMateusz Piniarski\t(259573)" << endl;
    int w, k;
    int wybor_opcji;
    string nazwa;
    Arkusz arkusz;
    int **wskaznik;
    do
    {
        cout << "Jakie dzialanie chcesz wykonac?" << endl;
        cout << "1. tworzenie tablicy\n 2. wyswietlanie tablicy\n 3. Zapis do pliku txt. \n 4. Wczytanie z pliku \n 5. Zmiana liczby \n 6. Usuniecie tablicy \n 99.Zamkniecie programu"<<endl;
        cout<<""<<endl;
        cin >> wybor_opcji;

        if (wybor_opcji == 1)
        { int wiersz, kolumna;
        cout << "Jaki ma byc rozmiar arkusza?" << endl;
            cout << "Liczba kolumn: ";
                cin >> kolumna;
                    cout << "Liczba wierszy ";
                        cin >> wiersz;

            /*stworz_tablice(&arkusz);*/
        }

        else if (wybor_opcji == 2)
        {
            arkusz.wyswietlenie_tablicy();
        }

        else if (wybor_opcji == 3)
        {
            cout << "Jak ma nazywac sie plik zapisu?" << endl;
            cin >> nazwa;
            arkusz.zapis_funkcji(nazwa);
        }

        else if (wybor_opcji == 4)
        {
            cout << "Z jakiego pliku program ma pobrac dane?" << endl;
                cin >> nazwa;
                    wczytanie_funkcji(nazwa);

                        w = wartosc_wierszy(nazwa);

                            k = wartosc_kolumn(nazwa);
        }

        else if (wybor_opcji == 5)
        {   /*int opcja;
            int wartosc = 0;
            string wartosc_string;
            cout<<"Chcesz Edytować w liczbe czy String? \n Wcisnij 1, by string lub 2, by liczbe"<<endl;
            cin>>opcja;
            if (opcja == 1 )
            {
                arkusz.zamiana_wartosci(x,y,wartosc)
            }
            else if (opcja == 2 )
            {
               arkusz.zamiana_wartosci(x, y, wartosc)
            }
            while (opcja !=1)
            {
                cout<<"Niepoprawna odpowiedz, autodestrukcja za 5 sekund"<<endl;
                break;
            }
            while (opcja !=2)
            {
                cout<<"Niepoprawna odpowiedz, autodestrukcja za 5 sekund"<<endl;
                break;
            }*/
        }

        else if (wybor_opcji == 6)
        {
          arkusz.usuwanie_tablicy(wskaznik);
        }

        else if (wybor_opcji == 7)
        {
        }
        else if (wybor_opcji == 8)
        {
        }
  } 
    while (wybor_opcji != 99);
}

 