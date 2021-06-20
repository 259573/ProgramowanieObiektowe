#pragma once
#include <iostream>
#include <fstream>


/**
 * @brief Funkcja służy do zapisu arkusza do pliku tekstowego.
 * @param[in] nazwa_pliku - plik, do którego zostanie zapisany arkusz
 * @return wartość 0 oznacza prawidłowo wykonaną operację, a wartość 1 oznacza błąd
 */
int zapis(std::string nazwa_pliku);
/**
 * @brief Funkcja służy do odczytu arkuszy z dysku, dokładnie z pliku tekstowego.
 * @param[in] nazwa_pliku - plik, z którego odczytamy arkusz
 */
int odczyt(std::string nazwa_pliku);
