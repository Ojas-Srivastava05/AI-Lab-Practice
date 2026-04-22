#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of rules"<<endl;
    cin>>n;

    vector<vector<string>>prem(n);
    vector<string>conc(n);
    vector<int>count(n);
    unordered_map<string,int>mp;

    for(int i=0;i<n;i++)
    {
        int k;
        cout<<"Enter the value in format k A B"<<endl;
        cin>>k;
        prem[i].resize(k);
        for(int j=0;j<k;j++)
        {
            cin>>prem[i][j];
            mp[prem[i][j]]=false;
        }
        cin>>conc[i];
        mp[conc[i]]=false;
        count[i]=k;
    }
    queue<string>q;
    cout<<"Enter the number of facts"<<endl;
    int u;
    cin>>u;
    for(int i=0;i<u;i++)
    {
        string temp;
        cin>>temp;
        q.push(temp);
    }
    string query;
    cout<<"Enter the query"<<endl;
    cin>>query;
    while(!q.empty())
    {
        string p=q.front();
        q.pop();
        if(p==query)
        {
            cout<<"TRUE"<<endl;
            return 0;
        }
        if(!mp[p])
        {
            mp[p]=true;
            for(int i=0;i<n;i++)
            {
                for(auto &x:prem[i])
                {
                    if(x==p)
                    {
                        count[i]--;
                        if(count[i]==0 && !mp[conc[i]])
                        {
                            q.push(conc[i]);
                        }
                    }
                }
            }
        }
    }
    cout<<"FALSE"<<endl;
    return 0;

}