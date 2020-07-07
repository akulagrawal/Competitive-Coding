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

int c[2005],dp[2005][2005],n;

int maxp(int st,int en)
{
    if(st>en)
        return 0;
    if(dp[st][en]!=-1)
        return dp[st][en];
    int x=n-(en-st+1)+1;
    return dp[st][en]=max(maxp(st+1,en)+x*c[st],maxp(st,en-1)+x*c[en]);
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i;
    cin>>n;
    for(i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
            dp[i][j]=-1;
    }
    for(i=0;i<n;i++)
        cin>>c[i];
    cout<<maxp(0,n-1);
    return 0;
}
