#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int n,a[200005],i,p=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        if(a[i]%2==1)
        {
            if(p==0)
                p=1;
            else
                p=0;
        }
        if(p==1)
        {
            if(a[i]==0)
            {
                printf("NO");
                break;
            }
        }
    }
    if(p==1&&i==n)
        printf("NO");
    else if(p==0)
        printf("YES");
    return 0;
}
