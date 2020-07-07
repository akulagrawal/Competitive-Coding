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

ll dp[100],sum[100];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i;
    dp[0]=1;
    dp[2]=3;
    for(i=4;i<100;i+=2)
    {
        sum[i]=sum[i-2]+dp[i-4];
        dp[i]=3*dp[i-2]+2*sum[i];
    }
    while(1)
    {
        scanf("%d",&n);
        if(n<0)
            break;
        printf("%lld\n",dp[n]);
    }
    return 0;
}
