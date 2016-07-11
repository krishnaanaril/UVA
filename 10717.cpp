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

vi coins, tables, large, small;
int n, t, tmp, lcmVal, lVal, sVal;

int lcm(int a, int b)
{
    return (a)/__gcd(a, b)*b;
}

int main()
{
    FASTIO
    while(cin>>n>>t)
    {
        if(n+t==0)
            break;
        coins.clear();
        tables.clear();    
        large.clear();
        small.clear();    
        large.resize(t, -1);
        small.resize(t, -1);
        //cout<<endl<<large[n-1]<<" "<<small[n-1]<<endl<<endl;
        REP(i, n)
        {
            cin>>tmp;
            coins.pb(tmp);
        }
        REP(i, t)
        {
            cin>>tmp;
            tables.pb(tmp);
        }
        REP(i, n)
            FOR(j, i+1, n)
                FOR(k, j+1, n)
                    FOR(l, k+1, n)
                    {
                        lcmVal = lcm(coins[i], lcm(coins[j], lcm(coins[k], coins[l])));
                        REP(m, t)
                        {
                            lVal = tables[m]/lcmVal*lcmVal;
                            sVal = (tables[m]+lcmVal-1)/lcmVal*lcmVal;
                            if(large[m]==-1 || large[m]<lVal)
                                large[m] = lVal;
                            if(small[m]==-1 || small[m]>sVal)
                                small[m] = sVal;
                        }
                    }
        REP(i, t)
            cout<<large[i]<<" "<<small[i]<<endl;
    }
    return 0;
}
