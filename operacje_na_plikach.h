#pragma once
#include <iostream>
#include <fstream>


/*!
* \brief Funkcja przenosi wartosci zapisane w arkuszu do zewnetrznego pliku tekstowego, a gdy ten nie istnieje, rowniez go tworzy.
*
*\param[in, out] tablica to struktura, ktora przechowuje dane o arkuszu (wskaznik do tablicy, liczbe wierszy i kolumn)
*\param[in] nazwa to argument odpowiadajacy nazwie pliku, do ktorego ma zostac zapisana zawartosc arkusza
*/
void zapis_funkcji(std::string nazwa);

/*!
* \brief Funkcja przenosi wartosci zapisane w zewnetrznym pliku tekstowym do arkusza.
*
*\param[in] nazwa to argument, ktory odpowiada nazwie pliku, z ktorego maja zostac pobrane dane
*\return zwracany jest wskaznik do arkusza, aby moc bazowac na otrzymanej tablicy w kolejnym pliku .cpp
*/
int** wczytanie_funkcji(std::string nazwa);

/*!
* \brief Funkcja wczytuje liczbe kolmun tablicy.
*
*\param[in] nazwa to argument, ktory odpowiada nazwie pliku, z ktorego maja zostac pobrane dane
*\return pozwala na zwrocenie liczby kolumn
*/
int wartosc_kolumn(std::string nazwa);

/*!
* \brief Funkcja wczytuje liczbe wierszy tablicy.
*
*\param[in] nazwa to argument, ktory odpowiada nazwie pliku, z ktorego maja zostac pobrane dane
*\return pozwala na zwrocenie liczby wierszy
*/
int wartosc_wierszy(std::string nazwa);