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
const double eps = 1e-6;

int t, a, b;
double a1, b1, c1, a2, b2, c2, D, Dx, Dy;
pii p[4];

bool isSame(double a, double b)
{
    return fabs(a - b) < eps;
}

int main()
{
    FASTIO
    cout<<"INTERSECTING LINES OUTPUT"<<endl;
    cin>>t;
    while(t--)
    {
        REP(i, 4)
        {
            cin>>p[i].x>>p[i].y;            
        }
        a1 = p[0].y - p[1].y ;
        b1 = p[1].x - p[0].x ;
        c1 = b1*p[0].y + a1*p[0].x;
        a2 = p[2].y - p[3].y ;
        b2 = p[3].x - p[2].x ;
        c2 = b2*p[2].y + a2*p[2].x;
        //cross product  - got from the solution of morris
        D = a1*b2 - a2*b1;
        Dx = c1*b2 - b1*c2;
        Dy = a1*c2 - a2*c1;
        if(!D && (Dx || Dy))
            cout<<"NONE"<<endl;
        else if (!D && !Dx && !Dy)
            cout<<"LINE"<<endl;
        else
        {
            cout<<"POINT "<<setprecision(2)<<fixed<<(Dx/D)<<" "<<(Dy/D)<<endl;
        }
    }
    cout<<"END OF OUTPUT"<<endl;
    return 0;
}
