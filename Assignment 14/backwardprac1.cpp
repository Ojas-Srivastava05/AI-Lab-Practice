#include<bits/stdc++.h>
using namespace std;

vector<vector<string>>prem;
vector<string>conc;
unordered_map<string,bool>visited;
unordered_map<string,bool>mp;

bool solve(string goal)
{

    if(mp[goal])
    return true;

    if(visited[goal])
    return false;

    visited[goal]=true;

    for(int i=0;i<conc.size();i++)
    {
        if(conc[i]==goal)
        {
            bool ok=true;
            for(auto &p:prem[i])
            {
                if(!solve(p))
                {
                    ok=false;
                    break;
                }
            }
            if(ok)
            {
                mp[goal]=true;
                return true;
            }
        }
    }
    return true;
}

int main()
{
    int n;
    cout<<"Enter the number of rules"<<endl;
    cin>>n;
    prem.resize(n);
    conc.resize(n);
    cout<<"Enter the rules in the format k A B ..";
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        prem[i].resize(k);
        for(int j=0;j<k;j++)
        {
            cin>>prem[i][j];
            mp[prem[i][j]]=false;
        }
        cin>>conc[i];
        mp[conc[i]]=false;
    }   
    cout<<"Enter the number of facts"<<endl;
    int f;
    cin>>f;
    cout<<"Enter the facts"<<endl;
    for(int i=0;i<f;i++)
    {
        string x;
        cin>>x;
        mp[x]=true;
    }
    string query;
    cout<<"Enter the query to be checked"<<endl;
    cin>>query;

    bool res=solve(query);

    if(res)
    cout<<"TRUE"<<endl;
    else
    cout<<"FALSE"<<endl;
    return 0;
}