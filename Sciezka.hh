#ifndef SCIEZKA_HH
#define SCIEZKA_HH

/*!
 * \file
 * \brief Definicja klasy Sciezka
 *
 * Plik zawiera definicję klasy Sciezka.
 */

#include "ObiektGraficzny.hh"

/*!
 * \brief Modeluje sciezke, ktora reprezentuje ruch robota
 *
 * Rysuje sciezke, ktora reprezentuje ruch robota. Zawiera metode
 * Dodaj, ktora odpowiada za dodanie wierzcholka do wskazanego
 * punktu.
 */

class Sciezka: public ObiektGraficzny{
public:
  void Dodaj(const Wektor2D& punkt)
  {
    DodajWierzcholek(punkt);
  }
  
};

#endif
