#include <iostream>

using namespace std;

class Poligon_Regulat
{
public:
    float b,i;
    Poligon_Regulat() {};
    void get(float b1,float i1)
    {
        b=b1;
        i=i1;
    }
};
class Triunghi : public Poligon_Regulat
{
public:
    void Arie()
    {
        cout<<b*i/2<<'\n';
    }
};
class Patrulater : public Poligon_Regulat
{
public:
    void Arie()
    {
        cout<<b*i<<'\n';
    }
};

int main()
{
    float b1,i1;
    Triunghi t;
    Patrulater d;
    Poligon_Regulat *p;
    cin>>b1>>i1;
    p=&d;
    p->get(b1,i1);
    d.Arie();
    p=&t;
    p->get(b1,i1);
    t.Arie();
    return 0;
}
