#include<bits/stdc++.h>
#define MAXM 10000000

using namespace std;

long long f[MAXM+7];

void sieve(int n)
{
    for(int i=2;i<n;i++)
    {
        if(!f[i])
        {
            for(int j=2*i;j<n;j+=i)
            {
                if(!f[j])
                    f[j]=(long long)i;
            }
            f[i]=(long long)i;
        }
        f[i]+=f[i-1];
    }
}

int main()
{
    int t,n,i;
    sieve(MAXM);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%lld\n",f[n]);
    }
    return 0;
}
