/*
    Another solution using multiset
*/

#include <bits/stdc++.h>

using namespace std;

typedef multiset<int> msi;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, tmp, ans;
    msi k;
    vi d;
    while(true)
    {
        cin>>n>>m;
        ans=0;
        if(n==0 && m==0)
            break;
        d.clear();
        k.clear();
        for(int i=0; i<n; i++)
        {
            cin>>tmp;
            d.push_back(tmp);
        }
        for(int i=0; i<m; i++)
        {
            cin>>tmp;
            k.insert(tmp);
        }
        int flag=0;
        for(int i=0; i<n; i++)
        {
            msi::iterator tm = k.lower_bound(d[i]);
            if(tm == k.end())
            {
                flag=1;
                break;
            }
            ans+=*tm;
            k.erase(tm);
        }
        if(flag)
            cout<<"Loowater is doomed!"<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}
