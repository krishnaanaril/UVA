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

const int mod = 1000000007;

int dp[101][101], ar[101][101];
string a, b;
int na, nb;

void print(int i, int j)
{
    if(i==0 && j==0)
        return;
    if(ar[i][j]==1)
        print(i-1, j-1);
    else if(ar[i][j]==2)
    {
        print(i-1, j);
        cout<<"D"<<a[i-1]<<setfill('0')<<setw(2)<<j+1;
    }
    else if(ar[i][j]==3)
    {
        print(i, j-1);
        cout<<"I"<<b[j-1]<<setfill('0')<<setw(2)<<j;
    }
    else if(ar[i][j]==4)
    {
        print(i-1, j-1);
        cout<<"C"<<b[j-1]<<setfill('0')<<setw(2)<<j;
    }
}

int main()
{
    FASTIO
    while(cin>>a)
    {
        if(a=="#")
            break;
        cin>>b;
        na = a.size();
        nb = b.size();
        memset(dp, 63, sizeof(dp));
        dp[0][0] = 0;
        REP(i, na+1)
        {
            REP(j, nb+1)
            {
                if(a[i]==b[j] && dp[i+1][j+1] > dp[i][j])
                    dp[i+1][j+1] = dp[i][j], ar[i+1][j+1] = 1; //copy
                if(dp[i+1][j] > dp[i][j]+1)
                    dp[i+1][j] = dp[i][j]+1, ar[i+1][j] = 2; //delete
                if(dp[i][j+1] > dp[i][j]+1)
                    dp[i][j+1] = dp[i][j]+1, ar[i][j+1] = 3;//insert
                if(dp[i+1][j+1] > dp[i][j]+1)
                    dp[i+1][j+1] = dp[i][j]+1, ar[i+1][j+1] = 4;//change
            }
        }
        print(na, nb);
        cout<<"E"<<endl;
    }
    return 0;
}
