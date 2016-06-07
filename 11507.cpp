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

const int mod = 1000000007;

int l, dir;
string str;

int main()
{
    FASTIO
    int dir = 0;
    //+x = 0, -x = 1, +y = 2, -y = 3, +z = 4 -z = 5
    while(cin>>l)
    {
        if(l==0)
            break;       
        dir = 0;
        REP(i, l-1)
        {
            cin>>str;
            if(str == "+z")
            {
                if(dir == 0) dir = 4;
                else if(dir == 1) dir = 5;
                else if(dir == 4) dir = 1;
                else if(dir == 5) dir = 0;
            }
            else if(str == "-z")
            {
                if(dir == 0) dir = 5;
                else if(dir == 1) dir = 4;
                else if(dir == 4) dir = 0;
                else if(dir == 5) dir = 1;
            }
            else if(str == "+y")
            {
                if(dir == 0) dir = 2;
                else if(dir == 1) dir = 3;
                else if(dir == 2) dir = 1;
                else if(dir == 3) dir = 0;
                
            }
            else if(str == "-y")
            {
                if(dir == 0) dir = 3;
                else if(dir == 1) dir = 2;
                else if(dir == 2) dir = 0;
                else if(dir == 3) dir = 1;
            }
            //cout<<str<<" "<<dir<<endl;
        }
        
        switch(dir)
        {
            case 0:
                cout<<"+x"<<endl;
                break;
            case 1:
                cout<<"-x"<<endl;
                break;
            case 2:
                cout<<"+y"<<endl;
                break;
            case 3:
                cout<<"-y"<<endl;
                break;
            case 4:
                cout<<"+z"<<endl;
                break;
            case 5:
                cout<<"-z"<<endl;
                break;
        }
    }
    return 0;
}
