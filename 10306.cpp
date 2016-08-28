/*
	Swamy Saranam

	Date	: 27/08/2016 19:03:20
	Author	: Krishna Mohan A M
	Problem	: 10306 - e-Coins
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
int n, m, s, a, b;
vector<pii> dat;
int dp[1005][1005];

int main()
{
    FASTIO
    cin>>n;
    while(n--)
    {
      cin>>m>>s;
      dat.clear();
      queue<pii> q;
      CL(dp, 0);
      REP(i, m)
      {
        cin>>a>>b;
        dp[a][b] = 1;
        dat.pb(pii(a, b));
        q.push(pii(a, b));
      }
      bool isFound = false;
      while(!q.empty())
      {
        pii curr = q.front(), tmp;
        if(curr.x*curr.x + curr.y*curr.y == s*s)
        {
          cout<<dp[curr.x][curr.y]<<endl;
          isFound = true;
          break;
        }
        q.pop();
        REP(i, m)
        {
          tmp.x = curr.x+dat[i].x;
          tmp.y = curr.y+dat[i].y;
          if(tmp.x*tmp.x + tmp.y*tmp.y <= s*s)
          {
            if(dp[tmp.x][tmp.y] > dp[curr.x][curr.y]+1 || dp[tmp.x][tmp.y]==0)
            {
              dp[tmp.x][tmp.y] = dp[curr.x][curr.y]+1;
              q.push(pii(tmp.x, tmp.y));
            }
          }
        }
      }
      if(!isFound)
        cout<<"not possible"<<endl;
    }
    return 0;
}
