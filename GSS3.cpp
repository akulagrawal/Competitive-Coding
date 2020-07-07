#include<bits/stdc++.h>

using namespace std;

int A[50004];

struct segNode {
    int left,right,segsum,bestsum;
} tree[200005];

int max3(int a,int b,int c)
{
    int d=max(a,b);
    return max(d,c);
}

void merge2(segNode &node,segNode &cl, segNode &cr)
{
    node.left=max(cl.left,cl.segsum+cr.left);
    node.right=max(cr.right,cr.segsum+cl.right);
    node.segsum=cl.segsum+cr.segsum;
    node.bestsum=max3(cl.bestsum,cr.bestsum,cl.right+cr.left);
}

void build(int node,int start,int end1)
{
    if(start==end1)
        tree[node].left=tree[node].right=tree[node].segsum=tree[node].bestsum=A[start];
    else
    {
        int mid=(start+end1)/2;
        build(node*2,start,mid);
        build(node*2+1,mid+1,end1);
        merge2(tree[node],tree[node*2],tree[node*2+1]);
    }
}

void query(segNode &res,int node,int start,int end1,int l,int r)
{
    if(start==l&&end1==r)
        res=tree[node];
    else
    {
        int mid=(start+end1)/2;
        if(mid>=r)
            query(res,node*2,start,mid,l,r);
        else if(mid<l)
            query(res,node*2+1,mid+1,end1,l,r);
        else
        {
            segNode leftNode,rightNode;
            query(leftNode,node*2,start,mid,l,mid);
            query(rightNode,node*2+1,mid+1,end1,mid+1,r);
            merge2(res,leftNode,rightNode);
        }
    }
}

void update(int node,int start,int end1,int x,int y)
{
    if(start==end1)
        tree[node].left=tree[node].right=tree[node].segsum=tree[node].bestsum=y;
    else
    {
        int mid=(start+end1)/2;
        if(mid>=x)
            update(2*node,start,mid,x,y);
        else
            update(2*node+1,mid+1,end1,x,y);
        merge2(tree[node],tree[2*node],tree[2*node+1]);
    }
}

int main()
{
    int n,m,d,l,r;
    segNode ans;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&A[i]);
    build(1,1,n);
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d%d%d",&d,&l,&r);
        if(d)
        {
            query(ans,1,1,n,l,r);
            printf("%d\n",ans.bestsum);
        }
        else
            update(1,1,n,l,r);
    }
    return 0;
}
