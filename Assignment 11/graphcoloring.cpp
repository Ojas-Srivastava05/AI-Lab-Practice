#include<bits/stdc++.h>
using namespace std;

map<string, set<string>> domain;
map<string, vector<string>> adj;

bool revise(string xi, string xj)
{
    bool changed = false;
    vector<string> rem;

    for(auto x:domain[xi])
    {
        bool ok=false;
        for(auto y:domain[xj])
            if(x!=y) ok=true;

        if(!ok) rem.push_back(x);
    }

    for(auto x:rem)
        domain[xi].erase(x), changed=true;

    return changed;
}

bool AC3()
{
    queue<pair<string,string>> q;

    for(auto &p:adj)
        for(auto &n:p.second)
            q.push({p.first,n});

    while(!q.empty())
    {
        auto [xi,xj]=q.front(); q.pop();

        if(revise(xi,xj))
        {
            if(domain[xi].empty()) return false;

            for(auto &xk:adj[xi])
                if(xk!=xj) q.push({xk,xi});
        }
    }
    return true;
}

bool solve(vector<string>& vars,int i)
{
    if(i==vars.size()) return true;

    string v=vars[i];

    for(auto c:domain[v])
    {
        auto backup=domain[v];
        domain[v]={c};

        if(AC3() && solve(vars,i+1)) return true;

        domain[v]=backup;
        
    }
    return false;
}

int main()
{
    vector<string> vars={"A","B","C","D","E"};
    vector<string> colors={"R","G","B","Y"};

    for(auto v:vars)
        domain[v]=set<string>(colors.begin(),colors.end());

    adj["A"]={"B","C"};
    adj["B"]={"A","C","D"};
    adj["C"]={"A","B","D"};
    adj["D"]={"B","C","E"};
    adj["E"]={"D"};

    AC3();
    solve(vars,0);

    for(auto &p:domain)
    {
        cout<<p.first<<" -> ";
        for(auto x:p.second) cout<<x<<" ";
        cout<<"\n";
    }
}