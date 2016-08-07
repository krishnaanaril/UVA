/*
	Swamy Saranam

	Date	: 01/08/2016 22:31:50
	Author	: Krishna Mohan A M
	Problem	:
	Status	:
*/
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i=0; i<(n); i++)
#define pb push_back

typedef long long ll;
typedef vector<int> vi;

const int M = 100005;

set<int> inStack;
stack<int> scc;
map<int, vi> graph;
int timer, start[M], low[M], parent[M], n, m, ans, a, b;

void dfs(int node)
{
	start[node] = low[node] = ++timer;
	scc.push(node);
	inStack.insert(node);
	for(auto i : graph[node])
	{
		cout<<"Node: "<<node<<" child: "<<i<<endl;
		if(start[i]==0)
		{
			dfs(i);
		}
		if(inStack.find(i) != inStack.end())
			low[node] = min(low[node], low[i]);
	}
	if(start[node] == low[node])
	{
		ans++;
		cout<<"SCC: ";
		while(!scc.empty() && scc.top() != node)
		{
			cout<<scc.top()<<" ";
			inStack.erase(scc.top());
			scc.pop();
		}
		cout<<scc.top()<<endl;
		inStack.erase(scc.top());
		scc.pop();
	}
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		memset(start, 0, sizeof(start));
		timer = ans = 0;
		graph.clear();
		inStack.clear();
		while(!scc.empty())
			scc.pop();
		REP(i, m)
		{
			cin>>a>>b;
			--a;
			--b;
			//graph[a].pb(b);
			graph[b].pb(a);
		}
		REP(i, n)
		{
			if(start[i]==0)
			{
			    dfs(i);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
