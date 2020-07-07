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

ll modInverse(ll a, ll m)
{
    a = a%m;
    for (ll x=1; x<m; x++)
       if ((a*x) % m == 1)
          return x;
}

long long fast_pow(ll a,ll n,ll p)
{
    long long result = 1;
    long long power = n;
    long long value = a;
    while(power>0)
    {
        if(power&1)
            {result = result*value;
            result = result%p;}
        value = value*value;
        value = value%p;
        power /= 2;
        //power >>= 1;
    }
    return result;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,p,x;
    cin>>a>>b>>p>>x;
    ll j;
    ll y;
    ll sum=0;
    for(j=0;j<p-1;j++)
    {
        y=fast_pow(a,j,p);
        y=modInverse(y,p);
        y=(y*b)%p;
        ll z,i;
        for(i=0;i<p-1;i++)
        {
            z=i*p+y;
            if(z>x)
                break;
            if(z%(p-1)==j)
            {
                sum++;
                break;
            }
        }
        if(i<p-1)
            sum+=(x-j)/(p*(p-1));
    }
    cout<<sum;
    return 0;
}
