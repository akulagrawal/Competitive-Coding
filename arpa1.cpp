#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    long n;
    scanf("%ld",&n);
    if(n==0)
        printf("1");
    else if(n%4==1)
        printf("8");
    else if(n%4==2)
        printf("4");
    else if(n%4==3)
        printf("2");
    else
        printf("6");
    return 0;
}
