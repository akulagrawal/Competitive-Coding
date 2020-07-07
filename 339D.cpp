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

int a[MAX],tree[MAX];

void build(int node,int l,int r,bool v)
{
    if(l==r)
        tree[node]=a[l];
    else
    {
        int mid=l+(r-l)/2;
        build(2*node,l,mid,v^1);
        build(2*node+1,mid+1,r,v^1);
        if(v)
            tree[node]=tree[2*node]^tree[2*node+1];
        else
            tree[node]=tree[2*node]|tree[2*node+1];
    }
}

void update(int node,int n,int k,int l,int r,bool v)
{
    if(l==r)
        tree[node]=k;
    else
    {
        int mid=l+(r-l)/2;
        if(n<=mid)
            update(2*node,n,k,l,mid,v^1);
        else
            update(2*node+1,n,k,mid+1,r,v^1);
        if(v)
            tree[node]=tree[2*node]^tree[2*node+1];
        else
            tree[node]=tree[2*node]|tree[2*node+1];
    }
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,i,b,c,v=0;
    cin>>n>>m;
    if(n%2)
        v=1;
    n=pow(2,n);
    for(i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n,v^1);
    while(m--)
    {
        cin>>b>>c;
        update(1,b,c,1,n,v^1);
        cout<<tree[1]<<"\n";
    }
    return 0;
}
