///*
//    UVA: 423 - Permutation
//    Algorithm: Implementation
//    Status: Accepted
//    Date: 10/12/2014
//*/
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//bool compare(string a, string b)
//{
//    istringstream is;
//    double da, db;
//    is.str(a);
//    is>>da;
//    is.clear();
//    is.str(b);
//    is>>db;
//    return da<db;
//}
//
//int main()
//{
//    ios_base::sync_with_stdio(0);
//    int t, n, temp;
//    string str;
//    vector<int> order;
//    //    double dtemp;
////    vector<double> dat;
//    string stemp;
//    string::size_type sz;
//    vector<string> sdat;
//    istringstream is;
//    string ans[100007];
//    cin>>t;
//    while(t--)
//    {
//        order.clear();
//        sdat.clear();
////        cin>>str;
////        cin.ignore();
//        getline(cin, str);
//        getline(cin, str);
////        cout<<"str: "<<str<<endl;
//        getline(cin, str);
////        cout<<"str: "<<str<<endl;
//        is.clear();
//        is.str(str);
//        while(!is.eof())
//        {
//            is>>temp;
////            cout<<temp<<endl;
//            order.push_back(temp);
//        }
//        n=*max_element(order.begin(), order.end());
////        cout<<"n: "<<n<<endl;
////        getline(cin, str);
////        cout<<str<<endl;
////        is.clear();
////        is.str(str);
//        for(int i=0;i<n;i++)
//        {
//            cin>>stemp;
//            sdat.push_back(stemp);
//            //dat.push_back(stod(stemp));
//        }
////        for(int i=0;i<n;i++)
////            cout<<sdat[i]<<endl;
////        sort(sdat.begin(), sdat.end(), compare);
////        for(int i=0;i<n;i++)
////            cout<<sdat[i]<<endl;
//        for(int i=0;i<n;i++)
//        {
////            printf("%lf\n", sdat[order[i]-1]);
//            ans[order[i]-1]=sdat[i];
////            cout<<sdat[order[i]-1]<<endl;
//        }
//        for(int i=0;i<n;i++)
//        {
//            cout<<ans[i]<<endl;
//        }
//        if(t>0)
//            cout<<endl;
//    }
//    return 0;
//}
//
