#include <bits/stdc++.h>

using namespace std;

class Semnal
{
public:
    float **m;
    float tp;
    Semnal() {};
    Semnal(float tp1)
    {
        int i;
        m=new float*[3];
        for(i=0; i<4; i++)
            m[i]=new float[50];
        tp=tp1;
    }
    virtual void esantion(int n) = 0;
    virtual void adaugare(float e, int i) = 0;
};

class Dsp1: public Semnal
{
public:
    int nr;
    float S;
    Dsp1(): Semnal() {};
    Dsp1(float tp1): Semnal(tp1)
    {
        S=0;
        nr=0;
    };
    void adaugare(float e, int i)override
    {
        int j;
        for(j=0; j<4; j++)
            m[j][i]=0.123;
        m[1][i]=e;
        if(i<9)
            S=S+m[1][i];
    }
    void nr_treceri(int n)
    {
        int i;
        for(i=1; i<n; i++)
            if(m[1][i]*m[1][i-1]<=0)
                nr++;
    }
    void medie(int n)
    {
        int i;
        for(i=9; i<n; i++)
            if(i%10==9)
            {
                m[1][i]=S/9;
                S=S+m[1][i]-m[1][i-9];
            }
            else
                S=S-m[1][i-9]+m[1][i];
    }
    void prag(int n)
    {
        int i;
        for(i=0; i<n; i++)
            if(m[1][i]>=15)
                m[2][i]=1;
            else
                m[2][i]=0;
    }
    void subesantion(int n)
    {
        int i,k=0;
        for(i=0; i<n; i=i+5)
        {
            m[3][k]=m[2][i];
            k++;
        }
    }
    int OK(float a, int i) //e un pic aleator ales ce numere sunt afisate cu zecimale si ce numere nu sunt
    {
        if((int)(a*100)==(int)a||(int)(a*100)==100)
            return 1;
        else if(i==0)
            return 1;
        return 0;
    }
    void esantion(int n)override
    {
        nr_treceri(n);
        medie(n);
        prag(n);
        subesantion(n);
        m[0][0]=nr;
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<n; j++)
                if((int)(m[i][j]*1000)!=123)
                    if(OK(m[i][j],i))
                        cout<<(int)m[i][j]<<" ";
                    else
                        cout<<fixed<<setprecision(2)<<m[i][j]<<" ";
            cout<<'\n';
        }
    }
};

class Dsp2: public Semnal
{
public:
    int nr1,nr2;
    Dsp2(): Semnal() {};
    Dsp2(float tp1): Semnal(tp1)
    {
        nr1=0;
        nr2=0;
    };
    void adaugare(float e, int i)override
    {
        int j;
        for(j=0; j<4; j++)
            m[j][i]=0.123;
        m[3][i]=e;
    }
    void maxime(int n)
    {
        int i;
        for(i=0; i<n; i++)
            if(m[3][i]>m[3][i-1]&&m[3][i]>m[3][i+1])
            {
                nr1++;
                if(m[3][i]>tp)
                {
                    nr2++;
                    m[2][i]=m[3][i];
                }
                else
                    m[2][i]=(m[3][i-1]+m[3][i+1])/2;
            }
            else
                m[2][i]=m[3][i];
    }
    void esantion(int n)override
    {
        int i;
        maxime(n);
        m[0][0]=nr1;
        m[1][0]=nr2;
        for(i=0; i<3; i++)
        {
            for(int j=0; j<n; j++)
                if((int)(m[i][j]*1000)!=123)
                    if(i==0||i==1)
                        cout<<(int)m[i][j]<<" ";
                    else
                        cout<<fixed<<setprecision(2)<<m[i][j]<<" ";
            cout<<'\n';
        }
        for(i=0; i<5; i++)
            cout<<0.00<<" ";
        for(i=0; i<n; i++)
            cout<<m[2][i]<<" ";
        for(i=0; i<5; i++)
            cout<<0.00<<" ";
    }
};

int main()
{
    int n=0,i,j,ty;
    float e,tp1;
    cin>>ty>>tp1;
    if(ty==1)
    {
        Dsp1 s(tp1);
        while(cin>>e)
        {
            s.adaugare(e,n);
            n++;
        }
        s.esantion(n);
    }
    else
    {
        Dsp2 s(tp1);
        while(cin>>e)
        {
            s.adaugare(e,n);
            n++;
        }
        s.esantion(n);
    }
    return 0;
}
