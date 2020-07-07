#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    long w,x,y,z,sum;
    scanf("%ld%ld%ld%ld",&w,&x,&y,&z);
    sum=x+y+z;
    if(w<sum)
        printf("Sad");
    else
        printf("Happy");
    return 0;
}
