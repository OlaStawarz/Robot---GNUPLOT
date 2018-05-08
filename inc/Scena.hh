#ifndef SCENA_HH
#define SCENA_HH

#include <iostream>

#include "Robot.hh"
#include "Sciezka.hh"
#include "lacze_do_gnuplota.hh"

class Scena{
  Robot robot;
  Sciezka sciezka;
  PzG::LaczeDoGNUPlota lacze;
public:
  Scena()
  {
    ZapiszDoPliku();
    lacze.DodajNazwePliku("figury/robot.dat",PzG::RR_Ciagly,2);
    lacze.ZmienTrybRys(PzG::TR_2D);
    std::cout<< "kontrol1\n";
    lacze.Rysuj();

    std::cout<< "Konstruktor sceny\n";
  }
  void ZapiszDoPliku();
  void RuchRobotem (const int Dystans);
  void ObrotRobotem (const double Angle);
  void ZapiszZbiorDoPliku(ZbiorWierzcholkow Z, char* nazwa);
};

  
#endif
