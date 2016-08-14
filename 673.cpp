/*
	Swamy Saranam

	Date	: 14/08/2016 10:50:45
	Author	: Krishna Mohan A M
	Problem	: 673 - Parentheses Balance
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
string s;
int t, n;
stack<char> stk;

int main()
{
    FASTIO
    cin>>t;
    cin.ignore();
    while(t--)
    {
      while(!stk.empty())
        stk.pop();
      getline(cin, s);
      n = s.size();
      //cout<<"n: "<<n<<endl;
      bool isCorrect = true;
      REP(i, n)
      {
        if(s[i]=='(' || s[i]=='[')
          stk.push(s[i]);
        else
        {
          if(stk.empty())
          {
            //cout<<"Empty: "<<s[i]<<endl;
            isCorrect= false;
            break;
          }
          if((stk.top()=='(' && s[i]==')') || (stk.top()=='[' && s[i]==']'))
          {
            stk.pop();
            continue;
          }
          else
          {
            //cout<<"Mismatch: "<<stk.top()<<" "<<s[i]<<endl;
            isCorrect = false;
            break;
          }
        }
      }
      if(!stk.empty())
      {
        //cout<<"Stack not empty"<<endl;
        isCorrect= false;
      }
      if(isCorrect)
        cout<<"Yes"<<endl;
      else
        cout<<"No"<<endl;
    }
    return 0;
}
