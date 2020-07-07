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

bool vis[201],vis2[201];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t,n;
    cin>>t;
    for(int i=2;i<201;i++)
    {
    	if(!vis[i])
    	{
    		for(int j=2*i;j<201;j+=i)
    			vis[j]=1;
    	}
    }
    for(int i=2;i<201;i++)
    {
    	for(int j=2;j<201;j++)
    	{
    		if((!vis[i]&&!vis[j])&&(i!=j))
    		{
    			if(i*j<201)
    				vis2[i*j]=1;
    		}
    		if(i*j>200)
    			break;
    	}
    }
    while(t--)
    {
    	int n;
    	cin>>n;
    	int i;
    	for(i=1;i<n;i++)
    	{
    		if(vis2[i]&&vis2[n-i])
    			break;
    	}
    	if(i<n)
    		cout<<"YES\n";
    	else
    		cout<<"NO\n";

    }


    return 0;
}