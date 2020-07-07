#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 1000005
#define mod 1000000007
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

struct my{
    int lmax;
    int lval;
    int rmax;
    int rval;
    int maxm;
}tree[MAX];

int a[MAX];

void build(int node,int start,int end1)
{
    if(start==end1)
    {
        tree[node].lval=tree[node].rval=a[start];
        tree[node].lmax=tree[node].rmax=tree[node].maxm=1;
    }
    else
    {
        int mid=(start+end1)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end1);
        tree[node].lmax=tree[2*node].lmax;
        if((tree[2*node].lmax==mid-start+1)&&(tree[2*node].lval==tree[2*node+1].lval))
            tree[node].lmax+=tree[2*node+1].lmax;
        tree[node].lval=tree[2*node].lval;
        tree[node].rmax=tree[2*node+1].rmax;
        if((tree[2*node+1].rmax==end1-mid)&&(tree[2*node].rval==tree[2*node+1].rval))
            tree[node].rmax+=tree[2*node].rmax;
        tree[node].rval=tree[2*node+1].rval;
        tree[node].maxm=max(tree[node].lmax,tree[node].rmax);
        tree[node].maxm=max(tree[node].maxm,max(tree[2*node].maxm,tree[2*node+1].maxm));
        if(tree[2*node].rval==tree[2*node+1].lval)
            tree[node].maxm=max(tree[node].maxm,tree[2*node].rmax+tree[2*node+1].lmax);
    }
}

my query(int node,int start,int end1,int l,int r)
{
    my x={0,0,0,0,0};
    if(l>end1||r<start)
        return x;
    if(l<=start&&r>=end1)
        return tree[node];
    int mid=(start+end1)/2;
    my x1,x2;
    x1=query(2*node,start,mid,l,r);
    x2=query(2*node+1,mid+1,end1,l,r);
    x.lmax=x1.lmax;
    if((x1.lmax==mid-start+1)&&(x1.lval==x2.lval))
        x.lmax+=x2.lmax;
    x.lval=x1.lval;
    x.rmax=x2.rmax;
    if((x2.rmax==end1-mid)&&(x1.rval==x2.rval))
        x.rmax+=x1.rmax;
    x.rval=x2.rval;
    x.maxm=max(x.lmax,x.rmax);
    x.maxm=max(x.maxm,max(x1.maxm,x2.maxm));
    if(x1.rval==x2.lval)
        x.maxm=max(x.maxm,x1.rmax+x2.lmax);
    return x;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q,i,x,y,z=1;
    while(1)
    {
        scanf("%d",&n);
        if(!n)
            break;
        scanf("%d",&q);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        build(1,1,n);
        my t;
        while(q--)
        {
            scanf("%d%d",&x,&y);
            t=query(1,1,n,x,y);
            printf("%d\n",t.maxm);
        }
    }
    return 0;
}
