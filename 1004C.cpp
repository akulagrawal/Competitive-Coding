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

int a[MAX],b[MAX],c[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    int i;
    ll p=0;
    for(i=0;i<n;i++)
    	cin>>a[i];
    for(i=0;i<n;i++)
    {
    	if(!b[a[i]])
    		p++;
    	b[a[i]]++;
    }
    ll ans=0;
    for(i=0;i<n-1;i++)
    {
    	if(c[a[i]])
    	{
    		if(b[a[i]]==1)
    			p--;
    		b[a[i]]--;
    		continue;
    	}
    	if(b[a[i]]==1)
    		p--;
    	b[a[i]]--;
    	ans+=p;
    	c[a[i]]=1;
    }
    cout<<ans;


    return 0;
}