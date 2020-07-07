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

struct seg{
    ll num;
    seg *l;
    seg *r;
};

seg* getnode()
{
    seg *ptr=new seg;
    ptr->l=NULL;
    ptr->r=NULL;
    ptr->num=0;
    return ptr;
}

void build(seg *&node,int l,int r)
{
    node=getnode();
    if(l==r)
    {
        node->num=0;
        return;
    }
    int mid=l+(r-l)/2;
    build(node->l,l,mid);
    build(node->r,mid+1,r);
    node->num=node->l->num+node->r->num;
}

void update(seg *&nodei,seg *node,int p,int l,int r)
{
    nodei=getnode();
    if(l==r)
    {
        nodei->num=1;
        return;
    }
    int mid=l+(r-l)/2;
    if(p<=mid)
    {
        update(nodei->l,node->l,p,l,mid);
        nodei->r=node->r;
    }
    else
    {
        update(nodei->r,node->r,p,mid+1,r);
        nodei->l=node->l;
    }
    nodei->num=nodei->l->num+nodei->r->num;
}

ll query(seg *node,int st,int en,int l,int r)
{
    if(st>r||en<l||node==NULL)
        return 0;
    if(st<=l&&en>=r)
        return node->num;
    int mid=l+(r-l)/2;
    return query(node->l,st,en,l,mid)+query(node->r,st,en,mid+1,r);
}

seg *r[MAX];
pii a[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,i,q,b,c,k,t;
    seg *root=NULL;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i].f);
        a[i].s=i;
    }
    sort(a,a+n,greater<pii>());
    build(root,0,n-1);
    update(r[0],root,a[0].s,0,n-1);
    for(i=1;i<n;i++)
        update(r[i],r[i-1],a[i].s,0,n-1);
    scanf("%lld",&q);
    ll ans=0;
    for(i=0;i<q;i++)
    {
        scanf("%lld%lld%lld",&b,&c,&k);
        b=b^ans;
        c=c^ans;
        k=k^ans;
        b--;
        c--;
        int l=0,h=n-1,mid;
        while(l<h)
        {
            mid=l+(h-l)/2;
            if(a[mid].f>k)
                l=mid+1;
            else
                h=mid;
        }
        mid=l+(h-l)/2;
        if(a[mid].f<=k)
            mid--;
        ans=query(r[mid],b,c,0,n-1);
        printf("%lld\n",ans);
    }
    return 0;
}
