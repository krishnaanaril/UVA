#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    double h, u, d, f, tr, dis, fat;
    int day;
    bool flag;
    while(cin>>h>>u>>d>>f)
    {
        if(h==0)
            break;
        tr=day=dis=0;
        flag=true;
        fat = u*f/100;
        while(true)
        {            
            dis+=u;
            day++;            
            //cout<<"Day- "<<day<<"->"<<tr<<" : "<<dis<<endl;
            if(dis>h)
                break;
            u-=fat;
            if(u<0)
                u=0;
            dis-=d;
            //cout<<"Night- "<<day<<"->"<<tr<<" : "<<dis<<endl;
            if(dis<=0)
            {
                if(dis==0)
                    day++;  
                flag=false;
                break;
            }   
        }
        if(flag)
            cout<<"success on day "<<day<<endl;
        else 
            cout<<"failure on day "<<day<<endl;
    }
    return 0;
}
