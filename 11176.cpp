/*
	Swamy Saranam

	Date	: 17/07/2016 13:49:54
	Author	: Krishna Mohan A M
	Problem	:
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
int num;
double p, n, dp[505][505], pp[505];

double solve()
{
    pp[0] = 1;
    FOR(i, 1, num+1)
        pp[i] = pp[i-1]*p;
    REP(i, num+1)
        dp[0][i] = 1;
    FOR(i, 1, num+1)
    {
        REP(j, num+1)
        {
            dp[i][j] = dp[i-1][j];
            if(j==i-1)
                dp[i][j] -= pp[i];   
            else if(j<i-1)
                dp[i][j] -= dp[i-j-2][j]*n*pp[j+1];
        }
    }
    double ans = 0;
    FOR(i, 1, num+1)
        ans += i * (dp[num][i] - dp[num][i-1]);
    return ans;
}

int main()
{
    FASTIO    
    while(cin>>num>>p)
    {
        if(num==0)
            break;
        n = 1-p;
        cout<<fixed<<setprecision(6)<<solve()<<endl;        
    }
    return 0;
}
