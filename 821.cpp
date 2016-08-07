/*
	Swamy Saranam

	Date	: 30/07/2016 23:50:09
	Author	: Krishna Mohan A M
	Problem	: 821 - Page Hopping
	Status	:
*/
#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
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
#define endl            "\n"
#define sendl           " \n"

const int mod = 1000000007;
int a, b, graph[105][105];
set<int> vertices;

void printGraph()
{
    REP(i, 5)
    {
        REP(j, 5)
            printf("%6d ", graph[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main()
{
    //FASTIO
    int ca = 0;
      REP(i, 105)
                REP(j, 105)
                    graph[i][j] = 999999;
    while(scanf("%d %d", &a, &b) != EOF)   
    {
        if((a+b)==0)
        {
            ++ca;
            int sz = vertices.size();
            if(sz !=0)
            {
                //printGraph();
                REP(k, 105)
                    REP(i, 105)
                        REP(j, 105)
                            graph[i][j] = min(i==j? 0: graph[i][j], graph[i][k]+graph[k][j]);
                int num = 0, den = sz*(sz-1);
                REP(i, 105)
                    REP(j, 105)
                        if(graph[i][j]!=999999)
                            num += graph[i][j];
                //printGraph();
                double ans = num*1.0/den;
                printf("Case %d: average length between pages = %.3lf clicks\n", ca, ans);
            }
            vertices.clear();
            REP(i, 105)
                REP(j, 105)
                    graph[i][j] = 999999;
            continue;
        }
        vertices.insert(a);
        vertices.insert(b);
        graph[a][b] = 1;
    }
    return 0;
}
