#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int n,k,i,g,t,temp,p=0;
    char s[102];
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    for(i=0;i<n;i++)
    {
        if(s[i]=='G')
            g=i;
        else if(s[i]=='T')
            t=i;
    }
    if(g>t)
    {
        temp=t;
        t=g;
        g=temp;
    }
    for(i=g;i<t;i+=k)
    {
        if(s[i]=='#')
        {
            p=1;
            break;
        }
    }
    if(p==0&&i==t)
        printf("YES");
    else
        printf("NO");
    return 0;
}
