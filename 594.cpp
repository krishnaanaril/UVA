#include <bits/stdc++.h>

using namespace std;

typedef int ll;

ll reverseBits(ll num)
{
    ll reverseNum = 0;
    ll bitsNum = sizeof(num)*8;
    cout<<bitsNum<<endl;
    for(int i=0; i<bitsNum; i++)
    {
        if(num & (1<<i))
            reverseNum |= (1<<((bitsNum-1)-i));
    }
    return reverseNum;
}

ll endianConversion(ll num)
{
    ll reverseNum = ((num>>24)&0xff) | // move byte 3 to byte 0
                    ((num<<8)&0xff0000) | // move byte 1 to byte 2
                    ((num>>8)&0xff00) | // move byte 2 to byte 1
                    ((num<<24)&0xff000000); // byte 0 to byte 3
    return reverseNum;
}

ll endianConversion2(ll x)
{
    bitset<32> b(x);
    long ret = 0;
    for (int j=0; j<32; j++) if (b[j]) ret |= 1<<(3-j/8)*8+(j%8);
    return ret;
}

ll endianConversion3(ll x)
{
    ll reverse = x;
    char *bits = (char *)&reverse;
    swap(bits[0], bits[3]);
    swap(bits[1], bits[2]);
    return reverse;
}

int main()
{
    ll num;
    while(cin>>num)
        cout<<num<<" converts to "<<endianConversion3(num)<<endl;
//    cout<<endl;
/*
    int o, reverse;
    while (scanf("%d", &o) == 1) {
        reverse = o;
        char * bits = (char*) &reverse;
        swap(bits[0], bits[3]), swap(bits[1], bits[2]);
        printf("%d converts to %d\n", o, reverse);
    }*/
    return 0;
}
