///*
//    UVA: 394 - MapMaker
//    Algorithm: Implementation
//    Status: Accepted
//    Date: 10/12/2014
//*/
//
//#include <bits/stdc++.h>
//
//#define LIM 100007
//
//using namespace std;
//
//int main()
//{
//    ios_base::sync_with_stdio(0);
//    int c[LIM][15], n, r, l, u, base, esz, d[LIM], pos, ans;
//    map<string, int> lookup;
//    vector< pair<int, int> > bounds;
//    string name;
//
//    cin>>n>>r;
//    for(int i=0;i<n;i++)
//    {
//        bounds.clear();
//        cin>>name>>base>>esz>>d[i];
//        lookup[name]=i;
//        for(int j=0;j<d[i];j++)
//        {
//            cin>>l>>u;
//            bounds.push_back(pair<int, int>(l,u));
////            cout<<bounds[j].first<<" : "<<bounds[j].second<<endl;
//        }
//        c[i][d[i]]=esz;
//        for(int j=d[i]-1;j>=1;j--)
//        {
////            cout<<c[i][j+1]<<" : "<<bounds[j].second<<" : "<<bounds[j].first<<endl;
//            c[i][j]=c[i][j+1]*(bounds[j].second-bounds[j].first+1);
//        }
////        cout<<"hi - "<<c[i][d[i]]<<endl;
//        c[i][0]=base;
//        for(int j=1;j<=d[i];j++)
//        {
//            c[i][0]-=(c[i][j]*bounds[j-1].first);
//        }
//    }
//    for(int i=0;i<r;i++)
//    {
//        cin>>name;
//        pos=lookup[name];
////        cout<<"C: "<<endl;
////        for(int i=0;i<=d[pos];i++)
////        {
////            cout<<c[pos][i]<<" ";
////        }
////        cout<<endl;
//        ans=c[pos][0];
//        cout<<name<<"[";
//        for(int j=1;j<=d[pos];j++)
//        {
//            cin>>l;
//            if(j!=d[pos]) cout<<l<<", ";
//            else cout<<l;
//            ans+=c[pos][j]*l;
//        }
//        cout<<"] = "<<ans<<endl;
//    }
//    return 0;
//}
