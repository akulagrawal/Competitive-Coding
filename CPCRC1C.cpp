#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 100005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

ll sumdig(int n)
{
    return (ll)n*(ll)pow(10,n-1)*45;
}

long long fast_pow(int a,int n)
{
    long long result = 1;
    long long power = n;
    long long value = a;
    while(power>0)
    {
        if(power&1)
            result = result*value;
        value = value*value;
        power /= 2;
    }
    return result;
}

ll sum(ll n)
{
    ll ans=0,temp=1;
    int i,x,m;
    for(i=0;;i++)
    {
        if(n<temp)
            break;
        temp*=10;
    }
    m=i;
    if(n<=0)
        return 0;
    if(m<2)
        return (n*(n+1))/2;
    temp=fast_pow(10,m-1);
    x=n/temp;
    n=n%temp;
    ans+=(((ll)(x)*(ll)(x-1))/2)*temp;
    ans+=(ll)x*sumdig(m-1);
    ans+=((ll)x*(n+1))+sum(n);
    return ans;
}

int main()
{
    ll a,b,ans;
    while(1)
    {
        ans=0;
        scanf("%lld%lld",&a,&b);
        if(a==-1)
            break;
        printf("%lld\n",sum(b)-sum(a-1));
    }
    return 0;
}
