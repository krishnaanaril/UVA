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

int n, a, b, c, ad, bd, cd, len;
int maxx, maxy, maxz, minx, miny, minz;
int vol;

int main()
{
    FASTIO
    while(cin>>n)
    {
        if(n==0)
            break;
        REP(i, n)
        {
            cin>>a>>b>>c>>len;
            ad = a+len;
            bd = b+len;
            cd = c+len;
            if(i==0)
            {
                minx = ad;
                maxx = a;
                miny = bd;
                maxy = b;
                minz = cd;
                maxz = c;
            }
            maxx = max(a, maxx);
            maxy = max(b, maxy);
            maxz = max(c, maxz);
            minx = min(ad, minx);
            miny = min(bd, miny);
            minz = min(cd, minz);                        
        }
        vol = max(minx-maxx, 0) * max(miny-maxy, 0) * max(minz-maxz, 0);
        cout<<vol<<endl;
    }
    return 0;
}
