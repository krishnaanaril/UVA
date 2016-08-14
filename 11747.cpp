/*
	Swamy Saranam

	Date	: 08/08/2016 22:39:38
	Author	: Krishna Mohan A M
	Problem	: 11747 - Heavy Cycle Edges
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
typedef pair<int, int> pii;
typedef pair<int, pii> ppii;

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
vi ans;
int n, m, a, b, w, pset[1005];
priority_queue<ppii, vector<ppii>, greater<ppii> > pq;

int findSet(int i)
{
    return pset[i]==i? i: pset[i] = findSet(pset[i]);
}

void unionSet(int i, int j)
{
    pset[findSet(i)] = findSet(j);
}

bool isSameSet(int i, int j)
{
    return findSet(i)== findSet(j);
}

int main()
{
    FASTIO
    while(cin>>n>>m)
    {
        if((n+m)==0)
            break;
        ans.clear();
        REP(i, m)
        {
            cin>>a>>b>>w;
            pq.push(ppii(w, pii(a, b)));
        }
        REP(i, n)
            pset[i] = i;
        while(!pq.empty())
        {
            ppii curr = pq.top();
            pq.pop();
            if(!isSameSet(curr.y.x, curr.y.y))
            {
                unionSet(curr.y.x, curr.y.y);
            }
            else 
                ans.pb(curr.x);
        }
        if(ans.size()>0)
        {
            REP(i, ans.size())
                cout<<ans[i]<<sendl[i==(ans.size()-1)];
        }
        else
            cout<<"forest"<<endl;
    }
    return 0;
}
