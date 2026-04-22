#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of rules you have"<<endl;
    cin>>n;

    vector<vector<string>>prem(n);
    vector<string>concl(n);
    vector<int>count(n);
    queue<string>q;
    unordered_map<string,bool>inferred;

    cout<<"Enter the rules"<<endl;
    cout<<"Format: k A B....(k=number of premises)"<<endl;

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
        cin>>concl[i];
        inferred[concl[i]]=false;
        count[i]=k;
    }

    int f;
    cout<<"enter the number of facts"<<endl;
    cin>>f;


    cout<<"Enter the facts"<<endl;
    for(int i=0;i<f;i++)
    {
        string x;
        cin>>x;
        q.push(x);
        inferred[x]=false;
    }
    string query;
    cout<<"Enter query"<<endl;
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
        if(!inferred[p])
        {
            inferred[p]=true;
            for(int i=0;i<n;i++)
            {
                for(auto &x:prem[i])
                {
                    if(x==p)
                    {
                        count[i]--;

                        if(count[i]==0  && !inferred[concl[i]])
                        {
                            q.push(concl[i]);
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