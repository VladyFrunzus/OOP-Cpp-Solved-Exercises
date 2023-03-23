#include <bits/stdc++.h>

using namespace std;

class Tara
{
public:
    int F,B,n,rp[60],bt,npd,pdc[60],npr,prc[60],nc,cc[60],nra[60],nrr;
    char r[60][60],pd[60][60],pr[60][60],c[60][60],ra[60][60];
    char nume[50];
    Tara() {};
    void get(char nume1[50], int n1, int rp1[60], int bt1, int npd1, int pdc1[60], int npr1, int prc1[60], int nc1, int cc1[60], char r1[60][60], char pd1[60][60], char pr1[60][60], char c1[60][60])
    {
        int i,j;
        strcpy(nume,nume1);
        F=100;
        B=0;
        n=n1;
        for(i=0; i<npd1; i++)
            nra[i]=pdc1[i];
        for(i=0; i<npd1; i++)
            strcpy(ra[i],pd1[i]);
        nrr=npd1;
        for(i=0; i<n; i++)
            rp[i]=rp1[i];
        bt=bt1;
        npd=npd1;
        for(i=0; i<npd; i++)
            pdc[i]=pdc1[i];
        npr=npr1;
        for(i=0; i<2*npr; i++)
            prc[i]=prc1[i];
        nc=nc1;
        for(i=0; i<nc; i++)
            cc[i]=cc1[i];
        for(i=0; i<n; i++)
            strcpy(r[i],r1[i]);
        for(i=0; i<npd; i++)
            strcpy(pd[i],pd1[i]);
        for(i=0; i<2*npr; i++)
            strcpy(pr[i],pr1[i]);
        for(i=0; i<nc; i++)
            strcpy(c[i],c1[i]);
    }
    void zilele_trec_saracia_ramane(int d)
    {
        int k,l,aux,OK;
        B=B+bt*F/100;
        if(d!=0)
            for(k=0; k<npd; k++) //produs
            {
                aux=-1;
                OK=1;
                for(l=0; l<nrr; l++)
                    if(strcmp(ra[l],pd[k])==0)
                    {
                        aux=l;
                        break;
                    }
                if(aux==-1)
                {
                    nrr++;
                    aux=nrr-1;
                    OK=0;
                }
                strcpy(ra[aux],pd[k]);
                if(OK)
                    nra[aux]=nra[aux]+pdc[k]*F/100;
                else
                    nra[aux]=pdc[k]*F/100;
            }
        for(k=0; k<npr; k++) //prelucrare
        {
            aux=-1;
            for(l=0; l<nrr; l++)
                if(strcmp(pr[2*k],ra[l])==0)
                {
                    aux=l;
                    if(nra[aux]>=prc[2*k])
                    {
                        if(nra[aux]-prc[2*k]>0)
                        {
                            nra[aux]=nra[aux]-prc[2*k];
                        }
                        else
                        {
                            for(l=aux; l>0; l--)
                            {
                                strcpy(ra[l],ra[l-1]);
                                nra[l]=nra[l-1];
                            }
                            for(l=0; l<strlen(ra[0]); l++)
                                ra[0][l]=' ';
                            nra[0]=0;
                        }
                        aux=-1;
                        OK=1;
                        for(l=0; l<nrr; l++)
                            if(strcmp(pr[2*k+1],ra[l])==0)
                            {
                                aux=l;
                                break;
                            }
                        if(aux==-1)
                        {
                            OK=0;
                            aux=0;
                            if(nra[0]!=0)
                            {
                                for(l=nrr; l>0; l--)
                                {
                                    strcpy(ra[l],ra[l-1]);
                                    nra[l]=nra[l-1];
                                }
                                for(l=0; l<strlen(ra[0]); l++)
                                    ra[0][l]=' ';
                                nra[0]=0;
                                nrr++;
                            }
                        }
                        strcpy(ra[aux],pr[2*k+1]);
                        if(OK)
                            nra[aux]=nra[aux]+prc[2*k+1]*F/100;
                        else
                            nra[aux]=prc[2*k+1]*F/100;
                    }
                    break;
                }
        }
        for(k=0; k<nc; k++) //consum
        {
            aux=-1;
            for(l=0; l<nrr; l++)
                if(strcmp(c[k],ra[l])==0)
                {
                    aux=l;
                    break;
                }
            if(aux==-1)
            {
                F=F-cc[k];
            }
            else if(nra[aux]>cc[k])
            {
                nra[aux]=nra[aux]-cc[k];
            }
            else
            {
                F=F-cc[k]+nra[aux];
                nra[aux]=0;
                for(l=aux; l<nrr-1; l++)
                {
                    strcpy(ra[l],ra[l+1]);
                    nra[l]=nra[l+1];
                }
                for(l=0; l<strlen(ra[nrr-1]); l++)
                    ra[nrr-1][l]=' ';
                nra[nrr-1]=0;
                nrr--;
            }
        }
        F=F+5;
        if(F>100)
            F=100;
        if(F<50)
            F=50;
        cout<<nume<<" "<<F<<" "<<B<<'\n';
        for(k=0; k<nrr; k++)
            cout<<ra[k]<<" "<<nra[k]<<'\n';
        cout<<'\n';
    }
//virtual char* nu_am_avut_rabdare(){};
};

/*class Firma: public Tara
{
public:
Firma():Tara(){};
char* nu_am_avut_rabdare()override
{
return "Imi pare rau, as fi avut rabdare sa fac si firma chiar daca nu conteaza la exemple, dar am si eu viata.";
}
};*/

int main()
{
    int i,j,k1,n1,rp1[60],bt1,npd1,pdc1[60],npr1,prc1[60],nc1,cc1[60],a,d,l;
    char nume1[50],*s1,s2[50];
    char pd1[60][60],pr1[60][60],c1[60][60],r1[60][60];
    Tara *v;
    v=new Tara[10];
    cin>>n1;
    for(i=0; i<n1; i++)
    {
        cin>>s2;
        strcpy(r1[i],s2);
    }
    for(i=0; i<n1; i++)
    {
        cin>>a;
        rp1[i]=a;
    }
    cin>>a>>k1;
    for(i=0; i<k1; i++)
    {
        cin>>nume1>>bt1;
        cin.getline(s2,50);
        cin>>npd1;
        for(j=0; j<npd1; j++)
            for(l=0; l<strlen(pd1[j]); l++)
                pd1[j][l]=' ';
        for(j=0; j<npr1; j++)
            for(l=0; l<strlen(pr1[j]); l++)
                pr1[j][l]=' ';
        for(j=0; j<nc1; j++)
            for(l=0; l<strlen(c1[j]); l++)
                c1[j][l]=' ';
        for(j=0; j<npd1; j++)
        {
            cin>>s2;
            strcpy(pd1[j],s2);
            cin>>a;
            pdc1[j]=a;
        }
        cin>>npr1;
        for(j=0; j<2*npr1; j++)
        {
            cin>>s2;
            strcpy(pr1[j],s2);
            cin>>a;
            prc1[j]=a;
        }
        cin>>nc1;
        for(j=0; j<nc1; j++)
        {
            cin>>s2;
            strcpy(c1[j],s2);
            cin>>a;
            cc1[j]=a;
        }
        v[i].get(nume1,n1,rp1,bt1,npd1,pdc1,npr1,prc1,nc1,cc1,r1,pd1,pr1,c1);
    }
    cin>>d;
    for(i=0; i<d; i++)
        cin>>s2>>a>>j;
    for(i=0; i<d; i++)
        for(j=0; j<k1; j++)
            v[j].zilele_trec_saracia_ramane(i);
    return 0;
}
