#include<bits/stdc++.h>

using namespace std;

vector<int> a[10004];
int vis[10004],maxm=0,last;

void dfs(int n,int depth)
{
    int i=0;
    vis[n]=1;
    if(depth>maxm)
    {
        maxm=depth;
        last=n;
    }
    for(i=0;i<a[n].size();i++)
    {
        if(!vis[a[n][i]])
        {
            dfs(a[n][i],depth+1);
        }
    }
}

int main()
{
    int n,u,v,i;
    scanf("%d",&n);
    for(i=0;i<n-1;i++)
    {
        scanf("%d%d",&u,&v);
        a[u-1].push_back(v-1);
        a[v-1].push_back(u-1);
    }
    dfs(0,0);
    for(i=0;i<n;i++)
        vis[i]=0;
    dfs(last,0);
    printf("%d",maxm);
    return 0;
}
