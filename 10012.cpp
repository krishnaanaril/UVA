#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define REP(i, n) for(int i=0; i<(n); i++)
#define REP2(i, a, n) for(int i=(a); i<(n); i++)
#define pb push_back

using namespace std;

int t, n;
vector<double> dat;
double r, ans, minVal;

int main()
{
    FASTIO
    cin>>t;
    while(t--)
    {
        minVal = 1e100;
        //cout<<minVal<<endl;
        dat.clear();        
        cin>>n;
        REP(i, n)
        {
            cin>>r;
            dat.pb(r);
        }
        sort(dat.begin(), dat.end());
        do
        {
            vector<double> r(dat.begin(), dat.end());
            ans = 0;
            REP2(i, 1, n)
            {
                REP(j, i)
                {
                    double sum  = dat[j] + dat[i];
                    double diff = dat[j] - dat[i];
                    ans = sqrt(sum * sum - diff * diff)+r[j];
                    r[i] = max(ans, r[i]);
                }
            }
            double tmp = 0;
            REP(i, n)
            {
                tmp = max(tmp, r[i]+dat[i]);
            }
            //cout<<"Ans: "<<ans<<endl;
            minVal = min(tmp, minVal);        
        }while(next_permutation(dat.begin(), dat.end()));
        cout<<fixed<<setprecision(3)<<minVal<<endl;
    }
    return 0;
}
