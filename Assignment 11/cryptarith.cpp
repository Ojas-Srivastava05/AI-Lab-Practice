#include<bits/stdc++.h>
using namespace std;

int main()
{
    string A = "SEND", B = "MORE", C = "MONEY";

    set<char> s;
    for(char c:A) s.insert(c);
    for(char c:B) s.insert(c);
    for(char c:C) s.insert(c);

    vector<char> letters(s.begin(), s.end());

    vector<int> d = {0,1,2,3,4,5,6,7,8,9};

    do
    {
        map<char,int> mp;

        for(int i=0;i<letters.size();i++)
            mp[letters[i]] = d[i];

        if(mp[A[0]]==0 || mp[B[0]]==0 || mp[C[0]]==0) continue;

        int x=0,y=0,z=0;

        for(char c:A) x = x*10 + mp[c];
        for(char c:B) y = y*10 + mp[c];
        for(char c:C) z = z*10 + mp[c];

        if(x + y == z)
        {
            cout<<x<<" + "<<y<<" = "<<z<<"\n";
            break;
        }

    } while(next_permutation(d.begin(), d.end()));
}