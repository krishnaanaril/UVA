/*
	Swamy Saranam

	Date	: 30/07/2016 22:34:43
	Author	: Krishna Mohan A M
	Problem	: 796 - Critical Links
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
const int M = 100005;
int n, m, a, b, timer, start[M], low[M], parent[M], root;
map<int, vi> graph;
vector<pii> bridges;

void dfs(int node)
{
    int child = 0;
    bool flag = false;
    start[node] = low[node] = ++timer;
    for(auto i : graph[node])
    {
        if(start[i]==0)
        {
            parent[i] = node;
            dfs(i);
            if(node == root)            
                ++child;
            low[node] = min(low[node], low[i]);
            //printf("%d %d %d %d\n", node, i, low[i], start[node]);
            if(low[i] > start[node])
            {
                if(node > i)
                    bridges.pb(pii(i, node));
                else
                    bridges.pb(pii(node, i));
            }
        }
        else if(i != parent[node])
            low[node] = min(low[node], start[i]);
    }
}

int main()
{
    //FASTIO
    /*while(scanf("%d\n", &n))
        printf("%d ", n);*/
    while(scanf("%d", &n) != EOF)
    {
        //if(n==0)
        //    break;
        graph.clear();
        memset(start, 0, sizeof(start));
        memset(parent, 0, sizeof(parent));
        bridges.clear();
        REP(i, n)
        {
            //printf("I: %d \n", i);
            scanf("%d (%d)", &a, &m);
            REP(j, m)
            {
                scanf("%d", &b);
                graph[a].pb(b);
                //graph[b].pb(a);
            }
            //printf("%d, %d, %d\n", m, a, graph[a].size());
        }
        REP(i, n)
        {
            if(start[i]==0)
            {
                //printf("i: %d\n", i);
                root  = i;
                dfs(i);
            }
        }
        sort(bridges.begin(), bridges.end());
        printf("%d critical links\n", bridges.size());
        for(auto i : bridges)
            printf("%d - %d\n", i.x, i.y);
        printf("\n");
    }
    return 0;
}
