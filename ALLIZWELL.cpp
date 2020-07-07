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

string s[102],l="ALLIZZWELL";
int a[8]={-1,0,1,-1,1,-1,0,1};
int b[8]={-1,-1,-1,0,0,1,1,1};
int r,c;
bool vis[102][102];

bool isvalid(int x,int y)
{
	if(x>=0&&x<r&&y>=0&&y<=c)
		return 1;
	return 0;
}

bool dfs(int x,int y,int z)
{
	if(z==9)
		return 1;
	vis[x][y]=1;
	bool temp=0;
	for(int i=0;i<8;i++)
	{
		if(isvalid(x+a[i],y+b[i])&&s[x+a[i]][y+b[i]]==l[z+1]&&!temp&&!vis[x+a[i]][y+b[i]])
			temp=temp|dfs(x+a[i],y+b[i],z+1);
	}
	vis[x][y]=0;
	return temp;
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
    	cin>>r>>c;
    	int i,j;
    	for(i=0;i<r;i++)
    		cin>>s[i];
    	for(i=0;i<r;i++)
    	{
    		for(j=0;j<c;j++)
    		{
    			if(s[i][j]=='A')
    			{
    				if(dfs(i,j,0))
    				{
    					cout<<"YES\n";
    					break;
    				}
    			}
    		}
    		if(j<c)
    			break;
    	}
    	if(i>=r)
    		cout<<"NO\n";
    }

    return 0;
}