#include <cmath>
#include "Robot.hh"

using namespace std;

void Robot::Obrot(const double Angle)
{
  Kat+=Angle;
  cout << Wsp_Lok[0] << endl;
  cout << "Kontrol1.00\n"; 
  for(int i=0; i<Wsp_Lok.Ilosc_Wierzcholkow(); i++ )
    {
      cout << "Kontrol" << i;
      cout << UzyskajPolozenieObiektu() << endl;
      UzyskajTabWierz()[i][0] = cos(Kat*STnaRAD)*Wsp_Lok[i][0] - sin(Kat*STnaRAD)*Wsp_Lok[i][1] + UzyskajPolozenieObiektu()[0];
      UzyskajTabWierz()[i][1] = sin(Kat*STnaRAD)*Wsp_Lok[i][0] + cos(Kat*STnaRAD)*Wsp_Lok[i][1] + UzyskajPolozenieObiektu()[1];
    }
 
}

void Robot::Ruch(const double Dlugosc)
{
  ZmienPolozenie(Dlugosc*cos(Kat),Dlugosc*sin(Kat));
}
