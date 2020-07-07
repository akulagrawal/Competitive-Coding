#include<bits/stdc++.h>

using namespace std;

int tree[400005];
bool lazy[400005];

void toggle(bool &a)
{
    if(a)
        a=0;
    else
        a=1;
}

void updateRange(int node, int start, int end1, int l, int r, int val)
{
    if(lazy[node] != 0)
    {
        tree[node] = (end1 - start + 1) - tree[node];
        if(start != end1)
        {
            toggle(lazy[node*2]);
            toggle(lazy[node*2+1]);
        }
        lazy[node] = 0;
    }
    if(start > end1 or start > r or end1 < l)
        return;
    if(start >= l and end1 <= r)
    {
        tree[node] = (end1 - start + 1) - tree[node];
        if(start != end1)
        {
            toggle(lazy[node*2]);
            toggle(lazy[node*2+1]);
        }
        return;
    }
    int mid = (start + end1) / 2;
    updateRange(node*2, start, mid, l, r, val);
    updateRange(node*2 + 1, mid + 1, end1, l, r, val);
    tree[node] = tree[node*2] + tree[node*2+1];
}

int queryRange(int node, int start, int end1, int l, int r)
{
    if(start > end1 or start > r or end1 < l)
        return 0;
    if(lazy[node] != 0)
    {
        tree[node] = (end1 - start + 1) - tree[node];
        if(start != end1)
        {
            toggle(lazy[node*2]);
            toggle(lazy[node*2+1]);
        }
        lazy[node] = 0;
    }
    if(start >= l and end1 <= r)
        return tree[node];
    int mid = (start + end1) / 2;
    int p1 = queryRange(node*2, start, mid, l, r);
    int p2 = queryRange(node*2 + 1, mid + 1, end1, l, r);
    return (p1 + p2);
}

int main()
{
    int n,m,d,l,r,ans;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        scanf("%d%d%d",&d,&l,&r);
        if(d==0)
            updateRange(1,1,n,l,r,1);
        else
        {
            ans=queryRange(1,1,n,l,r);
            printf("%d\n",ans);
        }
    }
    return 0;
}
