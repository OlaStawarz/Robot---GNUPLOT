#ifndef ROBOT_HH
#define ROBOT_HH

#include <iostream>

#include "ObiektGraficzny.hh"

class Robot: public ObiektGraficzny{
  ZbiorWierzcholkow Wsp_Lok;
  double Kat;
public:

  Robot()
  {
    Wsp_Lok.Dodaj(Wektor2D(0,0));
    Wsp_Lok.Dodaj(Wektor2D(50,0));
    Wsp_Lok.Dodaj(Wektor2D(70,50));
    Wsp_Lok.Dodaj(Wektor2D(50,100));
    Wsp_Lok.Dodaj(Wektor2D(0,100));
    Wsp_Lok.Dodaj(Wektor2D(0,0));
    for(Wektor2D w : Wsp_Lok )
      {
	UzyskajTabWierz().Dodaj(w);
      }
    Kat=0;

    std::cout<< "Konstruktor robota\n";
  }
  
  void Obrot(const double Angle);
  void Ruch(const double Dlugosc);
 
};

#endif
