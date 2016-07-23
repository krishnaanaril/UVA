/*
	Swamy Saranam

	Date	: 21/07/2016 00:05:17
	Author	: Krishna Mohan A M
	Problem	: 10491 - Cows and Cars
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
int cow, car, show;
double total, rem, ans;

int main()
{
    FASTIO
    while(cin>>cow>>car>>show)
    {
        total = car+cow;
        rem = total - show -1;
        ans = cow/total * car/rem + car/total * (car-1)/rem;
        cout<<fixed<<setprecision(5)<<ans<<endl;
    }
    return 0;
}
