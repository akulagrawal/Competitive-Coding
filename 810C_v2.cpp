#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 1000006
#define mod 1000000007
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

ll x[MAX],y[MAX];

long long fast_pow(int a,int n)
{
    long long result = 1;
    long long power = n;
    long long value = a;
    while(power>0)
    {
        if(power&1)
            {result = result*value;
            result = result%1000000007;}
        value = value*value;
        value = value%1000000007;
        power /= 2;
    }
    return result;
}

ll func(ll n)
{
    return (fast_pow(2,n-1)+mod-n)%mod;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i;
    ll ans=0,t=0;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>x[i];
    sort(x,x+n);
    for(i=0;i<n-1;i++)
        y[i]=x[i+1]-x[i];
    for(i=0;i<n;i++)
    {
        t=fast_pow(2,n-i-1)-1;
        t=(t*(x[n-1]-x[i]))%mod;
        ans=(ans+t)%mod;
    }
    for(i=n-2;i>0;i--)
    {
        t=(func(i+2)*y[i])%mod;
        ans=(ans+mod-t)%mod;
    }
    cout<<ans;
    return 0;
}
