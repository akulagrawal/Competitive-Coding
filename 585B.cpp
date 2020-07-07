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

string s[5];
int vis[5][105];

void dfs(int a,int b,int n)
{
    vis[a][b]=1;
    int i;
    if(b+3>=n)
    {
        for(i=b;i<n;i++)
            if(s[a][i]!='.')
                break;
        if(i>=n)
            vis[a][n-1]=1;
        return;
    }
    if(a>0)
        if(s[a][b+1]=='.'&&s[a][b+2]=='.'&&s[a][b+3]=='.'&&s[a-1][b+3]=='.'&&!vis[a-1][b+3])
            dfs(a-1,b+3,n);
    if(s[a][b+1]=='.'&&s[a][b+2]=='.'&&s[a][b+3]=='.'&&!vis[a][b+3])
        dfs(a,b+3,n);
    if(a<2)
        if(s[a][b+1]=='.'&&s[a][b+2]=='.'&&s[a][b+3]=='.'&&s[a+1][b+3]=='.'&&!vis[a+1][b+3])
            dfs(a+1,b+3,n);
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,k,i;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=0;i<3;i++)
            for(int j=0;j<n;j++)
                vis[i][j]=0;
        for(i=0;i<3;i++)
            cin>>s[i];
        for(i=0;i<3;i++)
            if(s[i][0]=='s')
                break;
        if(s[i][1]=='.')
        {
            if(i>0&&s[i-1][1]=='.')
                dfs(i-1,1,n);
            dfs(i,1,n);
            if(i<2&&s[i+1][1]=='.')
                dfs(i+1,1,n);
        }
        for(i=0;i<3;i++)
            if(vis[i][n-1])
                break;
        if(i==3)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }

    return 0;
}
