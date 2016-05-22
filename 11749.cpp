#include <bits/stdc++.h>

#define M 505

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

vpii graph[M];
bitset<M> isVisited;
int n, m, u, v, w, maxw, ans, cnt;


void dfs(int u)
{
    int a, b, p, sz = graph[u].size();
    isVisited[u] = 1;
    for(int i=0; i<sz; i++)
    {
        a = u; b = graph[u][i].first; p = graph[u][i].second;
        if(p==maxw && !isVisited[b])
        {
            cnt++;
            dfs(b);
        }
    }
}

void init()
{
    for(int i=0; i<M; i++)
        graph[i].clear();
}

int main()
{
    ios_base::sync_with_stdio(0);
    while(true)
    {
        init();
        cin>>n>>m;
        if(n==0 && m==0)
            break;
        for(int i=0; i<m; i++)
        {
            cin>>u>>v>>w;
            graph[u].push_back(pii(v, w));
            graph[v].push_back(pii(u, w));
            if(!i)
                maxw = w;
            else
                maxw = max(maxw,w);
        }
        //cout<<maxw<<endl;
        isVisited.reset();
        ans = 0;
        for(int i=1; i<=n; i++)
        {            
            if(!isVisited[i])
            {
                cnt =0;
                dfs(i);
                ans = max(ans, cnt+1);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
