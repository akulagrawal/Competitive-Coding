#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 100005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

int disc[MAX],low[MAX],parent[MAX];
bool vis[MAX],AP[MAX];
vector<int> v[MAX];
int t;

void dfs(int n)
{
    vis[n]=1;
    low[n]=disc[n]=t;
    t++;
    int child=0;
    for(int i=0;i<v[n].size();i++)
    {
        if(!vis[v[n][i]])
        {
            child++;
            parent[v[n][i]]=n;
            dfs(v[n][i]);
            low[n]=min(low[n],low[v[n][i]]);
            if(parent[n]>0&&low[v[n][i]]>=disc[n])
                AP[n]=1;
            else if(parent[n]==0&&child>1)
                AP[n]=1;
        }
        else if(v[n][i]!=parent[n])
        {
            low[n]=min(low[n],disc[v[n][i]]);
        }
    }
}

int main()
{
    int n,m,a,b,ans,i;
    while(1)
    {
        t=0;
        ans=0;
        scanf("%d%d",&n,&m);
        if(!n&&!m)
            break;
        while(m--)
        {
            scanf("%d%d",&a,&b);
            v[a].pb(b);
            v[b].pb(a);
        }
        dfs(1);
        for(i=1;i<=n;i++)
        {
            if(AP[i])
                ans++;
            if(!vis[i])
            {
                ans=n;
                break;
            }
        }
        printf("%d\n",ans);
        for(i=1;i<=n;i++)
        {
            vis[i]=0;
            AP[i]=0;
            disc[i]=0;
            low[i]=0;
            parent[i]=0;
            v[i].clear();
        }
    }
    return 0;
}
