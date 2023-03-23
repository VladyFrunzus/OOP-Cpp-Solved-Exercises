#include<bits/stdc++.h>
using namespace std;
class Forma
{
public:
    double xA,yA,xB,yB,xC,yC,xD,yD,dg;
    Forma()
    {
        xA=0;
        yA=0;
        xB=0;
        yB=0;
        xC=0;
        yC=0;
        xD=0;
        yD=0;
    }
    Forma(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4)
    {
        xA=x1;
        yA=y1;
        xB=x2;
        yB=y2;
        xC=x3;
        yC=y3;
        xD=x4;
        yD=y4;
    }
    void afis()
    {
        cout<<"Avem forma"<<endl;
    }
};
class patrat : public Forma
{
public:
    double l1,l2,l3,l4,dg;
    bool validp;
    patrat() : Forma(0,0,0,0,0,0,0,0) {}
    patrat(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) : Forma(x1,y1,x2,y2,x3,y3,x4,y4)
    {
    }
    bool validare_patrat()
    {
        l1=sqrt(((xA-xB)*(xA-xB))+((yA-yB)*(yA-yB)));
        l2=sqrt(((xB-xC)*(xB-xC))+((yB-yC)*(yB-yC)));
        l3=sqrt(((xC-xD)*(xC-xD))+((yC-yD)*(yC-yD)));
        l4=sqrt(((xD-xA)*(xD-xA))+((yD-yA)*(yD-yA)));
        if (l1!=l2)
        {
            validp=0;
        }
        else if (l2!=l3)
        {
            validp=0;
        }
        else if (l3!=l4)
        {
            validp=0;
        }
        else
            validp=1;
        return validp;
    }
    double Perimetru()
    {
        return 4*l1;
    }
    double Arie()
    {
        return l1*l1;
    }
    string TipForma()
    {
        return "Patrat";
    }
    bool afisp()
    {
        if(validare_patrat())
            cout<<fixed<<setprecision(2)<<Arie()<<'\n'<<Perimetru()<<'\n'<<TipForma();
        else
            return 0;
    }
};
class dreptunghi : public Forma
{
    double l1,l2,l3,l4,dg;
    const double a = 1e-9;
    bool validd;
public:
    dreptunghi() : Forma(0,0,0,0,0,0,0,0) {}
    dreptunghi(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) : Forma(x1,y1,x2,y2,x3,y3,x4,y4)
    {
    }

    bool validare_dreptunghi()
    {
        dg=sqrt(((xA-xD)*(xA-xD))+((yA-yD)*(yA-yD)));
        l1=sqrt(((xA-xB)*(xA-xB))+((yA-yB)*(yA-yB)));
        l2=sqrt(((xB-xC)*(xB-xC))+((yB-yC)*(yB-yC)));
        l3=sqrt(((xC-xD)*(xC-xD))+((yC-yD)*(yC-yD)));
        l4=sqrt(((xD-xA)*(xD-xA))+((yD-yA)*(yD-yA)));
        if (l1!=l3)
        {
            validd=0;
        }
        else if (l2!=l4)
        {
            validd=0;
        }
        else if (abs(dg*dg-l1*l1-l2*l2) < a)
        {
            validd=0;
        }
        else
            validd=1;
        return validd;
    }
    double Perimetru()
    {
        return 2*l1+2*l2;
    }
    double Arie()
    {
        return l1*l2;
    }
    string TipForma()
    {
        return "Dreptunghi";
    }
    bool afisd()
    {
        if(validare_dreptunghi())
            cout<<fixed<<setprecision(2)<<Arie()<<'\n'<<Perimetru()<<'\n'<<TipForma();
        else
            return 0;
    }
};

int main()
{
    patrat pp(0, 0, 0, 0, 0, 0, 0, 0);
    bool OK=0;
    cin>>pp.xA;
    cin>>pp.yA;
    cin>>pp.xB;
    cin>>pp.yB;
    cin>>pp.xC;
    cin>>pp.yC;
    cin>>pp.xD;
    cin>>pp.yD;
    if(pp.afisp())
        OK=1;
    else
    {
        dreptunghi dd(pp.xA,pp.yA,pp.xB,pp.yB,pp.xC,pp.yC,pp.xD,pp.yD);
        if(dd.afisd())
            OK=1;
    }
}
