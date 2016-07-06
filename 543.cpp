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
const int M = 1e6+10;
bitset<M> isPrime;
int n;

void init()
{
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    for(int i=4; i<M; i+=2)
        isPrime[i] = 0;
    for(int i=3; i<M; i+=2)
    {
        if(isPrime[i])
        {
            for(int j= 2*i; j<M; j+=i)
                isPrime[j] = 0;
        }
    }
}

int main()
{
    FASTIO
    init();
    while(cin>>n)
    {
        if(n==0)
            break;
        int i;
        for(i =2; i<M; i++)
        {
            if(isPrime[i] && isPrime[n-i])
            {
                cout<<n<<" = "<<i<<" + "<<(n-i)<<endl;
                break;
            }
        }
        if(i==M)
            cout<<"Goldbach's conjecture is wrong."<<endl;
    }
    return 0;
}
