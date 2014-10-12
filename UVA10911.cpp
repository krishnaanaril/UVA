///*
//    UVA: 10911
//    Algorithm: Bit manipulatoion
//    Status: Accepted
//    Date: 10/6/2014
//*/
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int n;
//double dist[20][20], memo[1<<16], x[20], y[20];
//string name;
//
//void printBit(int num)
//{
//    int mask=(1<<31);
//    for(int i=0;i<32;i++)
//    {
//        if(mask&(num<<i)) cout<<"1";
//        else cout<<"0";
//    }
//    cout<<endl;
//}
//
//double matching(int bitmask)
//{
////    cout<<"Bitmasl: "<<bitmask<<endl;
//    if(memo[bitmask]>-0.5) return memo[bitmask];
//    if(bitmask==(1<<2*n)-1) return memo[bitmask]=0;
//    double matchingvalue=32767*32767;
//    for(int i=0;i<2*n;i++)
//    {
//        if(!(bitmask & (1<<i)))
//        {
////            cout<<"bitmask: ";
////            printBit(bitmask);
////            cout<<endl<<"(1<<i): ";
////            printBit(1<<i);
//            for(int j=i+1;j<2*n;j++)
//            {
//                if(!(bitmask & (1<<j)))
//                {
////                    cout<<endl<<"(1<<j): ";
////                    printBit(1<<j);
//                    matchingvalue=min(matchingvalue, dist[i][j]+matching(bitmask | (1<<i) | (1<<j)));
//                }
//            }
//            break;
//        }
//    }
//    return memo[bitmask]=matchingvalue;
//}
//
//int main()
//{
//    ios_base::sync_with_stdio(0);
//    int i=0;
////    printBit(10);
//    while(true)
//    {
//        cin>>n;
//        if(n==0) break;
//        for(int i=0;i<2*n;i++)
//        {
//            cin>>name>>x[i]>>y[i];
//        }
//        for(int i=0;i<2*n;i++)
//        {
//            for(int j=0;j<2*n;j++)
//            {
//                dist[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
//            }
//        }
//        memset(memo, -1, sizeof memo);
//        printf("Case %d: %.2lf\n", ++i, matching(0));
//    }
//    return 0;
//}
