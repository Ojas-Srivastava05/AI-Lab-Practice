#include<bits/stdc++.h>
using namespace std;

vector<vector<string>>prem;
vector<string>conc;
unordered_map<string,bool>inferred;

int main()
{

    cout<<"Enter the number of rules"<<endl;
    int n;
    cin>>n;
    prem.resize(n);
    conc.resize(n);
    vector<int>count(n);
    cout<<"Enter the rules in the format k A B ...."<<endl;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        prem[i].resize(k);
        for(int j=0;j<k;j++)
        {
            cin>>prem[i][j];
            inferred[prem[i][j]]=false;
        }
        cin>>conc[i];
        inferred[conc[i]]=false;
        count[i]=k;
    }
    cout<<"Enter the number of facts"<<endl;
    queue<string>q;
    int f;
    cin>>f;
    for(int i=0;i<f;i++)
    {
        string temp;
        cin>>temp;
        q.push(temp);
    }
    string query;
    cout<<"Enter the query to check"<<endl;
    cin>>query;
    bool found=false;
    while(!q.empty())
    {
        auto p=q.front();
        q.pop();
        if(p==query)
        {
            cout<<"TRUE"<<endl;
            return 0;
        }
        if(!inferred[p])
        {
            inferred[p]=true;
            for(int i=0;i<n;i++)
            {
                for(auto &x:prem[i])
                {
                    if(p==x)
                    {
                        count[i]--;
                        if(count[i]==0 && !inferred[conc[i]])
                        {
                            q.push(conc[i]);
                        }
                        break;
                    }
                }
            }
        }
    }
    cout<<"FALSE"<<endl;
    return 0;
}