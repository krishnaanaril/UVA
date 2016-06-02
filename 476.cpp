#include <bits/stdc++.h>

#define x first 
#define y second
#define FOR(i, a, n) 	for(int i=(a);i<(n); i++)
#define REP(i, n) 		FOR(i, 0, n)

using namespace std;

typedef pair<double, double> pdd;
typedef struct rect
{
	pdd a;
	pdd b;
	rect(pdd _a, pdd _b)
	{
		a = _a;
		b = _b;
	}
}rect;
typedef vector<rect> vr;

char ch;
double l, m, n, o;
vr dat;

bool isInside(rect tmp, pdd pt)
{
	if(pt.x > tmp.a.x && pt.x < tmp.b.x &&
		pt.y < tmp.a.y && pt.y > tmp.b.y )
		return true;
	return false;
}

int main()
{
	while(cin>>ch)
	{
		if(ch == '*')
			break;
		cin>>l>>m>>n>>o;
		//rect tmp();
		dat.push_back(rect(pdd(l, m), pdd(n, o)));
	}
	int sz = dat.size();
	//cout<<sz<<endl;
	int ca = 0;
	while(cin>>l>>m)
	{
		if(l==9999.9 && m==9999.9)
			break;
		bool flag = false;
		ca ++;
		REP(i, sz)
		{
			if(isInside(dat[i], pdd(l, m)))
			{
				cout<<"Point "<<ca<<" is contained in figure "<<(i+1)<<endl;
				flag = true;
			}
		}
		if(!flag)
			cout<<"Point "<<ca<<" is not contained in any figure"<<endl;
	}
	return 0;
}