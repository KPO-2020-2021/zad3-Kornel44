#ifndef WEKTOR_HH
#define WEKTOR_HH


#include <iostream>
#include "Rozmiary.hh"


/*Klasa Wketor:
 *Opisuje wektor w zdefiniowanej liczbie wymiarów za pomocą tablicy double
 *Do zmiennej klasy odwołujemy się poprzez operator [].
 */
class Wektor {
  double wektor[ROZMIARWEKTORA];

  public:
  double operator []( int ind) const {return wektor[ind];}
  double & operator [](int ind){return wektor[ind];}
  Wektor operator + (Wektor Arg2)const;
  Wektor operator - (Wektor Arg2)const;
  double operator * (Wektor Arg2) const;


};


/*
 *Przeciążenie operatora przesunięcia bitowego w prawo:
 *Czyta wartości do zmiennej typu wektor
 *Akceptuje wektor w formacie dwóch liczb typu double podanych po sobie.
 */
std::istream& operator >> (std::istream &Strm, Wektor &Wek);

/*
Przeciążenie operatora przesunięcia bitowego w lewo:
*Wypisuje wartość zmiennej typu wektor w formacie dwuch następujących po sobie liczb typu double
 */
std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);

#endif
