/*
	Swamy Saranam

	Date	: 31/07/2016 22:51:23
	Author	: Krishna Mohan A M
	Problem	: 10731 - Test   
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
const int M = 105;
int n, start[M], low[M], timer;
set<int> inStack;
stack<int> scc;
char arr[5];
map<int, vi> graph;
vector< vector<char> > res;

void dfs(int node)
{
    start[node] = low[node] = ++timer;
    scc.push(node); 
    inStack.insert(node);
    for(auto i : graph[node])
    {
        if(start[i] == 0)
            dfs(i);
        if(inStack.find(i) != inStack.end())
            low[node] = min(low[node], low[i]);
    }
    if(start[node] == low[node])
    {
        vector<char> ans;
        while(!scc.empty() && scc.top() != node)
        {
            //cout<<(char)(scc.top()+'A')<<" ";
            ans.pb((char)(scc.top()+'A'));
            inStack.erase(scc.top());
            scc.pop();
        }
        //cout<<(char)(scc.top()+'A')<<endl;
        ans.pb((char)(scc.top()+'A'));
        inStack.erase(scc.top());
        scc.pop();
        sort(ans.begin(), ans.end());
        /*REP(k, ans.size())
            cout<<ans[k]<<sendl[k==(ans.size()-1)];*/
        res.pb(ans);
    }
}

int main()
{
    FASTIO
    bool first = true;
    while(cin>>n)
    {
        if(n==0)
            break;
        if(!first)
            cout<<endl;
        first = false;
        memset(start, 0, sizeof(start));
        inStack.clear();
        graph.clear();
        timer = 0;
        res.clear();
        while(!scc.empty())
            scc.pop();        
        REP(j, n)
        {
            REP(i, 6)
            {
                cin>>arr[i];
            }
            REP(i, 5)
            {
                if(arr[i] != arr[5])
                    graph[arr[5]-'A'].pb(arr[i]-'A');
            }
        }
        /*for(auto i : graph)
            cout<<i.x<<" "<<i.y.size()<<endl;*/
        for(auto i : graph)
        {
            if(start[i.x] == 0)
                dfs(i.x);
        }
        sort(res.begin(), res.end());
        for(auto i : res)
        {
            int sz = i.size();
            REP(j, sz)
                cout<<i[j]<<sendl[j==sz-1];
            //cout<<endl;
        }
        //cout<<endl;
    }
    return 0;
}
