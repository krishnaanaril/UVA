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

const int mod = 1000000007;
const double R = 6371009;
const double pi = acos(-1);

pdd a, b;
int t;

double greatCircleDistance(pdd a, pdd b)
{
    a.x *= pi/180.0;
    b.x *= pi/180.0;
    a.y *= pi/180.0;
    b.y *= pi/180.0;
    return R*acos(cos(a.x)*cos(a.y)*cos(b.x)*cos(b.y) +
                cos(a.x)*sin(a.y)*cos(b.x)*sin(b.y) +
                sin(a.x)*sin(b.x));
}

double tunnelDistance(pdd a, pdd b)
{
    a.x *= pi/180.0;
    b.x *= pi/180.0;
    a.y *= pi/180.0;
    b.y *= pi/180.0;
    double dx = cos(b.x)*cos(b.y) - cos(a.x)*cos(a.y);
    double dy = cos(b.x)*sin(b.y) - cos(a.x)*sin(a.y);
    double dz = sin(b.x) - sin(a.x);
    return R*sqrt(dx*dx + dy*dy + dz*dz);
}

int main()
{
    FASTIO
    cin>>t;
    while(t--)
    {
        cin>>a.x>>a.y>>b.x>>b.y;
        cout<<setprecision(0)<<fixed<<(greatCircleDistance(a, b)-tunnelDistance(a, b))<<endl;
    }
    return 0;
}
