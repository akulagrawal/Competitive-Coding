#include<iostream>
#include<stdio.h>
using namespace std;
long long c;
long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    else
    {
        c=b;
        b=a%b;
        a=c;
        return gcd(a,b);
    }
}
int main()
{
    int i,t,n,j;
    long long a[505],temp,minm,lcm;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        if(n==1)
            minm=0;
        else
            minm=a[0]*a[1];
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[i]>a[j])
                    temp=gcd(a[i],a[j]);
                else
                    temp=gcd(a[j],a[i]);
                lcm=a[j]*a[i]/temp;
                if(minm>lcm)
                    minm=lcm;
            }
        }
        printf("%lld\n",minm);
    }
    return 0;
}
