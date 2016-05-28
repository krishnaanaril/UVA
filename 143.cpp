#include <bits/stdc++.h>

#define REP(i, n) for(int i=0; i<(n); i++)
#define REP2(i, a, n) for(int i=(a); i<(n); i++)
#define x first 
#define y second
#define EPS 1e-8

using namespace std;

typedef pair<double, double> pdd;

long long cross(pdd o, pdd a, pdd b) {
    return (a.x - o.x)*(b.y - o.y) - (a.y - o.y)*(b.x - o.x);
}
int inShape(pdd a, pdd b, pdd c, pdd t) {
    if(cross(a, b, t)*cross(a, c, t) > 0) {
        return 0;
    }
    if(cross(b, a, t)*cross(b, c, t) > 0) {
        return 0;
    }
    if(cross(c, a, t)*cross(c, b, t) > 0) {
        return 0;
    }
    return 1;
}

double area(pdd a, pdd b, pdd c)
{
    return fabs((a.x*(b.y - c.y )+ b.x*(c.y - a.y) + c.x*(a.y - b.y))/2.0);
}

bool areSame(double a, double b)
{
    return fabs(a-b) < EPS;
}


bool isInside(pdd a, pdd b, pdd c, pdd pt)
{
    double areaMain = area(a, b, c);
    double area1 = area(pt, b, c);
    double area2 = area(a, pt, c);
    double area3 = area(a, b, pt);
    return areSame(areaMain, (area1 + area2 + area3));
}

int parseDouble(string str) {/*100X*/
    int tmp = 0, i, cnt = 0;
    for(i = 0; str[i]; i++) {
        if(str[i] >= '0' && str[i] <= '9')
            tmp = tmp*10 + str[i]-'0';
        else {
            i++;
            for(; str[i]; i++) {
                tmp = tmp*10 + str[i]-'0';
                cnt++;
                if(cnt == 2)
                    return tmp;
            }
            while(cnt < 2)
                tmp = tmp*10, cnt++;
            return tmp;
        }
    }
    while(cnt < 2)
        tmp = tmp*10, cnt++;
    return tmp;
}

int main()
{
    while(true)
    {
        pdd v[3];        
        double sum = 0, lx = 99, ly = 99, hx  = -1, hy = -1;
        int ans =0;
        string sa, sb;
        REP(i, 3)
        {
            cin>>v[i].x>>v[i].y;
            sum += v[i].x + v[i].y;
            lx = min(lx, v[i].x);
            ly = min(ly, v[i].y);
            hx = max(hx, v[i].x);
            hy = max(hy, v[i].y);
        }           
        if(sum == 0)
            break;
        lx = (int)lx;
        ly = (int)ly;
        hx = (int)hx;
        hy = (int)hy;
        //cout<<lx<<" - "<<ly<<" - "<<hx<<" - "<<hy<<endl;
        REP2(i, lx, hx+1)
        {
            REP2(j, ly, hy+1)
            {
                if(inShape(v[0], v[1], v[2], pdd(i, j)))
                    ans++;
            }
        }
        cout<<setw(4)<<ans<<endl;
    }
    return 0;
}
