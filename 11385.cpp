#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;
typedef pair<int, char> pic;

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

int n;
map<ll, int> fib;
vector<int> f;
vector<pic> dat;
pic tmp;
string s;
char ch;

void init()
{
    fib[1] = 1;
    fib[2] = 2;
    f.pb(1);
    f.pb(2);
    int i=3;
    ll a = 1, b = 2, c;
    do
    {
        c = a+b;
        //cout<<c<<endl;
        f.pb(c);
        fib[c] = i++;
        a = b;
        b = c;
    }while(c<((ll)1<<31));
}

int main()
{
    FASTIO
    init();
    int t;
    cin>>t;
    while(t--)
    {        
        cin>>n;
        dat.clear();
        REP(i, n)
        {
            cin>>tmp.x;
            dat.pb(tmp);
        }
        cin.ignore();
        getline(cin, s);
        /*cout<<n<<" "<<dat.size()<<" ";
        cout<<s<<endl;*/
        int j=0;
        REP(i, s.size())
        {
            if(s[i]>='A' && s[i]<='Z' && j<dat.size())
                dat[j++].y = s[i];
        }
        sort(dat.begin(), dat.end());
        j=0;
        //cout<<f[0]<<" "<<dat[0].x<<endl;
        REP(i, dat.size())
        {
            while(f[j]!=dat[i].x)
            {
                cout<<" ";
                j++;
            }            
            cout<<dat[i].y;
            j++;
        }
        cout<<endl;
    }
    return 0;
}
