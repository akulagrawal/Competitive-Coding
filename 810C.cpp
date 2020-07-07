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

ll a[MAX];

bool cmp(ll a,ll b)
{
    return a>b;
}

ll power(ll x,ll y)
{
    ll temp;
    if( y == 0)
        return (long long)1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return (temp*temp)%mod;
    else
        return (x*temp*temp)%mod;

}
int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,i;
    cin>>n;

    for(i=0;i<n;i++)
       cin>>a[i];

    sort(a,a+n,cmp);
    ll ans=0,x=n-1;

    for(i=0;i<n-1;i++)
    {
       ans=(ans+ (a[i]*(power(2,x)-1+mod)%mod) %mod)%mod;
       ans = (ans - (a[n-1-i]*(power(2,x)-1+mod)%mod)%mod+mod) %mod;
       x--;
    }

    cout<<ans<<endl;

    return 0;
}
