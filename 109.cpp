#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<double, double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;
typedef vector<pii> vp;

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

const int mod = 1000000007;

int n, a, b;
vp kd[25];
vector<vp> hulls;

bool checkInside(vp dat, pii t)
{
	int sz = dat.size();
	//cout<<"sz: "<<sz<<endl;
	bool cnt = 0;
	for(int i=0, j=sz-1; i<sz; j = i++)
	{
		if(((dat[j].y > t.y) != (dat[i].y > t.y)) &&
			(t.x < (dat[j].x - dat[i].x) * (t.y - dat[i].y) / (dat[j].y - dat[i].y) + dat[i].x))
			cnt =  !cnt;
	}
	return cnt;
}

double getArea(vp dat)
{
	double determinant = 0;
	int sz = dat.size();
	REP(i, sz)
	{
		determinant +=((dat[i].x * dat[(i+1)%sz].y) - (dat[i].y * dat[(i+1)%sz].x));
	}
	return determinant*0.5;
}

double isLeft(pii p, pii q, pii r)
{
	return (q.x - p.x)*(r.y - p.y) - (q.y - p.y)*(r.x - p.x);
}

void getConvexHull(int pos)
{
	int sz = kd[pos].size();
	int k =0;
	vp tmpHull;
	sort(kd[pos].begin(), kd[pos].end());
	REP(i, sz)
	{
		while(k>=2 && isLeft(tmpHull[k-2], tmpHull[k-1], kd[pos][i]) <= 0)
			tmpHull.pop_back(), k--;
		tmpHull.pb(kd[pos][i]);
		k++;
	}
	for(int i=sz-2, t= k+1; i>=0; i--)
	{
		while(k>=t && isLeft(tmpHull[k-2], tmpHull[k-1], kd[pos][i]) <= 0)
			tmpHull.pop_back(), k--;
		tmpHull.pb(kd[pos][i]);
		k++;
	}
	//cout<<kd[pos].size()<<" - "<<tmpHull.size()<<endl;
	hulls.pb(tmpHull);
}

int main()
{
    FASTIO  
    int cnt = 0;
	while(cin>>n)
	{
		if(n==-1)
			break;
		REP(i, n)
		{
			cin>>a>>b;
			kd[cnt].pb(pii(a, b));
		}
		cnt++;
	}
	//cout<<cnt<<endl;
	REP(i, cnt)
	{
		getConvexHull(i);	
	}
	//cout<<hulls.size()<<endl;
	double totalArea = 0;
	while(cin>>a>>b)
	{
		for(vector<vp>::iterator it = hulls.begin(); it!= hulls.end(); it++)
		{
			if(checkInside(*it, pii(a, b)))
			{
				//cout<<"Kds identified"<<endl;
				totalArea += getArea(*it);
				hulls.erase(it);
				break;
			}
		}
	}
	cout<<setprecision(2)<<fixed<<totalArea<<endl;
    return 0;
}