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

pair<ll,int> t[MAX];
ll s[MAX];

int tree[MAX],lazy[MAX];

void build(int node, int start, int end1)
{
    if(start == end1)
    {
        // Leaf node will have a single element
        tree[node] = t[start].s;
    }
    else
    {
        int mid = (start + end1) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end1);
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void updateRange(int node, int start, int end1, int l, int r, int val)
{
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (end1 - start + 1) * lazy[node]; // Update it
        if(start != end1)
        {
            lazy[node*2] += lazy[node]; // Mark child as lazy
            lazy[node*2+1] += lazy[node]; // Mark child as lazy
        }
        lazy[node] = 0; // Reset it
    }
    if(start > end1 or start > r or end1 < l) // Current segment is not within range [l, r]
        return;
    if(start >= l and end1 <= r)
    {
        // Segment is fully within range
        tree[node] += (end1 - start + 1) * val;
        if(start != end1)
        {
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start + end1) / 2;
    updateRange(node*2, start, mid, l, r, val); // Updating left child
    updateRange(node*2 + 1, mid + 1, end1, l, r, val); // Updating right child
    tree[node] = tree[node*2] + tree[node*2+1]; // Updating root with max value
}

int queryRange(int node, int start, int end1, int l, int r)
{
    if(start > end1 or start > r or end1 < l)
        return 0; // Out of range
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (end1 - start + 1) * lazy[node]; // Update it
        if(start != end1)
        {
            lazy[node*2] += lazy[node]; // Mark child as lazy
            lazy[node*2+1] += lazy[node]; // Mark child as lazy
        }
        lazy[node] = 0; // Reset it
    }
    if(start >= l and end1 <= r) // Current segment is totally within range [l, r]
        return tree[node];
    int mid = (start + end1) / 2;
    int p1 = queryRange(node*2, start, mid, l, r); // Query left child
    int p2 = queryRange(node*2 + 1, mid + 1, end1, l, r); // Query right child
    return (p1 + p2);
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,m;
    ll ans=0,p;
    scanf("%d",&n);
    m=n;
    for(i=0;i<n;i++)
    {
        scanf("%lld",&t[i].f);
        t[i].s=i;
    }
    build(1,0,n-1);
    stable_sort(t,t+n);
    i=0;
    while(n)
    {
        p=t[i].f;
        if(!ans)
            ans=(ll)n*(t[i].f-1)+(ll)t[i].s+1;
        else
            ans+=(ll)n*(t[i].f-t[i-1].f)-(ll)queryRange(1,0,m-1,t[i-1].s,t[i-1].s)+(ll)queryRange(1,0,m-1,t[i].s,t[i].s);
        while(i<m)
        {
            s[t[i].s]=ans;
            i++;
            n--;
            updateRange(1,0,m-1,t[i-1].s,m-1,-1);
            if(t[i].f!=p)
                break;
            if(i<m)
                ans+=((ll)queryRange(1,0,m-1,t[i].s,t[i].s)-(ll)queryRange(1,0,m-1,t[i-1].s,t[i-1].s));
        }
    }
    for(i=0;i<m;i++)
        printf("%lld\n",s[i]);
    return 0;
}
