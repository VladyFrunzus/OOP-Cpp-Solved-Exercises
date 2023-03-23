#include <bits/stdc++.h>

using namespace std;

class FiguraGeometrica
{
public:
    float r,L,l;
    FiguraGeometrica()
    {
        r=0;
        L=0;
        l=0;
    };
    FiguraGeometrica(float r1, float L1, float l1)
    {
        r=r1;
        L=L1;
        l=l1;
    };
    virtual void getPerimetru() = 0;
    virtual void getArie() = 0;
};

class Cerc: public FiguraGeometrica
{
public:
    Cerc(): FiguraGeometrica() {};
    Cerc(float r1): FiguraGeometrica(r1,0,0) {};
    void getPerimetru()override
    {
        cout<<fixed<<setprecision(2)<<2*3.14159265359*r<<'\n';
    }
    void getArie()override
    {
        cout<<fixed<<setprecision(2)<<3.14159265359*r*r<<'\n';
    }
};

class Dreptunghi: public FiguraGeometrica
{
public:
    Dreptunghi(): FiguraGeometrica() {};
    Dreptunghi(float l1, float L1): FiguraGeometrica(0,L1,l1) {};
    void getPerimetru()override
    {
        cout<<fixed<<setprecision(2)<<2*l+2*L<<'\n';
    }
    void getArie()override
    {
        cout<<fixed<<setprecision(2)<<l*L<<'\n';
    }
};

int main()

{
    float r1,l1,L1;
    cin>>r1>>l1>>L1;
    Cerc c(r1);
    Dreptunghi d(l1,L1);
    c.getPerimetru();
    c.getArie();
    d.getPerimetru();
    d.getArie();
    return 0;
}
