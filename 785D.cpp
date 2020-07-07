#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 200005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

ll fac[2*MAX];

void fact(int n)
{
    fac[0]=1;
    fac[1]=1;
    for(int i=2;i<=n;i++)
        fac[i]=(fac[i-1]*i)%mod;
}

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
        //power >>= 1;
    }
    return result;
}

int a[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    string s;
    int n,m=0,i,j=0,t=0;
    ll sum=0;
    cin>>s;
    n=s.size();
    for(i=0;i<n;i++)
    {
        if(s[i]==')')
            m++;
    }
    fact(n+m+1);
    for(i=0;i<n;i++)
    {
        if(s[i]=='('&&t<m)
        {
            a[j]=m-t;
            j++;
        }
        else
            t++;
    }
    m=j;
    ll x,y;
    for(i=0;i<m;i++)
    {
        x=fac[i+a[i]];
        y=(fac[i+1]*fac[a[i]-1])%mod;
        y=fast_pow(y,mod-2);
        sum=(sum+(x*y))%mod;
    }
    cout<<sum;
    return 0;
}
