#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    int t,i,n,p;
    char s[100005];
    scanf("%d",&t);
    while(t--)
    {
        p=0;
        scanf("%s",s);
        n=strlen(s);
        for(i=0;i<n-1;i++)
        {
            if(s[i]=='<'&&s[i+1]=='>')
                p++;
        }
        printf("%d\n",p);
    }
    return 0;
}
