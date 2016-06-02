#include <bits/stdc++.h>

#define pi acos(-1)

using namespace std;

int k;
double r1, r2, r3;

double heron(double a, double b, double c)
{
    double s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

double deg(double a)
{
    return a*180/pi;
}

int main()
{
    cin>>k;
    while(k--)
    {
        cin>>r1>>r2>>r3;
        double ab = r1+r2;
        double bc = r2+r3;
        double ac = r1+r3;
        double triarea = heron(ab, bc, ac);                
        double anga = acos((ab*ab + ac*ac - bc*bc)/(2*ab*ac));
        double angb = acos((ab*ab + bc*bc - ac*ac)/(2*ab*bc));
        double angc = acos((ac*ac + bc*bc - ab*ab)/(2*ac*bc));
        //cout<<deg(anga)<<" - "<<deg(angb)<<" - "<<deg(angc)<<" = "<<(deg(anga)+deg(angb)+deg(angc))<<endl;
        double cira = pi*r1*r1*(anga/(2*pi));
        double cirb = pi*r2*r2*(angb/(2*pi));
        double circ = pi*r3*r3*(angc/(2*pi));        
        //cout<<triarea<<" "<<cira<<" "<<cirb<<" "<<circ<<endl;
        double ans = triarea - (cira + cirb + circ);
        cout<<setprecision(6)<<fixed<<ans<<endl;
    }
    return 0;
}
