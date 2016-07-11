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
#define sendl           " \n"

const int mod = 1000000007;
const int M = 50005;
int phi[M], ans[M];

void init()
{
    FOR(i, 1, M)
        phi[i] = i;
    FOR(i, 2, M)
        if(phi[i]==i)
        {
            for(int j=2*i; j<M; j+=i)
                phi[j] -= phi[j]/i;
        }
    FOR(i, 2, M)
        if(phi[i]==i)
            phi[i] = i-1;
    FOR(i, 1, M)
        ans[i] += ans[i-1]+phi[i];
    FOR(i, 1, M)
        ans[i] = 2*ans[i]-1;
}

int n;

int main()
{
    FASTIO
    init();
    while(cin>>n)
    {
        if(n==0)
            break;
        assert(n<M);
        cout<<ans[n]<<endl;
    }
    return 0;
}
