#include <iostream>
#include <cstring>
using namespace std;

class pokerstars
{
    int val, tip;
public:
    friend void simbol(char a[256]);
};

void simbol(char a[256])
{
    pokerstars v[500],aux;
    int j=0,k,nr1,nr2,c=1,t=0,r=0,i=0,p=0,aux1,aux2;
    while(j<15)
    {
        if(a[j]>=50&&a[j]<=57)
        {
            v[c].val=a[j]-48;
            j++;
        }
        else if(a[j]=='Z')
        {
            v[c].val=10;
            j++;
        }
        else if(a[j]=='J')
        {
            v[c].val=11;
            j++;
        }
        else if(a[j]=='Q')
        {
            v[c].val=12;
            j++;
        }
        else if(a[j]=='K')
        {
            v[c].val=13;
            j++;
        }
        else if(a[j]=='A')
        {
            v[c].val=14;
            j++;
        }
        if(a[j]=='T')
        {
            v[c].tip=1;
            t++;
            j++;
        }
        else if(a[j]=='R')
        {
            v[c].tip=2;
            r++;
            j++;
        }
        else if(a[j]=='i'||a[j]=='I')
        {
            v[c].tip=3;
            i++;
            j++;
        }
        else if(a[j]=='P')
        {
            v[c].tip=4;
            p++;
            j++;
        }
        j++;
        c++;
    }
    for(j=1; j<5; j++)
        for(k=j+1; k<=5; k++)
            if(v[j].val>v[k].val)
            {
                aux=v[j];
                v[j]=v[k];
                v[k]=aux;
            }
    if(t==5||r==5||i==5||p==5)
    {
        int OK=1;
        for(j=1; j<5; j++)
            if(v[j].val+1!=v[j+1].val)
            {
                OK=0;
                break;
            }
        if(OK)
        {
            nr1=8;
            aux1=v[5].val;
        }
        else
        {
            nr1=5;
            aux1=v[5].val;
        }
    }
    else if((v[1].val==v[2].val&&v[2].val==v[3].val&&v[3].val==v[4].val)||(v[2].val==v[3].val&&v[3].val==v[4].val&&v[4].val==v[5].val))
    {
        nr1=7;
        aux1=v[3].val;
    }
    else if((v[1].val==v[2].val&&v[2].val==v[3].val&&v[4].val==v[5].val)||(v[3].val==v[4].val&&v[4].val==v[5].val&&v[1].val==v[2].val))
    {
        nr1=6;
        aux1=v[3].val;
    }
    else if(v[5].val==v[4].val+1&&v[4].val==v[3].val+1&&v[3].val==v[2].val+1&&v[2].val==v[1].val+1)
    {
        nr1=4;
        aux1=v[5].val;
    }
    else if((v[1].val==v[2].val&&v[2].val==v[3].val)||(v[2].val==v[3].val&&v[3].val==v[4].val)||(v[3].val==v[4].val&&v[4].val==v[5].val))
    {
        nr1=3;
        aux1=v[3].val;
    }
    else if(v[1].val==v[2].val||v[2].val==v[3].val||v[3].val==v[4].val||v[4].val==v[5].val)
    {
        nr1=2;
        if(v[1].val==v[2].val||v[2].val==v[3].val)
            aux1=v[2].val;
        else if(v[3].val==v[4].val||v[4].val==v[5].val)
            aux1=v[4].val;
    }
    else
    {
        nr1=1;
        aux1=v[3].val;
    }
    t=0;
    r=0;
    i=0;
    p=0;
    j=15;
    c=1;
    while(j<30)
    {
        if(a[j]>=50&&a[j]<=57)
        {
            v[c].val=a[j]-48;
            j++;
        }
        else if(a[j]=='Z')
        {
            v[c].val=10;
            j++;
        }
        else if(a[j]=='J')
        {
            v[c].val=11;
            j++;
        }
        else if(a[j]=='Q')
        {
            v[c].val=12;
            j++;
        }
        else if(a[j]=='K')
        {
            v[c].val=13;
            j++;
        }
        else if(a[j]=='A')
        {
            v[c].val=14;
            j++;
        }
        if(a[j]=='T')
        {
            v[c].tip=1;
            t++;
            j++;
        }
        else if(a[j]=='R')
        {
            v[c].tip=2;
            r++;
            j++;
        }
        else if(a[j]=='i'||a[j]=='I')
        {
            v[c].tip=3;
            i++;
            j++;
        }
        else if(a[j]=='P')
        {
            v[c].tip=4;
            p++;
            j++;
        }
        j++;
        c++;
    }
    for(j=1; j<5; j++)
        for(k=j+1; k<=5; k++)
            if(v[j].val>v[k].val)
            {
                aux=v[j];
                v[j]=v[k];
                v[k]=aux;
            }
    if(t==5||r==5||i==5||p==5)
    {
        int OK1=1;
        for(j=1; j<5; j++)
            if(v[j].val+1!=v[j+1].val)
            {
                OK1=0;
                break;
            }
        if(OK1)
        {
            nr2=8;
            aux2=v[5].val;
        }
        else
        {
            nr2=5;
            aux2=v[5].val;
        }
    }
    else if((v[1].val==v[2].val&&v[2].val==v[3].val&&v[3].val==v[4].val)||(v[2].val==v[3].val&&v[3].val==v[4].val&&v[4].val==v[5].val))
    {
        nr2=7;
        aux2=v[3].val;
    }
    else if((v[1].val==v[2].val&&v[2].val==v[3].val&&v[4].val==v[5].val)||(v[3].val==v[4].val&&v[4].val==v[5].val&&v[1].val==v[2].val))
    {
        nr2=6;
        aux2=v[3].val;
    }
    else if(v[5].val==v[4].val+1&&v[4].val==v[3].val+1&&v[3].val==v[2].val+1&&v[2].val==v[1].val+1)
    {
        nr2=4;
        aux2=v[5].val;
    }
    else if((v[1].val==v[2].val&&v[2].val==v[3].val)||(v[2].val==v[3].val&&v[3].val==v[4].val)||(v[3].val==v[4].val&&v[4].val==v[5].val))
    {
        nr2=3;
        aux2=v[3].val;
    }
    else if(v[1].val==v[2].val||v[2].val==v[3].val||v[3].val==v[4].val||v[4].val==v[5].val)
    {
        nr2=2;
        if(v[1].val==v[2].val||v[2].val==v[3].val)
            aux2=v[2].val;
        else if(v[3].val==v[4].val||v[4].val==v[5].val)
            aux2=v[4].val;
    }
    else
    {
        nr2=1;
        aux2=v[5].val;
    }
    if(nr1>nr2)
        cout<<1;
    else if(nr1<nr2)
        cout<<2;
    else
    {
        if(aux1>aux2)
            cout<<1;
        else if(aux2>aux1)
            cout<<2;
        else
            cout<<"egal";
    }
}

int main()
{
    char a[256];
    cin.getline(a,256);
    simbol(a);
    return 0;
}
