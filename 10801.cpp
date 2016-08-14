/*
	Swamy Saranam

	Date	: 13/08/2016 15:26:08
	Author	: Krishna Mohan A M
	Problem	: 10801 - Lift Hopping
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
const int inf = 0xffffff;

struct LiftInfo
{
  int time;
  bitset<105> floors;
} l[15];

struct FloorInfo
{
  int floorNum;
  int cost;
  int liftNum;
} tmp, p;

bool operator < (FloorInfo a, FloorInfo b)
{
    return a.cost > b.cost;
}

int n, k, dat[15][105], t;
string s;
istringstream iss;
priority_queue <FloorInfo> pq;

int main()
{
    FASTIO
    while(cin>>n>>k)
    {
      REP(i, n)
      {
        cin>>l[i].time;
        l[i].floors.reset();
      }
      //cout<<"N, K: "<<n<<" "<<k<<endl;
      cin.ignore();
      REP(i, n)
      {
        getline(cin, s);
        //cout<<s<<endl;
        iss.clear();
        iss.str(s);
        while(iss>>t)
        {
          l[i].floors[t] =1;
        }
      }
      REP(i, 15)
        REP(j, 105)
          dat[i][j] = inf;
      /*REP(i, n)
      {
        cout<<"Lift "<<i<<endl;
        REP(j, 105)
          if(l[i].floors[j])
              cout<<j<<" ";
        cout<<endl;
      }*/
      REP(i, n)
      {
        if(l[i].floors[0])
        {
          tmp.floorNum = 0;
          tmp.cost = 0;
          tmp.liftNum = i;
          pq.push(tmp);
          dat[i][0] = 0;
        }
      }
      while(!pq.empty())
      {
        p = pq.top();
        pq.pop();
        // To check lowest time inside a lift
        if(p.cost > dat[p.liftNum][p.floorNum])
            continue;
        REP(i, 105)
        {
          tmp.cost = p.cost + l[p.liftNum].time * abs(p.floorNum - i);
          if(l[p.liftNum].floors[i] && dat[p.liftNum][i] > tmp.cost)
          {
            tmp.floorNum = i;
            tmp.liftNum = p.liftNum;
            pq.push(tmp);
            dat[p.liftNum][i] = tmp.cost;
          }
        }
        //To check lowest time between lifts.
        REP(i, n)
        {
          if(l[i].floors[p.floorNum])
          {
            tmp.floorNum = p.floorNum;
            tmp.cost = p.cost+60;
            tmp.liftNum = i;
            if(tmp.cost < dat[i][p.floorNum])
            {
              dat[i][p.floorNum] = tmp.cost;
              pq.push(tmp);
            }
          }
        }
      }
      int ans = inf;
      REP(i, n)
      {
          ans = min(ans, dat[i][k]);
      }
      if(ans == inf)
        cout<<"IMPOSSIBLE"<<endl;
      else
        cout<<ans<<endl;
    }
    return 0;
}
