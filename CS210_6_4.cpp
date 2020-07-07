#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 100005
#define mod 1000000007
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

typedef struct binomial_heap{
    int key;
    int deg;
    struct binomial_heap *child;
    struct binomial_heap *sib;
    struct binomial_heap *par;
} bin;

bin *getnode(int n)                         // function allocates memory and returns a node of binomial tree with key n
{
    bin *temp;
    temp=new bin;
    temp->key=n;
    temp->deg=0;
    temp->child=temp->sib=temp->par=NULL;
    return temp;
}

void mheap(bin *h[],int &n)               // function to make new heap
{
    n++;
    h[n]=NULL;
}

bin* mergeh(bin *h1,bin *h2)                // function to link two heap nodes in which key of h1 is smaller than key of h2
{
    if(h1==NULL)
        return h2;
    else if(h2==NULL)
        return h1;
    h2->par=h1;
    h2->sib=h1->child;
    h1->child=h2;
    h1->deg++;
    return h1;
}

bin* union2(bin *h1,bin *h2)                // merge two heaps in increasing order of their degree like merging arrays in merge sort
{
    bin *h=NULL,*x=h1,*y=h2,*z=NULL;
    while(x!=NULL&&y!=NULL)
    {
        if(x->deg<=y->deg)
        {
            if(h==NULL)
            {
                h=x;
                z=x;
            }
            else
            {
                z->sib=x;
                z=z->sib;
            }
            x=x->sib;
        }
        else
        {
            if(h==NULL)
            {
                h=y;
                z=y;
            }
            else
            {
                z->sib=y;
                z=z->sib;
            }
            y=y->sib;
        }
    }
    if(x!=NULL)
    {
        if(z!=NULL)
            z->sib=x;
        else
        {
            z=x;
            if(h==NULL)
                h=z;
        }
    }
    if(y!=NULL)
    {
        if(z!=NULL)
            z->sib=y;
        else
        {
            z=y;
            if(h==NULL)
                h=z;
        }
    }
    return h;
}

bin* unionh(bin *h1,bin *h2)            // make one binomial heap from 2 binomial heaps and return head of final binomial heap
{
    bin *h=union2(h1,h2);
    bin *prev=NULL,*x=NULL,*next=NULL,*nextsib=NULL;
    x=h;
    if(x!=NULL)
        next=x->sib;
    if(next!=NULL)
        nextsib=next->sib;
    while(next!=NULL)
    {
        if((x->deg!=next->deg)||((nextsib!=NULL)&&(x->deg==nextsib->deg)))
        {
            prev=x;
            x=next;
            next=nextsib;
            if(nextsib!=NULL)
                nextsib=nextsib->sib;
        }
        else if(x->deg==next->deg)              // merge only when x and next have same degree and sibnext has different degree
        {                                       // that is merge last 2 heaps with same degree
            if(x->key<=next->key)
            {
                x->sib=nextsib;
                x=mergeh(x,next);
                next=nextsib;
            }
            else
            {
                if(prev!=NULL)
                    prev->sib=next;
                else
                    h=next;
                next=mergeh(next,x);
                x=next;
                next=x->sib;
            }
            if(next!=NULL)
                nextsib=next->sib;
        }
    }
    return h;
}

bin* findmin(bin *h)            // return the pointer to minimum value of key in the heap h
{
    bin *temp=h,*ptr=NULL;
    int x=MAX;
    while(temp!=NULL)           // find minimum of all values of key in the siblings of head and return it's pointer
    {
        if(temp->key<x)
        {
            x=temp->key;
            ptr=temp;
        }
        temp=temp->sib;
    }
    return ptr;
}

bin* extract_min(bin *h,bool t)     // remove the smallest element in the heap and return the head of final heap
{
    bin *temp=findmin(h), *temp2=NULL;
    if(h==NULL)
    {
        cout<<"Heap Empty\n";
        return NULL;
    }
    if(t)                           // if print after extract_min is on, print the minimum value
        cout<<"Minimum extracted : "<<temp->key<<endl;
    if(temp==h)                     // if head is the ptr to minimum value, make it's sibling as the head
        h=h->sib;
    else                            // remove the heap containing ptr to min as the head
    {
        temp2=h;
        while(temp2->sib!=temp)
            temp2=temp2->sib;
        temp2->sib=temp->sib;
    }
    bin *x=temp->child;
    bin *y=NULL,*z=NULL;
    if(x!=NULL)                     // reverse the order of children of ptr to min and make the union of original heap and heap formed by children to min
    {
        y=x->sib;
        x->sib=NULL;
    }
    while(x!=NULL)
    {
        if(y!=NULL)
        {
            z=y->sib;
            y->sib=x;
        }
        else
            break;
        x=y;
        y=z;
    }
    if(x!=NULL)
        x->par=NULL;
    delete(temp);               // delete ptr to min after forming heap of children (x)
    return unionh(h,x);
}

