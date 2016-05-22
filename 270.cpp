#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vp;

int n, cnt, a, b;
string s;
vp points;
istringstream iss;

int main()
{
    cin>>n;
    getline(cin, s);
    getline(cin, s);
    while(n--)
    {
        while(getline(cin, s))
        {
            if(s=="")
            {                
                break;
            }
            //cout<<s<<endl;   
            sscanf(s.c_str(), "%d %d", &a, &b);
            cout<<a<<" "<<b<<endl;
        }
    }
    return 0;
}
