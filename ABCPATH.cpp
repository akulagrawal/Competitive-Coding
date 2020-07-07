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

string s[100];
int n,m;
int vis[55][55];

int dfs(int x,int y)
{
	if(vis[x][y])
		return vis[x][y];
	char ch=s[x][y];
	int ans=s[x][y]-'A'+1;
	if(x>0&&y>0&&s[x-1][y-1]==ch+1)
		ans=max(ans,dfs(x-1,y-1));
	if(x>0&&s[x-1][y]==ch+1)
		ans=max(ans,dfs(x-1,y));
	if(x>0&&(y<m-1)&&s[x-1][y+1]==ch+1)
		ans=max(ans,dfs(x-1,y+1));
	if((x<n-1)&&y>0&&s[x+1][y-1]==ch+1)
		ans=max(ans,dfs(x+1,y-1));
	if((x<n-1)&&s[x+1][y]==ch+1)
		ans=max(ans,dfs(x+1,y));
	if((x<n-1)&&(y<m-1)&&s[x+1][y+1]==ch+1)
		ans=max(ans,dfs(x+1,y+1));
	if(y>0&&s[x][y-1]==ch+1)
		ans=max(ans,dfs(x,y-1));
	if((y<m-1)&&s[x][y+1]==ch+1)
		ans=max(ans,dfs(x,y+1));
	return vis[x][y]=ans;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    int t=1;

    while(1)
    {
    	cin>>n>>m;
    	int i,j;
    	int ans=0;
    	if(!n)
    		break;
    	for(i=0;i<n;i++)
    		cin>>s[i];
    	for(i=0;i<=n;i++)
    	{
    		for(j=0;j<=m;j++)
    			vis[i][j]=0;
    	}
    	cout<<"Case "<<t<<": ";
    	for(i=0;i<n;i++)
    	{
    		for(j=0;j<m;j++)
    		{
    			if(s[i][j]=='A')
    				ans=max(ans,dfs(i,j));
    		}
    	}
    	cout<<ans<<endl;
    	t++;
    }

    return 0;
}