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

ll dp[30];
char s[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,i,j;
    ll sum;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%s",&s);
        getchar();
        memset(dp,0,sizeof(dp));
        n=strlen(s);
        for(i=0;i<n;i++)
        {
            sum=(sum-dp[s[i]-'A']+mod)%mod;
            dp[s[i]-'A']=(dp[s[i]-'A']+1+sum)%mod;
            sum=(sum+dp[s[i]-'A'])%mod;
        }
        sum=1;
        for(i=0;i<26;i++)
            sum=(sum+dp[i])%mod;
        printf("%lld\n",sum);
    }
    return 0;
}
