#include "Macierz.hh"
#include "math.h"

Macierz::Macierz(){
    for (int i = 0; i < ROZMIARMACIERZY; ++i)
    {for(int j =0; i < ROZMIARWEKTORA; ++i){
        macierz[i][j]=0;}
    }
    
}

Macierz::Macierz(Wektor tmp[ROZMIARMACIERZY]){
    for (int i = 0; i < ROZMIARMACIERZY; ++i)
    {
        macierz[i]=tmp[i];
    }
    
}

 Wektor Macierz::operator [](int ind)const{
     if (ind <ROZMIARMACIERZY) return macierz[ind];
     else{
         throw std::runtime_error("odwolanie do niedozwolonego pola");
         return macierz[ind];
     }
 }

 Wektor& Macierz::operator [](int ind){
     if (ind <ROZMIARMACIERZY) return macierz[ind];
     else{
         throw std::runtime_error("odwolanie do niedozwolonego pola");
         return macierz[ind];
     }
 }



/*Operator mnożenia macierzy przez wektor:
*Arg2- referencja na stały wektor
*Działanie: operator mnoży zadaną macież przez wektor o tej samej długości i zwraca wektor.
*/
Wektor Macierz::operator *(const Wektor& Arg2) const{
    Wektor wynik;
    for (int i = 0; i < ROZMIARWEKTORA; i++)
    {
        wynik[i]=this->macierz[i]*Arg2;
    }
    return wynik;
    
}

void Macierz::Mobrotu (double Kont){
double KontRad;
KontRad=Kont*M_PI/180;
this->macierz[0][0]=cos(KontRad);
this->macierz[0][1]=-sin(KontRad);
this->macierz[1][0]=sin(KontRad);
this->macierz[1][1]=cos(KontRad);
}
