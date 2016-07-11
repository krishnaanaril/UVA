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
ll n, ca;

ll getSumSquare(ll n)
{
    ll t = n, res = 0;
    while(t)
    {
        int k = t%10;
        res += k*k;
        t/=10;
    }
    return res;
}

bool solve(ll n)
{
    map<int, int> mp;
    ll t = n;
    mp[t]++;
    while(true)
    {
        t = getSumSquare(t);
        if(t==1)
            return true;
        if(mp[t]!=0)
            return false;        
        mp[t]++;
    }
}

int main()
{
    FASTIO
    int t;    
    cin>>t;
    while(t--)
    {
        ca++;
        cin>>n;
        cout<<"Case #"<<ca<<": ";
        if(solve(n))
            cout<<n<<" is a Happy number."<<endl;
        else
            cout<<n<<" is an Unhappy number."<<endl;
    }
    return 0;
}
