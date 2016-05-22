#include <bits/stdc++.h>

using namespace std;

void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

struct teamDetails
{
    string name;
    int ga, gf, games, points;
    teamDetails()
    {
        ga=gf=games=points;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    string str, t1, t2, s1, s2, tname, name;
    int t, n, g;
    istringstream iss;
    map<string, teamDetails> table;
    vector<teamDetails> vtable;
    cin>>t;
    while(t--)
    {
        cin>>tname>>n;
        for(int i=0;i<n;i++)
        {
            teamDetails tmp;
            cin>>name;
            tmp.name = name;
            table[name]  = tmp; 
        }
        cin>>g;
        for(int i=0;i<g;i++)
        {
            cin>>str;
            replaceAll(str, "#", " ");
            replaceAll(str, "@", " ");
            cout<<str<<endl;
            iss.str(str);    
            iss>>t1>>s1>>s2>>t2;
            table[t1].games++; table[t2].games++;
            table[t1].ga+=s1; table[t1].gd+=s2;
            table[t2].ga+=s2; table[t2].gd+=s1;
            if(s1>s2)
                table[t1].points+=3;
            else if(s2>s1)
                table[t2].points+=3;    
            else
                table[t1].points++; table[t2].points++;
            cout<<t1<<" : "<<s1<<" : "<<s2<<" : "<<t2<<endl;
        }
        vtable = 
    }
    return 0;
}
