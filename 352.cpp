#include <bits/stdc++.h>

using namespace std;

#define M 50

int n, ans;
string str;
int dat[M][M];
bool isVisited[M][M];

void dfs(int i, int j)
{
    if((i>=n || i<0) || (j>=n || j<0 ))
        return;
    isVisited[i][j] = 1;
    if(i-1>=0 && !isVisited[i-1][j] && dat[i-1][j]==1)
        dfs(i-1, j); 
    if(j-1>=0 && !isVisited[i][j-1] && dat[i][j-1]==1)
        dfs(i, j-1);
    if(i-1>=0 && j-1>=0 && !isVisited[i-1][j-1] && dat[i-1][j-1]==1)
        dfs(i-1, j-1);
    if(i+1<n && !isVisited[i+1][j] && dat[i+1][j]==1)
        dfs(i+1, j); 
    if(j+1<n && !isVisited[i][j+1] && dat[i][j+1]==1) 
        dfs(i, j+1);
    if(i+1<n && j+1<n && !isVisited[i+1][j+1] && dat[i+1][j+1]==1)
        dfs(i+1, j+1);
    if(i-1>=0 && j+1<n && !isVisited[i-1][j+1] && dat[i-1][j+1]==1)
        dfs(i-1, j+1);
    if(i+1<n && j-1>=0 && !isVisited[i+1][j-1] && dat[i+1][j-1]==1)
        dfs(i+1, j-1);
    return;
}

int main()
{
    ios_base::sync_with_stdio();
    int ca=0;
    while(cin>>n)
    {
        ca++;
        //cout<<n<<endl;
        memset(isVisited, 0, sizeof(isVisited));
        for(int i=0; i<n; i++)
        {
            cin>>str;
            for(int j=0; j<n; j++)
            {
                dat[i][j] = str[j]=='1'? 1: 0;
            }
        }
        ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(!isVisited[i][j] && dat[i][j]==1)
                {
                    //cout<<i<<" : "<<j<<endl;
                    dfs(i, j);
                    ans++;
                }
            }
        }
        cout<<"Image number "<<ca<<" contains "<<ans<<" war eagles."<<endl;
        //cout<<ans<<endl;
    }
    return 0;
}
