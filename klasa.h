/// @file
#include <iostream>
#include "menu.h"
#include <cstdlib>
#include <stdlib.h>
#include "operacje_na_plikach.h"
#include <fstream>
#include <string>
/*!
  Klasa, która zawiera dane i metody dotyczące komorek wewnątrz arkusza.
  */
class Komorka
{     
 
   public:
  /**
   * @brief Metoda wirtualna pobierająca wartośc pól.
   * 
   * @return string - przekonwertowaną wartość "obiekt_int".
   */
  virtual string wez_wartosc()=0;
  

  /**
   * @brief Metoda wirtualna służąca do ustawiania wartości arkusza.
   * 
   * @param string - zmienna typu string
   */
  virtual void ustaw_wartosc(string)=0;
  
  /**
   * @brief Metoda wirtualna zwracająca informację o rodzaju kolumny.
   * 
   * @return true - kolumna ze zmiennymi typu string
   * @return false - kolumna ze zmiennymi typu double
   */
  virtual bool wez_kolumne()=0;
};

/*!
  Klasa, która zawiera pola i metody odpowiadające jednej komórce typu string
  */
class Komorka_String: public Komorka
{
  /**
   * @brief Zmienna typu string, która odpowiada jednej komórce arkusza.
   * 
   */
  string komorka_string = "X";

public:
  
  /**
   * @brief Metoda odpowiadająca za ustawienie wartości w komórce.
   * @param string - zmienna typu string
   */
  void ustaw_wartosc(string);
  
  /**
   * @brief Metoda, która zwraca wartość komórki.
   * 
   * @return string 
   */
  string wez_wartosc();
  
  /**
   * @brief Metoda zwracająca informacje o typie zmiennej jaki aktualnie komórka przechowuje.
   * 
   * @return true - typ string 
   */
  bool wez_kolumne();
  };

class Komorka_Liczb: public Komorka
{
  
  /**
   * @brief Zmienna typu double, która odpowiada jednej komórce arkusza.
   * 
   */
  int komorka_int = 0;
public:
  
  /**
   * @brief Metoda odpowiadająca za ustawienie wartości w komórce.
   * @param string - zmienna typu string, która jest konwertowana na zmienną typu double.
   */
  void ustaw_wartosc(string);
  
  /**
   * @brief Metoda, która zwraca wartość komórki.
   * 
   * @return string 
   */
  string wez_wartosc();
  
  /**
   * @brief Metoda zwracająca informacje o typie zmiennej jaki aktualnie komórka przechowuje.
   * 
   * @return false - typ int
   */
  bool wez_kolumne();
};



/*!
  Klasa zawierająca parametry arkusza, arkusz oraz metody, które go modyfikują.
 */
class Arkusz 
{
 
  private:

  
  /**
   * @brief rozmiar(kolumny)
   */
  int kolumny;

  /**
   * @brief rozmiar(wiersze)
   */
  int wiersze;

  /**
   * @brief Potrójny wskaźnik do obiektu klasy Komorka(arkusz)
   */
  Komorka*** obiekt;

  /**
 * \brief To funkcja służąca do tworzenia arkusza. 
 * @param[in] wiersze - ilość wierszy
 * @param[in] kolumny - ilość kolumn
 * @param[in] typ - informacja o rodzaju kolumny
 * @return arkusz - potrójny wskaźnik do obiektu klasy Komorka
 */
  Komorka*** tworzenie_tablicy(int wiersze, int kolumny, int* typ);

 
  
  /**
 * \brief To funkcja służąca do zmieniania wielkosci tablicy (arkusza).
 * @param[in] w - ilość wierszy, którą będzie mieć zmodyfikowana tablica
 * @param[in] k - ilość kolumn, którą będzie mieć zmodyfikowana tablica
 * @param[in] typ - informacja o rodzaju kolumny
 * @return arkusz - zmodyfikowa obiekt klasy Komorka
 */
  Komorka*** aktualizacja_rozmiaru(int w, int k, int* typ);

