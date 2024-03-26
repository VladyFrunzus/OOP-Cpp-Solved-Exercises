#include <bits/stdc++.h>

using namespace std;

class Player
{
public:
    int h,m,l,vp;
    Player() {};
    Player(int h1, int m1, int l1, int vp1)
    {
        h=h1;
        m=m1;
        l=l1;
        vp=vp1;
    }
    void IcecrownCitadel()
    {
        vp=vp+h+m+l;
    }
};

class Orcs: public Player
{
    int wl;
public:
    Orcs(): Player() {};
    Orcs(int h1,int m1,int l1,int vp1) : Player(h1,m1,l1,vp1)
    {
        wl=0;
    }
    void Naxxramas()
    {
        vp=vp+2*m+l;
        wl++;
    }
    void BlackrockDepths()
    {
        vp=vp+2*h+m;
    }
    void HealthPointsHorde()
    {
        if(vp>=5+h/3)
        {
            vp=vp-5-h/3;
            h++;
        }
    }
    void LevelHorde()
    {
        if(vp>=5+l/6)
        {
            vp=vp-5-l/6;
            l++;
        }
    }
    void ManaHorde()
    {
        if(vp>=3+h/7)
        {
            vp=vp-3-h/7;
            m++;
        }
    }
    void ZiHorde(string s)
    {
        if(s=="H")
            HealthPointsHorde();
        else if(s=="M")
            ManaHorde();
        else if(s=="L")
            LevelHorde();
        else if(s=="ICC")
            IcecrownCitadel();
        else if(s=="NX")
            Naxxramas();
        else if(s=="BK")
            BlackrockDepths();
        cout<<h<<" "<<m<<" "<<l<<" "<<vp<<" "<<wl<<'\n';
    }
};

class Humans: public Player
{
    int gc,ngc;
public:
    Humans(): Player() {};
    Humans(int h1,int m1, int l1,int vp1): Player(h1,m1,l1,vp1)
    {
        gc=0;
        ngc=0;
    }
    void Stratholme()
    {
        vp=vp+2*h+l;
    }
    void VioletHold()
    {
        vp=vp+2*l+m;
        ngc++;
        if(ngc==4)
            gc=1;
    }
    void HealthPointsHumans()
    {
        if(vp>=8+h/4)
        {
            vp=vp-8-h/4;
            h++;
        }
    }
    void LevelHumans()
    {
        if(vp>=4+l/5)
        {
            vp=vp-4-l/5;
            l++;
        }
    }
    void ManaHumans()
    {
        if(vp>=5+m/5)
        {
            vp=vp-5-m/5;
            m++;
        }
    }
    void ZiHuman(string s)
    {
        if(s=="H")
            HealthPointsHumans();
        else if(s=="M")
            ManaHumans();
        else if(s=="L")
            LevelHumans();
        else if(s=="ICC")
            IcecrownCitadel();
        else if(s=="SA")
            Stratholme();
        else if(s=="VH")
            VioletHold();
        cout<<h<<" "<<m<<" "<<l<<" "<<vp<<" "<<gc<<'\n';
    }
};

int main()
{
    int i,j,nro,nrh,nr;
    string s[100][100];
    Orcs *o,obj1(1,1,1,0);
    Humans *h,obj2(1,1,1,0);
    cin>>nro>>nrh>>nr;
    o=new Orcs[nro];
    for(i=0; i<nro; i++)
        o[i]=obj1;
    h=new Humans[nrh+nro];
    for(i=nro; i<nro+nrh; i++)
        h[i]=obj2;
    for(i=0; i<nr; i++)
        for(j=0; j<nro+nrh; j++)
            cin>>s[i][j];
    for(i=0; i<nr; i++)
    {
        for(j=0; j<nro; j++)
            o[j].ZiHorde(s[i][j]);
        for(j=nro; j<nro+nrh; j++)
            h[j].ZiHuman(s[i][j]);
    }
    return 0;
}

