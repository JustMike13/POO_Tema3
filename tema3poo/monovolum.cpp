#include "monovolum.h"
#include <iostream>

monovolum::monovolum():masina()
{
    this->tip=4;
    this->nou=true;
    this->vechime=0;
    std::cout<<"monovolum fp\n";
};
monovolum::monovolum(std::string marca="",std::string model="",int pret=0,bool nou=0,int vechime=0):masina(marca,model,4,pret),nou(nou),vechime(vechime)
{
    std::cout<<"monovolum p\n";
};
monovolum::monovolum(const monovolum& mono):masina(mono.marca,mono.model,mono.tip,mono.pret),nou(mono.nou),vechime(mono.vechime)
{
    std::cout<<"CC monovolum\n";
};
monovolum::~monovolum()
{
    std::cout<<"del monovolum\n";
};
int monovolum::cumpara()
{
    if(nou==true)
    {
        return this->pret;
    }
    else if (  pret-((5*(this->vechime)/100)*pret)  <100) return 100;
            else pret-((5*(this->vechime)/100)*pret);
};
void monovolum::afiseaza()
{
    std::string a="";
    int b=(this->cumpara());
    if (this->nou!=true) a="Second Hand";
    std::cout<<this->marca<<" "<<this->model<<" "<<a<<"  Pret: "<<b<<" Euro\n";
};




monovolum& operator>>(std::istream& in, monovolum& m)
{
    in>>m.marca;
    in>>m.model;
    in>>m.pret;
    in>>m.nou;
    in>>m.vechime;
    return m;
}
void operator<<(std::ostream& out, monovolum& m)
{
    m.afiseaza();
}
monovolum monovolum:: operator=(const monovolum m2)
{
    return m2;
}

