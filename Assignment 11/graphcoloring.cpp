#include<bits/stdc++.h>
using namespace std;

map<string,vector<string>>adj;
map<string,int>color;

bool solve(vector<string>&nodes,int i,int k)
{
    if(i==nodes.size())
    return true;

    string node=nodes[i];
    for(int c=1;c<=k;c++)
    {
        bool ok=true;
        for(auto &nbr:adj[node])
        {
            if(color[nbr]==c)
            {
                ok=false;
                break;
            }
        }
        if(ok)
        {
            color[node]=c;
            if(solve(nodes,i+1,k))
            return true;
            color[node]=0;
        }
    }
    return false;
}