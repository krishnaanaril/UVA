/*
    Building suffix array using hash
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
#define getHash(lo, size)   (h[lo] - h[(lo)+(size)]*hPow[size])

const int mod = 1000000007;
const int MAXN = 1<<21;
string s, ans;
int sa[MAXN], lcp[MAXN], N, t, pos[MAXN];
ll h[MAXN], hPow[MAXN];
ll BASE = 137;
map<string, int> mp;

bool sufCmp(int i, int j)
{
    int lo=1, hi = min(N-i, N-j);
    while(lo<=hi)
    {
        int mid = (lo+hi)>>1;    
        if(getHash(i, mid) == getHash(j, mid))  
            lo = mid+1;
        else
            hi = mid-1;
    }
    return s[i+hi] < s[j+hi];
}

void buildSA()
{
    N = s.size();
    hPow[0] =1;
    FOR(i, 1, N+1)
        hPow[i] = hPow[i-1]*BASE;
    h[N] = 0;
    for(int i=N-1; i>=0; i--)
    {
        h[i] = h[i+1]*BASE + s[i];
        sa[i] = i;
    }
    sort(sa, sa+N, sufCmp);
}

void buildLCP()
{
    REP(i, N)
        pos[sa[i]] = i;
    /*REP(i, N)
        cout<<pos[i]<<" \n"[i==N-1];*/
    for(int i=0, k=0; i<N; i++)
        if(pos[i]!=N-1)
        {
            for(int j = sa[pos[i]+1]; s[j+k]==s[i+k];)
                k++;
            lcp[pos[i]] = k;
            if(k)
                --k;
        }
}

int main()
{
    FASTIO
    cin>>t;
    while(t--)
    {
        memset(sa, 0, sizeof(sa));
        memset(lcp, 0, sizeof(lcp));
        mp.clear();
        cin>>s;
        //cout<<s<<endl;
        buildSA();
        /*REP(i, N)
            cout<<sa[i]<<" \n"[i==N-1];*/
        buildLCP();
        int maxVal =0;
        REP(i, N)
        {
            maxVal = max(lcp[i], maxVal);
            //cout<<lcp[i]<<" \n"[i==N-1];
        }
        if(maxVal ==0)
            cout<<"No repetitions found!"<<endl;
        else
        {
            REP(i, N)
            {
                if(lcp[i]==maxVal)
                    mp[s.substr(sa[i], lcp[i])]++;
            }
            maxVal = 0;
            for(auto i : mp)
            {
                //cout<<i.x<<" "<<i.y<<endl;
                if(i.y > maxVal)
                {
                    maxVal = i.y;
                    ans = i.x;
                }
            }
            ++maxVal;
            cout<<ans<<" "<<maxVal<<endl;
        }    
    }
    return 0;
}
