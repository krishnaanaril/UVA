#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pld;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;
typedef pair<double, double> pdd;
typedef vector<pdd> vp;

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

int n;
double a, b, c, d, xl, xr, yt, yb;
vp line;

bool in(double p, double q, double c)
{
    //cout<<p<<" "<<q<<" "<<c<<" "<<(c >= p && c <= q)<<endl;
    return c >= p && c <= q;
}

bool online(pdd p, pdd q, pdd c)
{
    double maxx = max(p.x, q.x);
    double minx = min(p.x, q.x);
    double maxy = max(p.y, q.y);
    double miny = min(p.y, q.y);
    if(in(minx, maxx, c.x)!=0 && in(miny, maxy, c.y)!=0)
        if((p.x - q.x)*(c.y - p.y) ==  (p.y - q.y)*(c.x - p.x))
            return true;
    return false;
}

double cross(pdd p, pdd q, pdd r)
{
    return (q.x - p.x)*(r.y - p.y) - (q.y - p.y)*(r.x - p.x);
}

bool doIntersect(pdd p, pdd q, pdd a, pdd b)
{
    if(online(p, q, a) || online(p, q, b) || online(a, b, p) || online(a, b, q))
        return true;
    if(cross(p, q, a)*cross(p, q, b) < 0 &&
        cross(q, p, a)*cross(q, p, b) < 0 &&
        cross(a, b, p)*cross(a, b, q) < 0 &&
        cross(b, a, p)*cross(b, a, q) < 0)
        return true;
    return false;
}

int main()
{
    FASTIO
    cin>>n;
    while(n--)
    {
        cin>>a>>b>>c>>d;
        line.clear();
        line.pb(pdd(a, b));
        line.pb(pdd(c, d));
        cin>>xl>>yt>>xr>>yb;
        if(xl>xr)
            swap(xl, xr);
        if(yb>yt)
            swap(yt, yb);
        //cout<<xl<<" "<<xr<<" "<<yt<<" "<<yb<<endl;
        bool isInside =  false;
        if(in(xl, xr, line[0].x) && in(yb, yt, line[0].y))
            isInside = true;
        else if(in(xl, xr, line[1].x) && in(yb, yt, line[1].y))
            isInside = true;
        else
        {
            isInside |= doIntersect(pdd(xl, yt), pdd(xl, yb), line[0], line[1]);
            //cout<<"3. "<<isInside<<endl; 
            isInside |= doIntersect(pdd(xl, yb), pdd(xr, yb), line[0], line[1]);
            //cout<<"4. "<<isInside<<endl; 
            isInside |= doIntersect(pdd(xr, yb), pdd(xr, yt), line[0], line[1]);
            //cout<<"5. "<<isInside<<endl; 
            isInside |= doIntersect(pdd(xr, yt), pdd(xl, yt), line[0], line[1]);
            //cout<<"6. "<<isInside<<endl;            
        }
        if(isInside)
            cout<<"T"<<endl;
        else
            cout<<"F"<<endl;
    }
    return 0;
}
