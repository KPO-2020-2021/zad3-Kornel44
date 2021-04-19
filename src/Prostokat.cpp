#include "Prostokat.hh"
#include<iomanip>
#include"math.h"


Prostokat::Prostokat(){
    for(int i = 0; i <ILOSCBOKOW; ++i)
        {for (int j = 0; j < ROZMIARWEKTORA; ++j)
        {
            Figura[i][j]=0;
        }
         
    }
    
}

Prostokat::Prostokat(Wektor tmp[ILOSCBOKOW]){
    for(int i = 0; i <ILOSCBOKOW; ++i)
            Figura[i]= tmp[i];
        
         
    }
    


 Wektor Prostokat::operator[](unsigned int  wierzcholek) const{
if (wierzcholek<ILOSCBOKOW) return Figura[wierzcholek];
else {
throw std::runtime_error("odwolanie do niedozwolonego pola");
return Figura[wierzcholek];}
 }

 Wektor& Prostokat::operator[](unsigned int wierzcholek) {
if (wierzcholek<ILOSCBOKOW) return Figura[wierzcholek];
else {
throw std::runtime_error("odwolanie do niedozwolonego pola");
return Figura[wierzcholek];}
 }

 
std::ostream& operator << ( std::ostream   &Strm, const Prostokat &Pr){
    for(int i=0;i<ILOSCBOKOW;++i){
        Strm<<std::setw(16)<<Pr[i]<<std::endl;}
    Strm<<std::setw(16)<<Pr[0]<<std::endl;
   
    return Strm;
}

void Prostokat::przesuniecie(Wektor Kier){
for (int i = 0; i < ILOSCBOKOW; ++i)
{
    this->Figura[i]=this->Figura[i]+Kier;
}  
}

void Prostokat::obrot(Macierz Kont,  int ilosc){
for (int i = 0; i < ilosc; i++)
{

for (int j = 0; j < ILOSCBOKOW; ++j)
{
  this->Figura[j]=Kont*this->Figura[j];
}}}

double Prostokat::dlugoscboku (unsigned int wierzcholekA, unsigned int wierzcholekB) const{
    double wynik;
    
    wynik=sqrt(pow(this->Figura[wierzcholekB][0]-this->Figura[wierzcholekA][0], 2)+pow(this->Figura[wierzcholekB][1]-this->Figura[wierzcholekA][1], 2));
    return wynik;
}

void Prostokat::wypiszdlugosc(){
    double ab, cd, ac, bd;
    ab=dlugoscboku(0,1);
    cd=dlugoscboku(2,3);
    ac=dlugoscboku(1,2);
    bd=dlugoscboku(3,0);
    if(ab>ac){
         if(ab==cd){
            std::cout<<"Dłuższe przeciwległe boki są równe"<<std::endl;
            std::cout<<"Długość pierwszego boku: "<<std::fixed<<std::setprecision(10)<<ab<<std::endl;
            std::cout<<"Długość pierwszego boku: "<<std::fixed<<std::setprecision(10)<<cd<<std::endl;
        }else{
            std::cout<<"Dłuższe przeciwległe boki nie są równe!!!"<<std::endl;
            std::cout<<"Długość pierwszego boku: "<<std::fixed<<std::setprecision(10)<<ab<<std::endl;
            std::cout<<"Długość pierwszego boku: "<<std::fixed<<std::setprecision(10)<<cd<<std::endl;
        }
        if(ac==bd){
            std::cout<<"Krótsze przeciwległe boki są równe"<<std::endl;
            std::cout<<"Długość pierwszego boku: "<<std::fixed<<std::setprecision(10)<<ac<<std::endl;
            std::cout<<"Długość pierwszego boku: "<<std::fixed<<std::setprecision(10)<<bd<<std::endl;
        }else{
            std::cout<<"Krótsze przeciwległe boki nie są równe!!!"<<std::endl;
            std::cout<<"Długość pierwszego boku: "<<std::fixed<<std::setprecision(10)<<ac<<std::endl;
            std::cout<<"Długość pierwszego boku: "<<std::fixed<<std::setprecision(10)<<bd<<std::endl;
        }
    }else{
        if(ac==bd){
            std::cout<<"Dłuższe  przeciwległe boki są równe: "<<std::endl;
            std::cout<<"Długość pierwszego boku: "<<std::fixed<<std::setprecision(10)<<ac<<std::endl;
            std::cout<<"Długość pierwszego boku: "<<std::fixed<<std::setprecision(10)<<bd<<std::endl;
        }else{
            std::cout<<"Dłuższe przeciwległe boki nie są równe!!!"<<std::endl;
            std::cout<<"Długość pierwszego boku: "<<std::fixed<<std::setprecision(10)<<ac<<std::endl;
            std::cout<<"Długość pierwszego boku: "<<std::fixed<<std::setprecision(10)<<bd<<std::endl;
        }
        if(ab==cd){
            std::cout<<"Krótsze przeciwległe boki są równe: "<<std::endl;
            std::cout<<"Długość pierwszego boku: "<<std::fixed<<std::setprecision(10)<<ab<<std::endl;
            std::cout<<"Długość pierwszego boku: "<<std::fixed<<std::setprecision(10)<<cd<<std::endl;
        }else{
            std::cout<<"Krótsze przeciwległe boki nie są równe!!!"<<std::endl;
            std::cout<<"Długość pierwszego boku: "<<std::fixed<<std::setprecision(10)<<ab<<std::endl;
            std::cout<<"Długość pierwszego boku: "<<std::fixed<<std::setprecision(10)<<cd<<std::endl;
        }
    }
}
void Prostokat::wyswietl(){
    for(int i=0;i<ILOSCBOKOW;++i){
        std::cout<<std::setw(16)<<this->Figura[i]<<std::endl;}
    
}