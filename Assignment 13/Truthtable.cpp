#include<bits/stdc++.h>
using namespace std;

bool NOT(bool p)
{return !p;}
bool OR(bool p,bool q)
{return p||q;}
bool AND(bool p,bool q)
{return p&&q;}
bool imp(bool p,bool q)
{return (!p)||q;}
bool iff(bool p,bool q)
{return p==q;}

void print(bool x)
{
    if(x)
    cout<<"T"<<" ";
    else
    cout<<"F"<<" ";
}

int main()
{
    cout<<"P Q R Result\n";
    for(int p=0;p<2;p++)
    {
        for(int q=0;q<2;q++)
        {
            for(int r=0;r<2;r++)
            {
                bool P=p;
                bool Q=q;
                bool R=r;

                print(P);
                print(Q);
                print(R);

                bool res=imp(OR(P,Q),NOT(R));

                print(res);
                cout<<endl;
            }
        }
    }
    return 0;
}


