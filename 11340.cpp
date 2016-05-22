#include <bits/stdc++.h>

using namespace std;

int main()
{
    int lineCount = 0;
    int k, t, n, m;
    long long ans;
    char ch;
    scanf("%d\n", &t);
    while(t--)
    {
        ans=lineCount=0;
        scanf("%d\n", &n);
        map<char, int> mp;
        for(int i=0; i<n; i++)
        {
            scanf("%c %d\n", &ch, &m);
            //printf("%c -  %d\n", ch, m);
            mp[ch]=m;
        }
        scanf("%d\n", &k);
        //printf("ch: %d\n", k);
        while(lineCount<k)
        {
            scanf("%c", &ch);
            if(ch=='\n')
                lineCount++;
            ans+=mp[ch];
            /*if(mp[ch]!=0)
                printf("%c", ch);*/
        }
        printf("%3.2f$\n", (double)ans/100.00);
    }
    return 0;
}
