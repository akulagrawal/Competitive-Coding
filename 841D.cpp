#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 1000006
#define mod 1000000007
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

int d[MAX];
vector<pii> v[MAX];
bool vis[MAX],del[MAX];

int dfs(int n)
{
    vis[n]=1;
    int i,p,c=d[n];
    for(i=0;i<v[n].size();i++)
    {
        if(!vis[v[n][i].f])
        {
            p=dfs(v[n][i].f);
            if(p)
            {
                c=(c+1)%2;
                del[v[n][i].s]=1;
            }
        }
    }
    if(d[n]==-1)
        return 0;
    return c;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,i,x,y,c=0,e=0,ans=0;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>d[i];
        if(d[i]==-1)
            c=i;
        else if(d[i])
            e++;
    }
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        v[x].pb(mp(y,i+1));
        v[y].pb(mp(x,i+1));
    }
    if(!c&&e%2)
    {
        cout<<"-1";
        return 0;
    }
    dfs(max(1,c));
    for(i=1;i<=m;i++)
    {
        if(del[i])
            ans++;
    }
    cout<<ans<<endl;
    for(i=1;i<=m;i++)
    {
        if(del[i])
            cout<<i<<endl;
    }
    return 0;
}
