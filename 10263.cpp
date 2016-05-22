#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define x first
#define y second
#define REP(i, n) for(int i=0; i<(n); i++)
#define pb push_back
#define INF 1000000007
#define EPS 1e-9

using namespace std;

typedef pair<double, double> pdd;
typedef vector<pdd> vpd;

pdd m, res;
int n;
double a, b, dx, dy, k, l;
vpd lines;

double getDistance(pdd a, pdd b)
{
    double px = a.x - b.x;
    double py = a.y - b.y;
    return hypot(px, py);
}

int main()
{
    FASTIO
    while(cin>>m.x>>m.y)
    {
        double ans = INF;
        lines.clear();
        cin>>n;
        REP(i, n+1)
        {
            cin>>a>>b;
            lines.pb(pdd(a, b));
        }
        //cout<<lines.size()<<endl;
        REP(i, n)
        {
            //cout<<lines[i].x<<" "<<lines[i].y<<endl;
            //cout<<lines[i+1].x<<" "<<lines[i+1].y<<endl;
            dx = lines[i+1].x - lines[i].x;
            dy = lines[i+1].y - lines[i].y;
            k = (dx * (m.x - lines[i].x) + dy * (m.y - lines[i].y));// / (dx*dx + dy*dy);
            l = (-dx * (m.x - lines[i+1].x) + -dy * (m.y - lines[i+1].y));

            if(k < EPS) 
            {
                a = lines[i].x;
                b = lines[i].y;
            }
            else if(l < EPS)
            {
                a = lines[i+1].x;
                b = lines[i+1].y;
            }
            else
            {
                k/=(dx*dx + dy*dy);
                a = lines[i].x + k * dx;
                b = lines[i].y + k * dy;
            }
            double currDist = getDistance(m, pdd(a, b));
            //cout<<currDist<<endl;
            if(currDist < ans)
            {
                ans = currDist;
                res = pdd(a, b);
            }
        }        
        cout<<fixed<<setprecision(4)<<res.x<<endl<<res.y<<endl;
    }
    return 0;
}
