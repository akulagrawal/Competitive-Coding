#include<bits/stdc++.h>

using namespace std;

vector<int> v[102];
bool ans[3003];
int k,vis[102];

void dfs(int n)
{
    vis[n]=k;
    for(int i=0;i<v[n].size();i++)
    {
        if(!vis[v[n][i]])
            dfs(v[n][i]);
    }
}

int main()
{
    int t,n,m,a,b,q,i,x,y;
    scanf("%d",&t);
    while(t--)
    {
        k=1;
        scanf("%d%d",&n,&m);
        while(m--)
        {
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i);
                k++;
            }
        }
        scanf("%d",&q);
        for(i=0;i<q;i++)
        {
            scanf("%d%d",&x,&y);
            if(vis[x]==vis[y])
                ans[i]=1;
            else
                ans[i]=0;
        }
        for(i=0;i<q;i++)
        {
            if(ans[i]==1)
                printf("YO\n");
            else
                printf("NO\n");
        }
        for(i=0;i<n;i++)
        {
            vis[i]=0;
            v[i].clear();
        }
    }
    return 0;
}
