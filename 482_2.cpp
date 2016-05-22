#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;

int main()
{
    int t, tmp;
    istringstream iss;
    string s, stmp;
    vi ip;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        getline(cin, s);
        getline(cin, s);
        iss.clear();
        ip.clear();
        iss.str(s);
        while(iss>>tmp)
        {
            ip.push_back(tmp);
        }
        vs dat(ip.size());
        getline(cin, s);
        iss.clear();
        iss.str(s);
        int i=0;
        while(iss>>stmp)
        {
            dat[ip[i++]-1]=stmp;
        }
        for(int i=0; i<ip.size(); i++)
        {
            if(dat[i]!="")
                cout<<dat[i]<<endl;
        }
        if(t)
            cout<<endl;
    }
    return 0;
}
