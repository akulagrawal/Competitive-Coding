#include<iostream>
#include<stdio.h>
#include<math.h>
#define REM 1000000007
using namespace std;
/*
long long fast_pow(int a,int n)
{
    long long result = 1;
    long long power = n;
    long long value = a;
    while(power>0)
    {
        if(power&1)
        {
            result = result*value;
            result = result%1000000007;
        }
        value = value*value;
        value = value%1000000007;
        power /= 2;
    }
    return result;
}
*/
int main()
{
    int t;
    long long n,res,val;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        if(n==1)
            printf("0\n");
        else
        {
            res=1;
            val=2;
            n--;
            while(n)
            {
                if(n%2==1)
                    res=(res*val)%REM;
                val=(val*val)%REM;
                n/=2;
            }
            res-=2;
            printf("%lld\n",res);
        }
    }
    return 0;
}
