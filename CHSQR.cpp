#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int t,k,n,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&k);
        if(k==1)
            printf("1\n");
        else
        {
            n=(k+3)/2;
            for(i=0;i<n;i++)
            {
                j=n-i;
                while(j!=k+1)
                {
                    printf("%d ",j);
                    j++;
                }
                j=1;
                while(j!=n-i)
                {
                    printf("%d ",j);
                    j++;
                }
                printf("\n");
            }
            for(i=0;i<k-n;i++)
            {
                j=k-i;
                while(j!=k+1)
                {
                    printf("%d ",j);
                    j++;
                }
                j=1;
                while(j!=k-i)
                {
                    printf("%d ",j);
                    j++;
                }
                printf("\n");
            }
        }
    }
    return 0;
}
