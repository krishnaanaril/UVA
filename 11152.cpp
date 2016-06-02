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
#define pi              acos(-1)
#define prs(a)          fixed<<setprecision((a))

const int mod = 1000000007;

int a, b, c;

double heron(int a, int b, int c)
{
    double s = (a+b+c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main()
{
    FASTIO
    while(cin>>a>>b>>c)
    {
        double s = (a+b+c)/2.0;
        double tArea = sqrt(s*(s-a)*(s-b)*(s-c));
        double inR = tArea/s;
        double inArea = pi*inR*inR;
        double outR = (a*b*c)/4.0/tArea;
        double outArea = pi*outR*outR;
        double roses = inArea;
        double violets = tArea - inArea;
        double sunflowers = outArea - tArea;
        //cout<<inR<<" - "<<outR<<endl;
        cout<<prs(4)<<sunflowers<<" "<<violets<<" "<<roses<<endl;
    }
    return 0;
}
