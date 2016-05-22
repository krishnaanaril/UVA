#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll t, n, ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans = ((((n*567/9)+7492)*235/47)-498);
        //cout<<ans<<endl;
        ans=(ans%100)/10;
        cout<<abs(ans)<<endl;
    }    
    return 0;
}
