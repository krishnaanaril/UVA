#include <bits/stdc++.h>

using namespace std;

typedef vector<string> vs;

bool compareOp(string str, string tmp)
{
    int t1, t2;
    if((str=="*"||str=="/"))
        t1=2;
    else
        t1=1;
    if((tmp=="*"||str=="/"))    
        t2=2;
    else
        t2=1;
    if(t2>=t1)
        return true;
    else 
        return false;
}

bool isOperator(string tmp)
{
    if(tmp=="+" || tmp=="-" || tmp=="*" || tmp=="/")
        return true;
    else return false;
}

int main()
{
    int t;
    string str, tmp;
    vs dat;    
    cin>>t;
    bool flag = false;
    t++;
    cin.ignore();
    while(t--)
    {
        stack<string> stk;
        while(getline(cin, str))
        {
            //cout<<"\n 1. str: "<<str<<" stk: "<<stk.size()<<endl;
            if(str=="")
                break; 
            if(str=="("){
                    stk.push(str);
            }
            else if(str== ")"){
                    while(!stk.empty())
                    {
                        tmp = stk.top();
                        stk.pop();
                        if(tmp!="(")
                            cout<<tmp;
                        else 
                            break;                           
                    }
            }
            else if(str=="+" ||
                str== "-"||
                str== "*"||
                str== "/"){
                    if(!stk.empty())
                    {
                        while(!stk.empty())
                        {
                            tmp = stk.top();                        
                            if(isOperator(tmp) && compareOp(str, tmp))
                            {
                                stk.pop();
                                cout<<tmp;
                            }
                            else 
                            {                                
                                break;                           
                            }
                        }
                        stk.push(str);
                    }
                    else
                    {
                        //cout<<"\n 2. str: "<<str<<endl;
                        stk.push(str);
                    }
              }
              else{
                    /*tmp = stk.top();
                    stk.pop();*/
                    cout<<str;
               }          
            
        }
        while(!stk.empty())
        {
            tmp=stk.top();
            stk.pop();
            cout<<tmp;
        }
        if(flag)
            cout<<endl<<endl;
        flag=true;
    }
    return 0;
}
