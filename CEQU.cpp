#include<bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}

int main()
{
    int t,a,b,c,i,g;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        printf("Case %d: ",i);
        a=abs(a);
        b=abs(b);
        if(!a&&!b)
        {
            if(!c)
                printf("Yes\n");
            else
                printf("No\n");
            continue;
        }
        g=gcd(a,b);
        if(c%g==0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
