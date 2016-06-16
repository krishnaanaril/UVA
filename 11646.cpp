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

double a, b;
char delim;
int ca;

int main()
{
    FASTIO
    while(cin>>a>>delim>>b)
    {
        ca++;
        double lo = 0, hi = 400, L , W;
        while(fabs(hi-lo) > 1e-9)
        {
            L = (hi+lo)/2.0;
            W = b*L/a;
            double expected = (400 - 2.0*L)/2.0;
            double r = sqrt((L*L/4) + (W*W/4));
            double angle = 2.0*atan(W/L)*180/acos(-1);
            double actual = angle/360.0 * acos(-1)*2.0*r;
            if(actual>expected)
                hi = L;
            else 
                lo = L;  
        }
        cout<<"Case "<<ca<<": ";
        cout<<setprecision(10)<<fixed<<L<<" "<<W<<endl;
    }
    return 0;
}
