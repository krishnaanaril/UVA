/*
	Swamy Saranam

	Date	: 23/07/2016 21:47:44
	Author	: Krishna Mohan A M
	Problem	: 657 - The die is cast
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
int n, m;
bool isVisited[100][100];
char dat[100][100];
vi res;

void printGrid()
{
    REP(i, n)
    {
        REP(j, m)
            cout<<dat[i][j];
        cout<<endl;
    }
}

int subsolve(int a, int b)
{
    dat[a][b] = '*';
    int c[]  = {-1, 1, 0, 0};
    int d[] = {0, 0, -1, 1};
    REP(i, 4)
        if(a+c[i] >= 0 && a+c[i] < n && b+d[i] >= 0 && b+d[i] < m && dat[a+c[i]][b+d[i]]=='X')
        {            
            subsolve(a+c[i], b+d[i]);
        }
}

int solve(int a, int b)
 {    
    int ans = 0;
    isVisited[a][b] = 1;
    int c[]  = {-1, 1, 0, 0};
    int d[] = {0, 0, -1, 1};
    if(dat[a][b]=='X')
    {
        /*ans = 1;
        //currflag = 1;
        REP(i, 4)
        {
            /*if(a+c[i] >= 0 && a+c[i] < n && b+d[i] >= 0 && b+d[i] < m && dat[a+c[i]][b+d[i]]=='X')
                    flag = 1;*/
            /*if(a+c[i] >= 0 && a+c[i] < n && b+d[i] >= 0 && b+d[i] < m && !isVisited[a+c[i]][b+d[i]] && dat[a+c[i]][b+d[i]]=='X')
            {            
                ans = max(ans, solve(a+c[i], b+d[i]));
                //solve(a+c[i], b+d[i]);
                //ans +=1;
            }
        }*/
        //ans += 1;
        subsolve(a, b);
        ans++;
    }    
    /*cout<<a<<" "<<b<<" ->"<<endl;
    printGrid();*/
    REP(i, 4)
    {     
        if(a+c[i] >= 0 && a+c[i] < n && b+d[i] >= 0 && b+d[i] < m && !isVisited[a+c[i]][b+d[i]] && dat[a+c[i]][b+d[i]]!='.')
        {            
            ans += solve(a+c[i], b+d[i]);
        }
    }
    /*cout<<a<<" "<<b<<" -> ";
    cout<<dat[a][b]<<" "<<ans<<" "<<flag<<" "<<currflag<<endl;*/    
    return ans;
}

int main()
{
    FASTIO
    int ca = 0;
    while(cin>>m>>n)
    {        
        if(m+n == 0)
            break;
        res.clear();
        /*if(ca)
            cout<<endl;*/
        ca++;
        cout<<"Throw "<<ca<<endl;
        memset(isVisited, 0, sizeof(isVisited));
        REP(i, n)
            REP(j, m)
                cin>>dat[i][j];
        int cnt = 0;
        REP(i, n)
        {
            REP(j, m)
            {
                //cout<<dat[i][j];
                
                if(dat[i][j] != '.' && !isVisited[i][j])
                {
                    cnt++;
                    int tmp  =  solve(i, j);
                    //cout<<tmp<<endl;
                    res.pb(tmp);
                }                
            }
            //cout<<endl;
        }
        sort(res.begin(), res.end());
        REP(i, res.size())
            cout<<res[i]<<" \n"[i==res.size()-1];
        cout<<endl;
        //cout<<"Count: "<<cnt<<endl;
    }
    return 0;
}
