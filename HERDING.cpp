#include<iostream>
#include<stdio.h>
using namespace std;

char a[1003][1003];
int vis[1003][1003],p=0,ans=0;

void floodfill(int i, int j)
{
    if(vis[i][j]!=0)
    {
        p=vis[i][j];
        return;
    }
    vis[i][j]=p;
    switch(a[i][j])
    {
        case 'N':   floodfill(i-1,j);
                    break;
        case 'S':   floodfill(i+1,j);
                    break;
        case 'E':   floodfill(i,j+1);
                    break;
        case 'W':   floodfill(i,j-1);
                    break;
        default:    break;
    }
    vis[i][j]=p;
}

int main()
{
    int i,j,m,n;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            vis[i][j]=0;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(vis[i][j]==0)
            {
                p=ans+1;
                floodfill(i,j);
                if(p>ans)
                    ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
