#include<bits/stdc++.h>
using namespace std;
#define MAX 1000006

int dfs(int x,int y,int a,int b,int n,int m,bool vis[1000][1000],string s[])        // depth first search from the starting position
{                                                                                   // (x,y) is current position while (a,b) is the final position of professors' home
    vis[x][y]=1;
    int p=0;
    int d1=0,d2=0,d3=0,d4=0;
    if(x==a&&y==b)
        return 1;                                                                   // return 1 if reach professors' home
    if((x>0)&&s[x-1][y]=='L')
    {
        if(!vis[x-1][y])
            d1=dfs(x-1,y,a,b,n,m,vis,s);
        else
            p++;
    }
    if((y<m-1)&&s[x][y+1]=='L')
    {
        if(!vis[x][y+1])
            d2=dfs(x,y+1,a,b,n,m,vis,s);
        else
            p++;
    }
    if((x<n-1)&&s[x+1][y]=='L')
    {
        if(!vis[x+1][y])
            d3=dfs(x+1,y,a,b,n,m,vis,s);
        else
            p++;
    }
    if((y>0)&&s[x][y-1]=='L')
    {
        if(!vis[x][y-1])
            d4=dfs(x,y-1,a,b,n,m,vis,s);
        else
            p++;
    }
    if((p>1)||(d1<0)||(d2<0)||(d3<0)||(d4<0))                               // in case of cycles, multiple paths are possible so return -1
        return -1;
    return (d1|d2|d3|d4);                                                   // return 1 if any (a,b) is reachable from any direction, otherwise return 0 ( thus, bitwise or)
}

int main()
{
    string s[100];
    bool vis[1000][1000];                                               // to mark visited position in dfs
    int pos[20];                                                        // pos stores starting and final positions.
    int n,m,i,k,j;
    while(1)
    {
        cout<<"Enter no. of rows and cols followed by matrix:\n";
        cin>>n>>m;
        if(!n||!m)
            break;
        k=0;
        for(i=0;i<=n;i++)                                               // unmarking every position in beginning
        {
            for(j=0;j<=m;j++)
                vis[i][j]=0;
        }
        for(i=0;i<n;i++)
            cin>>s[i];
        for(j=0;j<m;j++)
        {
            if(k>2)
                break;
            if(s[0][j]=='L')
            {
                pos[2*k]=0;
                pos[2*k+1]=j;
                k++;
            }
            if(n>1&&s[n-1][j]=='L')
            {
                pos[2*k]=n-1;
                pos[2*k+1]=j;
                k++;
            }
        }
        for(i=1;i<n-1;i++)
        {
            if(k>2)
                break;
            if(s[i][0]=='L')
            {
                pos[2*k]=i;
                pos[2*k+1]=0;
                k++;
            }
            if(m>1&&s[i][m-1]=='L')
            {
                pos[2*k]=i;
                pos[2*k+1]=m-1;
                k++;
            }
        }
        if(k!=2)
        {
            cout<<"Bad Luck! (Entry point + Exit point not exactly 2)\n";
            continue;
        }
        k=dfs(pos[0],pos[1],pos[2],pos[3],n,m,vis,s);
        if(k==0)
            cout<<"Bad Luck! (No path from one point to another)\n";
        else if(k<0)
            cout<<"Bad Luck! (More than one paths from one point to another)\n";
        else
            cout<<"Submitted! (Entry point + Exit point exactly 2 and exactly one path from one point to another)\n";
    }
    return 0;
}
