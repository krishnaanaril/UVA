#include <bits/stdc++.h>

#define x first
#define y second
#define REP(i, a, n) for(int i=(a); i< (n); i++)

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vp;
typedef map<double, vp> mp;
typedef mp::iterator itr;

int a, b, sz;
vp dat;
mp val;
itr it;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    while(true)
    {
        val.clear();
        dat.clear();
        while(cin>>a>>b)
        {
            if(a+b == 0)
                break;
            dat.push_back(pii(a, b));
        }
        if(dat.size()==0)
            break;
        sort(dat.begin(), dat.end());
        sz = dat.size();
        REP(i, 0, sz-2)
        {
            REP(j, i+1, sz-1)
            {
                REP(k, j+1, sz)
                {
                    double a1 = ((double)dat[k].y - dat[i].y)/(dat[k].x - dat[i].x);
                    double a2 = ((double)dat[j].y - dat[i].y)/(dat[j].x - dat[i].x);
                    if(a1 == a2)
                    {
                        if(find(val[a1].begin(), val[a1].end(), dat[i])==val[a1].end())
                            val[a1].push_back(dat[i]);
                        if(find(val[a1].begin(), val[a1].end(), dat[j])==val[a1].end())
                            val[a1].push_back(dat[j]);
                        if(find(val[a1].begin(), val[a1].end(), dat[k])==val[a1].end())
                            val[a1].push_back(dat[k]);
                    }
                }
            }
        }
        int ans =0;
        for(it = val.begin(); it !=val.end(); it++)
        {
            if(it->y.size()>2)
            {
                ans++;
                if(ans==1)
                    cout<<"The following lines were found:"<<endl;                
                REP(i, 0, it->y.size())
                    cout<<"( "<<setw(3)<<it->y[i].x<<", "<<setw(3)<<it->y[i].y<<")";
                cout<<endl;
            }
        }
        if(ans==0)
            cout<<"No lines were found"<<endl;
    }
    return 0;
}
