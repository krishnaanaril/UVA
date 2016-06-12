#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;
typedef vector<pii> vp;

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
const double eps = 1e-8;

//to find the distance between two points
double getDistance(pii a, pii b)
{   
    double px = a.x - b.x;
    double py = a.y - b.y;
    return hypot(px, py);
}

double getArea(vp points)
{
    double det = 0;
    int n = points.size();
    REP(i, n)
    {
        det += (points[i].x*points[(i+1)%n].y) - (points[(i+1)%n].x*points[i].y);
    }
    return fabs(det)*0.5;
}

double isLeft(pii p, pii q, pii r)
{
    return (q.x - p.x)*(r.y - p.y) - (q.y - p.y)*(r.x - p.x);
}

double getConvexHullPerimeter(vp points)
{
    int sz = points.size();
    int k= 0;
    sort(points.begin(), points.end());
    vp tmpHull;
    REP(i, sz)
    {
        while(k>=2 && isLeft(tmpHull[k-2], tmpHull[k-1], points[i])<=0)
            tmpHull.pop_back(), k--;
        tmpHull.push_back(points[i]), k++;
    }
    for(int i=sz-2, t= k+1; i>=0; i--)
    {
        while(k>=t && isLeft(tmpHull[k-2], tmpHull[k-1], points[i])<=0)
            tmpHull.pop_back(), k--;
        tmpHull.push_back(points[i]), k++;
    }
    k = tmpHull.size();
    double res = 0;
    if(k==2)
        res = 2*getDistance(tmpHull[0], tmpHull[1]);
    else
    {
        for(int i = 0, j=k-1; i<k; j= i++)
            res+=getDistance(tmpHull[i], tmpHull[j]);
    }
    return res;
}

int n, X[20], Y[20], V[20], L[20];

int main()
{
    FASTIO
    int ca = 0;
    while(cin>>n)
    {
        if(n==0)    
            break;
        if(ca)
            cout<<endl;
        ca++;
        REP(i, n)
        {
            cin>>X[i]>>Y[i]>>V[i]>>L[i];
        }
        double minCost = 0xffffff, extra = 0;
        int minState, minCut;
        for(int i = (1<<n)-1; i>0; i--)
        {
            double totalLen = 0, cost = 0;
            vp trees;
            int cut = 0;
            REP(j, n)
            {
                if((i>>j)&1)
                {
                    totalLen+=L[j];
                    cost+=V[j];
                    cut++;
                }
                else
                {
                    trees.pb(pii(X[j], Y[j]));
                }
            }
            if(cost>minCost)
                continue;
            /*if(totalLen ==25)
                cout<<trees.size()<<endl;*/
            double currHullLen  = getConvexHullPerimeter(trees);
            //cout<<"currHullLen: "<<currHullLen<<" totalLen: "<<totalLen<<" extra: "<<(totalLen -  currHullLen)<<" treesize: "<<trees.size()<<endl;
            if(currHullLen <= totalLen)
            {
                if((minCost > cost) || ((fabs(minCost - cost)<eps) && (minCut>cut)))
                {
                    minCost = cost;
                    minCut = cut;
                    minState = i;
                    extra = totalLen -  currHullLen;
                }
            }
        }
        cout<<"Forest "<<ca<<endl;
        cout<<"Cut these trees:";
        REP(i, n)
        {
            if((minState>>i)&1)
                cout<<" "<<(i+1);
        }
        cout<<endl;
        cout<<"Extra wood: "<<setprecision(2)<<fixed<<extra<<endl;
    }
    return 0;
}
