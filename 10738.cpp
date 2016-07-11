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
const int M = 1e6+5;
int n, v[M];
bitset<M> isPrime, isSQFree;


void init()
{
    isPrime.set();
    isSQFree.set();
    isPrime[0] = isPrime[1] = 0;
    v[1] = 1;
    v[2] = -1;    
    for(int i=4; i<M; i+=2)
    {
        isPrime[i] = 0;
        v[i]++;
        if(i%4==0)
        {
            isSQFree[i] = 0;
            v[i] = 0;
        }
    }    
    for(int i=3; i<M; i+=2)
    {
        if(isPrime[i])
        {
            v[i]++;
            for(int j=2*i; j<M; j+=i)
            {                
                isPrime[j] = 0;
                if(j%(i*i)==0)
                {
                    isSQFree[j]=0;
                    v[j]=0;
                }
                else if(isSQFree[j])
                    v[j]++;
            }
        }
    }    
    FOR(i, 2, M)
        if(v[i]>0)
        {
            if(v[i]&1)
                v[i] = -1;
            else
                v[i] = 1;
        }
    FOR(i, 2, M)
        v[i] += v[i-1];
}

int main()
{
    FASTIO
    init();
    /*cout<<"Done 4"<<endl;
    REP(i, 21)
        cout<<i<<" "<<v[i]<<endl;
    cout<<"Done..."<<endl;*/
    while(cin>>n)
    {
        if(n==0)
            break;
        cout<<setw(8)<<n<<setw(8)<<(v[n] - v[n-1])<<setw(8)<<v[n]<<endl;
    }
    return 0;
}
