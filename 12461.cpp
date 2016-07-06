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

int n;
/*

The last vacant seat must be either seat 1 or seat n, because otherwise the person that owns it would have occupied it.

But because the first n-1 passengers don't have tickets for either one of those seats, there's no difference between those two seats in our problem. Therefore the probability that the last vacant seat is 1 is the same as the probability that the last vacant seat is n, and they equal 1/2.

*/

int main()
{
    FASTIO
    while(cin>>n)
    {
        if(n==0)
            break;
        cout<<"1/2"<<endl;
    }
    return 0;
}
