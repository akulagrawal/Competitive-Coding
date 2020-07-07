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

int p[55];

int main()
{
    //freopen ("interceptionin.txt","r",stdin);
    //freopen ("interceptionout.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t,n;
    cin>>t;
    int i,j;
    for(j=1;j<=t;j++)
    {
    	cin>>n;
    	for(i=0;i<=n;i++)
    		cin>>p[i];
    	cout<<"Case #"<<j<<": ";
    	int c=1;
    	if(p[0]<-1)
    	{
    		cout<<"0\n";
    		continue;
    	}
    	if(n%2)
    	{
    		if(p[0]==-1)
    			c=0;
    	}
    	else if(p[0]!=-1)
    		c=0;
    	if(c)
    	{
    		cout<<"1\n";
    		cout<<"0.0\n";
    	}
    	else
    		cout<<"0\n";
    }

    return 0;
}