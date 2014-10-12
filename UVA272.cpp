///*
//    UVA: 272
//    Algorithm: Ad-hoc
//    Status: Accepted
//    Date: 10/9/2014
//*/
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main()
//{
//    string str;
//    int count =0, sx;
//    while(getline(cin, str))
//    {
//        sx=str.size();
//        for(int i=0;i<sx;i++)
//        {
//            if(str[i]=='"')
//            {
//                count++;
//                if(count&1)
//                {
//                    cout<<"``";
//                }
//                else
//                {
//                    cout<<"''";
//                }
//            }
//            else
//            {
//                cout<<str[i];
//            }
//        }
//        cout<<endl;
//    }
//    return 0;
//}
