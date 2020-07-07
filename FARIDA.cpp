#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 10005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

ll a[MAX],dp[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i,j,n;
    scanf("%d",&t);
    for(j=1;j<=t;j++)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        dp[0]=0;
        dp[1]=a[1];
        for(i=2;i<=n;i++)
            dp[i]=max(dp[i-2]+a[i],dp[i-1]);
        printf("Case %d: %lld\n",j,dp[n]);
    }
    return 0;
}
