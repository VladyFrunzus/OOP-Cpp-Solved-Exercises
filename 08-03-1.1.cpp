#include <iostream>

using namespace std;

class Meteo
{
    char id[500];
    float c,t,u;
public:
    friend void setval(char s[256], float a[500], Meteo v[20][60], int m, int cont);
    friend void verificare(Meteo v[20][60],int n, int m);
    friend void smecherie(Meteo v[20][60],int n,int m);
};

void setval(char s[256], float a[500], Meteo v[20][60], int m, int cont)
{
    int i,j=1;
    for(i=0; i<4; i++)
        v[cont][0].id[i]=s[i];
    for(i=1; i<=m; i++)
    {
        v[cont][i].c=a[j];
        v[cont][i].t=a[j+1];
        v[cont][i].u=a[j+2];
        j=j+3;
    }
}

void verificare(Meteo v[20][60],int n,int m)
{
    int i,j,nr,OK,OKM=1;
    for(i=1; i<=n; i++)
    {
        nr=0;
        OK=0;
        for(j=1; j<=m; j++)
        {
            if(v[i][j].c<6||v[i][j].c>10)
                nr++;
            else if(v[i][j].t<15||v[i][j].t>25)
                nr++;
            else if(v[i][j].u>80)
                nr++;
            else
                nr=0;
            if(nr==3)
            {
                OK=1;
                break;
            }
        }
        if(OK)
        {
            cout<<v[i][0].id<<" ";
            OKM=0;
        }
    }
    if(OKM)
        cout<<"Functionare corecta";
}


int main()
{
    Meteo v[20][60];
    int n,m,i,j;
    float a[500];
    char s[256];
    cin>>n>>m;
    for(i=1; i<=n; i++)
    {
        cin>>s;
        for(j=1; j<=3*m; j++)
            cin>>a[j];
        setval(s,a,v,m,i);
    }
    verificare(v,n,m);
    return 0;
}
