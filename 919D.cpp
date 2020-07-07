#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 300006
#define mod 1000000007
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

vector<int> v[MAX];
int vis[MAX];
string s;
int my[MAX][30];
int h;
int p=0;

void dfs(int n)
{
    vis[n]=1;
    for(int i=0;i<v[n].size();i++)
    {
        if(!vis[v[n][i]])
            dfs(v[n][i]);
        else if(vis[v[n][i]]==1)
            p++;
        for(int j=0;j<26;j++)
            my[n][j]=max(my[n][j],my[v[n][i]][j]);
    }
    my[n][(int)((char)s[n]-'a')]++;
    vis[n]=2;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    h=n;
    cin>>s;
    int x,y,i;
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        x--;
        y--;
        v[x].pb(y);
    }
    int maxm=0;
    for(i=0;i<n;i++)
    {
        if(!vis[i])
            dfs(i);
    }
    for(i=0;i<n;i++)
    {
        for(int j=0;j<26;j++)
            maxm=max(maxm,my[i][j]);
    }
    if(p)
        cout<<"-1";
    else
        cout<<maxm;
    return 0;
}
