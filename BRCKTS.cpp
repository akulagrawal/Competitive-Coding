#include<bits/stdc++.h>

using namespace std;

struct my{
    int left, right;
}tree[120004];

string A;

void build(int node,int start,int end1)
{
    if(start==end1)
    {
        if(A[start-1]=='(')
        {
            tree[node].left=1;
            tree[node].right=0;
        }
        else
        {
            tree[node].right=1;
            tree[node].left=0;
        }
    }
    else
    {
        int mid=(start+end1)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end1);
        int minm=min(tree[2*node].left,tree[2*node+1].right);
        tree[node].left=tree[2*node].left+tree[2*node+1].left-minm;
        tree[node].right=tree[2*node].right+tree[2*node+1].right-minm;
    }
}

void query(my &tnode,int node,int start,int end1,int l,int r)
{
    if(start==l&&end1==r)
        tnode=tree[node];
    else
    {
        int mid=(start+end1)/2;
        if(mid>=r)
            query(tnode,2*node,start,mid,l,r);
        else if(mid<l)
            query(tnode,2*node+1,mid+1,end1,l,r);
        else
        {
            my tnode1,tnode2;
            query(tnode1,2*node,start,mid,l,mid);
            query(tnode2,2*node+1,mid+1,end1,mid+1,r);
            int minm=min(tnode1.left,tnode2.right);
            tnode.left=tnode1.left+tnode2.left-minm;
            tnode.right=tnode1.right+tnode2.right-minm;
        }
    }
}

void update(int node,int start,int end1,int i)
{
    if(start==end1)
    {
        if(tree[node].left==1)
        {
            tree[node].left=0;
            tree[node].right=1;
        }
        else
        {
            tree[node].left=1;
            tree[node].right=0;
        }
    }
    else
    {
        int mid=(start+end1)/2;
        if(mid>=i)
            update(2*node,start,mid,i);
        else
            update(2*node+1,mid+1,end1,i);
        int minm=min(tree[2*node].left,tree[2*node+1].right);
        tree[node].left=tree[2*node].left+tree[2*node+1].left-minm;
        tree[node].right=tree[2*node].right+tree[2*node+1].right-minm;
    }
}

int main()
{
    int n,m,k;
    for(int i=1;i<=10;i++)
    {
        cin>>n>>A>>m;
        build(1,1,n);
        cout<<"Test "<<i<<":\n";
        while(m--)
        {
            cin>>k;
            if(!k)
            {
                my node;
                query(node,1,1,n,1,n);
                if(node.left==0&&node.right==0)
                    cout<<"YES\n";
                else
                    cout<<"NO\n";
            }
            else
                update(1,1,n,k);
        }
    }
    return 0;
}
