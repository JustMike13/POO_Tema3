#include "masina.h"
#pragma once
class monovolum: public virtual masina
{
    bool nou;
    int vechime;
public:
    monovolum();
    monovolum(std::string marca,std::string model,int pret,bool nou,int vechime);
    monovolum(const monovolum&);
    ~monovolum();
    int cumpara();
    void afiseaza();
    friend monovolum& operator>>(std::istream&, monovolum&);
    friend void operator<<(std::ostream&, monovolum&);
    monovolum operator=(const monovolum);
};
