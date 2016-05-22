#include <bits/stdc++.h>

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)

using namespace std;

typedef long long ll;

ll bigMod(ll a, ll b, ll mod)
{
    if(b==0)
        return 1;
    if(b==1)
        return a;
    if(b&1)
        return (a*bigMod(a, b-1, mod))%mod;
    else
    {
        ll tmp = bigMod(a, b/2, mod);
        return (tmp*tmp)%mod;
    }
}

ll x, y, n, t;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);    
    while(true)
    {
        cin>>t;
        if(t==0)
            break;
        REP(i, t)
        {
            cin>>x>>y>>n;
            cout<<bigMod(x, y, n)<<endl;
        }        
    }
    return 0;
}
