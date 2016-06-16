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

const int mod = 1000000007;

double x, y, c, w;

bool solve()
{
    double res = 1 - (c/sqrt(y*y-w*w)) - (c/sqrt(x*x-w*w));
    return res>0;
}
int main()
{
    FASTIO
    while(cin>>x>>y>>c)
    {
        double lo = 0, hi = min(x, y);
        while(fabs(hi-lo)>1e-9)
        {
            w = (hi+lo)/2.0;           
            if(solve())
                lo = w;
            else
                hi = w;
        }
        cout<<setprecision(3)<<fixed<<w<<endl;
    }
    return 0;
}
