#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define REP(i, n) for(int i=0; i<(n); i++)
#define x first 
#define y second

using namespace std;

typedef pair<double, double> pdd;

pdd a, b, c, u;
double r;

double dist(pdd a, pdd c)
{
    double px = a.x - c.x;
    double py = a.y - c.y;
    return hypot(px, py);
}

int main()
{
    FASTIO
    bool flag = false;
    while(cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y)
    {        
        double d = 2*(a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y));
        double ax = (a.x*a.x + a.y*a.y);
        double bx = (b.x*b.x + b.y*b.y);
        double cx = (c.x*c.x + c.y*c.y);
        u.x = (ax*(b.y - c.y) + bx*(c.y - a.y) + cx*(a.y - b.y))/d;
        u.y = (ax*(c.x - b.x) + bx*(a.x - c.x) + cx*(b.x - a.x))/d;
        r = dist(a, u);
        double ux2 = 2*u.x;
        double uy2 = 2*u.y;
        double con = u.x*u.x + u.y*u.y - r*r;
        //cout<<setprecision(18)<<fixed<<"con: "<<con<<endl;
        cout<<setprecision(3)<<fixed;
        if(u.x !=  0.0)
            cout<<"(x"<<(u.x>0?" - ":" + ")<<(u.x<0? -1*u.x: u.x)<<")^2 + ";
        else
            cout<<"x^2 + ";
        if(u.y !=0.0)
            cout<<"(y"<<(u.y>0?" - ":" + ")<<(u.y<0? -1*u.y: u.y)<<")^2 = ";
        else
            cout<<"y^2 = ";
        if(r != 0.0)
            cout<<r<<"^2"<<endl;
        else
            cout<<"0"<<endl;
        cout<<"x^2 + y^2";
        if(ux2 != 0.0)
            cout<<(ux2>0?" - ":" + ")<<(ux2<0? -1*ux2: ux2)<<"x";
        if(uy2 != 0.0)
            cout<<(uy2>0?" - ":" + ")<<(uy2<0? -1*uy2: uy2)<<"y";        
        if(con != 0.0)
            cout<<(con<0?" - ":" + ")<<(con<0? -1*con: con);
        cout<<" = 0"<<endl;
        cout<<endl;
    }
    return 0;
}
