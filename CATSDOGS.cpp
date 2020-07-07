#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    long long c,d,l,p1,p2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&c,&d,&l);
        if((2*d)>=c)
            p1=d*4;
        else
            p1=(c-d)*4;
        p2=(c+d)*4;
        if(l%4==0&&l>=p1&&l<=p2)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
