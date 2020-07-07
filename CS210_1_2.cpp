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

typedef struct node{
    int n;
    struct node *ptr;
} node;

node* getnode(int x)
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->n=x;
    temp->ptr=NULL;
    return temp;
}

node* enqueue(node *tail, int x)
{
    node *temp=getnode(x);
    if(tail==NULL)
        return temp;
    tail->ptr=temp;
    return temp;
}

node* dequeue(node *head)
{
    if(head==NULL)
        return head;
    node *temp=head;
    head=head->ptr;
    delete(temp);
    return head;
}

node* push(node *top,int x)
{
    node *temp=getnode(x);
    temp->ptr=top;
    return temp;
}

node* pop(node *top)
{
    if(top==NULL)
        return top;
    node *temp=top;
    top=top->ptr;
    delete(temp);
    return top;
}

node* isstack(node *top,int x)
{
    while(top!=NULL)
    {
        if(top->n==x)
            break;
        top=top->ptr;
    }
    return top;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x,i,p=0;
    int a[MAX];
    node *head1=NULL,*tail1=NULL,*head2=NULL,*tail2=NULL,*top=NULL;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        tail1=enqueue(tail1,i);
        if(head1==NULL)
            head1=tail1;
    }
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    i=0;
    while(i<n&&head1!=NULL)
    {
        while(head1!=NULL&&head1->n==a[i])
        {
            printf("enqueue(Q2, dequeue(Q1))\n");
            tail2=enqueue(tail2,head1->n);
            if(head2==NULL)
                head2=tail2;
            head1=dequeue(head1);
            i++;
        }
        if(isstack(top,a[i])!=NULL&&top->n!=a[i])
            break;
        while(head1!=NULL&&(top==NULL||top->n!=a[i]))
        {
            printf("push(S, dequeue(Q1))\n");
            top=push(top,head1->n);
            head1=dequeue(head1);
        }
        while(top!=NULL&&top->n==a[i])
        {
            printf("enqueue(Q2, pop(S))\n");
            tail2=enqueue(tail2,top->n);
            if(head2==NULL)
                head2=tail2;
            top=pop(top);
            i++;
        }
    }
    if(i<n)
    {
        printf("This is NOT a stack permutation because only first %d elements can be correctly ordered.\n",i);
        if(i>0)
            printf("Now, %d can't be placed next to %d.",a[i],a[i-1]);
    }
    return 0;
}
