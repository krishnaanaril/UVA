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

int x[1005][30], step =1, n;
string st;

void build(string s)
{
    int i=0, v=0;
    while(i<s.size())
    {
        if(x[v][s[i]-'a']== -1)
            v = x[v][s[i++]-'a']= step++;
        else
            v = x[v][s[i++]-'a'];
    }
}

int main()
{
    FASTIO
    memset(x, -1, sizeof(x));
    cin>>n;
    REP(i, n)
    {
        cin>>st;
        build(st);
    }
    REP(i, 10)
    {
        REP(j, 30)
            cout<<x[i][j]<<" \n"[j==(29)] ;
    }
    return 0;
}
