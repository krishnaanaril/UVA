/*
	Swamy Saranam

	Date	: 14/07/2016 00:07:28
	Author	: Krishna Mohan A M
	Problem	: 443 - Humble Numbers 
	Status	: Accepted
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
int n;

int main()
{
    FASTIO
    set<ll> dat = {1, 2, 3, 5, 7};
    for(auto i: dat)
    {
        if(dat.size()>6999)
            break;
        dat.insert(2*i);
        dat.insert(3*i);
        dat.insert(5*i);
        dat.insert(7*i);
    }
    vector<ll> ans(dat.begin(), dat.end());
    while(cin>>n)
    {
        if(n==0)
            break;
        int t=n;
        cout<<"The "<<(n);
        cout<<(n/10%10-1&&(n=n%10)<4&&n?n>2?"rd":n<2?"st":"nd":"th")<<" humble number is "<<ans[t-1]<<"."<<endl;
    }
    return 0;
}
