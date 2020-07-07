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

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k,ans=0,p=0;
    cin>>n;
    int t=50;
    while(t--)
    {
        k=fast_pow(2,t);
        if(n>=k)
        {
            n-=k;
            ans+=(ll)t*(k/2);
            ans++;
            ans+=(k*p);
            p++;
        }
    }
    cout<<ans;
    return 0;
}
