#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef pair<double, double> pdd;

double dist(pdd a, pdd b)
{
    double px = a.x - b.x;
    double py = a.y - b.y;
    return hypot(px, py);
}

pdd a, b, c;

int main()
{
    while(cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y)
    {
        double d = 2*(a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y));
        double axy = a.x*a.x + a.y*a.y;
        double bxy = b.x*b.x + b.y*b.y;
        double cxy = c.x*c.x + c.y*c.y;
        pdd u;
        u.x = (axy*(b.y - c.y) + bxy*(c.y - a.y) + cxy*(a.y - b.y))/d;
        u.y = (axy*(c.x - b.x) + bxy*(a.x - c.x) + cxy*(b.x - a.x))/d;
        double r = dist(a, u);
        //cout<<r<<endl;
        double cir = 2*acos(-1)*r;
        cout<<setprecision(2)<<fixed<<cir<<endl;
    }
    return 0;
}
