/*
	Swamy Saranam

	Date	: 27/08/2016 16:43:50
	Author	: Krishna Mohan A M
	Problem	: 991 	Safe Salutations
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
ll nCr[35][35];

void init()
{
	nCr[0][0] = 1;
	FOR(i, 1, 26)
	{
		nCr[i][0] = 1;
		FOR(j, 1, i+1)
			nCr[i][j]  = nCr[i-1][j] + nCr[i-1][j-1];
	}
	/*
	REP(i, 20)
	{
		REP(j, 20)
			cout<<nCr[i][j]<<" ";
		cout<<endl;
	}
	*/
}

int main()
{
    FASTIO
    init();
    int n;
    bool f = 0;
    while(cin>>n)
    {
    	if(f)
    		cout<<endl;
		f = 1;
		ll ans = nCr[n<<1][n]/(n+1);
		cout<<ans<<endl;
    }
    return 0;
}
