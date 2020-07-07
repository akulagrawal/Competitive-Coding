#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 100006
#define mod 1000000007
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

int vis[MAX],last,maxm;
vector<pii> v[MAX];

void dfs(int n,int depth)
{
    if(maxm<depth)
    {
        last=n;
        maxm=depth;
    }
    vis[n]=1;
    for(int i=0;i<v[n].size();i++)
    {
        if(!vis[v[n][i].f])
            dfs(v[n][i].f,depth+v[n][i].s);
    }
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,x,y,z,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        m=n-1;
        while(m--)
        {
            scanf("%d%d%d",&x,&y,&z);
            v[x].pb(mp(y,z));
            v[y].pb(mp(x,z));
        }
        memset(vis,0,sizeof(vis));
        maxm=0;
        last=1;
        dfs(1,0);
        memset(vis,0,sizeof(vis));
        maxm=0;
        dfs(last,0);
        printf("%d\n",maxm);
        n++;
        while(n--)
            v[n].clear();
    }
    return 0;
}
