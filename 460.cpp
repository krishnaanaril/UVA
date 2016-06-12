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

typedef struct rect
{
    pii ll;
    pii ur;
}rect;

rect a, b, res;

int main()
{
    FASTIO
    cin>>t;
    while(t--)
    {
        cin>>a.ll.x>>a.ll.y>>a.ur.x>>a.ur.y;
        cin>>b.ll.x>>b.ll.y>>b.ur.x>>b.ur.y;
        res.ll.x = max(a.ll.x, b.ll.x);
        res.ll.y = max(a.ll.y, b.ll.y);
        res.ur.x = min(a.ur.x, b.ur.x);
        res.ur.y = min(a.ur.y, b.ur.y);
        if(res.ll.x >= res.ur.x || res.ll.y >= res.ur.y)
            cout<<"No Overlap"<<endl;
        else
            cout<<res.ll.x<<" "<<res.ll.y<<" "<<res.ur.x<<" "<<res.ur.y<<endl;
        if(t)
            cout<<endl;
    }
    return 0;
}
