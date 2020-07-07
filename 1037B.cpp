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

ll a[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    ll s;
    cin>>n>>s;
    int i;
    for(i=0;i<n;i++)
    	cin>>a[i];
    
    sort(a,a+n);
    ll ans=0;
    int x=n/2;
    if(a[x]<s)
    {
    	for(i=x;i<n;i++)
    	{
    		if(a[i]<s)
    			ans+=s-a[i];
    	}
    }
    else
    {
    	for(i=x;i>=0;i--)
    	{
    		if(a[i]>s)
    			ans+=a[i]-s;
    	}
    }
    cout<<ans;



    return 0;
}