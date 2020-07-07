#include<iostream>
#include<stdio.h>
using namespace std;
int t;
long long a,b,c,d,ans;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        if(a>=d)
            ans=0;
        else
        {
            if(c<=a)
                c=a+1;
            if(b>=d)
                b=d-1;
            if(b<c)
                ans=(b-a+1)*(d-c+1);
            else
                ans=((c-a)*(d-c+1))+((b-c+1)*(d-c))-(((b-c)*(b-c+1))/2);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
