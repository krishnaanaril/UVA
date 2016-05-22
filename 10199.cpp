#include <bits/stdc++.h>

#define M 105

using namespace std;

typedef pair<int,  int> pii;
typedef vector<pii> vpii;
typedef map<string, int> msi;

int n, m, dfs_num[M], dfs_low[M], dfs_parent[M], dfsNumberCount;
int dfsRoot, rootChildren;
msi mp;
string str, tmp, rmp[M];
vpii graph[M];
bitset<M> points;

void dfs(int u)
{
    dfs_low[u] = dfs_num[u]  = dfsNumberCount++;
    int v, sz = graph[u].size();
    for(int i=0; i<sz; i++)
    {   
        v = graph[u][i].first;        
        if(dfs_num[v]==0)
        {
            dfs_parent[v] = u;
            if(u==dfsRoot)
                rootChildren++;
            dfs(v);
            if(dfs_low[v] >= dfs_num[u])
                points[u] = true;
            dfs_low[u] = min(dfs_low[u], dfs_low[v]); 
        }
        else if(dfs_parent[u] != v)
            dfs_low[u] = min(dfs_low[u], dfs_num[v]); 
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
        cin>>n;
        if(!n)
            break;
        init();
        memset(dfs_num, 0, sizeof(dfs_num));
        /*memset(dfs_low, 0, sizeof(dfs_low));*/
        memset(dfs_parent, 0, sizeof(dfs_parent));
        points.reset();
        for(int i=0; i<n; i++)
        {
            cin>>str;
            mp[str] = i+1;    
            rmp[i+1] = str;
        }
        cin>>m;
        for(int i=0; i<m; i++)
        {
            cin>>str>>tmp;
            cout<<str<<" "<<mp[str]<<" "<<tmp<<" "<<mp[tmp]<<endl;
            graph[mp[str]].push_back(pii(mp[tmp], 0));
        }
        dfsNumberCount=0;
        for(int i=1; i<=n; i++)
        {
            if(dfs_num[i]==0)
            {
                dfsRoot = i;
                rootChildren = 0;
                dfs(i);
                points[i] = (rootChildren>1);
            }
        }
        for(int i=1; i<=n; i++)
            if(points[i])
                cout<<rmp[i]<<" ";
        cout<<endl;
    }
    return 0;
}
