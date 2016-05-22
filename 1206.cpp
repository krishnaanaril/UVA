/*
    Jarvis algorithm implementation, not solved
*/

#include <bits/stdc++.h>

#define x first
#define y second

#define REP(i, a, n) for(int i = (a); i < (n); i++)

using namespace std;

typedef pair<double, double> pii;
typedef vector<pii> vp;

double a, b;
char l, m, n;
string mainStr, s;
vp points, hull;

int orientation(pii p, pii q, pii r)
{
    double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if(val == 0)
        return val;
    return val > 0 ? 1 : 2;
}

int main()
{    
    while(getline(cin, mainStr))
    {
        //cout<<mainStr<<endl;
        int sz = 0;
        points.clear();
        hull.clear();
        istringstream iss, issM;
        issM.str(mainStr);
        while(issM>>s)
        {
            iss.str(s);
            iss>>l>>a>>m>>b>>n;
            //cout<<a<<" "<<b<<endl;
            points.push_back(pii(a, b));
            sz++;
        }
        int p, l=0, q;
        REP(i, 1, sz)
        {
            if(points[i].x < points[l].x)
                l = i;
        }
        p= l;
        do
        {
            //cout<<"P: "<<p<<"L:"<<l<<endl;
            hull.push_back(points[p]);
            q = (p+1)%sz;
            REP(i, 0, sz)
            {
                if(orientation(points[p], points[i], points[q]) == 2)
                    q = i;
            }
            p = q;
        }while(p != l);
        int n = hull.size();
        REP(i, 0, n)
        {
            cout<<setprecision(15)<<"("<<hull[i].x<<", "<<hull[i].y<<") ";
        }
        cout<<"("<<hull[0].x<<", "<<hull[0].y<<")"<<endl;
    }
    return 0;
}
