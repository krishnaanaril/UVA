#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef vector<string> vs;

int n;
string s;
vs dat; 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    while(cin>>n)
    {
        dat.clear();
        if(n==0)
            break;
        REP(i, n)
        {
            cin>>s;
            dat.push_back(s);
        }        
        REP(i, n)
        {
            REP(j, n-i-1)
            {
                if(dat[j+1]+dat[j] > dat[j]+dat[j+1])
                {
                    //cout<<dat[j+1]+dat[j]<<" "<<dat[j]+dat[j+1]<<endl;
                    s = dat[j+1];
                    dat[j+1] = dat[j];
                    dat[j] = s;
                }
            }
        }
        REP(i, n)
        {
            cout<<dat[i];
        }
        cout<<endl;
    }
    return 0;
}
