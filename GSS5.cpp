#include<bits/stdc++.h>

using namespace std;

int A[50004];

struct segNode {
    long left,right,segsum,bestsum;
} tree[200005];

long max3(long a,long b,long c)
{
    long d=max(a,b);
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
        tree[node].left=tree[node].right=tree[node].segsum=tree[node].bestsum=(long)A[start];
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

int main()
{
    int n,m,x1,y1,x2,y2,t;
    long a1,a2,a3,a;
    segNode ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&A[i]);
        build(1,1,n);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(y1<=x2)
            {
                query(ans,1,1,n,x1,y1);
                a=ans.right;
                query(ans,1,1,n,y1,x2);
                a+=ans.segsum;
                query(ans,1,1,n,x2,y2);
                a+=ans.left;
                a-=(A[y1]+A[x2]);
            }
            else
            {
                query(ans,1,1,n,x1,x2);
                a1=ans.right;
                query(ans,1,1,n,x2,y2);
                a1+=ans.left;
                query(ans,1,1,n,x1,y1);
                a2=ans.right;
                query(ans,1,1,n,y1,y2);
                a2+=ans.left;
                query(ans,1,1,n,x2,y1);
                a3=ans.bestsum;
                a1-=A[x2];
                a2-=A[y1];
                a=max3(a1,a2,a3);
            }
            printf("%ld\n",a);
        }
    }
    return 0;
}
