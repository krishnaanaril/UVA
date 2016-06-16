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

const int mod = 1000000007;

typedef struct circle
{
    double x, y, r;
}circle;
vector<circle> dat;
circle tmp;
int dp[1000][1000], n;
bitset<1000> isVisited;

double dist(circle a, circle b)
{
    double px = a.x - b.x;
    double py = a.y - b.y;
    return hypot(px, py);
}


int main()
{
    FASTIO
    while(cin>>n)
    {
        if(n==-1)
            break;
        dat.clear();
        memset(dp, 0, sizeof(dp));
        isVisited.reset();
        REP(i, n)
        {
            cin>>tmp.x>>tmp.y>>tmp.r;
            dat.pb(tmp);
        }
        REP(i, n)
        {
            REP(j, n)
            {
                if(i==j)
                    continue;
                double tmpDist = dist(dat[i], dat[j]);
                if(tmpDist < (dat[i].r+dat[j].r) && tmpDist > fabs(dat[i].r - dat[j].r))
                    dp[i][j] = 1;
            }
        }
        /*REP(i, n)
        {
            REP(j, n)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }*/
        int ans = 0;
        REP(i, n)
        {
            if(!isVisited[i])
            {
                isVisited[i] = 1;
                int cnt = 1;
                queue<int> q;
                q.push(i);
                while(!q.empty())
                {
                    int curr = q.front();
                    q.pop();                    
                    REP(j, n)
                    {
                        if(dp[curr][j] && !isVisited[j])
                        {
                            cnt++;
                            isVisited[j] = 1;
                            q.push(j);
                        }
                    }
                }
                ans = max(ans, cnt);
            }
        }
        if(ans==1)
            cout<<"The largest component contains 1 ring."<<endl;
        else
            cout<<"The largest component contains "<<ans<<" rings."<<endl;
    }
    return 0;
}
