#include <bits/stdc++.h>

using namespace std;

class Biblioteca
{
public:
    vector<int> a;
    virtual void biblioteca(vector<int> b) = 0;
    Biblioteca() {};
};

class Literatura : virtual public Biblioteca
{
public:
    void biblioteca(vector<int> b)override
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

class Manuscrise : virtual public Biblioteca
{
public:
    void biblioteca(vector<int> b)override
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

class Carti_Rare: public Manuscrise,Literatura
{
public:
    void biblioteca(vector<int> b)override
    {
        int i=0;
        deque<int> c;
        a=b;
        while(i<a.size())
        {
            if(a[i]>=100)
            {
                if(a[i]>9999)
                    if(a[i]%2==0&&a[i-1]<100)
                        c.pop_front();
                    else if(a[i]%2==0&&a[i-1]>=100)
                        c.pop_back();
                    else
                        c.pop_front();
                else
                    c.push_back(a[i]);
            }
            else
                c.push_front(a[i]);
            i++;
        }
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
    Literatura b1;
    Manuscrise b2;
    Carti_Rare b3;
    b1.biblioteca(c);
    b2.biblioteca(c);
    b3.biblioteca(c);
}
