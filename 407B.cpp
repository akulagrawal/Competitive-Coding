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

ll p[1003],low[1003],dp[1003];
map<int,bool> mark[1003];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,j;
    ll sum=0;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>p[i];
    for(i=1;i<=n;i++)
    {
        low[i]=p[i];
        low[i]=low[p[i]];
        j=i;
        while(j!=low[j])
        {
            mark[i][j]=1;
            j=p[j];
        }
        mark[i][j]=1;
    }
    for(i=1;i<=n;i++)
    {
        for(j=low[i];j<=i;j++)
        {
            if(!mark[i][j])
                dp[i]=(dp[i]+dp[j])%mod;
            else
                dp[i]+=2;
        }
    }
    for(i=1;i<=n;i++)
        sum=(sum+dp[i])%mod;
    cout<<sum;
    return 0;
}
