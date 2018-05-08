#ifndef SCIEZKA_HH
#define SCIEZKA_HH

#include "ObiektGraficzny.hh"

class Sciezka: public ObiektGraficzny{
public:
  void Dodaj(const Wektor2D& punkt)
  {
    DodajWierzcholek(punkt);
  }
  
};

#endif
