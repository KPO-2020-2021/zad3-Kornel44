#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <iostream>
#include"Wektor.hh"
#include"Macierz.hh"

/*Klasa Prostokąt:
 *  Opisuje prostokąt jako cztery punkty na płaszczyźnie wyrażone jako wektory o pączątkach w punkcie 00.
 */
class Prostokat {
  Wektor Figura[ILOSCBOKOW];
  public:
  Prostokat();
  Prostokat(Wektor tmp[ILOSCBOKOW] );
  Wektor operator [](unsigned int wierzcholek)const;
  Wektor& operator [](unsigned int wierzcholek);
  void przesuniecie(Wektor Kier);
  void obrot(Macierz Kont,  int ilosc);
  double dlugoscboku (unsigned int wierzcholekA, unsigned int wierzcholekB) const;
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
