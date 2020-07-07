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

vector<int> v[2003];
int vis[2003];

int bfs(int n)
{
    queue<int> q;
    q.push(n);
    int p=2,t=0;
    vis[n]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(vis[u]==1)
            p=2;
        else
            p=1;
        for(int i=0;i<v[u].size();i++)
        {
            if(!vis[v[u][i]])
            {
                vis[v[u][i]]=p;
                q.push(v[u][i]);
            }
            else if(vis[v[u][i]]!=p)
            {
                t=1;
                break;
            }
        }
    }
    return t;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,k,n,m,i,x,y,p;
    scanf("%d",&t);
    for(k=1;k<=t;k++)
    {
        p=0;
        scanf("%d%d",&n,&m);
        while(m--)
        {
            scanf("%d%d",&x,&y);
            v[x].pb(y);
            v[y].pb(x);
        }
        for(i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                p=bfs(i);
                if(p)
                    break;
            }
        }
        for(i=1;i<=n;i++)
        {
            v[i].clear();
            vis[i]=0;
        }
        printf("Scenario #%d:\n",k);
        if(p)
            printf("Suspicious bugs found!\n");
        else
            printf("No suspicious bugs found!\n");
    }
    return 0;
}
