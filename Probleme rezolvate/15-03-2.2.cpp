#include <iostream>

using namespace std;

class NumarMare
{
    int *v,nr;
public:
    NumarMare(int *a=NULL, int nr1=0)
    {
        nr=nr1;
        v=new int[nr];
        for(int i=0; i<nr; i++)
            v[i]=a[i];
    };
    friend istream & operator >> (istream & in, NumarMare & a)
    {
        in >> a.nr;
        a.v=new int[a.nr];
        for(int i=0; i<a.nr; i++)
            in >> a.v[i];
        return in;
    }
    friend ostream & operator << (ostream & out, const NumarMare & a)
    {
        for(int i=0; i<a.nr; i++)
            out << a.v[i];
        return out;
    }
    int &operator[](int i)
    {
        return v[i];
    }
    friend NumarMare operator < (const NumarMare& a, const NumarMare& b)
    {
        if(a.nr<b.nr)
            return b;
        else if(a.nr>b.nr)
            return a;
        else
        {
            int i=0,OK=1;
            for(i=0; i<a.nr; i++)
                if(a.v[i]<b.v[i])
                {
                    return b;
                    i=a.nr;
                    OK=0;
                }
                else if(a.v[i]>b.v[i])
                {
                    return a;
                    i=a.nr;
                    OK=0;
                }
        }
    }
    friend NumarMare operator + (NumarMare a, NumarMare b)
    {
        int i,aux;
        NumarMare c,s;
        if(a.nr>b.nr)
        {
            c.nr=a.nr;
            c.v=new int[a.nr];
            for(i=0; i<a.nr-b.nr; i++)
                c.v[i]=0;
            for(i=a.nr-b.nr; i<a.nr; i++)
                c.v[i]=b.v[i-a.nr+b.nr];
            aux=0;
            s.nr=a.nr;
            s.v=new int[a.nr];
            for(i=a.nr-1; i>0; i--)
            {
                s.v[i]=(a.v[i]+c.v[i]+aux)%10;
                aux=(a.v[i]+c.v[i]+aux)/10;
            }
            s.v[0]=a.v[0]+c.v[0]+aux;
            return s;
        }
        else if(a.nr<b.nr)
        {
            c.nr=b.nr;
            c.v=new int[b.nr];
            for(i=0; i<b.nr-a.nr; i++)
                c.v[i]=0;
            for(i=b.nr-a.nr; i<b.nr; i++)
                c.v[i]=a.v[i-b.nr+a.nr];
            aux=0;
            s.nr=b.nr;
            s.v=new int[b.nr];
            for(i=b.nr-1; i>0; i--)
            {
                s.v[i]=(b.v[i]+c.v[i]+aux)%10;
                aux=(b.v[i]+c.v[i]+aux)/10;
            }
            s.v[0]=b.v[0]+c.v[0]+aux;
            return s;
        }
        else
        {
            aux=0;
            s.nr=a.nr;
            s.v=new int[b.nr];
            for(i=b.nr-1; i>0; i--)
            {
                s.v[i]=(b.v[i]+a.v[i]+aux)%10;
                aux=(b.v[i]+a.v[i]+aux)/10;
            }
            s.v[0]=b.v[0]+a.v[0]+aux;
            return s;
        }
    }

    friend void cifre(NumarMare a, NumarMare b)
    {
        cout<<endl<<(a<b).v[0]<<endl<<(a<b).v[1]<<endl<<(a<b).v[2];
    }
};
int main()
{
    NumarMare a,b;
    cin>>a>>b;
    cout<<a+b<<endl;
    cout<<(a<b);
    cifre(a,b);
    return 0;
}
