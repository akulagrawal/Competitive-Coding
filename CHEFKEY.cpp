#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int t,n,m,c,i,p;
    scanf("%d",&t);
    while(t--)
    {
        p=0;
        scanf("%d%d%d",&n,&m,&c);
        for(i=1;i<=c;i++)
        {
            if(c%i==0)
            {
                if((i<=n)&&((c/i)<=m))
                    p++;
                else if(i>n)
                    break;
            }
        }
        printf("%d\n",p);
    }
    return 0;
}
