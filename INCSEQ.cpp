#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 1000006
#define MAX2 100005
#define mod 5000000
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

int a[MAX],n;
ll tree[55][MAX];

void update(int x,unsigned ll delta,int k)
{
    for(;x<=MAX2;x+=x&-x)
        tree[k][x]=(tree[k][x]+delta)%mod;
}

ll sum(int x,int k)
{
    ll val=0;
    for(;x>0;x-=x&-x)
        val=(val+tree[k][x])%5000000;
    return val;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k,i,j;
    ll p1;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i]+=1;
    }
    for(i=1;i<=n;i++)
    {
        update(a[i],1,1);
        for(j=2;j<=k;j++)
        {
            p1=sum(a[i]-1,j-1);
            update(a[i],p1,j);
        }
    }
    p1=sum(MAX2,k);
    printf("%lld",p1);
    return 0;
}
