#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 100005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

int dp[102][102],p[102];

int main()
{
    int t,n,k,i,x,y,z,temp,minm;
    scanf("%d",&t);
    while(t--)
    {
        minm=-1;
        scanf("%d%d",&n,&k);
        for(i=1;i<=n;i++)
        {
            for(x=1;x<=k;x++)
                dp[i][x]=-1;
        }
        for(i=1;i<=k;i++)
            scanf("%d",&p[i]);
        for(i=1;i<=k;i++)
                dp[1][i]=p[i];
        for(i=2;i<=n;i++)
        {
            for(x=1;x<=k;x++)
            {
                for(y=1;y<x;y++)
                {
                    for(z=1;z<i;z++)
                    {
                        if(dp[i-z][x-y]>=0&&dp[z][y]>=0)
                        {
                            temp=dp[i-z][x-y]+dp[z][y];
                            if(dp[i][x]>=0)
                                dp[i][x]=min(dp[i][x],temp);
                            else
                                dp[i][x]=temp;
                        }
                    }
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            if(dp[i][k]>=0)
            {
                if(minm>=0)
                    minm=min(minm,dp[i][k]);
                else
                    minm=dp[i][k];
            }
        }
        printf("%d\n",minm);
    }
    return 0;
}
