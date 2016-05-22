#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define REP(i, n) for(int i=0; i<(n); i++)
#define REP2(i, a, n) for(int i=(a); i<(n); i++)
#define x first
#define y second
#define EPS 1e-9

using namespace std;

typedef pair<double, double> pdd;

int t, n, sz, maxVal;
vector<pdd> dat;
double a, b;
set<pdd> st;

bool areSame(double a, double b)
{
    return fabs(a - b) < EPS;
}

int main()
{
    FASTIO
    cin>>t;
    REP(ca, t)
    {
        dat.clear();
        st.clear();
        maxVal = 0;
        cin>>n;
        REP(i, n)
        {
            cin>>a>>b;
            st.insert(pdd(a, b));
        }
        dat.assign(st.begin(), st.end());
        sz = dat.size();
        if(sz == 1)
        {
            cout<<"Data set #"<<(ca+1)<<" contains a single gnu."<<endl;
        }
        else 
        {
            REP(i, sz-2)
            {
                REP2(j, i+1, sz-1)
                {
                    int len = 2;
                    double dx = dat[j].x - dat[i].x;
                    double dy = dat[j].y - dat[i].y;
                    double c = dat[j].y * dx  - dat[j].x * dy;
                    REP2(k, j+1, sz)
                    {      
                        double d = (dat[k].y * dx  - dat[k].x * dy);                  
                        if(areSame(d, c))
                        {
                            //cout<<k<<" -> "<<dat[k].x<<" "<<dat[k].y<<endl;
                            len++;
                        }
                        /*else
                            cout<<setprecision(11)<<fixed<<d<<" == "<<c<<" not matching...Diff: "<<(d - c)<<endl;*/
                    }
                    if(maxVal < len)
                        maxVal = len;
                }
            }
            if(sz <= 2)
                maxVal = sz;
            cout<<"Data set #"<<(ca+1)<<" contains "<<sz<<" gnus, out of which a maximum of "<<maxVal<<" are aligned."<<endl;
        }
        //cout<<dat.size()<<endl;
    }
    return 0;
}
