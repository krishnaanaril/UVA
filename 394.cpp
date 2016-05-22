/*
    Accepted
*/
#include <bits/stdc++.h>

using namespace std;

struct address
{
    int B;
    int S;
    int D;
    int C[100], U[100], L[100];
};

map<string, address> dat;

int main()
{
    ios_base::sync_with_stdio(0);
    int N, R, dim[100], ans;
    string name;
    address temp;
    cin>>N>>R;
    for(int i=0; i<N; i++)
    {
        cin>>name>>temp.B>>temp.S>>temp.D;
        for(int j=1; j<=temp.D;j++)
        {
            cin>>temp.L[j]>>temp.U[j];
            //cout<<temp.L[j]<<temp.U[j]<<endl;
        }
        temp.C[temp.D] = temp.S;
        for(int j=temp.D-1; j>0; j--)
        {
            temp.C[j] = temp.C[j+1]*(temp.U[j+1]-temp.L[j+1]+1);
            //cout<<j<<" = "<<temp.C[j]<<"->"<<temp.C[j+1]<<"*"<<temp.U[j+1]<<"-"<<temp.L[j+1]<<endl;
        }
        temp.C[0] = temp.B;
        for(int j=1; j<=temp.D; j++)
        {
            temp.C[0]-= temp.C[j]*temp.L[j];
        }
        dat[name] = temp;
        //cout<<name<<temp.B<<temp.S<<temp.D<<endl;
    }
    for(int i=0; i<R; i++)
    {
        cin>>name;
        ans = dat[name].C[0];
        cout<<name<<"[";
        for(int j=1; j<=dat[name].D; j++)
        {
            cin>>dim[j];
            cout<<dim[j];
            if(j!=dat[name].D)
                cout<<", ";
            ans+=dim[j]*dat[name].C[j];
        }
        cout<<"] = ";
        cout<<ans<<endl;
    }
    return 0;
}

