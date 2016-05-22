/*
    Not solved : TLE
*/

#include <bits/stdc++.h>

using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;

vvi dat;
vi ans2, dum;
int n, m, c, k, tmp, ans;


void solve(int pos, int ord, int curr)
{
    if(curr>m)
        return;
    if(pos==c)
    {
        if(curr<=m)
            ans = max(ans, curr);
        return;
    }
    for(int i=0; i< dat[pos].size(); i++)
    {
        solve(pos+1, i, curr+dat[pos][i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    while(n--)
    {
        ans=-1;
        dat.clear();
        //ans.clear();
        cin>>m>>c;
        for(int i=0; i<c; i++)
        {
            cin>>k;
            dum.clear();
            for(int j=0; j<k; j++)
            {
                cin>>tmp;
                dum.push_back(tmp);
            }
            dat.push_back(dum);
        }
        solve(0, 0, 0);
        if(ans==-1)
            cout<<"no solution"<<endl;
        else
            cout<<ans<<endl;
    }   
    return 0;
}
