#include <iostream>

using namespace std;

class Card
{
public:
    double S;
    Card()
    {
        S=0;
    };
    void get(float b)
    {
        S=b;
    }
    virtual double operatie() {};
};
class Adaugare: public Card
{
public:
    double a;
    Adaugare(double a1,double S1)
    {
        a=a1;
        S=S1;
    }
    double operatie()override
    {
        S=S+a;
        return a;
    }
};
class Metrou: public Card
{
public:
    double m;
    Metrou(double m1,double S1): Card()
    {
        m=m1;
        S=S1;
    }
    double operatie()override
    {
        double aux;
        aux=S;
        if(S-m*3>=0)
            S=S-m*3;
        else
            while(S>=3)
                S=S-3;
        return aux-S;
    }
};
class STB: public Card
{
public:
    double stb;
    STB(double stb1,double S1): Card()
    {
        stb=stb1;
        S=S1;
    }
    double operatie()override
    {
        double aux=S;
        if(S-stb*1.5>=0)
        {
            S=S-stb*1.5;
            aux=stb*1.5;
        }
        else
        {
            while(S>=1.5)
                S=S-1.5;
            S=S-100;
            aux=aux-S;
        }
        return aux;
    }
};
class Taxi: public Card
{
public:
    double t;
    Taxi(double t1,double S1):Card()
    {
        t=t1;
        S=S1;
    }
    double operatie()override
    {
        if(S<10||S-t*2-t*2*0.025<0)
            return 0;
        else
        {
            S=S-t*2-t*2*0.025;
            return t*2+t*2*0.025;
        }
    }
};
int main()
{
    int n,z,i,Max=0,nr,aux;
    double a1;
    char c;
    Card obj;
    cin>>n>>z;
    for(i=1; i<=n; i++)
    {
        cin>>c;
        if(c=='A')
        {
            cin>>a1>>nr;
            Adaugare obja(a1,obj.S);
            if(obja.operatie()>Max)
            {
                Max=obja.operatie();
                aux=i;
            }
            obj.get(obja.S);
        }
        else if(c=='M')
        {
            cin>>a1>>nr;
            Metrou obja(a1,obj.S);
            if(obja.operatie()>Max)
            {
                Max=obja.operatie();
                aux=i;
            }
            obj.get(obja.S);
        }
        else if(c=='S')
        {
            cin>>a1>>nr;
            STB obja(a1,obj.S);
            if(obja.operatie()>Max)
            {
                Max=obja.operatie();
                aux=i;
            }
            obj.get(obja.S);
        }
        else
        {
            cin>>a1>>nr;
            Taxi obja(a1,obj.S);
            if(obja.operatie()>Max)
            {
                Max=obja.operatie();
                aux=i;
            }
            obj.get(obja.S);
        }
    }
    cout<<aux;
    return 0;
}
