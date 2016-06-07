#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;
typedef pair<double, int> pdi;

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

int n, ans =0;
double w, h, maxVal = 0; 

int main()
{
    FASTIO
    while(cin>>n)
    {
        if(n==0)
            break;
        maxVal = ans = -1;
        REP(i, n)
        {
            cin>>w>>h;
            if(w<h)
                swap(w, h);
            double val =  min(w, h)/2;
            val = max(val, min(w/4.0, h));
            if(val > maxVal)
            {
                maxVal = val;
                ans = i+1;
            }   
        }
        cout<<ans<<endl;
    }
    return 0;
}