bin* in(bin* h,int n)           // function to insert a node with key n in heap
{
    bin* temp=getnode(n);       // make individual node and make union of main heap and this node
    return unionh(h,temp);
}

int dig(int n)              // function to return no. of digits of n in decimal representation
{
    int p=0;
    if(!n)
        return 1;
    while(n)
    {
        p++;
        n/=10;
    }
    return p;
}

void showHeap(bin* h,int depth)     // function to print non null heap in the given format
{
    if(h->sib!=NULL)
        showHeap(h->sib,depth);
    if (h->par==NULL)
		cout<<endl;
    if(h->par==NULL||h->child!=NULL)
    {
        int k=dig(h->key);
        for(int i=0;i<7*depth+5-k;i++)
            cout<<" ";
        cout<<h->key;
        if(h->child==NULL)
            cout<<endl;
    }
    else
    {
        int k=dig(h->key);
        for(int i=0;i<7-k;i++)
            cout<<" ";
        cout<<h->key<<endl;
    }
    if(h->child!=NULL)
        showHeap(h->child,depth+1);
}

void showBinomialHeap(bin* h)           // function to print binomial heap
{
    cout<<"Structure of binomial heap (rotated 90 degrees clockwise):\n";
    if(h==NULL)
        cout<<"Empty heap\n";
    else
        showHeap(h,0);
}

void menu()                                 // display menu
{
    cout<<"         OPERATION               |PRESS KEY\n";
    cout<<"MAKE-BINOMIAL-HEAP               |   c\n";
    cout<<"BINOMIAL-HEAP-UNION              |   u\n";
    cout<<"BINOMIAL-HEAP-INSERT             |   i\n";
    cout<<"BINOMIAL-HEAP-EXTRACT-MIN        |   d\n";
    cout<<"PRINT-HEAP                       |   s\n";
    cout<<"Turn off Print after extract min |   +\n";
    cout<<"Turn on print after extract min  |   -\n";
    cout<<"QUIT                             |   q\n";
}

int main()
{
    char ch;
    bool p=0,t=0;
    int n,m=0,x,y;
    bin *h[MAX];
    for(int i=0;i<MAX;i++)
        h[i]=NULL;
    menu();
    while(1)
    {
        cout<<"Enter Choice(c/u/i/d/s/+/-/q) : ";
        cin>>ch;
        if(ch=='c'||ch=='C')
        {
            mheap(h,m);
            cout<<"heap "<<m<<" created\n";
        }
        else if(ch=='u'||ch=='U')
        {
            cout<<"Enter indices(starting from 1) of heaps to make union : ";
            cin>>x>>y;
            if(x<1||x>m||y<1||y>m||h[x]==NULL||h[y]==NULL)
            {
                cout<<"Indices incorrect\n";
                continue;
            }
            h[y]=unionh(h[x],h[y]);
            cout<<"Union successfully stored at index "<<y<<endl;
        }
        else if(ch=='i'||ch=='I')
        {
            if(!m)
            {
                cout<<"No heap to insert\n";
                continue;
            }
            cin>>n;
            h[m]=in(h[m],n);
        }
        else if(ch=='d'||ch=='D')
        {
            if(!m)
            {
                cout<<"No heap to extract from\n";
                continue;
            }
            else if(h[m]==NULL)
            {
                cout<<"Current heap is empty\n";
                continue;
            }
            h[m]=extract_min(h[m],t);
        }
        else if(ch=='+')
        {
            cout<<"Print flag turned on\n";
            t=1;
        }
        else if(ch=='-')
        {
            cout<<"Print flag turned off\n";
            t=0;
        }
        else if(ch=='q'||ch=='Q')
            break;
        else if(ch=='s'||ch=='S')
            showBinomialHeap(h[m]);
        else
            cout<<"Invalid Key\n";
    }
    return 0;
}
