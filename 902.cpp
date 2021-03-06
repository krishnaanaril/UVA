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

string s, res;
map<string, int> mp;
int maxVal, n, len;

int main()
{
    FASTIO
    while(cin>>n>>s)
    {
        maxVal = 0;
        mp.clear();
        len = s.size();
        //cout<<len<<endl;
        REP(i, len-n+1)
        {
            //cout<<s.substr(i, n)<<endl;
            mp[s.substr(i, n)]++;
        }
        for(typeof(mp.begin()) it=mp.begin(); it!=mp.end(); it++)
        {
            //cout<<it->x<<" "<<it->y<<endl;
            if(it->y > maxVal)
            {
                maxVal=it->y;
                res = it->x;
            }
        }
        //cout<<maxVal<<endl;
        cout<<res<<endl;
    }
    return 0;
}
