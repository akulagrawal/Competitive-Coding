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

int w[MAX];
int pre[MAX],post[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,l,r,ql,qr;
    cin>>n>>l>>r>>ql>>qr;
    int i;
    int ans=INT_MAX;
    for(i=1;i<=n;i++)
    {
    	cin>>w[i];
    	pre[i]+=w[i];
    	pre[i]+=pre[i-1];
    }
    for(i=n-1;i>=0;i--)
    {
    	post[i]=w[i+1]+post[i+1];
    }
    for(i=0;i<=n;i++)
    {
    	int x=pre[i]*l+post[i]*r;
    	//cout<<x<<":";
    	if(i<n-i)
    		x+=(n-2*i-1)*qr;
    	if(i>n-i)
    		x+=(2*i-n-1)*ql;
    	//cout<<x<<" ";
    	ans=min(ans,x);
    }
    cout<<ans;



    return 0;
}