/*
	Swamy Saranam

	Date	: 28/08/2016 19:47:19
	Author	: Krishna Mohan A M
	Problem	: 108 - Maximum Sum
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
int dat[105][105], tmp[105];
int n;

int KadaneAlgo()
{
  int ans, curr;
  ans = curr= tmp[0];
  FOR(i, 1, n)
  {
    curr = max(tmp[i], curr+tmp[i]);
    ans = max(ans, curr);
  }
  return ans;
}

int solve()
{
  int ans = INT_MIN;
  int curr;
  for(int left = 0; left<n; left++)
  {
    CL(tmp, 0);
    for(int right = left; right<n; right++)
    {
      REP(i, n)
        tmp[i] += dat[i][right];
      curr = KadaneAlgo();
      ans = max(ans, curr);
    }
  }
  return ans;
}

int main()
{
  FASTIO
  while(cin>>n)
  {
    REP(i, n)
      REP(j, n)
        cin>>dat[i][j];
    cout<<solve()<<endl;
  }
  return 0;
}
