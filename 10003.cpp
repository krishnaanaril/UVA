/*
    Accepted
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int l, n, tmp;
vi coord;
int dp[55][55];

int solve(int left, int right)
{
    if(left+1 == right)
        return dp[left][right] = 0;
    if(dp[left][right]!=-1)
        return dp[left][right];
    int cost = INT_MAX;
    for(int i=left+1; i< right; i++)
    {
        cost = min(cost, solve(left, i)+solve(i, right)+(coord[right]-coord[left]));
    }
    //cout<<coord[left]<<" : "<<coord[right]<<" : "<<cost<<endl;  
    return dp[left][right] = cost;
}

int main()
{
    ios_base::sync_with_stdio(0);
    while(true)
    {
        cin>>l;
        if(l==0)
            break;
        cin>>n;
        coord.clear();
        memset(dp, -1, sizeof(dp));
        //cout<<dp[34][34]<<endl;
        coord.push_back(0);
        for(int i=0;i<n;i++)
        {
            cin>>tmp;
            coord.push_back(tmp);
        }
        coord.push_back(l);
        /*for(int i=0;i<coord.size();i++)
        {
            cout<<coord[i]<<" ";
        }
        cout<<endl;*/
        cout<<"The minimum cutting is "<<solve(0, coord.size()-1)<<"."<<endl;
    }
    return 0;
}
