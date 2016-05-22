#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

using namespace std;

typedef long long ll;

ll x, y, d, a, b, xa, ya;

void extendedEuclid(ll a, ll b)
{
    if(b==0)
    {
        x = 1;
        y = 0;
        d = a;
        return;
    }
    extendedEuclid(b, a%b);
    xa = y;
    ya = x - (a/b)*y;
    x = xa;
    y = ya;
}

int main()
{
    FASTIO
    while(cin>>a>>b)
    {
        extendedEuclid(a, b);
        cout<<xa<<" "<<ya<<" "<<d<<endl;
    }
    return 0;
}
