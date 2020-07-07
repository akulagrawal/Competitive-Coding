#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int k,r,i,temp;
    scanf("%d%d",&k,&r);
    for(i=1;;i++)
    {
        temp=k;
        temp=(temp*i)%10;
        if(temp==r||temp==0)
        {
            printf("%d",i);
            break;
        }
    }
    return 0;
}
