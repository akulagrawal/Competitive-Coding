#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int n,i,p=0,q=0,temp=0,k=1,t2=0;
    long t;
    char a[200005];
    scanf("%d%ld",&n,&t);
    scanf("%s",a);
    for(i=0;i<n;i++)
    {
        if(q==t)
            break;
        else if((p>0)&&(i==p+1)&&(a[i]>=53))
            break;
        else if((p>0)&&(i>(p+1)))
        {
            if((i<(n-1))&&(a[i]=='4')&&((int)(a[i+1])>=52))
                temp++;
            else if(a[i]<52)
                temp=0;
            if((int)(a[i])>=53)
            {
                if((temp+1)>=t)
                    temp=t-1;
                a[i-1-temp]+=1;
                n=i-temp;
                if((i-1-temp)!=(p+1))
                    k=0;
                q+=temp+1;
                break;
            }
        }
        else if(a[i]=='.')
            p=i;
        else if(p==0)
        {
            if((i<(n-1))&&(a[i]=='9'))
            {
                if((a[i+1]=='9')||(a[i+1]=='.'))
                    t2++;
            }
            else if(a[i]!='9'&&a[i]!='.')
                t2=0;
        }
    }
    if((q==t)||((k==1)&&(a[p+1]<53)))
        k=0;
    else if(k==1)
    {
        if((int)(a[p-1])<57)
        {
            a[p-1]+=1;
            k=0;
            n=p;
        }
        else if((int)(a[p-1])==57)
        {
            n=p;
            if(t2<p)
            {
                for(int j=0;j<t2;j++)
                {
                    a[p-j-1]='0';
                }
                a[p-t2-1]+=1;
                k=0;
            }
            else
            {
                for(int j=0;j<t2;j++)
                {
                    a[p-j-1]='0';
                }
            }
        }
    }
    else
        k=0;
    if(k==1)
        printf("1");
    for(i=0;i<n;i++)
    {
        printf("%c",a[i]);
    }
    return 0;
}
