/*
    UVA: 594 - Little endian
    Algorithm: Implementation
    Status: Accepted
    Date: 10/12/2014
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int num, mask=0, ans=0, bk;
    for(int i=0;i<8;i++)
    {
        mask<<=1;
        mask++;
    }
//    cout<<mask<<endl;

    while(cin>>num)
    {
        bk=num;
        ans=0;
        for(int i=0;i<4;i++)
        {
            ans<<=8;
            int temp=num&mask;
//            cout<<"temp: "<<temp<<endl;
            ans|=temp;
    //        cout<<"ans: "<<ans<<endl;

            num>>=8;
        }
        cout<<bk<<" converts to "<<ans<<endl;
    }

    return 0;
}

