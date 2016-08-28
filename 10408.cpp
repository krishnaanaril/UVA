/*
	Swamy Saranam

	Date	: 27/08/2016 16:57:36
	Author	: Krishna Mohan A M
	Problem	: 10408 	Farey sequences
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
int n, k, tmp, a, b, c, d, cnt;

int main()
{
    FASTIO
    while(cin>>n>>k)
    {
	    a = 0;
	    b = 1;
	    c = 1;
	    d = n;
	    cnt = 0;
	    //cout<<a<<"/"<<b<<endl;
	    while(c<=n && cnt<k)
	    {
	    	tmp = (n+b)/d;
	    	int ta = a;
	    	int tb = b;
	    	a = c;
	    	b = d;
	    	c = tmp*c - ta;
	    	d = tmp*d - tb;
	    	//cout<<a<<"/"<<b<<endl;
	    	cnt++;
	    }
	    cout<<a<<"/"<<b<<endl;
    }
    return 0;
}
