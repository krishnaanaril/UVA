    #include <bits/stdc++.h>

    using namespace std;

    int main()
    {
        ios_base::sync_with_stdio(0);
        int n, m, c, maxVal, tmp, curr, seq=0;
        int dat[100];
        bool flag[100];
        while(true)
        {
            seq++;
            cin>>n>>m>>c;
            if(n==0 && m==0 && c==0)
                break;
            for(int i=0;i<n;i++)
            {
                cin>>dat[i];
                flag[i]=0;
            }
            maxVal=curr=0;
            for(int i=0;i<m; i++)
            {
                cin>>tmp;
                if(flag[tmp-1])
                    curr-=dat[tmp-1];
                else
                    curr+=dat[tmp-1];
                //cout<<tmp<<": "<<flag[tmp-1]<<" : "<<curr<<endl;
                flag[tmp-1]= !flag[tmp-1];
                maxVal = max(curr, maxVal);
            }
            cout<<"Sequence "<<seq<<endl;
            if(maxVal>c)
                cout<<"Fuse was blown."<<endl;
            else
            {
                cout<<"Fuse was not blown."<<endl;
                cout<<"Maximal power consumption was "<<maxVal<<" amperes."<<endl;
            }
            cout<<endl;
        }
        return 0;
    }
