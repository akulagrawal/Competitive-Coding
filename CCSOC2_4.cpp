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

char s[505][505];
pii vis[505][505];
int n,m;

void dfs(int i,int j,int x)
{
    int b=vis[i][j].f,t=vis[i][j].s;
    if((j<(m-1))&&((vis[i][j+1].s>(t+x))||((vis[i][j+1].s==(t+x))&&(vis[i][j+1].f>(b+1))))&&(s[i][j+1]=='.'))
    {
        vis[i][j+1]=mp(b+1,t+x);
        dfs(i,j+1,0);
    }
    if((i<(n-1))&&((vis[i+1][j].s>(t+!x))||((vis[i+1][j].s==(t+!x))&&(vis[i+1][j].f>(b+1))))&&(s[i+1][j]=='.'))
    {
        vis[i+1][j]=mp(b+1,t+!x);
        dfs(i+1,j,1);
    }
    if((j>0)&&((vis[i][j-1].s>(t+x))||((vis[i][j-1].s==(t+x))&&(vis[i][j-1].f>(b+1))))&&(s[i][j-1]=='.'))
    {
        vis[i][j-1]=mp(b+1,t+x);
        dfs(i,j-1,0);
    }
    if((i>0)&&((vis[i-1][j].s>(t+!x))||((vis[i-1][j].s==(t+!x))&&(vis[i-1][j].f>(b+1))))&&(s[i-1][j]=='.'))
    {
        vis[i-1][j]=mp(b+1,t+x);
        dfs(i-1,j,1);
    }
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j;
    pii ans;
    cin>>n>>m;
    for(i=0;i<n;i++)
        cin>>s[i];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            vis[i][j]=mp(MAX,MAX);
    }
    vis[0][0]=mp(1,0);
    dfs(0,0,0);
    ans=vis[n-1][m-1];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            vis[i][j]=mp(MAX,MAX);
    }
    vis[0][0]=mp(1,0);
    dfs(0,0,1);
    if((vis[n-1][m-1].s<ans.s)||((vis[n-1][m-1].s==ans.s)&&(vis[n-1][m-1].f<ans.f)))
        ans=vis[n-1][m-1];
    if(ans.f==MAX)
    {
        cout<<"-1";
        return 0;
    }
    cout<<ans.s<<" "<<ans.f;
    return 0;
}
