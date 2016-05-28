#include <bits/stdc++.h>

using namespace std;

double a, b, c;

int main()
{
    while(cin>>a>>b>>c)
    {
        double s = (a+b+c)/2;
        double area = sqrt(s*(s-a)*(s-b)*(s-c));
        double r = s !=0 ? area/s : 0;
        cout<<"The radius of the round table is: "<<setprecision(3)<<fixed<<r<<endl;
    }
    return 0;
}
