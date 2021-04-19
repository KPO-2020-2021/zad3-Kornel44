#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif


#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <string>

#include "Wektor.hh"
#include "Macierz.hh"
#include "Prostokat.hh"
#include "lacze_do_gnuplota.hh"






/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */

void  menu();
void rysuj(std::ofstream& StrmWyj, PzG::LaczeDoGNUPlota  Lacze, const Prostokat& Pr);
int main()
{
  Prostokat             Pr;   // To tylko przykladowe definicje zmiennej
  PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
  std::ofstream StrmWyj;
  Wektor trans;
  Macierz obrot;
  char wyb;
  double kont, ileobrot;
                                // rysunku prostokata

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  Lacze.DodajNazwePliku("prostokat.dat",PzG::RR_Ciagly,2);
   //
   //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
   //      których połowa długości boku wynosi 2.
   //
  Lacze.DodajNazwePliku("prostokat.dat",PzG::RR_Punktowy,2);
   //
   //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy tylko x,y.
   //
  Lacze.ZmienTrybRys(PzG::TR_2D); 

  Pr[0][0]=100;
  Pr[0][1]=100;
  Pr[1][0]=100;
  Pr[1][1]=200;
  Pr[2][0]=200;
  Pr[2][1]=200;
  Pr[3][0]=200;
  Pr[3][1]=100;
  menu();
  Pr.wypiszdlugosc();
  while (wyb!='k')
  {
         std::cout<<"Twój wybór? (m - menu) ";
         std::cin>>wyb;
         std::cout<<std::endl;
       switch (wyb)
       {
       case 'o':
              std::cout<<"Podaj wartość kąta obrotu w stopniach"<<std::endl;
              std::cin>>kont;
              std::cout<<std::endl<<"Ile razy operacja ma być powtórzona?"<<std::endl;
              std::cin>>ileobrot;
              obrot.Mobrotu(kont);
              Pr.obrot(obrot, ileobrot);
              Pr.wypiszdlugosc();
              rysuj(StrmWyj , Lacze, Pr);
              break;
       case 'p':
              std::cout<<"Wprowadź współrzędne wektora translacji w postaci dwóch liczb"<<std::endl;
              std::cin>>trans;
              Pr.przesuniecie(trans);
              rysuj(StrmWyj , Lacze, Pr);
              break;
       case 'w':
              Pr.wyswietl();
               break;
       case 'm':
              menu();
               break;
       case 'k':
               break;
       default:
               std::cout<<"Podaj prawidłową opcje"<<std::endl;
               break;
 }}
}

  

void menu(){
       std::cout<<"o -- obrot prostokąta o zadany kąt"<<std::endl;
       std::cout<<"p -- przesuniecie prostokąta o zadany wektor"<<std::endl;
       std::cout<<"w -- wyświetlenie współrzędnych wierzchołków prostokąta"<<std::endl;
       std::cout<<"m -- wyświetl menu"<<std::endl;
       std::cout<<"o -- zakończ działanie programu"<<std::endl;
}

void rysuj( std::ofstream &StrmWyj, PzG::LaczeDoGNUPlota  Lacze, const Prostokat& Pr){
       StrmWyj.open("prostokat.dat");
       if(StrmWyj.is_open()){
         StrmWyj<<Pr;
         StrmWyj.close();}else{
                throw std::runtime_error ("operacja otwarcia pliku nie powiodla sie");
         }
         if(StrmWyj.fail()==false){
       Lacze.Rysuj();
       std::cin.ignore(100000,'\n');}
}
   
