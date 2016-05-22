// Got WA
#include <bits/stdc++.h>

using namespace std;

typedef vector<float> vf;
typedef pair<int, string> pis;
typedef vector<pis> vpis;

int main()
{
    string s;
    istringstream iss, oss;
    int t,sz, itmp;
    string otmp;
    vf io, op;
    vpis dat;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        dat.clear();
        getline(cin, s);
        //cout<<"io: "<<s<<endl;
        if(s=="")
            getline(cin, s);
        iss.clear();
        iss.str(s);
        //cout<<"i: "<<s<<endl;
        sz=0;
        getline(cin, s);
        oss.clear();
        oss.str(s);
        //cout<<"o: "<<s<<endl;
        while(iss>>itmp && oss>>otmp)
        {
            //if(!oss.eof())
            {
                //oss>>otmp;
                //cout<<itmp<<" : "<<otmp<<endl;
                dat.push_back(pis(itmp, otmp));
                sz++;
            }
        }
        sort(dat.begin(), dat.end());
        for(int i=0; i<sz; i++)
        {
            cout<<dat[i].second<<endl;
        }
        if(t)
            cout<<endl;
    }
    return 0;
}
