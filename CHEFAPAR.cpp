#include<bits/stdc++.h>

using namespace std;

int a[100005];

int main()
{
    int t,n,i,p,num;
    long ans;
    scanf("%d",&t);
    while(t--)
    {
        p=0;
        num=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(!p&&!a[i])
                p=i;
            if(!a[i])
                num++;
        }
        ans=(long)num;
        ans*=1000;
        if(p)
            ans+=100*(long)(n-p+1);
        printf("%ld\n",ans);
    }
    return 0;
}
