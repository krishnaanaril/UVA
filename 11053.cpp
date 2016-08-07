/*
	Swamy Saranam

	Date	: 24/07/2016 15:14:40
	Author	: Krishna Mohan A M
	Problem	: 11053 - Flavius Josephus Reloaded
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
int n, a, b;
map<ll, int> mp;

int main()
{
    FASTIO
    while(cin>>n)
    {
        if(n==0)
            break;
        mp.clear();
        cin>>a>>b;
        //mp[0]++;
        ll next  = 0, cnt = 0;
        /*while(mp[next]<2)
        {
            //cout<<next<<" - "<<mp[next]<<endl;
            mp[next]++;
            if(mp[next]==3)
                break;
            if(mp[next]==2)
                cnt++;
            next = ((a*((next*next)%n)%n) + b)%n;
        }
        cout<<(n-cnt)<<endl;
        next = cnt = 0;
        mp.clear();*/
        while(true)
        {
            //cout<<next<<" - "<<mp[next]<<endl;
            if(mp[next]!=0)
                break;
            mp[next] = cnt++;
            next = ((a*((next*next)%n)%n) + b)%n;
        }
        cout<<(n-cnt+mp[next])<<endl;
    }
    return 0;
}
