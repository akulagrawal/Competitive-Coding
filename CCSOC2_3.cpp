#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 1000006
#define mod 20011
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

int dp[302][302][2][302],ans;
int a[305][305];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    int r,c,x,i,j,k;
    scanf("%d%d%d",&r,&c,&x);
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            scanf("%d",&a[i][j]);
    }
    dp[0][0][0][0]=1;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(!a[i][j])
                continue;
            if(j>0)
            {
                for(k=0;k<=x;k++)
                {
                    dp[i][j][0][k+1]=(dp[i][j][0][k+1]+dp[i][j-1][0][k])%mod;
                    dp[i][j][0][1]=(dp[i][j][0][1]+dp[i][j-1][1][k])%mod;
                }
            }
            if(i>0)
            {
                for(k=0;k<=x;k++)
                {
                    dp[i][j][1][k+1]=(dp[i][j][1][k+1]+dp[i-1][j][1][k])%mod;
                    dp[i][j][1][1]=(dp[i][j][1][1]+dp[i-1][j][0][k])%mod;
                }
            }
        }
    }
    for(i=0;i<2;i++)
    {
        for(j=0;j<=x;j++)
            ans=(ans+dp[r-1][c-1][i][j])%mod;
    }
    printf("%lld",ans);
    return 0;
}
