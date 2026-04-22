#include<bits/stdc++.h>
using namespace std;


vector<vector<string>>prem;
vector<string>conc;
unordered_map<string,bool>visiting;
unordered_map<string,bool>mp;

bool solve(string goal)
{
    if(mp[goal])
    return true;

    if(visiting[goal])
    return false;

    visiting[goal]=true;

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
    return false;
}

int main()
{
    int n;
    cout<<"Enter the number of rules"<<endl;
    cin>>n;
    prem.resize(n);
    conc.resize(n);

    for(int i=0;i<n;i++)
    {
        cout<<"Enter the rules in format k A B ..."<<endl;
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
    int f;
    cout<<"Enter the number of facts"<<endl;
    cin>>f;
    for(int i=0;i<f;i++)
    {
        string x;
        cout<<"Enter the facts in space separated format"<<endl;
        cin>>x;
        mp[x]=true;
    }
    string query;
    cout<<"Enter the query"<<endl;
    cin>>query;

    if(solve(query))
    cout<<"TRUE"<<endl;
    else
    cout<<"FALSE"<<endl;

    return 0;
}