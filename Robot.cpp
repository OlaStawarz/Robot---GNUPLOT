/*!
 * \file
 * \brief Zawiera definicje metod klasy Robot
 *
 * Zawiera definicje metod klasy Robot
 * wraz z ich opisem.
 */

#include <cmath>
#include "Robot.hh"

using namespace std;

/*!
 * Odpowiada za obrot robota, jako argument przyjmuje kat obrotu
 */

void Robot::Obrot(const double Angle)
{
  Kat+=Angle;
  //cout << Wsp_Lok[0] << endl;
  for(int i=0; i<Wsp_Lok.Ilosc_Wierzcholkow(); i++ )
    {
      //cout << UzyskajPolozenieObiektu() << endl;
      UzyskajTabWierz()[i][0] = cos(Kat*STnaRAD)*Wsp_Lok[i][0] - sin(Kat*STnaRAD)*Wsp_Lok[i][1] + UzyskajPolozenieObiektu()[0];
      UzyskajTabWierz()[i][1] = sin(Kat*STnaRAD)*Wsp_Lok[i][0] + cos(Kat*STnaRAD)*Wsp_Lok[i][1] + UzyskajPolozenieObiektu()[1];
    }
 
}

/*!
 * Odpowiada za ruch robotem, jako argument przyjmuje dlugosc ruchu
 */

void Robot::Ruch(const double Dlugosc)
{
  ZmienPolozenie(Dlugosc*cos(Kat*STnaRAD),Dlugosc*sin(Kat*STnaRAD));
}

bool Robot::SprawdzCzyKolizja(ObiektGraficzny& Ob)
{
  Wektor2D polozenie=UzyskajPolozenieObiektu();
  ZbiorWierzcholkow zbior=Ob.UzyskajWierzKol();
  zbior[0][0]-=Promien;
  zbior[0][1]-=Promien;
  zbior[2][0]+=Promien;
  zbior[2][1]+=Promien;

  cout << "wierzcholki:\n";
  cout<<zbior[0] << endl;
  cout<<zbior[2] << endl;
  cout << polozenie << endl;
  
  if(polozenie[0]>zbior[0][0] && polozenie[0]<zbior[2][0] &&
     polozenie[1]>zbior[0][1] && polozenie[1]<zbior[2][1])
    {
      cout << "kolizja\n";
      return true;
    }
  return false;
}
