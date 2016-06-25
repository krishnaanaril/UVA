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
#define endl            "\n"

const int mod = 1000000007;

vi dat, M, Mid, P;
int tmp, n, pos;

void print(int end)
{
    if(end<0)
        return;
    print(P[end]);
    cout<<dat[end]<<endl;
}

int main()
{
    FASTIO
    while(cin>>tmp)
    {
        dat.pb(tmp);
    }
    n = dat.size();
    M.resize(n);
    Mid.resize(n);
    P.resize(n);
    int l = 0, lend = 0;
    REP(i, n)
    {
        pos = lower_bound(M.begin(), M.begin()+l, dat[i]) - M.begin();
        M[pos] = dat[i];
        Mid[pos] = i;
        P[i] = pos>0 ? Mid[pos-1] : -1;
        if(pos==l)
        {
            l++;
            lend = i;
        }
    }
    cout<<l<<endl<<"-"<<endl;
    print(lend);
    return 0;
}
