#ifndef ROBOT_HH
#define ROBOT_HH

/*!
 * \file
 * \brief Definicja klasy Robot
 *
 * Plik zawiera definicję klasy Robot.
 */

#include <iostream>
#include "ObiektGraficzny.hh"

/*!
 * \brief Modeluje robota, ktory wyswietlany jest na scenie
 * Modeluje robota, ktory wyswietlany jest na scenie. Robot jest
 * geometrycznym kształtem nadanym na starcie programu, posiada
 * dwie funkcje - Obrot oraz Ruch.
 */

class Robot: public ObiektGraficzny{
  ZbiorWierzcholkow Wsp_Lok;
  double Kat;
  double Promien;
public:
  
  Robot()
  {
    Wsp_Lok.Dodaj(Wektor2D(0,0));
    Wsp_Lok.Dodaj(Wektor2D(50,0));
    Wsp_Lok.Dodaj(Wektor2D(0,40));
    Wsp_Lok.Dodaj(Wektor2D(-30,40));
    Wsp_Lok.Dodaj(Wektor2D(-30,-40));
    Wsp_Lok.Dodaj(Wektor2D(0,-40));
    Wsp_Lok.Dodaj(Wektor2D(50,0));    
    for(Wektor2D w : Wsp_Lok )
      {
	UzyskajTabWierz().Dodaj(w);
      }
    Kat=0;
    Promien=50;
    for(int i=0; i<4; i++)
      {
	UzyskajWierzKol().Dodaj(Wektor2D(0,0));
      }
  }
  
  void Obrot(const double Angle);
  void Ruch(const double Dlugosc);
  bool SprawdzCzyKolizja(ObiektGraficzny& Ob);
};

#endif
