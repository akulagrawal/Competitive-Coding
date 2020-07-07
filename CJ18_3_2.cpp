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

int a[200][200],b[200];
pii c[200];
int vis[200];
vector<int> v;

int main()
{
    freopen ("B-large-practice.in","r",stdin);
    freopen ("B-large-practice.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n,i,j,k;
    cin>>t;
    for(j=1;j<=t;j++)
    {
    	cin>>n;
    	for(i=0;i<n;i++)
    	{
    		for(k=0;k<n;k++)
    			cin>>a[i][k];
    	}
    	cout<<"Case #"<<j<<": ";
    	int m=0;
    	for(i=0;i<n;i++)
    	{
    		for(k=0;k<n;k++)
    		{
    			if(a[i][k])
    			{
    				b[m]=a[i][k];
    				c[m]=mp(i,k);
    				a[i][k]=0;
    				a[k][i]=0;
    				m++;
    			}
    		}
    	}
    	int p=1<<m;
    	int ans=0;
    	while(p--)
    	{
    		int x=p;
    		i=0;
    		memset(vis,0,sizeof(vis));
    		v.clear();
    		while(x)
    		{
    			if(x%2)
    				v.pb(i);
    			x/=2;
    			i++;
    		}
    		for(i=0;i<v.size();i++)
    		{
    			if(vis[c[v[i]].f]||vis[c[v[i]].s])
    				break;
    			vis[c[v[i]].f]=1;
    			vis[c[v[i]].s]=1;
    		}
    		if((i<v.size())||v.size()<3)
    			continue;
    		int sum=0;
    		int maxm=0;
    		for(i=0;i<v.size();i++)
    		{
    			sum+=b[v[i]];
    			maxm=max(maxm,b[v[i]]);
    		}
    		sum-=maxm;
    		if(sum<=maxm)
    			continue;
    		ans++;
    	}
    	cout<<ans<<endl;

    }    


    return 0;
}