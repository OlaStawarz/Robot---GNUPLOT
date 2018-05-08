#include <unistd.h>
#include <fstream>
#include <iostream>
#include "Scena.hh"

using namespace std;

void Scena::RuchRobotem(const int  Dystans)
{
  for (int i=0; i<10; i++)
    {
      robot.Ruch(Dystans/10);
      sciezka.Dodaj(robot.UzyskajPolozenieObiektu());
      ZapiszDoPliku();
      lacze.Rysuj();
      usleep(200000);
    }
}

void Scena::ObrotRobotem(const double Kat)
{
  for (int i=0; i<10; i++)
    {
      robot.Obrot(Kat/10);
      ZapiszDoPliku();
      lacze.Rysuj();
      usleep(200000);
  }
}

void Scena::ZapiszDoPliku()
{
  ZbiorWierzcholkow Z;
  Z=robot.UzyskajTabWierz();

  cout << "Zapis:\n";
  for ( Wektor2D v: sciezka.UzyskajTabWierz())
    {
      Z.Dodaj(v);

    }
  ZapiszZbiorDoPliku( Z, "figury/robot.dat");
}
void Scena::ZapiszZbiorDoPliku(ZbiorWierzcholkow Z, char* nazwa)
{
  ofstream   StrmWy(nazwa);

  if (!StrmWy.is_open()) {
    cerr << endl
         << "Blad: Otwarcie do zapisu pliku '" << nazwa
	 << "' nie powiodlo sie." << endl
	 << endl;
  }
  for (const Wektor2D&  W_lok : Z) {
    StrmWy << W_lok << endl;
    cout << W_lok << endl;
   }
}
