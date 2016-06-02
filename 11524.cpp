#include <bits/stdc++.h>

using namespace std;

double m1, n1, m2, n2, m3, n3, r;
int n;

int main()
{
	cin>>n;
	while(n--)
	{
		cin>>r>>m1>>n1>>m2>>n2>>m3>>n3;
		n2 = n2/m2*n1;
		m2 = n1;
		n3 = n3/m3*n2;
		m3 = n2;
		double a = m1+n1;
		double b = m2+n2;
		double c = m3+n3;
		double s = (a+b+c)/2;
		double area = sqrt(s*(s-a)*(s-b)*(s-c));
		double x = r/area*s;
		cout<<setprecision(4)<<fixed<<(x*x*area)<<endl;
	}
	return 0;
}