#include <bits/stdc++.h>

using namespace std;

class Vector
{
public:
    float *v;
    Vector() {};
    Vector(float *v1)
    {
        v=v1;
    }
};

class Matrice
{
public:
    float **m;
    Matrice() {};
    Matrice(float **m1)
    {
        m=m1;
    }
    float Determinant(float **m1)
    {
        float S=0,P1,P2;
        for(int i=0; i<3; i++)
        {
            P1=1;
            P2=1;
            for(int j=0; j<3; j++)
            {
                P1=P1*m1[(i+j)%3][j];
                P2=P2*m1[(i+j)%3][2-j];
            }
            S=S+P1-P2;
        }
        return S;
    }
};

class Sistem: public Vector, Matrice
{
public:
    Sistem(float *v1,float **m1) : Vector(v1),Matrice(m1) {};
    float **Inloccol(int c)
    {
        float **m1;
        int i,j;
        m1=new float*[3];
        for(i=0; i<3; i++)
            m1[i]=new float[3];
        for(i=0; i<3; i++)
            for(j=0; j<3; j++)
                m1[i][j]=m[i][j];
        for(i=0; i<3; i++)
            m1[i][c]=v[i];
        return m1;
    }
    void RezolvareSistem()
    {
        cout<<fixed<<setprecision(2)<<Determinant(Inloccol(0))/Determinant(m)<<'\n'<<Determinant(Inloccol(1))/Determinant(m)<<'\n'<<Determinant(Inloccol(2))/Determinant(m);
    }
};


int main()
{
    float *v1, **m1;
    int i,j;
    v1=new float[3];
    m1=new float*[3];
    for(i=0; i<3; i++)
        m1[i]=new float[3];
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
            cin>>m1[i][j];
        cin>>v1[i];
    }
    Sistem Kra(v1,m1);
    Kra.RezolvareSistem();
    return 0;
}
