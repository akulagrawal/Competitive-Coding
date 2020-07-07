#include<bits/stdc++.h>
using namespace std;

#define MAX 1000006                         // elements in the input are <MAX

typedef struct node{
    int x;
    struct node* ptr;
} myq;                                      //structure to make linked list( actually queue implemented by linked list ) to store input data

myq* getnode(int n)                         //function to to make a new node for linked list
{
    myq* temp=new node;
    temp->x=n;
    temp->ptr=NULL;
    return temp;
}

myq* in(int n, myq *end1)                   // function to insert a node in the end of linked list ( queue insertion ) with x value one
{
    myq* temp=getnode(n);
    if(end1==NULL)
    {
        end1=temp;
        return end1;
    }
    end1->ptr=temp;
    end1=temp;
    return end1;
}

myq* del(myq *front1)                       // delete node from the front ( queue deletion )
{
    if(front1->ptr==NULL)
        {  return NULL;}

    myq *temp=front1;
    front1=front1->ptr;
    delete(temp);
    return front1;
}

void build(myq* a[],myq *b[],int node,int start,int end1)   // Build the tournament tree/Winner tree with parent node pointing to smaller of the children node's x value
{
    if(start==end1)
    {
        a[node]=b[start];
        return;
    }
    int mid=start+(end1-start)/2;
    int *temp1=NULL, *temp2=NULL;
    build(a,b,2*node,start,mid);
    build(a,b,2*node+1,mid+1,end1);
    if(a[2*node]->x<=a[2*node+1]->x)
        a[node]=a[2*node];
    else
        a[node]=a[2*node+1];
}

void add(myq *a[],myq *c,int node,int start,int end1,int pos)   //Update tournament tree by taking next element from the winner element sequence
{
    if(start==end1)
        a[node]=c;
    else
    {
        int mid=start+(end1-start)/2;
        if(pos>=start&&pos<=mid)
            add(a,c,2*node,start,mid,pos);
        else
            add(a,c,2*node+1,mid+1,end1,pos);
        if(a[2*node]->x<=a[2*node+1]->x)
            a[node]=a[2*node];
        else
            a[node]=a[2*node+1];
    }
}

int main()
{
    myq *a[MAX];
    myq *front1[MAX],*back1[MAX];           // pointers pointing to 1st and last elements of queue of k sequences
    myq *frontf=NULL, *backf=NULL;          // pointers pointing to 1st and last element of final solution queue
    int r;
    int i,j,k;
    char ch;
    cout<<"Enter no. of sequences followed by elements in each sequence separated by space\n";
    cin>>k;
    for(i=0;i<=k;i++)
        front1[i]=back1[i]=NULL;
    for(i=0;i<k;i++)                        // for loop to take input as k sequences
    {
        ch=' ';
        j=0;
        while(ch!='\n')                     // take input of a sequence till a newline comes
        {
            scanf("%d%c",&r,&ch);
	        back1[i]=in(r,back1[i]);        // pushing elements of a sequence in queue
            if(!j)
                front1[i]=back1[i];
            j++;
        }
    }
    build(a,front1,1,0,k-1);                // build the tree for 1st tournament/comparison between 1st elements
    j=0;
    while(1)
    {
        backf=in(a[1]->x,backf);            // pushing the winner of the last tournament/ winner of last comparisons, in solution queue
        if(!j)
            frontf=backf;
        j++;
        for(i=0;i<k;i++)
        {
            if(front1[i]==a[1])
            {
                if(front1[i]->ptr!=NULL)
                    front1[i]=del(front1[i]);       //deleting the existing winner and taking the position of next element to be inserted
                else
                {
                    front1[i]->x=MAX; front1[i]->ptr=NULL;  // if the sequence comes to an end, insert MAX which will lose everytime and is equal to being absent
                }
                add(a,front1[i],1,0,k-1,i);         // update winner tree
                break;
            }
        }
        if(a[1]->x==MAX)        // if winner is MAX, that means every sequence has come to an end, so break
           break;
    }
    myq *temp=frontf;
    while(temp!=NULL)
    {
        cout<<temp->x<<" ";         // traverse the solution queue
        temp=temp->ptr;
    }
    return 0;
}
