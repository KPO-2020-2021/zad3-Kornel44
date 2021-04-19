#include "Wektor.hh"
#include<iomanip>
#include<math.h>

#define MINDIV 0.01

 Wektor::Wektor(double tmp[ROZMIARWEKTORA]){
     for (int i = 0; i < ROZMIARWEKTORA; ++i)
     {
        this->wektor[i]=tmp[i];
     }
     
 }


double Wektor::operator []( int ind) const{
if (ind<ROZMIARWEKTORA)return wektor[ind];
else{
    throw std::runtime_error("odwolanie do niedozwolonego pola");
    return wektor[ind];
}
}

double& Wektor::operator []( int ind){
if (ind<ROZMIARWEKTORA)return wektor[ind];
else{
    throw std::runtime_error("odwolanie do niedozwolonego pola");
    return wektor[ind];
}
}

Wektor  Wektor::operator + (Wektor Arg2)const {
    Wektor wynik;
    for (int i=0;i<ROZMIARWEKTORA; ++i){
    wynik[i]=this->wektor[i]+Arg2.wektor[i];
    }
    return wynik;
}

Wektor  Wektor::operator - (Wektor Arg2)const {
    Wektor wynik;
    for (int i=0;i<ROZMIARWEKTORA; ++i){
    wynik[i]=this->wektor[i]-Arg2.wektor[i];
    }
    return wynik;
}

double  Wektor::operator * (Wektor Arg2)const {
    double wynik;
    for (int i=0;i<ROZMIARWEKTORA; ++i){
    wynik+=this->wektor[i]*Arg2.wektor[i];
    }
    return wynik;
}

bool Wektor::operator== (Wektor Arg2)const {
    bool wartosc;
for (int i = 0; i < ROZMIARWEKTORA; ++i)
 {
    wartosc=(abs(this->wektor[i]- Arg2[i])>MINDIV);
    if (wartosc==false){break;}
 
 
}
return wartosc;
}


std::istream& operator >> (std::istream &Strm, Wektor &Wek){
    for (int i = 0; i < ROZMIARWEKTORA; ++i)
    {
        Strm>>Wek[i];
    }
    return Strm;
    
}

std::ostream& operator << (std::ostream &Strm, const Wektor &Wek){
    for (int i = 0; i < ROZMIARWEKTORA; ++i)
    {
        Strm<<std::fixed<<std::setprecision(10)<<Wek[i]<<" ";
    }
    return Strm;
}


