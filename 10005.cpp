#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define REP(i, n) for(int i=0; i<(n); i++)
#define REP2(i, a, n) for(int i=(a); i<(n); i++)
#define x first
#define y second
#define EPS 1e-9
#define pb push_back

using namespace std;

typedef pair<double, double> pdd;

int n;
vector<pdd> dat;
double a, b, r;

bool areSame(double a, double b)
{
    return fabs(a-b) < EPS;
}

int areSame2(double a, double b)
{
    if(fabs(a-b) < EPS)
        return 0;
    if((a-b) > 0)
        return 1;
    else
        return -1;
}

double getDistance(pdd a, pdd b)
{
    double px = a.x - b.x;
    double py = a.y - b.y;
    return hypot(px, py);
}

bool isCentre(pdd c)
{
    REP(i, n)
    {
        if(areSame2(getDistance(dat[i], c), r) > 0)
            return false;
    }
    return true;
}

bool check(pdd a, pdd b)
{
    double q = getDistance(a, b);
    if(areSame2(q, 2*r) > 0)
        return false;
    double xpart = sqrt(r * r - (q*q*0.25)) * (a.y - b.y)/q;
    double ypart = sqrt(r * r - (q*q*0.25)) * (b.x - a.x)/q;
    pdd c = pdd((a.x + b.x)/2, (a.y + b.y)/2);
    pdd p1 = pdd(c.x + xpart, c.y + ypart);
    pdd p2 = pdd(c.x - xpart, c.y - ypart);
    /*cout<<"q: "<<q<<endl;
    cout<<"a: "<<p1.x<<" b: "<<p1.y<<" c: "<<p2.x<<" d: "<<p2.y<<endl;*/
    return isCentre(p1) || isCentre(p2);
}

bool solve()
{
    if(n==1)
        return true;
    else if(n==2)
        return getDistance(dat[0], dat[1]) <= 2 * r;
    else
    {
        REP(i, n-1)
        {
            REP2(j, i+1, n)
            {
                if(check(dat[i], dat[j]))
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    while(cin>>n)
    {
        if(n==0)
            break;
        dat.clear();
        REP(i, n)
        {
            cin>>a>>b;
            dat.pb(pdd(a, b));
        }
        cin>>r;       
        if(solve())
            cout<<"The polygon can be packed in the circle."<<endl;
        else
            cout<<"There is no way of packing that polygon."<<endl;
    }
}
