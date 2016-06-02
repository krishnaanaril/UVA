#include <bits/stdc++.h>

#define M 11
#define FOR(i, a, n) 	for(int i=(a);i<(n); i++)
#define REP(i, n) 		FOR(i, 0, n)

using namespace std;

int h[M][M], v[M][M], ans[M], a, b, n, m, ca;
char ch;

int main()
{
	while(cin>>n>>m)
	{
		ca++;
		memset(h, 0, sizeof(h));
		memset(v, 0, sizeof(v));
		memset(ans, 0, sizeof(ans));
		REP(i, m)
		{
			cin>>ch>>a>>b;
			if(ch=='H')
				h[a][b] = 1;
			else 
				v[b][a] = 1;
		}
		if(ca != 1)
			cout<<endl<<"**********************************"<<endl<<endl;
		for(int i=n; i>0; i--)
		{
			for(int j=n; j>0; j--)
			{
				if(h[i][j])
					h[i][j] = h[i][j+1]+1;
				if(v[i][j])
					v[i][j] = v[i+1][j]+1;
			}
		}
		/*FOR(i, 1, n+1)
		{
			FOR(j, 1, n+1)
				cout<<h[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
		FOR(i, 1, n+1)
		{
			FOR(j, 1, n+1)	
				cout<<v[i][j]<<" ";
			cout<<endl;
		}*/
		FOR(i, 1, n+1)
		{
			FOR(j, 1, n+1)
			{
				for(int k = min(h[i][j], v[i][j]); k>=1; k--)
				{
					if(h[i+k][j] >= k && v[i][j+k] >= k)
						ans[k]++;
				}
			}
		}
		cout<<"Problem #"<<ca<<endl<<endl;
		bool flag = false;
		REP(i, n+1)
		{
			if(ans[i])
			{
				cout<<ans[i]<<" square (s) of size "<<i<<endl;
				flag = true;
			}
		}
		if(!flag)
			cout<<"No completed squares can be found."<<endl;
	}
	return 0;
}