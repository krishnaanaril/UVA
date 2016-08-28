/*
	Swamy Saranam

	Date	: 27/08/2016 21:21:15
	Author	: Krishna Mohan A M
	Problem	: 11517 - Exact Change
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
int dp[20005], dat[105];
int price, n, a, t;
bool visit[105];

void dfs(int curr, int k, int cnt)
{
  if(curr>20004 || visit[k] || cnt>n)
    return;
  //cout<<curr<<" : "<<k<<" : "<<dp[curr]<<" : "<<visit[k]<<" : "<<cnt<<endl;
  visit[k] =1;
  REP(i, n)
  {
    int a = curr+dat[i];
    if(a>20004 || visit[i])
      continue;
    if(dp[a] > dp[curr]+1 || dp[a]==0)
    {
      dp[a] = dp[curr]+1;
      //cout<<a<<endl;
      dfs(a, i, cnt+1);
    }
  }
  visit[k] = 0;
}

int main()
{
    FASTIO
    cin>>t;
    while(t--)
    {
      cin>>price;
      cin>>n;
      //cout<<"Price: "<<price<<" n: "<<n<<endl;
      //queue<int> q;
      CL(dp, 0);
      REP(i, n)
      {
        cin>>dat[i];
        dp[dat[i]] = 1;
        //q.push(dat[i]);
      }
      //dp[0] = 1;
      REP(i, n)
      {
        //CL(visit, 0);
        dfs(dat[i], i, 0);
      }
      /*while(!q.empty())
      {
        int curr= q.front();
        q.pop();
        REP(i, n)
        {
          a = curr+dat[i];
          if(a<10005)
          {
            if(dp[a] > dp[curr]+1 || dp[a]==0)
            {
              /*if(a==8642)
                cout<<"Curr "<<curr<<" Dat:"<<dat[i]<<endl;*/
              /*dp[a] = dp[curr]+1;
              q.push(a);
            }
          }
        }
      }*/
      bool found = false;
      for(int i=price; i<20005; i++)
      {
        if(dp[i] != 0)
        {
          found = true;
          cout<<i<<" "<<dp[i]<<endl;
          break;
        }
      }
      /*if(!found)
        cout<<price<<" ; "<<n<<endl;*/
    }
    return 0;
}
