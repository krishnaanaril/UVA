/*
	Swamy Saranam

	Date	: 23/07/2016 19:42:19
	Author	: Krishna Mohan A M
	Problem	: 469 - Wetlands of Florida
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
int t, a, b, n, m;
string s;
int dat[205][205], ans[205][205];
bool isVisited[205][205];

int getValue(int a, int b)
{    
    isVisited[a][b] = 1;
    int ans = 1;
    int c[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    int d[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    //cout<<a<<" - "<<b<<" - "<<dat[a][b]<<endl;
    REP(i, 9)
    {
        if(a+c[i]>0 && a+c[i]<=(n) && b+d[i]>0 && b+d[i]<=(m)  && !isVisited[a+c[i]][b+d[i]] && dat[a+c[i]][b+d[i]])
            ans += getValue(a+c[i], b+d[i]);
    }
    return ans;
}

void setValue(int a, int b, int val)
{

}


int main()
{
    FASTIO
    cin>>t;
    cin.ignore();
    getline(cin, s);
    bool f =0;
    while(t--)
    {        
        if(f)
            cout<<endl;
        f  = 1;
        memset(dat, 0, sizeof(dat));
        memset(ans, 0, sizeof(ans));
        int i=1, sz = 0;
        while(getline(cin, s))
        {
            //cout<<(int)s[0]<<" "<<(int)'L'<<endl;
            if(s[0] != 'L' && s[0] != 'W')
            {                
                break;
            }
            sz = s.size();
            FOR(j, 1, sz+1)
                if(s[j-1]=='W')
                    dat[i][j] = 1;
            //cout<<s<<endl;
            i++;
        }
        n = i, m = sz+1;
        //cout<<n<<" "<<m<<endl;
        /*FOR(j, 1, i)
        {
            FOR(k, 1, sz+1)
                cout<<dat[j][k];
            cout<<endl;
        }*/
        //cout<<endl;
        do
        {            
            //cout<<ans[a][b]<<endl;
            istringstream iss;
            iss.str(s);
            iss>>a>>b;
            //cout<<a<<" "<<b<<endl;
            memset(isVisited, 0, sizeof(isVisited));
            cout<<getValue(a, b)<<endl;
            getline(cin, s);
            //cout<<"Dig: "<<s<<endl;
        }while(s!="");
    }
    return 0;
}
