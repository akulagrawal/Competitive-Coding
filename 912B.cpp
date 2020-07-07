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

long long fast_pow(ll a,ll n)
{
    long long result = 1;
    long long power = n;
    long long value = a;
    while(power>0)
    {
        if(power&1)
            {result = result*value;}
        value = value*value;
        power /= 2;
        //power >>= 1;
    }
    return result;
}

int f(ll n)
{
    int a=0;
    while(n)
    {
        n/=2;
        a++;
    }
    return a;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    if(k==1)
        cout<<n;
    else
    {
        ll p=f(n);
        ll q=fast_pow(2,p);
        cout<<q-1;
    }
    return 0;
}
