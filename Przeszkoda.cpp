#include <cmath>
#include "Przeszkoda.hh"

using namespace std;

void Przeszkoda::Obrot(const double Angle)
{
  Kat+=Angle;
  for(int i=0; i<Wsp_Lok.Ilosc_Wierzcholkow(); i++)
    {
      UzyskajTabWierz()[i][0]=cos(Kat*STnaRAD) * Wsp_Lok[i][0] - sin(Kat*STnaRAD)*Wsp_Lok[i][1] + UzyskajPolozenieObiektu()[0];
      UzyskajTabWierz()[i][1] = sin(Kat*STnaRAD)*Wsp_Lok[i][0] + cos(Kat*STnaRAD)*Wsp_Lok[i][1] + UzyskajPolozenieObiektu()[1];
	
    }
}

void Przeszkoda::Przesuniecie(double x, double y)
{
  ZmienPolozenie(x,y);
}

const ZbiorWierzcholkow Przeszkoda::UzyskajWspLok()const
{
  return Wsp_Lok;
}

