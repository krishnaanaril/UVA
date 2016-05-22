#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define REP(i, n) for(int i=0; i<(n); i++)
#define pb push_back

using namespace std;

typedef double ld;
const double pi = acos(-1);


ld heron(double a, double b, double c)
{
    if(a+b < c || b+c < a || a+c < b)
        return 0;
    ld s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int t, n;
vector<double> dat;
double tmp;
long double sum;

int main()
{
    FASTIO
    cin>>t;
    while(t--)
    {
        sum = 0;
        ld area = 0;
        dat.clear();
        cin>>n;
        REP(i, n)
        {
            cin>>tmp;
            sum += tmp;
            dat.pb(tmp);
        }
        double l = 0, r = sum, mid;
        bool ok = true;
        REP(i, n)
            l = max(l, dat[i]/2);
        if(sum - 2 * l < 2 * l)
            ok = false;
        //cout<<l<<" "<<r<<" "<<sum<<endl;
        REP(i, 40)
        {
            mid = (l+r)/2;
            double theta = 0;
            REP(j, n)
            {
                theta += asin((dat[j]/2) / mid) * 2;
            }
            //cout<<"theta: "<<theta<<endl;
            if(theta > 2*pi)
                l = mid;
            else
                r = mid;
        }
        //cout<<mid<<endl;
        REP(i, n)
        {
            area += heron(mid, mid, dat[i]);
        }
        if(!ok)
            area = 0;
        cout<<fixed<<setprecision(3)<<area<<endl;
    }
    return 0;
}
