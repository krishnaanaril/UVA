#include <bits/stdc++.h>

#define pi acos(-1)

using namespace std;

double a;

int main()
{
    while(cin>>a)
    {        
        double s = sin(108*pi/180)/sin(63*pi/180)*a;        
        cout<<setprecision(10)<<fixed<<s<<endl;        
    }
    return 0;
}
