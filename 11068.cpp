#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

using namespace std;

double a1, a2, b1, b2, c1, c2, m1, m2, d1, d2, x, y;

int  main()
{
    FASTIO
    while(cin>>a1>>b1>>c1>>a2>>b2>>c2)
    {
        if((a1 + b1 + c1 + a2 + b2 + c2) == 0)
            break;
        m1 = -1*a1/b1;
        m2 = -1*a2/b2;
        d1 = -1*c1/b1;
        d2 = -1*c2/b2;
        if(m1 == m2)
        {
            cout<<"No fixed point exists."<<endl;
        }
        else
        {
            x = (d1 - d2)/(m2 - m1);
            y = m1 * x + d1;
            x = x !=0 ? x*-1 : x;
            y = y !=0 ? y*-1 : y;
            //double y2 = m2 * x + d2;
            cout<<"The fixed point is at "<<setprecision(2)<<fixed<<x<<" "<<y<<"."<<endl;
            //cout<<"y2: "<<y2<<endl;
        }
    }
    return 0;
}
