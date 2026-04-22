#include<bits/stdc++.h>
using namespace std;

map<string, set<string>> domain;
map<string, vector<string>> adj;

bool revise(string xi, string xj)
{
    bool revised = false;
    vector<string> toRemove;

    for(auto x : domain[xi])
    {
        bool ok = false;
        for(auto y : domain[xj])
        {
            if(x != y)
            {
                ok = true;
                break;
            }
        }
        if(!ok) toRemove.push_back(x);
    }

    for(auto x : toRemove)
    {
        domain[xi].erase(x);
        revised = true;
    }

    return revised;
}

void AC3()
{
    queue<pair<string,string>> q;

    for(auto &p : adj)
    {
        for(auto &nbr : p.second)
            q.push({p.first, nbr});
    }

    while(!q.empty())
    {
        auto [xi,xj] = q.front();
        q.pop();

        if(revise(xi,xj))
        {
            if(domain[xi].empty())
            {
                cout<<"FAILURE\n";
                return;
            }

            for(auto &xk : adj[xi])
            {
                if(xk != xj)
                    q.push({xk, xi});
            }
        }
    }

    cout<<"Domains after AC-3:\n";
    for(auto &p : domain)
    {
        cout<<p.first<<": ";
        for(auto x : p.second) cout<<x<<" ";
        cout<<"\n";
    }
}

int main()
{
    vector<string> vars = {"P1","P2","P3","P4","P5","P6"};
    vector<string> rooms = {"R1","R2","R3"};

    for(auto v : vars)
        domain[v] = set<string>(rooms.begin(), rooms.end());

    adj["P1"] = {"P2","P3","P6"};
    adj["P2"] = {"P1","P3","P4"};
    adj["P3"] = {"P1","P2","P5"};
    adj["P4"] = {"P2","P6"};
    adj["P5"] = {"P3","P6"};
    adj["P6"] = {"P1","P4","P5"};

    domain["P1"] = {"R1"};

    AC3();
}