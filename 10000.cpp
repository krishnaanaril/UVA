/*
	Swamy Saranam

	Date	: 18/08/2016 22:17:54
	Author	: Krishna Mohan A M
	Problem	: 10000 - Longest Paths
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
int n, s, tmp, a, b, best[105];
vi graph[105];

int main()
{
    FASTIO
    int ca = 0;
    while(cin>>n)
    {
      if(n==0)
        break;
      ca++;
      cin>>s;
      FOR(i, 1, n+1)
        graph[i].clear();
      FOR(i, 1, n+1)
        best[i] = 1;
      while(cin>>a>>b)
      {
        if(a+b == 0)
          break;
        graph[a].pb(b);
      }
      queue<int> q;
      q.push(s);
      while(!q.empty())
      {
        int curr = q.front();
        q.pop();
        for(auto i : graph[curr])
        {
          if(best[i] < best[curr]+1)
          {
            best[i] = best[curr]+1;
            q.push(i);
          }
        }
      }
      int index, maxVal = 0;
      FOR(i, 1, n+1)
      {
        if(best[i]>maxVal)
        {
          index = i;
          maxVal = best[i];
        }
      }
      --maxVal;//edge number instead of veritces
      cout<<"Case "<<ca<<": The longest path from "<<s<<" has length "<<maxVal<<", finishing at "<<index<<".\n\n";
    }
    return 0;
}
