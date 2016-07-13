#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FASTIO          ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back
#define x               first
#define y               second
#define endl            "\n"
#define sendl           " \n"

const int mod = 1000000007;
/*
ll n, m;

ll solve()
{
    if(m==0)
        return 1;
    ll res = 1;
    for(ll i=(n-m+1); i<=n; i++)
    {
        res = res*i;
        while(res%10==0)
            res/=10;
        res %=10000000000;
    }
    return res%10;
}
*/
int main()
{
    FASTIO
    ll n, m, res;
    while(cin>>n>>m)
    {
        res = 1;
        ll c = (n-m+1);
        if(m!=0)
            //for(ll i=c; i<=n; i++) --not working
            for(ll i=n; i>=c; i--)
            {
                res = res*i;
                while(res%10==0)
                    res/=10;
                res %=1000000000;                    
            }
        res%=10;
        cout<<res<<endl;
    }
    return 0;
}
