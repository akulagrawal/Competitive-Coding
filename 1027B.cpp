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
    
    ll n;
    int q;
    cin>>n>>q;
    ll x,y;
    while(q--)
    {
    	cin>>x>>y;
    	ll ans=0;
    	if((x+y)%2==0)
    	{
    		ans=((x-1)*n+1)/2;
    		ans+=(y-1)/2;
    		ans++;
    	}
    	else
    	{
    		ans=(n*n+1)/2;
    		ans+=((x-1)*n)/2;
    		ans+=(y-1)/2;
    		ans++;
    	}
    	cout<<ans<<endl;
    }


    return 0;
}