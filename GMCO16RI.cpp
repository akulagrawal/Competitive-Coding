#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    int t,i,n;
    char s[300][60];
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%s",s[i]);
        n=strlen(s[i]);
        if(s[i][n-1]=='y')
            printf("Case #%d: %s is ruled by nobody.\n",(i+1),s[i]);
        else if((s[i][n-1]=='a')||(s[i][n-1]=='e')||(s[i][n-1]=='i')||(s[i][n-1]=='o')||(s[i][n-1]=='u'))
            printf("Case #%d: %s is ruled by a queen.\n",(i+1),s[i]);
        else
            printf("Case #%d: %s is ruled by a king.\n",(i+1),s[i]);
    }
    return 0;
}
