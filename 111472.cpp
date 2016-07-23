/*
	Swamy Saranam

	Date	: 17/07/2016 22:05:15
	Author	: Krishna Mohan A M
	Problem	: 11472 - Beautiful Numbers
	Status	:
*/
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
ll dp[105][2000][15];
int n, m, t;

int solve(int n, int m)
{
    int ans = 0;
    memset(dp[0], 0, sizeof(dp[0]));
    memset(dp[1], 0, sizeof(dp[1]));
    int mx = 1<<n;
    FOR(i, 1, n)
        dp[1][1<<i][i] = 1;
    FOR(i, 1, m+1)
    {   
        memset(dp[i+1], 0, sizeof(dp[i+1]));
        FOR(j, 0, mx)
        {
            FOR(k, 0, n)
            {
                if(k)
                {
                    dp[i+1][j|(1<<(k-1))][k-1] += dp[i][j][k];
                    dp[i+1][j|(1<<(k-1))][k-1] %= mod;
                    
                }
                if(k!=(n-1))
                {
                    dp[i+1][j|(1<<(k+1))][k+1] += dp[i][j][k];
                    dp[i+1][j|(1<<(k+1))][k+1] %= mod;
                }
            }
        }
        FOR(j, 0, n)
            ans = (ans + dp[i][mx-1][j])%mod;
    }
    return ans;
}

int main()
{
    FASTIO
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        cout<<solve(n, m)<<endl;
    }
    return 0;
}
