#include<bits/stdc++.h>
using namespace std;

typedef struct mystack{                         // structure of stack. a stores the index of dice and b stores the face ( 0 to 5 )
    int a;
    int b;
    struct mystack *ptr;
} stk;

stk* getnode(int x,int y)       // allocate memory to a node of stack
{
    stk *temp=NULL;
    temp=new stk;
    temp->a=x;
    temp->b=y;
    temp->ptr=NULL;
    return temp;
}

stk* push(stk *top,int x,int y)         // push in stack with top given as top pointer
{
    stk *temp=getnode(x,y);
    temp->ptr=top;
    return top=temp;
}

stk* pop(stk *top)                  // pop from stack with top given as top pointer
{
    if(top==NULL)
        return NULL;
    stk *temp=top;
    top=top->ptr;
    delete(temp);
    return top;
}

void print(int n)               // print the face of cube according to it's index from 0 to 5
{
    switch(n)
    {
        case 0: cout<<"front";
                break;
        case 1: cout<<"back";
                break;
        case 2: cout<<"left";
                break;
        case 3: cout<<"right";
                break;
        case 4: cout<<"top";
                break;
        case 5: cout<<"bottom";
                break;
        default: break;
    }
    cout<<endl;
}

void read(int x[505][10],int n)       // read details of die as input
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<6;j++)
            cin>>x[i][j];
    }
}

void init(stk *g[505][10],int &maxm,stk *&top)       // initialize the elements required to calculate the answer
{
    maxm=0;                 // maximum height initialized as 0
    top=NULL;               // top pointer of stack initialized to NULL;
    for(int i=0;i<505;i++)
    {
        for(int j=0;j<10;j++)
        {
            while(g[i][j]!=NULL)
                g[i][j]=pop(g[i][j]);
        }
    }
}

void make_graph(stk *g[505][10],int x[505][10],int n)       // function to make graph based on input x[][]
{
    int i,j,k,l,opp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<6;j++)
        {
            if(j%2)
                opp=j-1;
            else
                opp=j+1;                                // opp is the face index of opposite face
            for(k=n-1;k>i;k--)
            {
                for(l=0;l<6;l++)
                {
                    if(x[k][l]==x[i][opp])              // make an edge if the opposite face matches with a face of a heavier cube
                        g[i][j]=push(g[i][j],k,l);
                }
            }
        }
    }
}

int dfs_vis(stk *g[505][10],int vis[505][10],int x,int y,int depth)         // dfs_visit function of dfs which calculates and returns maximum depth
{
    vis[x][y]=depth;
    int i,j,p,maxm=depth;
    stk *pt=g[x][y];
    while(pt!=NULL)
    {
        i=pt->a;
        j=pt->b;
        pt=pt->ptr;
        if(vis[i][j]<depth+1)
        {
            p=dfs_vis(g,vis,i,j,depth+1);
            if(maxm<p)
                maxm=p;
        }
    }
    return maxm;
}

void dfs(stk *g[505][10],int n,int &maxm,stk *&top)     // dfs function for graph g which finds maximum depth and stores in maxm and
{                                                       // stores the path of maximum depth in reverse order in stack top
    int vis[505][10],i,j,depth=0,p,q,x,y;
    for(i=0;i<=n;i++)
        memset(vis[i],0,sizeof(vis[i]));
    for(i=0;i<n;i++)
    {
        for(j=0;j<6;j++)
        {
            if(!vis[i][j])
            {
                depth=dfs_vis(g,vis,i,j,1);
                if(maxm<depth)
                    maxm=depth;
            }
            depth=0;
        }
    }
                                                // now vis[i][j] stores depth(maximum) of face j of dice of index i
    for(i=n-1;i>=0;i--)
    {
        for(j=0;j<6;j++)
        {
            if(vis[i][j]==maxm)                 // find face and dice index corresponding to deepest state
            {
                p=i;
                q=j;
                top=push(top,i+1,j);
                depth=maxm-1;
                break;
            }
        }
        if(j<6)
            break;
    }
    for(;i>0;i--)          // since we are moving in reverse order as output, the chosen die are pushed into the stack
    {
        for(j=0;j<6;j++)
        {
            if(vis[i][j]!=depth)
                continue;
            stk *temp=g[i][j];
            while(temp!=NULL)
            {
                x=temp->a;
                y=temp->b;
                if(x==p&&y==q)
                {
                    p=i;
                    q=j;
                    depth--;
                    top=push(top,i+1,j);
                    break;
                }
                temp=temp->ptr;
            }
        }
    }
    for(j=0;j<6;j++)                // separate loop for 1st dice as there is no edge to 1st
    {
        if(vis[0][j]!=depth)
            continue;
        stk *temp=g[i][j];
        while(temp!=NULL)
        {
            x=temp->a;
            y=temp->b;
            if(x==p&&y==q)
            {
                p=i;
                q=j;
                depth--;
                top=push(top,i+1,j);
                break;
            }
            temp=temp->ptr;
        }
    }
}

void display(stk *&top)
{
    while(top!=NULL)
    {
        cout<<top->a<<" ";          // top->a stores the indices of die in increasing order such that adjacent faces of cubes match
        print(top->b);              // print face name with index i
        top=pop(top);
    }
}

int main()
{
    int n,i,maxm,k;
    int x[505][10];
    stk *g[505][10];    // x[][] is the input matrix, faces are stored as 0-5 in order given in qn
                                    // dp[i][j] represents maximum height of tower to bring i on top of tower and choosing die from 1st j die
    stk *top=NULL;
    for(i=0;i<505;i++)
    {
        for(int j=0;j<10;j++)
            g[i][j]=NULL;
    }
    i=1;
    while(i++)
    {
        cout<<"Enter number of cubes : ";
        cin>>n;
        if(!n)
            break;
        cout<<"Enter details of n cubes (6 faces for each)\n";
        read(x,n);
        init(g,maxm,top);
        make_graph(g,x,n);
        dfs(g,n,maxm,top);
        cout<<"Case #"<<i-1<<endl;
        cout<<maxm<<endl;
        display(top);
        cout<<endl;
    }
    return 0;
}
