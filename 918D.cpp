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

vector<pii> v[105];
bool dp[105][105][30][5];
bool vis[105][105][30][5];

bool dfs(int i,int j,int ch,bool p)
{
    if(vis[i][j][ch][p])
        return dp[i][j][ch][p];
    int ans=0;
    int cnt=0;
    vis[i][j][ch][p]=1;
    for(int x=0;x<v[i].size();x++)
    {
        int w=v[i][x].f,c=v[i][x].s;
        if(c>=ch)
        {
            ans+=dfs(j,w,c,!p)==!p;
            cnt++;
        }
    }
    if(!cnt)
        return dp[i][j][ch][p]=p;
    if(ans)
        return dp[i][j][ch][p]=!p;
    return dp[i][j][ch][p]=p;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int i;
    int x,y;
    char ch;
    for(i=0;i<m;i++)
    {
        cin>>x>>y>>ch;
        v[x].pb(mp(y,(int)(ch-'a')));
    }
    for(i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(dfs(i,j,0,0))
                cout<<"A";
            else
                cout<<"B";
        }
        cout<<endl;
    }
    return 0;
}
