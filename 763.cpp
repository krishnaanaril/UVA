/*
	Swamy Saranam

	Date	: 13/07/2016 21:23:58
	Author	: Krishna Mohan A M
	Problem	: 763 - Fibinary Numbers
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
const int M = 150;
string a, b;
int sza, szb, sz, ans[M];

int main()
{
    FASTIO
    bool first = true;
    while(cin>>a>>b)
    {
        memset(ans, 0, sizeof(ans));
        if(!first)
            cout<<endl;
        else
            first = false;
        sza = a.size();
        szb = b.size();
        for(int i=0, j=sza-1; j>=0; j--, i++)
            ans[i] += a[j]-'0';
        for(int i=0, j=szb-1; j>=0; j--, i++)
            ans[i] += b[j]-'0';
        int i=0;
        sz = max(sza, szb);
        /*cout<<sz<<endl;
        REP(i, sz)
            cout<<ans[i];
        cout<<endl;*/
        for(;;)
        {
            for(i=0; i<110; i++)
            {
                if(ans[i] && ans[i+1]) //handles the case of two consecutive ones
                {                   
                    --ans[i];
                    --ans[i+1];
                    ++ans[i+2]; // 11 -> 100
                    break;
                   
                }
                else if(ans[i]>1) //if sum is greater than one
                {
                    ans[i] -= 2;
                    if(i==0)
                        ++ans[i+1];
                    else if(i==1)
                    {
                        ++ans[i+1];
                        ++ans[i-1];
                    }              
                    else
                    {
                        ++ans[i+1];
                        ++ans[i-2];
                    }     
                    break;     
                }
            }
            if(i==110)
                break;
        }
        for(i=110; i>0; i--)
            if(ans[i])
                break;
        for(int j=i; j>=0; j--)
            cout<<ans[j];
        cout<<endl;
    }
    return 0;
}
