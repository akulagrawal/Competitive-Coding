#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int n,p=0,a[105],j=0,i;
    char ch;
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        scanf("%c",&ch);
        if((ch=='W')&&(p!=0))
        {
            a[j]=p;
            p=0;
            j++;
        }
        else if(ch=='B')
            p++;
        if((i==n-1)&&(p!=0))
        {
            a[j]=p;
            j++;
        }
    }
    printf("%d\n",j);
    for(i=0;i<j;i++)
        printf("%d ",a[i]);
    return 0;
}
