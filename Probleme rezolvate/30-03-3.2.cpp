#include<iostream>
#include <algorithm>
using namespace std;
class Masina
{
public:
    double pret_masina;
    double autonomie;
    Masina()
    {
        pret_masina=0;
        autonomie=0;
    }
    Masina(double x, double y)
    {
        pret_masina=x;
        autonomie=y;
    }
};
class Baterie
{
public:
    double capacitate;
    double durata_viata;
    Baterie()
    {
        capacitate=0;
        durata_viata=0;
    }
    Baterie(double x, double y)
    {
        capacitate=x;
        durata_viata=y;
    }
};
class MasinaElectrica : public Masina, public Baterie
{
public :
    MasinaElectrica(double a, double b, double c, double d) : Masina(a,b), Baterie(c,d)
    {
    }
    double pret()
    {
        return pret_masina+durata_viata*12;
    }
    double autonomie()
    {
        return (capacitate*durata_viata)/100;
    }
    void afisare()
    {
        cout<<pret()<<'\n'<<autonomie();
    }
};
int main(void)
{
    double p,a,c,d;
    cin>>p>>a>>c>>d;
    MasinaElectrica m(p,a,c,d);
    m.afisare();
    return 0;
}
