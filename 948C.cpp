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

ll v[MAX],t[MAX];
ll a[MAX],b[MAX];

ll BIT[MAX], k;
void update(ll x, ll delta)
{
for(; x <= k; x += x&-x)
BIT[x] += delta;
}
ll query(ll x)
{
ll sum = 0;
for(; x > 0; x -= x&-x)
sum += BIT[x];
return sum;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    k=n;
    int i;
    for(i=0;i<n;i++)
        cin>>v[i];
    for(i=0;i<n;i++)
        cin>>t[i];
    a[0]=t[0];
    for(i=1;i<n;i++)
        a[i]=a[i-1]+t[i];
    for(i=0;i<n;i++)
    {
        int l=i;
        int r=n-1;
        int m=l+(r-l)/2;
        while(l<r)
        {
            m=l+(r-l)/2;
            if((a[m]-a[i-1])>v[i])
                r=m;
            else
                l=m+1;
        }
        m=l+(r-l)/2;
        while((m>i)&&((a[m]-a[i-1])>v[i]))
            m--;
        if(v[i]>(a[m]-a[i-1]))
            b[m+1]+=v[i]-a[m]+a[i-1];
        if((i==m)&&(v[i]<t[i]))
            b[m]+=v[i];
        else
        {
            update(i+1, 1);
            update(m+2, -1);
        }
    }
    for(i=0;i<n;i++)
        cout<<(query(i+1))*t[i]+b[i]<<" ";
    return 0;
}
