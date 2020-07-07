#include<bits/stdc++.h>
using namespace std;

struct bst{                     // structure for implementing binary search tree
    int num;
    bst *l;
    bst *r;
};

struct stk{                 // structure for a stack of bst nodes
    bst *data;
    stk *ptr;
};

bst* getbst(int n)      // initialize and allocate memory to a bst node with value n
{
    bst *temp=NULL;
    temp=new bst;
    temp->l=temp->r=NULL;
    temp->num=n;
    return temp;
}

stk* getstk(bst *x)     // initialize and allocate memory to a stack node with bst node x
{
    stk *temp=NULL;
    temp=new stk;
    temp->data=x;
    temp->ptr=NULL;
    return temp;
}

stk* push(stk *s,bst *x)        // push in stack s, bst node x
{
    stk *temp=NULL;
    temp=getstk(x);
    temp->ptr=s;
    return s=temp;
}

stk* pop(stk *s)        // pop from stack s
{
    if(s==NULL)
	return s;
    stk *temp=s;
    s=s->ptr;
    delete(temp);
    return s;
}

void swap(int &a,int &b)    // swap two integers a and b
{
    int temp=a;
    a=b;
    b=temp;
}

void b_init(int a[],int b[],int n)       // copy b[] to a[]
{
    for(int i=0;i<n;i++)
        a[i]=b[i];
}

bst* build(bst *root,int a[],int n)     // function to build a binary search tree from a given preorder traversal a[] and return root
{                                       // preorder is order root->left->right. Thus, if inserting in right begins, we will never insert in parent or left child
    int i;
    stk *s=NULL;                // stores path of nodes from current node to highest possible position according to preorder property mentioned above
    bst *temp=NULL;
    root=getbst(a[0]);          // 1st element of preorder traversal is always the root
    s=push(s,root);             // push root in stack
    for(i=1;i<n;i++)
    {
        temp=NULL;
        while(s!=NULL&&a[i]>s->data->num)   // pop till next element of preorder is greater than num of top node in stack
        {
            temp=s->data;       // temp stores the bst node popped
            s=pop(s);
        }
        if(temp==NULL)          // if a[i] was less than num of top node of stack, make it left child of top
        {
            s->data->l=getbst(a[i]);
            s=push(s,s->data->l);
        }
        else            // else make it right child. Once making right child, we never go to left child or parent again (as already popped)
        {
            temp->r=getbst(a[i]);
            s=push(s,temp->r);
        }
    }
    return root;
}

bst* bst_insert(bst *root,int n)        // normal insert function in bst a node with value n
{
    bst *x=root,*y=NULL, *z=getbst(n);
    if(x==NULL)
    {
        root=z;
        return root;
    }
    while(x!=NULL)
    {
        y=x;
        if(x->num<n)        //if greater than parent, go to right
            x=x->r;
        else                // else go to left
            x=x->l;
    }
    if(y->num<n)
        y->r=z;
    else
        y->l=z;
    return root;
}

bool perm(int a[],int n)            // function to generate next lexicographical permutation of array a[]
{
    int i,j;
    for(i=n-2;i>=0;i--)
    {
        if(a[i]<a[i+1])
            break;
    }                       // now i stores greatest index such that a[k]<a[k+1]
    if(i<0)
        return 0;
    for(j=n-1;j>i;j--)
        if(a[j]>a[i])
            break;          // j is greatest index such that a[k]>a[i]
    swap(a[i],a[j]);        // swap a[i] and a[j] and reverse array from index i+1 to last
    for(j=i+1;j<=(n+i)/2;j++)
        swap(a[j],a[n+i-j]);
    return 1;
}

bool check(bst *root,bst *temp)             // function to check if two trees are identical. It returns 1 if they are identical, else 0
{
    if(root==NULL&&temp==NULL)      // if corresponding nodes of both are NULL, return 1
        return 1;
    if(root!=NULL&&temp!=NULL)
    {
        bool p1=0,p2=0,p3=0;
        if(root->num==temp->num)
            p1=1;
        p2=check(root->l,temp->l);
        p3=check(root->r,temp->r);
        return (p1&&p2&&p3);        // identical only if num is same and left and right children are also identical
    }
    return 0;               // if one is null and other is non-null, they can't be identical
}

void printseq(bst *root,int b[],int n)          // function to print required sequence
{
    bool p;
    int cnt=0;
    int a[n+1];
    b_init(a,b,n);         // store preorder traversal order in a[] which is lexicographically minimum sequence of inserting nodes
    do{
        bst *temp=NULL;
        for(int i=0;i<n;i++)
            temp=bst_insert(temp,a[i]);
        if(check(root,temp))        // for all permutations in lexicographical increasing order, if two trees are identical, increase the count(=cnt)
            cnt++;
        p=perm(a+1,n-1);        // root remains same
    }while(p==1);
    b_init(a,b,n);
    cout<<cnt<<endl;        // print count
    do{
        bst *temp=NULL;
        for(int i=0;i<n;i++)
            temp=bst_insert(temp,a[i]);
        if(check(root,temp))        // for all permutations in lexicographical increasing order, if two trees are identical, print the sequence
        {
            for(int i=0;i<n;i++)
                cout<<a[i]<<" ";
            cout<<endl;
        }
        p=perm(a,n);
    }while(p==1);
}

int main()
{
    freopen ("output22.txt","w",stdout);
    int n,i;
    bst *root=NULL;
    cout<<"Enter number of keys in BST followed by n integer values of n keys\n";
    cin>>n;
    int a[n+1];
    for(i=0;i<n;i++)
        cin>>a[i];
    root=build(root,a,n);
    printseq(root,a,n);
    return 0;
}
