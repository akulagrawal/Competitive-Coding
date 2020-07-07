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

int dp[105][105][105];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m,k,i,j,l;
    string s1,s2;
    cin>>t;
    while(t--)
    {
        for(i=0;i<101;i++)
        {
            for(j=0;j<101;j++)
            {
                for(l=0;l<101;l++)
                    dp[i][j][l]=0;
            }
        }
        cin>>s1>>s2;
        n=s1.size();
        m=s2.size();
        cin>>k;
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=m;j++)
            {
                if(i==0||j==0)
                    continue;
                else if(s1[i-1]==s2[j-1])
                {
                    dp[i][j][0]=1+dp[i-1][j-1][0];
                    dp[i][j][1]=max((int)s1[i-1],dp[i-1][j-1][1]);
                    for(l=2;l<=dp[i][j][0];l++)
                        dp[i][j][l]=max(s1[i-1]+dp[i-1][j-1][l-1],dp[i-1][j-1][l]);
                }
                else
                {
                    dp[i][j][0]=max(dp[i-1][j][0],dp[i][j-1][0]);
                    for(l=1;l<=dp[i][j][0];l++)
                        dp[i][j][l]=max(dp[i-1][j][l],dp[i][j-1][l]);
                }
            }
        }
        cout<<dp[n][m][k]<<endl;
    }
    return 0;
}
