#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,a[100005],i;
    double temp,x,y,s1=0,s2=0,avg;
    scanf("%d%lf%lf",&n,&x,&y);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    if(x>y)
    {
        temp=x;
        x=y;
        y=temp;
    }
    for(i=n-1;i>n-x-1;i--)
        s1+=(double)a[i];
    for(i=n-x-1;i>n-x-y-1;i--)
        s2+=(double)a[i];
    avg=(s1/x)+(s2/y);
    printf("%f",avg);
    return 0;
}
