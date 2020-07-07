#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
     int n,k,a[505],i,sum=0,t;
     scanf("%d%d",&n,&k);
     for(i=0;i<n;i++)
        scanf("%d",&a[i]);
     for(i=1;i<n;i++)
     {
        t=k-a[i]-a[i-1];
        if(t>0)
        {
            sum+=t;
            a[i]+=t;
        }
     }
     printf("%d\n",sum);
     for(i=0;i<n;i++)
        printf("%d ",a[i]);
     return 0;
}
