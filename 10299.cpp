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


ll fi(ll n)
{
    ll res = n;
    for(ll i=2; i*i<=n; i++)
    {
        if(n%i==0)
            res -= res/i;
        while(n%i==0)
            n/=i;
    }
    if(n>1)
        res-=res/n;
    return res;
}

ll n;

int main()
{
    FASTIO
    while(cin>>n)
    {
        if(n==0)
            break;
        if(n==1)
            cout<<"0"<<endl;
        else
            cout<<fi(n)<<endl;
    }
    return 0;
}
