#include <bits/stdc++.h>

using namespace std;

class Servicii
{
protected:
    long mins, sms, gb;
public:
    Servicii() {};
    Servicii(long mins1, long sms1, long gb1)
    {
        mins=mins1;
        sms=sms1;
        gb=gb1;
    }
    virtual double cheltuiala()
    {
        return 0;
    };
};

class Abonament_Standard: public Servicii
{
public:
    Abonament_Standard(): Servicii() {};
    Abonament_Standard(long mins1, long sms1, long gb1): Servicii(mins1, sms1, gb1) {};
    double cheltuiala()
    {
        double val=50;
        if(mins>100)
            val=val+(mins-100)*0.1;
        if(sms>100)
            val=val+(sms-100)*0.5;
        if(gb>10)
            val=val+gb-10;
        return val;
    }
};

class Abonament_S_Plus: public Servicii
{
public:
    Abonament_S_Plus(): Servicii() {};
    Abonament_S_Plus(long mins1, long sms1, long gb1): Servicii(mins1, sms1, gb1) {};
    double cheltuiala()
    {
        double val=75;
        if(mins>200)
            val=val+(mins-200)*0.15;
        if(sms>200)
            val=val+(sms-200)*0.75;
        if(gb>15)
            val=val+(gb-15)*15;
        return val;
    }
};

class Clienti
{
    double id, cheltuiala;
public:
    Clienti() {};
    void get(double id1)
    {
        id=id1;
        cheltuiala=0;
    }
    void adaugare(double valoare)
    {
        cheltuiala=cheltuiala+valoare;
    }
    double return_id()
    {
        return id;
    }
    double return_cheltuiala()
    {
        return cheltuiala;
    }
};

int main()
{
    int i,j,n,m=0, aux1;
    double id1, mins1, sms1, gb1, Max=0, aux;
    char s;
    Clienti *c;
    cin>>n;
    c=new Clienti[n];
    for(i=0; i<n; i++)
    {
        cin>>id1>>s>>mins1>>sms1>>gb1;
        aux1=-1;
        for(j=0; j<m; j++)
            if(c[j].return_id()==id1)
                aux1=j;
        if(aux1==-1)
        {
            aux1=m;
            c[aux1].get(id1);
            m++;
        }
        if(s=='A')
        {
            Abonament_Standard ab(mins1,sms1,gb1);
            c[aux1].adaugare(ab.cheltuiala());
        }
        else
        {
            Abonament_S_Plus ab(mins1,sms1,gb1);
            c[aux1].adaugare(ab.cheltuiala());
        }
    }
    for(i=0; i<m; i++)
        if(c[i].return_cheltuiala()>Max)
        {
            Max=c[i].return_cheltuiala();
            aux=c[i].return_id();
        }
    cout<<aux;
    return 0;
}
