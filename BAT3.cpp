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

int a[1004],dp[1004];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m,i,j,maxm;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        maxm=0;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<m;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[j]<a[i])
                    dp[j]=max(dp[j],dp[i]+1);
            }
        }
        for(j=m+1;j<n;j++)
            dp[j]=max(dp[j],dp[m]+1);
        for(i=m+1;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[j]<a[i]&&j!=m)
                    dp[j]=max(dp[j],dp[i]+1);
            }
        }
        for(i=0;i<n;i++)
            maxm=max(maxm,dp[i]);
        printf("%d\n",maxm+1);
    }
    return 0;
}
