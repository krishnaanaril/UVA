#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

typedef unsigned long long ll;
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
/*const int M = 1e6+5;
bitset<M> isPrime;*/
ll n;

/*void init()
{
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    for(int i=4; i<M; i+=2)
        isPrime[i] = 0;
    primes.pb(2);
    for(int i=3; i<M; i+=2)
        if(isPrime[i])
        {
            primes.pb(i);
            for(int j=2*i; j<M; j+=i)
                isPrime[j] = 0;
        }
}

int lcm(int a, int b)
{
    return a/__gcd(a, b)*b;
}*/

int main()
{
    FASTIO
    //init();
    //int sz=primes.size();
    while(cin>>n)
    {
        if(n==0)
            break;
        vector<ll> factors;
        ll t = n;
        for(ll i=2; i*i<=n; i++)
        {
            ll cnt = 0;
            while(t%i==0)
            {
                ++cnt;
                t/=i;
            }
            if(cnt>0)
                factors.pb(cnt);
        }
        //cout<<t<<endl;
        if(t>1LL)
            factors.pb(1);
        ll len = factors.size();
        /*cout<<"Len: "<<len<<endl;
        REP(i, 11)
            cout<<factors[i]<<" ";
        cout<<endl;*/
        ll ans = 1;
        REP(i, len)
        {
            ans *= (2LL*factors[i])+1;
        }
        ans++;
        ans/=2;
        
        cout<<n<<" "<<ans<<endl; 
    }      
    return 0;
}
