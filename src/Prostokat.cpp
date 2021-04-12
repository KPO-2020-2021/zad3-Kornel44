#include "Prostokat.hh"
#include<iomanip>




 Wektor Prostokat::operator()(char abcd) const{
switch (abcd)
{
case 'a':
    return this->a;
    break;
case 'b':
    return this->b;
    break;
case 'c':
    return this->c;
    break;
case 'd':
    return this->d;
    break;

default:
throw std::runtime_error("zly wierzcholek prostokotu");
    break;
}
 }


 Wektor& Prostokat::operator()(char abcd) {
switch (abcd)
{
case 'a':
    return this->a;
    break;
case 'b':
    return this->b;
    break;
case 'c':
    return this->c;
    break;
case 'd':
    return this->d;
    break;

default:
throw std::runtime_error("zly wierzcholek prostokotu");
    break;
}
 }

 
std::ostream& operator << ( std::ostream   &Strm, const Prostokat &Pr){
    Strm<<std::setw(16)<<Pr('a')<<std::endl;
    Strm<<std::setw(16)<<Pr('b')<<std::endl;
    Strm<<std::setw(16)<<Pr('c')<<std::endl;
    Strm<<std::setw(16)<<Pr('d')<<std::endl;
    return Strm;
}

void Prostokat::przesuniecie(Wektor Kier){
    this->a=this->a+Kier;
    this->b=this->b+Kier;
    this->c=this->c+Kier;
    this->d=this->d+Kier;

}

void Prostokat::obrot(Macierz Kont){
  this->a=Kont*this->a;
  this->b=Kont*this->b;
  this->c=Kont*this->c;
  this->d=Kont*this->d;
}