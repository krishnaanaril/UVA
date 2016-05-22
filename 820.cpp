#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0;i < n;++i)
#define FOR(i, a, b) for(int i = a;i < b;++i)
#define M 105
#define INF 1<<20

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;


int n, f, s, t, c, a , b, w;
vpii AdjList[M];
int AdjMat[M][M];
map<int, int> p;

void augment_path(int v, int minEdge)
{
    printf("%d %d\n", v, minEdge);
    if(v==t)
    { 
        f=minEdge;
        return;
    }
    else if(p.count(v))
    {
        augment_path(p[v], min(minEdge, AdjMat[p[v]][v]));
        AdjMat[p[v]][v] -= f;
        AdjMat[p[v]][v] += f;
    }
}

ll solve()
{
    ll max_flow = 0;
    while(true)
    {
        f = 0;
        queue<int> q; map<int, int> dist;
        q.push(s); dist[s] = 0;
        while(!q.empty())
        {
            int u = q.front(); q.pop();
            if(u==t)
                break;
            for(int i=0; i<AdjList[u].size(); i++)
            {
                if(AdjMat[u][AdjList[u][i].first]>0 && !dist[AdjList[u][i].first])
                {
                    dist[AdjList[u][i].first] = dist[u] + 1;
                    q.push(AdjList[u][i].first);
                    p[AdjList[u][i].first] = u;
                }
            }
        }           
        augment_path(t, INF);  
        printf("f: %d\n", f);
        if(f==0)
            break;
        max_flow+= f;
    }
    return max_flow;
}



void init()
{
    REP(i, M)
        AdjList[i].clear();
    memset(AdjMat, 0, sizeof(AdjMat));
}

int main()
{
    int ca = 0;
    while(scanf("%d", &n) && n != 0)
    {
        ++ca;
        init();
        scanf("%d%d%d", &s, &t, &c);
        printf("%d %d %d\n", s, t, c);
        REP(i, c)
        {
            scanf("%d%d%d", &a, &b, &w);
            a--;
            b--;
            AdjList[a].push_back(pii(b, w));
            AdjList[b].push_back(pii(a, w));
            AdjMat[a][b] += w;
            AdjMat[b][a] += w;
        }
        printf("Network %d\nThe bandwidth is %lld.", ca, solve());       
    }         
    return 0;
}
