/*
	Swamy Saranam

	Date	: 15/08/2016 21:45:23
	Author	: Krishna Mohan A M
	Problem	: 10048 - Audiophobia
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
int c, s, q, dist[105][105], a, b, w;
//vector<pii> graph[105];

int main()
{
    FASTIO
    int ca = 0;
    while(cin>>c>>s>>q)
    {
      if((c+s+q)==0)
        break;
      ca++;
      cout<<"Case #"<<ca<<endl;
      REP(i, 105)
        REP(j, 105)
          dist[i][j] = 99999;
      REP(i, s)
      {
        cin>>a>>b>>w;
        //graph[a].pb(pii(b, w));
        dist[a][b] = w;
      }
      REP(i, c+1)
        REP(j, c+1)
          cout<<dist[i][j]<<sendl[j==c];
      REP(k, c+1)
        REP(i, c+1)
          REP(j, c+1)
            dist[i][j] = min(dist[i][j], min(dist[i][k],dist[k][j]));
      REP(i, c+1)
        REP(j, c+1)
          cout<<dist[i][j]<<sendl[j==c];
      REP(i, q)
      {
        cin>>a>>b;
        cout<<a<<" "<<b<<" ";
        cout<<dist[a][b]<<endl;
      }
    }
    return 0;
}
