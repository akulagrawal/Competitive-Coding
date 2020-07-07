#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    char a[105];
    int i,n,sum=0,p,k;
    scanf("%s",a);
    n=strlen(a);
    p='a';
    for(i=0;i<n;i++)
    {
        k=a[i]-p;
        if(k<0)
            k*=-1;
        if(k<=13)
            sum+=k;
        else
            sum+=(26-k);
        p=a[i];
    }
    printf("%d",sum);
    return 0;
}
