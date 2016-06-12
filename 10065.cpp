#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
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

const int mod = 1000000007;

vp tiles, hull;
int n, a, b, ca;

double getArea(vp piis)
{
    int sz = piis.size();
    double det = 0;
    REP(i, sz)
    {
        det += (piis[i].x * piis[(i+1)%sz].y) - (piis[(i+1)%sz].x * piis[i].y);
    }
    return det*0.5;
}

double isLeft(pii p, pii q, pii r)
{
    /*cout<<p.x<<" "<<p.y<<endl;
    cout<<q.x<<" "<<q.y<<endl;
    cout<<r.x<<" "<<r.y<<endl;
    cout<<"Res: "<<(q.x - p.x)*(r.y - p.y) - (q.y - p.y)*(r.x - p.x)<<endl;*/
    return (q.x - p.x)*(r.y - p.y) - (q.y - p.y)*(r.x - p.x);
}

void convexHull()
{
    int sz = tiles.size();
    int k = 0;    
    sort(tiles.begin(), tiles.end());
    REP(i, sz)
	{
		while(k>=2 && isLeft(hull[k-2], hull[k-1], tiles[i]) <= 0)
			cout<<"Poping: "<<hull[k-1].x<<" "<<hull[k-1].y<<endl, hull.pop_back(), k--;
		cout<<"Pushing: "<<tiles[i].x<<" "<<tiles[i].y<<endl;
		hull.pb(tiles[i]);
		k++;
	}
	for(int i=sz-2, t= k+1; i>=0; i--)
	{
		while(k>=t && isLeft(hull[k-2], hull[k-1], tiles[i]) <= 0)
			cout<<"Poping: "<<hull[k-1].x<<" "<<hull[k-1].y<<endl,hull.pop_back(), k--;
		cout<<"Pushing: "<<tiles[i].x<<" "<<tiles[i].y<<endl;
		hull.pb(tiles[i]);
		k++;
	}
}

double cross(const pii &O, const pii &A, const pii &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// Returns a list of piis on the convex hull in counter-clockwise order.
// Note: the last pii in the returned list is the same as the first one.
vector<pii> convex_hull(vector<pii> P)
{
	int n = P.size(), k = 0;
	vector<pii> H(2*n);

	// Sort piis lexicographically
	sort(P.begin(), P.end());

	// Build lower hull
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	// Build upper hull
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	H.resize(k-1);
	return H;
}

int main()
{
    FASTIO
    while(cin>>n)
    {
        if(n==0)
            break;
        ca++;
        tiles.clear();
        hull.clear();
        REP(i, n)
        {
            cin>>a>>b;
            tiles.pb(pii(a, b));
        }
        convexHull();
        cout<<tiles.size()<<" : "<<hull.size()<<endl;
        vp newHull;
        newHull = convex_hull(tiles);
        cout<<tiles.size()<<" : "<<hull.size()<<endl;
        double tilesArea = getArea(tiles);
        double hullArea = getArea(hull);
        double res = tilesArea/hullArea*100;
        cout<<setprecision(2)<<fixed<<res<<endl;
    }
    return 0;
}
