/*
	Swamy Saranam

	Date	: 04/08/2016 22:36:14
	Author	: Krishna Mohan A M
	Problem	:
	Status	:
*/
#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for(int i=0; i<(n); i++)
#define pb push_back

int can[50], mp[50][50], used[50], n;
string a, b, c, v;
char x, y, ans[50];
bool isFound = 0;

void dfs(int idx)
{
	if(idx==n)
	{
		isFound = 1;
		//ans[idx] = '\0';
		//puts(ans);
		//cout<<ans<<endl;
		REP(i, idx)
			cout<<ans[i]<<" \n"[i==(idx-1)];
		return ;
	}
	REP(i, n)
	{
		if(used[i]==0)
		{
			int j=0;
			for(j=0; j<idx; j++)
			{
				if(mp[v[i]-'A'][ans[j]-'A']==1)
					break ;
			}
			if(j==idx)
			{
			    used[i] = 1;
			    ans[idx] = v[i];
			    dfs(idx+1);
			    used[i] = 0;
			}
		}
	}
}

int main()
{
	bool first =1;
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
	{
		if(!first)
			cout<<endl;
		first = 0;
		getline(cin, a);
		getline(cin, a);
		getline(cin, b);
		if(a=="" || b=="")
			break;
		//cout<<a<<endl<<b<<endl;
		memset(can, 0, sizeof(can));
		memset(mp, 0, sizeof(mp));
		memset(used, 0, sizeof(used));
		stringstream s;
		s<<a;
		n = 0;
        v = "";
		while(s>>x)
		{
			//cout<<x<<endl;
			//can[x-'A'] = 1;
			v += x;
			n++;
		}
		assert(n==v.size());
		sort(v.begin(), v.end());
		s.clear();
		s<<b;
		while(s>>c)
		{
			//cout<<c<<endl;
			assert(c.size()==3);
			mp[c[0]-'A'][c[2]-'A'] = 1;	
		}
		dfs(0);
		if(!isFound)
			cout<<"NO"<<endl;
	}
	return 0;
}
