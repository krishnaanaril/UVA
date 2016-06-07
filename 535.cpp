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
const double pi = acos(-1);
const double R = 6378;

map<string, pdd> dat;
string a, b;
double c, d;

// Using the logic of Morris
double greatCircleDistance(pdd p, pdd q)
{
    p.x *= pi/180.0; // Latitude 
    p.y *= pi/180.0; // Longitude
    q.x *= pi/180.0;
    q.y *= pi/180.0;
    double xp = R*cos(p.x)*sin(p.y);
    double yp = R*cos(p.x)*cos(p.y);
    double zp = R*sin(p.x);
    double xq = R*cos(q.x)*sin(q.y);
    double yq = R*cos(q.x)*cos(q.y);
    double zq = R*sin(q.x);    
    double AB = sqrt((xp - xq)*(xp - xq) + (yp - yq)*(yp - yq) + (zp - zq)*(zp - zq));
    //cout<<"AB: "<<AB<<endl;
    double OA = R, OB = R;
    double theta = acos((OA*OA + OB*OB - AB*AB)/(2*OA*OB));
    return R*theta;
}

// Got from the book,
double greatCircleDistance2(double pLat, double pLong,
double qLat, double qLong, double radius) {
pLat *= pi / 180; pLong *= pi / 180;
qLat *= pi / 180; qLong *= pi / 180;
return radius * acos(cos(pLat)*cos(pLong)*cos(qLat)*cos(qLong) +
cos(pLat)*sin(pLong)*cos(qLat)*sin(qLong) +
sin(pLat)*sin(qLat));
}

int main()
{
    FASTIO
    while(cin>>a)
    {
        if(a == "#")
            break;
        cin>>c>>d;
        //cout<<c<<" "<<d<<endl;
        dat[a] = pdd(c, d);
    }
    while(cin>>a>>b)
    {
        if(a == "#" && b == "#")
            break;
        cout<<a<<" - "<<b<<endl;
        if(dat.count(a) == 0 || dat.count(b) == 0)
            cout<<"Unknown"<<endl;
        else
        {            
            double ans;
            if(a ==  b)
                ans = 0;
            else
                ans = greatCircleDistance2(dat[a].x, dat[a].y, dat[b].x, dat[b].y, R);
            //cout<<setprecision(0)<<fixed<<greatCircleDistance(dat[a], dat[b])<<" km"<<endl;
            //cout<<setprecision(0)<<fixed<<ans<<" km"<<endl;
            cout<<round(ans)<<" km"<<endl;
        }
    }
    return 0;
}
