#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,c,t,ans;
    long b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%ld",&a,&b);
        if(b!=0)
        {
            c=b%100;
            c=c%4;
            if(!c)
                c=4;
        }
        else
            c=0;
        a=a%10;
        ans=pow(a,c);
        ans=ans%10;
        printf("%d\n",ans);
    }
    return 0;
}
