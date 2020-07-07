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
    
    int t,n;
    string s;
    cin>>t;
    while(t--)
    {
    	cin>>n>>s;
    	int i;
    	for(i=0;i<n/2;i++)
    	{
    		if(abs(s[n-i-1]-s[i])==2||abs(s[n-i-1]-s[i])==0)
    			continue;
    		else
    			break;
    	}
    	if(i==n/2)
    		cout<<"YES\n";
    	else
    		cout<<"NO\n";
    }

    return 0;
}