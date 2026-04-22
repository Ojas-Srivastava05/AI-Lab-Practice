#include<bits/stdc++.h>
using namespace std;

vector<string>solve(vector<string>c1,vector<string>c2)
{
    for(auto &x:c1)
    {
        for(auto &y:c2)
        {
            if("~"+x==y || x=="~"+y)
            {
                vector<string>temp;
                for(auto &a:c1)
                {
                    if(a!=x)
                    temp.push_back(a);
                }
                for(auto &b:c2)
                {
                    if(b!=y)
                    temp.push_back(b);
                }
                return temp;
            }
        }
    }
    return {"NONE"};
}

int main()
{
    set<vector<string>>seen;
    vector<vector<string>>newclauses;
    vector<vector<string>>clauses={
        {"P","Q"},
        {"~P","R"},
        {"~Q","S"},
        {"~R","S"},
        {"~S"}
    };

    bool found=false;

    while(true)
    {
        int n=clauses.size();
        bool added=false;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                vector<string>res=solve(clauses[i],clauses[j]);
                if(res.empty())
                {
                    found=true;
                    break;
                }

                if(res.size()==1 || res[0]=="NONE")
                continue;

                sort(res.begin(),res.end());

                if(seen.find(res)==seen.end())
                {
                    seen.insert(res);
                    newclauses.push_back(res);
                    added=true;
                }
                if(found)
                break;
            }
            if(found)
            break;
        }
        for(auto &c:newclauses)
        {
            clauses.push_back(c);
        }
        if(found||!added)
        break;
    }
    if(found)
    cout<<"TRUE"<<endl;
    else
    cout<<"FALSE"<<endl;
    return 0;


}