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

ll dp[1<<19][19];
ll a[20],w[20][20];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k,i,j,x,y,c;
    ll maxm=0;
    cin>>n>>m>>k;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<k;i++)
    {
        cin>>x>>y>>c;
        w[x-1][y-1]=c;
    }
    for(i=0;i<n;i++)
        dp[1<<i][i]=a[i];
    int mask=0;
    while(!(mask&(1<<n)))
    {
        for(i=0;i<n;i++)
        {
            if(!(mask&(1<<i)))
            {
                for(j=0;j<n;j++)
                {
                    if(mask&(1<<j))
                        dp[mask|(1<<i)][i]=max(dp[mask|(1<<i)][i],dp[mask][j]+w[j][i]+a[i]);
                }
            }
            if(__builtin_popcount(mask|(1<<i))==m)
                if(maxm<dp[mask|(1<<i)][i])
                    maxm=dp[mask|(1<<i)][i];
        }
        mask++;
    }
    cout<<maxm;
    return 0;
}
