#include<bits/stdc++.h>
using namespace std;

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

void dfs_visitmod(que *g[],int n,bool vis[],int s[],int top,bool cc,bool print,int &cnt)         // modified dfs_visit function
{                     /* g[] is the graph in form of adjacency list, vis[] tells if a particular node is visited or not,
                         s[] is the array for implementation of stack and top is the index of top (last) element,
                         cc is 1 if connected components are to be printed, else 0. print is 1 if cycles are to be printed, else 0.
                         At any step, cnt is the count of cycles encountered till that step. */
    vis[n]=1;
    int x;
    top++;
    s[top]=n;           // push the parent in stack and traverse it's children
    if(cc)
        cout<<n<<" ";   // if connected components are to be printed, print every node when it is visited
    while(g[n]!=NULL)
    {
        x=g[n]->num;
        if(!vis[x])
            dfs_visitmod(g,x,vis,s,top,cc,print,cnt);       // traversing directly connected vertices by single edge (as in normal dfs)
        else if(top>0&&s[top-1]!=x)                 // cycle detected if next adjacent node is already visited and their are atleast 3 different nodes
        {                                           // in cycle i.e. current node and next to current node in stack are different from present visiting node.
            cnt++;
            if(print)       // if print cycle is on, print the path from the repeated node to itself, which simply is the order of displaying
            {               // stack elements from top, till the repeated node is encountered. NOTE : top is not changed in this process
                cout<<"Cycle "<<cnt<<": ";
                cout<<x<<" ";
                int j=top;
                while(j>=0&&s[j]!=x)
                {
                    cout<<s[j]<<" ";
                    j--;
                }
                cout<<x<<endl;
            }
        }
        g[n]=pop(g[n]);
    }
}

void make_graph(que *f[],que *b[],int x[],int y[],int e,int n)        // make graph from input. This is adjacency list implementation
{
    for(int i=0;i<=n;i++)
        f[i]=b[i]=NULL;
    for(int i=0;i<e;i++)
    {
        b[x[i]]=push(b[x[i]],y[i]);
        b[y[i]]=push(b[y[i]],x[i]);
        if(f[x[i]]==NULL)
            f[x[i]]=b[x[i]];
        if(f[y[i]]==NULL)
            f[y[i]]=b[y[i]];
    }
}

int dfscalc(que *f[],int n,int &cycno)          // dfs to calculate no. of connected components and cycles
{
    int ccno=0;
    int s[n+1];
    bool vis[n+1];
    cycno=0;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            ccno++;
            dfs_visitmod(f,i,vis,s,-1,0,0,cycno);
        }
    }
    return ccno;
}

void dfscc(que *f[],int n,int &cycno)           // dfs to display connected components
{
    int s[n+1],k=1;
    bool vis[n+1];
    memset(vis,0,sizeof(vis));
    cycno=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            cout<<"Connected components "<<k<<": ";
            k++;
            dfs_visitmod(f,i,vis,s,-1,1,0,cycno);
            cout<<endl;
        }
    }
}

void dfscyc(que *f[],int n,int &cycno)      // dfs to print all the cycles
{
    int s[n+1];
    bool vis[n+1];
    memset(vis,0,sizeof(vis));
    cycno=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
            dfs_visitmod(f,i,vis,s,-1,0,1,cycno);
    }
}

int main()
{
    int n,e,i;
    char ch;
    cout<<"Enter no. of nodes and no. of edges respectively separated by space: \n";
    cin>>n>>e;
    que *f[n+1], *b[n+1];
    int x[n+1], y[n+1],ccno=0,cycno=0;
    for(i=0;i<=n;i++)
        f[i]=b[i]=NULL;
    cout<<"Enter "<<e<<" edges, each consisting of 2 vertices separated by a comma : \n";
    for(i=0;i<e;i++)
        cin>>x[i]>>ch>>y[i];
    make_graph(f,b,x,y,e,n);
    ccno=dfscalc(f,n,cycno);
    cout<<"The number of connected components: "<<ccno<<endl;
    make_graph(f,b,x,y,e,n);
    dfscc(f,n,cycno);
    cout<<"The number of cycles: "<<cycno<<endl;
    make_graph(f,b,x,y,e,n);
    dfscyc(f,n,cycno);
    return 0;
}
