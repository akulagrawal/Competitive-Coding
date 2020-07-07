#include<bits/stdc++.h>

using namespace std;

int m[102][102],dp[102][102];

int main()
{
    int t,h,w,i,j,k,temp,maxm;
    scanf("%d",&t);
    while(t--)
    {
        maxm=0;
        scanf("%d%d",&h,&w);
        for(i=0;i<h;i++)
        {
            for(j=0;j<w;j++)
                scanf("%d",&m[i][j]);
        }
        for(j=0;j<w;j++)
            dp[0][j]=m[0][j];
        for(i=1;i<h;i++)
        {
            if(dp[i-1][0]>dp[i-1][1])
                dp[i][0]=dp[i-1][0]+m[i][0];
            else
                dp[i][0]=dp[i-1][1]+m[i][0];

            if(dp[i-1][w-1]>dp[i-1][w-2])
                dp[i][w-1]=dp[i-1][w-1]+m[i][w-1];
            else
                dp[i][w-1]=dp[i-1][w-2]+m[i][w-1];

            for(j=1;j<w-1;j++)
            {
                temp=max(dp[i-1][j-1],dp[i-1][j]);
                temp=max(dp[i-1][j+1],temp);
                dp[i][j]=temp+m[i][j];
            }
        }
        for(j=0;j<w;j++)
        {
            if(maxm<dp[h-1][j])
                maxm=dp[h-1][j];
        }
        printf("%d\n",maxm);
    }
    return 0;
}
