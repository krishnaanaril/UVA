#include <bits/stdc++.h>

#define MAX 7000
#define OFF 3500

using namespace std;

typedef vector<int> vi;

int  num[MAX], sig[MAX], n, sz, tmp;
string str;
bool used[MAX], memo[40][40][MAX], flag;
char ch;
istringstream iss;

void solve(int idx, int open, int val)
{
    if(memo[idx][open][val+OFF])
    {
        return;
    }
    memo[idx][open][val+OFF] =1;
    if(idx==n)
    {
        used[val+OFF] =1;
        return;
    }
    int nval = val + num[idx] * sig[idx] * ((open&1)? -1: 1);
    //cout<<" : "<<idx<<" : "<<open<<" : "<<val<<" : "<<nval<<endl;
    if(sig[idx]==-1)
        solve(idx+1, open+1, nval);
    if(open>0)
        solve(idx+1, open-1, nval);
    solve(idx+1, open, nval);
}

int main()
{
    ios_base::sync_with_stdio(0);
    sig[0] = 1;
    while(getline(cin,str))
    {
        //cout<<str<<endl;
        memset(used, 0, sizeof(used));
        memset(memo, 0, sizeof(memo));
        sz = str.size();        
        iss.clear();
        iss.str(str);
        flag =1;
        n=0;
        int npos=0, spos=1;
        while(!iss.eof())
        {
            //cout<<"In loop"<<endl;
            if(flag)
            {
                iss>>tmp;
                //cout<<tmp;
                num[npos++] = tmp;
                n++;
            }
            else 
            {
                iss>>ch;
                //cout<<ch;
                if(ch=='+' || ch=='-')
                    sig[spos++] = ch=='+'? 1: -1;
            }
            flag = !flag;
        }
        //cout<<endl;
        /*for(int i=0;i<n; i++)
        {
            cout<<num[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n; i++)
        {
            cout<<(sig[i])<<" ";
        }
        cout<<endl;*/
        solve(0, 0, 0);
        int ans = 0;
        for(int i = 0;i<MAX; i++)
            if(used[i])
                ans++;
        cout<<ans<<endl;
    }
    return 0;
}
