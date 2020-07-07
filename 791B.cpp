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

vector<int> v[150004];
int vis[150004],sum[150004];
int t;

void dfs(int n)
{
    sum[t]++;
    vis[n]=t;
    for(int i=0;i<v[n].size();i++)
    {
        if(!vis[v[n][i]])
            dfs(v[n][i]);
    }
}

int p[150004];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,a,b;
    cin>>n>>m;
    while(m--)
    {
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
        p[a]++;
        p[b]++;
    }
    t=1;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
            t++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(p[i]!=sum[vis[i]]-1)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}
