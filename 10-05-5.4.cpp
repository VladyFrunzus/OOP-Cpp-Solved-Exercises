#include <bits/stdc++.h>

using namespace std;

class Student
{
public:
    char *nume,*cnp;
    int lab, ex, eng, med;
    Student() {};
    Student(char *nume1, char *cnp1, int lab1, int ex1, int eng1)
    {
        nume=new char[20];
        nume=nume1;
        cnp=new char[20];
        cnp=cnp1;
        lab=lab1;
        ex=ex1;
        eng=eng1;
        med=0;
    }
    virtual int medie() = 0;
};

class Roman: virtual public Student
{
public:
    Roman() : Student() {};
    Roman(char *nume1, char *cnp1, int lab1, int ex1, int eng1): Student(nume1, cnp1, lab1, ex1, eng1) {};
    int medie()override
    {
        return lab+ex;
    }
};

class Strain_Erasmus: virtual public Student
{
public:
    Strain_Erasmus() : Student() {};
    Strain_Erasmus(char *nume1, char *cnp1, int lab1, int ex1, int eng1): Student(nume1, cnp1, lab1, ex1, eng1) {};
    int medie()override
    {
        if(eng>=50)
            return lab+ex;
        else
            return 0;
    }
};

class Rezultat_Examen: public Roman, Strain_Erasmus
{
public:
    Rezultat_Examen() : Student() {};
    void get(char *nume1, char *cnp1, int lab1, int ex1, int eng1)
    {
        nume=new char[20];
        nume=nume1;
        cnp=new char[20];
        cnp=cnp1;
        lab=lab1;
        ex=ex1;
        eng=eng1;
        med=0;
    };
    void rezultatr()
    {
        Roman b(nume, cnp, lab, ex, eng);
        med = b.medie();
    }
    void rezultats()
    {
        Strain_Erasmus b(nume, cnp, lab, ex, eng);
        med = b.medie();
    }
    bool roman()
    {
        if(cnp[0]=='7'||cnp[0]=='8')
            return 0;
        else
            return 1;
    }
    int medie()override
    {
        return 0;
    }
};

int main()

{
    char *nume1, *cnp1, s[200];
    int lab1, ex1, eng1, i=0, j, n, k, aux;
    Rezultat_Examen *r;
    r=new Rezultat_Examen[50];
    while(cin.getline(s,200))
        if(strlen(s)>1)
        {
            j=0;
            nume1=new char[20];
            cnp1=new char[20];
            lab1=ex1=eng1=0;
            while(s[j]!=' ')
            {
                nume1[j]=s[j];
                j++;
            }
            j++;
            k=0;
            while(s[j]!=' ')
            {
                cnp1[k]=s[j];
                j++;
                k++;
            }
            j++;
            k=j;
            aux=0;
            while(s[k]!=' ')
            {
                aux++;
                k++;
            }
            k=0;
            while(s[j]!=' ')
            {
                lab1=lab1+(s[j]-48)*pow(10,aux-k-1);
                j++;
                k++;
            }
            j++;
            k=j;
            aux=0;
            while(s[k]!=' ')
            {
                aux++;
                k++;
            }
            k=0;
            while(s[j]!=' ')
            {
                ex1=ex1+(s[j]-48)*pow(10,aux-k-1);
                j++;
                k++;
            }
            j++;
            k=j;
            aux=0;
            while(s[k])
            {
                aux++;
                k++;
            }
            k=0;
            while(s[j])
            {
                eng1=eng1+(s[j]-48)*pow(10,aux-k-1);
                j++;
                k++;
            }
            r[i].get(nume1,cnp1,lab1,ex1,eng1);
            if(r[i].roman())
                r[i].rezultatr();
            else
                r[i].rezultats();
            i++;
            nume1=NULL;
            cnp1=NULL;
        }
    n=i;
    i=0;
    for(i=0; i<n-1; i++)
        for(j=i+1; j<n; j++)
            if(r[i].med<r[j].med || (r[i].med==r[j].med  && r[i].ex < r[j].ex))
                swap(r[i],r[j]);
    for(i=0; i<n; i++)
        cout<<r[i].nume<<'\n';
    return 0;
}
