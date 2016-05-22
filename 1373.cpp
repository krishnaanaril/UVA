#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef struct stars
{
    double x, y, z;
    stars(double a, double b, double c)
    {
        x = a;
        y = b;
        z = c;
    }
}stars;

typedef struct tele
{
    double x, y, z, angle;
    tele(double a, double b, double c, double d)
    {
        x = a;
        y = b;
        z = c;
        angle = d;
    }
}tele;

typedef pair<double, double> pdd;

set<pdd> ans;

vector<stars> s;
vector<tele> t;

int n, m;
double a, b, c, d, mag, res;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    while(cin>>n)
    {
        s.clear();
        t.clear();
        ans.clear();
        if(n==0)
            break;
        REP(i, n)
        {
            cin>>a>>b>>c;
            mag = sqrt(a*a + b*b + c*c);
            s.push_back(stars(a/mag, b/mag, c/mag));
        }
        //cout<<s.size()<<endl;
        cin>>m;
        REP(i, m)
        {
            cin>>a>>b>>c>>d;
            mag = sqrt(a*a + b*b + c*c);
            t.push_back(tele(a/mag, b/mag, c/mag, d));   
        }
        //cout<<t.size()<<endl;
        REP(i, n)
        {
            REP(j, m)
            {
                res = acos(s[i].x*t[j].x + s[i].y*t[j].y + s[i].z*t[j].z);
                //cout<<res<<" = "<<t[j].angle<<endl; 
                if(res < t[j].angle)
                {
                    //cout<<i+1<<" = "<<j+1<<endl; 
                    //ans++;
                    ans.insert(pdd(res, t[j].angle));
                }
            }
        }
        cout<<ans.size()<<endl;
    }
    return 0;
}
