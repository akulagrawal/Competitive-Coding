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
#define pii pair<ll,ll>

ll s1[MAX],s2[MAX],n,m;

ll gcd(ll a,ll b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}

pii func(int k)
{
    if(k==n)
        return mp(0,1);
    if(s1[k]!=0&&s2[k]!=0)
    {
        if(s1[k]<s2[k])
            return mp(0,1);
        else if(s1[k]>s2[k])
            return mp(1,1);
        return func(k+1);
    }
    else if(s2[k]!=0)
    {
        pii w=func(k+1);
        ll p=((m-s2[k])*w.s)+w.f;
        ll q=m*w.s;
        ll r=gcd(p,q);
        p/=r;
        q/=r;
        return mp(p%mod,q%mod);
    }
    else if(s1[k]!=0)
    {
        pii w=func(k+1);
        ll p=((s1[k]-1)*w.s)+w.f;
        ll q=m*w.s;
        ll r=gcd(p,q);
        p/=r;
        q/=r;
        return mp(p%mod,q%mod);
    }
    pii w=func(k+1);
    ll p=((m-1)*w.s)+2*w.f;
    ll q=2*m*w.s;
    ll r=gcd(p,q);
    p/=r;
    q/=r;
    return mp(p%mod,q%mod);
}

ll modInverse(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {
        // q is quotient
        ll q = a / m;
        ll t = m;

        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
       x += m0;

    return x;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i;
    ll p=0,q=0;
    cin>>n>>m;
    for(i=0;i<n;i++)
        cin>>s1[i];
    for(i=0;i<n;i++)
        cin>>s2[i];
    pii ans=func(0);
    cout<<((ans.f%mod)*modInverse(ans.s,mod))%mod;
    return 0;
}
