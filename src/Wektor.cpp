#include "Wektor.hh"
#include<iomanip>

Wektor  Wektor::operator + (Wektor Arg2)const {
    Wektor wynik;
    for (int i=0;i<ROZMIARWEKTORA; i++){
    wynik[i]=this->wektor[i]+Arg2.wektor[i];
    }
    return wynik;
}

Wektor  Wektor::operator - (Wektor Arg2)const {
    Wektor wynik;
    for (int i=0;i<ROZMIARWEKTORA; i++){
    wynik[i]=this->wektor[i]-Arg2.wektor[i];
    }
    return wynik;
}

double  Wektor::operator * (Wektor Arg2)const {
    double wynik;
    for (int i=0;i<ROZMIARWEKTORA; i++){
    wynik+=this->wektor[i]*Arg2.wektor[i];
    }
    return wynik;
}

std::istream& operator >> (std::istream &Strm, Wektor &Wek){
    for (int i = 0; i < ROZMIARWEKTORA; i++)
    {
        Strm>>Wek[i];
    }
    return Strm;
    
}

std::ostream& operator << (std::ostream &Strm, const Wektor &Wek){
    for (int i = 0; i < ROZMIARWEKTORA; i++)
    {
        Strm<<std::fixed<<std::setprecision(10)<<Wek[i]<<" ";
    }
    return Strm;
}