  /**
 * \brief Ta funkcja kopiuje tablice (arkusze).
 * @param[in,out] obiekt_wyjscie - potrójny wskaźnik do obiektu klasy Komorka (arkusz)
 * @param[in] obiekt_wejscie - potrójny wskaźnik do obiektu klasy komorka (arkusz)
 * @param[in] w - ilosc wierszy jaka ma być skopiowana
 * @param[in] k - ilosc kolumn jaka ma być skopiowana
 */
  void kopiowanie(Komorka ***obiekt_wej,Komorka*** obiekt_wyj, int w, int k);

  public:


 
 /**
 * \brief Ta funkcja zmienia wartość poszczególnych komórek.
 * @param[in] w- numer wiersza, w którym chcemy zmienić wartość
 * @param[in] k - numer kolumny, w której chcemy zmienić wartość
 * @param[in] wartosc - wartość, którą chcemy wstawić do konkretnej komórki 
 * @return błąd - domyślnie zwraca wartość 0, która oznacza powodzenie, w przypadku niepowodzenia - zwróci 1.
 */
  int zmiana_wartosci(int w, int k, std::string wartosc);

  /**
 * @brief Ta funkcja służy do zapisu arkusza do pliku tekstowego.
 * @param[in] nazwa_pliku - plik, do którego zostanie zapisany arkusz
 * @return wartość 0 oznacza prawidłowo wykonaną operację, a wartość 1 oznacza błąd
 */
  int zapis_txt(std::string nazwa_pliku);

/**
 * @brief Ta funkcja służy do zapisu w pliku csv
 * param[in] arkusz - plik, do ktorego zapisany będzie akrusz
 * @return wartość 0 oznacza prawidłowo wykonaną operację, a wartość 1 oznacza błąd
 */
  /*int zapis_csv();*/

  /**
 * @brief Ta funkcja służy do odczytu arkuszy z dysku, dokładnie z pliku tekstowego.
 * @param[in] nazwa_pliku - plik, z którego odczytamy arkusz
 * @return wartość 0 oznacza powodzenie, a wartość jeden oznacza błąd
 */
  int odczyt(std::string nazwa_pliku);

  /**
   * @brief Funkcja służąca do stworzenia nowej tablicy.
   * 
   * @param[in] w - ilość wierszy 
   * @param[in] k - ilość kolumn
   * @param[in] typ - informacja o rodzaju kolumn
   */
  void nowa_tablica(int w, int k, int* typ);

  /**
 * \brief Funkcja służąca do wyświetlania arkusza. 
 */
  void wyswietl_tablice();

  /**
   * @brief 
   * 
   * @param[in] w - nowy rozmiar(wiersze)
   * @param[in] k - nowy rozmiar(kolumny)
   * @param[in] typ - informacja o rodzaju kolumn 
   */
  void zmien_rozmiar(int w,int k, int* typ);
  
  /**
   * @brief Metoda sumująca wartość w konkretnym wierszu.
   * 
   * @param w - numer wiersza
   * @return double - suma
   */
  double sumowanie_wierszy(int w);

  /**
   * @brief Metoda sumująca wartość w konkretnej kolumnie.
   * 
   * @param k - numer kolumny
   * @return int - suma
   */
  double sumowanie_kolumn(int k);

  /**
   * @brief Metoda znajdująca największą wartość w wierszu.
   * 
   * @param w -numer wiersza
   * @return double - największa wartość wiersza
   */
  double naj_wart_wiersza(int w);

  /**
   * @brief Metoda znajdująca największą wartość w kolumnie.
   * 
   * @param k - numer kolumny
   * @return double - największa wartość kolumny
   */
  double naj_wart_kolumny(int k);

  /**
   * @brief Metoda licząca średnia z kolumn lub wierszy.
   * 
   * @param numer - numer kolumny/wiersza
   * @param decyzja - decyzja(wiersze/kolumny)
   * @return double =średnią wartość
   */
  double srednia(int numer, std::string decyzja);

  /**
   * @brief Metoda pokazująca jakiego rodzaju są kolumny.
   * 
   * @param typ - informacja o rodzaju kolumn
   */
  void jaka_kolumna(int* typk);

  /**
   * @brief Metoda pobierająca informacje od użytkownika jakiego rodzaju maja powstać kolumny.
   * 
   * @param k 
   * @return int* - wskaźnik, tablica dynamiczna zawierająca informacje o typach kolumn. 
   */
  int* typ_kolumny(int k);
};

