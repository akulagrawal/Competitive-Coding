#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int n,x,y[100005],i,p,sum=0,sum1=0,sum2=0,temp;
    scanf("%d%d",&n,&x);
    for(i=0;i<n;i++)
        scanf("%d",&y[i]);
    for(i=0;i<n;i++)
    {
        if(y[i]==-1)
        {
            printf("%d %d\n",sum1,sum);
            sum1=0;
        }
        else
        {
            sum1+=y[i];
            sum+=y[i];
        }
        if(y[i]%2==1&&(i+1)%x==0)
            continue;
        else if(y[i]%2==1||(i+1)%x==0)
        {
            temp=sum1;
            sum1=sum2;
            sum2=temp;
        }
    }
    printf("%d",sum);
    return 0;
}
