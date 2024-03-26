#include <iostream>

using namespace std;

class Conversie
{
public:
    int a;
    Conversie() {};
    void get(int a1)
    {
        a=a1;
    }
    virtual void conversie()
    {
        int aux=a,*b,i;
        b=new int[8];
        for(i=7; i>=0; i--)
        {
            b[i]=aux%2;
            aux=aux/2;
        }
        for(i=0; i<8; i++)
            cout<<b[i];
        cout<<'\n';
    }
};

class Hexa : public Conversie
{
public:
    void conversie()
    {
        int i=1,aux=a;
        char *b;
        b=new char[2];
        while(aux)
        {
            b[i]=aux%16+48;
            aux=aux/16;
            i--;
        }
        for(i=0; i<2; i++)
            if(b[i]<=57&&b[i]>=48)
                cout<<(char)b[i];
            else if(b[i]>=58&&b[i]<=63)
                cout<<(char)(b[i]+7);
        cout<<'\n';
    }
};

class Octal : public Conversie
{
public:
    void conversie()
    {
        int i=2,aux=a;
        char *b;
        b=new char[3];
        while(aux)
        {
            b[i]=aux%8+48;
            aux=aux/8;
            i--;
        }
        for(i=0; i<3; i++)
            if(b[i]<=55&&b[i]>=48)
                cout<<b[i];
        cout<<'\n';
    }
};

int main()
{
    int a1;
    cin>>a1;
    Hexa h;
    Octal o;
    Conversie b;
    Conversie *p;
    p=&b;
    p->get(a1);
    p->conversie();
    p=&h;
    p->get(a1);
    p->conversie();
    p=&o;
    p->get(a1);
    p->conversie();
}
