/*
	Swamy Saranam

	Date	: 06/08/2016 21:53:01
	Author	: Krishna Mohan A M
	Problem	: 11624 - Fire!
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
int t, n, m, F[1005][1005], J[1005][1005];
vector<string> maze;
string s;

void printJ()
{
    REP(i, n)
        REP(j, m)
            cout<<J[i][j]<<sendl[j==m-1];
}

void printF()
{
    REP(i, n)
        REP(j, m)
            cout<<F[i][j]<<sendl[j==m-1];
}


void bfs(pii joePos)
{
    int X[] = {0, 0, -1, 1};
    int Y[] = {-1, 1, 0, 0};
    queue<pii> fireQ, joeQ;
    REP(i, n)
        REP(j, m)
            if(maze[i][j]=='F')
                fireQ.push(pii(i, j)), F[i][j] =1 ;
    joeQ.push(joePos);
    J[joePos.x][joePos.y] = 1;
    while(!fireQ.empty())
    {
        pii curr = fireQ.front();
        fireQ.pop();
        REP(i, 4)
        {
            int nextx = curr.x+X[i];
            int nexty = curr.y+Y[i];
            if(nextx<0||nextx>=n || nexty<0|| nexty>=m)
                continue;
            if(maze[nextx][nexty]=='#')
                continue;
            if(F[nextx][nexty]==0)
            {
                F[nextx][nexty] = F[curr.x][curr.y] + 1;
                fireQ.push(pii(nextx, nexty));
            }
        }
    }    
    while(!joeQ.empty())
    {
        pii curr = joeQ.front();
        joeQ.pop();
        if(curr.x==0 || curr.y==0 || curr.x==n-1 || curr.y==m-1)
        {
            cout<<J[curr.x][curr.y]<<endl;
            return;
        }
        REP(i, 4)
        {
            int nextx = curr.x + X[i];
            int nexty = curr.y + Y[i];
            if(nextx<0||nextx>=n || nexty<0|| nexty>=m)
                continue;
            if(maze[nextx][nexty]=='#')
                continue;
            if(F[nextx][nexty]!=0 && F[nextx][nexty] <= J[curr.x][curr.y]+1)
                continue;
            if(J[nextx][nexty]==0)
            {
                J[nextx][nexty] = J[curr.x][curr.y] + 1;
                joeQ.push(pii(nextx, nexty));
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return;
}

int main()
{
    FASTIO
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        maze.clear();
        memset(J, 0, sizeof(J));
        memset(F, 0, sizeof(F));
        pii start;
        REP(i, n)
        {
            cin>>s;
            assert(s.size()==m);
            REP(j, m)
                if(s[j]=='J')
                {
                    start.x = i;
                    start.y = j;
                }
            maze.pb(s);
        }
        assert(maze.size()==n);        
        bfs(start);
        /*printJ();
        cout<<endl;
        printF();*/
    }
    return 0;
}
