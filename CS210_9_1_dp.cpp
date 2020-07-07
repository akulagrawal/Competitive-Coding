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

void read(int x[][505],int n)       // read details of die as input
{
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<6;i++)
            cin>>x[i][j];
    }
}

void init(int dp[][505],int n,int &maxm,stk *&top)       // initialize the elements required to calculate the answer
{
    maxm=0;                 // maximum height initialized as 0
    top=NULL;               // top pointer of stack initialized to NULL;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
            dp[i][j]=0;         // dp matrix set to 0. dp[i][j] represents maximum height of tower to bring i on top of tower and choosing 1st j die
    }
}

void calc(int dp[][505], int x[][505],int n,int &maxm)      // calculating maximum height of the tower
{
    int p,q,i,j;
    for(j=0;j<n;j++)
    {
        for(i=0;i<6;i++)
        {
            p=x[i][j];                              // p is the number on present face
            if(i%2)                                 // q is the number on the face opposite to present face
                q=x[i-1][j];
            else
                q=x[i+1][j];
            dp[p][j+1]=max(dp[p][j],dp[q][j]+1);    // to make highest tower with p on top in first j+1 die,
        }                                           // either keep (j+1)th dice on tower formed with first j die with q on top
        for(i=1;i<=n;i++)                           // or take tower made with first j die, with p on top.
            dp[i][j+1]=max(dp[i][j],dp[i][j+1]);
    }
    for(i=1;i<=n;i++)
        maxm=max(maxm,dp[i][n]);        // maxm is the maximum height among towers formed by taking all the n cubes with top as any number
}

stk* make_stk(stk *top,int dp[][505],int x[][505],int n,int maxm)   // start from last and greedily push cube indices and faces in stack
{
    int i,j,p,q,k;
    for(i=0;i<6;i++)
    {
        p=x[i][n-1];
        if(i%2)
            q=x[i-1][n-1];
        else
            q=x[i+1][n-1];
        if(dp[p][n]==maxm&&dp[q][n-1]==maxm-1)      // the top face is the top face of maxm height tower, it's opposite face must be top of (maxm-1) height tower
        {
            if(i%2)                     // since the top is to be displayed in the end, push it to empty stack
                top=push(top,n,i-1);    // also, since display order is reversed, push with opposite face up
            else
                top=push(top,n,i+1);
            k=q;                        // k stores the number required to be on the top of the next cube in decreasing order of height
            maxm--;
            break;
        }
    }
    for(j=n-1;j>0;j--)          // since we are moving in reverse order as output, the chosen die are pushed into the stack
    {
        for(i=0;i<6;i++)
        {
            p=x[i][j-1];
            if(i%2)
                q=x[i-1][j-1];
            else
                q=x[i+1][j-1];
            if(p==k&&dp[p][j]==maxm&&dp[q][j-1]==maxm-1)    // top face matches bottom of previous and
            {                                               // we can form maxm-1 height tower with opposite face as top and j-1 cubes
                if(i%2)
                    top=push(top,j,i-1);
                else
                    top=push(top,j,i+1);
                k=q;
                maxm--;
                break;
            }
        }
    }
    return top;
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
    int n,i=1,maxm,k;
    int x[10][505],dp[505][505];    // x[][] is the input matrix, faces are stored as 0-5 in order given in qn
                                    // dp[i][j] represents maximum height of tower to bring i on top of tower and choosing die from 1st j die
    stk *top=NULL;
    while(i++)
    {
        cout<<"Enter number of cubes : ";
        cin>>n;
        if(!n)
            break;
        cout<<"Enter details of n cubes (6 faces for each)\n";
        read(x,n);
        init(dp,n,maxm,top);
        calc(dp,x,n,maxm);
        top=make_stk(top,dp,x,n,maxm);
        cout<<"Case #"<<i-1<<endl;
        cout<<maxm<<endl;
        display(top);
        cout<<endl;
    }
    return 0;
}
