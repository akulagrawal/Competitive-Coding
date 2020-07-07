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

int a[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,k;
    cin>>n>>k;
    int i,j,sum=0;
    for(i=0;i<n;i++)
    	cin>>a[i];
    double maxm=0;
    for(j=0;j<=n-k;j++)
    {
    	sum=0;
    	for(i=j;i<j+k;i++)
    		sum+=a[i];
    	maxm=max(maxm,(double)sum/(double)k);
    	for(i=j+k;i<n;i++)
    	{
    		sum+=a[i];
    		maxm=max(maxm,(double)sum/(double)(i-j+1));
    	}
    }
    cout<<fixed<<setprecision(10)<<maxm;

    return 0;
}