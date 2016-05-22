#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

const int mod = 1000000007;

int n, num1[10], num2[10], ans[10], carry, cnt1, cnt2;
char op[5], ch;
string cnum1, cnum2, cans;

void add()
{
    carry = 0;
    int lim = max(cnt1, cnt2);
    REP()    
}

void init()
{
    CL(num1, 0);
    CL(num2, 0);
    CL(ans, 0);
    REP(i, cnt1)
    {
        num1[i] = cnum1[cnt1-i-1] == 'V'? 0 : cnum1[cnt1-i-1] == 'U' ? 1: cnum1[cnt1-i-1] == 'C' ? 2 : cnum1[cnt1-i-1] == 'D' ? 3: -1;
    }
    REP(i, cnt2)
    {
        num2[i] = cnum2[cnt2-i-1] == 'V'? 0 : cnum2[cnt2-i-1] == 'U' ? 1: cnum2[cnt2-i-1] == 'C' ? 2 : cnum2[cnt2-i-1] == 'D' ? 3: -1;
    }
}

int main()
{
    cin>>n;
    cout<<"COWCULATIONS OUTPUT\n";
    while(n--)
    {
        
        cin>>cnum1>>cnum2;
        cnt1 = cnum1.size();                
        cnt2 = cnum2.size();        
        REP(i, 3)
            cin>>op[i]; 
        REP(i, 3)
            cout<<op[i]<<endl;                  
        cin>>cans;
    }
    cout<<"END OF OUTPUT\n";
    return 0;
}
