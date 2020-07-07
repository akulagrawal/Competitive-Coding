#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int n,a[100],i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    if(a[n-1]==0)
        printf("UP");
    else if(a[n-1]==15)
        printf("DOWN");
    else if(n==1)
    {
        printf("-1");
    }
    else if(a[n-1]>a[n-2])
    {
        printf("UP");
    }
    else if(a[n-1]<a[n-2])
    {
        printf("DOWN");
    }
    return 0;
}
