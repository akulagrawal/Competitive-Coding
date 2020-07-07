#include<bits/stdc++.h>

using namespace std;

int main()
{
    int m,d,n,x=0;
    scanf("%d%d",&m,&d);
    switch(m)
    {
        case(1): x=31;
                 break;
        case(2): x=28;
                 break;
        case(3): x=31;
                 break;
        case(4): x=30;
                 break;
        case(5): x=31;
                 break;
        case(6): x=30;
                 break;
        case(7): x=31;
                 break;
        case(8): x=31;
                 break;
        case(9): x=30;
                 break;
        case(10):x=31;
                 break;
        case(11):x=30;
                 break;
        case(12):x=31;
                 break;
        default: break;
    }
    n=x-29+d;
    if(n==0)
        printf("4");
    else if(n<=7)
        printf("5");
    else
        printf("6");
    return 0;
}
