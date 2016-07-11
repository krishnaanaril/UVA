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
const int MAXN = 1e6+5;
const ll INF = 1e12+5;
ll t, a, b, lo, hi;
vector<ll> primes;
bitset<MAXN> isPrime;

void init()
{
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    //primes.pb(2);
    for(ll i=4; i<INF; i*=2)
        primes.pb(i); 
    for(int i=3; i<MAXN; i+=2)
    {
        if(isPrime[i])
        {
            for(int j=2*i; j<MAXN; j+=i)
                isPrime[j] = 0;
            for(ll j=1LL*i*i; j<INF; j*=(ll)i)
                primes.pb(j);
        }
    }
    sort(primes.begin(), primes.end());
}

int main()
{
    FASTIO
    init();
    /*REP(i, 20)
        cout<<primes[i]<<" \n"[i==19];*/
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        lo = lower_bound(primes.begin(), primes.end(), a) - primes.begin();
        hi = upper_bound(primes.begin(), primes.end(), b) - primes.begin();
        //cout<<primes.size()<<" "<<lo<<" "<<hi<<endl;
        cout<<(hi-lo)<<endl;
    }
    return 0;
}
