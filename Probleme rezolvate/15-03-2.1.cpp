#include <iostream>

using namespace  std;

class Polinom
{
    int grad;
    double *coef;
public:
    Polinom(int grad1)
    {
        grad=grad1;
        coef=new double[grad+1];
    }
    ~Polinom()
    {

    }
    friend void setval(Polinom& P, double *v)
    {
        for(int i=0; i<=P.grad; i++)
            P.coef[i]=v[i];
    }
    double &operator[](int i)
    {
        return coef[i];
    }
    friend istream & operator >> (istream & in, Polinom & F)
    {
        in >> F.grad;
        for(int i=0; i<=F.grad; i++)
            in >> F.coef[i];
        return in;
    }
    friend ostream & operator << (ostream & out, const Polinom & F)
    {
        for(int i=F.grad; i>=1; i--)
            out << F.coef[i] << "*x^" << i << "+";
        out << F.coef[0] << "*x^0";
        return out;
    }
    Polinom& operator +(Polinom& P)
    {
        Polinom *T;
        int i;
        T = new Polinom(max(grad, P.grad));
        for (i = 0; i <= T->grad; i++)
            T->coef[i] = (*this)[i] + P[i];
        for (i = T->grad; i >= 0 && !T->coef[i]; i--);
        T->grad = i;
        return *T;
    }
    friend Polinom& operator*(Polinom &P1,Polinom &P2)
    {
        Polinom *T;
        int i,j;
        T = new Polinom(P1.grad+P2.grad);
        for(i=0; i<=P1.grad; i++)
            for(j=0; j<=P2.grad; j++)
                T->coef[i+j]=T->coef[i+j]+P1.coef[i]*P2.coef[j];
        for(i=T->grad; i>=0&&!T->coef[i]; i--);
        T->grad=i;
        return *T;
    }
};

int main()
{
    int a,i;
    double *v;
    cin>>a;
    Polinom P1(a);
    v=new double[a];
    for(i=0; i<=a; i++)
        cin>>v[i];
    setval(P1,v);
    cin>>a;
    Polinom P2(a);
    v=new double[a];
    for(i=0; i<=a; i++)
        cin>>v[i];
    setval(P2,v);
    cout<<P1+P2<<endl;
    cout<<P1*P2;
    return 0;
}
