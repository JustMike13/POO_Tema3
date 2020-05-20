#include <string>
#pragma once
class masina
{
protected:
    std::string marca;
    std::string model;
    int tip;//1=mini; 2=mica; 3=compacta;0=nedeterminat
    int pret;
public:
    masina();
    masina(std::string marca,std::string model,int tip,int pret);
    virtual ~masina();
    masina(const masina & other);
    virtual int cumpara();
    virtual void afiseaza();
    friend std::istream& operator>>(std::istream&, masina&);
    friend void operator<<(std::ostream&, masina&);
    virtual  masina operator=(const masina);
};
