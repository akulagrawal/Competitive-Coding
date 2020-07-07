#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 10004
#define mod 1000000007
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

typedef struct myqueue{                         //structure for implementation of queue
    int num;
    struct myqueue *ptr;
} que;

que* getnode(int x)                 // allocate memory and initialize a node of queue
{
    que *temp=new que;
    temp->num=x;
    temp->ptr=NULL;
    return temp;
}

que* push(que *b,int x)         // push at the back/enqueue in queue
{
    que *temp=getnode(x);
    if(b==NULL)
        return b=temp;
    b->ptr=temp;
    b=temp;
    return b;
}

que* pop(que *f)            // pop in front/dequeue from queue
{
    if(f==NULL)
        return NULL;
    que *temp=f;
    f=f->ptr;
    delete(temp);
    return f;
}

void bfs(int n,int p,bool mark[])       // bfs traversal of the graph formed in which there exists an edge between 2 numbers
{                                       // if they have three corresponding digits common and remaining digit differs by 1
    int vis[MAX];                       // n is the starting number and p is the final number required. vis[] stores the minimum distance of any number from n
    int i,x,y,k;
    for(i=0;i<MAX;i++)
        vis[i]=MAX;                 // initializing vis array to MAX ( more than total numbers ) and reducing it greedily
    vis[n]=0;
    que *b=NULL,*f=NULL;
    b=push(b,n);
    f=b;
    while(f!=NULL)
    {
        k=f->num;
        f=pop(f);
        x=10;
        for(i=0;i<4;i++)
        {
            y=(k+(x/10))%x;                         // y stores all adjacent numbers of x. starting from unit digit, each digit is both
            y=k-(k%x)+y;                            // increased and decreased by 1
            if((vis[y]>vis[k]+1)&&!mark[y])         // if distance of a number is more than calculated and is reachable, set it to calculated value and push in q
            {
                vis[y]=vis[k]+1;
                b=push(b,y);
                if(f==NULL)
                    f=b;
            }
            y=(k+x-(x/10))%x;
            y=k-(k%x)+y;
            if((vis[y]>vis[k]+1)&&!mark[y])
            {
                vis[y]=vis[k]+1;
                b=push(b,y);
                if(f==NULL)
                    f=b;
            }
            x=x*10;
        }
    }
    if(vis[p]==MAX)                 // if distance is never reduced, it can't be reached from initial number
        cout<<"-1\n";
    else
        cout<<vis[p]<<endl;
}

int in_4dig()               // take 4 digits as input and return 4 digit number formed by arranging them in order of input taken
{
    int x=0,a;
    for(int i=0;i<4;i++)
    {
        cin>>a;
        x=10*x+a;
    }
    return x;
}

int main()
{
    int n,t,i,x,y,a,m,z;
    bool mark[MAX];             // mark the numbers which are not reachable as 1
    cout<<"Enter number of test cases : ";
    cin>>t;
    while(t--)
    {
        x=0;
        y=0;
        memset(mark,0,sizeof(mark));
        cout<<"Enter initial and final configurations\n";
        x=in_4dig();
        y=in_4dig();
        cout<<"Enter number of forbidden configurations : ";
        cin>>m;
        cout<<"Enter forbidden configurations\n";
        while(m--)
        {
            z=in_4dig();
            mark[z]=1;
        }
        bfs(x,y,mark);
    }
    return 0;
}
