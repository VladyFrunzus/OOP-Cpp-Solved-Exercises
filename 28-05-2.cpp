#include <bits/stdc++.h>

using namespace std;

ifstream f("messi.in");
ofstream g("messi.out");

class Transport
{
public:
    float a1, a3, a24, c90, c1, cn;
    Transport() {};
    Transport(float a11, float a31, float a241, float c901, float c11, float cn1)
    {
        a1=a11;
        a3=a31;
        a24=a241;
        c90=c901;
        c1=c11;
        cn=cn1;
    }
};

class Metrou: virtual public Transport
{
public:
    Metrou():Transport() {};
    Metrou(float a11, float a31, float a241, float c901, float c11, float cn1): Transport(a11,a31,a241,c901,c11,cn1) {};
};

class Ratb: virtual public Transport
{
public:
    Ratb():Transport() {};
    Ratb(float a11, float a31, float a241, float c901, float c11, float cn1): Transport(a11,a31,a241,c901,c11,cn1) {};
};

class Calator: public Metrou, Ratb
{
public:
    float datam, datar, oram, orar, S;
    long long id;
    Calator()
    {
        datam=0;
        datar=0;
        oram=0;
        orar=0;
        S=0;
    };
};

int main()
{
    int i,j,zi,ora,n=-1,auxi,cont,nr;
    float a11, a31, a241, c901, c11, cn1, Sm=0, St=0;
    long long id1;
    char s[200];
    Calator cal[1200];
    cin>>a11>>a31>>a241>>c901>>c11>>cn1;
    Ratb r(a11,a31,a241,c901,c11,cn1);
    cin>>a11>>a31>>a241>>c901>>c11>>cn1;
    Metrou m(a11,a31,a241,c901,c11,cn1);
    while(cin>>zi)
    {
        cin>>ora>>id1;
        auxi=-1;
        for(i=0; i<n; i++)
            if(cal[i].id==id1)
            {
                auxi=i;
                break;
            }
        if(auxi==-1)
        {
            n++;
            auxi=n;
            cal[auxi].id=id1;
        }
        cin.getline(s,256);
        i=0;
        while(s[i]!='R'&&s[i]!='M')
            i++;
        if(s[i]=='M')
        {
            if(s[1]=='A')
            {
                if(s[2]=='1')
                {
                    cal[auxi].oram=ora;
                    cal[auxi].datam=zi+30;
                    Sm=Sm+m.a1;
                }
                else if(s[2]=='3')
                {
                    cal[auxi].oram=ora;
                    cal[auxi].datam=zi+3;
                    Sm=Sm+m.a3;
                }
                else
                {
                    cal[auxi].oram=ora;
                    cal[auxi].datam=zi+1;
                    Sm=Sm+m.a24;
                }
            }
            else if(zi>cal[auxi].datam||(zi==cal[auxi].datam && ora>cal[auxi].oram))
            {
                if(s[2]=='1')
                    Sm=Sm+m.c1;
                else if(s[2]=='9')
                {
                    if((int)(cal[auxi].oram)%100>=30)
                        cal[auxi].oram=ora+170;
                    else
                        cal[auxi].oram=ora+130;
                    if(cal[auxi].oram>=2400)
                    {
                        cal[auxi].datam=zi+1;
                        cal[auxi].oram=ora-2400;
                    }
                    else
                        cal[auxi].datam=zi;
                    Sm=Sm+m.c90;
                }
                else
                {
                    cont=2;
                    nr=0;
                    while(s[cont]!=' ')
                        cont++;
                    for(i=2; i<cont; i++)
                        nr=nr+s[i]*pow(10,cont-i-1);
                    Sm=Sm+nr*m.cn;
                }
            }
        }
        else
        {
            if(s[1]=='A')
            {
                if(s[2]=='1')
                {
                    cal[auxi].orar=ora;
                    cal[auxi].datar=zi+30;
                    St=St+r.a1;
                }
                else if(s[2]=='3')
                {
                    cal[auxi].orar=ora;
                    cal[auxi].datar=zi+3;
                    St=St+r.a3;
                }
                else
                {
                    cal[auxi].orar=ora;
                    cal[auxi].datar=zi+1;
                    St=St+r.a24;
                }
            }
            else if(zi>cal[auxi].datar||(zi==cal[auxi].datar && ora>cal[auxi].orar))
            {
                if(s[2]=='1')
                    St=St+r.c1;
                else if(s[2]=='9')
                {
                    if((int)(cal[auxi].orar)%100>=30)
                        cal[auxi].orar=ora+170;
                    else
                        cal[auxi].orar=ora+130;
                    if(cal[auxi].orar>=2400)
                    {
                        cal[auxi].datar=zi+1;
                        cal[auxi].orar=ora-2400;
                    }
                    else
                        cal[auxi].datar=zi;
                    St=St+r.c90;
                }
                else
                {
                    cont=2;
                    nr=0;
                    while(s[cont]!=' ')
                        cont++;
                    for(i=2; i<cont; i++)
                        nr=nr+s[i]*pow(10,cont-i-1);
                    St=St+nr*r.cn;
                }
            }
        }
    }
    cout<<fixed<<setprecision(2)<<St<<" "<<Sm;
    return 0;
}
