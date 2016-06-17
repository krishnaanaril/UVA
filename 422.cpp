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

vector<string> dat;
string tmp, word;
int n;

bool isNumber(string str)
{
    int ch = str[0]-'0';
    if(ch>=0 && ch<10)
        return true;
    return false;
}

pii solve(pii st, string w)
{
    int wl = w.size();
    int lim = min(n, st.x+wl);
    bool isfound = false;
    pii res = pii(-1, -1);
    //to down
    /*if(st==pii(0, 1))
        cout<<dat[st.x][st.y]<<endl;*/
    for(int i=st.x, k=0; i<lim; i++, k++)
    {
        //cout<<dat[i][st.y]<<" "<<word[i]<<endl;
        if(dat[i][st.y]!=word[k])
            break;
        else if(k==wl-1)
        {
            isfound = true;
            res = pii(i, st.y);
        }
    }
    if(isfound)
        return res;
    //to up
    // not required
    /*
    lim  = max(0, st.x-wl);
    for(int i=st.x, k=0; i>=lim;i--, k++)
        if(dat[i][st.y]!=word[k])
            break;
        else if(k==wl-1)
        {
            isfound = true;
            res = pii(i, st.y);
        }
    if(isfound)
        return res;
    */
    //to right
    lim = min(n, st.y+wl);
    for(int i=st.y, k=0; k<lim; i++, k++)
    {
        //cout<<dat[i][st.y]<<" "<<word[i]<<endl;
        if(dat[st.x][i]!=word[k])
            break;
        else if(k==wl-1)
        {
            isfound = true;
            res = pii(st.x, i);
        }
    }
    if(isfound)
        return res;
    //to left
    lim  = max(0, st.y-wl);
    for(int i=st.y, k=0; i>=lim;i--, k++)
        if(dat[st.x][i]!=word[k])
            break;
        else if(k==wl-1)
        {
            isfound = true;
            res = pii(st.x, i);
        }
    if(isfound)
        return res;
    //right-down diagonal
    int limi = min(n, st.x+wl);
    int limj = min(n, st.y+wl);
    for(int i=st.x, j=st.y, k=0; i<limi && j<limj; i++, j++, k++)
    {
        if(dat[i][j]!=word[k])
            break;
        else if(k==wl-1)
        {
            isfound = true;
            res = pii(i, j);
        }
    }
    if(isfound)
        return res;
    //right-up diagonal
    limi = max(0, st.x-wl);
    limj = min(n, st.y+wl);
    for(int i=st.x, j=st.y, k=0; i>=limi && j<limj; i--, j++, k++)
    {
        if(dat[i][j]!=word[k])
            break;
        else if(k==wl-1)
        {
            isfound = true;
            res = pii(i, j);
        }
    }
    if(isfound)
        return res;
    //left-down diagonal
    limj  = max(0, st.y-wl);
    limi = min(n, st.x+wl);
    for(int i=st.x, j=st.y, k=0; i<limi && j>=limj; i++, j--, k++)
    {
        if(dat[i][j]!=word[k])
            break;
        else if(k==wl-1)
        {
            isfound = true;
            res = pii(i, j);
        }
    }
    if(isfound)
        return res;
    //left-up diagonal
    limi = max(0, st.x-wl);
    limj = max(0, st.y-wl);
    for(int i=st.x, j=st.y, k=0; i>=limi && j>=limj; i--, j--, k++)
    {
        if(dat[i][j]!=word[k])
            break;
        else if(k==wl-1)
        {
            isfound = true;
            res = pii(i, j);
        }
    }
    if(isfound)
        return res;
    return res;
}

int main()
{
    FASTIO
    cin>>n;
    while(true)
    {
        if(n==0)
            break;
        //cout<<n<<endl;
        dat.clear();
        REP(i, n)
        {
            cin>>tmp;
            dat.pb(tmp);
        }
        while(cin>>word)
        {
            //cout<<word<<" "<<isNumber(word)<<endl;
            if(isNumber(word))
            {
                istringstream iss;
                iss.str(word);
                iss>>n;
                break;
            }
            //cout<<word<<" ";
            bool isfound = false;
            pii ress, rese;
            REP(i, n)
            {
                REP(j, n)
                {
                    rese = solve(pii(i, j), word);
                    if(rese.x!=-1)
                    {
                        ress = pii(i, j);
                        isfound = true;
                        break;
                    }
                }
                if(isfound)
                    break;
            }
            if(isfound)
            {
                ress.x++;
                ress.y++;
                rese.x++;
                rese.y++;
                cout<<ress.x<<","<<ress.y<<" "<<rese.x<<","<<rese.y<<endl;
            }
            else
                cout<<"Not found"<<endl;
        }
    }
    return 0;
}
