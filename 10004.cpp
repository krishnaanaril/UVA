/*
	Swamy Saranam

	Date	: 27/08/2016 16:48:10
	Author	: Krishna Mohan A M
	Problem	: 10004 	Bicoloring
	Status	:
*/
#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<double, double>	pdd;
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
#define EPS             1e-6
#define	endl			"\n"

const int mod = 1000000007;
int n, e;
vi graph[205];
bitset<205> isVisited;
int color[205], a, b;

bool solve()
{
	//Using BFS
	memset(color, -1, sizeof(color));
	color[0] = 0;
	queue<int> q;
	q.push(0);
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		//cout<<"Curr: "<<curr<<endl;
		int c = color[curr];
		for(int i=0; i<graph[curr].size();i++)
		{
			/*if(curr==2)
				cout<<graph[curr][i]<<" "<<color[graph[curr][i]]<<endl;*/
			if(color[graph[curr][i]] == -1)
			{
				color[graph[curr][i]] = !c;
				q.push(graph[curr][i]);
			}
			else if(color[graph[curr][i]]==c)
				return false;
		}
	}
	return true;
}

int main()
{
    FASTIO
    while(cin>>n)
    {
    	if(n==0)
    		break;
		cin>>e;
		REP(i, 205)
			graph[i].clear();
		REP(i, e)
		{
			cin>>a>>b;
			graph[a].pb(b);
			graph[b].pb(a);
		}
		if(solve())
			cout<<"BICOLORABLE."<<endl;
		else
			cout<<"NOT BICOLORABLE."<<endl;
    }
    return 0;
}
