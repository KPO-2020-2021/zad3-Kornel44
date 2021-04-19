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
  double kont=90;
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
  test[0]=10;
  test[1]=50;
  obrot.Mobrotu(kont);

  cout<<Pr;
  cout<<Pr.dlugoscboku(0,1)<<endl;
  StrmWyj.open("prostokat.dat");
  if(StrmWyj.is_open()){
         StrmWyj<<Pr;
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
  cout<<Pr.dlugoscboku(0,1)<<endl;
  StrmWyj.open("prostokat.dat");
  if(StrmWyj.is_open()){
         StrmWyj<<Pr;
         StrmWyj.close();}else{
                throw runtime_error ("operacja otwarcia pliku nie powiodla sie");
         }
         if(cout.fail()==false){
  Lacze.Rysuj();
  cout << "Naciśnij ENTER, aby kontynuowac" << endl;
  cin.ignore(100000,'\n');}


   Pr.obrot(obrot, 1);
  cout<<Pr;
  cout<<Pr.dlugoscboku(0,1)<<endl;
  StrmWyj.open("prostokat.dat");
  if(StrmWyj.is_open()){
         StrmWyj<<Pr;
         StrmWyj.close();}else{
                throw runtime_error ("operacja otwarcia pliku nie powiodla sie");
         }
         if(cout.fail()==false){
  Lacze.Rysuj();
  cout << "Naciśnij ENTER, aby kontynuowac" << endl;
  cin.ignore(100000,'\n');}
}


   
