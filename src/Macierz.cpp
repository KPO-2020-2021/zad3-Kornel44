#include "Macierz.hh"

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
