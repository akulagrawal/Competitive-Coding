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

int a[MAX],dp[MAX];

vector<int> v[MAX];

int dfs(int n)
{
	if(dp[n])
		return dp[n];
	int p=0,i;
	for(i=0;i<v[n].size();i++)
	{
		if(dfs(v[n][i])!=1)
			break;
	}
	if(i<v[n].size())
		return dp[n]=1;
	else
		return dp[n]=2;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    int i;
    for(i=0;i<n;i++)
    	cin>>a[i];
    for(i=0;i<n;i++)
    {
    	for(int j=i+a[i];j<n;j+=a[i])
    	{
    		if(a[j]>a[i])
    			v[i].pb(j);
    	}
    	for(int j=i-a[i];j>=0;j-=a[i])
    	{
    		if(a[j]>a[i])
    			v[i].pb(j);
    	}
    }
    for(i=0;i<n;i++)
    {
    	if(dfs(i)==1)
    		cout<<"A";
    	else
    		cout<<"B";
    }


    return 0;
}