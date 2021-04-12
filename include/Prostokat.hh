#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <iostream>
#include"Wektor.hh"
#include"Macierz.hh"

/*Klasa Prostokąt:
 *  Opisuje prostokąt jako cztery punkty na płaszczyźnie wyrażone jako wektory o pączątkach w punkcie 00.
 */
class Prostokat {
  Wektor a,b,c,d;
  public:
  Wektor operator ()(const char abcd)const;
  Wektor& operator ()(const char abcd);
  void przesuniecie(Wektor Kier);
  void obrot(Macierz Kont);
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << ( std::ostream   &Strm, const Prostokat &Pr);


#endif
