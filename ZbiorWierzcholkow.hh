#ifndef ZBIORWIERZCHOLKOW_HH
#define ZBIORWIERZCHOLKOW_HH

/*!
 * \file
 * \brief Definicja klasy Zbior Wierzcholkow
 *
 * Plik zawiera definicję klasy Zbior Wierzcholkow.
 */

#include "Wektor2D.hh"
#include <vector>

/*!
 * \brief Deklaracja zbioru wierzcholkow
 * 
 * Zbior wierzcholkow opiera sie na bibliotece vector, w klasie
 * zawarte sa przeciazenia operatora indeksowania oraz metody - Dodaj
 * (operujaca na funkcji push_back), Usun (operujaca na funkcji pop_back)
 * oraz Ilosc Wierzcholkow zwracajaca ilosc wierzcholkow.
 * 
 */

class ZbiorWierzcholkow : public std::vector<Wektor2D>{
public:
  const Wektor2D & operator [](const int Indeks) const
  { return at(Indeks);}
  Wektor2D &  operator [] (const int Indeks)
  {return at(Indeks); }
  void Dodaj(const Wektor2D Punkt)
  {
    push_back(Punkt);
  }
  int Ilosc_Wierzcholkow() {return size();}
  void Usun()
  {
    pop_back();
  }
  
};

#endif 
