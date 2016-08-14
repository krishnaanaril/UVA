/*
	Swamy Saranam

	Date	: 14/08/2016 09:32:55
	Author	: Krishna Mohan A M
	Problem	: 514 - Rails
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
int n, tmp;
vi dat;
stack<int> stk;

int main()
{
    FASTIO
    bool first = true;
    while(cin>>n)
    {
      if(n==0)
        break;
      first = false;
      bool isEnd = false;
      while(!isEnd)
      {
        while(!stk.empty())
            stk.pop();
        dat.clear();
        REP(i, n)
        {
          cin>>tmp;
          if(tmp==0)
          {
            isEnd = true;
            break;
          }
          dat.pb(tmp);
        }
        if(!isEnd)
        {
          int j = 0;
          FOR(i, 1, n+1)
          {
            stk.push(i);
            while(!stk.empty() && stk.top()==dat[j])
            {
              stk.pop();
              j++;
            }
          }
          //cout<<j<<" "<<stk.size()<<endl;
          if(!stk.empty())
            cout<<"No"<<endl;
          else
            cout<<"Yes"<<endl;
        }
      }
      cout<<endl;
    }
    return 0;
}
