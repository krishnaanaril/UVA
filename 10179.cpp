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

int fi(int n)
{
    int t = n;
    int res = n;
    for(int i=2; i*i<=t;i++)
    {
        if(t%i==0)
            res -= res/i;
        while(t%i==0)
            t/=i;
    }
    if(t>1)
        res -= res/t;
    return res;
}

int n;

int main()
{
    FASTIO
    while(cin>>n)
    {
        if(n==0)
            break;
        cout<<fi(n)<<endl;
    }
    return 0;
}
