#include<bits/stdc++.h>
using namespace std;
#define MAX 1000006

typedef enum {head, ele} tagfield;                              // to mark a node as head or element

typedef struct node{                                            // structure to store data
    string row;
    string col;
    int val;
} node;

typedef struct matrixnode{                                      // structure to implement sparse matrix through linked list
    struct matrixnode *down;
    struct matrixnode *right;
    union{
        node *ele;
        struct matrixnode *next;
    } u;
    tagfield tag;
} mnode;

node* getnode1(string a,string b,int d)                         // function to allocate memory and return a pointer to node with data given in parameter
{
    node *temp=NULL;
    temp=new node;
    temp->row=a;
    temp->col=b;
    temp->val=d;
    return temp;
}

mnode* getnode2(string a,string b,int d,tagfield p)             // function to allocate memory to new matrixnode to implement sparse matrix through linked list
{
    mnode *temp;
    temp=new mnode;
    temp->down=temp->right=temp;
    if(p==ele)
        temp->u.ele=getnode1(a,b,d);
    else
        temp->u.next=NULL;
    temp->tag=p;
    return temp;
}

void swap1(string &a,string &b)                                 // function to swap 2 strings
{
    string temp=a;
    a=b;
    b=temp;
}

void swap2(string &a1,string &a2,int &a3,string &b1,string &b2,int &b3) // function to swap 2 units of data. Each data includes 2 strings and 1 integer
{
    string t1=a1,t2=a2;
    int t3=a3;
    a1=b1;  a2=b2;  a3=b3;
    b1=t1;  b2=t2;  b3=t3;
}

int part(string a[], string b[], int c[], int l, int r)                 // partition for quick sort and returning pivot's position
{
    int rc=r,lc=l;
    string pivot=a[l], temp=b[l];
    while(lc<=rc)
    {
        while(((a[lc]<pivot)||((a[lc]==pivot)&&(b[lc]<=temp)))&&lc<=rc)
            lc++;
        while(((a[rc]>pivot)||((a[rc]==pivot)&&(b[rc]>temp)))&&lc<=rc)
            rc--;
        if(lc<=rc)
            swap2(a[lc],b[lc],c[lc],a[rc],b[rc],c[rc]);
    }
    swap2(a[l],b[l],c[l],a[rc],b[rc],c[rc]);
    return rc;
}

void qsort1(string a[], string b[], int c[], int l, int r)          // Quick sort for sorting data to put in sparse matrix
{
    if(l<r)
    {
        int x=part(a,b,c,l,r);
        qsort1(a,b,c,l,x-1);
        qsort1(a,b,c,x+1,r);
    }
}

void arrange(string a[], string b[], int d[],int n)     // Function to arrange pairs of same index in arrays of strings such that 1st is lexicographically less than 2nd
{                                                       // to make pairs unique
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]>b[i])
            swap1(a[i],b[i]);
    }
}

string int_str(int n)                           // Function to write integer as string
{
    int p=n,i;
    string s;
    char ch;
    while(p)
    {
        ch='0'+(p%10);
        s=ch+s;
        p=p/10;
    }
    return s;
}

void makem1(node matrix1[],string s1[],string s2[],int d[],int r,int n)     // make sparse matrix as an array
{
    arrange(s1,s2,d,r);
    qsort1(s1,s2,d,0,r-1);
    string s;
    int i;
    s=int_str(n);
    matrix1[0].row=s;
    matrix1[0].col=s;
    matrix1[0].val=r;
    for(i=1;i<=r;i++)
    {
        matrix1[i].row=s1[i-1];
        matrix1[i].col=s2[i-1];
        matrix1[i].val=d[i-1];
    }
}

mnode* inright(mnode *ptr, string a, string b, int d)       // function to insert a new mnode to right pointer and return pointer to it
{
    mnode *temp=getnode2(a,b,d,ele);
    temp->right=ptr->right;
    ptr->right=temp;
    return temp;
}

mnode* innext(mnode *ptr)                               // function to insert a new mnode to next pointer and return pointer to it
{
    mnode *temp=getnode2("","",0,head);
    temp->u.next=ptr->u.next;
    ptr->u.next=temp;
    return temp;
}

mnode* makem2(mnode *top, string s1[], string s2[], int d[], int f,int n)       // make sparse matrix using linked list
{
    arrange(s1,s2,d,f);
    qsort1(s1,s2,d,0,f-1);
    int i;
    mnode *temp=NULL, *temp2=NULL;
    string s=int_str(n);
    top=getnode2(s,s,f,ele);
    temp=getnode2("","",0,head);
    temp->u.next=top;
    top->right=temp;
    temp=inright(temp,s1[0],s2[0],d[0]);
    s=s1[0];
    for(i=1;i<f;i++)
    {
        if(s!=s1[i])
        {
            temp=temp->right;
            temp=innext(temp);
            s=s1[i];
        }
        temp=inright(temp,s1[i],s2[i],d[i]);
    }
    temp=top->right;
    mnode *temp3=NULL;
    while(temp!=top)
    {
        temp3=temp2=temp->u.next;
        temp=temp->right;
        while(temp->tag==ele)
        {
            temp2=temp3;
            s=temp->u.ele->col;
            while(temp2!=top)
            {
                temp2=temp2->right;
                while(temp2->tag==ele)
                {
                    if((temp2->u.ele->col==s)&&((temp2->down==temp2)))
                    {
                        temp2->down=temp->down;
                        temp->down=temp2;
                        temp=temp2;
                    }
                    temp2=temp2->right;
                }
                temp2=temp2->u.next;
            }
            temp=temp->right;
        }
        temp=temp->u.next;
    }
    return top;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,r,f,i,j;
    cin>>n>>r>>f;
    string s1[r+1],s2[r+1];
    int d[r+1];
    for(i=0;i<r;i++)
        cin>>s1[i]>>s2[i]>>d[i];
    node matrix1[r+1];
    makem1(matrix1,s1,s2,d,r,n);
    for(i=0;i<f;i++)
        cin>>s1[i]>>s2[i]>>d[i];
    mnode *top=NULL;
    top=makem2(top,s1,s2,d,f,n);
    mnode *temp=NULL;
    string a1,a2;
    int a3=-1,p;
    for(i=1;i<=r;i++)
    {
        temp=top->right;
        while(temp!=top)
        {
            temp=temp->right;
            while(temp->tag==ele)
            {
                if((matrix1[i].row==temp->u.ele->row)&&(matrix1[i].col==temp->u.ele->col))      // checking if the fare and distance are between same cities
                {
                    p=matrix1[i].val*temp->u.ele->val;
                    if(p>a3)                                            // ai store data of pair of cities with maximum cost
                    {
                        a3=p;
                        a1=matrix1[i].row;
                        a2=matrix1[i].col;
                    }
                }
                temp=temp->right;
            }
            temp=temp->u.next;
        }
    }
    cout<<a1<<" "<<a2<<" "<<a3;
    return 0;
}
