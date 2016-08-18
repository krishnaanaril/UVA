/*
	Swamy Saranam

	Date	: 18/08/2016 19:17:54
	Author	: Krishna Mohan A M
	Problem	: 103 - Stacking Boxes
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
int n, d, tmp, pos, ter, curr, start, res, len;
vi dat[35], path;
int parent[35], best[35], id[35];
bitset<35> visited;

void printPath(int x)
{
  if(x==parent[x])
    return;
  printPath(parent[x]);
  path.pb(id[parent[x]]);
}

bool cmp (int x, int y)
{
    for ( int i = 0; i < d; i++ ) {
        if ( dat[x][i] <= dat[y][i] )
            return false;
    }
    return true;
}

int main()
{
    FASTIO
    while(cin>>n>>d)
    {
      path.clear();
      FOR(i, 1, n+1)
      {
        dat[i].clear();
      }
      REP(i, n)
      {
        REP(j, d)
        {
          cin>>tmp;
          dat[i+1].pb(tmp);
        }
        id[i+1] = i+1;
        SORT(dat[i+1]);
      }
      //sort(dat+1, dat+n+1);
     for ( int i = 1; i <=n; i++ ) {
          for ( int j = i + 1; j <=n; j++ ) {
                  if ( cmp (i, j) )
                  {
                    swap (dat[i], dat[j]);
                    swap(id[i], id[j]);
                  }
          }
      }
      for(int i=1; i<=n; i++)
      {
        best[i] = 1;
        parent[i] = i;
      }
      for(int i=2; i<=n; i++)
      {
        for(int j=1; j<i; j++)
        {
          if(cmp(i, j) && best[i] < best[j] + 1)
          {
            best[i] = best[j]+1;
            parent[i] = j;
          }
        }
      }
      int res = 0, index;
      FOR(i, 1, n+1)
      {
        //cout<<best[i]<<" ";
        if(best[i]>res)
        {
          res = best[i];
          index = i;
        }
      }
      /*cout<<endl;
      FOR(i, 1, n+1)
        cout<<parent[i]<<" ";
      cout<<endl;
      FOR(i, 1, n+1)
        cout<<id[i]<<" ";
      cout<<endl;
      cout<<"Ans "<<res<<" Ind: "<<index<<endl;*/
      cout<<res<<endl;
      printPath(index);
      path.pb(id[index]);
      REP(j, path.size())
      {
        if(j)
          cout<<" ";
        cout<<path[j];
      }
      cout<<endl;
      /*FOR(i, 1, n+1)
      {
        for(auto j : dat[i])
          cout<<j<<" ";
        cout<<endl;
      }*/
    }
    return 0;
}
