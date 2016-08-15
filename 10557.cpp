/*
	Swamy Saranam

	Date	: 15/08/2016 20:27:23
	Author	: Krishna Mohan A M
	Problem	:
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
int n, k, a, w, dist[105], st, en, weight[105];
map<int, vector<pii> > graph;

int main()
{
    FASTIO
    while(cin>>n)
    {
      if(n==-1)
        break;
      graph.clear();
      cout<<n<<endl;
      weight[0] = weight[n-1] = 0;
      REP(i, n)
      {
        cin>>w>>k;
        weight[i] = w;
        REP(j, k)
        {
          cin>>a;
          --a;
          graph[i].pb(pii(a, w));
        }
      }
      //cin>>st>>en;
      //cout<<st<<" "<<en<<endl;
      REP(i, 105)
        dist[i] = 1<<30;
      dist[0] = 100;
      REP(i, n)
        REP(j, n)
          for(auto k : graph[j])
            dist[k.x] = min(dist[k.x], dist[j]+weight[k.x]);
      REP(i, n)
        cout<<dist[i]<<sendl[i==n-1];
    }
    return 0;
}
