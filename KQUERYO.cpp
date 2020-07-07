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

int a[MAX];
vector<int> tree[MAX];

void merge1(int x,int y,int z)
{
    int i,j=0;
    for(i=0;i<tree[y].size();i++)
    {
        while(j<tree[z].size()&&(tree[z][j]<=tree[y][i]))
        {
            tree[x].pb(tree[z][j]);
            j++;
        }
        tree[x].pb(tree[y][i]);
    }
    while(j<tree[z].size())
    {
        tree[x].pb(tree[z][j]);
        j++;
    }
}

void build(int node,int l,int r)
{
    if(l==r)
        tree[node].pb(a[l]);
    else
    {
        int mid=l+(r-l)/2;
        build(2*node,l,mid);
        build(2*node+1,mid+1,r);
        merge1(node,2*node,2*node+1);
    }
}

int func(int node,int k)
{
    int n=tree[node].size();
    int low=0,mid,high=n-1;
    while(low<high)
    {
        mid=low+(high-low)/2;
        if(tree[node][mid]<=k)
            low=mid+1;
        else
            high=mid;
    }
    mid=low+(high-low)/2;
    if(tree[node][mid]<=k)
        mid+=1;
    return n-mid;
}

int query(int node,int start,int end1,int l,int r,int k)
{
    if(r<start||l>end1)
        return 0;
    if(l<=start&&r>=end1)
        return func(node,k);
    int mid=start+(end1-start)/2;
    return query(2*node,start,mid,l,r,k)+query(2*node+1,mid+1,end1,l,r,k);
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q,i,x,y,z,ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    build(1,0,n-1);
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d%d",&x,&y,&z);
        x=x^ans;
        y=y^ans;
        z=z^ans;
        ans=query(1,0,n-1,x-1,y-1,z);
        printf("%d\n",ans);
    }
    return 0;
}
