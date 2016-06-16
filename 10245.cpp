    
    #include <bits/stdc++.h>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<double, double>	pdd;
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
#define x               second
#define y               first

const int mod = 1000000007;

int INF = 10000, n;
vector<pdd> dat;
set<pdd> box;
pdd tmp;

bool cmp(const pdd &a, const pdd &b)
{
    return a.x < b.x;
}

int main()
{
    FASTIO
    while(cin>>n)
    {
        if(n==0)
            break;
        dat.clear();
        box.clear();
        REP(i, n)
        {
            cin>>tmp.x>>tmp.y;
            dat.pb(tmp);
        }
        sort(dat.begin(), dat.end(), cmp);
        /*REP(i, n)
            cout<<dat[i].x<<" "<<dat[i].y<<endl; */
        int left = 0;
        double best = INF;
        FOR(i, 1, n)
        {
            while(left<i && dat[i].x - dat[left].x > best) box.erase(dat[left++]);
            for(typeof(box.begin()) it = box.lower_bound(pdd(dat[i].y-best, dat[i].x-best)); it != box.end() && dat[i].y +best >= it->y; it++)
                best = min(best, sqrt(pow(dat[i].y-it->y, 2.0)+pow(dat[i].x-it->x, 2.0)));
            box.insert(dat[i]);
        }
        if(best==INF)
            cout<<"INFINITY"<<endl;
        else
            cout<<setprecision(4)<<fixed<<best<<endl;
    }
    return 0;
}
