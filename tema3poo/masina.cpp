#include "masina.h"
#include <iostream>

masina::masina()
{
    std::cout<<"masina fp\n";
}
masina::masina(std::string marca="",std::string model="",int tip=0,int pret=0): marca(marca), model(model), tip(tip), pret(pret)
    {
        std::cout<<"masina p\n";
    }
masina::~masina()
{
    std::cout<<"del masina\n";
}
masina::masina(const masina & other):marca(other.marca),model(other.model),tip(other.tip),pret(other.pret)
{
    std::cout<<"CC masina\n";
}
int masina::cumpara()
{
    return this->pret;
}
void masina::afiseaza()
{
    std::cout<<this->marca<<" "<<this->model<<"  Pret: "<<this->pret<<" Euro\n";
}
std::istream& operator>>(std::istream& in, masina& m)
{
    in>>m.marca;
    in>>m.model;
    in>>m.tip;
    in>>m.pret;
    return in;
}
void operator<<(std::ostream& out, masina& m)
{
    m.afiseaza();
}
masina masina:: operator=(const masina m2)
{
    return m2;
}
