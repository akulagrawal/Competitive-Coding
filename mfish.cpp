#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,b,d,i,j,flag=0,flag1=0,pre=0;
    scanf("%d",&n);
    int a[n],pos[n],dp[n];
    for (i=0; i<n; i++)
        pos[i]=0,dp[i]=0;
    for (i=0; i<n; i++)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    for ( i=0; i<m; i++)
    {
        scanf("%d %d",&b,&d);
        pos[b-1]=d;
    }
    for (i=0; i<n; i++)
    {
        if (pos[i]!=0)
        {
            int sum=0,l=max(pre,i-pos[i]+1);
            for (j=l; j<min(l+pos[i],n); j++)
                sum+=a[j];
            int k=j;
            if (!flag)
            {
                dp[min(l+pos[i]-1,n-1)]=sum;
                flag=1;
            }
            else
                dp[min(l+pos[i]-1,n-1)]=sum+dp[l-1];
            for (j=min(l+pos[i],n); j<min(n,i+pos[i]); j++)
            {
                sum=(sum+a[j]-a[j-pos[i]]);
                dp[j]=max(dp[j-1],dp[j-pos[i]]+sum);
            }
            pre=k;
        }
        else if (i>0)
            dp[i]=max(dp[i],dp[i-1]);
    }
    printf("%d\n",dp[n-1]);
    return 0;
}
