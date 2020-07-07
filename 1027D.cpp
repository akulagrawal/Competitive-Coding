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

int a[MAX],c[MAX];
int vis[MAX];
int ans[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    int i;
    int sum=0;
    cin>>n;
    for(i=1;i<=n;i++)
    	cin>>c[i];
    for(i=1;i<=n;i++)
    	cin>>a[i];
    for(i=1;i<=n;i++)
    {
    	int x=i;
    	while(!vis[x])
    	{
    		vis[x]=1;
    		x=a[x];
    	}
    	if(vis[x]>1)
    	{
    		int p=ans[x];
    		x=i;
    		while(vis[x]==1)
    		{
    			vis[x]=2;
    			ans[x]=p;
    			x=a[x];
    		}
    		continue;
    	}
    	int minm=MAX;
    	while(vis[x]==1)
    	{
    		vis[x]=2;
    		minm=min(minm,c[x]);
    		x=a[x];
    		//cout<<x<<" ";
    	}
    	//cout<<endl;
    	x=i;
    	while(vis[x]<3)
    	{
    		vis[x]=3;
    		ans[x]=minm;
    		x=a[x];
    	}
    	sum+=minm;
    	
    }
    //for(i=1;i<=n;i++)
   // 	cout<<ans[i]<<" ";
    cout<<sum;


    return 0;
}