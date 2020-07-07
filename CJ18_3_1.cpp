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

vector<int> v[1003];
int vis[1003],idx,is[1003],idx2,ans[1003];

void dfs1(int x,int y)
{
	vis[x]=1;
	for(int i=0;i<v[x].size();i++)
	{
		if(!vis[v[x][i]])
			dfs1(v[x][i],x);
		else if(y!=v[x][i])
		{
			idx=v[x][i];
			is[x]=1;
			return;
		}
		if(idx==x)
		{
			idx2=idx;
			idx=0;
			is[x]=1;
			return;
		}
		if(idx)
		{
			is[x]=1;
			return;
		}
	}
}

void dfs2(int x,int y)
{
	vis[x]=1;
	ans[x]=y;
	for(int i=0;i<v[x].size();i++)
	{
		if(!vis[v[x][i]])
		{
			if(is[v[x][i]])
				dfs2(v[x][i],0);
			else
				dfs2(v[x][i],y+1);
		}
	}
}

int main()
{
    //freopen ("A-large-practice.in","r",stdin);
    //freopen ("A-large-practice.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    int i,j;
    cin>>t;
    for(j=1;j<=t;j++)
    {
    	int n;
    	cin>>n;
    	for(i=1;i<=n;i++)
    		v[i].clear();
    	memset(vis,0,sizeof(vis));
    	memset(is,0,sizeof(is));
    	idx=0;
    	idx2=0;
    	int x,y;
    	for(i=0;i<n;i++)
    	{
    		cin>>x>>y;
    		v[x].pb(y);
    		v[y].pb(x);
    	}
    	cout<<"Case #"<<j<<": ";
    	dfs1(1,0);
    	memset(vis,0,sizeof(vis));
    	dfs2(idx2,0);
    	for(i=1;i<=n;i++)
    		cout<<ans[i]<<" ";
    	cout<<endl;
    }

    return 0;
}