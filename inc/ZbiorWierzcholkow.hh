#ifndef ZBIORWIERZCHOLKOW_HH
#define ZBIORWIERZCHOLKOW_HH

#include "Wektor2D.hh"
#include <vector>

class ZbiorWierzcholkow : public std::vector<Wektor2D>{
public:
  /*const Wektor2D & operator [](const int Indeks) const
  { return at(Indeks);}
  Wektor2D &  operator [] (const int Indeks)
  {return at(Indeks); }*/
  void Dodaj(const Wektor2D Punkt)
  {
    push_back(Punkt);
  }
  int Ilosc_Wierzcholkow() {return size();}
  void Usun()
  {
    pop_back();
  }
  
};

#endif 
