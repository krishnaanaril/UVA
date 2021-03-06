/*
	Swamy Saranam

	Date	: 25/07/2016 22:42:13
	Author	: Krishna Mohan A M
	Problem	: 10930 - A-Sequence
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
int d, tmp;
vi dat, act;
bitset<2500> chk;

bool solve()
{
	REP(i, d)
		FOR(j, i+1, d)
			if(dat[j]<dat[i])
				return false;
	chk[0]=1;
	REP(j, d)
	{
		if(chk[dat[j]])
			return false;
		for(int i=1001; i>=0; i--)
		{
			if(chk[i])
				chk[i+dat[j]] = 1;
		}
	}
	/*REP(i, 15)
		cout<<chk[i]<<" ";
	cout<<endl;*/
	return true;
}

int main()
{
    FASTIO
    int ca = 0;
    while(cin>>d)
    {
    	ca++;
    	chk.reset();
    	dat.clear();
    	act.clear();
    	REP(i, d)
    	{
    		cin>>tmp;
    		dat.pb(tmp);
    		act.pb(tmp);
    	}
    	cout<<"Case #"<<ca<<": ";
    	REP(i, d)
    		cout<<act[i]<<" \n"[i==d-1];
    	if(solve())
    		cout<<"This is an A-sequence."<<endl;
		else
			cout<<"This is not an A-sequence."<<endl;
    }
    return 0;
}
