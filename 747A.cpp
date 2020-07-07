#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i,n,p,a,b;
    scanf("%d",&n);
    p=sqrt(n);
    for(i=p;i>=1;i--)
    {
        if(n%i==0)
            break;
    }
    a=i;
    b=n/i;
    printf("%d %d",a,b);
    return 0;
}
