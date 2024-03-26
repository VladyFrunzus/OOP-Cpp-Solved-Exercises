#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class vect
{
    int n;
    double *v;
public:
    vect();
    vect(int n1, double *v1);
    void push(int i, double x);
    double pop(int i);
    double medie();
    double stdev();
    ~vect();
};

vect::vect()
{
    v=NULL;
    n=0;
}

vect::~vect()
{
    delete[] v;
}

void vect::push(int i, double x)
{
    v[i]=x;
}

vect::vect(int n1, double *v1)
{
    n=n1;
    v=new double[n];
    for(int i=0; i<n; i++)
        push(i,v1[i]);
}

double vect::pop(int i)
{
    return v[i];
}

double vect::medie()
{
    double S=0;
    int i;
    for(i=0; i<n; i++)
        S=S+pop(i);
    return S/n;
}

double vect::stdev()
{
    double S=0;
    int i;
    for(i=0; i<n; i++)
        S=S+pow(pop(i)-medie(),2);
    return sqrt(S/n);
}

int main()
{
    int n1;
    double *v1;
    cin>>n1;
    v1=new double[n1];
    for(int i=0; i<n1; i++)
        cin>>v1[i];
    vect obj(n1,v1);
    cout<<fixed<<setprecision(2)<<obj.medie();
    cout<<fixed<<setprecision(2)<<" "<<obj.stdev();
    return 0;
}
Footer
© 2023 GitHub, Inc.
Footer navigation

