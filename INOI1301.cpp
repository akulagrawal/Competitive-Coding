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

ll a[MAX],dp1[MAX],dp2[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,k;
    cin>>n>>k;
    int i;
    for(i=1;i<=n;i++)
    	cin>>a[i];
    if(n==1)
    {
    	cout<<"0\n";
    	return 0;
    }
    for(i=k+1;i<=n;i++)
    {
    	dp1[i]=max(dp1[i-1],dp1[i-2])+a[i];
    }
    dp2[n]=dp1[n];
    dp2[n-1]=max(dp1[n-1],dp2[n]+a[n-1]);
    for(i=n-2;i>=k;i--)
    {
    	dp2[i]=max(dp1[i], max(dp2[i+1],dp2[i+2])+a[i]);
    }
    for(i=k-1;i>=1;i--)
    {
    	dp2[i]=max(dp2[i+1],dp2[i+2])+a[i];
    }
    cout<<dp2[1];

    return 0;
}