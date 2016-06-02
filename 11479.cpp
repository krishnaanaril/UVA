#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isTriangle(ll a, ll b, ll c)
{
	if(a+b < c)
		return false;
	if(a+c < b)
		return false;
	if(b+c < a)
		return false;
	return true;
}

ll t, a, b, c, ca;

int main()
{
	cin>>t;
	while(t--)
	{
		ca++;
		cin>>a>>b>>c;
		if(!isTriangle(a, b, c))
			cout<<"Case "<<ca<<": Invalid"<<endl;
		else if(a==b && b==c)
			cout<<"Case "<<ca<<": Equilateral"<<endl;
		else if(a==b || b==c || a==c)
			cout<<"Case "<<ca<<": Isosceles"<<endl;
		else
			cout<<"Case "<<ca<<": Scalene"<<endl;
	}
	return 0;
}