#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 100005
#define mod 1000000007
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

int graph[100][100],vis[100],parent[100];

bool bfs(int s,int t)
{
    memset(vis,0,sizeof(vis));
    queue<int> q;
    q.push(s);
    vis[s]=1;
    parent[s]=-1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v=0;v<60;v++)
        {
            if(!vis[v]&&graph[u][v]>0)
            {
                q.push(v);
                parent[v]=u;
                vis[v]=1;
            }
        }
    }
    return vis[t]==1;
}

int FordFulkerson(int s,int t)
{
    int max_flow=0;
    while(bfs(s,t))
    {
        int path_flow=100000,u,v;
        for(v=t;v!=s;v=parent[v])
        {
            u=parent[v];
            path_flow=min(path_flow,graph[u][v]);
        }
        for(v=t;v!=s;v=parent[v])
        {
            u=parent[v];
            graph[u][v]-=path_flow;
            graph[v][u]+=path_flow;
        }
        max_flow+=path_flow;
    }
    return max_flow;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    char c1,c2;
    cin>>n;
    while(n--)
    {
        cin>>c1>>c2>>x;
        graph[(int)c1-65][(int)c2-65]+=x;
        graph[(int)c2-65][(int)c1-65]+=x;
    }
    cout<<FordFulkerson(0,25);
    return 0;
}
