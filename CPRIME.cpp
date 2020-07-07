#include<bits/stdc++.h>
#define MAX 100000000

using namespace std;

bitset<MAX+1> prime;
int primes[MAX+1];

void sieve()
{
    for(int i=3;i<=sqrt(MAX);i+=2)
    {
        if(!prime[i])
        {
            for(int j=i*i;j<=MAX;j+=2*i)
                prime[j]=1;
        }
    }
}

int main()
{
    int x,i;
    double ans;
    sieve();
    primes[2]=1;
    for(i=3;i<=MAX;i++)
    {
        if(!prime[i]&&i%2)
            primes[i]=primes[i-1]+1;
        else
            primes[i]=primes[i-1];
    }
    while(1)
    {
        scanf("%d",&x);
        if(!x)
            break;
        ans=(double)x;
        ans/=log(x);
        ans-=(double)primes[x];
        ans=(double)abs(ans);
        ans/=(double)primes[x];
        ans*=100;
        printf("%.1lf\n",ans);
    }
    return 0;
}
