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

string s[105];
char d[105];
int vis[105][105];

int main()
{
    freopen ("C-small-attempt0.in","r",stdin);
    freopen ("C-small-attempt0.out","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    
    int t,i,j;
    cin>>t;
    for(j=1;j<=t;j++)
    {
    	int r,c,w,ans=0;
    	cin>>r>>c>>w;
    	int k;
    	for(i=0;i<r;i++)
    		cin>>s[i];
    	for(i=0;i<w;i++)
    		cin>>d[i];
    	for(i=0;i<r;i++)
    		for(k=0;k<c;k++)
    			vis[i][k]=0;
    	for(i=0;i<w;i++)
    	{
    		int x;
    		for(k=0;k<r;k++)
    		{
    			for(x=0;x<c;x++)
    			{
    				if((!vis[k][x])&&(s[k][x]==d[i]))
    					vis[k][x]=1;
    				if(k>0)
    					vis[k][x]+=vis[k-1][x];
    				if(x>0)
    					vis[k][x]+=vis[k][x-1];
    				if(k>0&&x>0)
    					vis[x][x]-=vis[k-1][x-1];
    			}
    			
    		}
    	}

    	double maxm=0;
    	int num=0,den=1;
    	int k2,k3;

    	for(i=0;i<r;i++)
    	{
    		for(k=0;k<c;k++)
    		{
    			for(k2=i;k2<r;k2++)
    			{
    				for(k3=k;k3<c;k3++)
    				{
    					int sum=vis[k2][k3];
    					if(i>0)
    						sum-=vis[i-1][k3];
    					if(k>0)
    						sum-=vis[k2][k];
    					if(i>0&&k>0)
    						sum+=vis[i][k];
    					sum*=4;
    					double p=(double)sum/(double)(k2+k3-i-k+2);
    					if(p>maxm)
    					{
    						num=sum;
    						maxm=p;
    						den=k2+k3-i-k+2;
    						int a2=__gcd(num,den);
    						if(!a2)
    							a2=den;
    						num/=a2;
    						den/=a2;
    						ans=0;
    					}
    					int d32=k2+k3-i-k+2;
    					int c2=__gcd(sum,d32);
    					sum/=c2;
    					d32/=c2;

    					if(num==sum&&den==d32)
    						ans++;

    				}
    			}
    		}
    	}
    	



    	cout<<"Case #"<<j<<": ";
    	cout<<num<<"/"<<den<<" "<<ans<<endl;
    }


    return 0;
}