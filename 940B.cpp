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

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k,a,b;
    cin>>n>>k>>a>>b;
    ll ans=0;
    if(k==1)
    {
        cout<<(n-1)*a;
        return 0;
    }
    while(n>1)
    {
        ll p=n/k;
        p*=k;
        if(p==0)
        {
            ans+=(n-1)*a;
            break;
        }
        ans+=(n-p)*a;
        n=p;
        p/=k;
        if((n-p)*a>b)
        {
            ans+=b;
            n=p;
        }
        else
        {
            ans+=(n-1)*a;
            break;
        }
    }
    cout<<ans;
    return 0;
}
