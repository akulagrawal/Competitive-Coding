#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int n,i,b1=0,b2=0,r1=0,r2=0,maxm1,maxm2;
    char a[100005];
    scanf("%d",&n);
    scanf("%s",a);
    for(i=0;i<n;i++)
    {
        if((i%2==0)&&(a[i]=='b'))
            b1++;
        else if((i%2!=0)&&(a[i]=='r'))
            r1++;
    }
    b2=(n/2)-r1;
    r2=n-(r1+b2+b1);
    if(b1>=r1)
        maxm1=b1;
    else
        maxm1=r1;
    if(b2>=r2)
        maxm2=b2;
    else
        maxm2=r2;
    if(maxm1>=maxm2)
        printf("%d",maxm2);
    else
        printf("%d",maxm1);
    return 0;
}
