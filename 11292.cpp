#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef priority_queue<int, vi, greater<int> >  pqi;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, tmp, ans, a, b;
    pqi d, k;
    while(true)
    {
        ans=0;
        cin>>n>>m;
        if(n==0 && m==0)
            break;
        pqi d, k;
        for(int i=0; i<n; i++)
        {
            cin>>tmp;
            d.push(tmp);
        }
        for(int i=0; i<m; i++)
        {
            cin>>tmp;
            k.push(tmp);
        }
        while(!d.empty() && !k.empty())
        {
            a = d.top();
            b = k.top();
            //cout<<a<<" "<<b<<endl;
            if(a<=b)
            {
                d.pop();
                ans+=b;
            }
            k.pop();
        }
        if(d.empty())
        {
            cout<<ans<<endl;
        }
        else if(k.empty())
        {
            cout<<"Loowater is doomed!"<<endl;
        }
    }
    return 0;
}
