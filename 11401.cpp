#include <bits/stdc++.h>

#define M 1000005
#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)

using namespace std;

long long dat[M], num;

void init()
{
    long long n;
    FOR(i, 3, M)
    {
        n = (i-3)/2 + 1;
        dat[i] = (i*n) - (n*3 + n*(n-1));
        //cout<<i<<" - "<<dat[i]<<endl;
    }
    FOR(i, 4, M)
    {
        dat[i] += dat[i-1];
    }
}

int main()
{
    init();
    while(true)
    {
        cin>>num;
        if(num<3)
            break;
        cout<<dat[num]<<endl;
    }
    return 0;
}
