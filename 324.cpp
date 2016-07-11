#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<double, double>	pdd;
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
#define EPS             1e-6
#define	endl			"\n"
#define	sendl			" \n"

const int mod = 1000000007;
int fact[500][2000];
int n;

void init()
{
	fact[0][0] = 1;
	int len = 1;
	for(int i=1; i<400; i++)
	{		
		int carry=0;
		for(int j=0; j<len; j++)
		{
			fact[i][j] = fact[i-1][j]*i+carry;
			carry = fact[i][j]/10;
			fact[i][j]%=10;
		}	
		while(carry)
		{		    
			fact[i][len++] = carry;
			carry = fact[i][len-1]/10;
			fact[i][len-1]%=10;
		}
	}
}

int main()
{
    FASTIO  
    init();
    /*REP(i, 20)
    {
        cout<<i<<" - ";   
    	REP(j, 20)
    		cout<<fact[i][j]<<sendl[j==19];
	}*/
	while(cin>>n)
	{
	    if(n==0)
	        break;
        /*REP(j, 20)
    		cout<<fact[n][j]<<sendl[j==19];*/
        int dat[10], j=1999;
        memset(dat, 0, sizeof(dat));
        while(fact[n][j]==0)
            j--;
        for(;j>=0;j--)
            dat[fact[n][j]]++;
        cout<<n<<"! --"<<endl;
        REP(i, 5)
        {
            cout<<"   ("<<i<<")"<<setw(5)<<dat[i];
            if(i<4)
                cout<<" ";
        }
        cout<<endl;
        FOR(i, 5, 10)
        {
            cout<<"   ("<<i<<")"<<setw(5)<<dat[i];
            if(i<9)
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
