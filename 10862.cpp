/*
	Swamy Saranam

	Date	: 13/07/2016 22:26:33
	Author	: Krishna Mohan A M
	Problem	: 10862
	Status	: Accepted
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
int dat[4005][1005];

void add(int k, int i, int j)
{
    int carry = 0, l;
    for(l=0; l<1002; l++)
    {
        dat[k][l] = dat[i][l]+dat[j][l] +carry;
        carry = dat[k][l]/10;
        dat[k][l] %= 10;
    }
    if(carry)
        dat[k][l] = carry;
}

void init()
{
    dat[1][0] = 1;
    dat[2][0] = 2;
    for(int i=3; i<4002; i++)
        add(i, i-1, i-2);
}

int main()
{
    FASTIO
    int n, pos;
    init();
    while(cin>>n)
    {
        if(n==0)
            break;
        pos = 2*n-1;
        int i = 0;
        for(i=1002; i>0; i--)
            if(dat[pos][i])
                break;
        for(;i>=0; i--)
            cout<<dat[pos][i];
        cout<<endl;
    }
    return 0;
}
