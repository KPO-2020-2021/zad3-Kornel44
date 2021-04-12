#ifndef MACIERZ_HH
#define MACIERZ_HH


#include <iostream>
#include "Wektor.hh"
#include "Rozmiary.hh"

/*Klasa macierz:
 *  Opisuje macierz o zdefiniowanym rozmiarze.
 *  Macierz jest opisana poprzez tablice wektorów
 *  Do poszczególnych pól odwołujemy się poprzez podwójny operator []
 */
class Macierz{
  Wektor macierz[ROZMIARMACIERZY];

  public:
  Wektor operator [](int ind)const{return macierz[ind];}
  Wektor& operator [](int ind ) {return macierz[ind];}
  Wektor operator *(const Wektor& Arg2) const;
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 *
 * Przeciążenie to może być użyteczne w trakcie debugowania programu.
 */
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);

#endif
