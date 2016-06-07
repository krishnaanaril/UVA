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
const double R = 6378;
const double pi = 3.141592653589793;//acos(-1);

int n, m, q, ca;
string city1, city2;
double a, b;
map<string, pdd> dat;
map<string, int> mp;
double dp[400][400];

void init()
{
    dat.clear();
    mp.clear();
    REP(i, n)
        REP(j, n)
            dp[i][j] = 0xffffffffLL;
}

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

int main()
{
    FASTIO
    while(cin>>n>>m>>q)
    {
        if(n+m+q == 0)
            break;
        if(ca!=0)
            cout<<endl;
        ca++;
        cout<<"Case #"<<ca<<endl;
        init();
        REP(i, n)
        {
            cin>>city1>>a>>b;
            dat[city1] = pdd(a, b);
            mp[city1] = i;
        }
        REP(i, m)
        {
            cin>>city1>>city2;
            dp[mp[city1]][mp[city2]] = (ll)(greatCircleDistance(dat[city1], dat[city2])+0.5);
            //cout<<city1<<" "<<city2<<" = "<<dp[mp[city1]][mp[city2]]<<endl;
        }
        REP(k, n)
            REP(i, n)
                REP(j, n)               
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        REP(i, q)
        {
            cin>>city1>>city2;
            if(dp[mp[city1]][mp[city2]] == 0xffffffffLL)
                cout<<"no route exists"<<endl;
            else
                cout<<dp[mp[city1]][mp[city2]]<<" km"<<endl;
        }
    }
    return 0;
}
