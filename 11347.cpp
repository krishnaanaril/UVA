/*
	Swamy Saranam

	Date	: 13/07/2016 22:58:52
	Author	: Krishna Mohan A M
	Problem	: 11347 - Multifactorials
	Status	:
*/
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
const int M = 1005;
const ll INF = 1e18;
int primeCount[1005];
int n, k, t, sz;
string a;
vi primes;
bitset<M> isPrime;

void init()
{
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    for(int i = 4; i<M; i+=2)
        isPrime[i] = 0;
    primes.pb(2);
    for(int i=3; i<M; i+=2)
    {
        if(isPrime[i])
        {
            primes.pb(i);
            for(int j=2*i; j<M; j+=i)
                isPrime[j] = 0;
        }
    }
}

void primeFactors(int n)
{
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        primeCount[2]++;
        //printf("%d ", 2);
        n = n/2;
    }
 
    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            primeCount[i]++;
            //printf("%d ", i);
            n = n/i;
        }
    }
 
    // This condition is to handle the case whien n is a prime number
    // greater than 2
    if (n > 2)
    {
        primeCount[n]++;
        //printf ("%d ", n);
    }
}

int main()
{
    FASTIO
    //init();
    //cout<<"sz: "<<primes.size()<<endl;
    /*REP(i, 100)
        cout<<primes[i]<<" ";
    cout<<endl;*/
    int ca=0;
    cin>>t;
    while(t--)
    {
        ca++;
        memset(primeCount, 0, sizeof(primeCount));
        cin>>a;
        sz = a.size();
        n=0;
        REP(i, sz)
        {   
            if(a[i] != '!')
                n = (n*10)+(a[i]-'0');
            else
            {
                k = sz-i;
                break;
            }
        }
        cout<<"Case "<<ca<<": ";
        //cout<<n<<" "<<k<<endl;
        if(n==0 || n==1)
            cout<<1<<endl;
        else
        {
            for(int i = n; i>0; i-=k)
            {
                primeFactors(i);
            }
            ll res =1;
            REP(i, M)
            {
                if(primeCount[i])
                {
                    //cout<<i<<" "<<primeCount[i]<<endl;
                    res*=(primeCount[i]+1);
                }
                if(res>INF)
                    break;
            }            
            if(res>INF)
                cout<<"Infinity"<<endl;
            else
                cout<<res<<endl;
            //cout<<primeCount[2]<<endl;
            //cout<<res<<endl;
            //cout<<primeCount[2]<<endl;
        }
    }
    return 0;
}
