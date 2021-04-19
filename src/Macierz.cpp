#include "Macierz.hh"

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
