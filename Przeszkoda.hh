#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include <iostream>
#include "ObiektGraficzny.hh"

class Przeszkoda : public ObiektGraficzny
{
  ZbiorWierzcholkow Wsp_Lok;
  double Kat;
  void Obrot(const double Angle);
  void Przesuniecie(double x, double y);
public:

  Przeszkoda(double szerokosc, double wysokosc, double alfa, double x, double y)
  {
    Wsp_Lok.Dodaj(Wektor2D(0,0));
    Wsp_Lok.Dodaj(Wektor2D(szerokosc,0));
    Wsp_Lok.Dodaj(Wektor2D(szerokosc,wysokosc));
    Wsp_Lok.Dodaj(Wektor2D(0,wysokosc));
    Wsp_Lok.Dodaj(Wektor2D(0,0));
    for(Wektor2D w : Wsp_Lok)
      {
	UzyskajTabWierz().Dodaj(w);
      }
    Kat=0;
    Obrot(alfa);
    Przesuniecie(x,y);
    UzyskajWierzKol()=UzyskajTabWierz();
  }
  bool SprawdzCzyKolizja(ObiektGraficzny & Ob);
  const ZbiorWierzcholkow UzyskajWspLok()const;

};

#endif
