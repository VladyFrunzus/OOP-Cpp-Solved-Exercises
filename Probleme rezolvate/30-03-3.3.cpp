#include <iostream>
#include <string>
using namespace std;
class Student
{
protected:
    string nume,facultate;
    double medie;
public:
    Student() {};
    Student(string a, string b, double c)
    {
        nume=a;
        facultate=b;
        medie=c;
    }
};
class Absolvent : public Student
{
private:
    bool Licenta;
public:
    Absolvent() {};
    Absolvent(string a, string b, double c): Student(a,b,c) {};
    bool verificare()
    {
        if(facultate!="ETTI")
            Licenta=0;
        else if(medie<6)
            Licenta=0;
        else
            Licenta=1;
        return Licenta;
    }
    void situatie()
    {
        if(verificare())
            cout<<"DA";
        else
            cout<<"NU";
    }
};
int main()
{
    string n,f;
    double m;
    cin>>n>>f>>m;
    Absolvent Ionel(n,f,m);
    Ionel.situatie();
    return 0;
}
