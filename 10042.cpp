/*
	Swamy Saranam

	Date	: 17/07/2016 12:16:00
	Author	: Krishna Mohan A M
	Problem	: 10042 - Smith Numbers
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
ll n;
int t;

ll getDigitSum(ll num)
{
    ll sum=0;
    while(num)
    {
        sum += num%10;
        num/=10;
    }
    return sum;
}

bool solve(ll num)
{
    ll tmp = num;
    ll ans = 0;
    int cnt = 0;
    if(tmp%2==0)
    {
        //cout<<2<<" "; 
        while(tmp%2==0)
        {    
            tmp/=2;
            ans += getDigitSum(2);
            cnt++;
        }
    }
    //cout<<tmp<<" "<<cnt<<endl;   
    for(int i=2; i*i<=tmp; i++)
    {
        if(tmp%i==0)
        {
            //cout<<i<<" ";
            while(tmp%i==0)
            {
                tmp/=i;
                ans += getDigitSum(i);
                cnt++;
            }
        }
    } 
    if(tmp!=1)
        ans += getDigitSum(tmp), cnt++;
    
    if(tmp==num || cnt ==1 )
        return false;
    //cout<<ans<<" "<<getDigitSum(num)<<endl;
    return ans == getDigitSum(num);
}

int main()
{
    FASTIO
    cin>>t;
    while(t--)
    {
        cin>>n;
        n++;
        while(true)
        {
            //cout<<n<<": ";
            if(solve(n))
            {
                cout<<n<<endl;
                break;
            }
            n++;
        }
    }
    //cout<<solve(7777786)<<endl;
    return 0;
}
