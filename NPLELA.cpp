#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int n,a[5],i,p=0,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        j=i%2;
        scanf("%d",&a[j]);
        if(i>0)
        {
            if(i%2==1)
            {
                if(a[1]<a[0])
                    p=1;
            }
            else
            {
                if(a[0]<a[1])
                    p=1;
            }
        }
    }
    if(p==1)
        printf("Angry");
    else
        printf("Happy");
    return 0;
}
