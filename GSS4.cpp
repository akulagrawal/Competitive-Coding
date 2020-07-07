#include<bits/stdc++.h>

using namespace std;

long long A[100005],tree[400005];

void build(int node, int start, int end1)
{
    if(start == end1)
        tree[node] = A[start];
    else
    {
        int mid = (start + end1) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end1);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void updateRange(int node, int start, int end1, int l,int r)
{
    if(start>end1||start>r||end1<l)
        return;
    if(tree[node]==(long long)end1-(long long)start+(long long)1)
        return;
    if(start==end1)
    {
        tree[node]=sqrt(tree[node]);
        return;
    }
    int mid=(start+end1)/2;
    updateRange(node*2,start,mid,l,r);
    updateRange(node*2+1,mid+1,end1,l,r);
    tree[node] = tree[node*2] + tree[node*2+1];
}

long long queryRange(int node, int start, int end1, int l, int r)
{
    if(start > end1 or start > r or end1 < l)
        return 0;
    if(start >= l and end1 <= r)
        return tree[node];
    int mid = (start + end1) / 2;
    long long p1 = queryRange(node*2, start, mid, l, r);
    long long p2 = queryRange(node*2 + 1, mid + 1, end1, l, r);
    return (p1 + p2);
}

int main()
{
    int n,i,m,d,x,y,t=0;
    long long sum;
    while(scanf("%d",&n)!=EOF)
    {
        t++;
        for(i=1;i<=n;i++)
            scanf("%lld",&A[i]);
        build(1,1,n);
        scanf("%d",&m);
        printf("Case #%d:\n",t);
        while(m--)
        {
            scanf("%d%d%d",&d,&x,&y);
            if(x>y)
            {
                int temp=x;
                x=y;
                y=temp;
            }
            if(d)
            {
                sum=queryRange(1,1,n,x,y);
                printf("%lld\n",sum);
            }
            else
            {
                updateRange(1,1,n,x,y);
            }
        }
    }
    return 0;
}
