#include<bits/stdc++.h>
using namespace std;

#define MAX 100005

struct bst{                 // structure for a node of binary search tree. An extra variable f to store the frequency of num
    int num;
    int f;
    bst *l;
    bst *r;
};

bst* getbst(int n,int m)        // function that initializes allocates memory to a node of bst and with num=n and f=m
{
    bst *temp=NULL;
    temp=new bst;
    temp->l=temp->r=NULL;
    temp->num=n;
    temp->f=m;
    return temp;
}

bool comp(bst *x,bst *y)            // compare which one is to be printed first
{
    if(x->f<y->f)
        return 0;
    else if(x->f==y->f&&x->num>y->num)
        return 0;
    return 1;
}

bst* bst_insert(bst *root,int a[],int freq[],int n)     // insert element with num=a[n] and f=freq[a[n]] into bst
{
    if(!freq[a[n]])                 // number of element should occur more than once
        return root;
    bst *x=root,*y=NULL, *z=getbst(a[n],freq[a[n]]);
    if(x==NULL)
    {
        root=z;
        freq[a[n]]=0;
        return root;
    }
    while(x!=NULL)
    {
        y=x;
        if(comp(x,z))               // compare using comp() function above as required in question
            x=x->r;
        else
            x=x->l;
    }
    if(comp(y,z))
        y->r=z;
    else
        y->l=z;
    freq[a[n]]=0;       // since a[n] and it's frequency (which thus, includes all occurrences) has been included, set it's freq as 0
    return root;
}

void print(bst *root)           // print the elements in sorted order according to comp() function (inorder traversal)
{
    if(root==NULL)
        return;
    print(root->l);
    while(root->f--)                // print num f times
        cout<<root->num<<" ";
    print(root->r);
}

int main()
{
    int n,i;
    int a[MAX],freq[MAX];
    bst *root=NULL;
    memset(freq,0,sizeof(freq));            // initialize freq[] of every element to be 0
    cout<<"Enter size of sequence n followed by n integers\n";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        freq[a[i]]++;
    }
    for(i=0;i<n;i++)
        root=bst_insert(root,a,freq,i);
    print(root);
    return 0;
}
