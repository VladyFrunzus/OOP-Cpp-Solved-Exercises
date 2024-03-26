#include <bits/stdc++.h>

using namespace std;

class Biblioteca
{
public:
    vector<int> a;
    virtual void biblioteca(vector<int> b) {};
    Biblioteca() {};
};

class Biblioteca_veche : public Biblioteca
{
public:
    void biblioteca(vector<int> b)
    {
        int i;
        vector<int> c;
        a=b;
        for(i=0; i<a.size(); i++)
            if(a[i]<=9999)
                c.push_back(a[i]);
            else if(a[i]>9999)
                c.pop_back();
        for(i=c.size()-1; i>=0; i--)
            cout<<c[i]<<" ";
        cout<<'\n';
    }
};

class Biblioteca_copii : public Biblioteca
{
public:
    void biblioteca(vector<int> b)
    {
        int i;
        deque<int> c;
        a=b;
        for(i=0; i<a.size(); i++)
            if(a[i]<=9999)
                c.push_back(a[i]);
            else if(a[i]>9999)
                c.pop_front();
        for(i=0; i<c.size(); i++)
            cout<<c[i]<<" ";
        cout<<'\n';
    }
};

int main()
{
    vector<int> c;
    string buffer;
    int data;
    getline(cin, buffer);
    istringstream iss(buffer);
    while (iss >> data)
        c.push_back(data);
    Biblioteca_veche b1;
    Biblioteca_copii b2;
    Biblioteca b;
    Biblioteca *p;
    p=&b1;
    p->biblioteca(c);
    p=&b2;
    p->biblioteca(c);
}
