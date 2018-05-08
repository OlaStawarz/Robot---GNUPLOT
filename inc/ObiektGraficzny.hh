#ifndef OBIEKTGRAFICZNY_HH
#define OBIEKTGRAFICZNY_HH
#define STnaRAD 0.0174532925

/*!
 * \file
 * \brief Definicja klasy ObiektGraficzny
 *
 * Plik zawiera definicję klasy ObiektGraficzny.
 */

#include <iostream>
#include "Wektor2D.hh"
#include "ZbiorWierzcholkow.hh"
#include "SWektor.hh"

/*!
 * \brief Modeluje obiekt, który ma swoją reprezentację graficzną
 *
 * Modeluje obiekt, który ma swoją reprezentację graficzną
 * w postaci łamanej. Może ona być łamaną zamkniętą w postaci
 * wieloboku lub otwartą. Ilość jej wierzchołków nie jest jawnie
 * ograniczona. Jedynym ograniczeniem jest dostępność pamięci
 * komputera.
 */
class ObiektGraficzny {
  /*!
   * \brief Współrzędne pozycji obiektu
   *
   *  Zawiera współrzędne punktu względem, którego podane są
   *  współrzędne punktów obrysu obiektu.
   */
   Wektor2D   _PolozenieObiektu;
  /*!
   * \brief Tablica wierzchołków
   *
   *  
   */
  //   Wektor2D   _TabWierz[7]; // To jest tylko tymczasowe rozwiązanie.
                            // Tu należy użyć szablonu wektor.
  // SWektor<STyp,SWymiar> _TabWierz[SWymiar];
  ZbiorWierzcholkow _TabWierz;
  
  
  public:
  /*!
   * \brief Inicjalizacja współrzędnych wierzchołków
   */
   void InicjalizujKsztalt();
  /*!
   * \brief Metoda zapisuje do pliku współrzędne wierzchołków
   */
   bool ZapiszDoPliku(const char* sNazwaPliku) const;
  /*!
   * \brief Metoda zapisuje do strumienia współrzędne wierzchołków
   */   
   bool ZapiszDoStrumienia(std::ostream& StrmWy) const;
  /*!
   * \brief Zmiania współrzędne położenia obiektu
   */
  void ZmienPolozenie(double x, double y);
  void DodajWierzcholek(Wektor2D punkt);
  Wektor2D& UzyskajPolozenieObiektu()
  {
    return _PolozenieObiektu;
  }
  ZbiorWierzcholkow&  UzyskajTabWierz()
  {
    return _TabWierz;
  }
};


#endif
