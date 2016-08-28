/*
	Swamy Saranam

	Date	: 27/08/2016 16:50:38
	Author	: Krishna Mohan A M
	Problem	: 10360 	Rat Attack
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
int dat[1400][1400], ans[1400][1400];
int t, d, n, a, b, val;

void solve()
{
	int maxVal = 0, maxX, maxY;
	for(int i=0; i<1030; i++)
	{
		for(int j=0; j<1030; j++)
		{
			if(dat[i][j] != 0)
			{
				int lx = max(i-d, 0), ly = max(j-d, 0);
				int rx = min(i+d, 1029), ry = min(j+d, 1029);
				for(int l = lx; l<=rx; l++)
				{
					for(int m = ly; m<=ry; m++)
					{
						ans[l][m] += dat[i][j];
						if(ans[l][m] > maxVal)
						{
							maxVal  = ans[l][m];
							maxX = l;
							maxY = m;
						}
					}
				}
			}
		}
	}
	//maxX++; maxY++;
	cout<<maxX<<" "<<maxY<<" "<<maxVal<<endl;
	/*FOR(i, 1, 7)
	{
		FOR(j, 1, 7)
			cout<<setw(4)<<dat[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	FOR(i, 1, 7)
	{
		FOR(j, 1, 7)
			cout<<setw(4)<<ans[i][j]<<" ";
		cout<<endl;
	}*/
}

int main()
{
    FASTIO
    cin>>t;
    while(t--)
    {
    	cin>>d>>n;
    	memset(dat, 0, sizeof(dat));
    	memset(ans, 0, sizeof(ans));
    	REP(i, n)
    	{
    		cin>>a>>b>>val;
    		//--a; --b;
    		dat[a][b] = val;
    	}
    	solve();
    }
    return 0;
}
