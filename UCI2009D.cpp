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

string s[10],l;
unordered_map<string,bool> my;
bool vis[10][10];
int a[4]={-1,0,1,0};
int b[4]={0,-1,0,1};
int n;

bool isvalid(int x,int y)
{
	return (x>=0&&y>=0&&x<n&&y<n);
}

int dfs(int x,int y,int z,string k)
{
	//cout<<x<<" "<<y<<" "<<z<<" "<<k<<endl;
	if(z==8)
	{
		if(my[k])
			return 0;
		my[k]=1;
		return 1;
	}
	vis[x][y]=1;
	int ans=0;
	for(int i=0;i<4;i++)
	{
		int xn=x+a[i];
		int yn=y+b[i];
		string c=k;
		if(!vis[xn][yn]&&isvalid(xn,yn)&&s[xn][yn]=='X')
		{
			c[8*xn+yn]='X';
			ans+=dfs(xn,yn,z+1,c);
		}
	}
	vis[x][y]=0;
	return ans;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--)
    {
    	my.clear();
    	cin>>n;
    	int i,j;
    	for(i=0;i<n;i++)
    		cin>>s[i];
    	for(i=0;i<64;i++)
    		l.pb('.');
    	int ans=0;
    	for(i=0;i<n;i++)
    	{
    		for(j=0;j<n;j++)
    		{
    			if(s[i][j]=='X')
    			{
    				l[8*i+j]='X';
    				ans+=dfs(i,j,1,l);
    				l[8*i+j]='.';
    			}
    		}
    	}
    	cout<<ans<<endl;
    }


    return 0;
}