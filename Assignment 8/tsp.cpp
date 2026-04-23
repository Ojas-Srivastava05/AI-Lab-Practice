#include<bits/stdc++.h>
using namespace std;

int g[8][8] = {
{0,10,15,20,25,30,35,40},
{12,0,35,15,20,25,30,45},
{25,30,0,10,40,20,15,35},
{18,25,12,0,15,30,20,10},
{22,18,28,20,0,15,25,30},
{35,22,18,28,12,0,40,20},
{30,35,22,18,28,32,0,15},
{40,28,35,22,18,25,12,0}
};

int cost(vector<int> &p)
{
    int c=0,n=p.size();
    for(int i=0;i<n;i++)
        c+=g[p[i]][p[(i+1)%n]];
    return c;
}

int main()
{
    vector<int> p = {0,1,2,3,4,5,6,7};

    int best = 1e9;
    vector<int> ans;

    do
    {
        int c = cost(p);
        if(c < best)
        {
            best = c;
            ans = p;
        }
    } while(next_permutation(p.begin()+1, p.end())); // fix start

    cout<<"Min Cost = "<<best<<"\n";

    for(int x:ans) cout<<x<<" ";
}