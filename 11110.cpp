/*
	Swamy Saranam

	Date	: 23/07/2016 23:34:35
	Author	: Krishna Mohan A M
	Problem	: 11110 - Equidivisions
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
int dat[205][205], mp[205];
int n, a, b;
string s;

void display()
{
    FOR(i, 1, n+1)
            FOR(j, 1, n+1)
                cout<<dat[i][j]<<sendl[j==n];
    cout<<endl;
}

void dfs(int a, int b)
{
    int c[] = {-1, 1, 0, 0};
    int d[] = {0, 0, -1, 1};
    int tmp = dat[a][b];
    dat[a][b] = -1;
    REP(i, 4)
        if(a+c[i] >= 1 && a+c[i]<=n && b+d[i]>=1 && b+d[0]<=n && dat[a+c[i]][b+d[i]]==tmp)
            ++mp[dat[a+c[i]][b+d[i]]], dfs(a+c[i], b+d[i]);
}

bool solve()
{
    FOR(i, 1, n+1)
        FOR(j, 1, n+1)
            if(dat[i][j] != -1 && !mp[dat[i][j]])
            {
                mp[dat[i][j]] = 1;
                int tmp = dat[i][j];
                dfs(i, j);
                //cout<<tmp<<" "<<mp[tmp]<<" "<<n<<endl;
                if(mp[tmp] != n)
                    return false;
                //display();
            }
            else if(dat[i][j] != -1 && mp[dat[i][j]])
            {
                //cout<<mp[dat[i][j]]<<" -> "<<dat[i][j]<<" "<<i<<" "<<j<<endl;
                return false;
            }
    return true;
}

int main()
{
    FASTIO
    while(cin>>n)
    {
        if(n==0)
            break;
        cin.ignore();
        //cout<<n<<":"<<endl;
        memset(dat, -1, sizeof(dat));
        FOR(i, 1, n+1)
            FOR(j, 1, n+1)
                dat[i][j] = 0;
        memset(mp, 0, sizeof(mp));
        FOR(i, 1, n)
        {
            getline(cin, s);
            //cout<<s<<endl;
            istringstream iss;
            iss.str(s);
            while(iss>>a>>b)
                dat[a][b] = i;  
        }        
        if(solve())
            cout<<"good"<<endl;
        else
            cout<<"wrong"<<endl;
    }
    return 0;
}
