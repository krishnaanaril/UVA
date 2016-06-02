/*
    AC Answer - Not mine
    
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>

using namespace std;
typedef unsigned int u32;
typedef long long i64;
typedef unsigned long long u64;
typedef vector<int> IV;
typedef vector<bool> BV;
typedef pair<int,int> II;
typedef vector<II> IIV;
#define For(t,v,c) for(t::const_iterator v=c.begin(); v!=c.end(); ++v)
const int INF = 0x7FFFFFFF;
struct Point {
  double x, y;
  Point(double x=0, double y=0):x(x),y(y) { }
};

typedef Point Vector;

Vector operator + (const Vector& A, const Vector& B) { return Vector(A.x+B.x, A.y+B.y); }
Vector operator - (const Point& A, const Point& B) { return Vector(A.x-B.x, A.y-B.y); }
Vector operator * (const Vector& A, double p) { return Vector(A.x*p, A.y*p); }
Vector operator / (const Vector& A, double p) { return Vector(A.x/p, A.y/p); }
double Dot(const Vector& A, const Vector& B) { return A.x*B.x + A.y*B.y; }
double Length(const Vector& A) { return sqrt(Dot(A, A)); }
double Angle(const Vector& A, const Vector& B) { return acos(Dot(A, B) / Length(A) / Length(B)); }
double Cross(const Vector& A, const Vector& B) { return A.x*B.y - A.y*B.x; }

Point GetLineIntersection(const Point& P, const Point& v, const Point& Q, const Point& w) {
  Vector u = P-Q;
  double t = Cross(w, u) / Cross(v, w);
  return P+v*t;
}

Vector Rotate(const Vector& A, double rad) {
  return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad));
}

Point read_point() {
  double x, y;
  scanf("%lf%lf", &x, &y);
  return Point(x,y);
}
Point solve ( Point A, Point B, Point C ) {
	Point D = B*2.0/3 + C/3;
	Vector AD = D-A;
	Point E = C*2.0/3 + A/3;
	Vector BE = E-B;
	return GetLineIntersection(A, AD, B, BE);
}
double ConvexPolygonArea(Point *p, int n) {
	double area = 0;
	for ( int i = 1; i < n-1; ++i ) area += Cross(p[i]-p[0], p[i+1]-p[0]);
	return area/2;
}
const double EPS = 1E-10;
int main()
{
	int T;
	Point A, B, C, P[3];
	scanf ( "%d", &T );
	while ( T-- ) {
		A = read_point();
		B = read_point();
		C = read_point();
		P[0] = solve(A, B, C);
		P[1] = solve(B, C, A);
		P[2] = solve(C, A, B);
		printf("%.0lf %.0lf\n%.0lf %.0lf\n%.0lf %.0lf\n", P[0].x, P[0].y, P[1].x, P[1].y, P[2].x, P[2].y);
		double ans = ConvexPolygonArea(P,3);
		/*
		double low = floor(ans);
		double high = ceil(ans);
		if ( ( ans-low ) < ( high-ans ) + EPS ) ans = low;
		else ans = high;
		printf ( "%d\n", (int)ans );
		*//*
		printf ( "%.0lf\n", ans );
	}
    return 0;
}

*/
#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FASTIO          ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back
#define x               first
#define y               second

const int mod = 1000000007;

pdd a, b, c;

pdd getSection(pdd a, pdd b, int m, int n)
{
    pdd u;
    u.x =  (b.x*m + a.x*n)/(m+n);
    u.y =  (b.y*m + a.y*n)/(m+n);
    return u;
}

pdd getInter(pdd p1, pdd q1, pdd p2, pdd q2)
{
    pdd u;
    double m1 = (q1.y - p1.y)/(q1.x - p1.x);
    double m2 = (q2.y - p2.y)/(q2.x - p2.x);
    double d1 = p1.y - (m1*p1.x);
    double d2 = p2.y - (m2*p2.x);
    u.x = (d1 - d2)/(m2 - m1);
    u.y = m1*u.x + d1;
    return u;   
}

double dist(pdd a, pdd b)
{
    double px = b.x - a.x;
    double py = b.y - a.y;
    return hypot(px, py);
}

int t;

int main()
{
    FASTIO
    cin>>t;
    while(t--)
    {
        cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
        pdd ab = getSection(a, b, 1, 2);
        pdd bc = getSection(b, c, 1, 2);
        pdd ca = getSection(c, a, 1, 2);
        pdd r = getInter(a, bc, ab, c);
        pdd q = getInter(b, ca, ab, c);
        pdd p = getInter(b, ca, a, bc);
        /*cout<<r.x<<" "<<r.y<<endl; 
        cout<<q.x<<" "<<q.y<<endl;
        cout<<p.x<<" "<<p.y<<endl;*/
        double a1 = dist(p, q);
        double b1 = dist(q, r);
        double c1 = dist(r, p);
        double s = (a1 + b1 + c1)/2.0;
        double area = sqrt(s*(s-a1)*(s-b1)*(s-c1));
        cout<<fixed<<setprecision(0)<<area<<endl;
    }
    return 0;
}
