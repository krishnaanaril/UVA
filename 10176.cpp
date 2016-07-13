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
const int M = 131071;

void printBinary(int n)
{
    int t= n;
    stack<int> stk;
    while(t)
    {
        stk.push(t%2);
        t/=2;
    }
    cout<<stk.size()<<endl;
    while(!stk.empty())
    {
        cout<<stk.top();
        stk.pop();
    }
    cout<<endl;
}

int powMod(int x, int n)
{
    if(n==1)
        return x;
    if(n==0)
        return 1;
    if(n&1)
        return (x*(powMod(x, n-1)%M))%M;
    else
    {
        int tmp = powMod(x, n>>1)%M;
        return (tmp*tmp)%M;
    }
}

bool solve(string s)
{
    int sz = s.size();
    //cout<<"sz: "<<sz<<endl;
    ll res = 0;
    for(int j=0, i=0; j<sz; j++, i++)
    {
        /*if(s[j]-'0'==1)
        {
            //cout<<i<<" "<<(s[j]-'0')<<endl;
            res = (res+powMod(2, i))%M;
        }*/
        res = (res*2)%M;
        res = (res+(s[j]-'0'))%M;
    }
    //cout<<s<<endl<<res<<endl;
    return res==0;
}

string s;

bool readString()
{
    char arr[10005], ch;
    int i=0;
    while(cin>>ch)
    {
        if(ch=='#')
            break;
        arr[i++] = ch;
    }
    arr[i] = '\0';
    if(i==0)
        return false;
    string res(arr);
    s = res;
    return true;
}

int main()
{
    FASTIO
    while(readString())
    {
        //cout<<s<<endl;
        if(solve(s))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
