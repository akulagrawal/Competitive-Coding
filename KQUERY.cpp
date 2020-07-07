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
pii x[MAX],y[MAX];
pair<ll,int> z[MAX];
int ans[MAX],s[MAX];

void build(int node,int l,int r)
{
    if(l==r)
        s[node]=1;
    else
    {
        int mid=l+(r-l)/2;
        build(2*node,l,mid);
        build(2*node+1,mid+1,r);
        s[node]=s[2*node]+s[2*node+1];
    }
}

void update(int node,int l,int r,int p)
{
    if(l==r)
        s[node]=0;
    else
    {
        int mid=l+(r-l)/2;
        if(l<=p&&p<=mid)
            update(2*node,l,mid,p);
        else
            update(2*node+1,mid+1,r,p);
        s[node]=s[2*node]+s[2*node+1];
    }
}

int query(int node,int l,int r,int lq,int rq)
{
    if(lq>r||rq<l)
        return 0;
    if(lq<=l&&rq>=r)
        return s[node];
    int mid=l+(r-l)/2;
    return query(2*node,l,mid,lq,rq)+query(2*node+1,mid+1,r,lq,rq);
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,q,b,c,k,t;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        z[i]=mp(a[i],i);
    }
    sort(z,z+n);
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d%d%d",&b,&c,&k);
        x[i]=mp(b,c);
        y[i]=mp(k,i);
    }
    sort(y,y+q);
    t=0;
    build(1,0,n-1);
    for(i=0;i<q;i++)
    {
        b=y[i].s;
        while(t<n&&a[z[t].s]<=y[i].f)
        {
            update(1,0,n-1,z[t].s);
            t++;
        }
        ans[b]=query(1,0,n-1,x[b].f-1,x[b].s-1);
    }
    for(i=0;i<q;i++)
        printf("%d\n",ans[i]);
    return 0;
}
