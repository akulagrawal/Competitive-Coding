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

int b[20]={-2,-2,-1,-1,1,1,2,2},c[20]={-1,1,-2,2,-2,2,-1,1};
bool v[20][20],vis[20][20];
int e;

void dfs(int x,int y,int d)
{
    vis[x][y]=1;
    int xnew,ynew,p=0;
    for(int i=0;i<8;i++)
    {
        xnew=x+b[i];
        ynew=y+c[i];
        if(xnew>=0&&ynew>=0&&v[xnew][ynew]>0&&!vis[xnew][ynew])
            dfs(xnew,ynew,d+1);
    }
    e=max(e,d);
    vis[x][y]=0;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,x,y,j,sum,t;
    for(t=1;;t++)
    {
        sum=0;
        e=0;
        for(i=0;i<20;i++)
        {
            for(j=0;j<20;j++)
                vis[i][j]=v[i][j]=0;
        }
        cin>>n;
        if(!n)
            break;
        for(i=0;i<n;i++)
        {
            cin>>x>>y;
            sum+=y;
            for(j=0;j<y;j++)
                v[i][x+j-1]=1;
        }
        dfs(0,0,1);
        cout<<"Case "<<t<<", "<<sum<<" "<<e<<" "<<sum-e;
        if(sum-e==1)
            cout<<" square can not be reached.\n";
        else
            cout<<" squares can not be reached.\n";
    }
    return 0;
}
