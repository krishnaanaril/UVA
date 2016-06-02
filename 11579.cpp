#include <bits/stdc++.h>

#define FOR(i, a, n) 	for(int i=(a);i<(n); i++)
#define REP(i, n) 		FOR(i, 0, n)

using namespace std;

int t, n;
vector<double> dat;
double tmp;
string str;

bool isTriangle(double a, double b, double c)
{
	if(a+b <= c)
		return false;
	if(a+c <= b)
		return false;
	if(b+c <= a)
		return false;
	return true;
}

double getAreaSq(double a, double b, double c)
{
	double s = (a+b+c)/2.0;
	return (s*(s-a)*(s-b)*(s-c));
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		dat.clear();
		REP(i, n)
		{	
			cin>>tmp;
			dat.push_back(tmp);
		}
		sort(dat.begin(), dat.end());
		double maxArea = 0;
		FOR(i, 2, n)
		{
			if(dat[i-1]+dat[i-2] <= dat[i])
				continue;
			else
			{
				maxArea = max(maxArea, getAreaSq(dat[i-2], dat[i-1], dat[i]));
			}
		}
		cout<<setprecision(2)<<fixed<<sqrt(maxArea)<<endl;
	}
	return 0;
}