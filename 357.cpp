/*
	Swamy Saranam

	Date	: 27/08/2016 15:10:28
	Author	: Krishna Mohan A M
	Problem	: 357 - Let Me Count The Ways
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
int m, n;
ll dp[30005], cents[] = {1, 5, 10, 25, 50};

void init()
{
  /*REP(i, 5)
    dp[cents[i]] = 1;*/
  dp[0] = 1;
  REP(j, 5)
  {
    FOR(i, cents[j], 30005)
    {
      dp[i] += dp[i-cents[j]];
    }
  }
}

int main()
{
    FASTIO
    init();
    /*REP(i, 21)
      cout<<i<<" - "<<dp[i]<<endl;*/
    while(cin>>n)
    {
      if(dp[n]==1)
        cout<<"There is only 1 way to produce "<<n<<" cents change.\n";
      else
        cout<<"There are "<<dp[n]<<" ways to produce "<<n<<" cents change.\n";
    }
    return 0;
}
