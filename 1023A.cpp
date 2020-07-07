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

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    string s,t;
    cin>>n>>m>>s>>t;
    int i,j;
    for(i=0;i<n;i++)
    {
    	if(s[i]=='*')
    		break;
    }
    if(i==n)
    {
    	if(s==t)
    		cout<<"YES";
    	else
    		cout<<"NO";
    }
    else
    {
    	for(j=0;j<i;j++)
    	{
    		if(s[j]!=t[j])
    		{
    			cout<<"NO";
    			return 0;
    		}
    	}
    	if(t.size()<s.size()-1)
    	{
    		cout<<"NO";
    		return 0;
    	}
    	for(j=n-1;j>i;j--)
    	{
    		if(s[j]!=t[m-n+j])
    		{
    			cout<<"NO";
    			return 0;
    		}
    	}
    	cout<<"YES";
    }

    return 0;
}