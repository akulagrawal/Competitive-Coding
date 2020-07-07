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

string s[1003];
int vis[1003][1003];
int n,m,k;

bool is(int i,int j)
{
    return ((i>=0&&i<n&&j>=0&&j<m)&&s[i][j]=='.');
}

void bfs(int x,int y)
{
    queue<pii> q;
    q.push(mp(x,y));
    vis[x][y]=0;
    int x1,y1,i;
    while(!q.empty())
    {
        x1=(q.front()).f;
        y1=(q.front()).s;
        q.pop();
        for(i=1;i<=k;i++)
        {
            if(!is(x1+i,y1))
                break;
            if(vis[x1+i][y1]>vis[x1][y1]+1)
            {
                vis[x1+i][y1]=vis[x1][y1]+1;
                q.push(mp(x1+i,y1));
            }
            else if(vis[x1+i][y1]<vis[x1][y1]+1)
                break;
        }
        for(i=1;i<=k;i++)
        {
            if(!is(x1-i,y1))
                break;
            if(vis[x1-i][y1]>vis[x1][y1]+1)
            {
                vis[x1-i][y1]=vis[x1][y1]+1;
                q.push(mp(x1-i,y1));
            }
            else if(vis[x1-i][y1]<vis[x1][y1]+1)
                break;
        }
        for(i=1;i<=k;i++)
        {
            if(!is(x1,y1+i))
                break;
            if(vis[x1][y1+i]>vis[x1][y1]+1)
            {
                vis[x1][y1+i]=vis[x1][y1]+1;
                q.push(mp(x1,y1+i));
            }
            else if(vis[x1][y1+i]<vis[x1][y1]+1)
                break;
        }
        for(i=1;i<=k;i++)
        {
            if(!is(x1,y1-i))
                break;
            if(vis[x1][y1-i]>vis[x1][y1]+1)
            {
                vis[x1][y1-i]=vis[x1][y1]+1;
                q.push(mp(x1,y1-i));
            }
            else if(vis[x1][y1-i]<vis[x1][y1]+1)
                break;
        }
    }
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,x1,x2,y1,y2;
    cin>>n>>m>>k;
    for(i=0;i<1000;i++)
    {
        for(j=0;j<1003;j++)
            vis[i][j]=MAX;
    }
    for(i=0;i<n;i++)
        cin>>s[i];
    cin>>x1>>y1>>x2>>y2;
    x1--;y1--;x2--;y2--;
    bfs(x1,y1);
    if(vis[x2][y2]!=MAX)
        cout<<vis[x2][y2];
    else
        cout<<"-1";
    return 0;
}
