#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int t,n,q,r;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        q=n/8;
        r=n%8;
        n=8*q;
        switch(r)
        {
            case 0: printf("%dSL",n-1);
                    break;
            case 1: printf("%dLB",n+4);
                    break;
            case 2: printf("%dMB",n+5);
                    break;
            case 3: printf("%dUB",n+6);
                    break;
            case 4: printf("%dLB",n+1);
                    break;
            case 5: printf("%dMB",n+2);
                    break;
            case 6: printf("%dUB",n+3);
                    break;
            case 7: printf("%dSU",n+8);
                    break;
            default: break;
        }
        printf("\n");
    }
    return 0;
}
