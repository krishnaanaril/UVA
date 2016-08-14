/*
	Swamy Saranam

	Date	: 14/08/2016 11:20:22
	Author	: Krishna Mohan A M
	Problem	: 291 - The House Of Santa Claus
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
int dat[6][6], ans[100], pos, cnt;
vi graph[6];
vector<string> res;

void init()
{
  memset(dat, 0, sizeof(dat));
  graph[1] = {5, 2, 3};
  graph[2] = {1, 5, 3};
  graph[3] = {1, 4, 5, 2};
  graph[5] = {1, 4, 3, 2};
  graph[4] = {3, 5};
}

bool isAns()
{
  /*cout<<"Cond: ";
  cout<<dat[1][2]<<" "<<
    dat[3][2] <<" "<<
    dat[3][4] <<" "<<
    dat[4][5] <<" "<<
    dat[1][5] <<" "<<
    dat[3][5] <<" "<<
    dat[2][5] <<" "<<
    dat[1][3]<<endl;*/
  if(dat[1][2] &&
    dat[3][2] &&
    dat[3][4] &&
    dat[4][5] &&
    dat[1][5] &&
    dat[3][5] &&
    dat[2][5] &&
    dat[1][3] )
    return true;
  return false;
}

void solve(int node)
{
  //cout<<node<<" "<<pos<<endl;
  ans[pos++] = node;
  if(isAns())
  {
    //cout<<"Found: ";
    string a = "";
    REP(i, pos)
      a += to_string(ans[i]);
    res.pb(a);
    pos--;
    return;
  }
  for(auto i: graph[node]){
    if(dat[node][i]==0){
      dat[node][i] = dat[i][node] = 1;
      solve(i);
      dat[node][i] = dat[i][node] = 0;
    }
  }
  pos--;
  return;
}

int main()
{
    FASTIO
    init();
    solve(1);
    sort(res.begin(), res.end());
    for(auto i : res)
      cout<<i<<endl;
    return 0;
}
