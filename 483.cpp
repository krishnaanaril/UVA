#include <bits/stdc++.h>

using namespace std;

typedef vector<string> vs;

int main()
{
    vs data;
    string str, temp;
    istringstream iss;
    //cin.ignore();
    while(getline(cin, str))
    {
        iss.clear();
        iss.str(str);
        while(iss>>temp)
        {
           reverse(temp.begin(), temp.end());
           cout<<temp;
           if(!iss.eof())
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
