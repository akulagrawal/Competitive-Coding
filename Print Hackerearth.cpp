#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int n,t[30],i,k,temp[10]={0,2,4,7,10,17,19},minm;
    char p;
    scanf("%d",&n);
    getchar();
    for(i=0;i<26;i++)
        t[i]=0;
    for(i=0;i<n;i++)
    {
        scanf("%c",&p);
        k=p;
        k-=97;
        t[k]++;
    }
    t[0]/=2;t[4]/=2;t[7]/=2;t[17]/=2;
    minm=n;
    for(i=0;i<7;i++)
    {
        if(minm>t[temp[i]])
            minm=t[temp[i]];
    }
    printf("%d",minm);
    return 0;
}
