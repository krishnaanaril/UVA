#include <bits/stdc++.h>

#define FOR(i, a, n) 	for(int i=(a);i<(n); i++)
#define REP(i, n) 		FOR(i, 0, n)
#define M 				105

using namespace std;

int graph[M][M], sum[M][M], n, m;
string tmp;

int main()
{
	while(cin>>n)
	{
		if(n==0)
			break;
		memset(graph, 0, sizeof(graph));
		memset(sum, 0, sizeof(sum));
		cin>>m;
		REP(i, n)
		{
			cin>>tmp;
			REP(j, m)
				graph[i+1][j+1] = tmp[j]-'0';
		}
		FOR(i, 1, n+1)
		{
			FOR(j, 1, m+1)
				sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + graph[i][j];
		}
		int ans = 0;
		FOR(x1, 1, n+1)
		{
			FOR(y1, 1, m+1)
			{
				FOR(x2, x1, n+1)
				{
					FOR(y2, y1, m+1)
					{
						if((x2-x1+1)*(y2-y1+1) == (sum[x2][y2]+sum[x1-1][y1-1] - sum[x1-1][y2]-sum[x2][y1-1]))
							ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}