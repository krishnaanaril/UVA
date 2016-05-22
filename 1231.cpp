#include <bits/stdc++.h>

using namespace std;

int ca, t, h, f, n, pos;
int dp[2100], acorn[2100][2100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>ca;
    while(ca--)
    {
        memset(acorn, 0, sizeof(acorn));
        memset(dp, 0, sizeof(dp));
        cin>>t>>h>>f;
        for(int i=0; i<t; i++)
        {
            cin>>n;
            for(int j=0; j<n; j++)
            {
                cin>>pos;
                acorn[i][pos]++;
            }
            /*for(int j=0; j<=h; j++)
            {
                cout<<acorn[i][j]<<" ";
            }
            cout<<endl;*/
        }
        for(int i=0; i<=h; i++)
        {
            for(int j=0; j<t; j++)
            {
                dp[i] = max(dp[i], acorn[j][i]);
            }
        }
        for(int height = h-1; height>=0; height--)
        {
            for(int tree=0; tree<t; tree++)
            {
                acorn[tree][height]+= max(acorn[tree][height+1], (height+f)<=h? dp[height+f]: 0);
                dp[height] = max(dp[height], acorn[tree][height]);
            }
        }
        cout<<dp[0]<<endl;
    }
    return 0;
}
