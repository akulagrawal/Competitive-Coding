#include<bits/stdc++.h>
#define gc getchar_unlocked

using namespace std;

long long phi[1000006];
long long ret[1000006];

void totient(int n)
{
    for(int i=1;i<=n;i++)
        phi[i]=i;
    for(int p=2;p<=n;p++)
    {
        if(phi[p]==p)
        {
            phi[p]=p-1;
            for(int i=2*p;i<=n;i+=p)
            {
                phi[i]/=p;
                phi[i]*=(p-1);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j+=i)
            ret[j]+=i*phi[i];
    }
}

int main()
{
    long long sum;
    int t,j,i,n;
    totient(1000000);
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d",&n);
        sum=(1+ret[n])*n/2;
        printf("%lld\n",sum);
    }
    return 0;
}
