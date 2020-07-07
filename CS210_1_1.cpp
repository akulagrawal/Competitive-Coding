#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 1000006
#define mod 1000000007
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

typedef struct node{
    int x;
    struct node* ptr;
    struct node* ptr2;
} node;

node* getnode(int n)
{
    node*temp;
    temp=(node*)malloc(sizeof(node));
    temp->x=n;
    temp->ptr=NULL;
    temp->ptr2=NULL;
    return temp;
}

node* next(node *p)
{
    if(p==NULL)
        return p;
    if(p->ptr2!=NULL)
        p=p->ptr2;
    else
        p=p->ptr;
    return p;
}

node* linear(int n,node *top,node *stop)
{
    if(stop!=NULL)
        stop=stop->ptr;
    while(top!=stop)
    {
        if(top->x==n)
            break;
        top=top->ptr;
    }
    if(top!=NULL&&top->x!=n)
        top=NULL;
    return top;
}

node* cycle(int n,node *top)
{
    if(top==NULL||top->x==n)
        return top;
    node *temp=next(top);
    while(temp!=top)
    {
        if(temp->x==n)
            break;
        temp=next(temp);
    }
    return temp;
}

node* func(int a,node *top,node *rear)
{
    node *temp1=top,*temp2=top, *ans=NULL, *temp=NULL;
    if(top==NULL)
        return top;
    while(1)
    {
        temp1=next(temp1);
        temp2=next(temp2);
        temp2=next(temp2);
        if(temp1==NULL||temp2==NULL)
            break;
        if(temp1==temp2)
        {
            ans=temp1;
            break;
        }
    }
    temp=linear(a,top,rear);
    if(temp!=NULL)
        return temp;
    if(ans==NULL)
    {
        temp=NULL;
        while(top!=rear)
        {
            if(top->ptr2!=NULL)
                temp=linear(a,top->ptr2,rear);
            if(temp!=NULL)
                return temp;
            top=top->ptr;
        }
    }
    return cycle(a,ans);
}

node* inbeg(int n,node*top)
{
    node *temp=getnode(n);
    temp->ptr=top;
    return top=temp;
}

node* inend(int n,node*rear)
{
    if(rear==NULL)
        return rear=getnode(n);
    node *temp=getnode(n);
    rear->ptr=temp;
    return rear=temp;
}

void in(int a,int b,int c,node*top,node*rear)
{
    node *x,*y1;
    x=func(a,top,rear);
    y1=func(c,top,rear);
    if(x==NULL||y1==NULL)
        return;
    node *temp=getnode(b);
    if(x->ptr==NULL)
        x->ptr=temp;
    else
        x->ptr2=temp;
    temp->ptr=y1;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c,n;
    node *top=NULL,*rear=NULL;
    while(1)
    {
        scanf("%d",&a);
        if(a==-1)
            break;
        scanf("%d%d",&b,&c);
        if(!a)
            top=inbeg(b,top);
        else if(!c)
            rear=inend(b,rear);
        else
            in(a,b,c,top,rear);
        if(top==NULL)
            top=rear;
        else if(rear==NULL)
            rear=top;
    }
    node *temp=NULL;
    scanf("%d",&n);
    temp=func(n,top,rear);
    if(temp==NULL||temp->x!=n)
        printf("NOT FOUND\n");
    else
        printf("FOUND\n");
    return 0;
}
