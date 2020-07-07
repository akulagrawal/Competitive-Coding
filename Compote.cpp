#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,sum;
    scanf("%d%d%d",&a,&b,&c);
    if(b>2*a)
        b=2*a;
    if(c>4*a)
        c=4*a;
    if(a>(b/2))
    {
        a=b/2;
        b=2*a;
    }
    if(c>4*a)
        c=4*a;
    if(a>(c/4))
    {
        a=c/4;
        c=4*a;
        b=2*a;
    }
    sum=a+b+c;
    printf("%d",sum);
    return 0;
}
