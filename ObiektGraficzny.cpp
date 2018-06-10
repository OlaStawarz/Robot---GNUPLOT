/*!
 * \file
 * \brief Zawiera definicje metod klasy ObiektGraficzny
 *
 * Zawiera definicje metod klasy ObiektGraficzny
 * wraz z ich opisem.
 */

#include <fstream>
#include "ObiektGraficzny.hh"


using namespace std;


/*!
 * Przypisuje wartości współrzędnych poszczególnym wierzchołkom.
 *
 * Uwaga:Ta metoda to tylko tymczasowe rozwiązanie. Ona powinna
 *       być w klasie pochodnej.
 */
void ObiektGraficzny::InicjalizujKsztalt()
{
  Wektor2D punkt;
  punkt[0] = 0; punkt[1] = 0;
  
    _TabWierz.Dodaj(punkt);
    /* _TabWierz.Dodaj(Wektor2D(30,0));
  _TabWierz.Dodaj(Wektor2D(0,-30));
  _TabWierz.Dodaj(Wektor2D(-30,-30));
  _TabWierz.Dodaj(Wektor2D(-30,30));
  _TabWierz.Dodaj(Wektor2D(0,30));
  _TabWierz.Dodaj(Wektor2D(30,0));

  */}



/*!
 *  Zmiania współrzędne położenia punktu, względem którego tworzony
 *  jest obrys obiektu.
 *  \param[in] x - współrzędna x-owa nowego położenia.
 *  \param[in] y - współrzędna y-owa nowego położenia.
 */
void ObiektGraficzny::ZmienPolozenie(double x, double y)
{
  Wektor2D w(x, y);
  
  _PolozenieObiektu[0] += x;
  _PolozenieObiektu[1] += y;  
  for ( Wektor2D&  W_lok : _TabWierz) {
    W_lok = W_lok + w;
  }
  for(Wektor2D& v : _WierzKol)
    {
      v=v+w;
    }      
}


/*!
 * Zapisuje do strumienia współrzędne globalne wierzchołków
 * obrysu obiektu.
 * \param[in,out] - strumień, do którego wpisane zostałe współrzędne
 *                  wierzchołków.
 * \retval true - gdy operacja powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool ObiektGraficzny::ZapiszDoStrumienia(std::ostream& StrmWy) const
{

  for (const Wektor2D&  W_lok : _TabWierz) {
    StrmWy << W_lok << endl;
   }
  return !StrmWy.fail();
}


/*!
 * Zapisuje do pliku współrzędne globalne wierzchołków
 * obrysu obiektu.
 * \param[in,out] - strumień, do którego wpisane zostałe współrzędne
 *                  wierzchołków.
 * \retval true - gdy operacja powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool ObiektGraficzny::ZapiszDoPliku(const char* sNazwaPliku) const
{
  ofstream   StrmWy(sNazwaPliku);

  if (!StrmWy.is_open()) {
    cerr << endl
         << "Blad: Otwarcie do zapisu pliku '" << sNazwaPliku
	 << "' nie powiodlo sie." << endl
	 << endl;
    return false;
  }
  return ZapiszDoStrumienia(StrmWy);
}

void ObiektGraficzny::DodajWierzcholek(Wektor2D punkt)
{
  _TabWierz.Dodaj(punkt);
}
