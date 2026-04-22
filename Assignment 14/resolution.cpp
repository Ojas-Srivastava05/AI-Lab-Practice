#include<bits/stdc++.h>
using namespace std;

vector<string> resolve(vector<string> &c1, vector<string> &c2)
{
    for(auto &x : c1)
    {
        for(auto &y : c2)
        {
            if(x == "~"+y || "~"+x == y)
            {
                vector<string> res;
                for(auto &a : c1)
                    if(a != x) res.push_back(a);
                for(auto &b : c2)
                    if(b != y) res.push_back(b);
                return res;
            }
        }
    }
    return {"NONE"};
}

int main()
{
    vector<vector<string>> clauses = {
        {"P","Q"},
        {"~P","R"},
        {"~Q","S"},
        {"~R","S"},
        {"~S"}
    };

    set<vector<string>> seen;
    bool found = false;

    while(true)
    {
        int n = clauses.size();
        bool added = false;
        vector<vector<string>> newClauses;

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                vector<string> res = resolve(clauses[i], clauses[j]);

                if(res.empty())
                {
                    found = true;
                    break;
                }

                if(res.size() == 1 && res[0] == "NONE")
                    continue;

                sort(res.begin(), res.end());

                if(seen.find(res) == seen.end())
                {
                    seen.insert(res);
                    newClauses.push_back(res);
                    added = true;
                }
            }
            if(found) break;
        }

        for(auto &c : newClauses)
            clauses.push_back(c);

        if(found || !added) break;
    }

    if(found) cout<<"TRUE\n";
    else cout<<"FALSE\n";

    return 0;
}