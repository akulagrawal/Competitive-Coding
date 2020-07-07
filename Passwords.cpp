#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    int n,k,i,b[100],c,d=0,e=0,sum,minm,maxm;
    char a[100][100],ans[100];
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%s",a[i]);
        b[i]=strlen(a[i]);
    }
    scanf("%s",ans);
    c=strlen(ans);
    for(i=0;i<n;i++)
    {
        if(b[i]<c)
            d++;
        else if(b[i]==c)
            e++;
    }
    sum=d/k;
    minm=(k+5)*sum;
    minm+=((d%k)+1);
    sum=(d+e)/k;
    maxm=(k+5)*sum;
    maxm+=((d+e)%k);
    if((d+e)%k==0)
        maxm-=5;
    printf("%d %d",minm,maxm);
    return 0;
}
