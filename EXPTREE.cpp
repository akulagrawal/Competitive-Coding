#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 1000006
#define mod1 1000000007
#define mod2 1000000009
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

long long fast_pow(ll a,ll n,ll rem)
{
    long long result = 1;
    long long power = n;
    long long value = a;
    while(power>0)
    {
        if(power&1)
            {result = result*value;
            result = result%rem;}
        value = value*value;
        value = value%rem;
        power /= 2;
    }
    return result;
}

int main()
{
    int t,i;
    ll n,p,q,r,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        n--;
        m=n%mod1;
        p=(m*(m+1))/2;
        q=(2*n-1)%mod1;
        p=p%mod1;
        printf("%lld ",(p*fast_pow(q,mod1-2,mod1))%mod1);
        m=n%mod2;
        p=(m*(m+1))/2;
        p=p%mod2;
        q=(2*n-1)%mod2;
        printf("%lld\n",(p*fast_pow(q,mod2-2,mod2)%mod2));
    }
    return 0;
}
