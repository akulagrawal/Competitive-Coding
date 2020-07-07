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

int n,b[40],dp[40][40];

int solve(int n,int m)
{
    if(n<0||m<0)
        return 0;
    if(dp[n][m]>-1)
        return dp[n][m];
    if(n==1&&m==0)
        return dp[1][0]=1;
    if(n<m)
        return dp[n][m]=0;
    if(b[n+m]==1)
        return dp[n][m]=solve(n-1,m);
    else
        return dp[n][m]=solve(n-1,m)+solve(n,m-1);
}

int a[20];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int d,n,k;
    cin>>d;
    while(d--)
    {
        int i;
        memset(b,0,sizeof(b));
        cin>>n>>k;
        for(i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
                dp[i][j]=-1;
        }
        for(i=0;i<k;i++)
            cin>>a[i];
        for(i=0;i<k;i++)
            b[a[i]]=1;
        cout<<solve(n,n)<<endl;
    }
    return 0;
}
