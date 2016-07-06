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

const int mod = 1000000007;
const int MAXN = 1<<21;
int N, gap, t;
int sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN];
string s, ans;
map<string, int> mp;

bool sufCmp(int i, int j)
{
	if (pos[i] != pos[j])
		return pos[i] < pos[j];
	i += gap;
	j += gap;
	return (i < N && j < N) ? pos[i] < pos[j] : i > j;
}

void buildSA()
{
	N = s.size();//strlen(S);
	REP(i, N) sa[i] = i, pos[i] = s[i];
	for (gap = 1;; gap *= 2)
	{
		sort(sa, sa + N, sufCmp);
		REP(i, N - 1) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
		REP(i, N) pos[sa[i]] = tmp[i];
		if (tmp[N - 1] == N - 1) break;
	}
}

void buildLCP()
{
	for (int i = 0, k = 0; i < N; ++i) if (pos[i] != N - 1)
	{
		for (int j = sa[pos[i] + 1]; s[i + k] == s[j + k];)
		++k;
		lcp[pos[i]] = k;
		if (k)--k;
	}
}

/*
bool sufCmp(int i, int  j)
{
    if(pos[i]!=pos[j])
        return pos[i] < pos[j];
    i+=gap;
    j+=gap;
    return (i<N && j<N)? pos[i] < pos[j] : i>j;
}

void buildSA()
{
    N = s.size();
    REP(i, N)
    {
        sa[i] = i;
        pos[i] = s[i];
    }
    for(gap =1;; gap*=2)
    {
        sort(sa, sa+N, sufCmp);
        REP(i, N-1)
            tmp[i+1] = tmp[i]+sufCmp(sa[i], sa[i+1]);
        REP(i, N)
            pos[sa[i]] = tmp[i];
        if(tmp[N-1]==N-1)
            break;
    }
}

void buildLCP()
{
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
*/
int main()
{
    FASTIO
    cin>>t;
    while(t--)
    {
        memset(sa, 0, sizeof(sa));
        memset(pos, 0, sizeof(pos));
        memset(tmp, 0, sizeof(tmp));
        memset(lcp, 0, sizeof(lcp));
        mp.clear();
        cin>>s;
        //cout<<s<<endl;
        buildSA();
        //cout<<N<<endl;
        REP(i, N)
            cout<<pos[i]<<" \n"[i==N-1];
        REP(i, N)
            cout<<sa[i]<<" \n"[i==N-1];
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
