/*
	Swamy Saranam

	Date	: 14/08/2016 19:38:51
	Author	: Krishna Mohan A M
	Problem	: 11456 - Trainsorting
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
int t, n, tmp, lis[2005], lds[2005];
vi dat;


int main()
{
    FASTIO
    cin>>t;
    while(t--)
    {
      dat.clear();
      memset(lis, 0, sizeof(lis));
      memset(lds, 0, sizeof(lds));
      cin>>n;
      REP(i, n)
      {
        cin>>tmp;
        dat.pb(tmp);
      }
      for(int j=n-1; j>=0; j--)
      {
        lis[j] = lds[j] = 1;
        for(int i = j+1; i<n; i++)
        {
          if(dat[j] < dat[i])
            lis[j] = max(lis[i]+1, lis[j]);
          else if(dat[i] < dat[j])
            lds[j] = max(lds[i]+1, lds[j]);
        }
      }
      int ans = 0;
      REP(i, n)
      {
        ans = max(ans, lis[i]+lds[i]-1);
      }
      cout<<ans<<endl;
    }
    return 0;
}
