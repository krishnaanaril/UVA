/*
	Swamy Saranam

	Date	: 16/08/2016 22:33:20
	Author	: Krishna Mohan A M
	Problem	: 820 - Internet Bandwidth
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
int f, n, s, t, c, adjMat[105][105], a, b, w;
map<int, vi> adjList;
map<int, int> p;

/*
  To find the minEdge in an augmentPath
*/
void augmentPath(int v, int minEdge)
{
  if(v==s)
  {
    f=minEdge;
    return;
  }
  else if(p.count(v))
  {
    augmentPath(p[v], min(minEdge, adjMat[p[v]][v]));
    adjMat[p[v]][v] -= f;
    adjMat[v][p[v]] += f;
  }
}

int EdmondsKarp()
{
  int maxflow = 0;
  //p.clear();
  while(true)
  {
    f = 0;
    queue<int> pq;
    map<int, int> dist;
    pq.push(s);
    dist[s] = 0;
    while(!pq.empty())
    {
      int curr = pq.front();
      pq.pop();
      if(curr==t)
        break;
      for(auto i : adjList[curr])
      {
        if(adjMat[curr][i] > 0 && !dist.count(i))
        {
          dist[i] = dist[curr] + 1;
          pq.push(i);
          p[i] = curr;
        }
      }
    }
    augmentPath(t, 0xffffff);
    if(f==0)
      break;
    maxflow += f;
  }
  return maxflow;
}

int main()
{
    FASTIO
    int ca = 0;
    while(cin>>n)
    {
      if(n==0)
        break;
      /*if(ca)
        cout<<endl;*/
      ca++;
      cout<<"Network "<<ca<<endl;
      p.clear();
      memset(adjMat, 0, sizeof(adjMat));
      adjList.clear();
      cin>>s>>t>>c;
      //cout<<s<<" "<<t<<" "<<c<<endl;
      REP(i, c)
      {
        cin>>a>>b>>w;
        adjMat[a][b] += w;
        adjMat[b][a] += w;
        adjList[a].pb(b);
        adjList[b].pb(a);
      }
      cout<<"The bandwidth is "<<EdmondsKarp()<<"."<<endl;
      cout<<endl;
    }
    return 0;
}
