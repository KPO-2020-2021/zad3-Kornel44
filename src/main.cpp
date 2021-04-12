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




using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */



int main()
{
  Prostokat             Pr;   // To tylko przykladowe definicje zmiennej
  PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
  ofstream StrmWyj;
  Wektor test;
  Macierz obrot;
  double kat=M_PI/2;
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

  Pr('a')[0]=100;
  Pr('a')[1]=100;
  Pr('b')[0]=100;
  Pr('b')[1]=200;
  Pr('c')[0]=200;
  Pr('c')[1]=200;
  Pr('d')[0]=200;
  Pr('d')[1]=100;
  test[0]=10;
  test[1]=50;
  obrot[0][0]=cos(kat);
  obrot[0][1]=-sin(kat);
  obrot[1][0]=sin(kat);
  obrot[1][1]=cos(kat);

  cout<<Pr;
  StrmWyj.open("prostokat.dat");
  if(StrmWyj.is_open()){
         StrmWyj<<Pr;
         StrmWyj<<setw(16)<<Pr('a')<<endl;
         StrmWyj.close();
         }else{
                throw runtime_error ("operacja otwarcia pliku nie powiodla sie");
         }

  if(cout.fail()==false){
  Lacze.Rysuj();
  cout << "Naciśnij ENTER, aby kontynuowac" << endl;
  cin.ignore(100000,'\n');}

  Pr.przesuniecie(test);
  cout<<Pr;
  StrmWyj.open("prostokat.dat");
  if(StrmWyj.is_open()){
         StrmWyj<<Pr;
         StrmWyj<<setw(16)<<Pr('a')<<endl;
         StrmWyj.close();}else{
                throw runtime_error ("operacja otwarcia pliku nie powiodla sie");
         }
         if(cout.fail()==false){
  Lacze.Rysuj();
  cout << "Naciśnij ENTER, aby kontynuowac" << endl;
  cin.ignore(100000,'\n');}


   Pr.obrot(obrot);
  cout<<Pr;
  StrmWyj.open("prostokat.dat");
  if(StrmWyj.is_open()){
         StrmWyj<<Pr;
         StrmWyj<<setw(16)<<Pr('a')<<endl;
         StrmWyj.close();}else{
                throw runtime_error ("operacja otwarcia pliku nie powiodla sie");
         }
         if(cout.fail()==false){
  Lacze.Rysuj();
  cout << "Naciśnij ENTER, aby kontynuowac" << endl;
  cin.ignore(100000,'\n');}
}


   
