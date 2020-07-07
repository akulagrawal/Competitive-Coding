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

ll x[MAX],s[MAX],my1[MAX],my2[MAX],my3[MAX];

int main()
{
    freopen ("A-small-attempt0.in","r",stdin);
    freopen ("A-small-attempt0.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t,i,j;
    cin>>t;
    for(j=1;j<=t;j++)
    {
    	ll n,o,d,x11,x12,a,b,c,m,l;
    	cin>>n>>o>>d;
    	cin>>x11>>x12>>a>>b>>c>>m>>l;
    	x[0]=x11;
    	x[1]=x12;
    	s[0]=x11+l;
    	s[1]=x12+l;
    	for(i=2;i<n;i++)
    		x[i]=(a*x[i-1]+b*x[i-2]+c)%m;
    	for(i=2;i<n;i++)
    		s[i]=x[i]+l;
    	cout<<"Case #"<<j<<": ";

    	my1[0]=s[0];
    	my2[0]=s[0]%2;
    	my3[0]=s[0];

    	for(i=1;i<n;i++)
    	{
    		my3[i]=my3[i-1]+s[i];
    		my1[i]=max(max(my3[i-1]+s[i],s[i]),my1[i-1]);
    		my2[i]=my2[i-1]+s[i]%2;
    	}
    	for(i=0;i<n;i++)
    	{
    		int lo=i;
    		int ro=n-1;
    		int mid;
    		while(l<r)
    		{
    			mid=l+(r-l)/2;
    			if(my2[mid]>o)
    				r=mid-1;
    			else
    				l=mid;
    		}
    		mid=l+(r-l)/2;
    		my
    	}

    	if(maxm!=-1)
    		cout<<maxm<<endl;
    	else
    		cout<<"IMPOSSIBLE\n";

    }


    return 0;
}