#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left,*right;
};

node *newnode(int n)
{
    node *temp=new node;
    temp->data=n;
    temp->left=temp->right=NULL;
    return temp;
}
//int res=0;
int maxsum(node *root,int &res)
{
    int l=0,r=0;
    if(root==NULL)
         return 0;
    l=maxsum(root->left,res);
    r=maxsum(root->right,res);

    int maxsingle=max(max(l,r)+root->data,root->data);
    int maxtop=max(maxsingle,l+r+root->data);
    res=max(res,maxtop);
    return maxsingle;
}
int main()
{
    node *root=newnode(1);
    root->left=newnode(-1);
    root->right=newnode(2);
    root->left->left=newnode(2);
    root->left->right=newnode(3);
    root->right->left=newnode(5);
    root->right->right=newnode(6);

    int res=0;
    int sum=maxsum(root,res);
    cout<<res<<endl;
    return 0;
}
