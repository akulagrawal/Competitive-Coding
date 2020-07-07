#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t,n,i,m;
    long long sum;
    scanf("%d",&t);
    while(t--)
    {
        sum=(long long)0;
        scanf("%d",&n);
        for(i=1;i*i<n;i++)
        {
            if(n%i==0)
                sum+=((long long)i+(long long)(n/i));
        }
        if(i*i==n)
            sum+=(long long)i;
        sum-=(long long)n;
        printf("%lld\n",sum);
    }
    return 0;
}
