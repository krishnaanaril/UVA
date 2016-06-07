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

int t;
ll a, b, c, d;

bool isQuadrangle(ll a, ll b, ll c, ll d)
{
    if(a >= (b+c+d) ||
        b >= (a+c+d) ||
        c >= (a+b+d) ||
        d >= (a+b+c))
        return false;
    return true;
}

bool isSquare(ll a, ll b, ll c, ll d)
{
    if(a == b && b == c && c == d) // (a+b+c+d) == 4*a
        return true;
    return false;
}

bool isRectangle(ll a, ll b, ll c, ll d)
{
    if(( a==b && c==d) ||
        ( a==c && b==d) ||
        ( a==d && b==c))
        return true;
    return false;
}

int main()
{
    FASTIO
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d;
        if(isSquare(a, b, c, d))
        {
            cout<<"square"<<endl;
        }
        else if(isRectangle(a, b, c, d))
        {
            cout<<"rectangle"<<endl;
        }    
        else if(isQuadrangle(a, b, c, d))
            cout<<"quadrangle"<<endl;
        else
        {
            cout<<"banana"<<endl;
        }  
    }
    return 0;
}
