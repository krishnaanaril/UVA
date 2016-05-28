#include <bits/stdc++.h>

using namespace std;

double a, b, c;

int main()
{
    while(cin>>a>>b>>c)
    {
        double s = (a+b+c)/2;
        double area = sqrt(s*(s-a)*(s-b)*(s-c))*4.0/3.0;
        area  = area>0.0 ? area : -1;
        cout<<setprecision(3)<<fixed<<area<<endl;
    }
}
