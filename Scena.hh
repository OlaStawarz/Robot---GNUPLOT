#ifndef SCENA_HH
#define SCENA_HH

/*!
 * \file
 * \brief Definicja klasy Scena
 *
 * Plik zawiera definicję klasy Scena.
 */

#include <iostream>
#include <list>
#include <memory>
#include "Robot.hh"
#include "Sciezka.hh"
#include "Przeszkoda.hh"
#include "lacze_do_gnuplota.hh"

/*!
 * \brief Modeluje scene, po ktorej porusza sie robot
 *
 * Modeluje scene, po ktorej porusza sie robot. Zawiera funkcje odpowiadajace
 * za zapis do pliku oraz metody pozwalajace na ruch robotem oraz obrot 
 * robotem. W klasie scena nastepuje rowniez zapisanie do pliku obiektow 
 * znajdujacych sie obecnie na scenie oraz wybor trybu rysowania - w tym 
 * przypadku jest to tryb 2D.
 */



template<typename T>
class lista : public std::list<T>
{
public:
  T operator [] (const int index)
  {
    T ret;
    int i = 0;
    for(T r : (*this))
      {
	if(i == index)
	  ret = r;
	i++;
      }
    
    return ret;
  }
  void erase(int index)
  {
    int i = 0;
    
    for(auto it = std::list<T>::begin(); it != std::list<T>::end(); )
      {
	if (i++ == index)
	  {
	    it = std::list<T>::erase(it);
	    break;
	  }
	else
	  ++it;
      }
    
  }
};

class Scena{
  lista <std::shared_ptr <Robot>> roboty;
  lista <std::shared_ptr<ObiektGraficzny>> obiekty;
  Sciezka sciezka;
  PzG::LaczeDoGNUPlota lacze;
  int aktywnyrobot;
public:
  Scena()
  {
    aktywnyrobot=0;
    obiekty.push_back(std::make_shared<Przeszkoda> (Przeszkoda(100, 100, 0, 200, 200)));
    roboty.push_back(std::make_shared<Robot>());
    obiekty.push_back(roboty[aktywnyrobot]);
    ZapiszDoPliku("figury/robot.dat");
    lacze.DodajNazwePliku("figury/robot.dat",PzG::RR_Ciagly,2);
    lacze.ZmienTrybRys(PzG::TR_2D);
    lacze.Rysuj();
   
  }
  void ZapiszDoPliku(char* nazwa);
  bool RuchRobotem (const int Dystans);
  void ObrotRobotem (const double Angle);
};

  
#endif
