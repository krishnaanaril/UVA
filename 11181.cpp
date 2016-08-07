/*
	Swamy Saranam

	Date	: 24/07/2016 18:55:02
	Author	: Krishna Mohan A M
	Problem	: 11181 - Probability|Given
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
double res[25], prob[25];
int n, r;


int main()
{
    FASTIO
    int ca = 0;
    while(cin>>n>>r)
    {        
        //cout<<n<<" "<<r<<endl;
        if((n+r)==0)
            break;
        ca++;
        cout<<"Case "<<ca<<":"<<endl;
        int lim  = 1<<n;
        double sum = 0;
        //cout<<lim<<endl;
        REP(i, n)
        {
            cin>>prob[i];
            res[i] = 0;
        }
        REP(i, lim)
        {
            if(__builtin_popcount(i)==r)
            {
                double p =1;
                REP(j, n)
                {
                    if(i&(1<<j))
                    {
                        p *= prob[j];
                    }
                    else
                    {
                        p *= (1 - prob[j]);
                    }
                }
                //cout<<i<<" - "<<p<<endl;
                REP(j, n)
                    if(i&(1<<j))
                        res[j] += p;
                sum += p;
            }
        }
        //cout<<sum<<endl;
        REP(i, n)
            cout<<fixed<<setprecision(6)<<(res[i]/sum)<<endl;
    }
    return 0;
}
