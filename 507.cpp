/*
	Swamy Saranam

	Date	: 28/08/2016 21:32:49
	Author	: Krishna Mohan A M
	Problem	: 507 - Jill Rides Again
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
int t, n, ca, tmp;
vi dat;
vector< pair<int, pii> > res;

bool cmp(const pair<int, pii> a, const pair<int, pii> b)
{
  if(a.x == b.x)
    if((a.y.y-a.y.x) == (b.y.y-b.y.x))
      return a.y.x < b.y.x;
    else
      return (a.y.y-a.y.x) > (b.y.y-b.y.x);
  return a.x > b.x;
}

int main()
{
    FASTIO
    cin>>t;
    while(t--)
    {
      dat.clear();
      res.clear();
      ca++;
      cin>>n;
      REP(i, n-1)
      {
        cin>>tmp;
        dat.pb(tmp);
      }
      int ans, curr, begin, start,end;
      ans = curr = 0;
      begin = end = start = 0;
      for(int i=0; i<n-1; i++)
      {
        curr += dat[i];
        if(curr<0)
        {
          curr = 0;
          begin = end = i+1;
        }
        if(curr >= ans)
        {
          ans = curr;
          start = begin;
          end = i;
          res.pb(pair<int, pii>(ans, pii(start, end)));
        }
      }
      sort(res.begin(), res.end(), cmp);
      /*for(auto i : res)
        cout<<i.x<<" "<<i.y.x<<" "<<i.y.y<<endl;*/
      start = res[0].y.x;
      end = res[0].y.y;
      start += 1;
      end += 2;
      if(ans <= 0)
        cout<<"Route "<<ca<<" has no nice parts\n";
      else
        cout<<"The nicest part of route "<<ca<<" is between stops "<<start<<" and "<<end<<endl;
      //cout<<ans<<" "<<begin<<" "<<end<<endl;
    }
    return 0;
}
