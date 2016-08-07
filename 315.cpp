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
vi graph[105], artPoints;
int low[105], start[105];
int n, tmp, v, timer;
string st;

void dfs(int u)
{
	//cout<<"u: "<<u<<endl;
	start[u] = low[u] = ++timer;
	int child = 0;
	bool flag = 0;
	for(int i=0; i<graph[u].size(); i++)
	{
		if(start[graph[u][i]] == 0)
		{
			//cout<<u<<" - "<<graph[u][i]<<endl;
			dfs(graph[u][i]);
			++child;
			low[u] = min(low[u], low[graph[u][i]]);
			if(low[graph[u][i]] >= start[u])
				flag= 1;
		}
		else
			low[u] = min(low[u], start[graph[u][i]]);
	}
	if((u==1 && child>1) || (u!=1 && flag))
		artPoints.pb(u);
}

int main()
{
    FASTIO
    while(cin>>n)
    {
    	if(n==0)
    		break;
		cin.ignore();
		REP(i, n+1)
			graph[i].clear();
		timer = 0;
		artPoints.clear();
		while(getline(cin, st))
		{
			//cout<<st<<endl;
			if(st=="0")
				break;
			istringstream iss;
			iss.str(st);
			iss>>v;
			while(iss>>tmp)
			{
				graph[v].pb(tmp);
				graph[tmp].pb(v);
			}
		}
		/*FOR(i, 1, n+1)
			REP(j, graph[i].size())
				cout<<i<<" "<<graph[i][j]<<endl;*/
		memset(start, 0, sizeof(start));
		dfs(1);
		/*FOR(i, 1, n+1)
			if(start[i]==0)
			{
				timer = 0;
				cout<<i<<endl;
				dfs(i);
			}*/
		/*cout<<"Ans: "<<endl;
		for(int i=0; i<artPoints.size(); i++)
			cout<<artPoints[i]<<endl;*/
		cout<<artPoints.size()<<endl;
    }
    return 0;
}
