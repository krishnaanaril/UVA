/*
	Swamy Saranam

	Date	: 27/08/2016 17:03:17
	Author	: Krishna Mohan A M
	Problem	: 1709 	Amalgamated Artichokes
	Status	:
*/
#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<double, double>	pdd;
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
#define EPS             1e-6
#define	endl			"\n"

const int mod = 1000000007;
int p, a, b, c, d, n, sz;
double ans, currMax;

int main()
{
    FASTIO
    while(cin>>p>>a>>b>>c>>d>>n)
    {
    	ans = 0;
    	currMax = p*(sin(a+b)+cos(c+d)+2);
    	ans = 0;
    	FOR(i, 2, n+1)
    	{
    		double tmp = p*(sin(a*i+b)+cos(c*i+d)+2);
    		if(tmp < currMax)
				ans = max(ans, (currMax - tmp));
			else
				currMax = tmp;
		}
		cout<<setprecision(6)<<fixed<<ans<<endl;
    }
    return 0;
}
