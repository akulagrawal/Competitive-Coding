#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    int t,n,p1,p2,p3,p,sum,sum1,sum2,i;
    char s1[1005],s2[1005],s3[1005];
    scanf("%d",&t);
    while(t--)
    {
        p=0;sum=0;sum1=0;sum2=0;
        scanf("%s%s%s",s1,s2,s3);
        p1=strlen(s1);
        p2=strlen(s2);
        p3=strlen(s3);
        scanf("%d",&n);
        for(i=p3-1;i>=0;i--)
        {
            if(s3[i]=='0')
                p=1;
            else if(p==1)
                sum++;
        }
        for(i=p2-1;i>=0;i--)
        {
            if(s2[i]=='0')
                p=1;
            else if(p==1)
            {
                sum1++;
                sum2++;
            }
            else
                sum2++;
        }
        if(p==1)
            sum+=(sum1+((n-1)*sum2));
        else
            sum+=(n*sum1);
        for(i=p1-1;i>=0;i--)
        {
            if(s1[i]=='0')
                p=1;
            else if(p==1)
                sum++;
        }
        printf("%d\n",sum+1);
    }
    return 0;
}
