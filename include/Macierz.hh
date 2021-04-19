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
  Macierz();
  Macierz(Wektor tmp[ROZMIARMACIERZY]);
  Wektor operator [](int ind)const;
  Wektor& operator [](int ind );
  Wektor operator *(const Wektor& Arg2) const;
  void Mobrotu (double Kont);
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
