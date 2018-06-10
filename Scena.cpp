/*!
 * \file
 * \brief Zawiera definicje metod klasy Scena
 *
 * Zawiera definicje metod klasy Scena
 * wraz z ich opisem.
 */

#include <unistd.h>
#include <fstream>
#include <iostream>
#include "Scena.hh"

using namespace std;

bool Scena::RuchRobotem(const int  Dystans)
{
  for (int i=0; i<10; i++)
    {
      roboty[aktywnyrobot]->Ruch(Dystans/10);
      for(shared_ptr<ObiektGraficzny> p : obiekty)
	{
	  if(p != roboty[aktywnyrobot])
	    if(roboty[aktywnyrobot]->SprawdzCzyKolizja(*p))
	      {
		roboty[aktywnyrobot]->Ruch(-Dystans/10);
		return false;
	      }
	}
      sciezka.Dodaj(roboty[aktywnyrobot]->UzyskajPolozenieObiektu());
      ZapiszDoPliku("figury/robot.dat");
      lacze.Rysuj();
      usleep(200000);
      
    }
  return true;
}

void Scena::ObrotRobotem(const double Kat)
{
  for (int i=0; i<10; i++)
    {
      roboty[aktywnyrobot]->Obrot(Kat/10);
      ZapiszDoPliku("figury/robot.dat");
      lacze.Rysuj();
      usleep(200000);
  }
}

void Scena::ZapiszDoPliku(char* nazwa)
{
  ZbiorWierzcholkow Z;
  ofstream   StrmWy(nazwa);

  if (!StrmWy.is_open()) {
    cerr << endl
         << "Blad: Otwarcie do zapisu pliku '" << nazwa
	 << "' nie powiodlo sie." << endl
	 << endl;
  }

  //cout << "Zapis:\n";
  for ( Wektor2D v: sciezka.UzyskajTabWierz())
    {
      Z.Dodaj(v);
      
    }

  for (const Wektor2D&  W_lok : Z)
    {
      StrmWy << W_lok << endl;
      
    }

  StrmWy << "\n\n";
  Z.clear();
  for(shared_ptr<ObiektGraficzny> p : obiekty)
    {
      Z=p->UzyskajTabWierz();

      for (const Wektor2D&  W_lok : Z)
	{
	  StrmWy << W_lok << endl;
	  
	}

      StrmWy << "\n\n";
	
    }

}
