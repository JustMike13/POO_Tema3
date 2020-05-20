#include <iostream>
#include "masina.h"
#include "monovolum.h"
#include <vector>
#include "eroare.h"
using namespace std;
masina *lista_masini[1000],*masini_vandute[1000];int masini_it=0,masini_v=0;
monovolum *lista_monovolume[1000],*monovolume_vandute[1000];int monovolume_it=0,monovolume_v=0;
int incasari=0;
void adauga(std::string marca,std::string model,int tip,int pret,bool nou=1,int vechime=0)
{
    if (tip<4)
    {
        lista_masini[masini_it]=new masina(marca,model,tip,pret);
        masini_it++;
    }
    else{
        lista_monovolume[monovolume_it]=new monovolum(marca,model,pret,nou=1,vechime=0);
        monovolume_it++;
    }
}
void afiseaza_lista()
{
    std::cout<<"\n  Lista 1:\n";
    for(int i=0;i<masini_it;i++)
    {
        cout<<i+1<<". ";
        lista_masini[i]->afiseaza();
    }

    std::cout<<"\n  Lista 2:\n";
    for(int i=0;i<monovolume_it;i++)
    {
        cout<<i+1<<". ";
        lista_monovolume[i]->afiseaza();
    }
}

void vinde(int lista,int i)
{
    if (lista==1 && i<masini_it+1 && masini_it>-1)
    {
        masini_vandute[masini_v]=lista_masini[i-1];
        incasari+=lista_masini[i-1]->cumpara();
        std::cout<<"    Au fost retrasi "<<lista_masini[i-1]->cumpara()<<" Euro din contul dumneavoastra\n";
        for (int j=i-1;j<masini_it-1;j++)
        {
            lista_masini[j]=lista_masini[j+1];
        }
        masini_it-=1;masini_v++;
        afiseaza_lista();

    }
    else if (lista==2 && i<monovolume_it+1 && monovolume_it>-1)
    {
        monovolume_vandute[monovolume_v]=lista_monovolume[i-1];
        incasari+=lista_monovolume[i-1]->cumpara();
        std::cout<<"Au fost retrasi "<<lista_monovolume[i-1]->cumpara()<<" Euro din contul dumneavoastra!\n";
        for (int j=i-1;j<monovolume_it-1;j++)
        {
            lista_monovolume[j]=lista_monovolume[j+1];
        }
        monovolume_it-=1;monovolume_v++;
        afiseaza_lista();
    }
    else{
        eroare e=eroare();
        throw e;
    }
}
void afiseaza_vandute()
{
    int i,k;
    std::cout<<"Incasari totale: "<<incasari<<" Euro\n\n";
    for(i=0;i<masini_v;i++)
    {
        std::cout<<i+1<<". ";
        masini_vandute[i]->afiseaza();
    }
    int j=masini_v+1;
    for(k=0;k<monovolume_v;k++)
    {
        std::cout<<j+k<<". ";
        monovolume_vandute[k]->afiseaza();
    }
}
void consola()
{
    std::cout<<"\n  Ce operatie doriti sa efectuati?\n";
    std::cout<<"1. Afiseaza lista de masini\n2. Cumpara masina\n3. Iesire\n";
    int a,b,c;
    std::cout<<"Introduceti nr operatiei dorite: ";cin>>a;
    if(a==1) {afiseaza_lista();consola();}
    else if (a==2)
    {
        std::cout<<"Introduceti:\nNr lista: ";cin>>b;
        std::cout<<"\nNr masini: ";cin>>c;
        try
        {
            vinde(b,c);
        }
        catch(std::exception& e)
        {
            std::cout<<e.what()<<"\n\n";
        }
        consola();
    }
    else if(a=7862)
    {
        afiseaza_vandute();
        consola();
    }
    else std::cout<<"\n            Tranzactie incheiata cu succes!\n";

}
int main()
{
    adauga("vw","passat",3,2000);
    adauga("vw","jetta",3,1500);
    adauga("audi","a4",3,5000);
    adauga("testa","model 3",3,20000);
    adauga("vw","fsdf",4,3000);
    //adauga("vSDFRga","sdf",4,4000);
    //adauga("vjhk","psdft",4,25000);
    adauga("vsdfsdfw","psdfat",4,45000);


    std::cout<<"\n\n            Bun venit la Targul de masini FMI!\n";


    consola();
    return 0;
}
