#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 200005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

vector<int> v[MAX];
pair<int,int> vis[MAX];
int p=1;

void bfs(int n)
{
    int j;
    queue<int> q;
    q.push(n);
    vis[n].f=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        j=-1*vis[u].f;
        for(int i=0;i<v[u].size();i++)
        {
            if(!vis[v[u][i]].f)
            {
                vis[v[u][i]].s=vis[u].f;
                if(j==-1||j==vis[u].s-vis[u].f-1)
                    j++;
                if(j==-1||j==vis[u].s-vis[u].f-1)
                    j++;
                vis[v[u][i]].f=vis[u].f+1+j;
                q.push(v[u][i]);
                j++;
            }
        }
    }
}

int main()
{
    int n,i,x,y,maxm=0;
    cin>>n;
    for(i=0;i<n-1;i++)
    {
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    bfs(1);
    for(i=1;i<=n;i++)
        if(maxm<vis[i].f)
            maxm=vis[i].f;
    cout<<maxm<<"\n";
    for(i=1;i<=n;i++)
        cout<<vis[i].f<<" ";
    return 0;
}
