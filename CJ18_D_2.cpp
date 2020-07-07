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

ll p[MAX],h[MAX],x[MAX],y[MAX];
ll a[5],b[5],c[5],m[5];
bool vis[MAX];

int main()
{
    freopen ("B-small-attempt2.in","r",stdin);
    freopen ("B-small-attempt2.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t,i,j;
    cin>>t;
    for(j=1;j<=t;j++)
    {
    	int n,k;
    	memset(vis,0,sizeof(vis));
    	cin>>n>>k;
    	cin>>p[0]>>p[1]>>a[0]>>b[0]>>c[0]>>m[0];
    	cin>>h[0]>>h[1]>>a[1]>>b[1]>>c[1]>>m[1];
    	cin>>x[0]>>x[1]>>a[2]>>b[2]>>c[2]>>m[2];
    	cin>>y[0]>>y[1]>>a[3]>>b[3]>>c[3]>>m[3];


    	for(i=2;i<n;i++)
    	{
    		p[i]=((a[0]*p[i-1])%m[0]+(b[0]*p[i-2])%m[0]+(c[0]%m[0])+m[0])%m[0]+1;
    		h[i]=((a[1]*h[i-1])%m[1]+(b[1]*h[i-2])%m[1]+(c[1]%m[1])+m[1])%m[1]+1;
    		x[i]=((a[2]*x[i-1])%m[2]+(b[2]*x[i-2])%m[2]+(c[2]%m[2])+m[2])%m[2]+1;
    		y[i]=((a[3]*y[i-1])%m[3]+(b[3]*y[i-2])%m[3]+(c[3]%m[3])+m[3])%m[3]+1;
    	}
    	int l;
    	int maxm=0;
    	for(i=0;i<n;i++)
    	{
    		for(l=0;l<k;l++)
    		{
    			if(vis[l])
    				continue;
    			int xd=abs(x[l]-p[i]);
    			int yd=h[i]-xd;
    			if(yd>=y[l])
    			{
    				vis[l]=1;
    				maxm++;
    			}
    			if(y[l]==0&&!vis[l])
    			{
    				vis[l]=1;
    				maxm++;
    			}
    		}
    	}
    	cout<<"Case #"<<j<<": ";
    	cout<<maxm<<endl;
    }


    return 0;
}