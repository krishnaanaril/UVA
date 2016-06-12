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

const int mod = 1000000007;

typedef struct line
{
    pdd s, e;
    /*line(pdd a, pdd b)
    {   
        s = a;
        e = b;
    }*/
}line;

int n;
vector<line> dat;
line tmp;
bool flag;
vi ans;

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
    while(cin>>n)
    {
        if(n==0)
            break;
        dat.clear();
        ans.clear();
        REP(i, n)
        {
            cin>>tmp.s.x>>tmp.s.y>>tmp.e.x>>tmp.e.y;
            dat.pb(tmp);
        }
        REP(i, n)
        { 
            flag = true;          
            FOR(j, i+1, n)
            {
                if(doIntersect(dat[i].s, dat[i].e, dat[j].s, dat[j].e))
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans.pb(i+1);
        }
        int sz= ans.size();
        cout<<"Top sticks: ";
        REP(i, sz)
        {
            cout<<ans[i];
            if(i<sz-1)
                cout<<", ";
            else
                cout<<".";
        }    
        cout<<endl;
    }
    return 0;
}
